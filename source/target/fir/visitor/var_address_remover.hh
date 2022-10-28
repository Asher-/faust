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

#ifndef __FAUST_VAR_ADDRESS_REMOVER_HH__
#define __FAUST_VAR_ADDRESS_REMOVER_HH__

#include "visitor/basic_clone_visitor.hh"
#include "instruction_builder.hh"
#include "named_address.hh"
#include "indexed_address.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/memory/load_var_address_instruction.hh"
#include "compiler/instruction/value/value_instruction.hh"

/*

  Remove usage of var address:
  int* v1 = &foo[n]; ==> v1 definition is removed, usage of v1[m] are replaced with foo[n+m]
  v1 = &foo[n];      ==> usage of v1[m] are replaced with foo[n+m]
 */
struct VarAddressRemover : public BasicCloneVisitor {

    std::map<std::string, LoadVarAddressInst*> fVariableMap;

    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        LoadVarAddressInst* var_address = dynamic_cast<LoadVarAddressInst*>(inst->fValue);
        if (var_address) {
            fVariableMap[inst->fAddress->getName()] = var_address;
            return InstBuilder::genNullStatementInst();
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

    virtual StatementInst* visit(StoreVarInst* inst)
    {
        LoadVarAddressInst* var_address = dynamic_cast<LoadVarAddressInst*>(inst->fValue);
        if (var_address) {
            fVariableMap[inst->fAddress->getName()] = var_address;
            return InstBuilder::genNullStatementInst();
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

    virtual Address* visit(IndexedAddress* address)
    {
        if (fVariableMap.find(address->getName()) != fVariableMap.end()) {
            IndexedAddress* id_add1 = dynamic_cast<IndexedAddress*>(fVariableMap[address->getName()]->fAddress);
            IndexedAddress* id_add2 = dynamic_cast<IndexedAddress*>(address);
            faustassert(id_add2);
            faustassert(id_add1);
            ValueInst* id1 = id_add1->getIndex();
            ValueInst* id2 = id_add2->getIndex();
            return InstBuilder::genIndexedAddress(id_add1->fAddress->clone(this),
                                                  InstBuilder::genAdd(id1->clone(this), id2->clone(this)));
        } else {
            return BasicCloneVisitor::visit(address);
        }
    }

};

#endif
