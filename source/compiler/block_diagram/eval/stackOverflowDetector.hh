
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

#ifndef __STACKOVERFLOWDETECTOR__
#define __STACKOVERFLOWDETECTOR__

/**
 * \file stackOverflowDetector.hh
 *
 * Detect evaluation loops
 *
 **/

#include "compiler/block_diagram/boxes/boxes.hh"

#define MAX_STACK_SIZE 1024 * 1024 * 16  // 16 MO
#define STACK_FRAME 65536 * 4

class stackOverflowDetector {
   private:
    long fMaxStackSize;

    bool  fFirstCall;
    void* fFirstStackAddress;

   public:
    stackOverflowDetector(long size) : fMaxStackSize(size), fFirstCall(true), fFirstStackAddress(nullptr) {}

    void detect();
};

#endif