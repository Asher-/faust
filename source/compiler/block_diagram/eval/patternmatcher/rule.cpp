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

#include "patternmatcher/rule.hh"

namespace PM {


  /* Merge two tree automata. Merges the tree automaton rooted at state2 into
     the automaton rooted at state1. We assume that state2 is in "trie" form,
     i.e., each state has at most one transition, which is always guaranteed
     here and simplifies the algorithm. */

  void Rule::merge_rules(list<Rule>& rules1, list<Rule>& rules2)
  {
      list<Rule> cprules2 = rules2;
      rules1.merge(cprules2);
  }

  #ifdef DEBUG
  inline ostream& operator<<(ostream& s, const Rule& x)
  {
      return x.print(s);
  }
  ostream& Rule::print(ostream& fout) const
  {
      if (id != NULL)
          fout << "#" << r << "(" << *id << ")";
      else
          fout << "#" << r;
      return fout;
  }
  #endif

}
