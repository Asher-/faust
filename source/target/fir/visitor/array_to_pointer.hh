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

#ifndef __FAUST_ARRAY_TO_POINTER_HH__
#define __FAUST_ARRAY_TO_POINTER_HH__

#include "compiler/instruction_compiler/instruction_builder.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/visitor/basic_clone_visitor.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"

// Rewrite DSP array fields as pointers
struct ArrayToPointer : public BasicCloneVisitor {

    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        ArrayTyped* array_typed = dynamic_cast<ArrayTyped*>(inst->fType);
        if (array_typed) {
            return InstBuilder::genDecStructVar(inst->getName(), InstBuilder::genArrayTyped(array_typed->fType->clone(this), 0));
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

};

#endif
