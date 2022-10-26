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

#include "compiler/instruction/declarations/declare_var_instruction.hh"
#include "global.hh"
#include "fir_to_fir.hh"

void DeclareVarInst::cleanup()
{
    gGlobal->gVarTypeTable.clear();
}

// Variable types are kept in the global name <===> type table
DeclareVarInst::DeclareVarInst(Address* address, Typed* type, ValueInst* value)
    : fAddress(address), fType(type), fValue(value)
{
    if (gGlobal->gVarTypeTable.find(fAddress->getName()) == gGlobal->gVarTypeTable.end()) {
        gGlobal->gVarTypeTable[fAddress->getName()] = type;
    } else if (gGlobal->gVarTypeTable[fAddress->getName()] != type) {
        // If named type, check their name and internal type
        NamedTyped* name_t1 = dynamic_cast<NamedTyped*>(gGlobal->gVarTypeTable[fAddress->getName()]);
        NamedTyped* name_t2 = dynamic_cast<NamedTyped*>(type);
        if (name_t1 && name_t2) {
            faustassert(name_t1->fName == name_t2->fName && name_t1->fType == name_t2->fType);
        } else {
            // If array type, check their size and internal type
            ArrayTyped* array_t1 = dynamic_cast<ArrayTyped*>(gGlobal->gVarTypeTable[fAddress->getName()]);
            ArrayTyped* array_t2 = dynamic_cast<ArrayTyped*>(type);
            if (array_t1 && array_t2) {
                // Arrays have the exact same size
                bool same_size = array_t1->fSize == array_t2->fSize;
                // Or not but one of them is actually a pointer
                bool compatible_size = (array_t1->fSize != array_t2->fSize)
                    && array_t1->fType == array_t2->fType
                    && (array_t1->fSize == 0 || array_t2->fSize == 0);
                bool same_type = array_t1->fType == array_t2->fType;
                faustassert((same_size && same_type) || compatible_size);
            } else {
                dump2FIR(address);
                dump2FIR(type);
                faustassert(false);
            }
        }
    }
}

struct StoreVarInst* DeclareVarInst::store(ValueInst* exp)
{
    return InstBuilder::genStoreVarInst(fAddress, exp);
}

struct LoadVarInst* DeclareVarInst::load()
{
    return InstBuilder::genLoadVarInst(fAddress);
}
