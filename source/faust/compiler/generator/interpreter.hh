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

#ifndef __FAUST_COMPILE_INTERPRETER_HH__
#define __FAUST_COMPILE_INTERPRETER_HH__

#include "faust.hh"
#include "faust/compiler/generator/common.hh"

#include "interpreter_code_container.cpp"

#include "faust/primitive/math.hh"

namespace Faust {
  namespace Compiler {


    struct Interpreter : public Common
    {
      static constexpr const char* TargetString = "Interpreter";
      static constexpr const char* LanguageString = "interp";

      void compile(Tree signals, int numInputs, int numOutputs)
      override
      {
          #ifndef INTERP_BUILD
              throw faustexception("ERROR : -lang interp not supported since Interpreter backend is not built\n");
          #endif

          if (::Faust::Primitive::Math::floatSize == 1) {
            this->_codeContainer = InterpreterCodeContainer<float>::createContainer(global::config().gClassName, numInputs, numOutputs);
          } else if (::Faust::Primitive::Math::floatSize == 2) {
            this->_codeContainer = InterpreterCodeContainer<double>::createContainer(global::config().gClassName, numInputs, numOutputs);
          } else {
              throw faustexception("ERROR : quad format not supported in Interp\n");
          }
          global::config().gAllowForeignFunction = false;  // No foreign functions
          global::config().gAllowForeignConstant = false;  // No foreign constant
          global::config().gAllowForeignVar      = false;  // No foreign variable
          // global::config().gComputeIOTA       = true;   // Ensure IOTA base fixed delays are computed once

          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          global::config().gFAUSTFLOAT2Internal = true;
          ::Faust::Primitive::Math::needManualPow = false;  // Standard pow function will be used in pow(x,y) when Y in an integer
          global::config().gRemoveVarAddress    = true;   // To be used in -vec mode

          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InterpreterInstructionsCompiler(this->_codeContainer);
          }

          if (global::config().gPrintXMLSwitch || global::config().gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());
          this->_instructionCompiler->compileMultiSignal(signals);
      }

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
