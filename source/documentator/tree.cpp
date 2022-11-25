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

#include <vector>
#include "documentator/tree.hh"

/*****************************************************************************
                    Types of Documentation Elements
 *****************************************************************************/

///< Contains <mdoc> parsed trees: DOCTXT, DOCEQN, DOCDGM
std::vector<Tree>& docVector()
{
  static std::vector<Tree> doc_vector{};
  return doc_vector;
}

void declareDoc(Tree t)
{
	docVector().push_back(t);
}

Tree docTxt(const char* name)
{
    return tree(
      ::Faust::Primitive::Symbols::internal().symbol("DocTxt"),
      tree(::Faust::Primitive::Symbols::runtime().insert(name, false))
    );
}
bool isDocTxt(Tree t)
{
    return t->node() == Node(::Faust::Primitive::Symbols::internal().symbol("DocTxt"));
}
bool isDocTxt(Tree t0, const char** str)
{
    Tree t1;
    Sym  s{nullptr};
    if (isTree(t0, ::Faust::Primitive::Symbols::internal().symbol("DocTxt"), t1) && isSym(t1->node(), &s)) {
        *str = s->name().c_str();
        return true;
    } else {
        return false;
    }
}

Tree docEqn(Tree x)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("DocEqn"), x);
}
bool isDocEqn(Tree t, Tree& x)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("DocEqn"), x);
}

Tree docDgm(Tree x)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("DocDgm"), x);
}
bool isDocDgm(Tree t, Tree& x)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("DocDgm"), x);
}

Tree docNtc()
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("DocNtc"));
}
bool isDocNtc(Tree t)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("DocNtc"));
}

Tree docLst()
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("DocLst"));
}
bool isDocLst(Tree t)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("DocLst"));
}

Tree docMtd(Tree x)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("DocMtd"), x);
}
