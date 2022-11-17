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

#include "faust/primitive/symbol/internal/implementation.hh"
#include "faust/primitive/symbols/internal.hh"

struct InternalSymbolTest
:
  ::testing::Test
{

    InternalSymbolTest
    ()
    {
    }

    virtual
    ~InternalSymbolTest

    ()
    {

    }
    
    using InternalSymbols = ::Faust::Primitive::Symbols::Internal;
    using AbstractSymbol = ::Faust::Primitive::Symbol::Abstract::Implementation;
};

namespace Symbol = ::Faust::Primitive::Symbol;
namespace Symbols = ::Faust::Primitive::Symbols;


TEST_F( InternalSymbolTest, symbolDoesNotExist ) {
  std::string name( "NameThatDoesNotExist" );
  AbstractSymbol* null_symbol = Symbols::internal.symbol( name, false );
  ASSERT_EQ( null_symbol, nullptr );
}

TEST_F( InternalSymbolTest, symbol ) {
  std::string name( "EvalProperty" );
  auto hash = Symbol::hash( name );
  AbstractSymbol* symbol = Symbols::internal.symbol( name, false );
  ASSERT_EQ( symbol->hash(), hash );
}

