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

#ifndef __OPENCL_VECTOR_CODE_CONTAINER_HH__
#define __OPENCL_VECTOR_CODE_CONTAINER_HH__

#include "target/language/cpp/gpu/opencl/code_container.hh"

class CPPOpenCLVectorCodeContainer : public CPPOpenCLCodeContainer {
   public:
    CPPOpenCLVectorCodeContainer(const string& name, const string& super, int numInputs, int numOutputs,
                                 std::ostream* out)
        : CPPOpenCLCodeContainer(name, super, numInputs, numOutputs, out)
    {
    }

    void generateComputeKernel(int n);
};

#endif
