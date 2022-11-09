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

#ifndef __STRUCT_INSTRUCTION_CLONE_VISITOR_1_HH__
#define __STRUCT_INSTRUCTION_CLONE_VISITOR_1_HH__

#include "compiler/visitor/struct_instruction_visitor.hh"

/*
 A version that separates some of the fields for the iZone/fZone model
 and keep the others in the DSP struct:
    - small arrays (size < fDLThreshold) are allocated in the DSP struct
    - first generated big arrays are moved in iZone/fZone, until fExternalMemory reaches 0
    - then other big arrays are kept in the DSP struct
*/
struct StructInstVisitor1 : public StructInstVisitor {

    int fExternalMemory;
    int fDLThreshold;

    // To be computed with DSP struct size and FAUST_MAX_SIZE
    StructInstVisitor1(int external_memory, int dl_threshold = 4)
    : StructInstVisitor(), fExternalMemory(external_memory), fDLThreshold(dl_threshold)
    {}

    // Declarations
    void visit(DeclareVarInst* inst)
    {
        string              name   = inst->fAddress->getName();
        Address::AccessType access = inst->fAddress->getAccess();

        bool        is_struct   = (access & Address::kStruct) || (access & Address::kStaticStruct);
        ArrayTyped* array_typed = dynamic_cast<ArrayTyped*>(inst->fType);

        if (array_typed && array_typed->fSize > 1) {
            Typed::VarType type = array_typed->fType->getType();
            if (is_struct) {
                // Arrays are allocated in iZone/fZone until fExternalMemory reaches 0
                // kStaticStruct are always allocated in kExternal
                if ((access & Address::kStaticStruct) || (fExternalMemory > 0 && array_typed->fSize > fDLThreshold)) {
                    fFieldTable.push_back(std::make_pair(name, MemoryDesc(fFieldIndex++,
                                                                     getStructSize(),
                                                                     getStructIntSize(),
                                                                     getStructRealSize(),
                                                                     array_typed->fSize,
                                                                     array_typed->getSizeBytes(),
                                                                     type,
                                                                     MemoryDesc::kExternal)));

                    if (type == Typed::kInt32) {
                        fStructIntOffset += array_typed->getSizeBytes();
                    } else {
                        fStructRealOffset += array_typed->getSizeBytes();
                    }
                    fExternalMemory -= array_typed->getSizeBytes();
                } else {
                    // Keep arrays in local struct memory
                    fFieldTable.push_back(std::make_pair(name, MemoryDesc(fFieldIndex++,
                                                                     getStructSize(),
                                                                     getStructIntSize(),
                                                                     getStructRealSize(),
                                                                     array_typed->fSize,
                                                                     array_typed->getSizeBytes(),
                                                                     type,
                                                                     MemoryDesc::kLocal)));
                }
            } else {
                // Should never happen...
                faustassert(false);
            }
        } else {
            if (is_struct) {
                // Scalar variable always stay in local struct memory
                fFieldTable.push_back(std::make_pair(name, MemoryDesc(fFieldIndex++,
                                                                 getStructSize(),
                                                                 getStructIntSize(),
                                                                 getStructRealSize(),
                                                                 1,
                                                                 inst->fType->getSizeBytes(),
                                                                 inst->fType->getType(),
                                                                 MemoryDesc::kLocal)));
            }
        }

        if (inst->fValue) getMemoryDesc(inst->getName()).fWAccessCount++;
        DispatchVisitor::visit(inst);
    }

};

#endif
