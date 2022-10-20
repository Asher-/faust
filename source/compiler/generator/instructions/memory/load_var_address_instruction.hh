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

#ifndef _LOAD_VAR_ADDRESS_INSTRUCTION_
#define _LOAD_VAR_ADDRESS_INSTRUCTION_

#include "instructions/value_instruction.hh"
#include "address/named_address.hh"

#include "visitors/instruction_visitor.hh"
#include "visitors/clone_visitor.hh"

struct LoadVarAddressInst : public ValueInst {
    Address* fAddress;

    LoadVarAddressInst(Address* address) : ValueInst(), fAddress(address) {}

    virtual ~LoadVarAddressInst() {}

    void   setName(const std::string& name) { fAddress->setName(name); }
    std::string getName() const { return fAddress->getName(); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    ValueInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    virtual bool isSimpleValue() const { return dynamic_cast<NamedAddress*>(fAddress); }
};

#endif
