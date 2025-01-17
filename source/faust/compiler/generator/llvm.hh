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

#ifndef __FAUST_COMPILE_LLVM_HH__
#define __FAUST_COMPILE_LLVM_HH__

#include "faust/api/faust.hh"
#include "faust/compiler/generator/common.hh"

#include "target/language/llvm/llvm_code_container.hh"
#include "target/language/clang/clang_code_container.hh"

namespace Faust {
  namespace Compiler {

    struct LLVM : public Common
    {
      static constexpr const char* TargetString = "LLVM IR";
      static constexpr const char* LanguageString = "llvm";

      void compile(Tree signals, int numInputs, int numOutputs, bool generate)
      override
      {
          #ifndef LLVM_BUILD
              throw faustexception("ERROR : -lang llvm not supported since LLVM backend is not built\n");
          #endif
          this->_codeContainer = LLVMCodeContainer::createContainer(global::config().gClassName, numInputs, numOutputs);

          // libc functions will be found by the LLVM linker, but not user defined ones...
          global::config().gAllowForeignFunction = false;
          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          global::config().gFAUSTFLOAT2Internal = true;
          global::config().gUseDefaultSound     = false;

          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler(this->_codeContainer);
          }

          if (global::config().gPrintXMLSwitch || global::config().gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());

          if (generate) {
              this->_instructionCompiler->compileMultiSignal(signals);
          } else {
              // To trigger 'sig.dot' generation
              this->_instructionCompiler->prepare(signals);
          }
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "bool generate required."; };

      const char* const& targetString() override  { return TargetString; }

      virtual void printVersionTargetDetail()
      {
          std::cout << "Build with LLVM version " << LLVM_VERSION << "\n";
      }

    };

  }
}

#endif
