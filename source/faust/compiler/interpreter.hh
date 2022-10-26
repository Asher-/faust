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

#ifndef __FAUST_COMPILE_INTERPRETER_HH__
#define __FAUST_COMPILE_INTERPRETER_HH__

#include "faust.hh"
#include "faust/compiler/common.hh"

#include "interpreter_code_container.cpp"

namespace Faust {
  namespace Compiler {


    struct Interpreter : public Common
    {
      static constexpr const char* TargetString = "Interpreter";
      ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs)
      override
      {
          #ifndef INTERP_BUILD
              throw faustexception("ERROR : -lang interp not supported since Interpreter backend is not built\n");
          #endif
          static ::Faust::Compiler::Return compiler_return;

          if (gGlobal->gFloatSize == 1) {
            compiler_return.container = InterpreterCodeContainer<float>::createContainer(gGlobal->gClassName, numInputs, numOutputs);
          } else if (gGlobal->gFloatSize == 2) {
            compiler_return.container = InterpreterCodeContainer<double>::createContainer(gGlobal->gClassName, numInputs, numOutputs);
          } else {
              throw faustexception("ERROR : quad format not supported in Interp\n");
          }
          gGlobal->gAllowForeignFunction = false;  // No foreign functions
          gGlobal->gAllowForeignConstant = false;  // No foreign constant
          gGlobal->gAllowForeignVar      = false;  // No foreign variable
          // gGlobal->gComputeIOTA       = true;   // Ensure IOTA base fixed delays are computed once

          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          gGlobal->gFAUSTFLOAT2Internal = true;
          gGlobal->gNeedManualPow       = false;  // Standard pow function will be used in pow(x,y) when Y in an integer
          gGlobal->gRemoveVarAddress    = true;   // To be used in -vec mode

          if (gGlobal->gVectorSwitch) {
              compiler_return.new_comp = new DAGInstructionsCompiler(compiler_return.container);
          } else {
              compiler_return.new_comp = new InterpreterInstructionsCompiler(compiler_return.container);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) compiler_return.new_comp->setDescription(new Description());
          compiler_return.new_comp->compileMultiSignal(signals);
          return compiler_return;
      }

      const char* const& targetString()
      override
      {
          return TargetString;
      }

    };

  }
}

#endif
