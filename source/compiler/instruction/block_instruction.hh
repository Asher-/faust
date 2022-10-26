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

#ifndef _BLOCK_INSTRUCTION_
#define _BLOCK_INSTRUCTION_

#include "compiler/instruction/statement_instruction.hh"
#include "compiler/instruction/declarations.hh"
#include "visitor/instruction_visitor.hh"
#include "visitor/clone_visitor.hh"

#include <list>

// ====================
// Block of statements
// ====================

struct BlockInst : public StatementInst {
    std::list<StatementInst*> fCode;
    bool                 fIndent;

    BlockInst(std::list<StatementInst*> code) : fCode(code), fIndent(false) {}

    BlockInst() : fIndent(false) {}

    virtual ~BlockInst() {}

    void setIndent(bool indent) { fIndent = indent; }
    bool getIndent() { return fIndent; }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    void pushFrontInst(StatementInst* inst) { faustassert(inst); fCode.push_front(inst); }

    void pushBackInst(StatementInst* inst) { faustassert(inst); fCode.push_back(inst); }

    void merge(BlockInst* inst)
    {
        for (const auto& it : inst->fCode) {
            fCode.push_back(it);
        }
    }

    int size() const { return int(fCode.size()); }

    bool hasReturn() const;
    ValueInst* getReturnValue();
};

#endif
