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

#ifndef __SOUL_TABLE_SIZE_VISITOR_HH__
#define __SOUL_TABLE_SIZE_VISITOR_HH__

#include "compiler/visitor/basic_clone_visitor.hh"
#include "compiler/visitor/dispatch_visitor.hh"

// Look for the "fillXXX" function call and keep the size of the third 'table' argument
struct TableSizeVisitor : public DispatchVisitor {
    map<string, int> fSizeTable;

    virtual void visit(FunCallInst* inst)
    {
        if (startWith(inst->fName, "fill")) {
            ValuesIt it = inst->fArgs.begin();
            it++;
            Int32NumInst* size = dynamic_cast<Int32NumInst*>(*it);
            faustassert(size);
            it++;
            LoadVarInst* table = dynamic_cast<LoadVarInst*>(*it);
            faustassert(table);
            fSizeTable[inst->fName + "_" + to_string(size->fNum)] = size->fNum;
        }
    }
};

#endif
