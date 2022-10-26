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

#ifndef __CPP_GPU_CODE_CONTAINER_CONTROL_INSTRUCTION_VISITOR_HH__
#define __CPP_GPU_CODE_CONTAINER_CONTROL_INSTRUCTION_VISITOR_HH__

#include "target/language/cpp/visitor/instruction.hh"

// Visitor that only generates control fields
struct ControlInstVisitor : public CPPInstVisitor {
    ControlInstVisitor(std::ostream* out, int tab) : CPPInstVisitor(out, tab) {}

    virtual void visit(DeclareVarInst* inst)
    {
        if (isControl(inst->fAddress->getName())) {
            tab(fTab, *fOut);
            *fOut << fTypeManager->generateType(inst->fType, inst->fAddress->getName()) << ";";
        }
    }
};


#endif
