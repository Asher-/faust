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

#ifndef _SIMPLE_FOR_LOOP_INSTRUCTION_
#define _SIMPLE_FOR_LOOP_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/statement/block_instruction.hh"

#include "visitor/instruction_visitor.hh"
#include "visitor/clone_visitor.hh"

struct InstructionBuilder;

// To be used for the Rust backend
struct SimpleForLoopInst : public StatementInst {
    StatementInst* fInit;
    ValueInst*   fUpperBound;
    ValueInst*   fLowerBound;
    const std::string fName;
    const bool   fReverse;
    BlockInst* fCode;

    SimpleForLoopInst(const std::string& name, ValueInst* upperBound, ValueInst* lowerBound, bool reverse, BlockInst* code);

    std::string getName() const { return fName; }

    virtual ~SimpleForLoopInst() {}

    void pushFrontInst(StatementInst* inst) { faustassert(inst); fCode->pushFrontInst(inst); }

    void pushBackInst(StatementInst* inst) { faustassert(inst); fCode->pushBackInst(inst); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
