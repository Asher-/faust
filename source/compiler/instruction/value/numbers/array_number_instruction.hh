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

#ifndef _ARRAY_NUMBER_INSTRUCTION_
#define _ARRAY_NUMBER_INSTRUCTION_

#include "compiler/instruction/value/value_instruction.hh"
#include <vector>

template <class TYPE>
struct ArrayNumInst : public ValueInst {
    std::vector<TYPE> fNumTable;

    ArrayNumInst(const std::vector<TYPE>& nums) : ValueInst(), fNumTable(nums) {}

    ArrayNumInst(int size) : ValueInst() { fNumTable.resize(size); }

    void setValue(int index, TYPE num) { fNumTable[index] = num; }
    TYPE getValue(int index) { return fNumTable[index]; }
    void addValue(TYPE num) { fNumTable.push_back(num); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    virtual bool isSimpleValue() const { return true; }
};

#endif
