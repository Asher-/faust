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

#ifndef __FAUST__PRIMITIVE__AS_TREE__HH__
#define __FAUST__PRIMITIVE__AS_TREE__HH__

#include "faust/primitive/symbols.hh"
#include "tlib/tree.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbols {

      struct AsTree
      {
        Tree BOXTYPEPROP      = tree(::Faust::Primitive::Symbols::internal().symbol("boxTypeProp"));
        Tree NUMERICPROPERTY  = tree(::Faust::Primitive::Symbols::internal().symbol("NUMERICPROPERTY"));
        Tree SIMPLIFIED       = tree(::Faust::Primitive::Symbols::internal().symbol("sigSimplifiedProp"));
        Tree DOCTABLES        = tree(::Faust::Primitive::Symbols::internal().symbol("DocTablesProp"));
        Tree NULLENV          = tree(::Faust::Primitive::Symbols::internal().symbol("NullRenameEnv"));
        Tree COLORPROPERTY    = tree(::Faust::Primitive::Symbols::internal().symbol("ColorProperty"));
        Tree ORDERPROP        = tree(::Faust::Primitive::Symbols::internal().symbol("OrderProp"));
        Tree RECURSIVNESS     = tree(::Faust::Primitive::Symbols::internal().symbol("RecursivnessProp"));
        Tree NULLTYPEENV      = tree(::Faust::Primitive::Symbols::internal().symbol("NullTypeEnv"));
        Tree RECDEF           = tree(::Faust::Primitive::Symbols::internal().symbol("RECDEF"));
        Tree DEBRUIJN2SYM     = tree(::Faust::Primitive::Symbols::internal().symbol("deBruijn2Sym"));
        Tree NORMALFORM       = tree(::Faust::Primitive::Symbols::internal().symbol("NormalForm"));
        Tree DEFNAMEPROPERTY  = tree(::Faust::Primitive::Symbols::internal().symbol("DEFNAMEPROPERTY"));
        Tree NICKNAMEPROPERTY = tree(::Faust::Primitive::Symbols::internal().symbol("NICKNAMEPROPERTY"));
        Tree BCOMPLEXITY      = tree(::Faust::Primitive::Symbols::internal().symbol("BCOMPLEXITY"));
        Tree RECURSIVEBODY    = tree(::Faust::Primitive::Symbols::internal().symbol("RECURSIVEBODY"));
        Tree LETRECBODY       = tree(::Faust::Primitive::Symbols::internal().symbol("BoxIdent"), RECURSIVEBODY);
        Tree nil              = tree(::Faust::Primitive::Symbols::internal().symbol("nil"));

      };

      AsTree& asTree();

    };
  };
};

#endif

