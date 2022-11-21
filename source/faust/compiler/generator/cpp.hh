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

#ifndef __FAUST_COMPILE_CPP_HH__
#define __FAUST_COMPILE_CPP_HH__

#include "faust/api/faust.hh"
#include "faust/compiler/generator/common.hh"

#include "target/language/cpp/code_container.hh"
#include "target/language/cpp/gpu/code_container.hh"

namespace Faust {
  namespace Compiler {

    struct CPP : public Common
    {
      static constexpr const char* TargetString = "C++";
      static constexpr const char* LanguageString = "cpp";

      void compile(Tree signals, int numInputs, int numOutputs, ostream* out)
      override
      {
          #ifndef CPP_BUILD
              throw faustexception("ERROR : -lang cpp not supported since CPP backend is not built\n");
          #endif

          this->_codeContainer = CPPCodeContainer::createContainer(
            global::config().gClassName,
            global::config().gSuperClassName,
            numInputs,
            numOutputs,
            out
          );

          this->_instructionCompiler = global::config().gVectorSwitch ?
            new DAGInstructionsCompiler(this->_codeContainer)
          : new InstructionsCompiler(this->_codeContainer);

          if ( global::config().gPrintXMLSwitch
            || global::config().gPrintDocSwitch ) {
            this->_instructionCompiler->setDescription( new Description() );
          }
          this->_instructionCompiler->compileMultiSignal(signals);
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "std::ostream required."; };

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
