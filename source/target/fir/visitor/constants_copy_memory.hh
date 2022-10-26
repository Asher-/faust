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

#ifndef __FAUST_CONSTANTS_COPY_MEMORY_HH__
#define __FAUST_CONSTANTS_COPY_MEMORY_HH__

#include "visitor/basic_clone_visitor.hh"
#include "compiler/instruction/statement_instruction.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"
#include "instruction_builder.hh"

// Base class for iConst/fConst memory copy in -osX modes
struct ConstantsCopyMemory : public BasicCloneVisitor {

    int fIntIndex = 0;
    int fRealIndex = 0;

    ConstantsCopyMemory(int int_index, int float_index):fIntIndex(int_index), fRealIndex(float_index)
    {}

    StatementInst* visit(DeclareVarInst* inst)
    {
        return InstBuilder::genDropInst();
    }

};

#endif
