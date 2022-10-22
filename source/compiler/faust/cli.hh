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
    static void printHelp()
    {
        const char* tab  = "  ";
        const char* line = "\n---------------------------------------\n";

        cout << "FAUST compiler version " << FAUSTVERSION << "\n";
        cout << "usage : faust [options] file1 [file2 ...]." << endl;
        cout << "        where options represent zero or more compiler options \n\tand fileN represents a Faust source "
                "file (.dsp extension)."
             << endl;

        cout << endl << "Input options:" << line;
        cout << tab << "-a <file>                               wrapper architecture file." << endl;
        cout << tab << "-i        --inline-architecture-files   inline architecture files." << endl;
        cout << tab << "-A <dir>  --architecture-dir <dir>      add the directory <dir> to the architecture search path."
             << endl;
        cout << tab << "-I <dir>  --import-dir <dir>            add the directory <dir> to the libraries search path."
             << endl;
        cout << tab << "-L <file> --library <file>              link with the LLVM module <file>." << endl;

        cout << tab << "-t <sec>  --timeout <sec>               abort compilation after <sec> seconds (default 120)."
             << endl;

        cout << endl << "Output options:" << line;
        cout << tab << "-o <file>                               the output file." << endl;
        cout << tab << "-e        --export-dsp                  export expanded DSP (with all included libraries)." << endl;
        cout << tab << "-uim      --user-interface-macros       add user interface macro definitions to the output code."
             << endl;
        cout << tab << "-xml                                    generate an XML description file." << endl;
        cout << tab << "-json                                   generate a JSON description file." << endl;
        cout << tab
             << "-O <dir>  --output-dir <dir>            specify the relative directory of the generated output code and "
                "of additional generated files (SVG, XML...)."
             << endl;

        cout << endl << "Code generation options:" << line;
        cout << tab << "-lang <lang> --language                 select output language," << endl;
        cout << tab
             << "                                        'lang' should be c, cpp (default), csharp, dlang, fir, interp, "
                "java, jax, julia, llvm, "
                "ocpp, rust, soul or wast/wasm."
             << endl;
        cout << tab
             << "-single     --single-precision-floats   use single precision floats for internal computations (default)."
             << endl;
        cout << tab << "-double     --double-precision-floats   use double precision floats for internal computations."
             << endl;
        cout << tab << "-quad       --quad-precision-floats     use quad precision floats for internal computations."
             << endl;
        cout << tab << "-fx         --fixed-point               use fixed-point for internal computations." << endl;
        cout << tab
             << "-es 1|0     --enable-semantics 1|0      use enable semantics when 1 (default), and simple multiplication "
                "otherwise."
             << endl;
        cout << tab << "-lcc        --local-causality-check     check causality also at local level." << endl;
        cout << tab << "-light      --light-mode                do not generate the entire DSP API." << endl;
        cout << tab
             << "-clang      --clang                     when compiled with clang/clang++, adds specific #pragma for "
                "auto-vectorization."
             << endl;
        cout << tab
             << "-nvi        --no-virtual                when compiled with the C++ backend, does not add the 'virtual' "
                "keyword."
             << endl;
        cout << tab << "-fp         --full-parentheses          always add parentheses around binops " << endl;
        cout << tab << "-exp10      --generate-exp10            pow(10,x) replaced by possibly faster exp10(x)." << endl;
        cout << tab << "-os         --one-sample                generate one sample computation (same as -os0)." << endl;
        cout << tab << "-os0        --one-sample0               generate one sample computation (0 = separated control)."
             << endl;
        cout << tab
             << "-os1        --one-sample1               generate one sample computation (1 = separated control and DSP "
                "struct)."
             << endl;
        cout << tab
             << "-os2        --one-sample2               generate one sample computation (2 = separated control and DSP "
                "struct. Separation in short and long delay lines)."
             << endl;
        cout << tab
             << "-os3        --one-sample3               generate one sample computation (3 = like 2 but with external "
                "memory pointers kept in the DSP struct)."
             << endl;

        cout << tab << "-cm         --compute-mix               mix in outputs buffers." << endl;
        cout << tab
             << "-cn <name>  --class-name <name>         specify the name of the dsp class to be used instead of mydsp."
             << endl;
        cout << tab
             << "-scn <name> --super-class-name <name>   specify the name of the super class to be used instead of dsp."
             << endl;
        cout << tab << "-pn <name>  --process-name <name>       specify the name of the dsp entry-point instead of process."
             << endl;
        cout << tab
             << "-mcd <n>    --max-copy-delay <n>        threshold between copy and ring buffer implementation (default 16 "
                "samples)."
             << endl;
        cout << tab
             << "-dlt <n>    --delay-line-threshold <n>  threshold between 'mask' and 'select' ring buffer implementation "
                "(default INT_MAX "
                "samples)."
             << endl;
        cout << tab
             << "-mem        --memory-manager            allocate static in global state using a custom memory manager."
             << endl;
        cout << tab
             << "-ftz <n>    --flush-to-zero <n>         code added to recursive signals [0:no (default), 1:fabs based, "
                "2:mask based (fastest)]."
             << endl;
        cout << tab
             << "-rui        --range-ui                  whether to generate code to limit vslider/hslider/nentry values "
                "in [min..max] range."
             << endl;
        cout
            << tab
            << "-inj <f>    --inject <f>                inject source file <f> into architecture file instead of compiling "
               "a dsp file."
            << endl;
        cout << tab << "-scal       --scalar                    generate non-vectorized code." << endl;
        cout << tab
             << "-inpl       --in-place                  generates code working when input and output buffers are the same "
                "(scalar mode only)."
             << endl;
        cout << tab << "-vec        --vectorize                 generate easier to vectorize code." << endl;
        cout << tab << "-vs <n>     --vec-size <n>              size of the vector (default 32 samples)." << endl;
        cout << tab << "-lv <n>     --loop-variant <n>          [0:fastest (default), 1:simple]." << endl;
        cout << tab << "-omp        --openmp                    generate OpenMP pragmas, activates --vectorize option."
             << endl;
        cout << tab << "-pl         --par-loop                  generate parallel loops in --openmp mode." << endl;
        cout << tab
             << "-sch        --scheduler                 generate tasks and use a Work Stealing scheduler, activates "
                "--vectorize option."
             << endl;
        cout << tab << "-ocl        --opencl                    generate tasks with OpenCL (experimental)." << endl;
        cout << tab << "-cuda       --cuda                      generate tasks with CUDA (experimental)." << endl;
        cout << tab << "-dfs        --deep-first-scheduling     schedule vector loops in deep first order." << endl;
        cout << tab
             << "-g          --group-tasks               group single-threaded sequential tasks together when -omp or -sch "
                "is used."
             << endl;
        cout << tab
             << "-fun        --fun-tasks                 separate tasks code as separated functions (in -vec, -sch, or "
                "-omp mode)."
             << endl;
        cout << tab
             << "-fm <file>  --fast-math <file>          use optimized versions of mathematical functions implemented in "
                "<file>, use 'faust/dsp/fastmath.cpp' when file is 'def'."
             << endl;
        cout << tab

             << "-mapp       --math-approximation        simpler/faster versions of 'floor/ceil/fmod/remainder' functions."
             << endl;
        cout << tab << "-ns <name>  --namespace <name>          generate C++ or D code in a namespace <name>." << endl;

        cout << tab << "-vhdl          --vhdl                   output vhdl file." << endl;
        cout << tab << "-vhdl-trace    --vhdl-trace             activate trace." << endl;
        cout << tab << "-vhdl-type 0|1 --vhdl-type 0|1          sample format 0 = sfixed (default), 1 = float." << endl;
        cout << tab << "-vhdl-msb <n>  --vhdl-msb <n>           MSB number of bits." << endl;
        cout << tab << "-vhdl-lsb <n>  --vhdl-lsb <n>           LSB number of bits." << endl;

        cout << tab << "-wi <n>     --widening-iterations <n>   number of iterations before widening in signal bounding."
             << endl;

        cout << tab
             << "-ni <n>     --narrowing-iterations <n>  number of iterations before stopping narrowing in signal bounding."
             << endl;

        cout << endl << "Block diagram options:" << line;
        cout << tab << "-ps        --postscript                 print block-diagram to a postscript file." << endl;
        cout << tab << "-svg       --svg                        print block-diagram to a svg file." << endl;
        cout << tab << "-sd        --simplify-diagrams          try to further simplify diagrams before drawing." << endl;
        cout << tab << "-drf       --draw-route-frame           draw route frames instead of simple cables." << endl;
        cout << tab
             << "-f <n>     --fold <n>                   threshold to activate folding mode during block-diagram "
                "generation (default 25 elements)."
             << endl;
        cout << tab
             << "-fc <n>    --fold-complexity <n>        complexity threshold to fold an expression in folding mode "
                "(default 2)."
             << endl;
        cout << tab
             << "-mns <n>   --max-name-size <n>          threshold during block-diagram generation (default 40 char)."
             << endl;
        cout << tab
             << "-sn        --simple-names               use simple names (without arguments) during block-diagram "
                "generation."
             << endl;
        cout << tab << "-blur      --shadow-blur                add a shadow blur to SVG boxes." << endl;

        cout << endl << "Math doc options:" << line;
        cout << tab
             << "-mdoc       --mathdoc                   print math documentation of the Faust program in LaTeX format in "
                "a -mdoc folder."
             << endl;
        cout << tab << "-mdlang <l> --mathdoc-lang <l>          if translation file exists (<l> = en, fr, ...)." << endl;
        cout << tab << "-stripmdoc  --strip-mdoc-tags           strip mdoc tags when printing Faust -mdoc listings."
             << endl;

        cout << endl << "Debug options:" << line;
        cout << tab << "-d          --details                   print compilation details." << endl;
        cout << tab << "-time       --compilation-time          display compilation phases timing information." << endl;
        cout << tab << "-flist      --file-list                 print file list (including libraries) used to eval process."
             << endl;
        cout << tab << "-tg         --task-graph                print the internal task graph in dot format." << endl;
        cout << tab << "-sg         --signal-graph              print the internal signal graph in dot format." << endl;
        cout << tab << "-norm       --normalized-form           print signals in normalized form and exit." << endl;
        cout << tab << "-ct         --check-table               check table index range and exit at first failure." << endl;
        cout << tab << "-cat        --check-all-table           check all table index range." << endl;
        cout << tab
             << "-me         --math-exceptions           check / for 0 as denominator and remainder, fmod, sqrt, log10, "
                "log, acos, asin functions domain."
             << endl;

        cout << endl << "Information options:" << line;
        cout << tab << "-h          --help                      print this help message." << endl;
        cout << tab << "-v          --version                   print version information and embedded backends list."
             << endl;
        cout << tab << "-libdir     --libdir                    print directory containing the Faust libraries." << endl;
        cout << tab << "-includedir --includedir                print directory containing the Faust headers." << endl;
        cout << tab << "-archdir    --archdir                   print directory containing the Faust architectures."
             << endl;
        cout << tab << "-dspdir     --dspdir                    print directory containing the Faust dsp libraries."
             << endl;
        cout << tab << "-pathslist  --pathslist                 print the architectures and dsp library paths." << endl;

        cout << endl << "Example:" << line;
        cout << "faust -a jack-gtk.cpp -o myfx.cpp myfx.dsp" << endl;
    }

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
