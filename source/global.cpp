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

#include <limits.h>
#include <cstdint>

#include "compiler/signals/binop.hh"
#include "compiler/types/floats.hh"
#include "compiler/instruction/instructions.hh"
#include "compiler/file_handling/sourcereader.hh"

#include "tlib/tree.hh"
#include "llvm_dsp_aux.hh"

#ifdef TEMPLATE_BUILD
#include "template_code_container.hh"
#endif

#include "signals.hh"
#include "global.hh"
#include "faust/primitive/math.hh"

#include "faust/primitive/symbols.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

using Availability = ::Faust::Primitive::Type::Availability;
using Precision = ::Faust::Primitive::Type::Precision;
using Priority = ::Faust::Primitive::Type::Priority;
using Value = ::Faust::Primitive::Type::Value;
using Vectorability = ::Faust::Primitive::Type::Vectorability;

// Garbageable globals
bool                    global::gHeapCleanup = false;

global* gGlobal = nullptr;

std::list<Garbageable*>& global::getObjectTable()
{
  static std::list<Garbageable*> objectTable;
  return objectTable;
}

global& global::config()
{
  static global global_instance;
  return global_instance;
}

std::list<Garbageable*>& global::gObjectTable = getObjectTable();



/*
faust1 uses a loop size of 512, but 512 makes faust2 crash (stack allocation error).
So we use a lower value here.
*/

global::global() : TABBER(1), gLoopDetector(1024, 400), gStackOverflowDetector(MAX_STACK_SIZE), gNextFreeColor(1)
{
    CTree::init();
    
    // Part of the state that needs to be initialized between consecutive calls to Box/Signal API
    reset();

    gResult          = nullptr;
    gResult2         = nullptr;
    gExpandedDefList = nullptr;

    gDetailsSwitch    = false;
    gDrawSignals      = false;
    gDrawRouteFrame   = false;
    gShadowBlur       = false;  // note: svg2pdf doesn't like the blur filter
    gScaledSVG        = false;
    gStripDocSwitch   = false;  // Strip <mdoc> content from doc listings.
    gFoldThreshold    = 25;
    gFoldComplexity   = 2;
    gMaxNameSize      = 40;
    gSimpleNames      = false;
    gSimplifyDiagrams = false;
    gMaxCopyDelay     = 16;

    gVectorSwitch      = false;
    gDeepFirstSwitch   = false;
    gVecSize           = 32;
    gVectorLoopVariant = 0;

    gOpenMPSwitch    = false;
    gOpenMPLoop      = false;
    gSchedulerSwitch = false;
    gOpenCLSwitch    = false;
    gCUDASwitch      = false;
    gGroupTaskSwitch = false;
    gFunTaskSwitch   = false;

    gUIMacroSwitch = false;
    gDumpNorm      = -1;
    gRangeUI       = false;

    gPrintFileListSwitch = false;
    gInlineArchSwitch    = false;

    gDSPStruct  = false;
    gLightMode  = false;
    gClang      = false;
    gNoVirtual  = false;
    gCheckTable = "";

    gClassName      = "mydsp";
    gSuperClassName = "dsp";
    gProcessName    = "process";

    gDSPFactory = nullptr;

    gInputString = nullptr;

    // Backend configuration : default values
    gAllowForeignFunction = true;
    gAllowForeignConstant = true;
    gAllowForeignVar      = true;
    gComputeIOTA          = false;
    gFAUSTFLOAT2Internal  = false;
    gInPlace              = false;
    gLoopVarInBytes       = false;
    gWaveformInDSP        = false;
    gUseDefaultSound      = true;
    gHasTeeLocal          = false;
    gFastMath             = false;
    gRemoveVarAddress     = false;
    gOneSample            = -1;
    gOneSampleControl     = false;
    gComputeMix           = false;
    gFastMathLib          = "default";
    gNameSpace            = "";
    gFullParentheses      = false;

    gNarrowingLimit = 0;
    gWideningLimit  = 0;

    // Fastmath mapping float version
    gFastMathLibTable["fabsf"]      = "fast_fabsf";
    gFastMathLibTable["acosf"]      = "fast_acosf";
    gFastMathLibTable["asinf"]      = "fast_asinf";
    gFastMathLibTable["atanf"]      = "fast_atanf";
    gFastMathLibTable["atan2f"]     = "fast_atan2f";
    gFastMathLibTable["ceilf"]      = "fast_ceilf";
    gFastMathLibTable["cosf"]       = "fast_cosf";
    gFastMathLibTable["expf"]       = "fast_expf";
    gFastMathLibTable["exp2f"]      = "fast_exp2f";
    gFastMathLibTable["exp10f"]     = "fast_exp10f";
    gFastMathLibTable["floorf"]     = "fast_floorf";
    gFastMathLibTable["fmodf"]      = "fast_fmodf";
    gFastMathLibTable["logf"]       = "fast_logf";
    gFastMathLibTable["log2f"]      = "fast_log2f";
    gFastMathLibTable["log10f"]     = "fast_log10f";
    gFastMathLibTable["powf"]       = "fast_powf";
    gFastMathLibTable["remainderf"] = "fast_remainderf";
    gFastMathLibTable["rintf"]      = "fast_rintf";
    gFastMathLibTable["roundf"]     = "fast_roundf";
    gFastMathLibTable["sinf"]       = "fast_sinf";
    gFastMathLibTable["sqrtf"]      = "fast_sqrtf";
    gFastMathLibTable["tanf"]       = "fast_tanf";

    // Fastmath mapping double version
    gFastMathLibTable["fabs"]      = "fast_fabs";
    gFastMathLibTable["acos"]      = "fast_acos";
    gFastMathLibTable["asin"]      = "fast_asin";
    gFastMathLibTable["atan"]      = "fast_atan";
    gFastMathLibTable["atan2"]     = "fast_atan2";
    gFastMathLibTable["ceil"]      = "fast_ceil";
    gFastMathLibTable["cos"]       = "fast_cos";
    gFastMathLibTable["exp"]       = "fast_exp";
    gFastMathLibTable["exp2"]      = "fast_exp2";
    gFastMathLibTable["exp10"]     = "fast_exp10";
    gFastMathLibTable["floor"]     = "fast_floor";
    gFastMathLibTable["fmod"]      = "fast_fmod";
    gFastMathLibTable["log"]       = "fast_log";
    gFastMathLibTable["log2"]      = "fast_log2";
    gFastMathLibTable["log10"]     = "fast_log10";
    gFastMathLibTable["pow"]       = "fast_pow";
    gFastMathLibTable["remainder"] = "fast_remainder";
    gFastMathLibTable["rint"]      = "fast_rint";
    gFastMathLibTable["round"]     = "fast_round";
    gFastMathLibTable["sin"]       = "fast_sin";
    gFastMathLibTable["sqrt"]      = "fast_sqrt";
    gFastMathLibTable["tan"]       = "fast_tan";

    gLatexDocSwitch = true;  // Only LaTeX outformat is handled for the moment.

    gErrorCount = 0;

    gFileNum = 0;

    gBoxCounter    = 0;
    gSignalCounter = 0;

    gCountInferences = 0;
    gCountMaximal    = 0;

    gDummyInput = 10000;

    gBoxSlotNumber = 0;
    gMemoryManager = false;

    gLocalCausalityCheck = false;
    gCausality           = false;

    gOccurrences = nullptr; // FIX - only used for Draw
    gFoldingFlag = false;
    gDevSuffix   = nullptr;

    gMachineFloatSize      = sizeof(float);
    gMachineInt32Size      = sizeof(int);
    gMachineInt64Size      = sizeof(long int);
    gMachineDoubleSize     = sizeof(double);
    gMachineQuadSize       = sizeof(long double);
    gMachineFixedPointSize = gMachineFloatSize;
    gMachineBoolSize       = sizeof(bool);

    // Assuming we are compiling for a 64 bits machine
    gMachinePtrSize = sizeof(nullptr);
#if defined(ANDROID) && INTPTR_MAX == INT32_MAX
    // Hack for 32Bit Android Architectures ; sizeof(nullptr) == 4 but LLVM DataLayout.GetPointerSize() == 8
    gMachinePtrSize *= 2;
#endif

    gMachineMaxStackSize = MAX_MACHINE_STACK_SIZE;

#ifdef TEMPLATE_BUILD
    gTemplateVisitor = nullptr;    // Will be (possibly) allocated in Template backend
#endif
    gOutputLang          = "";

    gHelpSwitch       = false;
    gVersionSwitch    = false;
    gLibDirSwitch     = false;
    gIncludeDirSwitch = false;
    gArchDirSwitch    = false;
    gDspDirSwitch     = false;
    gPathListSwitch   = false;
    gGraphSwitch      = false;
    gDrawPSSwitch     = false;
    gDrawSVGSwitch    = false;
    gVHDLSwitch       = false;
    gVHDLTrace        = false;
    gVHDLFloatType    = 0;  // sfixed
    gVHDLFloatMSB     = 8;
    gVHDLFloatLSB     = -23;
    gPrintXMLSwitch   = false;
    gPrintJSONSwitch  = false;
    gPrintDocSwitch   = false;
    gArchFile         = "";
    gExportDSP        = false;
    
    gTimeout = 120;  // Time out to abort compiler (in seconds)
    
    gErrorCount = 0;
    gErrorMessage = "";
    
    // By default use "cpp" output
    gOutputLang = (getenv("FAUST_DEFAULT_BACKEND")) ? string(getenv("FAUST_DEFAULT_BACKEND")) : "cpp";
}

// Done after contructor since part of the following allocations need the "global" object to be fully built
void global::init()
{
    gPureRoutingProperty   = new property<bool>();
    gSymbolicBoxProperty   = new property<Tree>();
    gSimplifiedBoxProperty = new property<Tree>();
    gSymListProp           = new property<Tree>();

    // Essential predefined types
    gMemoizedTypes          = new property<AudioType*>();
    gAllocationCount        = 0;
    gMaskDelayLineThreshold = INT_MAX;

    // True by default but only usable with -lang ocpp backend
    gEnableFlag = true;

    // Essential predefined types
    TINPUT   = makeSimpleType(kReal, kSamp, kExec, kVect, kNum, interval(-1, 1));
    TGUI     = makeSimpleType(kReal, kBlock, kExec, kVect, kNum, interval());
    TGUI01   = makeSimpleType(kReal, kBlock, kExec, kVect, kNum, interval(0, 1));
   
    TREC = makeSimpleType(kInt, kSamp, kInit, kScal, kNum, interval(0, 0));
    // !!! TRECMAX Maximal only in the last component of the type lattice
    TRECMAX = makeSimpleType(Precision::Int, Priority::Samp, Availability::Init, Vectorability::Scal, Value::Num, interval(-HUGE_VAL, HUGE_VAL));

    // Empty predefined bit depth
    RES = res();

    // Predefined nil tree
    nil = tree(::Faust::Primitive::Symbols::internal().symbol("nil"));

    BOXTYPEPROP      = tree(::Faust::Primitive::Symbols::internal().symbol("boxTypeProp"));
    NUMERICPROPERTY  = tree(::Faust::Primitive::Symbols::internal().symbol("NUMERICPROPERTY"));
    DEFLINEPROP      = tree(::Faust::Primitive::Symbols::internal().symbol("DefLineProp"));
    USELINEPROP      = tree(::Faust::Primitive::Symbols::internal().symbol("UseLineProp"));
    SIMPLIFIED       = tree(::Faust::Primitive::Symbols::internal().symbol("sigSimplifiedProp"));
    DOCTABLES        = tree(::Faust::Primitive::Symbols::internal().symbol("DocTablesProp"));
    NULLENV          = tree(::Faust::Primitive::Symbols::internal().symbol("NullRenameEnv"));
    COLORPROPERTY    = tree(::Faust::Primitive::Symbols::internal().symbol("ColorProperty"));
    ORDERPROP        = tree(::Faust::Primitive::Symbols::internal().symbol("OrderProp"));
    RECURSIVNESS     = tree(::Faust::Primitive::Symbols::internal().symbol("RecursivnessProp"));
    NULLTYPEENV      = tree(::Faust::Primitive::Symbols::internal().symbol("NullTypeEnv"));
    RECDEF           = tree(::Faust::Primitive::Symbols::internal().symbol("RECDEF"));
    DEBRUIJN2SYM     = tree(::Faust::Primitive::Symbols::internal().symbol("deBruijn2Sym"));
    NORMALFORM       = tree(::Faust::Primitive::Symbols::internal().symbol("NormalForm"));
    DEFNAMEPROPERTY  = tree(::Faust::Primitive::Symbols::internal().symbol("DEFNAMEPROPERTY"));
    NICKNAMEPROPERTY = tree(::Faust::Primitive::Symbols::internal().symbol("NICKNAMEPROPERTY"));
    BCOMPLEXITY      = tree("BCOMPLEXITY");
    LETRECBODY       = boxIdent("RECURSIVEBODY");

    PROPAGATEPROPERTY = ::Faust::Primitive::Symbols::internal().symbol("PropagateProperty");

    gLatexheaderfilename = "latexheader.tex";
    gDocTextsDefaultFile = "mathdoctexts-default.txt";

    gCurrentLocal = setlocale(LC_ALL, NULL);
    if (gCurrentLocal != NULL) {
        gCurrentLocal = strdup(gCurrentLocal);
    }

    // Setup standard "C" local
    // (workaround for a bug in bitcode generation : http://lists.cs.uiuc.edu/pipermail/llvmbugs/2012-May/023530.html)
    setlocale(LC_ALL, "C");

    // Source file injection
    gInjectFlag = false;  // inject an external source file into the architecture file
    gInjectFile = "";     // instead of a compiled dsp file

    // Create type declaration for external 'soundfile' type
    vector<NamedTyped*> sf_type_fields;
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fBuffers", InstBuilder::genBasicTyped(Typed::kVoid_ptr)));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fLength", InstBuilder::genBasicTyped(Typed::kInt32_ptr)));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fSR", InstBuilder::genBasicTyped(Typed::kInt32_ptr)));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fOffset", InstBuilder::genBasicTyped(Typed::kInt32_ptr)));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fChannels", InstBuilder::genInt32Typed()));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fParts", InstBuilder::genInt32Typed()));
    sf_type_fields.push_back(InstBuilder::genNamedTyped("fIsDouble", InstBuilder::genInt32Typed()));
    gExternalStructTypes[Typed::kSound] =
        InstBuilder::genDeclareStructTypeInst(InstBuilder::genStructTyped("Soundfile", sf_type_fields));

    // Foreign math functions supported by the Interp, Cmajor, wasm/wast backends
    gMathForeignFunctions["acoshf"] = true;
    gMathForeignFunctions["acosh"]  = true;
    gMathForeignFunctions["acoshl"] = true;

    gMathForeignFunctions["asinhf"] = true;
    gMathForeignFunctions["asinh"]  = true;
    gMathForeignFunctions["asinhl"] = true;

    gMathForeignFunctions["atanhf"] = true;
    gMathForeignFunctions["atanh"]  = true;
    gMathForeignFunctions["atanhl"] = true;

    gMathForeignFunctions["coshf"] = true;
    gMathForeignFunctions["cosh"]  = true;
    gMathForeignFunctions["coshl"] = true;

    gMathForeignFunctions["sinhf"] = true;
    gMathForeignFunctions["sinh"]  = true;
    gMathForeignFunctions["sinhl"] = true;

    gMathForeignFunctions["tanhf"] = true;
    gMathForeignFunctions["tanh"]  = true;
    gMathForeignFunctions["tanhl"] = true;

    gMathForeignFunctions["isnanf"] = true;
    gMathForeignFunctions["isnan"]  = true;
    gMathForeignFunctions["isnanl"] = true;

    gMathForeignFunctions["isinff"] = true;
    gMathForeignFunctions["isinf"]  = true;
    gMathForeignFunctions["isinfl"] = true;

    gMathForeignFunctions["copysignf"] = true;
    gMathForeignFunctions["copysign"]  = true;
    gMathForeignFunctions["copysignl"] = true;

    // internal state during drawing
    gInverter[0] = boxSeq(boxPar(boxWire(), boxInt(-1)), boxPrim2(sigMul));
    gInverter[1] = boxSeq(boxPar(boxInt(-1), boxWire()), boxPrim2(sigMul));
    gInverter[2] = boxSeq(boxPar(boxWire(), boxReal(-1.0)), boxPrim2(sigMul));
    gInverter[3] = boxSeq(boxPar(boxReal(-1.0), boxWire()), boxPrim2(sigMul));
    gInverter[4] = boxSeq(boxPar(boxInt(0), boxWire()), boxPrim2(sigSub));
    gInverter[5] = boxSeq(boxPar(boxReal(0.0), boxWire()), boxPrim2(sigSub));
}

string global::printFloat()
{
    switch (::Faust::Primitive::Math::floatSize) {
        case 1:
            return "-single ";
        case 2:
            return "-double ";
        case 3:
            return "-quad ";
        case 4:
            return "-fx ";
        default:
            faustassert(false);
            return "";
    }
}

void global::printCompilationOptions(stringstream& dst, bool backend)
{
    if (gArchFile != "") dst << "-a " << gArchFile << " ";
    if (backend) {
#ifdef LLVM_BUILD
        if (gOutputLang == "llvm") {
            dst << "-lang " << gOutputLang << " " << LLVM_VERSION << " ";
        } else {
            dst << "-lang " << gOutputLang << " ";
        }
#else
        dst << "-lang " << gOutputLang << " ";
#endif
    }
    if (gInlineArchSwitch) dst << "-i ";
    if (gInPlace) dst << "-inpl ";
    if (gOneSample >= 0) dst << "-os" << gOneSample << " ";
    if (gLightMode) dst << "-light ";
    if (gMemoryManager) dst << "-mem ";
    if (gComputeMix) dst << "-cm ";
    if (gRangeUI) dst << "-rui ";
    if (::Faust::Primitive::Math::approx) dst << "-mapp ";
    if (gClassName != "mydsp") dst << "-cn " << gClassName << " ";
    if (gSuperClassName != "dsp") dst << "-scn " << gSuperClassName << " ";
    if (gProcessName != "process") dst << "-pn " << gProcessName << " ";
    if (gMaskDelayLineThreshold != INT_MAX) dst << "-dtl " << gMaskDelayLineThreshold << " ";
    dst << "-es " << gEnableFlag << " ";
    if (::Faust::Primitive::Math::hasExp10) dst << "-exp10 ";
    if (gSchedulerSwitch) dst << "-sch ";
    if (gOpenMPSwitch) dst << "-omp " << ((gOpenMPLoop) ? "-pl " : "");
    dst << "-mcd " << gGlobal->gMaxCopyDelay << " ";
    if (gGlobal->gUIMacroSwitch) dst << "-uim ";
    dst << printFloat() << "-ftz " << ::Faust::Primitive::Math::FTZMode << " ";
    if (gVectorSwitch) {
        dst << "-vec "
            << "-lv " << gVectorLoopVariant << " "
            << "-vs " << gVecSize << " " << ((gFunTaskSwitch) ? "-fun " : "") << ((gGroupTaskSwitch) ? "-g " : "")
            << ((gDeepFirstSwitch) ? "-dfs " : "");
    }

    // Add 'compile_options' metadata
    string res = dst.str();
    gGlobal->gMetaDataSet[tree("compile_options")].insert(tree("\"" + res.substr(0, res.size() - 1) + "\""));
}

string global::printCompilationOptions1()
{
    stringstream dst;
    printCompilationOptions(dst, true);
    string res = dst.str();
    return res.substr(0, res.size() - 1);
}

void global::initTypeSizeMap()
{
    // Init type size table (in bytes)
    gTypeSizeMap[Typed::kFloat]         = gMachineFloatSize;
    gTypeSizeMap[Typed::kFloat_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kFloat_ptr_ptr] = gMachinePtrSize;
    gTypeSizeMap[Typed::kFloat_vec]     = gMachineFloatSize * gVecSize;
    gTypeSizeMap[Typed::kFloat_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kDouble]         = gMachineDoubleSize;
    gTypeSizeMap[Typed::kDouble_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kDouble_ptr_ptr] = gMachinePtrSize;
    gTypeSizeMap[Typed::kDouble_vec]     = gMachineDoubleSize * gVecSize; 
    gTypeSizeMap[Typed::kDouble_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kQuad]         = gMachineQuadSize;
    gTypeSizeMap[Typed::kQuad_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kQuad_ptr_ptr] = gMachinePtrSize;
    gTypeSizeMap[Typed::kQuad_vec]     = gMachineQuadSize * gVecSize;
    gTypeSizeMap[Typed::kQuad_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kFixedPoint]         = gMachineFixedPointSize;
    gTypeSizeMap[Typed::kFixedPoint_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kFixedPoint_ptr_ptr] = gMachinePtrSize;
    gTypeSizeMap[Typed::kFixedPoint_vec]     = gMachineFixedPointSize * gVecSize;
    gTypeSizeMap[Typed::kFixedPoint_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kInt32]         = gMachineInt32Size;
    gTypeSizeMap[Typed::kInt32_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kInt32_vec]     = gMachineInt32Size * gVecSize;
    gTypeSizeMap[Typed::kInt32_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kInt64]         = gMachineInt64Size;
    gTypeSizeMap[Typed::kInt64_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kInt64_vec]     = gMachineInt64Size * gVecSize;
    gTypeSizeMap[Typed::kInt64_vec_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kBool]         = gMachineBoolSize;
    gTypeSizeMap[Typed::kBool_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kBool_vec]     = gMachineBoolSize * gVecSize;
    gTypeSizeMap[Typed::kBool_vec_ptr] = gMachinePtrSize;

    // Takes the type of internal real
    gTypeSizeMap[Typed::kFloatMacro]         = gTypeSizeMap[itfloat()];
    gTypeSizeMap[Typed::kFloatMacro_ptr]     = gMachinePtrSize;
    gTypeSizeMap[Typed::kFloatMacro_ptr_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kVoid_ptr] = gMachinePtrSize;

    gTypeSizeMap[Typed::kObj_ptr]   = gMachinePtrSize;
    gTypeSizeMap[Typed::kSound_ptr] = gMachinePtrSize;
    gTypeSizeMap[Typed::kUint_ptr]  = gMachinePtrSize;
}

int global::audioSampleSize()
{
    return int(pow(2.f, float(::Faust::Primitive::Math::floatSize + 1)));
}

bool global::hasForeignFunction(const string& name, const string& inc_file)
{
#ifdef LLVM_BUILD
    // LLVM backend can use 'standard' foreign linked functions
    static vector<string> inc_list = {"<math.h>", "<cmath>", "<stdlib.h>"};
    bool                       is_inc   = find(begin(inc_list), end(inc_list), inc_file) != inc_list.end();
    // or custom added ones
    bool is_ff       = llvm_dsp_factory_aux::gForeignFunctions.count(name) > 0;
    bool is_linkable = (gOutputLang == "llvm") && (is_inc || is_ff);
#else
    bool is_linkable = false;
#endif
    bool internal_math_ff =
        ((gOutputLang == "llvm") || startWith(gOutputLang, "wast") || startWith(gOutputLang, "wasm") ||
         (gOutputLang == "interp") || startWith(gOutputLang, "cmajor") || (gOutputLang == "dlang") ||
         (gOutputLang == "csharp") || (gOutputLang == "rust") || (gOutputLang == "julia") ||
         (gOutputLang == "jax"));

    return (internal_math_ff && (gMathForeignFunctions.find(name) != gMathForeignFunctions.end())) || is_linkable;
}

BasicTyped* global::genBasicTyped(Typed::VarType type)
{
    // Possibly force FAUSTFLOAT type (= kFloatMacro) to internal real
    Typed::VarType new_type = ((type == Typed::kFloatMacro) && gFAUSTFLOAT2Internal) ? itfloat() : type;

    // If not defined, add the type in the table
    if (gTypeTable.find(new_type) == gTypeTable.end()) {
        gTypeTable[new_type] = new BasicTyped(new_type);
    }
    return gTypeTable[new_type];
}

void global::setVarType(const string& name, Typed::VarType type)
{
    gVarTypeTable[name] = genBasicTyped(type);
}

Typed::VarType global::getVarType(const string& name)
{
    return gVarTypeTable[name]->getType();
}

global::~global()
{
    Garbageable::cleanup();
    BasicTyped::cleanup();
    DeclareVarInst::cleanup();
    setlocale(LC_ALL, gCurrentLocal);
    free(gCurrentLocal);

// FIX - what's the point? none of this has been allocated
/*
    // Cleanup
#ifdef C_BUILD
    CInstVisitor::cleanup();
#endif
#ifdef CPP_BUILD
    CPPInstVisitor::cleanup();
#endif
#ifdef CSHARP_BUILD
    CSharpInstVisitor::cleanup();
#endif
#ifdef DLANG_BUILD
    DLangInstVisitor::cleanup();
#endif
#ifdef FIR_BUILD
    FIRInstVisitor::cleanup();
#endif
#ifdef JAVA_BUILD
    JAVAInstVisitor::cleanup();
#endif
#ifdef JULIA_BUILD
    JuliaInstVisitor::cleanup();
#endif
#ifdef JAX_BUILD
    JAXInstVisitor::cleanup();
#endif
#ifdef TEMPLATE_BUILD
    TemplateInstVisitor::cleanup();
#endif
#ifdef RUST_BUILD
    RustInstVisitor::cleanup();
#endif
*/
}

void global::allocate()
{
    gGlobal = new global();
    gGlobal->init();
}

void global::destroy()
{
#ifdef EMCC
    if (faustexception::gJSExceptionMsg) {
        free((void*)faustexception::gJSExceptionMsg);
        faustexception::gJSExceptionMsg = nullptr;
    }
#endif
    delete gGlobal;
    gGlobal = nullptr;
}

string global::makeDrawPath()
{
    if (gOutputDir != "") {
        return gOutputDir + "/" + gMasterName + ".dsp";
    } else {
        return gMasterDocument;
    }
}

string global::makeDrawPathNoExt()
{
    if (gOutputDir != "") {
        return gOutputDir + "/" + gMasterName;
    } else if (gMasterDocument.length() >= 4 && gMasterDocument.substr(gMasterDocument.length() - 4) == ".dsp") {
        return gMasterDocument.substr(0, gMasterDocument.length() - 4);
    } else {
        return gMasterDocument;
    }
}

/*****************************************************************************
                        getFreshID
*****************************************************************************/

string global::getFreshID(const string& prefix)
{
    if (gIDCounters.find(prefix) == gIDCounters.end()) {
        gIDCounters[prefix] = 0;
    }
    int n               = gIDCounters[prefix];
    gIDCounters[prefix] = n + 1;
    return subst("$0$1", prefix, T(n));
}

bool global::isDebug(const string& debug_val)
{
    string debug_var = (getenv("FAUST_DEBUG")) ? string(getenv("FAUST_DEBUG")) : "";
    return debug_var == debug_val;
}

// Memory management
void Garbageable::cleanup()
{
    list<Garbageable*>::iterator it;

    // Here removing the deleted pointer from the list is pointless
    // and takes time, thus we don't do it.
    global::gHeapCleanup = true;
    for (it = global::gObjectTable.begin(); it != global::gObjectTable.end(); it++) {
#ifdef _WIN32
        // Hack : "this" and actual pointer are not the same: destructor cannot be called...
        Garbageable::operator delete(*it);
#else
        delete (*it);
#endif
    }

    // Reset to default state
    global::gObjectTable.clear();
    global::gHeapCleanup = false;
}

// For box/sig generation
void global::clear()
{
    gBoxCounter = 0;
    gBoxTable.clear();
    gBoxTrace.clear();

    gSignalCounter = 0;
    gSignalTable.clear();
    gSignalTrace.clear();
}

void* Garbageable::operator new(size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);
    global::getObjectTable().push_front(res);
    return res;
}

void Garbageable::operator delete(void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!global::gHeapCleanup) {
        global::gObjectTable.remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}

void* Garbageable::operator new[](size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);
    global::gObjectTable.push_front(res);
    return res;
}

void Garbageable::operator delete[](void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!global::gHeapCleanup) {
        global::gObjectTable.remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}
