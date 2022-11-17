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

#ifndef __FAUST__PRIMITIVE__SYMBOL__INTERNAL__TABLE__HH__
#define __FAUST__PRIMITIVE__SYMBOL__INTERNAL__TABLE__HH__

#include "faust/primitive/math/primes.hh"

#include "faust/primitive/symbol/hash_type.hh"

#include "faust/primitive/symbol/abstract/table.hh"
#include "faust/primitive/symbol/internal/implementation.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Internal {
        
        template
        <
          auto... SymbolNames
        >
        struct Table
        :
          ::Faust::Primitive::Symbol::Abstract::Table
        {
          /********** Types **********/
          
          using AbstractTable = ::Faust::Primitive::Symbol::Abstract::Table;
          
          template <auto Name> using Symbol = ::Faust::Primitive::Symbol::Internal::Implementation<Name>;
          using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;

          using Bucket = ::Faust::Primitive::Symbol::Bucket;
          using HashType = ::Faust::Primitive::Symbol::HashType;

          /********** Constants **********/

          ///< Size of the hash table (a prime number is recommended to minimize collisions)
          static constexpr const std::size_t& Size = ::Faust::Primitive::Math::firstPrime( sizeof...(SymbolNames) );
          
          /********** Types **********/

          using BucketsType = std::array<Bucket, Size>;

          /********** Constructors **********/
          
          Table
          ()
          {
            ( _buckets[ Symbol<SymbolNames>::Hash % Size ].template insert<Symbol<SymbolNames>>(), ... );
          }

          /********** Accessors **********/
          
          using AbstractTable::symbol;
          
          virtual
          AbstractSymbol*
          symbol(
            const HashType& hash,
            bool throw_if_not_found = true
          )
          override
          {
            const unsigned int Index = hash % Size;
            Bucket& bucket = _buckets[ Index ];
            AbstractSymbol* symbol = bucket.find( hash, throw_if_not_found );
            return symbol;
          }
          
          /********** Variables **********/

          BucketsType _buckets;

        };

      };
    };
  };
};

#endif

