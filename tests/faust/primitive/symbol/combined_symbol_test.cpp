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

#include "faust/primitive/symbols/combined.hh"

struct CombinedSymbolTest
:
  ::testing::Test
{

    CombinedSymbolTest
    ()
    {
      ::Faust::Primitive::Symbols::runtime.clear();
    }

    virtual
    ~CombinedSymbolTest
 
    ()
    {

    }

    using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;

};

namespace Symbol = ::Faust::Primitive::Symbol;
namespace Symbols = ::Faust::Primitive::Symbols;

TEST_F( CombinedSymbolTest, symbolDoesNotExist ) {
  std::string name( "NameThatDoesNotExist" );
  AbstractSymbol* null_symbol = Symbols::combined.symbol( name, false );
  ASSERT_EQ( null_symbol, nullptr );
}

TEST_F( CombinedSymbolTest, internalSymbol ) {
  std::string name( "EvalProperty" );
  auto hash = Symbol::hash( name );
  AbstractSymbol* symbol = Symbols::combined.symbol( name, false );
  ASSERT_EQ( symbol->hash(), hash );
}

TEST_F( CombinedSymbolTest, runtimeSymbol ) {
  std::string name = "RuntimeSymbol";
  AbstractSymbol* symbol = Symbols::combined.symbol( name, false );
  ASSERT_EQ( symbol, nullptr );
  symbol = Symbols::runtime.insert( name, false );
  ASSERT_NE( symbol, nullptr );
  ASSERT_EQ( symbol->name(), "RuntimeSymbol" );
  ASSERT_EQ( symbol->hash(), Symbol::hash( symbol->name() ) );
  AbstractSymbol* symbol_again_runtime = Symbols::runtime.symbol( name, false );
  ASSERT_NE( symbol_again_runtime, nullptr );
  ASSERT_EQ( symbol_again_runtime->name(), "RuntimeSymbol" );
  ASSERT_EQ( symbol_again_runtime->hash(), Symbol::hash( symbol->name() ) );
  AbstractSymbol* symbol_again_combined = Symbols::combined.symbol( name, false );
  ASSERT_NE( symbol_again_combined, nullptr );
  ASSERT_EQ( symbol, *symbol_again_combined ); // without deref we are comparing address instead of symbol
}

