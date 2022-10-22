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

#ifndef __FAUST_COMPILE_COMMON_HH__
#define __FAUST_COMPILE_COMMON_HH__

#include "faust.hh"
#include "faust/architectures.hh"
#include "faust/compiler/return.hh"

namespace Faust {
  namespace Compiler {

    struct Common
    {
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs) = 0;
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out) = 0;
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out, const std::string& ) = 0;
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, bool generate) = 0;
      static void injectCode(::Faust::Compiler::Return compiler_return, unique_ptr<ifstream>& injcode, unique_ptr<ifstream>& enrobage, ostream& dst)
      {
          /****************************************************************
           1.7 - Inject code instead of compile
           *****************************************************************/

          // Check if this is a code injection
          if (gGlobal->gInjectFlag) {
              if (gGlobal->gArchFile == "") {
                  stringstream error;
                  error << "ERROR : no architecture file specified to inject \"" << gGlobal->gInjectFile << "\"" << endl;
                  throw faustexception(error.str());
              } else {
                  streamCopyUntil(*enrobage.get(), dst, "<<includeIntrinsic>>");
                  compiler_return.container->printMacros(dst, 0);
                  streamCopyUntil(*enrobage.get(), dst, "<<includeclass>>");
                  streamCopyUntilEnd(*injcode.get(), dst);
                  streamCopyUntilEnd(*enrobage.get(), dst);
              }
              throw faustexception("");
          }
      }
    };

  }
}

#endif
