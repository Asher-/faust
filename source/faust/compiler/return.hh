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

#ifndef __FAUST_COMPILE_RETURN_HH__
#define __FAUST_COMPILE_RETURN_HH__

#include "instructions_compiler.hh"
#include "compile.hh"
#include "code_container.hh"

namespace Faust {
  namespace Compiler {

    struct Return
    {
      Return () = default;
      Return ( InstructionsCompiler* new_comp, CodeContainer* container )
      : new_comp(new_comp), container(container) {}
      InstructionsCompiler* new_comp  = nullptr;
      #ifdef OCPP_BUILD
      class Compiler* old_comp = nullptr;
      #endif
      CodeContainer*        container = nullptr;
    };

  }
}

#endif
