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

#include "faust/export.h"

#include "compiler/errors/errormsg.hh"
#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/errors/exception.hh"
#include "global.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"

#include <iostream>
using namespace std;

using Location = ::Faust::Compiler::Parser::Location::Implementation;

void evalerror(const std::string& filename, int linenum, const char* msg, Tree exp)
{
    stringstream error;
    error << filename << " : " << linenum << " : ERROR : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorCount++;
    throw faustexception(error.str());
}

void evalerrorbox(const std::string& filename, int linenum, const char* msg, Tree exp)
{
    stringstream error;
    error << filename << " : " << linenum << " : ERROR : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorCount++;
    throw faustexception(error.str());
}

void evalwarning(const std::string& filename, int linenum, const char* msg, Tree exp)
{
    stringstream error;
    error << filename << " : " << linenum << " : WARNING : " << msg << " : " << boxpp(exp) << endl;
    global::config.gErrorMessage = error.str();
}

void evalremark(const std::string& filename, int linenum, const char* msg, Tree exp)
{
    stringstream error;
    error << filename << " : " << linenum << " : REMARK : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorMessage = error.str();
}

void evalerror(const Location& location, const char* msg, Tree exp)
{
    stringstream error;
    error << location << " : ERROR : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorCount++;
    throw faustexception(error.str());
}

void evalerrorbox(const Location& location, const char* msg, Tree exp)
{
    stringstream error;
    error << location << " : ERROR : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorCount++;
    throw faustexception(error.str());
}

void evalwarning(const Location& location, const char* msg, Tree exp)
{
    stringstream error;
    error << location << " : WARNING : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorMsg = error.str();
}

void evalremark(const Location& location, const char* msg, Tree exp)
{
    stringstream error;
    error << location << " : REMARK : " << msg << " : " << boxpp(exp) << endl;
    global::config().gErrorMsg = error.str();
}

