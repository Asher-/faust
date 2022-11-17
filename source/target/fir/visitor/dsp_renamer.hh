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

#ifndef __FAUST__DSP_RENAMER_HH__
#define __FAUST__DSP_RENAMER_HH__

#include "compiler/visitor/basic_clone_visitor.hh"
#include "compiler/type_manager/address/named_address.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"
#include "compiler/instruction_compiler/instruction_builder.hh"

// ========================================
// Used in WebAssembly and Interp backends
// ========================================

/*
 For subcontainers table generation : rename 'sig' in 'dsp' and remove 'dsp' allocation.
*/

struct DspRenamer : public BasicCloneVisitor {
    DspRenamer() {}

    // Change access
    virtual Address* visit(NamedAddress* named)
    {
        if (startWith(named->getName(), "sig")) {
            return InstBuilder::genNamedAddress("dsp", named->fAccess);
        } else {
            return BasicCloneVisitor::visit(named);
        }
    }

    // Remove allocation
    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        if (startWith(inst->fAddress->getName(), "sig")) {
            return InstBuilder::genDropInst();
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

};

#endif
