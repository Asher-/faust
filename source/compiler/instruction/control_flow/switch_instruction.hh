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

#ifndef _SWITCH_INSTRUCTION_
#define _SWITCH_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/declarations.hh"
#include <list>
#include <utility>

struct SwitchInst : public StatementInst {
    ValueInst*                   fCond;
    std::list<std::pair<int, BlockInst*> > fCode;

    SwitchInst(ValueInst* cond, const std::list<std::pair<int, BlockInst*> >& code) : fCond(cond), fCode(code) {}

    SwitchInst(ValueInst* cond) : fCond(cond) {}

    virtual ~SwitchInst() {}

    void addCase(int value, BlockInst* block) { fCode.push_back(std::make_pair(value, block)); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
