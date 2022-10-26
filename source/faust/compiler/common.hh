/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
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

#ifndef __FAUST_COMPILE_COMMON_HH__
#define __FAUST_COMPILE_COMMON_HH__

#include <cassert>

#include "faust.hh"
#include "file_handling/string_substitution.hh"
#include "faust/controller.hh"

#include "architectures.hh"
#include "exception.hh"
#include "propagate.hh"

#include "sigprint.hh"
#include "ppsig.hh"
#include "eval.hh"
#include "ppbox.hh"
#include "drawschema.hh"

#include "timing.hh"

#include "instructions_compiler.hh"
#include "doc.hh"


#ifdef DLANG_BUILD
#include "dlang_code_container.hh"
#endif

namespace Faust {
  namespace Compiler {

    struct Common
    {
      std::string _name{"FaustDSP"};
      std::string _dspContent{};
      bool        _generate{true};
      std::string _compileOptions{};
      unique_ptr<ifstream> _injcode;
      unique_ptr<ostream>  _helpers;
      Tree _lsignals{nullptr};

      InstructionsCompiler* _instructionCompiler = nullptr;
      CodeContainer*        _codeContainer = nullptr;

      static constexpr const char* DSPtoTargetString = "   DSP to ";

      Common
      () = default;
      Common
      ( const std::string& name )
      : _name(name)
      {}
      Common
      ( const std::string& name,
        const std::string& dsp_content )
      : Common(
          name,
          dsp_content,
          true
        )
      {}
      Common
      ( const std::string& name,
        const bool&        generate )
      : _name(name),
        _generate(generate)
      {}
      Common
      ( const std::string& name,
        const std::string& dsp_content,
        const bool&        generate )
      : _name(name),
        _dspContent(dsp_content),
        _generate(generate)
      {
          if (dsp_content.length() > 0) {
              gGlobal->gInputString = dsp_content.c_str();
              gGlobal->gInputFiles.push_back(name);
          }
      }

      static Common* compiler( const std::string& output_lang );

      /****************************************************************
                           Required Overrides
      *****************************************************************/

      virtual const char* const& targetString() = 0;

      /****************************************************************
                           Help and Version information
      *****************************************************************/

      void printVersion()
      {
          std::cout << "FAUST Version " << FAUSTVERSION << std::endl;
          std::cout << "Embedded backends: " << std::endl;
          std::cout << DSPtoTargetString << this->targetString() << std::endl;
          std::cout << "Copyright (C) 2002-2022, GRAME - Centre National de Creation Musicale. All rights reserved." << std::endl;
      }

      static void printDeclareHeader(ostream& dst)
      {
          for (const auto& i : gGlobal->gMetaDataSet) {
              if (i.first != tree("author")) {
                  dst << "declare ";
                  stringstream key;
                  key << *(i.first);
                  vector<char> rep{'.', ':', '/'};
                  dst << replaceCharList(key.str(), rep, '_');
                  dst << " " << **(i.second.begin()) << ";" << endl;
              } else {
                  for (set<Tree>::iterator j = i.second.begin(); j != i.second.end(); ++j) {
                      if (j == i.second.begin()) {
                          dst << "declare " << *(i.first) << " " << **j << ";" << endl;
                      } else {
                          dst << "declare contributor " << **j << ";" << endl;
                      }
                  }
              }
          }
      }

      virtual
      void
      printXML()
      {
          this->printXML(
              this->_instructionCompiler->getDescription(),
              this->_codeContainer->inputs(),
              this->_codeContainer->outputs()
          );
      }

      void
      printXML(
        Description* description,
        int inputs,
        int outputs
      )
      {
          faustassert(description);
          ofstream xout(subst("$0.xml", gGlobal->makeDrawPath()).c_str());

          MetaDataSet::const_iterator it1;
          set<Tree>::const_iterator   it2;
          for (const auto& it1 : gGlobal->gMetaDataSet) {
              const string key = tree2str(it1.first);
              for (it2 = it1.second.begin(); it2 != it1.second.end(); ++it2) {
                  const string value = tree2str(*it2);
                  if (key == "name") {
                      description->name(value);
                  } else if (key == "author") {
                      description->author(value);
                  } else if (key == "copyright") {
                      description->copyright(value);
                  } else if (key == "license") {
                      description->license(value);
                  } else if (key == "version") {
                      description->version(value);
                  } else {
                      description->declare(key, value);
                  }
              }
          }

          description->className(gGlobal->gClassName);
          description->inputs(inputs);
          description->outputs(outputs);
          description->print(0, xout);
      }

      void createHelperFile(const string& outpath)
      {
          // Additional file with JS code
          if (gGlobal->gOutputFile == "binary") {
              // Nothing
          } else if (gGlobal->gOutputFile != "") {
              string outpath_js;
              bool   res = replaceExtension(outpath, ".js", outpath_js);
              if (res) {
                  _helpers = unique_ptr<ostream>(new ofstream(outpath_js.c_str()));
              } else {
                  cerr << "WARNING : cannot generate helper JS file, outpath is incorrect : \"" << outpath << "\"" << endl;
              }
          } else {
              _helpers = unique_ptr<ostream>(new ostringstream());
          }
      }

      virtual void compile(Tree signals, int numInputs, int numOutputs) = 0;
      virtual void compile(Tree signals, int numInputs, int numOutputs, bool generate) { return this->compile(signals, numInputs, numOutputs); };
      virtual void compile(Tree signals, int numInputs, int numOutputs, ostream* out) { return compile(signals, numInputs, numOutputs); };
      virtual void compile(Tree signals, int numInputs, int numOutputs, ostream* out, const std::string&) { return compile(signals, numInputs, numOutputs, out); };

      void injectCode(unique_ptr<ifstream>& enrobage, ostream& dst)
      {
          /****************************************************************
           1.7 - Inject code instead of compile
           *****************************************************************/

          // Check if this is a code injection
          if (gGlobal->gInjectFlag) {
              if (gGlobal->gArchFile == "") {
                  std::stringstream error;
                  error << "ERROR : no architecture file specified to inject \"" << gGlobal->gInjectFile << "\"" << endl;
                  throw faustexception(error.str());
              } else {
                  streamCopyUntil(*enrobage.get(), dst, "<<includeIntrinsic>>");
                  this->_codeContainer->printMacros(dst, 0);
                  streamCopyUntil(*enrobage.get(), dst, "<<includeclass>>");
                  streamCopyUntilEnd(*_injcode.get(), dst);
                  streamCopyUntilEnd(*enrobage.get(), dst);
              }
              throw faustexception("");
          }
      }

      Tree evaluateBlockDiagram(Tree expandedDefList, int& numInputs, int& numOutputs)
      {
          startTiming("evaluation");

          Tree process = evalprocess(expandedDefList);
          if (gGlobal->gErrorCount > 0) {
              stringstream error;
              error << "ERROR : total of " << gGlobal->gErrorCount << " errors during the compilation of "
                    << gGlobal->gMasterDocument << endl;
              throw faustexception(error.str());
          }

          if (gGlobal->gDetailsSwitch) {
              cout << "process = " << boxpp(process) << ";\n";
          }

          if (!getBoxType(process, &numInputs, &numOutputs)) {
              stringstream error;
              error << "ERROR during the evaluation of process : " << boxpp(process) << endl;
              throw faustexception(error.str());
          }

          if (gGlobal->gDrawPSSwitch) {
              drawSchema(process, subst("$0-ps", gGlobal->makeDrawPathNoExt()).c_str(), "ps");
          }

          if (gGlobal->gDrawSVGSwitch) {
              drawSchema(process, subst("$0-svg", gGlobal->makeDrawPathNoExt()).c_str(), "svg");
          }

          if (gGlobal->gDetailsSwitch) {
              cout << "process has " << numInputs << " inputs, and " << numOutputs << " outputs" << endl;
          }

          endTiming("evaluation");

          if (gGlobal->gPrintFileListSwitch) {
              cout << "---------------------------\n";
              cout << "List of file dependencies :\n";
              cout << "---------------------------\n";
              // print the pathnames of the files used to evaluate process
              vector<string> pathnames = gGlobal->gReader.listSrcFiles();
              for (size_t i = 0; i < pathnames.size(); i++) cout << pathnames[i] << endl;
              cout << "---------------------------\n";
              cout << endl;
          }

          return process;
      }

      void parseSourceFiles()
      {
          assert( gGlobal->gInjectFlag || (gGlobal->gInputFiles.begin() != gGlobal->gInputFiles.end()) );

          startTiming("parser");

          std::list<string>::iterator s;
          gGlobal->gResult2 = gGlobal->nil;
          gGlobal->gReader.init();

          if (!gGlobal->gInjectFlag && gGlobal->gInputFiles.begin() == gGlobal->gInputFiles.end()) {
              throw faustexception("ERROR : no files specified; for help type \"faust --help\"\n");
          }

          for (s = gGlobal->gInputFiles.begin(); s != gGlobal->gInputFiles.end(); s++) {
              if (s == gGlobal->gInputFiles.begin()) {
                  gGlobal->gMasterDocument = *s;
              }
              gGlobal->gResult2 = cons(importFile(tree(s->c_str())), gGlobal->gResult2);
          }

          gGlobal->gExpandedDefList = gGlobal->gReader.expandList(gGlobal->gResult2);

          endTiming("parser");
      }

      static void* threadEvaluateBlockDiagram(void* arg)
      {
          ::Faust::Compiler::Common* compiler{reinterpret_cast<::Faust::Compiler::Common*>(arg)};
          try {
              gGlobal->gProcessTree =
                  compiler->evaluateBlockDiagram(gGlobal->gExpandedDefList, gGlobal->gNumInputs, gGlobal->gNumOutputs);
          } catch (faustexception& e) {
              gGlobal->gErrorMessage = e.Message();
          }
          return 0;
      }

      typedef void* (*compile_fun)(void* compiler);

      void callFunctionInNewThread(compile_fun fun)
      {
      #if defined(EMCC)
          // No thread support in JS or WIN32
          fun(this);
      #elif defined(_WIN32)
          DWORD  id;
          HANDLE thread = CreateThread(NULL, MAX_STACK_SIZE, LPTHREAD_START_ROUTINE(fun), this, 0, &id);
          faustassert(thread != NULL);
          WaitForSingleObject(thread, INFINITE);
      #else
          pthread_t      thread;
          pthread_attr_t attr;
          faustassert(pthread_attr_init(&attr) == 0);
          faustassert(pthread_attr_setstacksize(&attr, MAX_STACK_SIZE) == 0);
          faustassert(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE) == 0);
          faustassert(pthread_create(&thread, &attr, fun, this) == 0);
          pthread_join(thread, nullptr);
      #endif
      }

      void evaluateBlockDiagramInNewThread()
      {
          callFunctionInNewThread(threadEvaluateBlockDiagram);  // In a thread with more stack size...
      }

      Tree DSPToBoxes(const std::string& name_app, const std::string& dsp_content, int* inputs, int* outputs, std::string& error_msg)
      {
          /****************************************************************
           1 - process command line
           *****************************************************************/

          faust_alarm(gGlobal->gTimeout);

          /****************************************************************
           2 - parse source files
           *****************************************************************/
          if (dsp_content.c_str()) {
              gGlobal->gInputString = dsp_content.c_str();
              gGlobal->gInputFiles.push_back(name_app.c_str());
          }
          ::Faust::Controller::initDocumentNames();
          ::Faust::Type::Float::init();

          try {
              this->parseSourceFiles();
          } catch (faustexception& e) {
              error_msg = e.what();
              return nullptr;
          }

          /****************************************************************
           3 - evaluate 'process' definition
           *****************************************************************/

          evaluateBlockDiagramInNewThread();
          if (gGlobal->gProcessTree) {
              *inputs  = gGlobal->gNumInputs;
              *outputs = gGlobal->gNumOutputs;
              return gGlobal->gProcessTree;
          } else {
              error_msg = gGlobal->gErrorMessage;
              return nullptr;
          }
      }

      void injectCodeFromFiles()
      {
          /****************************************************************
           1.5 - Inject Code if needed
          *****************************************************************/
          // Check for injected code (before checking for architectures)
          if (gGlobal->gInjectFlag) {
              _injcode = openArchStream(gGlobal->gInjectFile.c_str());
              if (!_injcode) {
                  stringstream error;
                  error << "ERROR : can't inject \"" << gGlobal->gInjectFile << "\" external code file, file not found\n";
                  throw faustexception(error.str());
              }
          }
      }

      void evaluateProcessDefinition()
      {
          /****************************************************************
           3 - evaluate 'process' definition
          *****************************************************************/

          evaluateBlockDiagramInNewThread();

          if (!gGlobal->gProcessTree) {
              throw faustexception(gGlobal->gErrorMessage);
          }
      }

      bool expandDSP()
      {
        /****************************************************************
         3.1 - possibly expand the DSP and return
         *****************************************************************/

        if (gGlobal->gExportDSP) {
            string outpath =
                (gGlobal->gOutputDir != "") ? (gGlobal->gOutputDir + "/" + gGlobal->gOutputFile) : gGlobal->gOutputFile;
            ofstream out(outpath.c_str());
            this->expandDSPInternalAux(out);
            return true;
        }

        return false;
      }

      void includeFile(const std::string& file, std::ostream& dst)
      {
          std::unique_ptr<ifstream> file_include = openArchStream(file.c_str());
          if (file_include) {
              streamCopyUntilEnd(*file_include.get(), dst);
          }
      }

      void expandDSPInternalAux(ostream& out)
      {
          // Encode compilation options as a 'declare' : has to be located first in the string
          out << "declare version \"" << FAUSTVERSION << "\";" << endl;
          out << COMPILATION_OPTIONS << this->_compileOptions << ';' << endl;

          // Encode all libraries paths as 'declare'
          vector<string> pathnames = gGlobal->gReader.listSrcFiles();
          // Remove DSP filename
          pathnames.erase(pathnames.begin());
          int i = 0;
          for (const auto& it : pathnames) {
              out << "declare library_path" << to_string(i++) << " \"" << it << "\";" << endl;
          }

          this->printDeclareHeader(out);
          boxppShared(gGlobal->gProcessTree, out);
      }

      static void* threadBoxPropagateSig(void* arg)
      {
          try {
              gGlobal->gLsignalsTree =
                  boxPropagateSig(gGlobal->nil, gGlobal->gProcessTree, makeSigInputList(gGlobal->gNumInputs));
          } catch (faustexception& e) {
              gGlobal->gErrorMessage = e.Message();
          }
          return 0;
      }

      void computeOutputSignals()
      {
          /****************************************************************
           4 - compute output signals of 'process'
          *****************************************************************/

          startTiming("propagation");

          ::Faust::Compiler::Common::callFunctionInNewThread(threadBoxPropagateSig);  // In a thread with more stack size...
          if (!gGlobal->gLsignalsTree) {
              throw faustexception(gGlobal->gErrorMessage);
          }
          _lsignals = gGlobal->gLsignalsTree;

          if (gGlobal->gDetailsSwitch) {
              cout << "output signals are : " << endl;
              printSignal(_lsignals, stdout);
              cout << std::endl << ppsig(_lsignals) << std::endl;
              cout << "\n\n";
          }

          endTiming("propagation");
      }

      void translateOutputSignals()
      {
          /*************************************************************************
          5 - preparation of the signal tree and translate output signals
          **************************************************************************/

          int numInputs  = gGlobal->gNumInputs;
          int numOutputs = gGlobal->gNumOutputs;
          if (numOutputs == 0) {
              throw faustexception("ERROR : the Faust program has no output signal\n");
          }
          compileCode(_lsignals, numInputs, numOutputs);
      }

      virtual void generateXMLDescription()
      {
          /****************************************************************
           1 - generate XML description (if required)
          *****************************************************************/

          if (gGlobal->gPrintXMLSwitch) {
            this->printXML();
          }
      }

      void generateOutputFiles()
      {
          /****************************************************************
           1 - generate XML description (if required)
          *****************************************************************/

          this->generateXMLDescription();

          /****************************************************************
           2 - generate documentation from Faust comments (if required)
          *****************************************************************/

          if (gGlobal->gPrintDocSwitch && gGlobal->gLatexDocSwitch) {
              printDoc(subst("$0-mdoc", gGlobal->makeDrawPathNoExt()).c_str(), "tex", FAUSTVERSION);
          }

          /****************************************************************
           3 - generate the task graph file in dot format
          *****************************************************************/

          if (gGlobal->gGraphSwitch) {
              ofstream dotfile(subst("$0.dot", gGlobal->makeDrawPath()).c_str());
              this->printGraphDotFormat(dotfile);
          }
      }

      virtual
      void
      printGraphDotFormat(
        std::ofstream&  dotfile
      )
      {
          this->_codeContainer->printGraphDotFormat(dotfile);
      }

      /* From Source */
      void createFactory()
      {
          faust_alarm(gGlobal->gTimeout);

          /****************************************************************
           1.5 - Inject Code if needed
          *****************************************************************/

          injectCodeFromFiles();

          /****************************************************************
           2 - parse source files
          *****************************************************************/

          ::Faust::Controller::initDocumentNames();
          parseSourceFiles();

          /****************************************************************
           3 - evaluate 'process' definition
          *****************************************************************/

          evaluateProcessDefinition();

          /****************************************************************
           3.1 - possibly expand the DSP and return
           *****************************************************************/

          if ( expandDSP() )
            return;

          /****************************************************************
           4 - compute output signals of 'process'
          *****************************************************************/

          computeOutputSignals();

          /*************************************************************************
          5 - preparation of the signal tree and translate output signals
          **************************************************************************/

          translateOutputSignals();

          /****************************************************************
           6 - generate xml description, documentation or dot files
          *****************************************************************/
          generateOutputFiles();
      }


      /* From Signals */
      void createFactory(const char* name, Tree signals, int numInputs,
                                int numOutputs)
      {
          /****************************************************************
           1 - process command line
           *****************************************************************/

          ::Faust::Controller::initDocumentNames();

          /*************************************************************************
           5 - preparation of the signal tree and translate output signals
           **************************************************************************/

          gGlobal->gMetaDataSet[tree("name")].insert(tree(quote(name)));
          compileCode(signals, numInputs, numOutputs);
      }

      void generateCode(unique_ptr<ostream>& dst)
      {
        unique_ptr<ifstream> enrobage;
          if (gGlobal->gArchFile != "") {
              if ((enrobage = openArchStream(gGlobal->gArchFile.c_str()))) {
                  if (gGlobal->gNameSpace != "" && gGlobal->gOutputLang == "cpp")
                      *dst.get() << "namespace " << gGlobal->gNameSpace << " {" << endl;
      #ifdef DLANG_BUILD
                  else if (gGlobal->gOutputLang == "dlang") {
                      DLangCodeContainer::printDRecipeComment(*dst.get(), this->_codeContainer->getClassName());
                      DLangCodeContainer::printDModuleStmt(*dst.get(), this->_codeContainer->getClassName());
                  }
      #endif

                  // Possibly inject code
                  this->injectCode(enrobage, *dst.get());

                  this->_codeContainer->printHeader();

                  streamCopyUntil(*enrobage.get(), *dst.get(), "<<includeIntrinsic>>");
                  streamCopyUntil(*enrobage.get(), *dst.get(), "<<includeclass>>");

                  if (gGlobal->gOpenCLSwitch || gGlobal->gCUDASwitch) {
                      includeFile("thread.h", *dst.get());
                  }

                  this->_codeContainer->printFloatDef();
                  this->_codeContainer->produceClass();

                  streamCopyUntilEnd(*enrobage.get(), *dst.get());

                  if (gGlobal->gSchedulerSwitch) {
                      includeFile("scheduler.cpp", *dst.get());
                  }

                  this->_codeContainer->printFooter();

                  // Generate factory
                  gGlobal->gDSPFactory = this->_codeContainer->produceFactory();

                  if (gGlobal->gOutputFile == "string") {
                      gGlobal->gDSPFactory->write(dst.get(), false, false);
                  } else if (gGlobal->gOutputFile == "binary") {
                      gGlobal->gDSPFactory->write(dst.get(), true, false);
                  } else if (gGlobal->gOutputFile != "") {
                      // Binary mode for LLVM backend if output different of 'cout'
                      gGlobal->gDSPFactory->write(dst.get(), true, false);
                  } else {
                      gGlobal->gDSPFactory->write(&cout, false, false);
                  }

                  if (gGlobal->gNameSpace != "" && gGlobal->gOutputLang == "cpp") {
                      *dst.get() << "} // namespace " << gGlobal->gNameSpace << endl;
                  }

              } else {
                  stringstream error;
                  error << "ERROR : can't open architecture file " << gGlobal->gArchFile << endl;
                  throw faustexception(error.str());
              }

          } else {
              this->_codeContainer->printHeader();
              this->_codeContainer->printFloatDef();
              this->_codeContainer->produceClass();
              this->_codeContainer->printFooter();

              // Generate factory
              gGlobal->gDSPFactory = this->_codeContainer->produceFactory();

              if (gGlobal->gOutputFile == "string") {
                  gGlobal->gDSPFactory->write(dst.get(), false, false);
                  if (_helpers) gGlobal->gDSPFactory->writeHelper(_helpers.get(), false, false);
              } else if (gGlobal->gOutputFile == "binary") {
                  gGlobal->gDSPFactory->write(dst.get(), true, false);
                  if (_helpers) gGlobal->gDSPFactory->writeHelper(_helpers.get(), true, false);
              } else if (gGlobal->gOutputFile != "") {
                  // Binary mode for LLVM backend if output different of 'cout'
                  gGlobal->gDSPFactory->write(dst.get(), true, false);
                  if (_helpers) gGlobal->gDSPFactory->writeHelper(_helpers.get(), false, false);
              } else {
                  gGlobal->gDSPFactory->write(&cout, false, false);
                  if (_helpers) gGlobal->gDSPFactory->writeHelper(&cout, false, false);
              }
          }
      }

      void compileCode(Tree signals, int numInputs, int numOutputs)
      {
          /*******************************************************************
           MANDATORY: use ostringstream which is indeed a subclass of ostream
           (otherwise subtle dynamic_cast related crash can occur...)
          *******************************************************************/

          unique_ptr<ostream> dst;
          string              outpath;

          if (gGlobal->gOutputFile == "string") {
              dst = unique_ptr<ostream>(new ostringstream());
          } else if (gGlobal->gOutputFile == "binary") {
              dst = unique_ptr<ostream>(new ostringstream(ostringstream::out | ostringstream::binary));
          } else if (gGlobal->gOutputFile != "") {
              outpath =
                  (gGlobal->gOutputDir != "") ? (gGlobal->gOutputDir + "/" + gGlobal->gOutputFile) : gGlobal->gOutputFile;

              unique_ptr<ofstream> fdst = unique_ptr<ofstream>(new ofstream(outpath.c_str()));
              if (!fdst->is_open()) {
                  stringstream error;
                  error << "ERROR : file '" << outpath << "' cannot be opened\n";
                  throw faustexception(error.str());
              } else {
                  dst = move(fdst);
              }

          } else {
              dst = unique_ptr<ostream>(new ostringstream());
          }

          startTiming("generateCode");

          /****************************************************************
           * create container
           ****************************************************************/


          this->compile(signals, numInputs, numOutputs, dst.get(), outpath);

          /****************************************************************
           * generate output file
           ****************************************************************/

          this->generateCode(dst);

          endTiming("generateCode");
      }


    };

  }
}

#endif
