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

#include "compiler/instruction/statement/block_instruction.hh"
#include "compiler/instruction/control_flow/return_instruction.hh"
#include "instruction_builder.hh"

bool BlockInst::hasReturn() const
{
    std::list<StatementInst*>::const_iterator it = fCode.end();
    it--;
    return dynamic_cast<RetInst*>(*it);
}

// Return the block value (if is has one) and remove it from the block
ValueInst* BlockInst::getReturnValue()
{
    std::list<StatementInst*>::const_iterator it = fCode.end();
    it--;
    RetInst* ret = dynamic_cast<RetInst*>(*it);
    if (ret) {
        fCode.pop_back();
        return ret->fResult;
    } else {
        return InstBuilder::genNullValueInst();
    }
}
