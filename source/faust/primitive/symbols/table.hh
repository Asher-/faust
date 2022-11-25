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

#ifndef __FAUST__PRIMITIVE__SYMBOLS__TABLE__HH__
#define __FAUST__PRIMITIVE__SYMBOLS__TABLE__HH__

#include "faust/primitive/symbols/internal.hh"
#include "faust/primitive/symbols/runtime.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbols {

      struct Table
      :
        ::Faust::Primitive::Symbol::Abstract::Table
      {
        /********** Types **********/
        
        using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;
        using AbstractTable = ::Faust::Primitive::Symbol::Abstract::Table;

        using Bucket = ::Faust::Primitive::Symbol::Bucket;
        using HashType = ::Faust::Primitive::Symbol::HashType;

        using InternalTable = ::Faust::Primitive::Symbols::Internal;
        using RuntimeTable = ::Faust::Primitive::Symbols::Runtime;

        /********** Constructors **********/
        
        Table
        ( InternalTable& internal_table,
          RuntimeTable& runtime_table )
        :
          _internal( internal_table ),
          _runtime( runtime_table )
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
          AbstractSymbol* symbol = _internal.symbol( hash, false );
          if ( ! symbol )
            symbol = _runtime.symbol( hash, throw_if_not_found );
          return symbol;
        }

        AbstractSymbol*
        insert(
          const std::string& name,
          bool throw_if_exists = true
        )
        {
          const HashType hash = ::Faust::Primitive::Symbol::hash( name );
          AbstractSymbol* symbol = _internal.symbol( hash, false );
          if ( ! symbol )
            symbol = _runtime.insert( name, hash, throw_if_exists );
          else if ( throw_if_exists ) {
            std::stringstream error;
            error << "Symbol :" << symbol->name() << " already in internal table!";
            throw error;
          }
          return symbol;
        }

        InternalTable&
        internal()
        {
          return _internal;
        }

        const InternalTable&
        internal()
        const
        {
          return _internal;
        }

        RuntimeTable&
        runtime()
        {
          return _runtime;
        }

        const RuntimeTable&
        runtime()
        const
        {
          return _runtime;
        }

        /********** Variables **********/
        
        InternalTable& _internal;
        RuntimeTable& _runtime;
        
        
      };

    };
  };
};

#endif

