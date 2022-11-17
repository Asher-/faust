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

#ifndef __FAUST__PRIMITIVE__SYMBOL__ABSTRACT__TABLE__HH__
#define __FAUST__PRIMITIVE__SYMBOL__ABSTRACT__TABLE__HH__

#include "faust/primitive/symbol/hash_type.hh"
#include "faust/primitive/symbol/bucket.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Abstract {

        struct Table
        {
          using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;
          using HashType = ::Faust::Primitive::Symbol::HashType;

          virtual AbstractSymbol*
          symbol(
            const HashType& hash,
            bool throw_if_not_found = true
          ) = 0;
          
          virtual
          const AbstractSymbol* const
          symbol(
            const HashType& hash,
            bool throw_if_not_found = true
          )
          const
          {
            Table* non_const_this = const_cast<Table*>( this );
            AbstractSymbol* non_const_symbol = non_const_this->symbol( hash, throw_if_not_found );
            return const_cast<const AbstractSymbol* const>( non_const_symbol );
          }

          virtual
          AbstractSymbol*
          symbol(
            const std::string& name,
            bool throw_if_not_found = true
          )
          {
            const HashType hash = ::Faust::Primitive::Symbol::hash( name );
            return symbol( hash, throw_if_not_found );
          }

          virtual
          const AbstractSymbol* const
          symbol(
            const std::string& name,
            bool throw_if_not_found = true
          )
          const
          {
            const HashType hash = ::Faust::Primitive::Symbol::hash( name );
            return symbol( hash, throw_if_not_found );
          }
        };
        
      };
    };
  };
};

#endif

