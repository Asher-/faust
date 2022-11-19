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

#ifndef __FAUST__PRIMITIVE__SYMBOL__BUCKET__HH__
#define __FAUST__PRIMITIVE__SYMBOL__BUCKET__HH__

#include <sstream>

#include "faust/primitive/symbol/abstract/implementation.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
    
      struct Bucket
      {
        /********** Types **********/

        using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;
        using HashType = typename AbstractSymbol::HashType;

        /********** Constructors **********/
        
        Bucket
        ()
        = default;
        
        Bucket
        ( AbstractSymbol* const& symbol )
        :
          _symbol( symbol )
        {}

        /********** Destructor **********/
        
        ~Bucket
        ()
        {
          if ( _next )
            delete _next;
          if ( _symbol )
            delete _symbol;
        }

        /********** Accessors **********/
        
        AbstractSymbol*
        find(
          const std::string& name,
          bool throw_if_not_found = true
        ) {
          const HashType hash = ::Faust::Primitive::Symbol::hash( name );
          AbstractSymbol* symbol = find( hash, false );
          if ( ! symbol && throw_if_not_found ) {
            std::stringstream error;
            error << "Symbol not found :" << name << ". Is it defined in ::Faust::Primitive::Symbols?";
            throw error;
          }
          return symbol;
        }

        const AbstractSymbol*
        find(
          const std::string& name,
          bool throw_if_not_found = true
        )
        const
        {
          const HashType hash = ::Faust::Primitive::Symbol::hash( name );
          const AbstractSymbol* symbol = find( hash, false );
          if ( ! symbol && throw_if_not_found ) {
            std::stringstream error;
            error << "Symbol not found :" << name << ". Is it defined in ::Faust::Primitive::Symbols?";
            throw error;
          }
          return symbol;
        }

        AbstractSymbol*
        find(
          const HashType& hash,
          bool throw_if_not_found = true
        ) {
          Bucket* this_bucket = this;
          if ( this_bucket->symbol() ) do {
            if ( this_bucket->symbol()->hash() == hash )
              return this_bucket->_symbol;
          } while ((this_bucket = this_bucket->_next));
          if ( throw_if_not_found ) {
            std::stringstream error;
            error << "Symbol hash not found #" << hash << ". Is it defined in ::Faust::Primitive::Symbols?";
            throw error;
          }
          return nullptr;
        }

        const AbstractSymbol* const
        find(
          const HashType& hash,
          bool throw_if_not_found = true
        )
        const
        {
          Bucket* non_const_this = const_cast<Bucket*>(this);
          AbstractSymbol* symbol = non_const_this->find( hash, throw_if_not_found );
          return const_cast<const AbstractSymbol* const&>( symbol );
        }

        template <typename InternalSymbolType>
        AbstractSymbol*
        insert()
        {
          if ( ! _symbol ) {
            /* Bucket is empty - insert symbol. */
            _symbol = new InternalSymbolType();
            return _symbol;
          }
          else {
            /* Look to see if symbol already exists. */
            Bucket* this_bucket = this;
            while (this_bucket->_next && (this_bucket = this_bucket->_next)) {
              if ( this_bucket->symbol()->name() == InternalSymbolType::Name ) {
                return this_bucket->symbol();
              }
            };
            /* Create new symbol at end of bucket's linked list. */
            Bucket* new_bucket = this_bucket->_next = new Bucket( new InternalSymbolType() );
            return new_bucket->_symbol;
          }
        }

        template <typename RuntimeSymbolType>
        AbstractSymbol*
        insert(
          const std::string& name,
          const HashType& hash,
          bool  throw_if_exists = true
        )
        {
          if ( ! _symbol ) {
            /* Bucket is empty - insert symbol. */
            _symbol = new RuntimeSymbolType( name, hash );
            return _symbol;
          }
          else {
            /* Look to see if symbol already exists. */
            Bucket* this_bucket = this;
            do {
              if ( this_bucket->symbol()->name() == name ) {
                if ( throw_if_exists ) {
                  std::stringstream error;
                  error << "Symbol :" << name << " already in runtime table!";
                  throw error;
                }
                return this_bucket->symbol();
              }
            } while (this_bucket->_next && (this_bucket = this_bucket->_next));
            /* Create new symbol at end of bucket's linked list. */
            Bucket* new_bucket = this_bucket->_next = new Bucket( new RuntimeSymbolType( name, hash ) );
            return new_bucket->_symbol;
          }
        }

        template <typename RuntimeSymbolType>
        AbstractSymbol*
        insert(
          AbstractSymbol* const& symbol,
          bool  throw_if_exists = true
        ) {
          if ( ! _symbol ) {
            /* Bucket is empty - insert symbol. */
            _symbol = symbol;
            return _symbol;
          }
          else {
            /* Look to see if symbol already exists. */
            Bucket* this_bucket = _next;
            do {
              if ( this_bucket->symbol()->name() == symbol->name() ) {
                if ( throw_if_exists ) {
                  std::stringstream error;
                  error << "Symbol :" << symbol->name() << " already in runtime table!";
                  throw error;
                }
                return this_bucket->symbol();
              }
            } while (this_bucket->_next && (this_bucket = this_bucket->_next));
            /* Create new symbol at end of bucket's linked list. */
            Bucket* new_bucket = this_bucket->_next = new Bucket( symbol );
            return new_bucket->_symbol;
          }
        }

        /********** Accessors **********/
        
        AbstractSymbol*&
        symbol()
        {
          return _symbol;
        }

        const AbstractSymbol* const&
        symbol()
        const
        {
          return _symbol;
        }

        Bucket*&
        next()
        {
          return _next;
        }

        const Bucket* const&
        next()
        const
        {
          return _next;
        }

        /********** Variables **********/
        
        AbstractSymbol* _symbol = nullptr;
        Bucket* _next = nullptr;

      };

    };
  };
};

#endif

