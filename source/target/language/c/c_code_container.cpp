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

#include <climits>

#include "target/language/c/c_code_container.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/errors/exception.hh"
#include "target/fir/fir_function_builder.hh"
#include "compiler/types/floats.hh"
#include "global.hh"
#include "target/fir/visitor/constants_copy_to_memory.hh"

#include "faust/primitive/type/precision.hh"

#include "compiler/parser/implementation.hh"

using Precision = ::Faust::Primitive::Type::Precision;

using namespace std;

/*
 C backend and module description:
    - in -os mode:
        - subcontainers are merged in the main class
        - CScalarOneSampleCodeContainer1 (used in -os0) separates the DSP control state in iControl/fControl (possibly to be allocated elsewhere)
        - CScalarOneSampleCodeContainer2 (used in -os1) separates the DSP control state in iControl/fControl and the DSP state in iZone/fZone (possibly to be allocated elsewhere)
        - CScalarOneSampleCodeContainer3 (used in -os2) separates the DSP control state in iControl/fControl and the DSP state in iZone/fZone (possibly to be allocated elsewhere). Short delay lines remain in DSP struct, long delay lines are moved in iZone/fZone.
        Additional functions 'instanceConstantsFromMem' and 'instanceConstantsToMem' to copy iConst/fConst variables from/to memory are generated.
        - CScalarOneSampleCodeContainer4 (used in -os3) is similar to CPPScalarOneSampleCodeContainer3, but iControl/fControl and iZone/fZone pointers stay in the DSP class. The -mem option uses the memory manager to allocate/destroy the iControl/fControl and iZone/fZone pointers
 */

map<string, bool> CInstVisitor::gFunctionSymbolTable;

dsp_factory_base* CCodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), "");
}

CodeContainer* CCodeContainer::createScalarContainer(const std::string& name, int numInputs, int numOutputs, ostream* dst, const Precision& precision)
{
    if (global::config().gOneSample == 0) {
        return new CScalarOneSampleCodeContainer1(name, numInputs, numOutputs, dst, precision);
    } else if (global::config().gOneSample == 1) {
        return new CScalarOneSampleCodeContainer2(name, numInputs, numOutputs, dst, precision);
    } else if (global::config().gOneSample == 2) {
        return new CScalarOneSampleCodeContainer3(name, numInputs, numOutputs, dst, precision);
    } else if (global::config().gOneSample == 3) {
        return new CScalarOneSampleCodeContainer4(name, numInputs, numOutputs, dst, precision);
    } else {
        return new CScalarCodeContainer(name, numInputs, numOutputs, dst, precision);
    }
}

CodeContainer* CCodeContainer::createScalarContainer(const string& name, const Precision& precision)
{
    return createScalarContainer(name, 0, 1, fOut, precision);
}

CodeContainer* CCodeContainer::createContainer(const string& name, int numInputs, int numOutputs, ostream* dst)
{
    global::config().gDSPStruct = true;
    CodeContainer* container;

    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for C\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for C\n");
    }

    if (global::config().gOpenMPSwitch) {
        container = new COpenMPCodeContainer(name, numInputs, numOutputs, dst);
    } else if (global::config().gSchedulerSwitch) {
        container = new CWorkStealingCodeContainer(name, numInputs, numOutputs, dst);
    } else if (global::config().gVectorSwitch) {
        container = new CVectorCodeContainer(name, numInputs, numOutputs, dst);
    } else {
        container = createScalarContainer(name, numInputs, numOutputs, dst, Precision::Int);
    }

    return container;
}

void CCodeContainer::produceInternal()
{
    int n = 0;

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    *fOut << "typedef struct {";

    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);
    generateDeclarations(_codeProducer);

    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";

    if (!global::config().gLightMode) {
        // Memory methods
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "static " << fKlassName << "* new" << fKlassName << "() {"
              << " return (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << ")); }";

        tab(n, *fOut);
        *fOut << "static void delete" << fKlassName << "(" << fKlassName << "* dsp) { free(dsp); }";

        tab(n, *fOut);
        tab(n, *fOut);
    }
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Init
    // TODO
    // generateInstanceInitFun("instanceInit" + fKlassName, false, false)->accept(_codeProducer);

    tab(n, *fOut);
    *fOut << "static void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    generateInit(_codeProducer);
    generateResetUserInterface(_codeProducer);
    generateClear(_codeProducer);
    back(1, *fOut);
    *fOut << "}";

    // Fill
    tab(n, *fOut);
    string counter = "count";
    if (fSubContainerType == Precision::Int) {
        tab(n, *fOut);
        *fOut << "static void fill" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, int* " + fTableName + ") {", counter);
    } else {
        tab(n, *fOut);
        *fOut << "static void fill" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, $1* " + fTableName + ") {", counter, ifloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    generateComputeBlock(_codeProducer);
    ForLoopInst* loop = fCurLoop->generateScalarLoop(counter);
    loop->accept(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

void CCodeContainer::produceClass()
{
    int n = 0;

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "extern \"C\" {" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#if defined(_WIN32)" << endl;
    *fOut << "#define RESTRICT __restrict" << endl;
    *fOut << "#else" << endl;
    *fOut << "#define RESTRICT __restrict__" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    // Libraries
    printLibrary(*fOut);
    printIncludeFile(*fOut);

    // Generate gub containers
    generateSubContainers();

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    tab(n, *fOut);
    *fOut << "#ifndef FAUSTCLASS " << endl;
    *fOut << "#define FAUSTCLASS " << fKlassName << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#ifdef __APPLE__ " << endl;
    *fOut << "#define exp10f __exp10f" << endl;
    *fOut << "#define exp10 __exp10" << endl;
    *fOut << "#endif" << endl;

    if (global::config().gLightMode) {
        tab(n, *fOut);
        *fOut << "#define max(a,b) ((a < b) ? b : a)\n";
        *fOut << "#define min(a,b) ((a < b) ? a : b)\n";
        tab(n, *fOut);
    }

    tab(n, *fOut);
    *fOut << "typedef struct {";
    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);
    generateDeclarations(_codeProducer);
    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";

    // Memory methods
    tab(n, *fOut);
    if (!global::config().gLightMode) {

        if (fAllocateInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void allocate" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateAllocate(_codeProducer);
            back(1, *fOut);
            *fOut << "}";
        }
        tab(n, *fOut);

        if (fDestroyInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void destroy" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateDestroy(_codeProducer);
            back(1, *fOut);
            *fOut << "}";
            tab(n, *fOut);
        }

        *fOut << fKlassName << "* new" << fKlassName << "() { ";
        tab(n + 1, *fOut);
        *fOut << fKlassName << "* dsp = (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << "));";
        if (fAllocateInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "allocate" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "return dsp;";
        tab(n, *fOut);
        *fOut << "}";

        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void delete" << fKlassName << "(" << fKlassName << "* dsp) { ";
        if (fDestroyInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "destroy" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "free(dsp);";
        tab(n, *fOut);
        *fOut << "}";

        // Print metadata declaration
        tab(n, *fOut);
        produceMetadata(n);
    }

    // Get sample rate method
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGetSampleRate("getSampleRate" + fKlassName, "dsp", false, false)->accept(_codeProducer);

    tab(n, *fOut);
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Inits

    // TODO
    /*
     CInstVisitor codeproducer1(fOut, "");
     codeproducer1.Tab(n+1);
     generateStaticInitFun("classInit" + fKlassName, false)->accept(&codeproducer1);
     generateInstanceInitFun("instanceInit" + fKlassName, false, false)->accept(&codeproducer2);
     */

    tab(n, *fOut);
    *fOut << "void classInit" << fKlassName << "(int sample_rate) {";
    {
        tab(n + 1, *fOut);
        // Local visitor here to avoid DSP object incorrect type generation
        CInstVisitor codeproducer(fOut, "");
        codeproducer.Tab(n + 1);
        generateStaticInit(&codeproducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceResetUserInterface" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        // Local visitor here to avoid DSP object incorrect type generation
        CInstVisitor codeproducer(fOut, "");
        codeproducer.Tab(n + 1);
        generateResetUserInterface(&codeproducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceClear" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        // Local visitor here to avoid DSP object incorrect type generation
        CInstVisitor codeproducer(fOut, "");
        codeproducer.Tab(n + 1);
        generateClear(&codeproducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstants" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    {
        tab(n + 1, *fOut);
        // Local visitor here to avoid DSP object incorrect type generation
        CInstVisitor codeproducer(fOut, "");
        codeproducer.Tab(n + 1);
        generateInit(&codeproducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    *fOut << "instanceConstants" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceResetUserInterface" << fKlassName << "(dsp);";
    tab(n + 1, *fOut);
    *fOut << "instanceClear" << fKlassName << "(dsp);";
    tab(n, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void init" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    *fOut << "classInit" << fKlassName << "(sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceInit" << fKlassName << "(dsp, sample_rate);";
    tab(n, *fOut);
    *fOut << "}";

    if (!global::config().gLightMode) {
        // User interface
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void buildUserInterface" << fKlassName << "(" << fKlassName << "* dsp, UIGlue* ui_interface) {";
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateUserInterface(_codeProducer);
        back(1, *fOut);
        *fOut << "}";
    }

    // Compute
    generateCompute(n);

    // Generate user interface macros if needed
    printMacros(*fOut, n);

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "}" << endl;
    *fOut << "#endif" << endl;
}

// Used with -os0 option
void CScalarOneSampleCodeContainer1::produceClass()
{
    int n = 0;

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "extern \"C\" {" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#if defined(_WIN32)" << endl;
    *fOut << "#define RESTRICT __restrict" << endl;
    *fOut << "#else" << endl;
    *fOut << "#define RESTRICT __restrict__" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    // Libraries
    printLibrary(*fOut);
    printIncludeFile(*fOut);

    // Sub containers are merged in the main class
    mergeSubContainers();

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    tab(n, *fOut);
    *fOut << "#ifndef FAUSTCLASS " << endl;
    *fOut << "#define FAUSTCLASS " << fKlassName << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#ifdef __APPLE__ " << endl;
    *fOut << "#define exp10f __exp10f" << endl;
    *fOut << "#define exp10 __exp10" << endl;
    *fOut << "#endif" << endl;

    if (global::config().gLightMode) {
        tab(n, *fOut);
        *fOut << "#define max(a,b) ((a < b) ? b : a)\n";
        *fOut << "#define min(a,b) ((a < b) ? a : b)\n";
        tab(n, *fOut);
    }

    tab(n, *fOut);
    *fOut << "typedef struct {";
    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);
    generateDeclarations(_codeProducer);

    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#define FAUST_INT_CONTROLS " << fInt32ControlNum << endl;
    *fOut << "#define FAUST_REAL_CONTROLS " << fRealControlNum << endl;
    tab(n, *fOut);

    *fOut << "#ifndef TESTBENCH";

    // Memory methods
    tab(n, *fOut);
    if (!global::config().gLightMode) {

        if (fAllocateInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void allocate" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateAllocate(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
        }
        tab(n, *fOut);

        if (fDestroyInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void destroy" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateDestroy(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
            tab(n, *fOut);
        }

        *fOut << fKlassName << "* new" << fKlassName << "() { ";
        tab(n + 1, *fOut);
        *fOut << fKlassName << "* dsp = (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << "));";
        if (fAllocateInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "allocate" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "return dsp;";
        tab(n, *fOut);
        *fOut << "}";

        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void delete" << fKlassName << "(" << fKlassName << "* dsp) { ";
        if (fDestroyInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "destroy" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "free(dsp);";
        tab(n, *fOut);
        *fOut << "}";

        // Print metadata declaration
        tab(n, *fOut);
        produceMetadata(n);
    }

    // Get sample rate method
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGetSampleRate("getSampleRate" + fKlassName, "dsp", false, false)->accept(_codeProducer);

    tab(n, *fOut);
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Inits

    // Dummy
    tab(n, *fOut);
    *fOut << "void classInit" << fKlassName << "(int sample_rate) {}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void staticInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstants" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    {
        tab(n + 1, *fOut);
        fCodeProducer->Tab(n + 1);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fInitInstructions)->accept(fCodeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    
    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceResetUserInterface" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateResetUserInterface(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceClear" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateClear(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    // staticInit has to be called for each instance since the tables are actually not shared between instances
    tab(n + 1, *fOut);
    *fOut << "staticInit" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstants" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceResetUserInterface" << fKlassName << "(dsp);";
    tab(n + 1, *fOut);
    *fOut << "instanceClear" << fKlassName << "(dsp);";
    tab(n, *fOut);
    *fOut << "}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void init" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    *fOut << "instanceInit" << fKlassName << "(dsp, sample_rate);";
    tab(n, *fOut);
    *fOut << "}";

    if (!global::config().gLightMode) {
        // User interface
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void buildUserInterface" << fKlassName << "(" << fKlassName << "* dsp, UIGlue* ui_interface) {";
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateUserInterface(_codeProducer);
        back(1, *fOut);
        *fOut << "}";
    }

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void control" << fKlassName << "(" << fKlassName << "* dsp, " << subst("int* RESTRICT iControl, $0* RESTRICT fControl) {", ifloat());
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);
    back(1, *fOut);
    *fOut << "}" << endl;

    tab(n, *fOut);
    *fOut << "int getNumIntControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fInt32ControlNum << "; }";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "int getNumRealControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fRealControlNum << "; }";

    // Compute
    generateCompute(n);

    tab(n, *fOut);
    *fOut << "#endif // TESTBENCH" << endl;
    tab(n, *fOut);

    // Generate user interface macros if needed
    printMacros(*fOut, n);

    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "}" << endl;
    *fOut << "#endif" << endl;
}

// Used with -os1 option
void CScalarOneSampleCodeContainer2::produceClass()
{
    int n = 0;

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "extern \"C\" {" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#if defined(_WIN32)" << endl;
    *fOut << "#define RESTRICT __restrict" << endl;
    *fOut << "#else" << endl;
    *fOut << "#define RESTRICT __restrict__" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    // Libraries
    printLibrary(*fOut);
    printIncludeFile(*fOut);

    // Sub containers are merged in the main class
    mergeSubContainers();

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    tab(n, *fOut);
    *fOut << "#ifndef FAUSTCLASS " << endl;
    *fOut << "#define FAUSTCLASS " << fKlassName << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#ifdef __APPLE__ " << endl;
    *fOut << "#define exp10f __exp10f" << endl;
    *fOut << "#define exp10 __exp10" << endl;
    *fOut << "#endif" << endl;

    if (global::config().gLightMode) {
        tab(n, *fOut);
        *fOut << "#define max(a,b) ((a < b) ? b : a)\n";
        *fOut << "#define min(a,b) ((a < b) ? a : b)\n";
        tab(n, *fOut);
    }

    tab(n, *fOut);
    *fOut << "typedef struct {";
    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);
    generateDeclarations(_codeProducer);

    // Kept here because staticInit incorrectly change the size later on
    int int_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getIntZoneSize();
    int real_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getRealZoneSize();

    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#ifndef TESTBENCH";

    // Memory methods
    tab(n, *fOut);
    if (!global::config().gLightMode) {

        if (fAllocateInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void allocate" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateAllocate(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
        }
        tab(n, *fOut);

        if (fDestroyInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void destroy" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateDestroy(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
            tab(n, *fOut);
        }

        *fOut << fKlassName << "* new" << fKlassName << "() { ";
        tab(n + 1, *fOut);
        *fOut << fKlassName << "* dsp = (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << "));";
        if (fAllocateInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "allocate" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "return dsp;";
        tab(n, *fOut);
        *fOut << "}";

        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void delete" << fKlassName << "(" << fKlassName << "* dsp) { ";
        if (fDestroyInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "destroy" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "free(dsp);";
        tab(n, *fOut);
        *fOut << "}";

        // Print metadata declaration
        tab(n, *fOut);
        produceMetadata(n);
    }

    // Get sample rate method
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGetSampleRate("getSampleRate" + fKlassName, "dsp", false, false)->accept(_codeProducer);

    tab(n, *fOut);
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Inits

    // Dummy
    tab(n, *fOut);
    *fOut << "void classInit" << fKlassName << "(int sample_rate) {}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void staticInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // For waveform
        MoveVariablesInFront3().getCode(fGlobalDeclarationInstructions)->accept(_codeProducer);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceConstants" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    *fOut << "void instanceResetUserInterface" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        fCodeProducer->Tab(n + 1);
        generateResetUserInterface(fCodeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceClear" << fKlassName << "(" << fKlassName << "* dsp, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        fCodeProducer->Tab(n + 1);
        generateClear(fCodeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    // staticInit has to be called for each instance since the tables are actually not shared between instances
    tab(n + 1, *fOut);
    *fOut << "staticInit" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstants" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n + 1, *fOut);
    *fOut << "instanceResetUserInterface" << fKlassName << "(dsp);";
    tab(n + 1, *fOut);
    *fOut << "instanceClear" << fKlassName << "(dsp, iZone, fZone);";
    tab(n, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void init" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    tab(n + 1, *fOut);
    *fOut << "instanceInit" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n, *fOut);
    *fOut << "}";

    if (!global::config().gLightMode) {
        // User interface
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void buildUserInterface" << fKlassName << "(" << fKlassName << "* dsp, UIGlue* ui_interface) {";
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateUserInterface(_codeProducer);
        back(1, *fOut);
        *fOut << "}";
    }

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void control" << fKlassName << "(" << fKlassName << "* dsp, " << subst("int* RESTRICT iControl, $0* RESTRICT fControl, int* RESTRICT iZone, $0* RESTRICT fZone) {", ifloat());
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);
    back(1, *fOut);
    *fOut << "}" << endl;

    tab(n, *fOut);
    *fOut << "int getNumIntControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fInt32ControlNum << "; }";
    tab(n, *fOut);

    *fOut << "int getNumRealControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fRealControlNum << "; }";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "int getiZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return " << int_zone_size << "; }";
    tab(n, *fOut);

    *fOut << "int getfZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return " << real_zone_size << "; }";

    // Compute
    generateCompute(n);

    tab(n, *fOut);
    *fOut << "#define FAUST_INT_CONTROLS " << fInt32ControlNum << endl;
    *fOut << "#define FAUST_REAL_CONTROLS " << fRealControlNum << endl;

    tab(n, *fOut);
    *fOut << "#define FAUST_INT_ZONE " << int_zone_size << endl;
    *fOut << "#define FAUST_FLOAT_ZONE " << real_zone_size;
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#endif // TESTBENCH" << endl;
    tab(n, *fOut);

    // Generate user interface macros if needed
    printMacros(*fOut, n);

    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "}" << endl;
    *fOut << "#endif" << endl;
}

// Used with -os2 option
void CScalarOneSampleCodeContainer3::produceClass()
{
    VariableSizeCounter heap_counter(Address::kStruct);
    generateDeclarations(&heap_counter);

    char* max_size_str = getenv("FAUST_MAX_SIZE");
    int max_size = (max_size_str) ? atoi(max_size_str) : 10000;
    _codeProducer = new CInstVisitor2(fOut, fKlassName, std::max(0, heap_counter.fSizeBytes - max_size));

    int n = 0;

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "extern \"C\" {" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#if defined(_WIN32)" << endl;
    *fOut << "#define RESTRICT __restrict" << endl;
    *fOut << "#else" << endl;
    *fOut << "#define RESTRICT __restrict__" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    // Libraries
    printLibrary(*fOut);
    printIncludeFile(*fOut);

    // Sub containers are merged in the main class
    mergeSubContainers();

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    tab(n, *fOut);
    *fOut << "#ifndef FAUSTCLASS " << endl;
    *fOut << "#define FAUSTCLASS " << fKlassName << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#ifdef __APPLE__ " << endl;
    *fOut << "#define exp10f __exp10f" << endl;
    *fOut << "#define exp10 __exp10" << endl;
    *fOut << "#endif" << endl;

    if (global::config().gLightMode) {
        tab(n, *fOut);
        *fOut << "#define max(a,b) ((a < b) ? b : a)\n";
        *fOut << "#define min(a,b) ((a < b) ? a : b)\n";
        tab(n, *fOut);
    }

    tab(n, *fOut);
    *fOut << "typedef struct {";
    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);
    generateDeclarations(_codeProducer);

    // Kept here because staticInit incorrectly change the size later on
    int int_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getIntZoneSize();
    int real_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getRealZoneSize();

    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#ifndef TESTBENCH";

    // Memory methods
    tab(n, *fOut);
    if (!global::config().gLightMode) {

        if (fAllocateInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void allocate" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateAllocate(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
        }
        tab(n, *fOut);

        if (fDestroyInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void destroy" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateDestroy(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
            tab(n, *fOut);
        }

        *fOut << fKlassName << "* new" << fKlassName << "() { ";
        tab(n + 1, *fOut);
        *fOut << fKlassName << "* dsp = (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << "));";
        if (fAllocateInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "allocate" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "return dsp;";
        tab(n, *fOut);
        *fOut << "}";

        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void delete" << fKlassName << "(" << fKlassName << "* dsp) { ";
        if (fDestroyInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "destroy" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "free(dsp);";
        tab(n, *fOut);
        *fOut << "}";

        // Print metadata declaration
        tab(n, *fOut);
        produceMetadata(n);
    }

    // Get sample rate method
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGetSampleRate("getSampleRate" + fKlassName, "dsp", false, false)->accept(_codeProducer);

    tab(n, *fOut);
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Inits

    // Dummy
    tab(n, *fOut);
    *fOut << "void classInit" << fKlassName << "(int sample_rate) {}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void staticInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // For waveform
        MoveVariablesInFront3().getCode(fGlobalDeclarationInstructions)->accept(_codeProducer);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstants" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceConstantsFromMem" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    BlockInst* block1 = inlineSubcontainersFunCalls(fInitInstructions);
    ConstantsCopyFromMemory copy_from_mem(int_zone_size, real_zone_size);
    CInstVisitor visitor1(fOut, fKlassName, n + 1);
    copy_from_mem.getCode(block1)->accept(&visitor1);
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceConstantsToMem" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    BlockInst* block2 = inlineSubcontainersFunCalls(fInitInstructions);
    ConstantsCopyToMemory copy_to_mem(int_zone_size, real_zone_size);
    CInstVisitor visitor(fOut, fKlassName, n + 1);
    copy_to_mem.getCode(block2)->accept(&visitor);
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    *fOut << "void instanceResetUserInterface" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        fCodeProducer->Tab(n + 1);
        generateResetUserInterface(fCodeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceClear" << fKlassName << "(" << fKlassName << "* dsp, " << subst("int* iZone, $0* fZone) {", ifloat());
    {
        tab(n + 1, *fOut);
        fCodeProducer->Tab(n + 1);
        generateClear(fCodeProducer);
    }
    back(1, *fOut);
    *fOut << "}";
    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    // staticInit has to be called for each instance since the tables are actually not shared between instances
    tab(n + 1, *fOut);
    *fOut << "staticInit" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstants" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstantsToMem" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n + 1, *fOut);
    *fOut << "instanceResetUserInterface" << fKlassName << "(dsp);";
    tab(n + 1, *fOut);
    *fOut << "instanceClear" << fKlassName << "(dsp, iZone, fZone);";
    tab(n, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void init" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate, " << subst("int* iZone, $0* fZone) {", ifloat());
    tab(n + 1, *fOut);
    *fOut << "instanceInit" << fKlassName << "(dsp, sample_rate, iZone, fZone);";
    tab(n, *fOut);
    *fOut << "}";

    if (!global::config().gLightMode) {
        // User interface
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void buildUserInterface" << fKlassName << "(" << fKlassName << "* dsp, UIGlue* ui_interface) {";
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateUserInterface(_codeProducer);
        back(1, *fOut);
        *fOut << "}";
    }

    tab(n, *fOut);
    
    tab(n, *fOut);
    *fOut << "void control" << fKlassName << "(" << fKlassName << "* dsp, " << subst("int* RESTRICT iControl, $0* RESTRICT fControl, int* RESTRICT iZone, $0* RESTRICT fZone) {", ifloat());
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);
    back(1, *fOut);
    *fOut << "}" << endl;

    tab(n, *fOut);
    *fOut << "int getNumIntControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fInt32ControlNum << "; }";
    tab(n, *fOut);

    *fOut << "int getNumRealControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fRealControlNum << "; }";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "int getiZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << copy_from_mem.fIntIndex << "; }";
    tab(n, *fOut);

    *fOut << "int getfZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << copy_from_mem.fRealIndex << "; }";

    // Compute
    generateCompute(n);

    tab(n, *fOut);
    *fOut << "#define FAUST_INT_CONTROLS " << fInt32ControlNum << endl;
    *fOut << "#define FAUST_REAL_CONTROLS " << fRealControlNum << endl;

    tab(n, *fOut);
    // copy_from_mem.fIntIndex and copy_from_mem.fRealIndex contains the size used for tables, DLs and iConst/fConst variables
    *fOut << "#define FAUST_INT_ZONE " << copy_from_mem.fIntIndex << endl;
    *fOut << "#define FAUST_FLOAT_ZONE " << copy_from_mem.fRealIndex;
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#endif // TESTBENCH" << endl;
    tab(n, *fOut);

    // Generate user interface macros if needed
    printMacros(*fOut, n);

    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "}" << endl;
    *fOut << "#endif" << endl;
}

// Used with -os3 option
void CScalarOneSampleCodeContainer4::produceClass()
{
    VariableSizeCounter heap_counter(Address::kStruct);
    generateDeclarations(&heap_counter);

    char* max_size_str = getenv("FAUST_MAX_SIZE");
    int max_size = (max_size_str) ? atoi(max_size_str) : 10000;
    _codeProducer = new CInstVisitor3(fOut, fKlassName, std::max(0, heap_counter.fSizeBytes - max_size));

    int n = 0;

    tab(n, *fOut);
    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "extern \"C\" {" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#if defined(_WIN32)" << endl;
    *fOut << "#define RESTRICT __restrict" << endl;
    *fOut << "#else" << endl;
    *fOut << "#define RESTRICT __restrict__" << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    // Libraries
    printLibrary(*fOut);
    printIncludeFile(*fOut);

    // Sub containers are merged in the main class
    mergeSubContainers();

    // Global declarations
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGlobalDeclarations(_codeProducer);

    tab(n, *fOut);
    *fOut << "#ifndef FAUSTCLASS " << endl;
    *fOut << "#define FAUSTCLASS " << fKlassName << endl;
    *fOut << "#endif" << endl;
    tab(n, *fOut);

    *fOut << "#ifdef __APPLE__ " << endl;
    *fOut << "#define exp10f __exp10f" << endl;
    *fOut << "#define exp10 __exp10" << endl;
    *fOut << "#endif" << endl;

    if (global::config().gLightMode) {
        tab(n, *fOut);
        *fOut << "#define max(a,b) ((a < b) ? b : a)\n";
        *fOut << "#define min(a,b) ((a < b) ? a : b)\n";
        tab(n, *fOut);
    }

    tab(n, *fOut);
    *fOut << "typedef struct {";
    tab(n + 1, *fOut);

    // Fields
    _codeProducer->Tab(n + 1);

    // Additional fields
    pushDeclare(InstBuilder::genDecStructVar("iControl", InstBuilder::genArrayTyped(InstBuilder::genInt32Typed(), 0)));
    pushDeclare(InstBuilder::genDecStructVar("fControl", InstBuilder::genArrayTyped(InstBuilder::genItFloatTyped(), 0)));
    pushDeclare(InstBuilder::genDecStructVar("iZone", InstBuilder::genArrayTyped(InstBuilder::genInt32Typed(), 0)));
    pushDeclare(InstBuilder::genDecStructVar("fZone", InstBuilder::genArrayTyped(InstBuilder::genItFloatTyped(), 0)));
    generateDeclarations(_codeProducer);

    // Kept here because staticInit incorrectly change the size later on
    int int_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getIntZoneSize();
    int real_zone_size = static_cast<CInstVisitor1*>(_codeProducer)->getRealZoneSize();

    back(1, *fOut);
    *fOut << "} " << fKlassName << ";";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#ifndef TESTBENCH";

    // Memory methods
    tab(n, *fOut);
    if (!global::config().gLightMode) {

        if (fAllocateInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void allocate" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateAllocate(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
        }
        tab(n, *fOut);

        if (fDestroyInstructions->_code.size() > 0) {
            tab(n, *fOut);
            *fOut << "static void destroy" << fKlassName << "(" << fKlassName << "* dsp) {";
            tab(n + 1, *fOut);
            generateDestroy(_codeProducer);
            tab(n, *fOut);
            *fOut << "}";
            tab(n, *fOut);
        }

        *fOut << fKlassName << "* new" << fKlassName << "(int* icontrol, " << ifloat() << "* fcontrol, int* izone, " << ifloat() << "* fzone) {";
        tab(n + 1, *fOut);
        *fOut << fKlassName << "* dsp = (" << fKlassName << "*)calloc(1, sizeof(" << fKlassName << "));";
        if (fAllocateInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "allocate" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "dsp->iControl = icontrol;";
        tab(n + 1, *fOut);
        *fOut << "dsp->fControl = fcontrol;";
        tab(n + 1, *fOut);
        *fOut << "dsp->iZone = izone;";
        tab(n + 1, *fOut);
        *fOut << "dsp->fZone = fzone;";
        tab(n + 1, *fOut);
        *fOut << "return dsp;";
        tab(n, *fOut);
        *fOut << "}";

        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void delete" << fKlassName << "(" << fKlassName << "* dsp) { ";
        if (fDestroyInstructions->_code.size() > 0) {
            tab(n + 1, *fOut);
            *fOut << "destroy" << fKlassName << "(dsp);";
        }
        tab(n + 1, *fOut);
        *fOut << "free(dsp);";
        tab(n, *fOut);
        *fOut << "}";

        // setMemory
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void setMemory" << fKlassName << "(" << fKlassName << "* dsp, int* icontrol, " << ifloat() << "* fcontrol, int* izone, " << ifloat() << "* fzone) {";
        tab(n + 1, *fOut);
        *fOut << "dsp->iControl = icontrol;";
        tab(n + 1, *fOut);
        *fOut << "dsp->fControl = fcontrol;";
        tab(n + 1, *fOut);
        *fOut << "dsp->iZone = izone;";
        tab(n + 1, *fOut);
        *fOut << "dsp->fZone = fzone;";
        tab(n, *fOut);
        *fOut << "}";

        // Print metadata declaration
        tab(n, *fOut);
        produceMetadata(n);
    }

    // Get sample rate method
    tab(n, *fOut);
    _codeProducer->Tab(n);
    generateGetSampleRate("getSampleRate" + fKlassName, "dsp", false, false)->accept(_codeProducer);

    tab(n, *fOut);
    produceInfoFunctions(n, fKlassName, "dsp", false, FunTyped::kDefault, _codeProducer);

    // Inits

    // Dummy
    tab(n, *fOut);
    *fOut << "void classInit" << fKlassName << "(int sample_rate) {}";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "void staticInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // For waveform
        MoveVariablesInFront3().getCode(fGlobalDeclarationInstructions)->accept(_codeProducer);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceResetUserInterface" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateResetUserInterface(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceClear" << fKlassName << "(" << fKlassName << "* dsp) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateClear(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstants" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    {
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
        inlineSubcontainersFunCalls(fInitInstructions)->accept(_codeProducer);
    }
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstantsFromMem" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    BlockInst* block1 = inlineSubcontainersFunCalls(fInitInstructions);
    ConstantsCopyFromMemory1 copy_from_mem(int_zone_size, real_zone_size);
    CInstVisitor visitor1(fOut, fKlassName, n + 1);
    copy_from_mem.getCode(block1)->accept(&visitor1);
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceConstantsToMem" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    BlockInst* block2 = inlineSubcontainersFunCalls(fInitInstructions);
    ConstantsCopyToMemory1 copy_to_mem(int_zone_size, real_zone_size);
    CInstVisitor visitor(fOut, fKlassName, n + 1);
    copy_to_mem.getCode(block2)->accept(&visitor);
    // Keep the updated values
    int_zone_size = copy_from_mem.fIntIndex;
    real_zone_size = copy_from_mem.fRealIndex;
    back(1, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void instanceInit" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    // staticInit has to be called for each instance since the tables are actually not shared between instances
    tab(n + 1, *fOut);
    *fOut << "staticInit" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstants" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceConstantsToMem" << fKlassName << "(dsp, sample_rate);";
    tab(n + 1, *fOut);
    *fOut << "instanceResetUserInterface" << fKlassName << "(dsp);";
    tab(n + 1, *fOut);
    *fOut << "instanceClear" << fKlassName << "(dsp);";
    tab(n, *fOut);
    *fOut << "}";

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void init" << fKlassName << "(" << fKlassName << "* dsp, int sample_rate) {";
    tab(n + 1, *fOut);
    *fOut << "instanceInit" << fKlassName << "(dsp, sample_rate);";
    tab(n, *fOut);
    *fOut << "}";

    if (!global::config().gLightMode) {
        // User interface
        tab(n, *fOut);
        tab(n, *fOut);
        *fOut << "void buildUserInterface" << fKlassName << "(" << fKlassName << "* dsp, UIGlue* ui_interface) {";
        tab(n + 1, *fOut);
        _codeProducer->Tab(n + 1);
        generateUserInterface(_codeProducer);
        back(1, *fOut);
        *fOut << "}";
    }

    tab(n, *fOut);
    tab(n, *fOut);
    *fOut << "void control" << fKlassName << "(" << fKlassName << "* dsp) {";
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);
    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);
    back(1, *fOut);
    *fOut << "}" << endl;

    tab(n, *fOut);
    *fOut << "int getNumIntControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fInt32ControlNum << "; }";
    tab(n, *fOut);

    *fOut << "int getNumRealControls" << fKlassName << "(" << fKlassName << "* dsp) { return "
    << fRealControlNum << "; }";
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "int getiZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return " << int_zone_size << "; }";
    tab(n, *fOut);

    *fOut << "int getfZoneSize" << fKlassName << "(" << fKlassName << "* dsp) { return " << real_zone_size << "; }";

    // Compute
    generateCompute(n);

    tab(n, *fOut);
    *fOut << "#define FAUST_INT_CONTROLS " << fInt32ControlNum << endl;
    *fOut << "#define FAUST_REAL_CONTROLS " << fRealControlNum << endl;

    tab(n, *fOut);
    // int_zone_size and real_zone_size contains the size used for tables, DLs and iConst/fConst variables
    *fOut << "#define FAUST_INT_ZONE " << int_zone_size << endl;
    *fOut << "#define FAUST_FLOAT_ZONE " << real_zone_size;
    tab(n, *fOut);

    tab(n, *fOut);
    *fOut << "#endif // TESTBENCH" << endl;
    tab(n, *fOut);

    // Generate user interface macros if needed
    printMacros(*fOut, n);

    *fOut << "#ifdef __cplusplus" << endl;
    *fOut << "}" << endl;
    *fOut << "#endif" << endl;
}

void CCodeContainer::produceMetadata(int tabs)
{
    tab(tabs, *fOut);
    *fOut << "void metadata" << fKlassName << "(MetaGlue* m) { ";

    // We do not want to accumulate metadata from all hierachical levels, so the upper level only is kept
    for (const auto& i : gMetaDataSet()) {
        if (i.first != tree("author")) {
            tab(tabs + 1, *fOut);
            *fOut << "m->declare(m->metaInterface, \"" << *(i.first) << "\", " << **(i.second.begin()) << ");";
        } else {
            // But the "author" meta data is accumulated, the upper level becomes the main author and sub-levels become
            // "contributor"
            for (set<Tree>::iterator j = i.second.begin(); j != i.second.end(); j++) {
                if (j == i.second.begin()) {
                    tab(tabs + 1, *fOut);
                    *fOut << "m->declare(m->metaInterface, \"" << *(i.first) << "\", " << **j << ");";
                } else {
                    tab(tabs + 1, *fOut);
                    *fOut << "m->declare(m->metaInterface, \""
                          << "contributor"
                          << "\", " << **j << ");";
                }
            }
        }
    }

    tab(tabs, *fOut);
    *fOut << "}" << endl;
}

// Scalar
CScalarCodeContainer::CScalarCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out,
                                           const Precision& precision)
    : CCodeContainer(name, numInputs, numOutputs, out)
{
    fSubContainerType = precision;
}

void CScalarCodeContainer::generateComputeAux(int n)
{
    // Generates declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, $1** inputs, $1** outputs) {", fFullCount, xfloat());
    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, $1** RESTRICT inputs, $1** RESTRICT outputs) {", fFullCount, xfloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);

    // Generates one single scalar loop
    ForLoopInst* loop = fCurLoop->generateScalarLoop(fFullCount);
    loop->accept(_codeProducer);

    /*
     // TODO : atomic switch
     // Currently for soundfile management
     */
    generatePostComputeBlock(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// Used with -os0 option
void CScalarOneSampleCodeContainer1::generateComputeAux(int n)
{
    // Generates declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, $0* inputs, $0* outputs, int* RESTRICT iControl, $0* RESTRICT fControl) {", ifloat());
    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, $0* RESTRICT inputs, $0* RESTRICT outputs, int* RESTRICT iControl, $0* RESTRICT fControl) {", ifloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates one sample computation
    BlockInst* block = fCurLoop->generateOneSample();
    block->accept(_codeProducer);

    /*
     // TODO : atomic switch
     // Currently for soundfile management
     */
    generatePostComputeBlock(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// Used with -os1 and -os2 option
void CScalarOneSampleCodeContainer2::generateComputeAux(int n)
{
    // Generates declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, $0* inputs, $0* outputs, int* RESTRICT iControl, $0* RESTRICT fControl, int* RESTRICT iZone, $0* RESTRICT fZone) {", ifloat());

    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, $0* RESTRICT inputs, $0* RESTRICT outputs, int* RESTRICT iControl, $0* RESTRICT fControl, int* RESTRICT iZone, $0* RESTRICT fZone) {", ifloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates one sample computation
    BlockInst* block = fCurLoop->generateOneSample();
    block->accept(_codeProducer);

    /*
     // TODO : atomic switch
     // Currently for soundfile management
     */
    generatePostComputeBlock(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// Used with -os3 option
void CScalarOneSampleCodeContainer4::generateComputeAux(int n)
{
    // Generates declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, $0* inputs, $0* outputs) {", xfloat(), ifloat());

    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, $0* RESTRICT inputs, $0* RESTRICT outputs) {", xfloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates one sample computation
    BlockInst* block = fCurLoop->generateOneSample();
    block->accept(_codeProducer);

    /*
     // TODO : atomic switch
     // Currently for soundfile management
     */
    generatePostComputeBlock(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// Vector
CVectorCodeContainer::CVectorCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out)
    : VectorCodeContainer(numInputs, numOutputs), CCodeContainer(name, numInputs, numOutputs, out)
{
}

void CVectorCodeContainer::generateComputeAux(int n)
{
    // Generates declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, $1** inputs, $1** outputs) {", fFullCount, xfloat());
    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
              << subst("* dsp, int $0, $1** RESTRICT inputs, $1** RESTRICT outputs) {", fFullCount, xfloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);

    // Generates the DSP loop
    fDAGBlock->accept(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// OpenMP
COpenMPCodeContainer::COpenMPCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out)
    : OpenMPCodeContainer(numInputs, numOutputs), CCodeContainer(name, numInputs, numOutputs, out)
{
}

void COpenMPCodeContainer::generateComputeAux(int n)
{
    // Compute declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, int $0, $1** inputs, $1** outputs) {", fFullCount, xfloat());
    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, int $0, $1** RESTRICT inputs, $1** RESTRICT outputs) {", fFullCount, xfloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);

    // Generate it
    fGlobalLoopBlock->accept(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;
}

// Works stealing scheduler
CWorkStealingCodeContainer::CWorkStealingCodeContainer(const string& name, int numInputs, int numOutputs,
                                                       std::ostream* out)
    : WSSCodeContainer(numInputs, numOutputs, "dsp"), CCodeContainer(name, numInputs, numOutputs, out)
{
}

void CWorkStealingCodeContainer::generateComputeAux(int n)
{
    // Generates "computeThread" code
    tab(n, *fOut);
    *fOut << "static void computeThread" << fKlassName << "(" << fKlassName << "* dsp, int num_thread) {";
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generate it
    fThreadLoopBlock->accept(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;

    // Compute "compute" declaration
    tab(n, *fOut);
    if (global::config().gInPlace) {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, int $0, $1** inputs, $1** outputs) {", fFullCount, xfloat());
    } else {
        *fOut << "void compute" << fKlassName << "(" << fKlassName
        << subst("* dsp, int $0, $1** RESTRICT inputs, $1** RESTRICT outputs) {", fFullCount, xfloat());
    }
    tab(n + 1, *fOut);
    _codeProducer->Tab(n + 1);

    // Generates local variables declaration and setup
    generateComputeBlock(_codeProducer);

    back(1, *fOut);
    *fOut << "}" << endl;

    tab(n, *fOut);
    *fOut << "extern \"C\" void computeThreadExternal(void* dsp, int num_thread) {";
    tab(n + 1, *fOut);
    *fOut << "computeThread" << fKlassName << "((" << fKlassName << "*)dsp, num_thread);";
    tab(n, *fOut);
    *fOut << "}" << endl;
}
