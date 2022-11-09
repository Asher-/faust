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

/* Deconstruct a (BDA) op pattern (YO). */

#ifndef _IS_BOX_PATTERN_OP_
#define _IS_BOX_PATTERN_OP_

#include "compiler/block_diagram/boxes/boxes.hh"

inline bool isBoxPatternOp(Tree box, Node& n, Tree& t1, Tree& t2)
{
    if ( isBoxPar(box, t1, t2)
      || isBoxSeq(box, t1, t2)
      || isBoxSplit(box, t1, t2)
      || isBoxMerge(box, t1, t2)
      || isBoxHGroup(box, t1, t2)
      || isBoxVGroup(box, t1, t2)
      || isBoxTGroup(box, t1, t2)
      || isBoxRec(box, t1, t2)) {
        n = box->node();
        return true;
    }
    else {
        return false;
    }
}

#endif
