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

#ifndef __FAUST_COMPILE_OCPP_HH__
#define __FAUST_COMPILE_OCPP_HH__

#include "faust.hh"

#ifdef OCPP_BUILD
#include "compile_scalar.hh"
#include "compile_sched.hh"
#include "compile_vect.hh"
#endif

namespace Faust {
  namespace Compiler {

    struct OCPP
    {
      static ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs)
      {
      #ifdef OCPP_BUILD
          static ::Faust::Compiler::Return compiler_return;

          if (gGlobal->gSchedulerSwitch) {
              compiler_return.old_comp = new SchedulerCompiler(gGlobal->gClassName, gGlobal->gSuperClassName, numInputs, numOutputs);
          } else if (gGlobal->gVectorSwitch) {
              compiler_return.old_comp = new VectorCompiler(gGlobal->gClassName, gGlobal->gSuperClassName, numInputs, numOutputs);
          } else {
              compiler_return.old_comp = new ScalarCompiler(gGlobal->gClassName, gGlobal->gSuperClassName, numInputs, numOutputs);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) compiler_return.old_comp->setDescription(new Description());
          compiler_return.old_comp->compileMultiSignal(signals);
          return compiler_return;
      #else
          throw faustexception("ERROR : -lang ocpp not supported since old CPP backend is not built\n");
      #endif
      }

    };

  }
}

#endif
