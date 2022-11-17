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

#ifndef __FAUST__PRIMITIVE__SYMBOLS__COMBINED__HH__
#define __FAUST__PRIMITIVE__SYMBOLS__COMBINED__HH__

#include "faust/primitive/symbol/combined/table.hh"

#include "faust/primitive/symbols/internal.hh"
#include "faust/primitive/symbols/runtime.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbols {
    
        namespace Name = ::Faust::Primitive::Symbol::Internal::Name;

        using Combined = ::Faust::Primitive::Symbol::Combined::Table;
        
        Combined combined(
          internal,
          runtime
        );

    };
  };
};

#endif

