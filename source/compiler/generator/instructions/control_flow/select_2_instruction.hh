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

#ifndef _SELECT_2_INSTRUCTION_
#define _SELECT_2_INSTRUCTION_

#include "instructions/value_instruction.hh"
#include "instructions/declarations.hh"

struct Select2Inst : public ValueInst {
    ValueInst* fCond;
    ValueInst* fThen;
    ValueInst* fElse;

    Select2Inst(ValueInst* cond_inst, ValueInst* then_inst, ValueInst* else_inst)
        : ValueInst(), fCond(cond_inst), fThen(then_inst), fElse(else_inst)
    {
    }

    virtual ~Select2Inst() {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    ValueInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    virtual int size() const { return std::max(fThen->size(), fElse->size()); }
};

#endif
