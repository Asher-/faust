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

#ifndef _ARRAY_INT32_NUMBER_INSTRUCTION_
#define _ARRAY_INT32_NUMBER_INSTRUCTION_

#include "instructions/numbers/array_number_instruction.hh"
#include <vector>

struct Int32ArrayNumInst : public ArrayNumInst<int> {
    Int32ArrayNumInst(const std::vector<int>& nums) : ArrayNumInst<int>(nums) {}
    Int32ArrayNumInst(int size) : ArrayNumInst<int>(size) {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    ValueInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
