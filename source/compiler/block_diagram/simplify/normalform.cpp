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

#include <stdio.h>
#include <map>

#include "global.hh"
#include "tlib/tree.hh"
#include "compiler/signals/ppsig.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"
#include "simplify.hh"
#include "sigPromotion.hh"
#include "compiler/signals/sigtyperules.hh"
#include "timing.hh"

#include "faust/primitive/symbols/as_tree.hh"

// Implementation
static Tree simplifyToNormalFormAux(Tree LS)
{
    // Convert deBruijn recursion into symbolic recursion
    startTiming("deBruijn2Sym");
    Tree L1 = deBruijn2Sym(LS);
    endTiming("deBruijn2Sym");
    
    // Annotate L1 with type information
    startTiming("L1 typeAnnotation");
    typeAnnotation(L1, global::config().gLocalCausalityCheck);
    endTiming("L1 typeAnnotation");
    
    if (global::config().gCheckTable) {
        // Generate safe access to rdtable/rwtable
        startTiming("Safe access to rdtable/rwtable");
        L1 = signalTablePromote(L1);
        endTiming("Safe access to rdtable/rwtable");
        
        // Annotate L1 with type information
        startTiming("L1 typeAnnotation");
        typeAnnotation(L1, global::config().gLocalCausalityCheck);
        endTiming("L1 typeAnnotation");
    }
    
    if (global::config().gRangeUI) {
        // Generate safe values for range UI items (sliders and nentry)
        startTiming("Safe access to rdtable/rwtable");
        L1 = signalUIPromote(L1);
        endTiming("Safe access to rdtable/rwtable");
        
        // Annotate L1 with type information
        startTiming("L1 typeAnnotation");
        typeAnnotation(L1, global::config().gLocalCausalityCheck);
        endTiming("L1 typeAnnotation");
    }
    
    // Needed before 'simplify' (see sigPromotion.hh)
    startTiming("Cast and Promotion");
    Tree L2 = sigPromote(L1);
    endTiming("Cast and Promotion");
    
    // Simplify by executing every computable operation
    startTiming("L2 simplification");
    Tree L3 = simplify(L2);
    endTiming("L2 simplification");
    
    // Annotate L3 with type information
    startTiming("L3 typeAnnotation");
    typeAnnotation(L3, global::config().gLocalCausalityCheck);
    endTiming("L3 typeAnnotation");
    
    startTiming("Cast and Promotion");
    Tree L4 = sigPromote(L3);
    endTiming("Cast and Promotion");
    
    startTiming("L4 typeAnnotation");
    typeAnnotation(L4, global::config().gLocalCausalityCheck);
    endTiming("L4 typeAnnotation");
     
    // Check signal tree
    SignalTreeChecker checker(L4);
    return L4;
}

// Public API
LIBFAUST_API Tree simplifyToNormalForm(Tree t)
{
    if (isList(t)) {
        Tree t2 = t->getProperty(::Faust::Primitive::Symbols::asTree().NORMALFORM);
        if (!t2) {
            t2 = simplifyToNormalFormAux(t);
            t->setProperty(::Faust::Primitive::Symbols::asTree().NORMALFORM, t2);
        }
        return t2;
    } else {
        return simplifyToNormalForm(cons(t, ::Faust::Primitive::Symbols::asTree().nil));
    }
}

LIBFAUST_API tvec simplifyToNormalForm2(tvec siglist)
{
    return treeConvert(simplifyToNormalForm(listConvert(siglist)));
}

LIBFAUST_API string printSignal(Tree sig, bool shared)
{
    // Clear print state
    global::config().clear();
    stringstream str;
    if (shared) {
        ppsigShared(sig, str);
    } else {
        str << ppsig(sig) << endl;
    }
    return str.str();
}

LIBFAUST_API string printBox(Tree box, bool shared)
{
    // Clear print state
    global::config().clear();
    stringstream str;
    if (shared) {
        boxppShared(box, str);
    } else {
        str << boxpp(box) << endl;
    }
    return str.str();
}
