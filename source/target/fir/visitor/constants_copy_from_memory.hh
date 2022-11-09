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

#ifndef __FAUST_CONSTANTS_COPY_FROM_MEMORY_HH__
#define __FAUST_CONSTANTS_COPY_FROM_MEMORY_HH__

#include "constants_copy_memory.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/memory/store_var_instruction.hh"
#include "compiler/type_manager/address/address.hh"
#include "compiler/instruction_compiler/instruction_builder.hh"
#include "compiler/visitor/basic_clone_visitor.hh"
#include "target/fir/fir_index.hh"

// Analysis to copy constants from an external memory zone (FunArgs version) used in -os2 and -os3 modes
struct ConstantsCopyFromMemory : public ConstantsCopyMemory {

    ConstantsCopyFromMemory(int int_index, int float_index):ConstantsCopyMemory(int_index, float_index)
    {}

    StatementInst* visit(StoreVarInst* inst)
    override
    {
        string name = inst->fAddress->getName();
        bool is_struct = inst->fAddress->getAccess() & Address::kStruct;
        if (startWith(name, "iConst") && is_struct) {
            ValueInst* zone = InstBuilder::genLoadArrayFunArgsVar("iZone", FIRIndex(fIntIndex++));
            return InstBuilder::genStoreVarInst(inst->fAddress->clone(this), zone);
        } else if (startWith(name, "fConst") && is_struct) {
            ValueInst* zone = InstBuilder::genLoadArrayFunArgsVar("fZone", FIRIndex(fRealIndex++));
            return InstBuilder::genStoreVarInst(inst->fAddress->clone(this), zone);
        } else if (name == "fSampleRate") {
            return BasicCloneVisitor::visit(inst);
        } else {
            return InstBuilder::genDropInst();
        }
    }

};

#endif
