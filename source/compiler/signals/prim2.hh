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

#ifndef _Prim2_
#define _Prim2_

#include "compiler/signals/sigtype.hh"
#include "tlib/tlib.hh"

// Foreign functions management functions (ffun) (external C functions)


bool isffunction(Tree t);


/**
 *  Return the arity of a foreign function
 *
 * @param  s - the signal
 * @return the name
 */
LIBFAUST_API int ffarity(Tree s);

int         ffrestype(Tree t);
int         ffargtype(Tree t, int i);
std::string ffincfile(Tree t);
std::string fflibfile(Tree t);

#endif
