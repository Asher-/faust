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

#ifndef _FUNCTION_CALL_INSTRUCTION_
#define _FUNCTION_CALL_INSTRUCTION_

#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/declarations.hh"
#include <string>

struct FunCallInst : public ValueInst {
    const std::string     fName;
    Values fArgs;  // List of arguments
    const bool       fMethod;

    FunCallInst(const std::string& name, const Values& args, bool method)
        : ValueInst(), fName(name), fArgs(args), fMethod(method)
    {
    }

    virtual ~FunCallInst() {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    ValueInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
