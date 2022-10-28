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

#ifndef _ADD_BARGRAPH_INSTRUCTION_
#define _ADD_BARGRAPH_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"

struct AddBargraphInst : public StatementInst {
    enum BargraphType { kHorizontal, kVertical };

    const std::string       fLabel;
    const std::string       fZone;
    const double       fMin;
    const double       fMax;
    const BargraphType fType;

    AddBargraphInst(const std::string& label, const std::string& zone, double min, double max, BargraphType type)
        : fLabel(label), fZone(zone), fMin(min), fMax(max), fType(type)
    {
    }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
