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

#ifndef __FAUST_COMPILERS_HH__
#define __FAUST_COMPILERS_HH__

#include "faust/compiler/generator/c.hh"
#include "faust/compiler/generator/clang.hh"
#include "faust/compiler/generator/cpp.hh"
#include "faust/compiler/generator/csharp.hh"
#include "faust/compiler/generator/dlang.hh"
#include "faust/compiler/generator/fir.hh"
#include "faust/compiler/generator/interpreter.hh"
#include "faust/compiler/generator/java.hh"
#include "faust/compiler/generator/jax.hh"
#include "faust/compiler/generator/julia.hh"
#include "faust/compiler/generator/llvm.hh"
#include "faust/compiler/generator/ocpp.hh"
#include "faust/compiler/generator/rust.hh"
#include "faust/compiler/generator/soul.hh"
#include "faust/compiler/generator/wasm.hh"
#include "faust/compiler/generator/wast.hh"

namespace Faust {

  template <typename... Compilers> struct CompilerTypes {};
  using Compilers = CompilerTypes
  <
    ::Faust::Compiler::Clang,
    ::Faust::Compiler::LLVM,
    ::Faust::Compiler::Interpreter,
    ::Faust::Compiler::FIR,
    ::Faust::Compiler::C,
    ::Faust::Compiler::CPP,
    ::Faust::Compiler::OCPP,
    ::Faust::Compiler::Rust,
    ::Faust::Compiler::Java,
    ::Faust::Compiler::JAX,
    ::Faust::Compiler::Julia,
    ::Faust::Compiler::CSharp,
    ::Faust::Compiler::Soul,
    ::Faust::Compiler::WAST,
    ::Faust::Compiler::WASM,
    ::Faust::Compiler::Dlang
  >;

}

#endif
