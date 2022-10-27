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

#ifndef __FAUST_COMPILE_FIR_HH__
#define __FAUST_COMPILE_FIR_HH__

#include "faust.hh"
#include "faust/compiler/common.hh"

#include "fir_code_container.hh"

namespace Faust {
  namespace Compiler {

    struct FIR : public Common
    {
      static constexpr const char* TargetString = "FIR";
      void compile(Tree signals, int numInputs, int numOutputs, ostream* out)
      override
      {
          #ifndef FIR_BUILD
              throw faustexception("ERROR : -lang fir not supported since FIR backend is not built\n");
          #endif
          this->_codeContainer = FIRCodeContainer::createContainer(gGlobal->gClassName, numInputs, numOutputs, out, true);

          if (gGlobal->gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler(this->_codeContainer);
          }

          this->_instructionCompiler->compileMultiSignal(signals);
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "std::ostream required."; };

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
