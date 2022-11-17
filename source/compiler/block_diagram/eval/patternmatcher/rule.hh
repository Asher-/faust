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

#ifndef __PATTERNMATCHER__RULE__
#define __PATTERNMATCHER__RULE__

#include <list>

#include "patternmatcher/path.hh"
#include "compiler/type_manager/garbageable.hh"
#include "tlib/tree.hh"

namespace PM {

  struct Rule : public virtual Garbageable {
      int  r;   // rule number
      Tree id;  // matched variable (NULL if none)
      Path p;   // subterm path indicating where variable value is found

      Rule(int _r, Tree _id) : r(_r), id(_id), p(Path()) {}
      Rule(int _r, Tree _id, const Path& _p) : r(_r), id(_id), p(_p) {}
      Rule(const Rule& rule) : r(rule.r), id(rule.id), p(rule.p) {}

      Rule& operator=(const Rule& rule)
      {
          r  = rule.r;
          id = rule.id;
          p  = rule.p;
          return *this;
      }

      bool operator==(const Rule& rule) const { return r == rule.r; }
      bool operator<(const Rule& rule) const { return r < rule.r; }

      static void merge_rules(list<Rule>& rules1, list<Rule>& rules2);

  #ifdef DEBUG
      ostream& print(ostream& fout) const;
  #endif
  };

}

#endif
