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

#ifndef __CPP_GPU_OPENCL_BLOCK_KERNEL_INSTRUCTION_VISITOR_HH__
#define __CPP_GPU_OPENCL_BLOCK_KERNEL_INSTRUCTION_VISITOR_HH__

// Add __local keyword for stack variables
struct BlockKernelInstVisitor : public KernelInstVisitor {
    using KernelInstVisitor::visit;

    // Code will be generated as a string
    virtual void tab1(int n, ostream& fout)
    {
        fout << "  \\n\"  \\\n";
        fout << "\"";
        while (n--) fout << '\t';
    }

    BlockKernelInstVisitor(std::ostream* out, int tab) : KernelInstVisitor(out, tab) {}

    virtual void visit(DeclareVarInst* inst)
    {
        /*
        if (inst->fAddress->getAccess() & Address::kGlobal) {
            if (global::config().gSymbolGlobalsTable.find(inst->fAddress->getName()) == global::config().gSymbolGlobalsTable.end())
            {
                // If global is not defined
                global::config().gSymbolGlobalsTable[inst->fAddress->getName()] = 1;
            } else {
                return;
            }
        }
        */

        if (inst->fAddress->getAccess() & Address::kStaticStruct) {
            *fOut << "static ";
        }

        if (inst->fAddress->getAccess() & Address::kVolatile) {
            *fOut << "volatile ";
        }

        if (inst->fAddress->getAccess() & Address::kStack) {
            *fOut << "__local ";
        }

        *fOut << fTypeManager->generateType(inst->fType, inst->fAddress->getName());
        if (inst->fValue) {
            *fOut << " = ";
            inst->fValue->accept(this);
        }
        EndLine();
    }
};

#endif
