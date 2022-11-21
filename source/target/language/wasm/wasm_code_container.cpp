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

#include "target/language/wasm/wasm_code_container.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/errors/exception.hh"
#include "compiler/types/floats.hh"
#include "global.hh"
#include "rn_base64.h"
#include "target/fir/visitor/function_call_inliner.hh"
#include "target/fir/visitor/loop_variable_renamer.hh"

#include "faust/primitive/math.hh"

#include "faust/primitive/type/precision.hh"

using Precision = ::Faust::Primitive::Type::Precision;

using namespace std;

/*
 WASM backend and module description:

 - mathematical functions are either part of WebAssembly (like f32.sqrt, f32.main, f32.max), are imported from JS
 "global.Math", or are externally implemented (fmod and remainder in JS)
 - local variables have to be declared first on the block, before being actually initialized or set : this is done using
 MoveVariablesInFront3
 - 'faustpower' function fallbacks to regular 'pow' (see powprim.h)
 - subcontainers are inlined in 'classInit' and 'instanceConstants' functions
 - waveform generation is 'inlined' using MoveVariablesInFront3, done in a special version of generateInstanceInitFun
 - integer 'min/max' is done in the module in 'min_i/max_i' (using lt/select)
 - LocalVariableCounter visitor allows to count and create local variables of each types
 - FunAndTypeCounter visitor allows to count and create function types and global variable offset
 - memory can be allocated internally in the module and exported, or externally in JS and imported
 - the JSON string is written at offset 0 in a data segment. This string *has* to be converted in a JS string *before*
 using the DSP instance
 - memory module size cannot be written while generating the output stream, since DSP size is computed when inlining
 subcontainers and waveforms. The final memory size is finally written after module code generation.
 - in Load/Store, check if address is constant, so that to be used as an 'offset'
 - move loop 'i' variable by bytes instead of frames to save index code generation of input/output accesses
 (gLoopVarInBytes)
 - offset of inputs/outputs are constant, so can be directly generated

*/

dsp_factory_base* WASMCodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), fHelper.str());
}

WASMCodeContainer::WASMCodeContainer(const string& name, int numInputs, int numOutputs, ostream* out,
                                     bool internal_memory)
    : fOut(out)
{
    initialize(numInputs, numOutputs);
    fKlassName      = name;
    fInternalMemory = internal_memory;

    // Allocate one static visitor to be shared by main and sub containers
    if (!this->_visitor) {
        this->_visitor = new WASMInstVisitor(&fBinaryOut, internal_memory);
    }
}

CodeContainer* WASMCodeContainer::createScalarContainer(const string& name, const Precision& precision)
{
    return new WASMScalarCodeContainer(name, 0, 1, fOut, precision, true);
}

CodeContainer* WASMCodeContainer::createScalarContainer(const string& name, const Precision& precision,
                                                        bool internal_memory)
{
    return new WASMScalarCodeContainer(name, 0, 1, fOut, precision, internal_memory);
}

CodeContainer* WASMCodeContainer::createContainer(const string& name, int numInputs, int numOutputs, ostream* dst,
                                                  bool internal_memory)
{
    CodeContainer* container;

    if (::Faust::Primitive::Math::floatSize == 3) {
        throw faustexception("ERROR : quad format not supported for WebAssembly\n");
    }
    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for WebAssembly\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for WebAssembly\n");
    }

    if (global::config().gOpenMPSwitch) {
        throw faustexception("ERROR : OpenMP not supported for WebAssembly\n");
    } else if (global::config().gSchedulerSwitch) {
        throw faustexception("ERROR : Scheduler mode not supported for WebAssembly\n");
    } else if (global::config().gVectorSwitch) {
        // throw faustexception("ERROR : Vector mode not supported for WebAssembly\n");
        if (global::config().gVectorLoopVariant == 0) {
            throw faustexception("ERROR : Vector mode with -lv 0 not supported for WebAssembly\n");
        }
        container = new WASMVectorCodeContainer(name, numInputs, numOutputs, dst, internal_memory);
    } else {
        container = new WASMScalarCodeContainer(name, numInputs, numOutputs, dst, Precision::Int, internal_memory);
    }

    return container;
}

// DSP API generation

DeclareFunInst* WASMCodeContainer::generateClassInit(const string& name)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped("dsp", Typed::kObj_ptr));
    args.push_back(InstBuilder::genNamedTyped("sample_rate", Typed::kInt32));

    BlockInst* inlined = inlineSubcontainersFunCalls(fStaticInitInstructions);
    BlockInst* block   = MoveVariablesInFront3().getCode(inlined);

    // Creates function
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(), FunTyped::kDefault);
    return InstBuilder::genDeclareFunInst(name, fun_type, block);
}

DeclareFunInst* WASMCodeContainer::generateInstanceClear(const string& name, const string& obj, bool ismethod,
                                                         bool isvirtual)
{
    Names args;
    if (!ismethod) {
        args.push_back(InstBuilder::genNamedTyped(obj, Typed::kObj_ptr));
    }

    // Rename 'sig' in 'dsp' and remove 'dsp' allocation
    BlockInst* renamed = DspRenamer().getCode(fClearInstructions);
    BlockInst* block   = MoveVariablesInFront3().getCode(renamed);

    // Creates function
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(), FunTyped::kDefault);
    return InstBuilder::genDeclareFunInst(name, fun_type, block);
}

DeclareFunInst* WASMCodeContainer::generateInstanceConstants(const string& name, const string& obj, bool ismethod,
                                                             bool isvirtual)
{
    Names args;
    if (!ismethod) {
        args.push_back(InstBuilder::genNamedTyped(obj, Typed::kObj_ptr));
    }
    args.push_back(InstBuilder::genNamedTyped("sample_rate", Typed::kInt32));

    BlockInst* inlined = inlineSubcontainersFunCalls(fInitInstructions);
    BlockInst* block   = MoveVariablesInFront3().getCode(inlined);

    // Creates function
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(), FunTyped::kDefault);
    return InstBuilder::genDeclareFunInst(name, fun_type, block);
}

DeclareFunInst* WASMCodeContainer::generateInstanceResetUserInterface(const string& name, const string& obj,
                                                                      bool ismethod, bool isvirtual)
{
    Names args;
    if (!ismethod) {
        args.push_back(InstBuilder::genNamedTyped(obj, Typed::kObj_ptr));
    }

    // Rename 'sig' in 'dsp' and remove 'dsp' allocation
    BlockInst* renamed = DspRenamer().getCode(_resolutionetUserInterfaceInstructions);
    BlockInst* block   = MoveVariablesInFront3().getCode(renamed);

    // Creates function
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(), FunTyped::kDefault);
    return InstBuilder::genDeclareFunInst(name, fun_type, block);
}

// Scalar
WASMScalarCodeContainer::WASMScalarCodeContainer(const string& name, int numInputs, int numOutputs, ostream* out,
                                                 const Precision& precision, bool internal_memory)
    : WASMCodeContainer(name, numInputs, numOutputs, out, internal_memory)
{
    fSubContainerType = precision;
}

// Special version that uses MoveVariablesInFront3 to inline waveforms...
DeclareFunInst* WASMCodeContainer::generateInstanceInitFun(const string& name, const string& obj, bool ismethod,
                                                           bool isvirtual)
{
    Names args;
    if (!ismethod) {
        args.push_back(InstBuilder::genNamedTyped(obj, Typed::kObj_ptr));
    }
    args.push_back(InstBuilder::genNamedTyped("sample_rate", Typed::kInt32));

    BlockInst* init_block = InstBuilder::genBlockInst();
    init_block->pushBackInst(MoveVariablesInFront3().getCode(fStaticInitInstructions));
    init_block->pushBackInst(MoveVariablesInFront3().getCode(fInitInstructions));
    init_block->pushBackInst(MoveVariablesInFront3().getCode(fPostInitInstructions));
    init_block->pushBackInst(MoveVariablesInFront3().getCode(_resolutionetUserInterfaceInstructions));
    init_block->pushBackInst(MoveVariablesInFront3().getCode(fClearInstructions));

    init_block->pushBackInst(InstBuilder::genRetInst());

    // Creates function
    return InstBuilder::genVoidFunction(name, args, init_block, isvirtual);
}

void WASMCodeContainer::produceClass()
{
    // Module definition
    this->_visitor->generateModuleHeader();

    // Sub containers are merged in the main module, before functions generation
    mergeSubContainers();

    // Mathematical functions and global variables are handled in a separated visitor that creates functions types and
    // global variable offset
    generateGlobalDeclarations(this->_visitor->getFunAndTypeCounter());
    generateExtGlobalDeclarations(this->_visitor->getFunAndTypeCounter());

    // Update struct offset to take account of global variables defined in 'generateGlobalDeclarations' in the separated
    // visitor
    this->_visitor->updateStructOffsetAndFieldTable();

    // Functions types
    this->_visitor->generateFunTypes();

    // Imported functions
    this->_visitor->generateImports(fNumInputs + fNumOutputs, fInternalMemory);

    // Functions signature
    this->_visitor->generateFuncSignatures();

    // Fields : compute the structure size to use in 'new'
    generateDeclarations(this->_visitor);

    // Memory

    // Keep location of memory generation
    size_t begin_memory = -1;
    if (fInternalMemory) {
        begin_memory = this->_visitor->generateInternalMemory();
    }

    // Exports
    this->_visitor->generateExports(fInternalMemory);

    // Functions
    int32_t functions_start = this->_visitor->startSection(BinaryConsts::Section::Code);
    fBinaryOut << U32LEB(14);  // num functions

    // TO REMOVE when 'soundfile' is implemented
    {
        // Generate UI: only to trigger exception when using 'soundfile' primitive
        generateUserInterface(this->_visitor);
    }

    // Internal functions in alphabetical order

    // 1) classInit
    generateClassInit("classInit")->accept(this->_visitor);

    // 2) compute
    generateCompute();

    // 3) getNumInputs
    generateGetInputs("getNumInputs", "dsp", false, FunTyped::kDefault)->accept(this->_visitor);

    // 4) getNumOutputs
    generateGetOutputs("getNumOutputs", "dsp", false, FunTyped::kDefault)->accept(this->_visitor);

    // 5) getParamValue (adhoc generation for now since currently FIR cannot be generated to handle this case)
    this->_visitor->generateGetParamValue();

    // 6) getSampleRate
    generateGetSampleRate("getSampleRate", "dsp", false, false)->accept(this->_visitor);

    // 7) init
    generateInit("init", "dsp", false, false)->accept(this->_visitor);

    // 8) instanceClear
    generateInstanceClear("instanceClear", "dsp", false, false)->accept(this->_visitor);

    // 9) instanceConstants
    generateInstanceConstants("instanceConstants", "dsp", false, false)->accept(this->_visitor);

    // 10) instanceInit
    generateInstanceInit("instanceInit", "dsp", false, false)->accept(this->_visitor);

    // 11) instanceResetUserInterface
    generateInstanceResetUserInterface("instanceResetUserInterface", "dsp", false, false)
        ->accept(this->_visitor);

    // Always generated mathematical functions

    // 12) max_i
    WASInst::generateIntMax()->accept(this->_visitor);

    // 13) min_i
    WASInst::generateIntMin()->accept(this->_visitor);

    // 14) setParamValue (adhoc generation for now since currently FIR cannot be generated to handle this case)
    this->_visitor->generateSetParamValue();

    // Possibly generate separated functions : TO REMOVE ?
    generateComputeFunctions(this->_visitor);

    this->_visitor->finishSection(functions_start);

    // TO REMOVE when 'soundfile' is implemented
    {
        // Generate UI: only to trigger exception when using 'soundfile' primitive
        generateUserInterface(this->_visitor);
    }

    // JSON generation
    string json;
    if (::Faust::Primitive::Math::floatSize == 1) {
        json = generateJSON<float>();
    } else {
        json = generateJSON<double>();
    }

    // Memory size can now be written
    if (fInternalMemory) {
        int memory_size = genMemSize(this->_visitor->getStructSize(), fNumInputs + fNumOutputs, (int)json.size());
        // Since JSON is written in data segment at offset 0, the memory size
        // must be computed taking account JSON size and DSP + audio buffer size
        fBinaryOut.writeAt(begin_memory, U32LEB(memory_size));
        // maximum memory pages number, minimum value is to be extended on JS side for soundfiles
        fBinaryOut.writeAt(begin_memory + 5, U32LEB(memory_size+1000));
    }

    // Data segment contains the JSON string starting at offset 0,
    this->_visitor->generateJSON(json);

    // Finally produce output stream
    fBinaryOut.writeTo(*fOut);

    // Helper code
    int n = 0;

    // Generate JSON and getSize
    tab(n, fHelper);
    fHelper << "/*\n"
            << "Code generated with Faust version " << FAUSTVERSION << endl;
    fHelper << "Compilation options: ";
    global::config().printCompilationOptions(fHelper);
    fHelper << "\n*/\n";

    // Generate JSON
    tab(n, fHelper);
    string json2 = flattenJSON1(json);
    fHelper << "function getJSON" << fKlassName << "() {";
    tab(n + 1, fHelper);
    fHelper << "return '";
    fHelper << json2;
    fHelper << "';";
    printlines(n + 1, fUICode, fHelper);
    tab(n, fHelper);
    fHelper << "}\n";

    if (global::config().gOutputLang == "wasm-ib" || global::config().gOutputLang == "wasm-eb") {
        /*
        // Write binary as an array
        fHelper << showbase         // show the 0x prefix
                << internal         // fill between the prefix and the number
                << setfill('0');    // fill with 0s
        {
            fHelper << "function getBinaryCode" << fKlassName << "() {";
                tab(n+1, fHelper);
                fHelper << "return new Uint8Array([";
                char sep = ' ';
                for (int i = 0; i < fBinaryOut.size(); i++) {
                    fHelper << sep << hex << int(fBinaryOut[i]);
                    sep = ',';
                }
                fHelper << "]).buffer; }\n";
            tab(n, fHelper);
        }

        {
            fHelper << "function getBinaryCodeString" << fKlassName << "() {";
                tab(n+1, fHelper);
                fHelper << "return \"new Uint8Array([";
                char sep = ' ';
                for (int i = 0; i < fBinaryOut.size(); i++) {
                    fHelper << sep << hex << int(fBinaryOut[i]);
                    sep = ',';
                }
                fHelper << "]).buffer\"; }\n";
            tab(n, fHelper);
        }
        */

        fHelper << "function getBase64Code" << fKlassName << "() {";
        fHelper << " return \"" << base64_encode(fBinaryOut.toString()) << "\"; }\n";
        tab(n, fHelper);
    }
}

// Auxiliary function for shared code in generateCompute
void WASMCodeContainer::generateComputeAux(BlockInst* compute_block)
{
    DeclareFunInst* int_max_fun = WASInst::generateIntMax();
    DeclareFunInst* int_min_fun = WASInst::generateIntMin();

    // Inline "max_i" call
    compute_block = FunctionCallInliner(int_max_fun).getCode(compute_block);

    // Inline "min_i" call
    compute_block = FunctionCallInliner(int_min_fun).getCode(compute_block);

    // Push the loop in compute block
    fComputeBlockInstructions->pushBackInst(compute_block);

    // Put local variables at the begining
    BlockInst* block = MoveVariablesInFront2().getCode(fComputeBlockInstructions, true);

    // Creates function and visit it
    Names args;
    args.push_back(InstBuilder::genNamedTyped("dsp", Typed::kObj_ptr));
    args.push_back(InstBuilder::genNamedTyped("count", Typed::kInt32));
    args.push_back(InstBuilder::genNamedTyped("inputs", Typed::kVoid_ptr));
    args.push_back(InstBuilder::genNamedTyped("outputs", Typed::kVoid_ptr));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(), FunTyped::kDefault);

    InstBuilder::genDeclareFunInst("compute", fun_type, block)->accept(this->_visitor);
}

void WASMScalarCodeContainer::generateCompute()
{
    // Loop 'i' variable is moved by bytes
    BlockInst* compute_block = InstBuilder::genBlockInst();
    compute_block->pushBackInst(fCurLoop->generateScalarLoop(fFullCount, global::config().gLoopVarInBytes));

    // Generates post DSP loop code
    compute_block->pushBackInst(fPostComputeBlockInstructions);

    generateComputeAux(compute_block);
}

// Vector
WASMVectorCodeContainer::WASMVectorCodeContainer(const string& name, int numInputs, int numOutputs, ostream* out,
                                                 bool internal_memory)
    : VectorCodeContainer(numInputs, numOutputs), WASMCodeContainer(name, numInputs, numOutputs, out, internal_memory)
{
    // No array on stack, move all of them in struct
    global::config().gMachineMaxStackSize = -1;
}

void WASMVectorCodeContainer::generateCompute()
{
    // Rename all loop variables name to avoid name clash
    LoopVariableRenamer loop_renamer;
    generateComputeAux(loop_renamer.getCode(fDAGBlock));
}
