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

#ifndef __LOOP_CLONE_VISITOR_HH__
#define __LOOP_CLONE_VISITOR_HH__

#include <string>
#include <list>

#include "named_address.hh"
#include "instruction_builder.hh"
#include "visitor/basic_clone_visitor.hh"

// Change the status of all variables used in function parameter list
struct LoopCloneVisitor : public BasicCloneVisitor {
    std::list<std::string>& fAddedVarTable;

    LoopCloneVisitor(std::list<std::string>& table) : fAddedVarTable(table) {}

    virtual Address* visit(NamedAddress* address)
    {
        if (find(fAddedVarTable.begin(), fAddedVarTable.end(), address->fName) != fAddedVarTable.end()) {
            return InstBuilder::genNamedAddress(address->fName, Address::kFunArgs);
        } else {
            return BasicCloneVisitor::visit(address);
        }
    }
};

#endif
