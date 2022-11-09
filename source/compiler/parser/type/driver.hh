/************************************************************************
 ************************************************************************
 FAUST compiler
 Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
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

#ifndef __FAUST_SOURCE_COMPILER_PARSER_DRIVER_HH__
#define __FAUST_SOURCE_COMPILER_PARSER_DRIVER_HH__

#include <string>
#include <fstream>
#include <map>

#include "tlib/tree.hh"

#include "compiler/parser/faustparser.hh"
#include "compiler/parser/lexer/implementation.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Type {
      
        struct Driver
        {
          using Parser = ::Faust::Compiler::Parser::Implementation;
          using Location = ::Faust::Compiler::Parser::location;
          using Lexer = ::Faust::Compiler::Parser::Lexer::Implementation;

          Driver ()
          :
            _traceParsing(false),
            _traceScanning(false),
            _parser(*this)
          {
          }

          int
          scan()
          {
            _parser.set_debug_level( _traceParsing );
            int result_state = _parser();
            return result_state;
          }

          int parseStream(
            std::istream& in,
            const std::string& stream_name
          ) {
            _streamName = stream_name;

            Lexer lexer( &in );
            _lexer = &lexer;
//            yyset_extra();
//            _lexer->set_debug( _traceScanning );

            Parser parser(*this);
            parser.set_debug_level( _traceParsing );
            int res = parser();
            _lexer = nullptr;

            return res;
          }

          int
          parseFile(
            const std::string &filename
          ) {
            std::ifstream in(filename.c_str());
            if (!in.good()) return false;
            return parseStream(in, filename);
          }

          int
          parseString(
            const std::string& input,
            const std::string& stream_name
          ) {
            std::istringstream iss(input);
            return parseStream(iss, stream_name);
          }

          void
          error(
            const class location& l,
            const std::string& m
          ) {
            std::cerr << l << ": " << m << std::endl;
          }

          void error(const std::string& m)
          {
            std::cerr << m << std::endl;
          }

          std::string _streamName;
          
          bool _traceParsing;
          bool _traceScanning;

          Lexer* _lexer = nullptr;
          Parser _parser;
          Location _location;
        };
        
      };
    };
  };
};

#endif

