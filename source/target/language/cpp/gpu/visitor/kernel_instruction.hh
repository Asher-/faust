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

#ifndef __CPP_GPU_CODE_CONTAINER_KERNEL_INSTRUCTION_VISITOR_HH__
#define __CPP_GPU_CODE_CONTAINER_KERNEL_INSTRUCTION_VISITOR_HH__

#include "target/language/cpp/visitor/instruction.hh"

// Control fields are preceded with "control->"
// Non-control fields are preceded with "dsp->"
struct KernelInstVisitor : public CPPInstVisitor {
    using CPPInstVisitor::visit;

    map<string, string> fFunctionTable;
    KernelInstVisitor(std::ostream* out, int tab) : CPPInstVisitor(out, tab) {}

    virtual void visit(LoadVarInst* inst)
    {
        NamedAddress*   named   = dynamic_cast<NamedAddress*>(inst->fAddress);
        IndexedAddress* indexed = dynamic_cast<IndexedAddress*>(inst->fAddress);

        // Special treatment for "fSampleRate" variable
        if (named && named->getName() == "fSampleRate") {
            named->setAccess(Address::kStruct);
        }

        if (named) {
            if (named->getAccess() == Address::kStruct) {
                *fOut << (isControl(named->getName()) ? "control->" : "dsp->") << named->getName();
            } else {
                *fOut << named->getName();
            }
        } else {
            if (indexed->getAccess() == Address::kStruct) {
                *fOut << (isControl(indexed->getName()) ? "control->" : "dsp->") << indexed->getName() << "[";
            } else {
                *fOut << indexed->getName() << "[";
            }
            indexed->getIndex()->accept(this);
            *fOut << "]";
        }
    }

    virtual void visit(LoadVarAddressInst* inst)
    {
        NamedAddress*   named   = dynamic_cast<NamedAddress*>(inst->fAddress);
        IndexedAddress* indexed = dynamic_cast<IndexedAddress*>(inst->fAddress);

        // Special treatment for "fSampleRate" variable
        if (named && named->getName() == "fSampleRate") {
            named->setAccess(Address::kStruct);
        }

        if (named) {
            if (named->getAccess() == Address::kStruct) {
                *fOut << (isControl(named->getName()) ? "&control->" : "&dsp->") << named->getName();
            } else {
                *fOut << "&" << named->getName();
            }
        } else {
            if (indexed->getAccess() == Address::kStruct) {
                *fOut << (isControl(indexed->getName()) ? "&control->" : "&dsp->") << indexed->getName() << "[";
            } else {
                *fOut << "&" << indexed->getName() << "[";
            }
            indexed->getIndex()->accept(this);
            *fOut << "]";
        }
    }

    virtual void visit(StoreVarInst* inst)
    {
        NamedAddress*   named   = dynamic_cast<NamedAddress*>(inst->fAddress);
        IndexedAddress* indexed = dynamic_cast<IndexedAddress*>(inst->fAddress);

        // Special treatment for "fSampleRate" variable
        if (named && named->getName() == "fSampleRate") {
            named->setAccess(Address::kStruct);
        }

        if (named) {
            if (named->getAccess() == Address::kStruct) {
                *fOut << (isControl(named->getName()) ? "control->" : "dsp->") << named->getName() << " = ";
            } else {
                *fOut << named->getName() << " = ";
            }
        } else {
            if (indexed->getAccess() == Address::kStruct) {
                *fOut << (isControl(indexed->getName()) ? "control->" : "dsp->") << indexed->getName() << "[";
            } else {
                *fOut << indexed->getName() << "[";
            }
            indexed->getIndex()->accept(this);
            *fOut << "] = ";
        }
        inst->fValue->accept(this);
        EndLine();
    }

    virtual void visit(FunCallInst* inst)
    {
        if (inst->fMethod) {
            ValuesIt it = inst->fArgs.begin();
            // Compile object arg
            (*it)->accept(this);
            *fOut << "->"
                  << ((fFunctionTable.find(inst->fName) != fFunctionTable.end()) ? fFunctionTable[inst->fName]
                                                                                 : inst->fName)
                  << "(";
            size_t size = inst->fArgs.size() - 1, i = 0;
            for (ValuesIt it1 = ++it; it1 != inst->fArgs.end(); it1++, i++) {
                // Compile argument
                (*it1)->accept(this);
                if (i < size - 1) *fOut << ", ";
            }
            *fOut << ")";
        } else {
            *fOut << ((fFunctionTable.find(inst->fName) != fFunctionTable.end()) ? fFunctionTable[inst->fName]
                                                                                 : inst->fName)
                  << "(";
            size_t size = inst->fArgs.size(), i = 0;
            for (ValuesIt it = inst->fArgs.begin(); it != inst->fArgs.end(); it++, i++) {
                // Compile argument
                (*it)->accept(this);
                if (i < size - 1) *fOut << ", ";
            }
            *fOut << ")";
        }
    }

    // C like cast
    virtual void visit(CastInst* inst)
    {
        *fOut << "(" << fTypeManager->generateType(inst->fType) << ")";
        inst->fInst->accept(this);
    }
};

#endif
