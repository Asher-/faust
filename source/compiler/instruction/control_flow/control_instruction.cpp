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

#include "compiler/instruction/control_flow/control_instruction.hh"
#include <sstream>
#include "target/fir/fir_to_fir.hh"

bool ControlInst::hasCondition(ValueInst* cond)
{
    // Compare std::string representation of both conditions
    std::stringstream res1;
    std::stringstream res2;
    dump2FIR(fCond, res1, false);
    dump2FIR(cond, res2, false);
    return (res1.str() == res2.str());
}
