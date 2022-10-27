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

#include "patternmatcher/trans.hh"
#include "patternmatcher/state.hh"

namespace PM {

  void Trans::merge_trans_var(list<Trans>& trans, State* state)
  {
      if (!trans.begin()->is_var_trans()) {
          /* If we don't have a variable transition in this state yet then create a
             new one. */
          Trans tr(NULL);
          trans.push_front(tr);
      }
      list<Trans>::const_iterator t;
      Tree                        x;
      Node                        op(0);
      for (t = trans.begin(); t != trans.end(); t++) {
          if (t->is_var_trans())
              State::merge_state(t->state, state);
          else if (t->is_cst_trans(x)) {
              /* add the completion of the given state for a constant */
              State::merge_state(t->state, state);
          } else if (t->is_op_trans(op)) {
              /* add the completion of the given state for an arity>0 op */
              State* state1 = State::make_var_state(t->arity, state);
              State::merge_state(t->state, state1);
          }
      }
  }

  void Trans::merge_trans_cst(list<Trans>& trans, Tree x, State* state)
  {
      list<Trans>::iterator t0 = trans.begin(), t1 = t0, t;
      Tree                  x1;
      if (t0->is_var_trans()) t1++;
      for (t = t1; t != trans.end(); t++) {
          if (t->is_cst_trans(x1)) {
              if (x == x1) {
                  State::merge_state(t->state, state);
                  return;
              } else if (x < x1)
                  break;
          }
      }
      /* no matching transition has been found; add a new one */
      Trans tr(x);
      trans.insert(t, tr);
      t--;
      State* state1 = t->state;
      *state1       = *state;
      if (t1 != t0) {
          /* if we have a variable transition in the current state, we also need to
             merge its completion for the current symbol/constant */
          State::merge_state(state1, t0->state);
      }
  }

  void Trans::merge_trans_op(list<Trans>& trans, const Node& op, int arity, State* state)
  {
      /* analogous to merge_trans_cst above, but handles the arity>0 case */
      list<Trans>::iterator t0 = trans.begin(), t1 = t0, t;
      Node                  op1(0);
      if (t0->is_var_trans()) t1++;
      for (t = t1; t != trans.end(); t++) {
          if (t->is_op_trans(op1)) {
              if (op == op1) {
                  State::merge_state(t->state, state);
                  return;
              } else if (op.getSym() < op1.getSym())
                  break;
          }
      }
      Trans tr(op, arity);
      trans.insert(t, tr);
      t--;
      State* state1 = t->state;
      *state1       = *state;
      if (t1 != t0) {
          State* state2 = State::make_var_state(arity, t0->state);
          State::merge_state(state1, state2);
      }
  }

  void Trans::merge_trans(list<Trans>& trans1, list<Trans>& trans2)
  {
      Tree x;
      Node op(0);
      if (trans2.empty())
          ;
      else if (trans1.empty()) {
          list<Trans> cptrans2 = trans2;
          /* append a copy of trans2 to trans1 */
          trans1.splice(trans1.end(), cptrans2);
      } else if (trans2.begin()->is_var_trans())
          /* merge a variable transition */
          merge_trans_var(trans1, trans2.begin()->state);
      else if (trans2.begin()->is_cst_trans(x))
          /* merge a constant transition */
          merge_trans_cst(trans1, x, trans2.begin()->state);
      else if (trans2.begin()->is_op_trans(op))
          /* merge a BDA op transition */
          merge_trans_op(trans1, op, trans2.begin()->arity, trans2.begin()->state);
  }

  Trans::Trans(Tree _x) : x(_x), n(0), arity(0), state(new State)
  {
  }

  Trans::Trans(const Node& _n, int _arity) : x(NULL), n(_n), arity(_arity), state(new State)
  {
  }

  Trans::Trans(const Trans& trans) : x(trans.x), n(trans.n), arity(trans.arity)
  {
      state = new State(*trans.state);
  }

  Trans::~Trans()
  {
  }

  Trans& Trans::operator=(const Trans& trans)
  {
      x     = trans.x;
      n     = trans.n;
      arity = trans.arity;
      state = new State(*trans.state);
      return *this;
  }

  #ifdef DEBUG
  inline ostream& operator<<(ostream& s, const Trans& x)
  {
      return x.print(s);
  }
  ostream& Trans::print(ostream& fout) const
  {
      if (arity > 0)
          fout << "\top  " << n << ": state " << state->s << endl;
      else if (x == NULL)
          fout << "\tvar _: state " << state->s << endl;
      else
          fout << "\tcst " << *x << ": state " << state->s << endl;
      return fout;
  }
  #endif

}
