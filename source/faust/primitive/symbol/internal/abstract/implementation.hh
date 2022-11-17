
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

#ifndef __FAUST__PRIMITIVE__INTERNAL__ABSTRACT__SYMBOL__HH__
#define __FAUST__PRIMITIVE__INTERNAL__ABSTRACT__SYMBOL__HH__

#include <map>
#include <string>
#include <array>

#include "faust/primitive/symbol/abstract/implementation.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Internal {
        namespace Abstract {

          //--------------------------------SYMBOL-------------------------------------

          /**
           * Symbols are unique objects with a name stored in a hash table.
           */
          struct Implementation
          :
            ::Faust::Primitive::Symbol::Abstract::Implementation
          {
            /********** Types **********/
            
            using AbstractImplementation = ::Faust::Primitive::Symbol::Abstract::Implementation;
            using AbstractSymbol = AbstractImplementation;
            using HashType = typename AbstractImplementation::HashType;

            /********** Accessors **********/
            
            virtual constexpr const std::string_view& name() const = 0;
            virtual constexpr const HashType& hash() const = 0;

          };

        }
      }
    }
  }
}

#endif

