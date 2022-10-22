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

#ifndef __FAUST_COMPILE_LLVM_HH__
#define __FAUST_COMPILE_LLVM_HH__

#include "faust.hh"

#ifdef LLVM_BUILD
#include "clang_code_container.hh"
#include "llvm_code_container.hh"
#endif

namespace Faust {
  namespace Compiler {

    struct LLVM
    {
      static ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, bool generate)
      {
      #ifdef LLVM_BUILD
          static ::Faust::Compiler::Return compiler_return;
          compiler_return.container = LLVMCodeContainer::createContainer(gGlobal->gClassName, numInputs, numOutputs);

          // libc functions will be found by the LLVM linker, but not user defined ones...
          gGlobal->gAllowForeignFunction = false;
          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          gGlobal->gFAUSTFLOAT2Internal = true;
          gGlobal->gUseDefaultSound     = false;

          if (gGlobal->gVectorSwitch) {
              compiler_return.new_comp = new DAGInstructionsCompiler(compiler_return.container);
          } else {
              compiler_return.new_comp = new InstructionsCompiler(compiler_return.container);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) compiler_return.new_comp->setDescription(new Description());

          if (generate) {
              compiler_return.new_comp->compileMultiSignal(signals);
          } else {
              // To trigger 'sig.dot' generation
              compiler_return.new_comp->prepare(signals);
          }
          return compiler_return;
      #else
          throw faustexception("ERROR : -lang llvm not supported since LLVM backend is not built\n");
      #endif
      }

    };

  }
}

#endif
