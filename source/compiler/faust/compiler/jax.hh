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

#ifndef __FAUST_COMPILE_JAX_HH__
#define __FAUST_COMPILE_JAX_HH__

#include "faust.hh"
#include "faust/compiler/common.hh"

#ifdef JAX_BUILD
#include "jax_code_container.hh"
#endif

namespace Faust {
  namespace Compiler {

    struct JAX : public Common
    {
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out)
      {
      #ifdef JAX_BUILD
          gGlobal->gAllowForeignFunction = true;  // foreign functions are supported (we use jax.random.PRNG for example)
          gGlobal->gNeedManualPow        = false;
          gGlobal->gFAUSTFLOAT2Internal  = true;
          static ::Faust::Compiler::Return compiler_return;
          compiler_return.container = JAXCodeContainer::createContainer(gGlobal->gClassName, numInputs, numOutputs, out);

          if (gGlobal->gVectorSwitch) {
              compiler_return.new_comp = new DAGInstructionsCompiler(compiler_return.container);
          } else {
              compiler_return.new_comp = new InstructionsCompilerJAX(compiler_return.container);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) compiler_return.new_comp->setDescription(new Description());
          compiler_return.new_comp->compileMultiSignal(signals);
          return compiler_return;
      #else
          throw faustexception("ERROR : -lang jax not supported since JAX backend is not built\n");
      #endif
      }
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs) { return compile(signals, numInputs, numOutputs, nullptr); };
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, bool generate) { return compile(signals, numInputs, numOutputs, nullptr); };
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out, const std::string&) { return compile(signals, numInputs, numOutputs, out); };

    };

  }
}

#endif
