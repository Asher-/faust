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

#ifndef _VECTOR_TYPED_
#define _VECTOR_TYPED_

#include "compiler/types/basic_typed.hh"
#include "compiler/types/typed.hh"

struct VectorTyped : public Typed {
    BasicTyped* fType;
    const int  fSize;

    VectorTyped(BasicTyped* type, int size) : fType(type), fSize(size) {}

    virtual ~VectorTyped() {}

    VarType getType() const { return getVecFromType(fType->getType()); }

    int getSizeBytes() const { return fType->getSizeBytes() * fSize; }

    virtual void accept(InstVisitor* visitor) { visitor->visit(this); }

    Typed* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
