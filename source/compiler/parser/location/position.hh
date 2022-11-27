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

#ifndef __FAUST__COMPILER__PARSER__LOCATION__POSITION__HH__
#define __FAUST__COMPILER__PARSER__LOCATION__POSITION__HH__

#include <iostream>
#include <sstream>
#include <string>

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Location {

        struct Position
        {
          /********** Types **********/

          using CountingType = std::size_t;
          using ColumnCount = CountingType;
          using LineCount = CountingType;

          /********** Constructors **********/

          Position()
          :
            _line( 1 ),
            _column( 1 )
          {}

          explicit
          Position(
            const LineCount&    line,
            const ColumnCount&  column
          )
          :
            _line( line ),
            _column( column )
          {}

          /********** Copy Constructors **********/

          Position
          ( const Position& copy_instance )
          :
            _line( copy_instance.line() ),
            _column( copy_instance.column() )
          {
          }

          /********** Conversion **********/
          
          operator std::string()
          const
          {
            std::stringstream out;
            out << *this;
            return out.str();
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
            _line = rhs.line();
            _column = rhs.column();
            return *this;
          }

          /********** Comparison **********/

          const bool
          operator ==(
            const Position& rhs
          )
          const
          {
            return _line == rhs.line()
                && _column == rhs.column();
          }

          const bool
          operator !=(
            const Position& rhs
          )
          const
          {
            return ! operator==(rhs);
          }

          const bool
          operator <(
            const Position& rhs
          )
          const
          {
            if ( _line < rhs.line() )
              return true;
            else if ( _line == rhs.line() )
              return _column < rhs.column();
            else
              return false;
          }

          const bool
          operator <=(
            const Position& rhs
          )
          const
          {
            if ( _line < rhs.line() )
              return true;
            else if ( _line == rhs.line() )
              return _column <= rhs.column();
            else
              return false;
          }

          const bool
          operator >(
            const Position& rhs
          )
          const
          {
            if ( _line > rhs.line() )
              return true;
            else if ( _line == rhs.line() )
              return _column > rhs.column();
            else
              return false;
          }

          const bool
          operator >=(
            const Position& rhs
          )
          const
          {
            if ( _line > rhs.line() )
              return true;
            else if ( _line == rhs.line() )
              return _column >= rhs.column();
            else
              return false;
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
            return ostr << pos.line() << '.' << pos.column();
          }
          
          static constexpr
          std::size_t
          digits(
            const std::size_t& number
          ) {
            return  1
          + (std::size_t)(number>=10)
          + (std::size_t)(number>=100)
          + (std::size_t)(number>=1000)
          + (std::size_t)(number>=10000)
          + (std::size_t)(number>=100000)
          + (std::size_t)(number>=1000000)
          + (std::size_t)(number>=10000000)
          + (std::size_t)(number>=100000000)
          + (std::size_t)(number>=1000000000)
          + (std::size_t)(number>=10000000000ull)
          + (std::size_t)(number>=100000000000ull)
          + (std::size_t)(number>=1000000000000ull)
          + (std::size_t)(number>=10000000000000ull)
          + (std::size_t)(number>=100000000000000ull)
          + (std::size_t)(number>=1000000000000000ull)
          + (std::size_t)(number>=10000000000000000ull)
          + (std::size_t)(number>=100000000000000000ull)
          + (std::size_t)(number>=1000000000000000000ull)
          + (std::size_t)(number>=10000000000000000000ull);
            /* (2^64 = 1.84467441e19) < 10000000000000000000ull  */
          }

          std::size_t
          lineDigits()
          const
          {
            std::size_t line_digits = digits( _line );
            return line_digits;
          }

          std::size_t
          columnDigits()
          const
          {
            std::size_t column_digits = digits( _column );
            return column_digits;
          }

          std::size_t
          digits()
          const
          {
            std::size_t digit_count = lineDigits() + columnDigits() + 1;
            return digit_count;
          }

          /********** Variables **********/

          LineCount _line = 1;
          ColumnCount _column = 1;

        };

      }
    }
  }
}

#endif 
