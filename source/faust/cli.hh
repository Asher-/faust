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
#include "compiler/util/exepath.hh"

#include "faust/compiler/generator/common.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

#include "compiler/parser/implementation.hh"

// Timing can be used outside of the scope of 'gGlobal'
extern bool gTimingSwitch;

string reorganizeCompilationOptions(int argc, const char* argv[]);

namespace Faust {

  struct CLI
  {
    const int _argc;
    const char** _argv;

    CLI ( const int& argc, const char* argv[] ) : _argc(argc), _argv(argv) {}

    ::Faust::Compiler::Common*
    parse()
    {
      /****************************************************************
       1 - process command line
      *****************************************************************/

      ::Faust::Controller::initFaustDirectories( _argv[0] );
      parseArgs();
      ::Faust::Compiler::Common* compiler = ::Faust::Compiler::Common::compiler( gOutputLang() );
      resolveParsedState( compiler );
      ::Faust::Type::Float::init();
      compiler->_compileOptions = reorganizeCompilationOptions(_argc, _argv);
      return compiler;
    }

    void resolveParsedState( ::Faust::Compiler::Common* compiler )
    {
      if (global::config().gHelpSwitch) {
          ::Faust::CLI::printHelp();
          throw faustexception("");
      }
      if (global::config().gVersionSwitch) {
          compiler->printVersion();
          throw faustexception("");
      }
      if (global::config().gLibDirSwitch) {
          ::Faust::Controller::printLibDir();
          throw faustexception("");
      }
      if (global::config().gIncludeDirSwitch) {
          ::Faust::Controller::printIncludeDir();
          throw faustexception("");
      }
      if (global::config().gArchDirSwitch) {
          ::Faust::Controller::printArchDir();
          throw faustexception("");
      }
      if (global::config().gDspDirSwitch) {
          ::Faust::Controller::printDspDir();
          throw faustexception("");
      }
      if (global::config().gPathListSwitch) {
          ::Faust::Controller::printPaths();
          throw faustexception("");
      }

      if (!global::config().gInjectFlag && global::config().gInputFiles.begin() == global::config().gInputFiles.end()) {
          throw faustexception("ERROR : no files specified; for help type \"faust --help\"\n");
      }

    }









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

    bool parseArgs()
    {
        std::stringstream  parse_error;
        int                i   = 1;
        int                err = 0;
        bool               float_size = false;

        /*
        for (int i = 0; i < _argc; i++) {
            cout << "parseArgs i = " << i << " cmd = " << _argv[i] << "\n";
        }
        */

        while (i < _argc) {
            if (isCmd(_argv[i], "-h", "--help")) {
                global::config().gHelpSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-lang", "--language") && (i + 1 < _argc)) {
                gOutputLang() = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-v", "--version")) {
                global::config().gVersionSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-libdir", "--libdir")) {
                global::config().gLibDirSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-includedir", "--includedir")) {
                global::config().gIncludeDirSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-archdir", "--archdir")) {
                global::config().gArchDirSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-dspdir", "--dspdir")) {
                global::config().gDspDirSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-pathslist", "--pathslist")) {
                global::config().gPathListSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-d", "--details")) {
                global::config().gDetailsSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-a", "--architecture") && (i + 1 < _argc)) {
                global::config().gArchFile = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-inj", "--inject") && (i + 1 < _argc)) {
                global::config().gInjectFlag = true;
                global::config().gInjectFile = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-o") && (i + 1 < _argc)) {
                global::config().gOutputFile = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-wi", "--widening-iterations") && (i + 1 < _argc)) {
                global::config().gWideningLimit = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-ni", "--narrowing-iterations") && (i + 1 < _argc)) {
                global::config().gNarrowingLimit = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-ps", "--postscript")) {
                global::config().gDrawPSSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-xml", "--xml")) {
                global::config().gPrintXMLSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-json", "--json")) {
                global::config().gPrintJSONSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-tg", "--task-graph")) {
                global::config().gGraphSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-sg", "--signal-graph")) {
                global::config().gDrawSignals = true;
                i += 1;

            } else if (isCmd(_argv[i], "-drf", "--draw-route-frame")) {
                global::config().gDrawRouteFrame = true;
                i += 1;

            } else if (isCmd(_argv[i], "-blur", "--shadow-blur")) {
                global::config().gShadowBlur = true;
                i += 1;

            } else if (isCmd(_argv[i], "-sc", "--scaled-svg")) {
                global::config().gScaledSVG = true;
                i += 1;

            } else if (isCmd(_argv[i], "-svg", "--svg")) {
                global::config().gDrawSVGSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-vhdl", "--vhdl")) {
                global::config().gVHDLSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-vhdl-trace", "--vhdl-trace")) {
                global::config().gVHDLTrace = true;
                i += 1;

            } else if (isCmd(_argv[i], "-vhdl-type", "--vhdl-type") && (i + 1 < _argc)) {
                global::config().gVHDLFloatType = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-vhdl-msb", "--vhdl-msb") && (i + 1 < _argc)) {
                global::config().gVHDLFloatMSB = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-vhdl-lsb", "--vhdl-lsb") && (i + 1 < _argc)) {
                global::config().gVHDLFloatLSB = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-elm", "--elementary")) {
                global::config().gElementarySwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-f", "--fold") && (i + 1 < _argc)) {
                global::config().gFoldThreshold = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-fc", "--fold-complexity") && (i + 1 < _argc)) {
                global::config().gFoldComplexity = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-mns", "--max-name-size") && (i + 1 < _argc)) {
                global::config().gMaxNameSize = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-sn", "--simple-names")) {
                global::config().gSimpleNames = true;
                i += 1;

            } else if (isCmd(_argv[i], "-mcd", "--max-copy-delay") && (i + 1 < _argc)) {
                global::config().gMaxCopyDelay = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-dlt", "-delay-line-threshold") && (i + 1 < _argc)) {
                global::config().gMaskDelayLineThreshold = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-mem", "--memory-manager")) {
                global::config().gMemoryManager = true;
                i += 1;

            } else if (isCmd(_argv[i], "-sd", "--simplify-diagrams")) {
                global::config().gSimplifyDiagrams = true;
                i += 1;

            } else if (isCmd(_argv[i], "-vec", "--vectorize")) {
                global::config().gVectorSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-scal", "--scalar")) {
                global::config().gVectorSwitch = false;
                i += 1;

            } else if (isCmd(_argv[i], "-dfs", "--deepFirstScheduling")) {
                global::config().gDeepFirstSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-vs", "--vec-size") && (i + 1 < _argc)) {
                global::config().gVecSize = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-lv", "--loop-variant") && (i + 1 < _argc)) {
                global::config().gVectorLoopVariant = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-omp", "--openmp")) {
                global::config().gOpenMPSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-pl", "--par-loop")) {
                global::config().gOpenMPLoop = true;
                i += 1;

            } else if (isCmd(_argv[i], "-sch", "--scheduler")) {
                global::config().gSchedulerSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-ocl", "--openCL")) {
                global::config().gOpenCLSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-cuda", "--CUDA")) {
                global::config().gCUDASwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-g", "--groupTasks")) {
                global::config().gGroupTaskSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-fun", "--funTasks")) {
                global::config().gFunTaskSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-uim", "--user-interface-macros")) {
                global::config().gUIMacroSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-t", "--timeout") && (i + 1 < _argc)) {
                global::config().gTimeout = std::atoi(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-time", "--compilation-time")) {
                gTimingSwitch = true;
                i += 1;

                // 'real' options
            } else if (isCmd(_argv[i], "-single", "--single-precision-floats")) {
                if (float_size && ::Faust::Primitive::Math::floatSize != 1) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                ::Faust::Primitive::Math::floatSize = 1;
                i += 1;

            } else if (isCmd(_argv[i], "-double", "--double-precision-floats")) {
                if (float_size && ::Faust::Primitive::Math::floatSize != 2) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                ::Faust::Primitive::Math::floatSize = 2;
                i += 1;

            } else if (isCmd(_argv[i], "-quad", "--quad-precision-floats")) {
                if (float_size && ::Faust::Primitive::Math::floatSize != 3) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                ::Faust::Primitive::Math::floatSize = 3;
                i += 1;

            } else if (isCmd(_argv[i], "-fx", "--fixed-point")) {
                if (float_size && ::Faust::Primitive::Math::floatSize != 4) {
                    throw faustexception("ERROR : cannot using -single, -double, -quad or -fx at the same time\n");
                } else {
                    float_size = true;
                }
                ::Faust::Primitive::Math::floatSize = 4;
                i += 1;

            } else if (isCmd(_argv[i], "-mdoc", "--mathdoc")) {
                global::config().gPrintDocSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-mdlang", "--mathdoc-lang") && (i + 1 < _argc)) {
                global::config().gDocLang = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-stripmdoc", "--strip-mdoc-tags")) {
                global::config().gStripDocSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-flist", "--file-list")) {
                global::config().gPrintFileListSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-norm", "--normalized-form")) {
                global::config().gDumpNorm = 0;
                i += 1;

            } else if (isCmd(_argv[i], "-norm1", "--normalized-form1")) {
                global::config().gDumpNorm = 1;
                i += 1;

            } else if (isCmd(_argv[i], "-cn", "--class-name") && (i + 1 < _argc)) {
                vector<char> rep    = {'@', ' ', '(', ')', '/', '\\', '.'};
                global::config().gClassName = replaceCharList(_argv[i + 1], rep, '_');
                i += 2;

            } else if (isCmd(_argv[i], "-scn", "--super-class-name") && (i + 1 < _argc)) {
                global::config().gSuperClassName = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-pn", "--process-name") && (i + 1 < _argc)) {
                global::config().gProcessName = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-i", "--inline-architecture-files")) {
                global::config().gInlineArchSwitch = true;
                i += 1;

            } else if (isCmd(_argv[i], "-e", "--export-dsp")) {
                global::config().gExportDSP = true;
                i += 1;

            } else if (isCmd(_argv[i], "-exp10", "--generate-exp10")) {
                ::Faust::Primitive::Math::hasExp10 = true;
                i += 1;

            } else if (isCmd(_argv[i], "-os", "--one-sample") || isCmd(_argv[i], "-os0", "--one-sample0")) {
                global::config().gOneSample = 0;
                i += 1;

            } else if (isCmd(_argv[i], "-os1", "--one-sample1")) {
                global::config().gOneSample = 1;
                i += 1;

            } else if (isCmd(_argv[i], "-os2", "--one-sample2")) {
                global::config().gOneSample = 2;
                i += 1;

            } else if (isCmd(_argv[i], "-os3", "--one-sample3")) {
                global::config().gOneSample = 3;
                i += 1;

            } else if (isCmd(_argv[i], "-cm", "--compute-mix")) {
                global::config().gComputeMix = true;
                i += 1;

            } else if (isCmd(_argv[i], "-ftz", "--flush-to-zero")) {
                ::Faust::Primitive::Math::FTZMode = std::atoi(_argv[i + 1]);
                if ((::Faust::Primitive::Math::FTZMode > 2) || (::Faust::Primitive::Math::FTZMode < 0)) {
                    stringstream error;
                    error << "ERROR : invalid -ftz option: " << ::Faust::Primitive::Math::FTZMode << endl;
                    throw faustexception(error.str());
                }
                i += 2;

            } else if (isCmd(_argv[i], "-rui", "--range-ui")) {
                global::config().gRangeUI = true;
                i += 1;

            } else if (isCmd(_argv[i], "-fm", "--fast-math")) {
                global::config().gFastMath    = true;
                global::config().gFastMathLib = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-mapp", "--math-approximation")) {
                ::Faust::Primitive::Math::approx = true;
                i += 1;

            } else if (isCmd(_argv[i], "-ns", "--namespace")) {
                global::config().gNameSpace = _argv[i + 1];
                i += 2;

            } else if (isCmd(_argv[i], "-fp", "--full-parentheses")) {
                global::config().gFullParentheses = true;
                i += 1;

            } else if (isCmd(_argv[i], "-I", "--import-dir") && (i + 1 < _argc)) {
                if ((strstr(_argv[i + 1], "http://") != 0) || (strstr(_argv[i + 1], "https://") != 0)) {
                    // We want to search user given directories *before* the standard ones, so insert at the beginning
                    global::config().gImportDirList.insert(global::config().gImportDirList.begin(), _argv[i + 1]);
                } else {
                    char  temp[PATH_MAX + 1];
                    char* path = realpath(_argv[i + 1], temp);
                    if (path) {
                        // We want to search user given directories *before* the standard ones, so insert at the beginning
                        global::config().gImportDirList.insert(global::config().gImportDirList.begin(), path);
                    }
                }
                i += 2;

            } else if (isCmd(_argv[i], "-A", "--architecture-dir") && (i + 1 < _argc)) {
                if ((strstr(_argv[i + 1], "http://") != 0) || (strstr(_argv[i + 1], "https://") != 0)) {
                    global::config().gArchitectureDirList.push_back(_argv[i + 1]);
                } else {
                    char  temp[PATH_MAX + 1];
                    char* path = realpath(_argv[i + 1], temp);
                    if (path) {
                        global::config().gArchitectureDirList.push_back(path);
                    }
                }
                i += 2;

            } else if (isCmd(_argv[i], "-L", "--library") && (i + 1 < _argc)) {
                global::config().gLibraryList.push_back(_argv[i + 1]);
                i += 2;

            } else if (isCmd(_argv[i], "-O", "--output-dir") && (i + 1 < _argc)) {
                char  temp[PATH_MAX + 1];
                char* path = realpath(_argv[i + 1], temp);
                if (path == 0) {
                    stringstream error;
                    error << "ERROR : invalid directory path " << _argv[i + 1] << endl;
                    throw faustexception(error.str());
                } else {
                    global::config().gOutputDir = path;
                }
                i += 2;

            } else if (isCmd(_argv[i], "-inpl", "--in-place")) {
                global::config().gInPlace = true;
                i += 1;

            } else if (isCmd(_argv[i], "-es", "--enable-semantics")) {
                global::config().gEnableFlag = std::atoi(_argv[i + 1]) == 1;
                i += 2;

            } else if (isCmd(_argv[i], "-lcc", "--local-causality-check")) {
                global::config().gLocalCausalityCheck = true;
                i += 1;

            } else if (isCmd(_argv[i], "-light", "--light-mode")) {
                global::config().gLightMode = true;
                i += 1;

            } else if (isCmd(_argv[i], "-clang", "--clang")) {
                global::config().gClang = true;
                i += 1;

            } else if (isCmd(_argv[i], "-nvi", "--no-virtual")) {
                global::config().gNoVirtual = true;
                i += 1;

            } else if (isCmd(_argv[i], "-ct", "--check-table")) {
                global::config().gCheckTable = "ct";
                i += 1;

            } else if (isCmd(_argv[i], "-cat", "--check-all-table")) {
                global::config().gCheckTable = "cat";
                i += 1;

            } else if (isCmd(_argv[i], "-me", "--math-exceptions")) {
                ::Faust::Primitive::Math::exceptions = true;
                i += 1;

            } else if (isCmd(_argv[i], "-lm", "--local-machine") || isCmd(_argv[i], "-rm", "--remote-machine") ||
                       isCmd(_argv[i], "-poly", "--polyphonic-mode") || isCmd(_argv[i], "-voices", "--polyphonic-voices") ||
                       isCmd(_argv[i], "-group", "--polyphonic-group")) {
                // Ignore arg
                i += 2;

            } else if (_argv[i][0] != '-') {
                const char* url = _argv[i];
                if (checkURL(url)) {
                    global::config().gInputFiles.push_back(url);
                }
                i++;

            } else {
                if (err == 0) {
                    parse_error << "unrecognized option(s) : \"" << _argv[i] << "\"";
                } else {
                    parse_error << ",\"" << _argv[i] << "\"";
                }
                i++;
                err++;
            }
        }

        // Adjust related options
        if (global::config().gOpenMPSwitch || global::config().gSchedulerSwitch) global::config().gVectorSwitch = true;

        // Check options coherency
        if (global::config().gInPlace && global::config().gVectorSwitch) {
            throw faustexception("ERROR : '-inpl' option can only be used in scalar mode\n");
        }

    #if 0
        if (gOutputLang() == "ocpp" && global::config().gVectorSwitch) {
            throw faustexception("ERROR : 'ocpp' backend can only be used in scalar mode\n");
        }
    #endif
        if (global::config().gOneSample >= 0 && gOutputLang() != "cpp" && gOutputLang() != "c" &&
            gOutputLang() != "dlang" && !startWith(gOutputLang(), "soul") && gOutputLang() != "fir") {
            throw faustexception("ERROR : '-os' option cannot only be used with 'cpp', 'c', 'fir' or 'soul' backends\n");
        }

        if (global::config().gOneSample >= 0 && global::config().gVectorSwitch) {
            throw faustexception("ERROR : '-os' option cannot only be used in scalar mode\n");
        }

        if (::Faust::Primitive::Math::FTZMode == 2 && gOutputLang() == "soul") {
            throw faustexception("ERROR : '-ftz 2' option cannot be used in 'soul' backend\n");
        }

        if (global::config().gVectorLoopVariant < 0 || global::config().gVectorLoopVariant > 1) {
            stringstream error;
            error << "ERROR : invalid loop variant [-lv = " << global::config().gVectorLoopVariant << "] should be 0 or 1" << endl;
            throw faustexception(error.str());
        }

        if (global::config().gVecSize < 4) {
            stringstream error;
            error << "ERROR : invalid vector size [-vs = " << global::config().gVecSize << "] should be at least 4" << endl;
            throw faustexception(error.str());
        }

        if (global::config().gFunTaskSwitch) {
            if (!(gOutputLang() == "c" || gOutputLang() == "cpp" || gOutputLang() == "llvm" ||
                  gOutputLang() == "fir")) {
                throw faustexception("ERROR : -fun can only be used with 'c', 'cpp', 'llvm' or 'fir' backends\n");
            }
        }

        if (global::config().gFastMath) {
            if (!(gOutputLang() == "c" || gOutputLang() == "cpp" || gOutputLang() == "llvm" ||
                  startWith(gOutputLang(), "wast") || startWith(gOutputLang(), "wasm"))) {
                throw faustexception("ERROR : -fm can only be used with 'c', 'cpp', 'llvm' or 'wast/wast' backends\n");
            }
        }

        if (global::config().gNameSpace != "" && gOutputLang() != "cpp" && gOutputLang() != "dlang") {
            throw faustexception("ERROR : -ns can only be used with the 'cpp' or 'dlang' backend\n");
        }

        if (global::config().gMaskDelayLineThreshold < INT_MAX && (global::config().gVectorSwitch || (gOutputLang() == "ocpp"))) {
            throw faustexception(
                "ERROR : '-dlt < INT_MAX' option can only be used in scalar mode and not with the 'ocpp' backend\n");
        }

        // gComputeMix check
        if (global::config().gComputeMix && gOutputLang() == "ocpp") {
            throw faustexception("ERROR : -cm cannot be used with the 'ocpp' backend\n");
        }

        if (global::config().gComputeMix && gOutputLang() == "interp") {
            throw faustexception("ERROR : -cm cannot be used with the 'interp' backend\n");
        }

        if (global::config().gComputeMix && gOutputLang() == "soul") {
            throw faustexception("ERROR : -cm cannot be used with the 'soul' backend\n");
        }

        if (::Faust::Primitive::Math::floatSize == 4 && gOutputLang() != "cpp" && gOutputLang() != "ocpp" &&
            gOutputLang() != "c") {
            throw faustexception("ERROR : -fx can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (global::config().gClang && gOutputLang() != "cpp" && gOutputLang() != "ocpp" &&
            gOutputLang() != "c") {
            throw faustexception("ERROR : -clang can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (global::config().gNoVirtual && gOutputLang() != "cpp" && gOutputLang() != "ocpp" &&
            gOutputLang() != "c") {
            throw faustexception("ERROR : -nvi can only be used with 'c', 'cpp' or 'ocpp' backends\n");
        }

        if (global::config().gMemoryManager && gOutputLang() != "cpp" && gOutputLang() != "ocpp") {
            throw faustexception("ERROR : -mem can only be used with 'cpp' or 'ocpp' backends\n");
        }

        if (global::config().gArchFile != "" &&
            ((gOutputLang() == "wast") || (gOutputLang() == "wasm") || (gOutputLang() == "interp") ||
             (gOutputLang() == "llvm") || (gOutputLang() == "fir"))) {
            throw faustexception("ERROR : -a can only be used with 'c', 'cpp', 'ocpp', 'rust' and 'soul' backends\n");
        }

        if (global::config().gClassName == "") {
            throw faustexception("ERROR : -cn used with empty string \n");
        }

        if (err != 0) {
            stringstream error;
            error << "WARNING : " << parse_error.str() << endl;
            global::config().gErrorMsg = error.str();
        }

        return (err == 0);
    } /* parseArgs(int _argc, const char* _argv[]) */


  };

}

#endif
