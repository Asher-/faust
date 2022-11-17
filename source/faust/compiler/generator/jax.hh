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

#ifndef __FAUST_COMPILE_JAX_HH__
#define __FAUST_COMPILE_JAX_HH__

#include "faust.hh"
#include "faust/compiler/generator/common.hh"
#include "target/language/jax/instruction_compiler_jax.hh"

#include "jax_code_container.hh"

#include "faust/primitive/math.hh"

namespace Faust {
  namespace Compiler {

    struct JAX : public Common
    {
      static constexpr const char* TargetString = "JAX";
      static constexpr const char* LanguageString = "jax";

      void compile(Tree signals, int numInputs, int numOutputs, ostream* out)
      override
      {
          #ifndef JAX_BUILD
              throw faustexception("ERROR : -lang jax not supported since JAX backend is not built\n");
          #endif
          global::config().gAllowForeignFunction = true;  // foreign functions are supported (we use jax.random.PRNG for example)
          ::Faust::Primitive::Math::needManualPow = false;
          global::config().gFAUSTFLOAT2Internal  = true;
          this->_codeContainer = JAXCodeContainer::createContainer(global::config().gClassName, numInputs, numOutputs, out);

          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompilerJAX(this->_codeContainer);
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
