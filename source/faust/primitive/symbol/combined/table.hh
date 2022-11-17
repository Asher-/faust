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

#ifndef __FAUST__PRIMITIVE__SYMBOL__COMBINED__TABLE__HH__
#define __FAUST__PRIMITIVE__SYMBOL__COMBINED__TABLE__HH__

#include "faust/primitive/math/primes.hh"
#include "faust/primitive/symbol/abstract/table.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Combined {

        struct Table
        :
          ::Faust::Primitive::Symbol::Abstract::Table
        {
          /********** Types **********/
          
          using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;
          using AbstractTable = ::Faust::Primitive::Symbol::Abstract::Table;

          using Bucket = ::Faust::Primitive::Symbol::Bucket;
          using HashType = ::Faust::Primitive::Symbol::HashType;
          using RuntimeTables = std::vector<AbstractTable*>;

          /********** Constructors **********/
          
          Table
          () = default;
          
          template
          <
            typename... Tables
          >
          Table
          ( Tables&&... runtime_tables )
          :
            _runtimeTables( { & runtime_tables... } )
          {}

          template
          <
            typename... Tables
          >
          Table
          ( Tables*&&... runtime_tables )
          :
            _runtimeTables( { runtime_tables... } )
          {}


          /********** Accessors **********/
          
          using AbstractTable::symbol;
          
          AbstractSymbol*
          symbol(
            const HashType& hash,
            bool throw_if_not_found = true
          )
          override
          {
            AbstractSymbol* symbol = nullptr;
            std::find_if(
              _runtimeTables.begin(),
              _runtimeTables.end(),
              [&symbol, &hash]( AbstractTable* this_table ){
                symbol = this_table->symbol( hash, false );
                return !! symbol;
              }
            );
            return symbol;
          }
          
          AbstractTable* const&
          operator[]( const std::size_t& index )
          {
            return _runtimeTables[index];
          }

          /********** Variables **********/
          
          RuntimeTables _runtimeTables;
          
          
        };
          
      };
    };
  };
};

#endif

