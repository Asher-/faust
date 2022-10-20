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

#ifndef _INDEXED_ADDRESS_
#define _INDEXED_ADDRESS_

#include "address.hh"
#include "instructions/value_instruction.hh"
#include <vector>
#include <string>

#include "visitors/instruction_visitor.hh"
#include "visitors/clone_visitor.hh"

struct IndexedAddress : public Address {
    Address*   fAddress;
    std::vector<ValueInst*> fIndices;

    IndexedAddress(Address* address, ValueInst* index) : fAddress(address)
    {
        fIndices.push_back(index);
    }

    IndexedAddress(Address* address, const std::vector<ValueInst*>& indices) : fAddress(address), fIndices(indices)
    {}

    virtual ~IndexedAddress() {}

    void                setAccess(Address::AccessType type) { fAddress->setAccess(type); }
    Address::AccessType getAccess() const { return fAddress->getAccess(); }

    void   setName(const std::string& name) { fAddress->setName(name); }
    std::string getName() const { return fAddress->getName(); }

    ValueInst* getIndex(int index = 0) const { return fIndices[index]; }
    std::vector<ValueInst*> getIndices() const { return fIndices; }

    Address* clone(CloneVisitor* cloner) { return cloner->visit(this); }

    void accept(InstVisitor* visitor) { visitor->visit(this); }
};

#endif
