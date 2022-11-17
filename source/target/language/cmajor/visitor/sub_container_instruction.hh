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

#ifndef __SOUL_VISITOR_SUB_CONTAINER_INSTRUCTION_HH__
#define __SOUL_VISITOR_SUB_CONTAINER_INSTRUCTION_HH__

#include "target/language/soul/visitor/instruction.hh"

// For subcontainers: variable access is specific
class SOULSubContainerInstVisitor : public SOULInstVisitor {
   public:
    SOULSubContainerInstVisitor(std::ostream* out, int tab = 0) : SOULInstVisitor(out, tab) {}

    virtual void visit(NamedAddress* named)
    {
        if (named->getAccess() & Address::kStruct) {
            *fOut << "this.";
        }
        *fOut << named->fName;
    }
};

#endif
