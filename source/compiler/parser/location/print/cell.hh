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

#ifndef __FAUST__COMPILER__PARSER__LOCATION__PRINT__CELL__HH__
#define __FAUST__COMPILER__PARSER__LOCATION__PRINT__CELL__HH__

#include <iostream>
#include <string>

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Location {
        namespace Print {

          struct Cell
          {
            /********** Types **********/

            using CountingType = std::size_t;
            using ColumnCount = CountingType;
            using LineCount = CountingType;

            /********** Constructors **********/

            Cell()
            :
              _width( 0 ),
              _value()
            {}

            Cell(
              const ColumnCount& width
            )
            :
              _width( width ),
              _value()
            {}

            Cell(
              const ColumnCount& width,
              const std::string& value
            )
            :
              _width( width ),
              _value( value )
            {}

            /********** Copy Constructors **********/

            Cell
            ( const Cell& copy_instance )
            :
              _width( copy_instance.width() )
            {
            }

            /********** Assignment **********/
            
            Cell&
            operator =(
              const Cell& rhs
            )
            {
              _width = rhs.width();
              return *this;
            }

            /********** Comparison **********/

            const bool
            operator ==(
              const Cell& rhs
            )
            const
            {
              return _width == rhs.width();
            }

            const bool
            operator !=(
              const Cell& rhs
            )
            const
            {
              return ! operator==(rhs);
            }

            /********** ostream **********/

            template <typename CharType>
            std::basic_ostream<CharType>&
            print(
              std::basic_ostream<CharType>& ostr
            )
            {
              const char spacing_char = _closing ? '_' : ' ';
              if ( ! _value.length() )
                _value = "|";
              const std::size_t spacing = _width - _value.length();
              for ( std::size_t index = 0 ; index < spacing ; ++index ) {
                ostr << spacing_char;
              }
              ostr << _value;
              _value.clear();
              return ostr;
            }

            template <typename CharType>
            friend
            std::basic_ostream<CharType>&
            operator <<(
              std::basic_ostream<CharType>& stack,
              Cell& cell
            )
            {
              return cell.print( stack );
            }
            
            void
            clear()
            {
              _value.clear();
            }

            void
            close()
            {
              clear();
              _closing = true;
            }

            /********** Accessors **********/

            ColumnCount& width() { return _width; };
            const ColumnCount& width() const { return _width; };

            std::string& value() { return _value; };
            const std::string& value() const { return _value; };

            /********** Variables **********/

            ColumnCount _width = 0;
            std::string _value;
            bool _closing = false;

          };

        }
      }
    }
  }
}

#endif
