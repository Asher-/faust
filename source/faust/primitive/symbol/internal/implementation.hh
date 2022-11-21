
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

#ifndef __FAUST__PRIMITIVE__SYMBOL__INTERNAL__IMPLEMENTATION__HH__
#define __FAUST__PRIMITIVE__SYMBOL__INTERNAL__IMPLEMENTATION__HH__

#include <map>
#include <string>
#include <array>
#include <string_view>

#include "faust/primitive/symbol/abstract/implementation.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Internal {
      
        //--------------------------------SYMBOL-------------------------------------

        /**
         * Symbols are unique objects with a name stored in a hash table.
         */
        template
        <
          auto  NameValue
        >
        struct Implementation
        :
          ::Faust::Primitive::Symbol::Abstract::Implementation
        {
          /********** Types **********/
          
          using AbstractImplementation = ::Faust::Primitive::Symbol::Abstract::Implementation;
          using AbstractSymbol = AbstractImplementation;
          using HashType = typename AbstractImplementation::HashType;

          /********** Static **********/
          
          static constexpr std::string_view Name{NameValue};
          
          /**
           * Compute the 32-bits hash key of string \p str.
           * \param str the string
           * \return a 32-bits hash key
           */
          ///< Hash key computed from the name and used to determine the hash table entry
          static constexpr const HashType Hash = ::Faust::Primitive::Symbol::hash( Name );

          /********** Constructors **********/

          Implementation
          ()
          :
            /* Decided to store duplicate as std::string for consistent non-constexpr access. */
            AbstractImplementation( Name.data() )
          {}

          /********** Accessors **********/
          
          const HashType&
          hash()
          const override
          {
            return Implementation::Hash;
          };

          /********** Comparison **********/
          
          template <auto RHSNameValue>
          bool
          operator ==( const Implementation<RHSNameValue>& rhs )
          const
          {
            return Name == Implementation<RHSNameValue>::Name;
          }
          
          virtual
          bool
          operator ==( const std::string& name )
          const
          override
          {
            return Name == name;
          }

          virtual
          bool
          operator ==( const std::string_view& name )
          const
          override
          {
            return Name == name;
          }

          bool
          operator ==( const HashType& hash )
          const
          override
          {
            return Hash == hash;
          }

          template
          <
            typename RHS
          >
          bool
          operator !=( const RHS& rhs )
          const
          {
            return ! operator==( rhs );
          }

          /********** Variables **********/
          
          unsigned int _prefixCount = 0;

        };

      }
    }
  }
}

#endif

