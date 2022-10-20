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

#ifndef __PATTERNMATCHER__AUTOMATON__
#define __PATTERNMATCHER__AUTOMATON__

#include "garbageable.hh"
#include "patternmatcher/state.hh"
#include "patternmatcher/subst.hh"

namespace PM {

  struct Automaton : public virtual Garbageable {
      vector<State*> state;
      vector<Tree>   rhs;

      /* Create a pattern matching automaton from the given list of rules. */
      static Automaton* make_pattern_matcher(Tree R);

      /* Apply the pattern matcher to a single argument, starting from a given state
         s. Returns the resulting state, modifies the variable bindings E
         accordingly, and sets C to the resulting closure if a final state is
         reached. Result will be -1 to indicate a matching failure, and C will be
         set to nil if no final state has been reached yet. */
      static int apply_pattern_matcher(Automaton*    A,  // automaton
                              int           s,  // start state
                              Tree          X,  // arg to be matched
                              Tree&         C,  // output closure (if any)
                              vector<Tree>& E); // modified output environments
      static int apply_pattern_matcher_internal(Automaton* A, int s, Tree X, vector<Subst>& subst);
      static void add_subst(vector<Subst>& subst, Automaton* A, int s);
      static Tree subtree(Tree X, int i, const Path& p);


      Automaton() : state(vector<State*>()), rhs(vector<Tree>()), s(0) {}

      // number of rules
      int n_rules() { return (int)rhs.size(); }
      // markers of rules still active in state s
      const list<Rule>& rules(int s) { return state[s]->rules; }
      // transitions in state s
      const list<Trans>& trans(int s) { return state[s]->trans; }
      // is s a final state?
      bool final(int s) { return trans(s).empty(); }

      // assign state numbers and build the state table
      int  s;
      void build(State* st);

  #ifdef DEBUG
      ostream& print(ostream& fout) const;
  #endif
  };

}

#endif
