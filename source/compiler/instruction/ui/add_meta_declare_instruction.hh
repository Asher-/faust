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

#ifndef _ADD_META_DECLARE_INSTRUCTION_
#define _ADD_META_DECLARE_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/visitor/instruction_visitor.hh"

struct AddMetaDeclareInst : public StatementInst {
    const std::string fZone;
    const std::string fKey;
    const std::string fValue;

    AddMetaDeclareInst(const std::string& zone, const std::string& key, const std::string& value)
        : fZone(zone), fKey(key), fValue(value)
    {
    }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
