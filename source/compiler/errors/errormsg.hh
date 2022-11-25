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

#ifndef _ERRORMSG_
#define _ERRORMSG_

#include "tlib/tlib.hh"

#include "compiler/parser/lexer/location/implementation.hh"

// three levels or errors, warnings and remarks are provided during evaluation
void evalerror(const std::string& filename, int linenum, const char* msg, Tree exp);
void evalerrorbox(const std::string& filename, int linenum, const char* msg, Tree exp);
void evalwarning(const std::string& filename, int linenum, const char* msg, Tree exp);
void evalremark(const std::string& filename, int linenum, const char* msg, Tree exp);

void evalerror(const ::Faust::Compiler::Parser::Lexer::Location::Implementation& location, const char* msg, Tree exp);
void evalerrorbox(const ::Faust::Compiler::Parser::Lexer::Location::Implementation& location, const char* msg, Tree exp);
void evalwarning(const ::Faust::Compiler::Parser::Lexer::Location::Implementation& location, const char* msg, Tree exp);
void evalremark(const ::Faust::Compiler::Parser::Lexer::Location::Implementation& location, const char* msg, Tree exp);

#endif
