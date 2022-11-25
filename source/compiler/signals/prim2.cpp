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

#include <stdlib.h>

#include "compiler/signals/prim2.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

bool isffunction(Tree t)
{
    return t->node() == Node(::Faust::Primitive::Symbols::internal().symbol("ForeignFunction"));
}

std::string ffincfile(Tree ff)
{
    return tree2str(ff->branch(1));
}

std::string fflibfile(Tree ff)
{
    return tree2str(ff->branch(2));
}

int ffrestype(Tree t)
{
    return tree2int(hd(ffsignature(t)));
}


int ffarity(Tree t)
{
    return len(ffsignature(t)) - 2;
}

int ffargtype(Tree t, int i)
{
    return tree2int(nth(ffsignature(t), i + 2));
}
