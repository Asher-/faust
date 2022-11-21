/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2021 GRAME, Centre National de Creation Musicale
    Modified to C# from Java by Mike Oliphant
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

#include "target/language/csharp/csharp_code_container.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/errors/exception.hh"
#include "compiler/types/floats.hh"
#include "global.hh"

#include "faust/primitive/math.hh"

#include "faust/primitive/type/precision.hh"

using Precision = ::Faust::Primitive::Type::Precision;

using namespace std;

map<string, bool>   CSharpInstVisitor::gFunctionSymbolTable;
map<string, string> CSharpInstVisitor::gMathLibTable;

dsp_factory_base* CSharpCodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), "");
}

CodeContainer* CSharpCodeContainer::createScalarContainer(const string& name, const Precision& precision)
{
    return new CSharpScalarCodeContainer(name, "", 0, 1, fOut, precision);
}

CodeContainer* CSharpCodeContainer::createContainer(const string& name, const string& super, int numInputs,
                                                  int numOutputs, ostream* dst)
{
    CodeContainer* container;

    if (::Faust::Primitive::Math::floatSize == 3) {
        throw faustexception("ERROR : quad format not supported for CSharp\n");
    }
    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for CSharp\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for CSharp\n");
    }

    if (global::config().gOpenMPSwitch) {
        throw faustexception("ERROR : OpenMP not supported for CSharp\n");
    } else if (global::config().gSchedulerSwitch) {
        throw faustexception("ERROR : Scheduler not supported for CSharp\n");
    } else if (global::config().gVectorSwitch) {
        throw faustexception("ERROR : Vector mode not supported for CSharp\n");
    } else {
        container = new CSharpScalarCodeContainer(name, super, numInputs, numOutputs, dst, Precision::Int);
    }

    return container;
}

// Scalar
CSharpScalarCodeContainer::CSharpScalarCodeContainer(const string& name, const string& super, int numInputs,
                                                   int numOutputs,
                                                 std::ostream* out, const Precision& precision)
    : CSharpCodeContainer(name, super, numInputs, numOutputs, out)
{
    fSubContainerType = precision;
}

CSharpScalarCodeContainer::~CSharpScalarCodeContainer()
{
}

void CSharpCodeContainer::produceInternal()
{
    int n = 1;

    // Global declarations
    tab(n, *fOut);
    _codeProducer.Tab(n);
    generateGlobalDeclarations(&_codeProducer);

    tab(n, *fOut);
    *fOut << "class " << fKlassName;
    tab(n, *fOut);
    *fOut << "{";

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
    *fOut << "public void instanceInit" << fKlassName << "(int sample_rate) {";
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
        *fOut << "public void fill" << fKlassName << subst("(int $0, int[] " + fTableName + ") { ", counter);
    } else {
        tab(n + 1, *fOut);
        *fOut << "public void fill" << fKlassName << subst("(int $0, $1[] " + fTableName + ") {", counter, ifloat());
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

void CSharpCodeContainer::produceClass()
{
    int n = 0;

    // Libraries
    printLibrary(*fOut);
    tab(n, *fOut);
        
    tab(n, *fOut);
    *fOut << "public class " << fKlassName << " : " << fSuperKlassName << ", " << "IFaustDSP";
    tab(n, *fOut);
    *fOut << "{";

    // Global declarations
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

    tab(n + 1, *fOut);
    *fOut << "public " << fKlassName << "()";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    *fOut << "SetMetaData();";
    tab(n + 2, *fOut);
    *fOut << "BuildUserInterface();";
    tab(n + 1, *fOut);
    *fOut << "}";
    tab(n + 1, *fOut);

    tab(n + 1, *fOut);
    produceInfoFunctions(n + 1, "", "dsp", true, FunTyped::kVirtual, &_codeProducer);

    // Print metadata declaration
    tab(n + 1, *fOut);
    *fOut << "void SetMetaData()";
    tab(n + 1, *fOut);
    *fOut << "{";

    for (auto& i : global::config().gMetaDataSet) {
        if (i.first != tree("author")) {
            tab(n + 2, *fOut);
            *fOut << "MetaData.Declare(\"" << *(i.first) << "\", " << **(i.second.begin()) << ");";
        } else {
            for (set<Tree>::iterator j = i.second.begin(); j != i.second.end(); j++) {
                if (j == i.second.begin()) {
                    tab(n + 2, *fOut);
                    *fOut << "MetaData.Declare(\"" << *(i.first) << "\", " << **j << ");";
                } else {
                    tab(n + 2, *fOut);
                    *fOut << "MetaData.Declare(\""
                          << "contributor"
                          << "\", " << **j << ");";
                }
            }
        }
    }

    tab(n + 1, *fOut);
    *fOut << "}" << endl;

    // User interface
    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "void BuildUserInterface()";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateUserInterface(&_codeProducer);
    printlines(n + 2, fUICode, *fOut);
    back(1, *fOut);
    *fOut << "}" << endl;

    // Inits

    // TODO
    /*
    generateStaticInitFun("classInit", false)->accept(&_codeProducer);
    generateInstanceInitFun("instanceInit", true, true)->accept(&_codeProducer);
    */

    tab(n + 1, *fOut);
    *fOut << "public void ClassInit(int sample_rate)";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateStaticInit(&_codeProducer);
    back(1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void InstanceConstants(int sample_rate)";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateInit(&_codeProducer);
    back(1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void InstanceResetUserInterface()";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateResetUserInterface(&_codeProducer);
    back(1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void InstanceClear()";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);
    generateClear(&_codeProducer);
    back(1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void Init(int sample_rate)";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    *fOut << "ClassInit(sample_rate);";
    tab(n + 2, *fOut);
    *fOut << "InstanceInit(sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "}";

    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << "public void InstanceInit(int sample_rate)";
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    *fOut << "InstanceConstants(sample_rate);";
    tab(n + 2, *fOut);
    *fOut << "InstanceResetUserInterface();";
    tab(n + 2, *fOut);
    *fOut << "InstanceClear();";
    tab(n + 1, *fOut);
    *fOut << "}";

    // Compute
    generateCompute(n);

    // Possibly generate separated functions
    _codeProducer.Tab(n + 1);
    tab(n + 1, *fOut);
    generateComputeFunctions(&_codeProducer);

    back(1, *fOut);
    *fOut << "};\n" << endl;
}

void CSharpCodeContainer::produceInfoFunctions(int tabs, const string& classname, const string& obj, bool ismethod,
                                            FunTyped::FunAttribute funtype, TextInstVisitor* producer)
{
    // Input/Output method
    producer->Tab(tabs);
    generateGetInputs(subst("GetNumInputs$0", classname), obj, ismethod, funtype)->accept(producer);
    generateGetOutputs(subst("GetNumOutputs$0", classname), obj, ismethod, funtype)->accept(producer);
}

void CSharpScalarCodeContainer::generateCompute(int n)
{
    tab(n + 1, *fOut);
    tab(n + 1, *fOut);
    *fOut << subst("public void Compute(int $0, $1[][] inputs, $1[][] outputs)", fFullCount, ifloat());
    tab(n + 1, *fOut);
    *fOut << "{";
    tab(n + 2, *fOut);
    _codeProducer.Tab(n + 2);

    // Generates local variables declaration and setup
    generateComputeBlock(&_codeProducer);

    // Generates one single scalar loop
    ForLoopInst* loop = fCurLoop->generateScalarLoop(fFullCount);
    loop->accept(&_codeProducer);

    /*
     // TODO : atomic switch
     // Currently for soundfile management
     */
    generatePostComputeBlock(&_codeProducer);

    back(1, *fOut);
    *fOut << "}";
}
