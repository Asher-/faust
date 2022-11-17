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

#ifndef __FAUST__STACK_2_STRUCT_REWRITER_1_HH__
#define __FAUST__STACK_2_STRUCT_REWRITER_1_HH__

#include <string>
#include <stack>

#include "compiler/visitor/dispatch_visitor.hh"
#include "compiler/type_manager/address/named_address.hh"

// Analysis to change stack access to struct access
struct Stack2StructRewriter1 : public DispatchVisitor {
    std::string fName;

    using DispatchVisitor::visit;

    void visit(NamedAddress* address)
    {
        if (address->fAccess == Address::kStack && address->fName.find(fName) != std::string::npos) {
            address->fAccess = Address::kStruct;
        }
    }

    Stack2StructRewriter1(const std::string& name) : fName(name) {}
};

#endif
