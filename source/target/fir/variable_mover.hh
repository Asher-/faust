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

#ifndef __FAUST__VARIABLE_MOVER_HH__
#define __FAUST__VARIABLE_MOVER_HH__

#include "compiler/visitor/stack_2_struct_rewriter_1.hh"
#include "compiler/visitor/stack_2_struct_rewriter_2.hh"

struct VariableMover {
    static void Move(CodeContainer* container, const std::string& name)
    {
        // Transform stack variables in struct variables
        Stack2StructRewriter2 rewriter2(container, name);
        container->generateComputeBlock(&rewriter2);

        // Rewrite variable access stack ==> struct
        Stack2StructRewriter1 rewriter1(name);
        container->transformDAG(&rewriter1);
    }
};

#endif
