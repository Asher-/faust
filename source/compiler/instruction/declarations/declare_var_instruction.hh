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

#ifndef _DECLARE_VAR_INSTRUCTION_
#define _DECLARE_VAR_INSTRUCTION_

#include "address.hh"

#include "compiler/instruction/statement_instruction.hh"
#include "compiler/instruction/value_instruction.hh"
#include "compiler/instruction/memory/store_var_instruction.hh"
#include "compiler/instruction/memory/load_var_instruction.hh"
#include "types/typed.hh"
#include "types/named_typed.hh"
#include "types/array_typed.hh"

struct DeclareVarInst : public StatementInst {
    Address*   fAddress;
    Typed*     fType;
    ValueInst* fValue;

    static void cleanup();

    DeclareVarInst(Address* address, Typed* typed, ValueInst* value);

    virtual ~DeclareVarInst() {}

    void                setAccess(Address::AccessType type) { fAddress->setAccess(type); }
    Address::AccessType getAccess() const  { return fAddress->getAccess(); }

    void   setName(const std::string& name) { fAddress->setName(name); }
    std::string getName() const { return fAddress->getName(); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    struct StoreVarInst* store(ValueInst* val);
    struct LoadVarInst*  load();
};

#endif
