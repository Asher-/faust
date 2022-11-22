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

#ifndef __FAUST__COMPILER__PARSER__LEXER__POSITION__HH__
#define __FAUST__COMPILER__PARSER__LEXER__POSITION__HH__

#include <iostream>
#include <string>

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Lexer {
        namespace Location {

          struct Position
          {
            /********** Types **********/

            using CountingType = std::size_t;
            using ColumnCount = CountingType;
            using LineCount = CountingType;

            /********** Constructors **********/

            explicit
            Position(
              const std::string&  name,
              const LineCount&    line,
              const ColumnCount&  column
            )
            :
              _streamName( name ),
              _line( line ),
              _column( column )
            {}

            /********** Copy Constructors **********/

            Position
            ( const Position& copy_instance )
            :
              _streamName( copy_instance.streamName() ),
              _line( copy_instance.line() ),
              _column( copy_instance.column() )
            {
            }

            /********** Advance **********/

            /** \name Line and Column related manipulators
             ** \{ */
            /// (line related) Advance to the COUNT next lines.
            void advanceLine(
              const CountingType& count
            ) {
              if (count)
              {
                _column = 1; /* Reset column to first character. */
                _line += count;
              }
            }
            void advanceLine() { advanceLine(1); }

            /// (column related) Advance to the COUNT next columns.
            void advanceColumn(
              const ColumnCount& count
            ) {
              _column += count;
            }
            void advanceColumn() { advanceColumn(1); }
            /** \} */

            Position&
            operator +=(
              const CountingType& width
            ) {
              advanceColumn(width);
              return *this;
            }
            
            /********** Operators **********/

            Position
            operator +(
              const CountingType& width
            )
            const
            {
              Position copy(*this);
              return copy += width;
            }

            Position&
            operator -=(
              const CountingType& width
            ) {
              advanceColumn(-width);
              return *this;
            }

            Position
            operator -(
              const CountingType& width
            )
            const
            {
              Position copy(*this);
              return copy -= width;
            }

            /********** Accessors **********/
            
            std::string& streamName() { return _streamName; };
            const std::string& streamName() const { return _streamName; };
            
            LineCount& line() { return _line; };
            const LineCount& line() const { return _line; };

            ColumnCount& column() { return _column; };
            const ColumnCount& column() const { return _column; };

            /********** Assignment **********/
            
            Position&
            operator =(
              const Position& rhs
            )
            {
              _streamName = rhs.streamName();
              _line = rhs.line();
              _column = rhs.column();
              return *this;
            }

            /********** ostream **********/

            /** \brief Intercept output stream redirection.
             ** \param ostr the destination output stream
             ** \param pos a reference to the Position to redirect
             */
            template <typename CharType>
            friend
            std::basic_ostream<CharType>&
            operator <<(
              std::basic_ostream<CharType>& ostr,
              const Position& pos
            )
            {
              if (pos.streamName().length())
                ostr << pos.streamName() << ':';
              return ostr << pos.line() << '.' << pos.column();
            }

            /********** Variables **********/

            std::string _streamName;
            LineCount _line;
            ColumnCount _column;

          };









        }
      }
    }
  }
}

#endif 
