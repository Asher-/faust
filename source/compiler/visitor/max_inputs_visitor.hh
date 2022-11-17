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

#ifndef __FAUST_VISITORS_MAX_INPUTS__
#define __FAUST_VISITORS_MAX_INPUTS__

#include "signalVisitor.hh"

// Keep the maximum index of inputs signals
struct MaxInputsCounter : public SignalVisitor {
    int fMaxInputs = 0;

    MaxInputsCounter(Tree L)
    {
        // L is in normal form
        while (!isNil(L)) {
            self(hd(L));
            L = tl(L);
        }
    }

    void visit(Tree sig)
    {
        int input;
        if (isSigInput(sig, &input)) {
            fMaxInputs = std::max(fMaxInputs, input + 1);
        } else {
            SignalVisitor::visit(sig);
        }
    }
};

#endif
