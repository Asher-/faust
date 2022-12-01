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

#ifndef __FAUST__COMPILER__PARSER__LOCATION__PRINT__TREE__HH__
#define __FAUST__COMPILER__PARSER__LOCATION__PRINT__TREE__HH__

#include <iostream>
#include <string>

#include "compiler/parser/location/print/prefix.hh"
#include "compiler/parser/location/position.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Location {
        struct Implementation;
        namespace Print {
          
          namespace Helper {
            
            template
            <
              typename Location,
              /* Tree holds the prefix object; Helper::Tree keeps references. */
              typename PrefixVarType   = ::Faust::Compiler::Parser::Location::Print::Prefix&
            >
            struct Tree
            {
              /********** Types **********/

              using Position = ::Faust::Compiler::Parser::Location::Position;
              using Prefix = std::conditional_t
              <
                std::is_reference_v<PrefixVarType>,
                std::remove_reference_t<PrefixVarType>,
                PrefixVarType
              >;

              /********** Constants **********/
              
              static constexpr const char LeafString[] = "-- ";
              static constexpr const std::string_view Leaf{LeafString};

              /********** Constructors **********/

              template
              <
                typename EnableTemplateResolution = Tree,
                typename  = typename std::enable_if_t
                            <
                              ! std::is_reference_v<PrefixVarType>,
                              EnableTemplateResolution
                            >
              >
              Tree(
                const Location& location
              )
              :
                _location( location ),
                _lastPrintedPosition( Position( -1, -1 ) ),
                _prefix()
              {}

              Tree(
                const Location&  location,
                const Position&  last_printed_position,
                Prefix&          prefix
              )
              :
                _location( location ),
                _lastPrintedPosition( last_printed_position ),
                _prefix( prefix )
              {}

              Tree(
                const Location&  location,
                const Position&  last_printed_position,
                Prefix&          prefix,
                const bool&      nested
              )
              :
                _location( location ),
                _lastPrintedPosition( last_printed_position ),
                _prefix( prefix ),
                _finalNested( nested )
              {}

              template
              <
                typename EnableTemplateResolution = Tree,
                typename  = typename std::enable_if_t
                            <
                              ! std::is_reference_v<PrefixVarType>,
                              EnableTemplateResolution
                            >
              >
              Tree(
                const Location&     location,
                const Position&     last_printed_position,
                const Prefix&       prefix
              )
              :
                _location( location ),
                _lastPrintedPosition( last_printed_position ),
                _prefix( prefix )
              {}

              /********** Copy Constructors **********/

              Tree
              ( const Tree& copy_instance )
              :
                _location( copy_instance.location() ),
                _lastPrintedPosition( copy_instance.lastPrintedPosition() )
              {
              }

              /********** Assignment **********/
              
              Tree&
              operator =(
                const Tree& rhs
              )
              {
                _location = rhs.location();
                return *this;
              }

              /********** ostream **********/

              template <typename CharType>
              std::basic_ostream<CharType>&
              print(
                std::basic_ostream<CharType>& stack
              )
              {
                std::size_t initial_prefix_spacing = _location.begin().digits() ;
                if ( ! _prefix.size() ) {
                  stack << "[---------- " << _location.streamName() << " ----------]" << std::endl;
                }
                else {
                  stack << _prefix << Leaf;
                  initial_prefix_spacing = Leaf.size();
                }
                std::string position_string{ ( _location.begin() != _lastPrintedPosition )
                                             ? static_cast<std::string>((_lastPrintedPosition = _location.begin())) + " "
                                             : "" };
                stack << position_string << _location.name() << std::endl;
                _prefix.emplace_back( initial_prefix_spacing );
                if ( _location.parts().size() ) {
                  auto iterator_last_part = _location.parts().end() - 1;
                  for ( auto iterator = _location.parts().begin() ; iterator < iterator_last_part ; ++iterator ) {
                    const Location& location = *iterator;
                    Helper::Tree<Location> tree( location, _lastPrintedPosition, _prefix, false );
                    stack << tree;
                  }
                  Helper::Tree<Location> tree( *iterator_last_part, _lastPrintedPosition, _prefix, false );
                  stack << tree;
                }
                if ( ! _finalNested ) {
                  _prefix.closeLast();
                  auto& close_cell = _prefix.emplace_back( initial_prefix_spacing );
                  close_cell.value() = "/";
                  close_cell.setClosing();
                  stack << _prefix << std::endl;
                  _prefix.shrink();
                }
                else {
                  _prefix.last().value() = "/";
                  _prefix.last().setClosing();
                  stack << _prefix << std::endl;
                }

                return stack;
              }

              template <typename CharType>
              friend
              std::basic_ostream<CharType>&
              operator <<(
                std::basic_ostream<CharType>& stack,
                Tree& tree
              )
              {
                return tree.print( stack );
              }

              /********** Accessors **********/

              const Location& location() const { return _location; }

              const bool& finalNested() const { return _finalNested; }

              /********** Variables **********/
              
              const Location&     _location;
              Position            _lastPrintedPosition;
              PrefixVarType       _prefix;
              bool                _finalNested = true;

            };
          }
          
          template <typename Location>
          struct Tree
          :
            Helper::Tree<Location, ::Faust::Compiler::Parser::Location::Print::Prefix>
          {
            using Helper = Helper::Tree<Location, ::Faust::Compiler::Parser::Location::Print::Prefix>;
            using Helper::Helper;
            using Helper::operator=;
          };
          
        }
      }
    }
  }
}

#endif
