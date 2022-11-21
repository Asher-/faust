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

#ifndef __FAUST_COMPILE_JULIA_HH__
#define __FAUST_COMPILE_JULIA_HH__

#include "faust/api/faust.hh"
#include "faust/compiler/generator/common.hh"
#include "compiler/instruction_compiler/instruction_compiler1.hh"

#include "target/language/julia/julia_code_container.hh"

namespace Faust {
  namespace Compiler {

    struct Julia : public Common
    {
      static constexpr const char* TargetString = "Julia";
      static constexpr const char* LanguageString = "julia";

      void compile(Tree signals, int numInputs, int numOutputs, ostream* out)
      override
      {
        #ifndef JULIA_BUILD
          throw faustexception("ERROR : -lang julia not supported since Julia backend is not built\n");
        #endif
          global::config().gAllowForeignFunction = false;  // No foreign functions
          this->_codeContainer = JuliaCodeContainer::createContainer(global::config().gClassName, numInputs, numOutputs, out);

          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler1(this->_codeContainer);
          }

          if (global::config().gPrintXMLSwitch || global::config().gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());
          this->_instructionCompiler->compileMultiSignal(signals);
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "std::ostream required."; };

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
