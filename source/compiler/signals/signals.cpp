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

/*****************************************************************************
    HISTORY
    22/01/05 : added int cast in select2 and select3 selection signal
*****************************************************************************/

#include <float.h>
#include <vector>

#include "global.hh"
#include "compiler/signals/ppsig.hh"
#include "compiler/signals/signals.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"
#include "faust/primitive/symbols/as_tree.hh"


////////////////////////////////////////////////////////////////////////
/**
 * Signals
 */
///////////////////////////////////////////////////////////////////////





//  "select3" expressed with "select2"


LIBFAUST_API bool isSigAssertBounds(Tree t, Tree& s1, Tree& s2, Tree& s3)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("sigAssertBounds"), s1, s2, s3);
}


LIBFAUST_API bool isSigHighest(Tree t, Tree& s)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("sigHighest"), s);
}


LIBFAUST_API bool isSigLowest(Tree t, Tree& s)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("sigLowest"), s);
}

// Arithmetical operations


static Tree sigExtended1(Tree sig, Tree x)
{
    tvec args;
    args.push_back(x);
    return (getUserData(sig))->computeSigOutput(args);
}

static Tree sigExtended2(Tree sig, Tree x, Tree y)
{
    tvec args;
    args.push_back(x);
    args.push_back(y);
    return (getUserData(sig))->computeSigOutput(args);
}


LIBFAUST_API Tree sigAbs(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().abs.box(), x);
}

LIBFAUST_API Tree sigAcos(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().acos.box(), x);
}

LIBFAUST_API Tree sigTan(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().tan.box(), x);
}

LIBFAUST_API Tree sigSqrt(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().sqrt.box(), x);
}

LIBFAUST_API Tree sigSin(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().sin.box(), x);
}

LIBFAUST_API Tree sigRint(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().rint.box(), x);
}

LIBFAUST_API Tree sigRemainder(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().remainder.box(), x, y);
}

LIBFAUST_API Tree sigPow(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().pow.box(), x, y);
}

LIBFAUST_API Tree sigMin(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().min.box(), x, y);
}

LIBFAUST_API Tree sigMax(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().max.box(), x, y);
}

LIBFAUST_API Tree sigLog(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().log.box(), x);
}

LIBFAUST_API Tree sigLog10(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().log10.box(), x);
}

LIBFAUST_API Tree sigFmod(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().fmod.box(), x, y);
}

LIBFAUST_API Tree sigFloor(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().floor.box(), x);
}

LIBFAUST_API Tree sigExp(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().exp.box(), x);
}

LIBFAUST_API Tree sigExp10(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().exp10.box(), x);
}

LIBFAUST_API Tree sigCos(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().cos.box(), x);
}

LIBFAUST_API Tree sigCeil(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().ceil.box(), x);
}

LIBFAUST_API Tree sigAtan(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().atan.box(), x);
}

LIBFAUST_API Tree sigAtan2(Tree x, Tree y)
{
    return sigExtended2(::Faust::Primitive::Math::functions().atan2.box(), x, y);
}

LIBFAUST_API Tree sigAsin(Tree x)
{
    return sigExtended1(::Faust::Primitive::Math::functions().asin.box(), x);
}


// New version using rec and ref


// Extended math functions

bool sameMagnitude(Tree a, Tree b)
{
    return sameMagnitude(a->node(), b->node());
}

Tree addNums(Tree a, Tree b)
{
    Tree r = tree(addNode(a->node(), b->node()));
    // cerr.flags(ios::showpoint); cerr << "addNums " << *a << "+" << *b << " -> " << *r << endl;
    return r;
}

Tree subNums(Tree a, Tree b)
{
    Tree r = tree(subNode(a->node(), b->node()));
    // cerr.flags(ios::showpoint); cerr << "subNums " << *a << "-" << *b << " -> " << *r << endl;
    return r;
}

Tree mulNums(Tree a, Tree b)
{
    Tree r = tree(mulNode(a->node(), b->node()));
    // cerr.flags(ios::showpoint); cerr << "mulNums " << *a << "*" << *b << " -> " << *r << endl;
    return r;
}

// Tree divNums(Tree a, Tree b)
//{
//	Tree r = tree(divNode(a->node(),b->node()));
//	//cerr.flags(ios::showpoint); cerr << "divNums " << *a << "/" << *b << " -> " << *r << endl;
//	return r;
//}

Tree divExtendedNums(Tree a, Tree b)
{
    // cerr.flags(ios::showpoint); cerr << "divExtendeNums " << *a << "/" << *b << " -> " << endl;
    Tree r = tree(divExtendedNode(a->node(), b->node()));
    // cerr.flags(ios::showpoint); cerr << "divExtendeNums " << *a << "/" << *b << " -> " << *r << endl;
    return r;
}

Tree minusNum(Tree a)
{
    Tree r = tree(minusNode(a->node()));
    // cerr.flags(ios::showpoint); cerr << "minusNum " << *a << " -> " << *r << endl;
    return r;
}

Tree inverseNum(Tree a)
{
    Tree r = tree(inverseNode(a->node()));
    // cerr.flags(ios::showpoint); cerr << "inverseNum " << *a << " -> " << *r << endl;
    return r;
}

bool isSigAdd(Tree a, Tree& x, Tree& y)
{
    int op;
    return isSigBinOp(a, &op, x, y) && (op == kAdd);
}

bool isSigMul(Tree a, Tree& x, Tree& y)
{
    int op;
    return isSigBinOp(a, &op, x, y) && (op == kMul);
}

bool isSigSub(Tree a, Tree& x, Tree& y)
{
    int op;
    return isSigBinOp(a, &op, x, y) && (op == kSub);
}

bool isSigDiv(Tree a, Tree& x, Tree& y)
{
    int op;
    return isSigBinOp(a, &op, x, y) && (op == kDiv);
}


/*****************************************************************************
                             matrix extension
*****************************************************************************/


bool isSigTupleAccess(Tree s, Tree& ts, Tree& idx)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigTupleAccess"), ts, idx);
}


/**
 * Test if exp is very simple that is it
 * can't be considered a real component
 * @param exp the signal we want to test
 * @return true if it a very simple signal
 */
bool verySimple(Tree exp)
{
    int    i;
    double r;
    Tree   type, name, file;

    return isSigInt(exp, &i) || isSigReal(exp, &r) || isSigInput(exp, &i) || isSigFConst(exp, type, name, file);
}


/*****************************************************************************
 *                          sigList2vectInt
 *****************************************************************************/
// Convert a list of signals (representing numbers) into a vector of ints
// the result is true if the conversion was possible

bool sigList2vecInt(Tree ls, vector<int>& v)
{
    int    i;
    double x;

    while (!isNil(ls)) {
        Tree s = hd(ls);
        ls     = tl(ls);
        if (isSigInt(s, &i)) {
            v.push_back(i);
        } else if (isSigReal(s, &x)) {
            v.push_back(int(x));
        } else {
            return false;
        }
    }
    return true;
}

/**
 * Convert an stl vector of signals into a tree list of signals
 */
Tree listConvert(const siglist& a)
{
    int  n = (int)a.size();
    Tree t = ::Faust::Primitive::Symbols::asTree().nil;

    while (n--) t = cons(a[n], t);
    return t;
}

/*
 * Convert a Tree in stl vector of signals
 */
siglist treeConvert(Tree t)
{
    siglist res;
    while (!isNil(t)) {
        res.push_back(hd(t));
        t = tl(t);
    }
    return res;
}
