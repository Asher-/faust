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

#ifndef __PATTERNMATCHER__STATE__
#define __PATTERNMATCHER__STATE__

#include <list>

#include "patternmatcher/rule.hh"
#include "patternmatcher/trans.hh"

#include "tlib/tree.hh"

#include "tlib/list.hh"
#include "compiler/type_manager/garbageable.hh"

namespace PM {

  struct State : public virtual Garbageable {
      int         s;          // state number
      bool        match_num;  // whether state has a transition on a numeric constant
      list<Rule>  rules;      // rule markers
      list<Trans> trans;      // transitions (1st transition is on variable if available)
      State() : s(0), match_num(false), rules(list<Rule>()), trans(list<Trans>()) {}
      State(const State& state) : s(state.s), match_num(state.match_num), rules(state.rules), trans(state.trans) {}

      State& operator=(const State& state)
      {
          s         = state.s;
          match_num = state.match_num;
          rules     = state.rules;
          trans     = state.trans;
          return *this;
      }

      static State* make_state(State* state, int r, Tree x, Path& p);
      static State* make_var_state(int n, State* state);
      static void merge_state(State* state1, State* state2);

  #ifdef DEBUG
      ostream& print(ostream& fout) const;
  #endif
  };
}

#endif
