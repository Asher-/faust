
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

#ifndef __FAUST__PRIMITIVE__ABSTRACT__SYMBOL__HH__
#define __FAUST__PRIMITIVE__ABSTRACT__SYMBOL__HH__

#include <map>
#include <string>
#include <array>

#include "faust/primitive/symbol/hash_type.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Abstract {

        //--------------------------------SYMBOL-------------------------------------

        /**
         * Symbols are unique objects with a name stored in a hash table.
         */
        struct Implementation
        {
          /********** Types **********/
          
          using AbstractSymbol = Implementation;
          using HashType = ::Faust::Primitive::Symbol::HashType;

          /********** Constructors **********/

          Implementation
          () = default;

          /********** Destructor **********/
          
          virtual
          ~Implementation
          () = default;

          /********** Static **********/

          /********** Comparison **********/
          
          virtual
          bool
          operator ==( const AbstractSymbol* rhs )
          const
          {
            return this->name() == rhs->name();
          }

          virtual
          bool
          operator ==( const AbstractSymbol& rhs )
          const
          {
            return this->operator==( & rhs );
          }

          virtual
          bool
          operator ==( const std::string& name )
          const
          {
            return this->name() == name;
          }

          virtual
          bool
          operator ==( const std::string_view& name )
          const
          {
            return this->name() == name;
          }

          virtual
          bool
          operator ==( const HashType& hash )
          const
          {
            return this->hash() == hash;
          }

          virtual
          bool
          operator !=( const AbstractSymbol*& rhs )
          const
          {
            return ! operator==( rhs );
          }
          
          virtual
          bool
          operator !=( const std::string& name )
          const
          {
            return ! operator==( name );
          }

          virtual
          bool
          operator !=( const std::string_view& name )
          const
          {
            return ! operator==( name );
          }

          virtual
          bool
          operator !=( const HashType& hash )
          const
          {
            return ! operator==( hash );
          }

          /********** Accessors **********/
          
          virtual const std::string_view& name() const = 0;
          virtual const HashType& hash() const = 0;
          virtual const unsigned int& prefixCount() const = 0;
//          virtual AbstractSymbol* prefix( const std::string& ) const = 0;

          /********** Variables **********/
          
          ///< Field for user to store additional custom data
          void* _data = nullptr;
          
          unsigned int _prefixCount = 0;

        };

      }
    }
  }
}

#endif

