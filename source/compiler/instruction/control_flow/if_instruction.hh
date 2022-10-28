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

#ifndef _IF_INSTRUCTION_
#define _IF_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/statement/block_instruction.hh"
#include "compiler/instruction/declarations.hh"

struct IfInst : public StatementInst {
    ValueInst* fCond;
    BlockInst* fThen;
    BlockInst* fElse;

    IfInst(ValueInst* cond_inst, BlockInst* then_inst, BlockInst* else_inst)
        : fCond(cond_inst), fThen(then_inst), fElse(else_inst)
    {
    }

    IfInst(ValueInst* cond_inst, BlockInst* then_inst) : fCond(cond_inst), fThen(then_inst), fElse(new BlockInst()) {}

    virtual ~IfInst() {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
