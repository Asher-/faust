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

#ifndef __FAUST__COMPILER__PARSER__LOCATION__HH__
#define __FAUST__COMPILER__PARSER__LOCATION__HH__

#include <sstream>
#include <vector>

#include "compiler/parser/location/position.hh"
#include "compiler/parser/location/print/tree.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Location {

        struct Implementation
        {

          /********** Types **********/

          using Position = ::Faust::Compiler::Parser::Location::Position;
        
          using CountingType = typename Position::CountingType;
          using LineCount = typename Position::LineCount;
          using ColumnCount = typename Position::ColumnCount;

          using TreePrinter = ::Faust::Compiler::Parser::Location::Print::Tree<Implementation>;

          /********** Constructors **********/

          Implementation
          ()
          :
            _streamName( "<start>" ),
            _begin( 1, 1 ),
            _end( 1, 1 )
          {}

          explicit
          Implementation(
            const std::string&  stream_name
          )
          :
            _streamName( stream_name )
          {}

          explicit
          Implementation(
            const std::string&  stream_name,
            const std::string&  symbol_name,
            const Position&     position
          )
          :
            _begin( position ),
            _end( position )
          {}

          Implementation
          (
            const std::string&  stream_name,
            const std::string&  symbol_name,
            const Position&     begin,
            const Position&     end
          )
          :
            _begin( begin ),
            _end( end )
          {}

          explicit
          Implementation(
            const std::string&  stream_name,
            const std::string&  symbol_name,
            const std::string&  name
          )
          :
            Implementation(
              stream_name,
              symbol_name,
              Position( 1, 1 )
            )
          {}

          explicit
          Implementation(
            const std::string&  stream_name,
            const std::string&  symbol_name,
            const LineCount&    line,
            const ColumnCount&  column
          )
          :
            _streamName( stream_name ),
            _name( symbol_name ),
            _begin( Position( line, column) ),
            _end( Position( line, column) )
          {}

          /********** Copy Constructors **********/

          Implementation
          ( const Implementation& copy_instance )
          :
            _streamName( copy_instance.streamName() ),
            _name( copy_instance.name() ),
            _begin( copy_instance.begin() ),
            _end( copy_instance.end() ),
            _parts( copy_instance.parts() )
          {
          }

          /********** Advance **********/

          /** \name Line and Column related manipulators
           ** \{ */

          /// Reset initial Implementation to final Implementation.
          void step()
          {
            _begin = _end;
          }

          /// Extend the current Implementation to the COUNT next advanceColumn.
          void advanceColumn(
            const ColumnCount& count
          ) {
            _end += count;
          }
          void advanceColumn() { advanceColumn(1); }

          /// Extend the current Implementation to the COUNT next lines.
          void advanceLine(
            const LineCount& count
          ) {
            _end.advanceLine(count);
          }
          void advanceLine() { advanceLine(1); }

          /** \} */

          /********** Operators **********/

          /// Join two tokens
          Implementation&
          operator +=(
            const Implementation& rhs
          ) {
            _end = rhs.end();
            return *this;
          }

          /// Join two Implementations
          Implementation
          operator +(
            const Implementation& end
          )
          const
          {
            Implementation copy(*this);
            return copy += end;
          }

          /// Add \a width advanceColumn to the end Position, in place.
          Implementation&
          operator +=(
            ColumnCount width
          ) {
            advanceColumn(width);
            return *this;
          }

          /// Add \a width advanceColumn to the end Position.
          Implementation
          operator +(
            ColumnCount width
          )
          const
          {
            Implementation copy(*this);
            return copy += width;
          }

          /// Subtract \a width advanceColumn to the end Position, in place.
          Implementation&
          operator -=(
            ColumnCount width
          )
          {
            advanceColumn(-width);
            return *this;
          }

          /// Subtract \a width advanceColumn to the end Position.
          Implementation
          operator -(
            ColumnCount width
          )
          const
          {
            Implementation copy(*this);
            return copy -= width;
          }

          /********** Assignment **********/
          
          Implementation&
          operator =(
            const Implementation& rhs
          )
          {
            _streamName = rhs.streamName();
            _name = rhs.name();
            _begin = rhs.begin();
            _end = rhs.end();
            _parts = rhs.parts();
            return *this;
          }
          
          /* To declare locations in Faust implementation (C++) source. */
          Implementation&
          setToPositionInImplementation(
            const std::string& name,
            const std::string& stream_name,
            const std::size_t& line_number
          )
          {
            _name = name;
            _begin.line() = _end.line() = line_number;
            _begin.column() = _end.column() = 0;
            _streamName = stream_name;
            _isInImplementation = true;
            return *this;
          }

          /********** Comparison **********/

          const bool
          operator ==(
            const Implementation& rhs
          )
          const
          {
            return _streamName == rhs.streamName()
                && _name == rhs.name()
                && _begin == rhs.begin()
                && _end == rhs.end()
                && _parts == rhs.parts();
          }

          const bool
          operator !=(
            const Implementation& rhs
          )
          const
          {
            return ! operator==(rhs);
          }

          /********** ostream **********/

          /** \brief Intercept output stream redirection.
           ** \param ostr the destination output stream
           ** \param loc a reference to the Implementation to redirect
           **
           ** Avoid duplicate information.
           */
          template <typename CharType>
          friend
          std::basic_ostream<CharType>&
          operator <<(
            std::basic_ostream<CharType>& ostr,
            const Implementation& loc
          )
          {
            // end() is 1 past the last position
            ostr << loc.streamName() << (loc.streamName().length() ? ":" : "");
            ostr << loc.begin();
            if ( loc.end() != loc.begin() ) {
              ostr << "-" << loc.end();
            }
            return ostr;
          }
          
          std::string
          stackString()
          {
            std::stringstream stack;
            printStack( stack );
            return stack.str();
          }
          
          const std::size_t
          digits()
          const
          {
            if ( _end.column() > _begin.column() )
              return _end.digits();
            else {
              return _end.lineDigits() + _begin.columnDigits();
            }
          }

          template <typename CharType>
          std::basic_ostream<CharType>&
          printStack(
            std::basic_ostream<CharType>&  stack
          )
          const
          {
            TreePrinter printer( *this );
            stack << printer;
            return stack;
          }


          /********** Accessors **********/

          std::string& streamName() { return _streamName; };
          const std::string& streamName() const { return _streamName; };
          
          std::string& name() { return _name; };
          const std::string& name() const { return _name; };

          bool& isInImplementation() { return _isInImplementation; };
          const bool& isInImplementation() const { return _isInImplementation; };

          Position& begin() { return _begin; };
          const Position& begin() const { return _begin; };
          Position& end() { return _end; };
          const Position& end() const { return _end; };

          std::vector<Implementation>& parts() { return _parts; };
          const std::vector<Implementation>& parts() const { return _parts; };

          /********** Variables **********/
          
          std::string _streamName;

          std::string _name;
          bool        _isInImplementation = false;
          
          Position _begin;
          Position _end;
          
          std::vector<Implementation> _parts = {};

        };

        #define SET_LOCATION_IN_IMPLEMENTATION( location, name ) \
                location.setToPositionInImplementation( name, __FILE__, __LINE__ );

      }
    }
  }
}

#endif 
