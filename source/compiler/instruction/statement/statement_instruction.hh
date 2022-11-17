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

#ifndef _STATEMENT_INSTRUCTION_
#define _STATEMENT_INSTRUCTION_

#include <string>
#include "compiler/types/printable.hh"

struct InstVisitor; // Cyclic reference
struct CloneVisitor; // Cyclic reference

// Statement added in the compilation block
struct StatementInst : public Printable {
    virtual void accept(InstVisitor* visitor) = 0;

    virtual StatementInst* clone(CloneVisitor* cloner) = 0;

    virtual std::string getName() const { return ""; }
};

#endif
