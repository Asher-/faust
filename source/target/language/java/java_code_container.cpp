/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#include "target/language/java/java_code_container.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/errors/exception.hh"
#include "compiler/types/floats.hh"
#include "global.hh"
#include "faust/primitive/math.hh"

#include "faust/primitive/type/precision.hh"

using Precision = ::Faust::Primitive::Type::Precision;

using namespace std;

map<string, bool>   JAVAInstVisitor::gFunctionSymbolTable;
map<string, string> JAVAInstVisitor::gMathLibTable;

dsp_factory_base* JAVACodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), "");
}

CodeContainer* JAVACodeContainer::createScalarContainer(const string& name, const Precision& precision)
{
    return new JAVAScalarCodeContainer(name, "", 0, 1, fOut, precision);
}

CodeContainer* JAVACodeContainer::createContainer(const string& name, const string& super, int numInputs,
                                                  int numOutputs, ostream* dst)
{
    CodeContainer* container;

    if (::Faust::Primitive::Math::floatSize == 3) {
        throw faustexception("ERROR : quad format not supported for Java\n");
    }
    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for Java\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for Java\n");
    }

    if (global::config().gOpenMPSwitch) {
        throw faustexception("ERROR : OpenMP not supported for Java\n");
    } else if (global::config().gSchedulerSwitch) {
        throw faustexception("ERROR : Scheduler not supported for Java\n");
    } else if (global::config().gVectorSwitch) {
        throw faustexception("ERROR : Vector mode not supported for Java\n");
    } else {
        container = new JAVAScalarCodeContainer(name, super, numInputs, numOutputs, dst, Precision::Int);
    }

    return container;
}

// Scalar
JAVAScalarCodeContainer::JAVAScalarCodeContainer(const string& name, const string& super, int numInputs, int numOutputs,
                                                 std::ostream* out, const Precision& precision)
    : JAVACodeContainer(name, super, numInputs, numOutputs, out)
{
    fSubContainerType = precision;
}

JAVAScalarCodeContainer::~JAVAScalarCodeContainer()
{
}

void JAVACodeContainer::produceInternal()
{
    int n = 1;

    // Global declarations
    tab(n, *fOut);
    _codeProducer.Tab(n);
    // generateGlobalDeclarations(&_codeProducer);

    tab(n, *fOut);
    *fOut << "final class " << fKlassName << " {";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);

    // Fields
    _codeProducer.Tab(n + 1);
    generateDeclarations(&_codeProducer);

    tab(n + 1, *fOut);
    // fKlassName used in method naming for subclasses
    produceInfoFunctions(n + 1, fKlassName, "dsp", true, FunTyped::kDefault, &_codeProducer);

    // TODO
    // generateInstanceInitFun("instanceInit" + fKlassName, true, false)->accept(&_codeProducer);

    // Inits
    tab(n + 1, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(int sample_rate) {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateInit(&_codeProducer);
    generateResetUserInterface(&_codeProducer);
    generateClear(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    // Fill
    string counter = "count";
    if (fSubContainerType == Precision::Int) {
        tab(n + 1, *fOut);
        *fOut << "void fill" << fKlassName << subst("(int $0, int[] output) {", counter);
    } else {
        tab(n + 1, *fOut);
        *fOut << "void fill" << fKlassName << subst("(int $0, $1[] output) {", counter, ifloat());
    }
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateComputeBlock(&_codeProducer);
    ForLoopInst* loop = fCurLoop->generateScalarLoop(counter);
    loop->accept(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    *fOut << "};" << endl;

    // Memory methods (as globals)
    tab(n, *fOut);
    *fOut << fKlassName << " new" << fKlassName << "() {"
          << "return new " << fKlassName << "()"
          << "; }";

    tab(n, *fOut);
    *fOut << "void delete" << fKlassName << "(" << fKlassName << " dsp) {}";
    tab(n, *fOut);
}

void JAVACodeContainer::produceClass()
{
    int n = 0;

    // Libraries
    printLibrary(*fOut);

    tab(n, *fOut);
    *fOut << "public class " << fKlassName << " extends " << fSuperKlassName << " {";

    // Global declarations
    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    _codeProducer.Tab(n + 1);
    generateGlobalDeclarations(&_codeProducer);

    // Generate gub containers
    generateSubContainers();

    // Fields
    tab(n + 1, *fOut);
    _codeProducer.Tab(n + 1);
    generateDeclarations(&_codeProducer);

    if (fAllocateInstructions->_code.size() > 0) {
        tab(n + 1, *fOut);
        *fOut << "void allocate() {";
        tab(n + 2, *fOut);
        _codeProducer.Tab(n + 2);
        generateAllocate(&_codeProducer);
        tab(n + 1, *fOut);
        *fOut << "}";
        tab(n + 1, *fOut);
    }

    if (fDestroyInstructions->_code.size() > 0) {
        tab(n + 1, *fOut);
        *fOut << "void destroy() {";
        tab(n + 2, *fOut);
        _codeProducer.Tab(n + 2);
        generateDestroy(&_codeProducer);
        tab(n + 1, *fOut);
        *fOut << "}";
        tab(n + 1, *fOut);
    }

    // Print metadata declaration
    tab(n + 1, *fOut);
    *fOut << "public void metadata(Meta m) { ";

    for (const auto& i : global::config().gMetaDataSet) {
        if (i.first != tree("author")) {
            tab(n + 2, *fOut);
            *fOut << "m.declare(\"" << *(i.first) << "\", " << **(i.second.begin()) << ");";
        } else {
            for (set<Tree>::iterator j = i.second.begin(); j != i.second.end(); j++) {
                if (j == i.second.begin()) {
                    tab(n + 2, *fOut);
                    *fOut << "m.declare(\"" << *(i.first) << "\", " << **j << ");";
                } else {
                    tab(n + 2, *fOut);
                    *fOut << "m.declare(\""
                          << "contributor"
                          << "\", " << **j << ");";
                }
            }
        }
    }

    tab(n + 1, *fOut);
    *fOut << "}" << endl;

    tab(n + 1, *fOut);
    // No class name for main class
    produceInfoFunctions(n + 1, "", "dsp", true, FunTyped::kVirtual, &_codeProducer);

    // Inits

    // TODO
    /*
    generateStaticInitFun("classInit", false)->accept(&_codeProducer);
    generateInstanceInitFun("instanceInit", true, true)->accept(&_codeProducer);
    */

    tab(n + 1, *fOut);
    *fOut << "public void classInit(int sample_rate) {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateStaticInit(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void instanceConstants(int sample_rate) {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateInit(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void instanceResetUserInterface() {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateResetUserInterface(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void instanceClear() {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateClear(&_codeProducer);
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void init(int sample_rate) {";
    tab(n + 2, *fOut);
    *fOut << "classInit(sample_rate);";
    tab(n + 2, *fOut);
    *fOut << "instanceInit(sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void instanceInit(int sample_rate) {";
    tab(n + 2, *fOut);
    *fOut << "instanceConstants(sample_rate);";
    tab(n + 2, *fOut);
    *fOut << "instanceResetUserInterface();";
    tab(n + 2, *fOut);
    *fOut << "instanceClear();";
    tab(n + 1, *fOut);
    *fOut << "}";

    // User interface
    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void buildUserInterface(UI ui_interface) {";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateUserInterface(&_codeProducer);
    printlines(n + 2, fUICode, *fOut);
    tab(n + 1, *fOut);
    *fOut << "}";

    // Compute
    generateCompute(n);

    // Possibly generate separated functions
    _codeProducer.Tab(n + 1);
    tab(n + 1, *fOut);
    generateComputeFunctions(&_codeProducer);

    tab(n, *fOut);
    *fOut << "};\n" << endl;
}

void JAVAScalarCodeContainer::generateCompute(int n)
{
    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << subst("public void compute(int $0, $1[][] inputs, $1[][] outputs) {", fFullCount, ifloat());
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);

    // Generates local variables declaration and setup
    generateComputeBlock(&_codeProducer);

    // Generates one single scalar loop
    ForLoopInst* loop = fCurLoop->generateScalarLoop(fFullCount);
    loop->accept(&_codeProducer);

    tab(n + 1, *fOut);
    *fOut << "}";
}
