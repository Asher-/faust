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

#include "patternmatcher/state.hh"
#include "patternmatcher/is_box_pattern_op.hh"

namespace PM {

  /* Construction algorithm for the pattern matching automaton.
   *
   * We employ the incremental technique described in Graef: Left-To-Right Tree
   * Pattern Matching, Proc. RTA 1991, Springer 1991 (LNCS 488) to construct a
   * tree automaton (TA) for the given patterns. The basic outline of the
   * technique is as follows. Initially, the automaton is empty. From each
   * pattern we produce a trie (considering the pattern as a string of variable
   * and function symbols and constants). This trie is then merged with the TA
   * obtained so far. The latter process is similar to merging two deterministic
   * finite automata, but it also takes into account the variables (see the
   * merge_state() routine below).
   */

  /* Construct a trie from a term tree. Takes the "start" and returns the "end"
     state of the (sub-)trie. */
  State* State::make_state(State* state, int r, Tree x, Path& p)
  {
      Tree id, x0, x1;
      Node op(0);
      if (isBoxPatternVar(x, id)) {
          /* variable */
          Rule rule(r, id, p);
          state->rules.push_back(rule);
          Trans trans(NULL);
          state->trans.push_back(trans);
          return state->trans.begin()->state;
      } else if (isBoxPatternOp(x, op, x0, x1)) {
          /* composite pattern */
          Rule rule(r, NULL);
          state->rules.push_back(rule);
          Trans trans(op, 2);
          state->trans.push_back(trans);
          State* next = state->trans.begin()->state;
          p.push_back(0);
          next = make_state(next, r, x0, p);
          p.pop_back();
          p.push_back(1);
          next = make_state(next, r, x1, p);
          p.pop_back();
          return next;
      } else {
          /* constant */
          Rule rule(r, NULL);
          state->rules.push_back(rule);
          Trans trans(x);
          state->trans.push_back(trans);
          return state->trans.begin()->state;
      }
  }

  /* Take a copy of a state and prefix it with n variable transitions. */

  State* State::make_var_state(int n, State* state)
  {
      if (n <= 0) return new State(*state);
      list<Rule>           rules = state->rules;
      list<Rule>::iterator r;
      for (r = rules.begin(); r != rules.end(); r++) {
          r->id = NULL;
          r->p  = Path();
      }
      State* prefix = new State, *current = prefix;
      while (n-- > 0) {
          current->rules = rules;
          Trans trans(NULL);
          current->trans.push_back(trans);
          current = current->trans.begin()->state;
      }
      *current = *state;
      return prefix;
  }

  void State::merge_state(State* state1, State* state2)
  {
      Rule::merge_rules(state1->rules, state2->rules);
      Trans::merge_trans(state1->trans, state2->trans);
  }

  #ifdef DEBUG
  inline ostream& operator<<(ostream& s, const State& x)
  {
      return x.print(s);
  }
  ostream& State::print(ostream& fout) const
  {
      fout << "state " << s << ":";
      list<Rule>::const_iterator r;
      for (r = rules.begin(); r != rules.end(); r++) fout << " " << *r;
      fout << endl;
      list<Trans>::const_iterator t;
      for (t = trans.begin(); t != trans.end(); t++) fout << *t;
      return fout;
  }
  #endif

}
