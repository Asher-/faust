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

#ifndef __FAUST_COMPILE_OCPP_HH__
#define __FAUST_COMPILE_OCPP_HH__

#include "faust.hh"
#include "faust/compiler/generator/common.hh"
#include "instruction_compiler1.hh"

#include "compile_scalar.hh"
#include "compile_sched.hh"
#include "compile_vect.hh"

namespace Faust {
  namespace Compiler {

    struct OCPP : public Common
    {

      static constexpr const char* TargetString = "old C++";
      static constexpr const char* LanguageString = "ocpp";

      static unique_ptr<ifstream> enrobage;

      ::Compiler* _instructionCompiler = nullptr;

      static void printHeader(ostream& dst)
      {
          // defines the metadata we want to print as comments at the begin of in the C++ file
          set<Tree> selectedKeys;
          selectedKeys.insert(tree("name"));
          selectedKeys.insert(tree("author"));
          selectedKeys.insert(tree("copyright"));
          selectedKeys.insert(tree("license"));
          selectedKeys.insert(tree("version"));

          dst << "//----------------------------------------------------------" << endl;
          for (const auto& i : global::config().gMetaDataSet) {
              if (selectedKeys.count(i.first)) {
                  dst << "// " << *(i.first);
                  const char* sep = ": ";
                  for (const auto& j : i.second) {
                      dst << sep << *j;
                      sep = ", ";
                  }
                  dst << endl;
              }
          }

          dst << "//" << endl;
          dst << "// Code generated with Faust " << FAUSTVERSION << " (https://faust.grame.fr)" << endl;
          dst << "//----------------------------------------------------------" << endl << endl;
      }

      void generateCode(unique_ptr<ostream>& dst)
      {
          // Check for architecture file
          if (global::config().gArchFile != "") {
              if ((enrobage = openArchStream(global::config().gArchFile.c_str())) == nullptr) {
                  stringstream error;
                  error << "ERROR : can't open architecture file " << global::config().gArchFile << endl;
                  throw faustexception(error.str());
              }
          }

          // Possibly inject code
          this->injectCode(enrobage, *dst.get());

          printHeader(*dst);
          this->_instructionCompiler->getClass()->printLibrary(*dst.get());
          this->_instructionCompiler->getClass()->printIncludeFile(*dst.get());
          this->_instructionCompiler->getClass()->printAdditionalCode(*dst.get());

          if (global::config().gArchFile != "") {
              streamCopyUntil(*enrobage.get(), *dst.get(), "<<includeIntrinsic>>");

              if (global::config().gSchedulerSwitch) {
                  unique_ptr<ifstream> scheduler_include = openArchStream("old-scheduler.cpp");
                  if (scheduler_include) {
                      streamCopyUntilEnd(*scheduler_include, *dst.get());
                  } else {
                      throw("ERROR : can't include \"old-scheduler.cpp\", file not found>\n");
                  }
              }

              streamCopyUntil(*enrobage.get(), *dst.get(), "<<includeclass>>");
              printfloatdef(*dst.get());
              this->_instructionCompiler->getClass()->println(0, *dst.get());
              streamCopyUntilEnd(*enrobage.get(), *dst.get());

          } else {
              printfloatdef(*dst.get());
              this->_instructionCompiler->getClass()->println(0, *dst.get());
          }

          /****************************************************************
           9 - generate the task graph file in dot format
           *****************************************************************/

          if (global::config().gGraphSwitch) {
              ofstream dotfile(subst("$0.dot", global::config().makeDrawPath()).c_str());
              this->_instructionCompiler->getClass()->printGraphDotFormat(dotfile);
          }

          if (global::config().gOutputFile == "") {
              cout << dynamic_cast<ostringstream*>(dst.get())->str();
          }
      }

      void compile(Tree signals, int numInputs, int numOutputs)
      override
      {
          #ifndef OCPP_BUILD
              throw faustexception("ERROR : -lang ocpp not supported since old CPP backend is not built\n");
          #endif

          if (global::config().gSchedulerSwitch) {
              this->_instructionCompiler = new SchedulerCompiler(global::config().gClassName, global::config().gSuperClassName, numInputs, numOutputs);
          } else if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new VectorCompiler(global::config().gClassName, global::config().gSuperClassName, numInputs, numOutputs);
          } else {
              this->_instructionCompiler = new ScalarCompiler(global::config().gClassName, global::config().gSuperClassName, numInputs, numOutputs);
          }

          if (global::config().gPrintXMLSwitch || global::config().gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());
          this->_instructionCompiler->compileMultiSignal(signals);
      }

      const char* const& targetString() override  { return TargetString; }

      using Common::printXML;

      void
      printXML()
      override
      {
          this->printXML(
              this->_instructionCompiler->getDescription(),
              this->_instructionCompiler->getClass()->inputs(),
              this->_instructionCompiler->getClass()->outputs()
          );
      }

      virtual
      void
      printGraphDotFormat(
        std::ofstream&  dotfile
      )
      override
      {
          this->_instructionCompiler->getClass()->printGraphDotFormat(dotfile);
      }

    };

  }
}

#endif
