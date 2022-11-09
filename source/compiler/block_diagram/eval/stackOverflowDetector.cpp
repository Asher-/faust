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

#include <cmath>

#include "compiler/errors/exception.hh"
#include "stackOverflowDetector.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"

void stackOverflowDetector::detect()
{
    int   stack       = 0;
    void* cur_address = &stack;
    if (fFirstCall) {
        fFirstCall         = false;
        fFirstStackAddress = cur_address;
    } else {
        long long current_stack_size = (long long)fFirstStackAddress - (long long)cur_address;
        if (std::abs(current_stack_size - fMaxStackSize) < STACK_FRAME) {
            throw faustexception("ERROR : stack overflow in eval\n");
        }
    }
}
