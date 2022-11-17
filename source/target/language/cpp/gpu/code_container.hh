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

#ifndef _CPP_GPU_CODE_CONTAINER_H
#define _CPP_GPU_CODE_CONTAINER_H

#include "target/language/cpp/code_container.hh"
#include "global.hh"
#include "target/language/cpp/gpu/visitor/kernel_instruction.hh"
#include "target/language/cpp/gpu/visitor/ui_instruction.hh"

struct CPPOpenCLCodeContainer;

class CPPGPUCodeContainer : public CPPCodeContainer {
    void prepareFIR(void);

   protected:

    KernelInstVisitor* fKernelCodeProducer;
    std::ostream*      fGPUOut;

   public:
    CPPGPUCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out)
        : CPPCodeContainer(name, super, numInputs, numOutputs, out)
    {
        fNumInputs  = numInputs;
        fNumOutputs = numOutputs;
    }

    virtual ~CPPGPUCodeContainer() {}
};

#endif
