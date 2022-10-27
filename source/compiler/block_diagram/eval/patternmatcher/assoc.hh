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

#ifndef __PATTERNMATCHER__ASSOC__
#define __PATTERNMATCHER__ASSOC__

/* Helper type to represent variable substitutions which are recorded during
   matching. Each variable is associated with the path pointing at the subterm
   of the argument where the substitution of the matched variable is to be
   found. */

namespace PM {

  struct Assoc : public virtual Garbageable {
      Tree id;
      Path p;
      Assoc(Tree _id, const Path& _p) : id(_id), p(_p) {}
  };

}

#endif
