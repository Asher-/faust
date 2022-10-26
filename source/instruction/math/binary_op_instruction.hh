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

#ifndef _BINARY_OP_INSTRUCTION_
#define _BINARY_OP_INSTRUCTION_

#include "instruction/value_instruction.hh"

struct BinopInst : public ValueInst {
    const int  fOpcode;
    ValueInst* fInst1;
    ValueInst* fInst2;

    BinopInst(int opcode, ValueInst* inst1, ValueInst* inst2)
        : ValueInst(), fOpcode(opcode), fInst1(inst1), fInst2(inst2)
    {
    }

    virtual ~BinopInst() {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    ValueInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    virtual int size() const { return fInst1->size() + fInst2->size(); }
};

#endif
