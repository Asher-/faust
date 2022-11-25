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

#ifndef __FAUST__COMPILER__PARSER__LEXER__LOCATION__HH__
#define __FAUST__COMPILER__PARSER__LEXER__LOCATION__HH__

#include "compiler/parser/lexer/location/position.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Lexer {
        namespace Location {

          struct Implementation
          {

            /********** Types **********/

            using Position = ::Faust::Compiler::Parser::Lexer::Location::Position;
          
            using CountingType = typename Position::CountingType;
            using LineCount = typename Position::LineCount;
            using ColumnCount = typename Position::ColumnCount;

            /********** Constructors **********/

            /// Construct a default Implementation.
            Implementation
            ()
            :
              _begin( "<start>", 1, 1 ),
              _end( "<start>", 1, 1 )
            {}

            /// Construct a Implementation from \a b to \a e.
            Implementation
            (
              const Position& begin,
              const Position& end
            )
            :
              _begin( begin ),
              _end( end )
            {}

            /// Construct a 0-width Implementation in \a p.
            explicit
            Implementation(
              const Position& position
            )
            :
              _begin( position ),
              _end( position )
            {}

            explicit
            Implementation(
              const std::string&  name
            )
            :
              Implementation(
                Position( name, 1, 1 )
              )
            {}

            /// Construct a 0-width Implementation in \a f, \a l, \a c.
            explicit
            Implementation(
              const std::string&  name,
              const LineCount&    line,
              const ColumnCount&  column
            )
            :
              _name( name ),
              _begin( Position( name, line, column) ),
              _end( Position( name, line, column) )
            {}

            /********** Copy Constructors **********/

            Implementation
            ( const Implementation& copy_instance )
            :
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
              _begin.streamName() = _end.streamName() = stream_name;
              _positionInImplementation = true;
              return *this;
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
              Implementation::CountingType end_col = 0 < loc.end().column() ? loc.end().column() - 1 : 0;
              ostr << loc.begin();
              if (loc.end().streamName().length()
                  && (!loc.begin().streamName().length()
                      || loc.begin().streamName() != loc.end().streamName()))
                ostr << '-' << loc.end().streamName() << ':' << loc.end().line() << '.' << end_col;
              else if (loc.begin().line() < loc.end().line())
                ostr << '-' << loc.end().line() << '.' << end_col;
              else if (loc.begin().column() < end_col)
                ostr << '-' << end_col;
              return ostr;
            }

            /********** Accessors **********/

            std::string& name() { return _name; };
            const std::string& name() const { return _name; };

            bool& positionInImplementation() { return _positionInImplementation; };
            const bool& positionInImplementation() const { return _positionInImplementation; };

            Position& begin() { return _begin; };
            const Position& begin() const { return _begin; };
            Position& end() { return _end; };
            const Position& end() const { return _end; };

            std::vector<Implementation>& parts() { return _parts; };
            const std::vector<Implementation>& parts() const { return _parts; };

            /********** Variables **********/
            
            std::string _name;
            bool        _positionInImplementation = false;
            
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
}

#endif 
