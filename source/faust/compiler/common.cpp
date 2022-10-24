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

#include "faust/compiler/common.hh"

#include "faust/compiler/c.hh"
#include "faust/compiler/clang.hh"
#include "faust/compiler/cpp.hh"
#include "faust/compiler/csharp.hh"
#include "faust/compiler/dlang.hh"
#include "faust/compiler/fir.hh"
#include "faust/compiler/interpreter.hh"
#include "faust/compiler/java.hh"
#include "faust/compiler/jax.hh"
#include "faust/compiler/julia.hh"
#include "faust/compiler/llvm.hh"
#include "faust/compiler/ocpp.hh"
#include "faust/compiler/rust.hh"
#include "faust/compiler/soul.hh"
#include "faust/compiler/wasm.hh"
#include "faust/compiler/wast.hh"

namespace Faust {
  namespace Compiler {

      Common* Common::compiler( const std::string& output_lang )
      {
          Common* compiler(nullptr);
          if (output_lang == "cllvm") {
              compiler = new ::Faust::Compiler::Clang;
          }
          else if (output_lang == "llvm") {
              compiler = new ::Faust::Compiler::LLVM;
          }
          else if (startWith(output_lang, "interp")) {
              compiler = new ::Faust::Compiler::Interpreter;
          }
          else if (output_lang == "fir") {
              compiler = new ::Faust::Compiler::FIR;
          }
          else if (output_lang == "c") {
              compiler = new ::Faust::Compiler::C;
          }
          else if (output_lang == "cpp") {
              compiler = new ::Faust::Compiler::CPP;
          }
          else if (output_lang == "ocpp") {
              compiler = new ::Faust::Compiler::OCPP;
          }
          else if (output_lang == "rust") {
              compiler = new ::Faust::Compiler::Rust;
          }
          else if (output_lang == "java") {
              compiler = new ::Faust::Compiler::Java;
          }
          else if (output_lang == "jax") {
              compiler = new ::Faust::Compiler::JAX;
          }
          else if (output_lang == "julia") {
              compiler = new ::Faust::Compiler::Julia;
          }
          else if (output_lang == "csharp") {
              compiler = new ::Faust::Compiler::CSharp;
          }
          else if (startWith(output_lang, "soul")) {
              compiler = new ::Faust::Compiler::Soul;
          }
          else if (startWith(output_lang, "wast")) {
              compiler = new ::Faust::Compiler::WAST;
          }
          else if (startWith(output_lang, "wasm")) {
              compiler = new ::Faust::Compiler::WASM;
          }
          else if (startWith(output_lang, "dlang")) {
              compiler = new ::Faust::Compiler::Dlang;
          }
          else {
              stringstream error;
              error << "ERROR : cannot find backend for "
                    << "\"" << output_lang << "\"" << endl;
              throw faustexception(error.str());
          }
          return compiler;
      }

  }
}
