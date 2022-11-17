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

#ifndef __STRUCT_INSTRUCTION_CLONE_VISITOR_HH__
#define __STRUCT_INSTRUCTION_CLONE_VISITOR_HH__

#include <string>
#include <utility>
#include <vector>

#include "compiler/instruction/instructions.hh"
#include "memory_description.hh"

/*
 Compute all field info, the DSP size, and separate 'int' and 'real' types
 */
struct StructInstVisitor : public DispatchVisitor {
    int        fStructIntOffset;    // Keep the int offset in bytes
    int        fStructRealOffset;   // Keep the real offset in bytes
    int        fFieldIndex;         // Keep the field index
    MemoryDesc fDefault;

    // Vector is used so that field names are ordered in 'getStructType'
    typedef vector<pair<std::string, MemoryDesc> > field_table_type;

    field_table_type fFieldTable;  // Table: field_name, MemoryDesc

    StructInstVisitor() : fStructIntOffset(0), fStructRealOffset(0), fFieldIndex(0) {}

    // Check if the field name exists
    bool hasField(const std::string& name, Typed::VarType& type)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) {
                type = field.second.fType;
                return true;
            }
        }
        return false;
    }

    // Return the offset of a given field in bytes
    int getFieldOffset(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fOffset;
        }
        std::cerr << "ERROR in getFieldOffset : " << name << std::endl;
        faustassert(false);
        return -1;
    }

    // Return the int offset of a given field in bytes
    int getFieldIntOffset(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fIntOffset;
        }
        std::cerr << "ERROR in getFieldIntOffset : " << name << std::endl;
        faustassert(false);
        return -1;
    }

    // Return the real offset of a given field in bytes
    int getFieldRealOffset(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fRealOffset;
        }
        std::cerr << "ERROR in getFieldRealOffset : " << name << std::endl;
        faustassert(false);
        return -1;
    }

    // Return the index of a given field
    int getFieldIndex(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fIndex;
        }
        std::cerr << "ERROR in getFieldIndex : " << name << std::endl;
        faustassert(false);
        return -1;
    }

    // Return the FIR type of a given field
    Typed::VarType getFieldType(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fType;
        }
        std::cerr << "ERROR in getFieldType : " << name << std::endl;
        faustassert(false);
        return Typed::kNoType;
    }

    // Return the memory type of a given field
    MemoryDesc::memType getFieldMemoryType(const std::string& name)
    {
        for (const auto& field : fFieldTable) {
            if (field.first == name) return field.second.fMemType;
        }
        std::cerr << "ERROR in getFieldMemoryType : " << name << std::endl;
        faustassert(false);
        return MemoryDesc::kLocal;
    }

    // Return the memory description of a given field
    MemoryDesc& getMemoryDesc(const std::string& name)
    {
        for (auto& field : fFieldTable) {
            if (field.first == name) return field.second;
        }
        return fDefault;
    }

    // Return the struct 'int' size in bytes
    int getStructIntSize() { return fStructIntOffset; }

    // Return the struct 'real' size in bytes
    int getStructRealSize() { return fStructRealOffset; }

    // Return the struct size in bytes
    int getStructSize() { return fStructIntOffset + fStructRealOffset; }

    field_table_type& getFieldTable() { return fFieldTable; }

    int getArrayCount()
    {
        int res = 0;
        for (const auto& field : fFieldTable) {
            if (field.second.fSize > 1) res++;
        }
        return res;
    }

    // Return the struct type
    DeclareStructTypeInst* getStructType(const std::string& name)
    {
        vector<NamedTyped*> dsp_type_fields;
        for (auto& field : fFieldTable) {
            dsp_type_fields.push_back(InstBuilder::genNamedTyped(field.first, field.second.getTyped()));
        }
        return InstBuilder::genDeclareStructTypeInst(InstBuilder::genStructTyped(name, dsp_type_fields));
    }

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
                fFieldTable.push_back(std::make_pair(name, MemoryDesc(fFieldIndex++,
                                                                 getStructSize(),
                                                                 getStructIntSize(),
                                                                 getStructRealSize(),
                                                                 array_typed->fSize,
                                                                 array_typed->getSizeBytes(),
                                                                 type)));
                if (type == Typed::kInt32) {
                    fStructIntOffset += array_typed->getSizeBytes();
                } else {
                    fStructRealOffset += array_typed->getSizeBytes();
                }
            } else {
                // Should never happen...
                faustassert(false);
            }
        } else {
            if (is_struct) {
                fFieldTable.push_back(std::make_pair(name, MemoryDesc(fFieldIndex++,
                                                                 getStructSize(),
                                                                 getStructIntSize(),
                                                                 getStructRealSize(),
                                                                 1,
                                                                 inst->fType->getSizeBytes(),
                                                                 inst->fType->getType())));
                if (inst->fType->getType() == Typed::kInt32) {
                    fStructIntOffset += inst->fType->getSizeBytes();
                } else {
                    fStructRealOffset += inst->fType->getSizeBytes();
                }
            }
        }

        if (inst->fValue) getMemoryDesc(inst->getName()).fWAccessCount++;
        DispatchVisitor::visit(inst);
    }

    void visit(LoadVarInst* inst)
    {
        getMemoryDesc(inst->getName()).fRAccessCount++;
        DispatchVisitor::visit(inst);
    }

    void visit(StoreVarInst* inst)
    {
        getMemoryDesc(inst->getName()).fWAccessCount++;
        DispatchVisitor::visit(inst);
    }

};
