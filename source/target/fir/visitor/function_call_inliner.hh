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

#ifndef __FAUST__FUNCTION_CALL_INLINER_HH__
#define __FAUST__FUNCTION_CALL_INLINER_HH__

// ===============
// Inlining tools
// ===============

#include "target/fir/visitor/function_inliner.hh"

// Replace a function call with the actual inlined function code
struct FunctionCallInliner : public BasicCloneVisitor {

    DeclareFunInst* fFunction;

    FunctionCallInliner(DeclareFunInst* function) : fFunction(function) {}

    virtual ValueInst* visit(FunCallInst* inst)
    {
        FunCallInst* fun_call = inst;
        if (fun_call->fName == fFunction->fName) {
            FunctionInliner inliner;
            BlockInst*      inlined = inliner.ReplaceParametersByArgs(fFunction->_code, fFunction->fType->fArgsTypes,
                                                                 fun_call->fArgs, fun_call->fMethod);

            // Get return value and remove it from the block
            ValueInst* res = inlined->getReturnValue();
            // Put the code without the value into the enclosing block
            fBlockStack.top()->pushBackInst(inlined);
            return res;
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

};

#endif
