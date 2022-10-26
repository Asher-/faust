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

#ifndef __CPP_GPU_CODE_CONTAINER_VISITOR_UI_INSTRUCTION_HH__
#define __CPP_GPU_CODE_CONTAINER_VISITOR_UI_INSTRUCTION_HH__

#include "target/language/cpp/visitor/instruction.hh"

// To access control inside fControl field
struct UIInstVisitor : public CPPInstVisitor {
    UIInstVisitor(std::ostream* out, int tab) : CPPInstVisitor(out, tab) {}

    virtual void visit(AddMetaDeclareInst* inst)
    {
        *fOut << "interface->declare("
              << "&fHostControl->" << inst->fZone << ", "
              << "\"" << inst->fKey << "\""
              << ", "
              << "\"" << inst->fValue << "\""
              << ")";
        EndLine();
    }

    virtual void visit(AddButtonInst* inst)
    {
        if (inst->fType == AddButtonInst::kDefaultButton) {
            *fOut << "interface->addButton("
                  << "\"" << inst->fLabel << "\""
                  << ","
                  << "&fHostControl->" << inst->fZone << ")";
            EndLine();
        } else {
            *fOut << "interface->addCheckButton("
                  << "\"" << inst->fLabel << "\""
                  << ","
                  << "&fHostControl->" << inst->fZone << ")";
            EndLine();
        }
    }

    virtual void visit(AddSliderInst* inst)
    {
        string name;
        switch (inst->fType) {
            case AddSliderInst::kHorizontal:
                name = "interface->addHorizontalSlider";
                break;
            case AddSliderInst::kVertical:
                name = "interface->addVerticalSlider";
                break;
            case AddSliderInst::kNumEntry:
                name = "interface->addNumEntry";
                break;
        }
        *fOut << name << "("
              << "\"" << inst->fLabel << "\""
              << ", "
              << "&fHostControl->" << inst->fZone << ", " << checkReal(inst->fInit) << ", " << checkReal(inst->fMin)
              << ", " << checkReal(inst->fMax) << ", " << checkReal(inst->fStep) << ")";
        EndLine();
    }

    virtual void visit(AddBargraphInst* inst)
    {
        string name;
        switch (inst->fType) {
            case AddBargraphInst::kHorizontal:
                name = "interface->addHorizontalBargraph";
                break;
            case AddBargraphInst::kVertical:
                name = "interface->addVerticalBargraph";
                break;
        }
        *fOut << name << "("
              << "\"" << inst->fLabel << "\""
              << ", "
              << "&fHostControl->" << inst->fZone << ", " << checkReal(inst->fMin) << ", " << checkReal(inst->fMax)
              << ")";
        EndLine();
    }
};

#endif
