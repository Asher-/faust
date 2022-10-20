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

#include "instructions/loops/simple_for_loop_instruction.hh"

#include "instruction_builder.hh"

SimpleForLoopInst::SimpleForLoopInst(const std::string& name, ValueInst* upperBound, ValueInst* lowerBound, bool reverse, BlockInst* code)
: fUpperBound(upperBound), fLowerBound(lowerBound), fName(name), fReverse(reverse), fCode(code)
{
    // Define the loop variable in order to have it correctly typed when checking in FIRChecker
    fInit = InstBuilder::genDecLoopVar(name, InstBuilder::genInt32Typed(), InstBuilder::genInt32NumInst(0));
}
