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

#ifndef _SIGNALS_
#define _SIGNALS_

#include <vector>

#include "faust/export.h"

#include "compiler/signals/binop.hh"
#include "compiler/errors/exception.hh"
#include "tlib/tlib.hh"

#include "compiler/signals/tree.hh"

using namespace std;

#if defined(WIN32) && !defined(__GNUC__)
#pragma warning(disable : 4800)
#endif

////////////////////////////////////////////////////////////////////////
/**
 * Signals
 * Block-diagrams are converted into signal expressions via
 * symbolic propagation
 */
///////////////////////////////////////////////////////////////////////

typedef std::vector<Tree> siglist;

// Constant signals : for all t, x(t)=n


// Int and Double casting





// Selectors


LIBFAUST_API bool isSigAssertBounds(Tree t, Tree& s1, Tree& s2, Tree& s3);
LIBFAUST_API bool isSigLowest(Tree t, Tree& s);
LIBFAUST_API bool isSigHighest(Tree t, Tree& s);



// Pattern matching for old fonctions
bool isSigAdd(Tree a, Tree& x, Tree& y);
bool isSigMul(Tree a, Tree& x, Tree& y);
bool isSigSub(Tree a, Tree& x, Tree& y);
bool isSigDiv(Tree a, Tree& x, Tree& y);

// Operations on tree representing numbers
bool sameMagnitude(Tree a, Tree b);

Tree addNums(Tree a, Tree b);
Tree subNums(Tree a, Tree b);
Tree mulNums(Tree a, Tree b);
Tree divExtendedNums(Tree a, Tree b);
Tree minusNum(Tree a);
Tree inverseNum(Tree a);

// Tests on constant signals
inline bool isNum(Tree a)
{
    faustassert(a);
    return isNum(a->node());
}
inline bool isZero(Tree a)
{
    faustassert(a);
    return isZero(a->node());
}
inline bool isGTZero(Tree a)
{
    faustassert(a);
    return isGTZero(a->node());
}
inline bool isGEZero(Tree a)
{
    faustassert(a);
    return isGEZero(a->node());
}
inline bool isOne(Tree a)
{
    faustassert(a);
    return isOne(a->node());
}
inline bool isMinusOne(Tree a)
{
    faustassert(a);
    return isMinusOne(a->node());
}

// Extended math functions
LIBFAUST_API Tree sigAbs(Tree x);
LIBFAUST_API Tree sigAcos(Tree x);
LIBFAUST_API Tree sigTan(Tree x);
LIBFAUST_API Tree sigSqrt(Tree x);
LIBFAUST_API Tree sigSin(Tree x);
LIBFAUST_API Tree sigRint(Tree x);
LIBFAUST_API Tree sigRemainder(Tree x, Tree y);
LIBFAUST_API Tree sigPow(Tree x, Tree y);
LIBFAUST_API Tree sigMin(Tree x, Tree y);
LIBFAUST_API Tree sigMax(Tree x, Tree y);
LIBFAUST_API Tree sigLog(Tree x);
LIBFAUST_API Tree sigLog10(Tree x);
LIBFAUST_API Tree sigFmod(Tree x, Tree y);
LIBFAUST_API Tree sigFloor(Tree x);
LIBFAUST_API Tree sigExp(Tree x);
LIBFAUST_API Tree sigExp10(Tree x);
LIBFAUST_API Tree sigCos(Tree x);
LIBFAUST_API Tree sigCeil(Tree x);
LIBFAUST_API Tree sigAtan(Tree x);
LIBFAUST_API Tree sigAtan2(Tree x, Tree y);
LIBFAUST_API Tree sigAsin(Tree x);


inline bool isNum(const Tree& t, num& n)
{
    double f;
    int    i;

    if (isDouble(t->node(), &f)) {
        n = f;
        return true;
    }
    if (isInt(t->node(), &i)) {
        n = i;
        return true;
    }
    return false;
}



/*****************************************************************************
                             matrix extension
*****************************************************************************/

// A tuple of signals is basically a list of signals.
// mode = 0 means normal, mode = 1 means blocked
Tree sigTuple(int mode, Tree ls);
LIBFAUST_API bool isSigTuple(Tree s, int* mode, Tree& ls);

// Access the components of a tuple.
// ts is tuple of signals, idx is a scalar signal between 0..n
Tree sigTupleAccess(Tree ts, Tree idx);
LIBFAUST_API bool isSigTupleAccess(Tree s, Tree& ts, Tree& idx);

// Create a tuple of signals
Tree sigCartesianProd(Tree s1, Tree s2);

/*****************************************************************************
                             FTZ wrapping
    Add FTZ wrapping to a signal
*****************************************************************************/

Tree sigFTZ(Tree s);

/*****************************************************************************
                             Access to sub signals of a signal
*****************************************************************************/

int getSubSignals(Tree sig, tvec& vsigs, bool visitgen = true);

/**
 * Test if exp is very simple that is it
 * can't be considered a real component
 * @param exp the signal we want to test
 * @return true if it a very simple signal
 */
bool verySimple(Tree exp);

bool sigList2vecInt(Tree ls, vector<int>& v);

/**
 * Convert an stl vector of signals into a tree list of signals
 */
Tree listConvert(const siglist& a);

/**
 * Convert a Tree in stl vector of signals
 */
siglist treeConvert(Tree t);

#endif
