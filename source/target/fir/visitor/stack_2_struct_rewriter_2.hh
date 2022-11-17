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

#ifndef __FAUST__STACK_2_STRUCT_REWRITER_2_HH__
#define __FAUST__STACK_2_STRUCT_REWRITER_2_HH__

#include <stack>
#include <string>

#include "compiler/visitor/dispatch_visitor.hh"
#include "compiler/type_manager/address/named_address.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"
#include "target/code_container.hh"

// Analysis to promote stack variables to struct variables
struct Stack2StructRewriter2 : public DispatchVisitor {
    CodeContainer* fContainer;
    std::string         fName;

    using DispatchVisitor::visit;

    void visit(DeclareVarInst* inst)
    {
        BasicCloneVisitor cloner;
        std::string            name = inst->fAddress->getName();

        if (inst->fAddress->getAccess() == Address::kStack && name.find(fName) != std::string::npos) {
            // Variable moved to the Struct
            fContainer->pushDeclare(InstBuilder::genDecStructVar(name, inst->fType->clone(&cloner)));

            // For local thread access (in compute):
            // - rewrite the Declare instruction by a Store and put in Init section
            // - rewrite value access
            if (inst->fValue) {
                // Rewrite value access before cloning it
                Stack2StructRewriter1 rewriter(name);
                inst->fValue->accept(&rewriter);
                fContainer->pushInitMethod(InstBuilder::genStoreStructVar(name, inst->fValue->clone(&cloner)));
            }

            // Mark inst to be removed
            inst->fAddress->setAccess(Address::kLink);
        }

        // Then dispatch and possibly rewrite 'value' access
        DispatchVisitor::visit(inst);
    }

    void visit(NamedAddress* address)
    {
        if (address->fAccess == Address::kStack && address->fName.find(fName) != std::string::npos) {
            address->fAccess = Address::kStruct;
        }
    }

    Stack2StructRewriter2(CodeContainer* container, const std::string& name) : fContainer(container), fName(name) {}
};
#endif
