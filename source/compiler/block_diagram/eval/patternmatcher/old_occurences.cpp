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
#include <iostream>
#include <algorithm>

#include "global.hh"
#include "old_occurences.hh"
#include "recursivness.hh"
#include "compiler/signals/sigtyperules.hh"

#include "faust/primitive/symbols.hh"

#include "faust/primitive/type/priority.hh"

using Priority = ::Faust::Primitive::Type::Priority;

using namespace std;

/**
 * Extended Variability with recursiveness indication
 */
static Priority xVariability(
  const Priority& priority,
  int recursiveness
) {
    // cerr << "xVariability (" << v << ", " <<  r << ")" << endl;
    // faustassert(v < 3);				// Priority::Konst=0, Priority::Block=1, Priority::Samp=2
    // faustassert(r==0 | v==2);
    if (recursiveness > 1)
      recursiveness = 1;
    return Priority(std::min<int>(3, static_cast<unsigned int>(priority) + recursiveness));
}

//-------------------------------------------------
//	Occurences methods
//-------------------------------------------------

int old_Occurences::getOccurence( const Priority& priority) const
{
    return fOccurences[static_cast<unsigned int>(priority)];
}

old_Occurences::old_Occurences(
  const Priority& priority,
  const int& recursiveness,
  Tree xc
) :
  fXVariability(xVariability(priority, recursiveness))
{
    for (int i = 0; i < 4; i++) fOccurences[i] = 0;
    fMultiOcc      = false;
    fOutDelayOcc   = false;
    fMinDelay      = 0;
    fMaxDelay      = 0;
    fExecCondition = xc;
}

old_Occurences* old_Occurences::incOccurences(
  const Priority& priority,
  const int& recursiveness,
  const int& delay,
  Tree xc
) {
    const Priority ctxt = xVariability(priority, recursiveness);
    // assert (ctxt >= fXVariability);
    fOccurences[static_cast<unsigned int>(ctxt)] += 1;
    fMultiOcc = fMultiOcc | (ctxt > fXVariability) | (fOccurences[static_cast<unsigned int>(ctxt)] > 1);
    if (delay == 0) {
        // cerr << "Occurence outside a delay " << endl;
        fOutDelayOcc = true;
    }
    if (delay > fMaxDelay) {
        // cerr << "Max delay : " << fMaxDelay << " <- " << d << endl;
        fMaxDelay = delay;
    }

    // check if used in different execution conditions
    if (fExecCondition != xc) {
        fMultiOcc = true;
    }
    return this;
}

bool old_Occurences::hasMultiOccurences() const
{
    return fMultiOcc;
}

bool old_Occurences::hasOutDelayOccurences() const
{
    return fOutDelayOcc;
}

int old_Occurences::getMaxDelay() const
{
    return fMaxDelay;
}

Tree old_Occurences::getExecCondition() const
{
    return fExecCondition;
}

//--------------------------------------------------
//	Mark and retrieve occurences of subtrees of root
//--------------------------------------------------

void old_OccMarkup::mark(Tree root)
{
    fRootTree = root;
    fPropKey  = tree(::Faust::Primitive::Symbols::runtime().unique("OCCURRENCES"));

    if (isList(root)) {
        while (isList(root)) {
            // incOcc(Priority::Samp, 1, hd(root));
            incOcc(global::config().nil, Priority::Samp, 0, 0, global::config().nil, hd(root));
            root = tl(root);
        }
        // cerr << "END OF LIST IS " << *root << endl;
    } else {
        // incOcc(Priority::Samp, 1, root);
        incOcc(global::config().nil, Priority::Samp, 0, 0, global::config().nil, root);
    }
}

old_Occurences* old_OccMarkup::retrieve(Tree t)
{
    return getOcc(t);
}

//------------------------------------------------------------------------------
// Increment the occurences of t within context v,r,d,xc and proceed recursively
// xc : exec condition expression
//------------------------------------------------------------------------------

void old_OccMarkup::incOcc(
  Tree env,
  const Priority& priority,
  const int& recursiveness,
  const int& delay,
  Tree xc, Tree t
) {
    // Check if we have already visited this tree
    old_Occurences* occ = getOcc(t);

    if (occ == 0) {
        // 1) We build initial occurence information
        Type ty = getCertifiedSigType(t);
        const Priority&  v0 = ty->priority();
        int  r0 = getRecursivness(t);
        // fConditions may have been initialized empty
        Tree c0 = (fConditions.find(t) == fConditions.end()) ? global::config().nil : fConditions[t];        
        occ     = new old_Occurences(v0, r0, c0);
        setOcc(t, occ);

        // We mark the subtrees of t
        Tree x, y;
        if (isSigDelay(t, x, y)) {
            Type g2 = getCertifiedSigType(y);
            int  d2 = checkDelayInterval(g2);
            faustassert(d2 >= 0);
            incOcc(env, v0, r0, d2, c0, x);
            incOcc(env, v0, r0, 0, c0, y);
        } else if (isSigPrefix(t, y, x)) {
            incOcc(env, v0, r0, 1, c0, x);
            incOcc(env, v0, r0, 0, c0, y);
        } else {
            vector<Tree> br;
            int          n = getSubSignals(t, br);
            if (n > 0 && !isSigGen(t)) {
                for (int i = 0; i < n; i++) incOcc(env, v0, r0, 0, c0, br[i]);
            }
        }
    }

    occ->incOccurences(
      priority,
      recursiveness,
      delay,
      xc
    );
}

old_Occurences* old_OccMarkup::getOcc(Tree t)
{
    Tree p = t->getProperty(fPropKey);
    if (p) {
        return (old_Occurences*)tree2ptr(p);
    } else {
        return 0;
    }
}

void old_OccMarkup::setOcc(Tree t, old_Occurences* occ)
{
    t->setProperty(fPropKey, tree(occ));
}

#if 0

/**
 * return the position of a signal in the current recursive environment
 * @param env the current recursive environment of the signal
 * @param t signal we want to know the position
 * @return the position in the recursive environment
 */
static int position(Tree env, Tree t, int p)
{
	if (isNil(env)) return 0;	// was not in the environment
	if (hd(env) == t) return p;
	else return position(tl(env), t, p+1);
}
#endif
