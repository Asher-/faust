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

#ifndef _FOR_LOOP_INSTRUCTION_
#define _FOR_LOOP_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"

struct ForLoopInst : public StatementInst {
    StatementInst* fInit;
    StatementInst* fIncrement;
    ValueInst*     fEnd;
    BlockInst*     _code;
    const bool     fIsRecursive;

    ForLoopInst(StatementInst* init, ValueInst* end, StatementInst* increment, BlockInst* code, bool is_recursive)
        : fInit(init), fIncrement(increment), fEnd(end), _code(code), fIsRecursive(is_recursive)
    {
    }

    virtual ~ForLoopInst() {}

    void pushFrontInst(StatementInst* inst) { faustassert(inst); _code->pushFrontInst(inst); }

    void pushBackInst(StatementInst* inst) { faustassert(inst); _code->pushBackInst(inst); }

    std::string getName() const { return fInit->getName(); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif