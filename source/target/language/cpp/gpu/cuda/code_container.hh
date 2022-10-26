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

#ifndef __CUDA_CODE_CONTAINER_HH__
#define __CUDA_CODE_CONTAINER_HH__

#include "target/language/cpp/gpu/code_container.hh"
#include "target/language/cpp/gpu/cuda/visitor/kernel_instruction.hh"
#include "target/language/cpp/gpu/cuda/visitor/block_kernel_instruction.hh"

class CPPCUDACodeContainer : public CPPGPUCodeContainer {
   public:
    CPPCUDACodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out)
        : CPPGPUCodeContainer(name, super, numInputs, numOutputs, out)
    {
        string filename     = gGlobal->gOutputFile + ".cu";
        fGPUOut             = new std::ofstream(filename.c_str());
        fKernelCodeProducer = new CUDAKernelInstVisitor(fGPUOut, 0);
        fNumInputs          = numInputs;
        fNumOutputs         = numOutputs;
    }
    virtual ~CPPCUDACodeContainer() { delete fGPUOut; }

    void produceClass();
    void generateCompute(int tab);
    void produceInternal();

    virtual void generateComputeKernelGlue(int n);
    virtual void generateInstanceInitKernelGlue(int n);
    virtual void generateComputeKernel(int n);
};

#endif
