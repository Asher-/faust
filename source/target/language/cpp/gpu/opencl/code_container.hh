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

#ifndef __OPENCL_CODE_CONTAINER_HH__
#define __OPENCL_CODE_CONTAINER_HH__

#include "target/language/cpp/gpu/code_container.hh"

#include "target/language/cpp/gpu/opencl/visitor/control_instruction.hh"
#include "target/language/cpp/gpu/opencl/visitor/kernel_instruction.hh"
#include "target/language/cpp/gpu/opencl/visitor/block_kernel_instruction.hh"
#include "target/language/cpp/gpu/opencl/visitor/control_instruction.hh"
#include "target/language/cpp/gpu/opencl/visitor/dsp_instruction.hh"

class CPPOpenCLCodeContainer : public CPPGPUCodeContainer {
   public:
    CPPOpenCLCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out)
        : CPPGPUCodeContainer(name, super, numInputs, numOutputs, out)
    {
        fGPUOut             = new std::ostringstream();
        fKernelCodeProducer = new OpenCLKernelInstVisitor(fGPUOut, 0);
    }
    virtual ~CPPOpenCLCodeContainer() { delete fGPUOut; }

    void produceClass();
    void produceInternal();
    void generateCompute(int n);

    virtual void generateComputeKernel(int n);
};

#endif
