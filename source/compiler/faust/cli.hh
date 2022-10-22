/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2016 GRAME, Centre National de Creation Musicale
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

#ifndef __CLI_H__
#define __CLI_H__

#include <string>
#include <vector>

#include "global.hh"

// Timing can be used outside of the scope of 'gGlobal'
extern bool gTimingSwitch;

namespace Faust {

  struct CLI
  {

    static bool isCmd(const char* cmd, const char* kw1)
    {
        return (strcmp(cmd, kw1) == 0);
    }

    static bool isCmd(const char* cmd, const char* kw1, const char* kw2)
    {
        return (strcmp(cmd, kw1) == 0) || (strcmp(cmd, kw2) == 0);
    }

    static bool processCmdline(int argc, const char* argv[])
    {
        int          i   = 1;
        int          err = 0;
        stringstream parse_error;
        bool         float_size = false;

        /*
        for (int i = 0; i < argc; i++) {
            cout << "processCmdline i = " << i << " cmd = " << argv[i] << "\n";
        }
        */

        while (i < argc) {
            if (isCmd(argv[i], "-h", "--help")) {
                gGlobal->gHelpSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-lang", "--language") && (i + 1 < argc)) {
                gGlobal->gOutputLang = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-v", "--version")) {
                gGlobal->gVersionSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-libdir", "--libdir")) {
                gGlobal->gLibDirSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-includedir", "--includedir")) {
                gGlobal->gIncludeDirSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-archdir", "--archdir")) {
                gGlobal->gArchDirSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-dspdir", "--dspdir")) {
                gGlobal->gDspDirSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-pathslist", "--pathslist")) {
                gGlobal->gPathListSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-d", "--details")) {
                gGlobal->gDetailsSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-a", "--architecture") && (i + 1 < argc)) {
                gGlobal->gArchFile = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-inj", "--inject") && (i + 1 < argc)) {
                gGlobal->gInjectFlag = true;
                gGlobal->gInjectFile = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-o") && (i + 1 < argc)) {
                gGlobal->gOutputFile = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-wi", "--widening-iterations") && (i + 1 < argc)) {
                gGlobal->gWideningLimit = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-ni", "--narrowing-iterations") && (i + 1 < argc)) {
                gGlobal->gNarrowingLimit = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-ps", "--postscript")) {
                gGlobal->gDrawPSSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-xml", "--xml")) {
                gGlobal->gPrintXMLSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-json", "--json")) {
                gGlobal->gPrintJSONSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-tg", "--task-graph")) {
                gGlobal->gGraphSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-sg", "--signal-graph")) {
                gGlobal->gDrawSignals = true;
                i += 1;

            } else if (isCmd(argv[i], "-drf", "--draw-route-frame")) {
                gGlobal->gDrawRouteFrame = true;
                i += 1;

            } else if (isCmd(argv[i], "-blur", "--shadow-blur")) {
                gGlobal->gShadowBlur = true;
                i += 1;

            } else if (isCmd(argv[i], "-sc", "--scaled-svg")) {
                gGlobal->gScaledSVG = true;
                i += 1;

            } else if (isCmd(argv[i], "-svg", "--svg")) {
                gGlobal->gDrawSVGSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-vhdl", "--vhdl")) {
                gGlobal->gVHDLSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-vhdl-trace", "--vhdl-trace")) {
                gGlobal->gVHDLTrace = true;
                i += 1;

            } else if (isCmd(argv[i], "-vhdl-type", "--vhdl-type") && (i + 1 < argc)) {
                gGlobal->gVHDLFloatType = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-vhdl-msb", "--vhdl-msb") && (i + 1 < argc)) {
                gGlobal->gVHDLFloatMSB = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-vhdl-lsb", "--vhdl-lsb") && (i + 1 < argc)) {
                gGlobal->gVHDLFloatLSB = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-elm", "--elementary")) {
                gGlobal->gElementarySwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-f", "--fold") && (i + 1 < argc)) {
                gGlobal->gFoldThreshold = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-fc", "--fold-complexity") && (i + 1 < argc)) {
                gGlobal->gFoldComplexity = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-mns", "--max-name-size") && (i + 1 < argc)) {
                gGlobal->gMaxNameSize = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-sn", "--simple-names")) {
                gGlobal->gSimpleNames = true;
                i += 1;

            } else if (isCmd(argv[i], "-mcd", "--max-copy-delay") && (i + 1 < argc)) {
                gGlobal->gMaxCopyDelay = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-dlt", "-delay-line-threshold") && (i + 1 < argc)) {
                gGlobal->gMaskDelayLineThreshold = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-mem", "--memory-manager")) {
                gGlobal->gMemoryManager = true;
                i += 1;

            } else if (isCmd(argv[i], "-sd", "--simplify-diagrams")) {
                gGlobal->gSimplifyDiagrams = true;
                i += 1;

            } else if (isCmd(argv[i], "-vec", "--vectorize")) {
                gGlobal->gVectorSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-scal", "--scalar")) {
                gGlobal->gVectorSwitch = false;
                i += 1;

            } else if (isCmd(argv[i], "-dfs", "--deepFirstScheduling")) {
                gGlobal->gDeepFirstSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-vs", "--vec-size") && (i + 1 < argc)) {
                gGlobal->gVecSize = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-lv", "--loop-variant") && (i + 1 < argc)) {
                gGlobal->gVectorLoopVariant = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-omp", "--openmp")) {
                gGlobal->gOpenMPSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-pl", "--par-loop")) {
                gGlobal->gOpenMPLoop = true;
                i += 1;

            } else if (isCmd(argv[i], "-sch", "--scheduler")) {
                gGlobal->gSchedulerSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-ocl", "--openCL")) {
                gGlobal->gOpenCLSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-cuda", "--CUDA")) {
                gGlobal->gCUDASwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-g", "--groupTasks")) {
                gGlobal->gGroupTaskSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-fun", "--funTasks")) {
                gGlobal->gFunTaskSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-uim", "--user-interface-macros")) {
                gGlobal->gUIMacroSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-t", "--timeout") && (i + 1 < argc)) {
                gGlobal->gTimeout = std::atoi(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-time", "--compilation-time")) {
                gTimingSwitch = true;
                i += 1;

                // 'real' options
            } else if (isCmd(argv[i], "-single", "--single-precision-floats")) {
                if (float_size && gGlobal->gFloatSize != 1) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                gGlobal->gFloatSize = 1;
                i += 1;

            } else if (isCmd(argv[i], "-double", "--double-precision-floats")) {
                if (float_size && gGlobal->gFloatSize != 2) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                gGlobal->gFloatSize = 2;
                i += 1;

            } else if (isCmd(argv[i], "-quad", "--quad-precision-floats")) {
                if (float_size && gGlobal->gFloatSize != 3) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                gGlobal->gFloatSize = 3;
                i += 1;

            } else if (isCmd(argv[i], "-fx", "--fixed-point")) {
                if (float_size && gGlobal->gFloatSize != 4) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                gGlobal->gFloatSize = 4;
                i += 1;

            } else if (isCmd(argv[i], "-mdoc", "--mathdoc")) {
                gGlobal->gPrintDocSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-mdlang", "--mathdoc-lang") && (i + 1 < argc)) {
                gGlobal->gDocLang = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-stripmdoc", "--strip-mdoc-tags")) {
                gGlobal->gStripDocSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-flist", "--file-list")) {
                gGlobal->gPrintFileListSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-norm", "--normalized-form")) {
                gGlobal->gDumpNorm = 0;
                i += 1;

            } else if (isCmd(argv[i], "-norm1", "--normalized-form1")) {
                gGlobal->gDumpNorm = 1;
                i += 1;

            } else if (isCmd(argv[i], "-cn", "--class-name") && (i + 1 < argc)) {
                vector<char> rep    = {'@', ' ', '(', ')', '/', '\\', '.'};
                gGlobal->gClassName = replaceCharList(argv[i + 1], rep, '_');
                i += 2;

            } else if (isCmd(argv[i], "-scn", "--super-class-name") && (i + 1 < argc)) {
                gGlobal->gSuperClassName = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-pn", "--process-name") && (i + 1 < argc)) {
                gGlobal->gProcessName = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-i", "--inline-architecture-files")) {
                gGlobal->gInlineArchSwitch = true;
                i += 1;

            } else if (isCmd(argv[i], "-e", "--export-dsp")) {
                gGlobal->gExportDSP = true;
                i += 1;

            } else if (isCmd(argv[i], "-exp10", "--generate-exp10")) {
                gGlobal->gHasExp10 = true;
                i += 1;

            } else if (isCmd(argv[i], "-os", "--one-sample") || isCmd(argv[i], "-os0", "--one-sample0")) {
                gGlobal->gOneSample = 0;
                i += 1;

            } else if (isCmd(argv[i], "-os1", "--one-sample1")) {
                gGlobal->gOneSample = 1;
                i += 1;

            } else if (isCmd(argv[i], "-os2", "--one-sample2")) {
                gGlobal->gOneSample = 2;
                i += 1;

            } else if (isCmd(argv[i], "-os3", "--one-sample3")) {
                gGlobal->gOneSample = 3;
                i += 1;

            } else if (isCmd(argv[i], "-cm", "--compute-mix")) {
                gGlobal->gComputeMix = true;
                i += 1;

            } else if (isCmd(argv[i], "-ftz", "--flush-to-zero")) {
                gGlobal->gFTZMode = std::atoi(argv[i + 1]);
                if ((gGlobal->gFTZMode > 2) || (gGlobal->gFTZMode < 0)) {
                    stringstream error;
                    error << "ERROR : invalid -ftz option: " << gGlobal->gFTZMode << endl;
                    throw faustexception(error.str());
                }
                i += 2;

            } else if (isCmd(argv[i], "-rui", "--range-ui")) {
                gGlobal->gRangeUI = true;
                i += 1;

            } else if (isCmd(argv[i], "-fm", "--fast-math")) {
                gGlobal->gFastMath    = true;
                gGlobal->gFastMathLib = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-mapp", "--math-approximation")) {
                gGlobal->gMathApprox = true;
                i += 1;

            } else if (isCmd(argv[i], "-ns", "--namespace")) {
                gGlobal->gNameSpace = argv[i + 1];
                i += 2;

            } else if (isCmd(argv[i], "-fp", "--full-parentheses")) {
                gGlobal->gFullParentheses = true;
                i += 1;

            } else if (isCmd(argv[i], "-I", "--import-dir") && (i + 1 < argc)) {
                if ((strstr(argv[i + 1], "http://") != 0) || (strstr(argv[i + 1], "https://") != 0)) {
                    // We want to search user given directories *before* the standard ones, so insert at the beginning
                    gGlobal->gImportDirList.insert(gGlobal->gImportDirList.begin(), argv[i + 1]);
                } else {
                    char  temp[PATH_MAX + 1];
                    char* path = realpath(argv[i + 1], temp);
                    if (path) {
                        // We want to search user given directories *before* the standard ones, so insert at the beginning
                        gGlobal->gImportDirList.insert(gGlobal->gImportDirList.begin(), path);
                    }
                }
                i += 2;

            } else if (isCmd(argv[i], "-A", "--architecture-dir") && (i + 1 < argc)) {
                if ((strstr(argv[i + 1], "http://") != 0) || (strstr(argv[i + 1], "https://") != 0)) {
                    gGlobal->gArchitectureDirList.push_back(argv[i + 1]);
                } else {
                    char  temp[PATH_MAX + 1];
                    char* path = realpath(argv[i + 1], temp);
                    if (path) {
                        gGlobal->gArchitectureDirList.push_back(path);
                    }
                }
                i += 2;

            } else if (isCmd(argv[i], "-L", "--library") && (i + 1 < argc)) {
                gGlobal->gLibraryList.push_back(argv[i + 1]);
                i += 2;

            } else if (isCmd(argv[i], "-O", "--output-dir") && (i + 1 < argc)) {
                char  temp[PATH_MAX + 1];
                char* path = realpath(argv[i + 1], temp);
                if (path == 0) {
                    stringstream error;
                    error << "ERROR : invalid directory path " << argv[i + 1] << endl;
                    throw faustexception(error.str());
                } else {
                    gGlobal->gOutputDir = path;
                }
                i += 2;

            } else if (isCmd(argv[i], "-inpl", "--in-place")) {
                gGlobal->gInPlace = true;
                i += 1;

            } else if (isCmd(argv[i], "-es", "--enable-semantics")) {
                gGlobal->gEnableFlag = std::atoi(argv[i + 1]) == 1;
                i += 2;

            } else if (isCmd(argv[i], "-lcc", "--local-causality-check")) {
                gGlobal->gLocalCausalityCheck = true;
                i += 1;

            } else if (isCmd(argv[i], "-light", "--light-mode")) {
                gGlobal->gLightMode = true;
                i += 1;

            } else if (isCmd(argv[i], "-clang", "--clang")) {
                gGlobal->gClang = true;
                i += 1;

            } else if (isCmd(argv[i], "-nvi", "--no-virtual")) {
                gGlobal->gNoVirtual = true;
                i += 1;

            } else if (isCmd(argv[i], "-ct", "--check-table")) {
                gGlobal->gCheckTable = "ct";
                i += 1;

            } else if (isCmd(argv[i], "-cat", "--check-all-table")) {
                gGlobal->gCheckTable = "cat";
                i += 1;

            } else if (isCmd(argv[i], "-me", "--math-exceptions")) {
                gGlobal->gMathExceptions = true;
                i += 1;

            } else if (isCmd(argv[i], "-lm", "--local-machine") || isCmd(argv[i], "-rm", "--remote-machine") ||
                       isCmd(argv[i], "-poly", "--polyphonic-mode") || isCmd(argv[i], "-voices", "--polyphonic-voices") ||
                       isCmd(argv[i], "-group", "--polyphonic-group")) {
                // Ignore arg
                i += 2;

            } else if (argv[i][0] != '-') {
                const char* url = argv[i];
                if (checkURL(url)) {
                    gGlobal->gInputFiles.push_back(url);
                }
                i++;

            } else {
                if (err == 0) {
                    parse_error << "unrecognized option(s) : \"" << argv[i] << "\"";
                } else {
                    parse_error << ",\"" << argv[i] << "\"";
                }
                i++;
                err++;
            }
        }

        // Adjust related options
        if (gGlobal->gOpenMPSwitch || gGlobal->gSchedulerSwitch) gGlobal->gVectorSwitch = true;

        // Check options coherency
        if (gGlobal->gInPlace && gGlobal->gVectorSwitch) {
            throw faustexception("ERROR : '-inpl' option can only be used in scalar mode\n");
        }

    #if 0
        if (gGlobal->gOutputLang == "ocpp" && gGlobal->gVectorSwitch) {
            throw faustexception("ERROR : 'ocpp' backend can only be used in scalar mode\n");
        }
    #endif
        if (gGlobal->gOneSample >= 0 && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "c" &&
            gGlobal->gOutputLang != "dlang" && !startWith(gGlobal->gOutputLang, "soul") && gGlobal->gOutputLang != "fir") {
            throw faustexception("ERROR : '-os' option cannot only be used with 'cpp', 'c', 'fir' or 'soul' backends\n");
        }

        if (gGlobal->gOneSample >= 0 && gGlobal->gVectorSwitch) {
            throw faustexception("ERROR : '-os' option cannot only be used in scalar mode\n");
        }

        if (gGlobal->gFTZMode == 2 && gGlobal->gOutputLang == "soul") {
            throw faustexception("ERROR : '-ftz 2' option cannot be used in 'soul' backend\n");
        }

        if (gGlobal->gVectorLoopVariant < 0 || gGlobal->gVectorLoopVariant > 1) {
            stringstream error;
            error << "ERROR : invalid loop variant [-lv = " << gGlobal->gVectorLoopVariant << "] should be 0 or 1" << endl;
            throw faustexception(error.str());
        }

        if (gGlobal->gVecSize < 4) {
            stringstream error;
            error << "ERROR : invalid vector size [-vs = " << gGlobal->gVecSize << "] should be at least 4" << endl;
            throw faustexception(error.str());
        }

        if (gGlobal->gFunTaskSwitch) {
            if (!(gGlobal->gOutputLang == "c" || gGlobal->gOutputLang == "cpp" || gGlobal->gOutputLang == "llvm" ||
                  gGlobal->gOutputLang == "fir")) {
                throw faustexception("ERROR : -fun can only be used with 'c', 'cpp', 'llvm' or 'fir' backends\n");
            }
        }

        if (gGlobal->gFastMath) {
            if (!(gGlobal->gOutputLang == "c" || gGlobal->gOutputLang == "cpp" || gGlobal->gOutputLang == "llvm" ||
                  startWith(gGlobal->gOutputLang, "wast") || startWith(gGlobal->gOutputLang, "wasm"))) {
                throw faustexception("ERROR : -fm can only be used with 'c', 'cpp', 'llvm' or 'wast/wast' backends\n");
            }
        }

        if (gGlobal->gNameSpace != "" && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "dlang") {
            throw faustexception("ERROR : -ns can only be used with the 'cpp' or 'dlang' backend\n");
        }

        if (gGlobal->gMaskDelayLineThreshold < INT_MAX && (gGlobal->gVectorSwitch || (gGlobal->gOutputLang == "ocpp"))) {
            throw faustexception(
                "ERROR : '-dlt < INT_MAX' option can only be used in scalar mode and not with the 'ocpp' backend\n");
        }

        // gComputeMix check
        if (gGlobal->gComputeMix && gGlobal->gOutputLang == "ocpp") {
            throw faustexception("ERROR : -cm cannot be used with the 'ocpp' backend\n");
        }

        if (gGlobal->gComputeMix && gGlobal->gOutputLang == "interp") {
            throw faustexception("ERROR : -cm cannot be used with the 'interp' backend\n");
        }

        if (gGlobal->gComputeMix && gGlobal->gOutputLang == "soul") {
            throw faustexception("ERROR : -cm cannot be used with the 'soul' backend\n");
        }

        if (gGlobal->gFloatSize == 4 && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "ocpp" &&
            gGlobal->gOutputLang != "c") {
            throw faustexception("ERROR : -fx can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (gGlobal->gClang && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "ocpp" &&
            gGlobal->gOutputLang != "c") {
            throw faustexception("ERROR : -clang can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (gGlobal->gNoVirtual && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "ocpp" &&
            gGlobal->gOutputLang != "c") {
            throw faustexception("ERROR : -nvi can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (gGlobal->gMemoryManager && gGlobal->gOutputLang != "cpp" && gGlobal->gOutputLang != "ocpp") {
            throw faustexception("ERROR : -mem can only be used with 'cpp' or 'ocpp' backends\n");
        }

        if (gGlobal->gArchFile != "" &&
            ((gGlobal->gOutputLang == "wast") || (gGlobal->gOutputLang == "wasm") || (gGlobal->gOutputLang == "interp") ||
             (gGlobal->gOutputLang == "llvm") || (gGlobal->gOutputLang == "fir"))) {
            throw faustexception("ERROR : -a can only be used with 'c', 'cpp', 'ocpp', 'rust' and 'soul' backends\n");
        }

        if (gGlobal->gClassName == "") {
            throw faustexception("ERROR : -cn used with empty string \n");
        }

        if (err != 0) {
            stringstream error;
            error << "WARNING : " << parse_error.str() << endl;
            gGlobal->gErrorMsg = error.str();
        }

        return (err == 0);
    } /* processCmdline(int argc, const char* argv[]) */

    static void initFaustDirectories(int argc, const char* argv[])
    {
    #if !defined(FAUST_SELF_CONTAINED_LIB)
        char s[1024];
        getFaustPathname(s, 1024);

        gGlobal->gFaustExeDir              = exepath::get(argv[0]);
        gGlobal->gFaustRootDir             = exepath::dirup(gGlobal->gFaustExeDir);
        gGlobal->gFaustDirectory           = fileDirname(s);
        gGlobal->gFaustSuperDirectory      = fileDirname(gGlobal->gFaustDirectory);
        gGlobal->gFaustSuperSuperDirectory = fileDirname(gGlobal->gFaustSuperDirectory);

        //-------------------------------------------------------------------------------------
        // init gImportDirList : a list of path where to search .lib files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_LIB_PATH")) {
            gGlobal->gImportDirList.push_back(envpath);
        }
    #ifdef INSTALL_PREFIX
        gGlobal->gImportDirList.push_back(INSTALL_PREFIX "/share/faust");
    #endif

        gGlobal->gImportDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/share/faust");
        gGlobal->gImportDirList.push_back("/usr/local/share/faust");
        gGlobal->gImportDirList.push_back("/usr/share/faust");

        //-------------------------------------------------------------------------------------
        // init gArchitectureDirList : a list of path where to search architectures files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_ARCH_PATH")) {
            gGlobal->gArchitectureDirList.push_back(envpath);
        }
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustDirectory + "/architecture");
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustSuperDirectory + "/architecture");
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustSuperSuperDirectory + "/architecture");
    #ifdef INSTALL_PREFIX
        gGlobal->gArchitectureDirList.push_back(INSTALL_PREFIX "/share/faust");
        gGlobal->gArchitectureDirList.push_back(INSTALL_PREFIX "/include");
    #endif
        gGlobal->gArchitectureDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/share/faust");
        gGlobal->gArchitectureDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/include");
        gGlobal->gArchitectureDirList.push_back("/usr/local/share/faust");
        gGlobal->gArchitectureDirList.push_back("/usr/share/faust");
        gGlobal->gArchitectureDirList.push_back("/usr/local/include");
        gGlobal->gArchitectureDirList.push_back("/usr/include");

        // for debugging purposes
        //    cerr << "gArchitectureDirList:\n";
        //    for (const auto& d : gGlobal->gArchitectureDirList) {
        //        cerr << "\t" << d << "\n";
        //    }
        //    cerr << endl;
    #endif
  } /* initFaustDirectories(int argc, const char* argv[]) */

  };

}

#endif
