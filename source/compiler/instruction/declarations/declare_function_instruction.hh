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

#ifndef _DECLARE_FUNCTION_INSTRUCTION_
#define _DECLARE_FUNCTION_INSTRUCTION_

#include "compiler/instruction/statement_instruction.hh"
#include "compiler/instruction/block_instruction.hh"
#include "types/function_typed.hh"

struct DeclareFunInst : public StatementInst {
    const std::string fName;
    FunTyped*    fType;  // Describes type of all arguments and function result
    BlockInst*   fCode;  // Code is a list of StatementInst*

    DeclareFunInst(const std::string& name, FunTyped* type, BlockInst* code = new BlockInst());

    virtual ~DeclareFunInst() {}

    Typed::VarType getResType() { return fType->fResult->getType(); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
