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

#ifndef __FAUST_VARIABLE_SIZE_COUNTER_HH__
#define __FAUST_VARIABLE_SIZE_COUNTER_HH__

#include "compiler/visitor/dispatch_visitor.hh"
#include "compiler/type_manager/address/named_address.hh"

// Compute the size in bytes of variables of a given type
struct VariableSizeCounter : public DispatchVisitor {

    int                 fSizeBytes;
    Typed::VarType      fType;
    Address::AccessType fAccess;

    VariableSizeCounter(Address::AccessType access, Typed::VarType type = Typed::kNoType)
    {
        fSizeBytes = 0;
        fType      = type;
        fAccess    = access;
    }

    virtual void visit(DeclareVarInst* inst)
    {
        DispatchVisitor::visit(inst);

        if (((fType == Typed::kNoType) || (inst->fType->getType() == fType)) && inst->fAddress->getAccess() | fAccess) {
            fSizeBytes += inst->fType->getSizeBytes();
        }
    }
};

#endif
