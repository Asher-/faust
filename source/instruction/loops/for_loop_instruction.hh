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

#ifndef _FOR_LOOP_INSTRUCTION_
#define _FOR_LOOP_INSTRUCTION_

#include "instruction/statement_instruction.hh"

struct ForLoopInst : public StatementInst {
    StatementInst* fInit;
    StatementInst* fIncrement;
    ValueInst*     fEnd;
    BlockInst*     fCode;
    const bool     fIsRecursive;

    ForLoopInst(StatementInst* init, ValueInst* end, StatementInst* increment, BlockInst* code, bool is_recursive)
        : fInit(init), fIncrement(increment), fEnd(end), fCode(code), fIsRecursive(is_recursive)
    {
    }

    virtual ~ForLoopInst() {}

    void pushFrontInst(StatementInst* inst) { faustassert(inst); fCode->pushFrontInst(inst); }

    void pushBackInst(StatementInst* inst) { faustassert(inst); fCode->pushBackInst(inst); }

    std::string getName() const { return fInit->getName(); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
