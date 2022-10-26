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

#ifndef __CUDA_VECTOR_CODE_CONTAINER_HH__
#define __CUDA_VECTOR_CODE_CONTAINER_HH__

#include "target/language/cpp/gpu/cuda/code_container.hh"

class CPPCUDAVectorCodeContainer : public CPPCUDACodeContainer {
   protected:
   public:
    CPPCUDAVectorCodeContainer(const string& name, const string& super, int numInputs, int numOutputs,
                               std::ostream* out)
        : CPPCUDACodeContainer(name, super, numInputs, numOutputs, out)
    {
    }
    virtual ~CPPCUDAVectorCodeContainer() {}

    void generateComputeKernelGlue(int n);
    void generateInstanceInitKernelGlue(int n);
    void generateComputeKernel(int n);
};
#endif
