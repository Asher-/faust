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

#ifndef __PATTERNMATCHER__TRANS__
#define __PATTERNMATCHER__TRANS__

#include <list>

#include "tlib/tree.hh"
#include "tlib/node.hh"
#include "garbageable.hh"

namespace PM {

  struct State;

  struct Trans : public virtual Garbageable {
      Tree   x;      // symbol or constant (NULL for variable)
      Node   n;      // operator symbol (if arity>0)
      int    arity;  // symbol arity
      State* state;  // successor state

      static void merge_trans_var(list<Trans>& trans, State* state);
      static void merge_trans_cst(list<Trans>& trans, Tree x, State* state);
      static void merge_trans_op(list<Trans>& trans, const Node& op, int arity, State* state);
      static void merge_trans(list<Trans>& trans1, list<Trans>& trans2);

      Trans(Tree _x);
      Trans(const Node& _n, int _arity);
      Trans(const Trans& trans);
      ~Trans();

      Trans& operator=(const Trans& trans);

      bool is_var_trans() const { return arity == 0 && x == NULL; }
      bool is_cst_trans(Tree& _x) const
      {
          _x = x;
          return arity == 0 && x != NULL;
      }
      bool is_op_trans(Node& _n) const
      {
          _n = n;
          return arity > 0;
      }

      bool operator==(const Trans& trans) const { return arity == trans.arity && x == trans.x && n == trans.n; }
      bool operator<(const Trans& trans) const
      {
          return (arity < trans.arity)
                     ? 1
                     : (arity > trans.arity) ? 0 : (arity == 0) ? (x < trans.x) : (n.getSym() < trans.n.getSym());
      }

  #ifdef DEBUG
      ostream& print(ostream& fout) const;
  #endif
  };

}

#endif
