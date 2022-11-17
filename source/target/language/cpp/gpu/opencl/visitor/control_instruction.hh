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

#ifndef __CPP_GPU_OPENCL_CONTROL_INSTRUCTION_VISITOR_HH__
#define __CPP_GPU_OPENCL_CONTROL_INSTRUCTION_VISITOR_HH__

#include "target/language/cpp/gpu/visitor/control_instruction.hh"

// To be used when generating GPU kernel string
struct ControlOpenCLInstVisitor : public ControlInstVisitor {
    // Code will be generated as a string
    virtual void tab1(int n, ostream& fout)
    {
        fout << "  \\n\"  \\\n";
        fout << "\"";
        while (n--) fout << '\t';
    }

    ControlOpenCLInstVisitor(std::ostream* out, int tab) : ControlInstVisitor(out, tab) {}
};


#endif
