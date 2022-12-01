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

#ifndef __FAUST__COMPILER__PARSER__LOCATION__PRINT__PREFIX__HH__
#define __FAUST__COMPILER__PARSER__LOCATION__PRINT__PREFIX__HH__

#include <iostream>
#include <string>
#include <vector>

#include "compiler/parser/location/print/cell.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Location {
        namespace Print {

          struct Prefix
          {
            /********** Types **********/

            using Cell = ::Faust::Compiler::Parser::Location::Print::Cell;
            using Cells = std::vector<Cell>;
            using ColumnCount = typename Cell::CountingType;

            /********** Constructors **********/

            Prefix()
            :
              _cells( {} )
            {}

            /********** Copy Constructors **********/

            Prefix
            ( const Prefix& copy_instance )
            :
              _cells( copy_instance.cells() )
            {
            }

            /********** Assignment **********/
            
            Prefix&
            operator =(
              const Prefix& rhs
            )
            {
              _cells = rhs.cells();
              return *this;
            }

            /********** Cells **********/

            template <typename...Args>
            Cell&
            emplace_back(
              Args&&... args
            )
            {
              return _cells.emplace_back( std::forward<Args>(args)... );
            }

            Cell&
            operator[](
              const std::size_t& index
            )
            {
              return _cells.at( index );
            }

            const Cell&
            operator[](
              const std::size_t& index
            )
            const
            {
              return _cells.at( index );
            }

            void
            pop_back()
            {
              return _cells.pop_back();
            }

            Cell&
            last()
            {
              auto last_cell_iterator = _cells.end() - 1 - _closingOffset;
              return *last_cell_iterator;
            }

            /********** ostream **********/

            template <typename CharType>
            std::basic_ostream<CharType>&
            print(
              std::basic_ostream<CharType>& ostr
            )
            {
              for ( Cell& this_cell : _cells ) {
                ostr << this_cell;
              }
              return ostr;
            }

            template <typename CharType>
            friend
            std::basic_ostream<CharType>&
            operator <<(
              std::basic_ostream<CharType>& stack,
              Prefix& prefix
            )
            {
              return prefix.print( stack );
            }

            Prefix&
            close()
            {
              for ( auto iterator = _cells.begin() ; iterator < _cells.end() ; ++iterator ) {
                Cell& this_cell = *iterator;
                this_cell.close();
              }
              return *this;
            }
            
            Prefix&
            closeLast()
            {
              last().close();
              ++_closingOffset;
              return *this;
            }
            
            Prefix&
            setLastToClosing()
            {
              last().setClosing();
              ++_closingOffset;
              return *this;
            }
            
            Prefix&
            shrink()
            {
              std::size_t new_size = _cells.size() - _closingOffset - 1;
              _cells.resize( new_size );
              _closingOffset = 0;
              return *this;
            }

            /********** Accessors **********/
            
            Cells& cells() { return _cells; };
            const Cells& cells() const { return _cells; };

            const std::size_t size() const { return _cells.size(); };

            ColumnCount& closingOffset() { return _closingOffset; };
            const ColumnCount& closingOffset() const { return _closingOffset; };

            /********** Variables **********/

            std::vector<Cell> _cells;

            /* Number of cells to be popped after printing closing line. */
            ColumnCount _closingOffset = 0;

          };

        }
      }
    }
  }
}

#endif
