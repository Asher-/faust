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

#ifndef __OCCURRENCES__
#define __OCCURRENCES__

#include "compiler/type_manager/garbageable.hh"
#include "tlib/tlib.hh"

/**
 * Count subtree occurences
 * Count the number of occurences of each subtree of a root tree.
 */

class Occurrences : public virtual Garbageable {
    Tree fKey;  // specific property key

   public:
    Occurrences(Tree root);  // count the occurrences of each subtree of root
    virtual int getCount(Tree t);    // return the number of occurrences of t in root

   private:
    virtual Tree specificKey(Tree root);    // specific key for occurences counting in root
    virtual void countOccurrences(Tree t);  // increment the occurrences of t and its subtrees
    virtual void setCount(Tree t, int c);   // set the number of occurrences of t
};

#endif
