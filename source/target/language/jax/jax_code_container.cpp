/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2021 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#include "target/language/jax/jax_code_container.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/errors/exception.hh"
#include "target/fir/fir_function_builder.hh"
#include "compiler/types/floats.hh"
#include "global.hh"
#include "target/fir/visitor/function_call_inliner.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

#include "faust/primitive/type/precision.hh"

using Precision = ::Faust::Primitive::Type::Precision;

using namespace std;

/*
 JAX backend and module description:

 - Whereas a normal code container would generate a "compute" method, we generate
   a one-sample loop "tick" method. Our hard-coded "compute" method __call__ is implemented
   in an architecture file. It uses JAX's scan function in conjunction with the generated tick function.
 - Inside "__call__" and before using "scan", we setup the arrays, soundfiles, user interface parameters,
   and other state variables.
 - One tricky part of JAX is modifying arrays in-place:
   https://jax.readthedocs.io/en/latest/_autosummary/jax.numpy.ndarray.at.html
   Whereas C++ would look like
   `fRec1[0] = fTemp0`
   in JAX we have to do
   `state["fRec1"] = state["fRec1"].at[0].set(fTemp0)`
   Also, this at-and-set operation is slow, so we only use it inside the tick method.
   This is why in all other places (like initializing sound files which are arrays),
   we use numpy arrays instead of jnp arrays. It's best to just look at the generated code and notice
   how the jnp prefix is used differently than the np prefix.
 - In order to simplify global array typing, subcontainers are actually merged in the main DSP structure:
    - so 'mergeSubContainers' is used
    - global variables are added in the DSP structure
    - the JAXInitFieldsVisitor class does initialisation for waveforms. This makes it easy to use numpy
      instead of jax when initializing arrays (good for speed). We also use fUseNumpy in this decision making.
      We convert the numpy arrays to jax numpy before they're used in the tick method.
    - the fGlobalDeclarationInstructions contains global functions and variables. It is "manually" used
      to generate global functions and move global variables declaration at DSP structure level.
*/

map<string, bool> JAXInstVisitor::gFunctionSymbolTable;

dsp_factory_base* JAXCodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), "");
}

JAXCodeContainer::JAXCodeContainer(const std::string& name, int numInputs, int numOutputs, std::ostream* out)
{
    // Mandatory
    initialize(numInputs, numOutputs);
    fKlassName = name;
    fOut = out;

    // Allocate one static visitor
    if (! this->_visitor) {
        this->_visitor = new JAXInstVisitor(out, name);
    }
}

CodeContainer* JAXCodeContainer::createScalarContainer(const string& name, const Precision& precision)
{
    return new JAXScalarCodeContainer(name, 0, 1, fOut, precision);
}

CodeContainer* JAXCodeContainer::createContainer(const string& name, int numInputs, int numOutputs, ostream* dst)
{
    global::config().gDSPStruct = true;
    CodeContainer* container;

    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for JAX\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for JAX\n");
    }

    if (global::config().gOpenMPSwitch) {
        throw faustexception("ERROR : OpenMP not supported for JAX\n");
    } else if (global::config().gSchedulerSwitch) {
        throw faustexception("ERROR : Scheduler not supported for JAX\n");
    } else if (global::config().gVectorSwitch) {
        throw faustexception("ERROR : Vector not supported for JAX\n");
    } else {
        container = new JAXScalarCodeContainer(name, numInputs, numOutputs, dst, Precision::Int);
    }

    return container;
}

inline string flattenJSONforPython(const string& src)
{
    string dst;
    for (size_t i = 0; i < src.size(); i++) {
        switch (src[i]) {
            case '"':
                dst += "\\\"";
                break;
            case '\\':
                dst += "/";
                break;
            case '\'':
                dst += "'";
                break;
            default:
                dst += src[i];
                break;
        }
    }
    return dst;
}

void JAXCodeContainer::produceClass()
{
    int n = 0;

    // Print header
    *fOut << "\"\"\"" << endl
          << "Code generated with Faust version " << FAUSTVERSION << endl;
    *fOut << "Compilation options: ";
    stringstream stream;
    global::config().printCompilationOptions(stream);
    *fOut << stream.str();
    tab(n, *fOut);
    *fOut << "\"\"\"";
    tab(n, *fOut);

    if (::Faust::Primitive::Math::floatSize == 2) {
        tab(n, *fOut);
        *fOut << "# enable double precision: https://jax.readthedocs.io/en/latest/notebooks/Common_Gotchas_in_JAX.html#double-64bit-precision";
        tab(n, *fOut);
        *fOut << "from jax.config import config";
        tab(n, *fOut);
        *fOut << "config.update(\"jax_enable_x64\", True)";
        tab(n, *fOut);
        *fOut << "FAUSTFLOAT = jnp.float64";
        tab(n, *fOut);
    } else {
        tab(n, *fOut);
        *fOut << "# enable single precision";
        tab(n, *fOut);
        *fOut << "FAUSTFLOAT = jnp.float32";
        tab(n, *fOut);
    }

    // Merge sub containers
    mergeSubContainers();

    // Functions
    tab(n, *fOut);
    this->_visitor->Tab(n);

    *fOut << "class " << fKlassName << "(nn.Module):";
    tab(n + 1, *fOut);

    // Fields
    this->_visitor->Tab(n + 1);

    tab(n + 1, *fOut);
    *fOut << "sample_rate: int";

    tab(n + 1, *fOut);
    this->_visitor->Tab(n);

    tab(n + 1, *fOut);
    produceInfoFunctions(n + 1, "", "self", false, FunTyped::kDefault, this->_visitor);

    *fOut << "def initialize(self, sample_rate, x, T):";
    {
        tab(n + 2, *fOut);
        *fOut << "state = {}";
        tab(n + 2, *fOut);
        tab(n + 2, *fOut);
        *fOut << "# global declarations:";
        JAXInitFieldsVisitor initializer(fOut, n + 2);
        generateDeclarations(&initializer);
        // Generate global variables initialisation
        for (const auto& it : fGlobalDeclarationInstructions->_code) {
            if (dynamic_cast<DeclareVarInst*>(it)) {
                it->accept(&initializer);
            }
        }
        tab(n + 2, *fOut);
        tab(n + 2, *fOut);
        *fOut << "# init constants:";
        tab(n + 2, *fOut);
        this->_visitor->Tab(n + 2);
        inlineSubcontainersFunCalls(fInitInstructions)->accept(this->_visitor);
        tab(n + 2, *fOut);
        *fOut << "# inline subcontainers:";
        tab(n + 2, *fOut);
        this->_visitor->Tab(n + 2);
        inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(this->_visitor);
        tab(n + 2, *fOut);
        *fOut << "# instance clear:";
        tab(n + 2, *fOut);
        generateClear(this->_visitor);
        tab(n + 2, *fOut);
        *fOut << "return state";
        tab(n + 1, *fOut);
    }
    back(1, *fOut);

    // JSON generation
    tab(n+1, *fOut);
    *fOut << "def getJSON(self):";
    {
        string json;
        if (::Faust::Primitive::Math::floatSize == 1) {
            json = generateJSON<float>();
        } else {
            json = generateJSON<double>();
        }
        tab(n + 2, *fOut);
        *fOut << "json_str = \"\"\"" << flattenJSONforPython(json) << "\"\"\"";
        tab(n + 2, *fOut);
        *fOut << "return json.loads(json_str)";
        tab(n + 1, *fOut);
    }

    // User interface
    tab(n + 1, *fOut);
    *fOut << "def build_interface(self, state, x, T: int):";
    tab(n + 2, *fOut);
    *fOut << "ui_path = []";
    this->_visitor->Tab(n + 2);
    generateUserInterface(this->_visitor);
    tab(n + 2, *fOut);
    *fOut << "return state";

    // Compute
    tab(n + 1, *fOut);
    generateCompute(n+1);
    tab(n, *fOut);
}

void JAXCodeContainer::generateCompute(int n)
{
    // Generates declaration
    tab(n, *fOut);
    *fOut << "@staticmethod";
    tab(n, *fOut);
    *fOut << "def tick(state: dict, inputs: jnp.array):";
    tab(n + 1, *fOut);

    tab(n + 1, *fOut);
    this->_visitor->Tab(n + 1);

    // Generates local variables declaration and setup
    this->_visitor->fUseNumpy = false;
    generateComputeBlock(this->_visitor);

    auto loop = fCurLoop->generateOneSample();
    loop->accept(this->_visitor);

    generatePostComputeBlock(this->_visitor);
    this->_visitor->fUseNumpy = true;

    tab(n, *fOut);
    *fOut << "@nn.compact";
    tab(n, *fOut);
    *fOut << "def __call__(self, x, T: int) -> jnp.array:";
    tab(n + 1, *fOut);
    *fOut << "state = self.initialize(self.sample_rate, x, T)";
    tab(n + 1, *fOut);
    *fOut << "state = self.build_interface(state, x, T)";
    tab(n + 1, *fOut);
    *fOut << "# convert numpy array to jax numpy array";
    tab(n + 1, *fOut);
    *fOut << "state = jax.tree_map(jnp.array, state)";
    tab(n + 1, *fOut);
    *fOut << "return jnp.transpose(jax.lax.scan(self.tick, state, jnp.transpose(x, axes=(1, 0)))[1], axes=(1,0))";
    tab(n, *fOut);
}

BlockInst* JAXCodeContainer::inlineSubcontainersFunCalls(BlockInst* block)
{
    // Rename 'sig' in 'dsp' and remove 'dsp' allocation
    block = DspRenamer().getCode(block);
    // dump2FIR(block);

    // Inline subcontainers 'instanceInit' and 'fill' function call
    for (const auto& it : fSubContainers) {
        // Build the function to be inlined (prototype and code)
        DeclareFunInst* inst_init_fun =
            it->generateInstanceInitFun("instanceInit" + it->getClassName(), "dsp", true, false);
        // dump2FIR(inst_init_fun);
        block = FunctionCallInliner(inst_init_fun).getCode(block);
        // dump2FIR(block);

        // Build the function to be inlined (prototype and code)
        DeclareFunInst* fill_fun = it->generateFillFun("fill" + it->getClassName(), "dsp", true, false);
        // dump2FIR(fill_fun);
        block = FunctionCallInliner(fill_fun).getCode(block);
        // dump2FIR(block);
    }
    // dump2FIR(block);

    return block;
}

// Scalar
JAXScalarCodeContainer::JAXScalarCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out,
                                                   const Precision& precision)
    : JAXCodeContainer(name, numInputs, numOutputs, out)
{
    fSubContainerType = precision;
}
