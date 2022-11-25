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

#include <gtest/gtest.h>

#include "compiler/parser/implementation.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"
#include "global.hh"

using Parser = ::Faust::Compiler::Parser::Implementation;

struct ParserTest
:
  ::testing::Test
{

    ParserTest
    ()
    {
      /* Uncomment for Bison/Flex trace output */
      parser.setTraceParsing();
      parser._traceScanning = false;
    }

    virtual
    ~ParserTest

    ()
    {

    }
    

    Parser parser;

};

//TEST_F( ParserTest, empty ) {
//  std::string source = R""""()"""";
//  Tree ast = parser.parseString( source, "Empty.dsp" );
//  ASSERT_EQ( ast, nullptr );
//}
//
//TEST_F( ParserTest, semicolon ) {
//  std::string source = R""""(;)"""";
//  Tree ast = parser.parseString( source, "semicolon.dsp" );
//  ASSERT_EQ( ast, nullptr );
//}
//
//TEST_F( ParserTest, identifier ) {
//  std::string source = R""""(process=_;)"""";
//  Tree ast = parser.parseString( source, "identity.dsp" );
//  ASSERT_NE( ast, nullptr );
//  std::stringstream pprint;
//  pprint << boxpp(ast);
//  std::string printed(pprint.str());
//  std::cout << pprint.str() << std::endl;
//}

//TEST_F( ParserTest, function ) {
//  std::string source = R""""(somename(y)=x*y)"""";
//  Tree ast = parser.parseString( source, "function.dsp" );
//  ASSERT_NE( ast, nullptr );
//  std::stringstream pprint;
//  pprint << boxpp(ast);
//  std::cout << pprint.str() << std::endl;
//}

