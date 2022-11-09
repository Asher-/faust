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

#ifndef __FAUST_SOURCE_COMPILER_PARSER_LEXER_HH__
#define __FAUST_SOURCE_COMPILER_PARSER_LEXER_HH__

#include <string>

#include "compiler/parser/faustparser.hh"

#include "tlib/tree.hh"

namespace Faust { namespace Compiler { namespace Parser {
  namespace Type { struct Driver; }
  namespace Lexer {
    struct Implementation;
} } } }

#define YY_DECL symbol_type ::Faust::Compiler::Parser::Lexer::Implementation::lex()

#ifndef FaustAbstractFlexLexer
  #undef yyFlexLexer
  #define yyFlexLexer FaustAbstractFlexLexer
  #include <FlexLexer.h>
#endif

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Type { struct Driver; }
      namespace Lexer {
      
        struct Implementation : FaustAbstractFlexLexer
        {
          using Driver = ::Faust::Compiler::Parser::Type::Driver;
          using Parser = ::Faust::Compiler::Parser::Implementation;

          Implementation
          ( std::istream& arg_yyin,
            std::ostream& arg_yyout )
          : FaustAbstractFlexLexer(
              arg_yyin,
              arg_yyout
            )
          {}
          
          Implementation
          ( std::istream* arg_yyin = nullptr,
            std::ostream* arg_yyout = nullptr )
          : FaustAbstractFlexLexer(
              arg_yyin,
              arg_yyout
            )
          {}

          typename Parser::symbol_type
          lex( Driver& driver );
          
        };
        
      };
    };
  };
};

#endif

