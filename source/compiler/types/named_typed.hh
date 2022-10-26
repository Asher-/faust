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

#ifndef _NAMED_TYPED_
#define _NAMED_TYPED_

#include "types/basic_typed.hh"
#include "types/typed.hh"

#include <string>
#include <vector>

struct NamedTyped : public Typed {

    enum Attribute { kDefault, kNoalias };
    static std::vector <std::string> AttributeMap;

    const std::string fName;
    Typed* fType;

    NamedTyped(const std::string& name, Typed* type) : fName(name), fType(type) {}

    virtual ~NamedTyped() {}

    VarType getType() const { return fType->getType(); }

    std::string getName() const { return fName; }

    int getSizeBytes() const { return fType->getSizeBytes(); }

    virtual void accept(InstVisitor* visitor) { visitor->visit(this); }

    Typed* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
