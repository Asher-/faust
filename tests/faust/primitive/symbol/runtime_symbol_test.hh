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

#include "faust/primitive/symbol/runtime/implementation.hh"
#include "faust/primitive/symbols/runtime.hh"

struct RuntimeSymbolTest
:
  ::testing::Test
{

    RuntimeSymbolTest
    ()
    {
      ::Faust::Primitive::Symbols::runtime().clear();
    }

    virtual
    ~RuntimeSymbolTest

    ()
    {

    }
    
    using RuntimeSymbols = ::Faust::Primitive::Symbols::Runtime;
    using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;

};

namespace Symbol = ::Faust::Primitive::Symbol;
namespace Symbols = ::Faust::Primitive::Symbols;

TEST_F( RuntimeSymbolTest, symbolDoesNotExist ) {
  std::string name( "NameThatDoesNotExist" );
  AbstractSymbol* null_symbol = Symbols::runtime().symbol( name, false );
  ASSERT_EQ( null_symbol, nullptr );
}

TEST_F( RuntimeSymbolTest, insertAndRetrieve ) {
  std::string name( "RuntimeSymbol" );
  AbstractSymbol* symbol = Symbols::runtime().symbol( name, false );
  ASSERT_EQ( symbol, nullptr );
  symbol = Symbols::runtime().insert( name, false );
  ASSERT_NE( symbol, nullptr );
  ASSERT_EQ( symbol->name(), "RuntimeSymbol" );
  ASSERT_EQ( symbol->hash(), Symbol::hash( symbol->name() ) );
  AbstractSymbol* symbol_again_insert = Symbols::runtime().insert( name, false );
  ASSERT_NE( symbol_again_insert, nullptr );
  ASSERT_EQ( symbol_again_insert->name(), "RuntimeSymbol" );
  ASSERT_EQ( symbol_again_insert->hash(), Symbol::hash( symbol->name() ) );
  AbstractSymbol* symbol_again_retrieve = Symbols::runtime().symbol( name, false );
  ASSERT_NE( symbol_again_retrieve, nullptr );
  ASSERT_EQ( *symbol, *symbol_again_retrieve ); // without deref we are comparing address instead of symbol
}

