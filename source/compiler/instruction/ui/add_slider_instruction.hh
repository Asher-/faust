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

#ifndef _ADD_SLIDER_INSTRUCTION_
#define _ADD_SLIDER_INSTRUCTION_

#include "compiler/instruction/statement/statement_instruction.hh"

struct AddSliderInst : public StatementInst {
    enum SliderType { kHorizontal, kVertical, kNumEntry };

    const std::string     fLabel;
    const std::string     fZone;
    const double     fInit;
    const double     fMin;
    const double     fMax;
    const double     fStep;
    const SliderType fType;

    AddSliderInst(const std::string& label, const std::string& zone, double init, double min, double max, double step,
                  SliderType type)
        : fLabel(label), fZone(zone), fInit(init), fMin(min), fMax(max), fStep(step), fType(type)
    {
    }

    void accept(InstVisitor* visitor) { visitor->visit(this); }

    StatementInst* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
