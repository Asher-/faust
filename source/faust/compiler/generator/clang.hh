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

#ifndef __FAUST_COMPILE_CLANG_HH__
#define __FAUST_COMPILE_CLANG_HH__

#include "faust/api/faust.hh"
#include "faust/compiler/generator/common.hh"
#include "target/language/clang/clang_code_container.hh"

namespace Faust {
  namespace Compiler {

    struct Clang : public Common
    {
      static constexpr const char* TargetString = "Clang-LLVM";
      static constexpr const char* LanguageString = "cllvm";

      void compile(Tree signals, int numInputs, int numOutputs)
      override
      {
          #ifndef CLANG_BUILD
              throw faustexception("ERROR : -lang cllcm not supported since LLVM backend is not built\n");
          #endif

          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          global::config().gFAUSTFLOAT2Internal = true;

          this->_codeContainer = ClangCodeContainer::createContainer(global::config().gClassName, numInputs, numOutputs);

          // To trigger 'sig.dot' generation
          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler(this->_codeContainer);
          }
          this->_instructionCompiler->prepare(signals);
      }

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
