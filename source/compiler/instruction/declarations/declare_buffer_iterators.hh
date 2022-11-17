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

#ifndef _DECLARE_BUFFER_ITERATORS_INSTRUCTION_
#define _DECLARE_BUFFER_ITERATORS_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/types/typed.hh"

struct DeclareBufferIterators : public StatementInst {
    std::string fBufferName1;
    std::string fBufferName2;
    int         fChannels;
    Typed*      fType;
    bool        fMutable;

    DeclareBufferIterators(const std::string& name1, const std::string& name2, int channels, Typed* type, bool mut);

    virtual ~DeclareBufferIterators() {}

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
