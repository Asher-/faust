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

#ifndef __FAUST_FIR_CHECKER_HH__
#define __FAUST_FIR_CHECKER_HH__

#include "visitor/dispatch_visitor.hh"
#include "binop.hh"
#include "dump_to_fir.hh"

// FIR checker
struct FIRChecker : public DispatchVisitor {

    virtual void visit(BinopInst* inst)
    {
        Typed::VarType a1_type = TypingVisitor::getType(inst->fInst1);
        Typed::VarType a2_type = TypingVisitor::getType(inst->fInst2);
        if (a1_type == a2_type) {
            return;
        } else {
            bool v1 = isIntType(a1_type) && isBoolType(a2_type);
            bool v2 = isBoolType(a1_type) && isIntType(a2_type);
            if (v1 || v2) return;
        }
        // Fail
        dump2FIR(inst);
        cerr << "ERROR : FIRChecker in BinopInst";
        cerr << " a1_type = " << Typed::gTypeString[a1_type];
        cerr << " a2_type = " << Typed::gTypeString[a2_type] << endl;
        faustassert(false);
    }

    virtual void visit(Select2Inst* inst)
    {
        Typed::VarType cond_type = TypingVisitor::getType(inst->fCond);
        if (!(isIntType(cond_type) || isBoolType(cond_type))) {
            dump2FIR(inst);
            cerr << "ERROR : FIRChecker in Select2Inst";
            cerr << " cond_type = " << Typed::gTypeString[cond_type] << endl;
            faustassert(false);
        }
    }

    virtual void visit(::CastInst* inst)
    {
        Typed::VarType val_type = TypingVisitor::getType(inst->fInst);
        Typed::VarType cast_type = inst->fType->getType();

        if (isInt32Type(cast_type)) {
            if (isInt32Type(val_type)) {
                dump2FIR(inst);
                cerr << "ERROR : FIRChecker in CastInst Int";
                cerr << " value_type = " << Typed::gTypeString[val_type];
                cerr << " cast_type = " << Typed::gTypeString[cast_type] << endl;
                faustassert(false);
            }
        } else if (isFloatType(cast_type)) {
            if (isFloatType(val_type)) {
                dump2FIR(inst);
                cerr << "ERROR : FIRChecker in CastInst Float";
                cerr << " val_type = " << Typed::gTypeString[val_type];
                cerr << " cast_type = " << Typed::gTypeString[cast_type] << endl;
                faustassert(false);
            }
        } else if (isDoubleType(cast_type)) {
            if (isDoubleType(val_type)) {
                dump2FIR(inst);
                cerr << "ERROR : FIRChecker in CastInst Double";
                cerr << " val_type = " << Typed::gTypeString[val_type];
                cerr << " cast_type = " << Typed::gTypeString[cast_type] << endl;
                faustassert(false);
            }
        }
    }
};

#endif
