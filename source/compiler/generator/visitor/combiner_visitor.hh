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

#ifndef _COMBINER_VISITOR_
#define _COMBINER_VISITOR_

#include "visitor/dispatch_visitor.hh"

// ===================
// Combining visitors
// ===================

class CombinerVisitor : public DispatchVisitor {
   protected:
    InstVisitor* fVisitor1;
    InstVisitor* fVisitor2;
    InstVisitor* fCurVisitor;

   public:
    CombinerVisitor(InstVisitor* v1, InstVisitor* v2) : fVisitor1(v1), fVisitor2(v2) { fCurVisitor = v1; }

    virtual ~CombinerVisitor() {}
};

#endif
