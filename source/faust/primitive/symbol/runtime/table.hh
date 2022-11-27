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

#ifndef __FAUST__PRIMITIVE__SYMBOL__RUNTIME__TABLE__HH__
#define __FAUST__PRIMITIVE__SYMBOL__RUNTIME__TABLE__HH__

#include <vector>

#include "faust/primitive/math/primes.hh"
#include "faust/primitive/symbol/abstract/table.hh"
#include "faust/primitive/symbol/runtime/implementation.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Runtime {

        struct Table
        :
          ::Faust::Primitive::Symbol::Abstract::Table
        {
          /********** Types **********/
          
          using RuntimeSymbol = ::Faust::Primitive::Symbol::Runtime::Implementation;
          using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;

          using AbstractTable = ::Faust::Primitive::Symbol::Abstract::Table;

          using Bucket = ::Faust::Primitive::Symbol::Bucket;
          using HashType = ::Faust::Primitive::Symbol::HashType;
          using Buckets = std::vector<Bucket>;

          /********** Constants **********/
          
          static constexpr const std::size_t StartingSize = ::Faust::Primitive::Math::firstPrime( 521 );
          static constexpr const auto RegrowPercent = 0.1;

          /********** Constructors **********/

          Table
          ()
          :
            _buckets( StartingSize )
          {}

          /********** Insert **********/
          
          void
          clear()
          {
            std::size_t size = _buckets.size();
            _buckets.clear();
            _buckets.resize( size );
          }

          ///< Size of the hash table (a prime number is recommended to minimize collisions)
          void
          resize()
          {
            const std::size_t new_size = ::Faust::Primitive::Math::firstPrime( 2 * _buckets.size() );
            Buckets new_buckets;
            new_buckets.resize( new_size );
            std::for_each(
              _buckets.begin(),
              _buckets.end(),
              [&new_size, &new_buckets]( Bucket& each_bucket ){
                Bucket* this_bucket = & each_bucket;
                do {
                  AbstractSymbol* this_symbol = this_bucket->symbol();
                  std::size_t new_index = this_symbol->hash() % new_size;
                  new_buckets[ new_index ].template insert<RuntimeSymbol>( this_symbol );
                } while ( ( this_bucket = this_bucket->next() ) );
              }
            );
            _buckets = std::move(new_buckets);
            _regrowAt = _buckets.size() * RegrowPercent;
          }

          virtual
          AbstractSymbol*
          insert(
            const std::string& name,
            bool throw_if_exists = true
          )
          {
            /* If we are 10% away from capacity it's a good time to grow. */
            if ( _buckets.size() - _symbolCount <= _regrowAt )
              resize();
              
            unsigned int hash = ::Faust::Primitive::Symbol::hash( name );
            return insert(
              name,
              hash,
              throw_if_exists
            );
          }

          virtual
          AbstractSymbol*
          insert(
            const std::string& name,
            const HashType& hash,
            bool throw_if_exists = true
          )
          {
            std::size_t index = hash % _buckets.size();
            
            Bucket& bucket{ _buckets[index] };

            AbstractSymbol* symbol = bucket.template insert<RuntimeSymbol>( name, hash, _symbolCount, throw_if_exists );
            return symbol;
          }

          virtual
          AbstractSymbol*
          unique( const std::string& name )
          {
            AbstractSymbol* base_symbol = insert( name, false );
            std::stringstream unique_name;
            unique_name << name << "_" << base_symbol->nextUniqueNumber();
            AbstractSymbol* symbol = insert( unique_name.str(), false );
            return symbol;
          }
          /********** Accessors **********/

          using AbstractTable::symbol;

          AbstractSymbol*
          symbol(
            const HashType& hash,
            bool throw_if_not_found = true
          )
          override
          {
            const std::size_t index = hash % _buckets.size();
            if ( _buckets.size() && ( index < _buckets.size() - 1 ) ) {
              Bucket& bucket = _buckets[ index ];
              AbstractSymbol* symbol = bucket.find( hash, throw_if_not_found );
              return symbol;
            }
            else
              return nullptr;
          }
          
          Buckets&
          buckets()
          {
            return _buckets;
          }

          /********** Variables **********/
          
          std::size_t _symbolCount = 0;
          std::size_t _regrowAt = StartingSize * RegrowPercent;
          Buckets _buckets;
                    
        };
          
      };
    };
  };
};

#endif

