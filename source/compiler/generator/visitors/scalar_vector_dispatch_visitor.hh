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

#ifndef _SCALE_VECTOR_DISPATCH_VISITOR_
#define _SCALE_VECTOR_DISPATCH_VISITOR_

#include "visitors/dispatch_visitor.hh"

class ScalVecDispatcherVisitor : public DispatchVisitor {
   protected:
    InstVisitor* fScalarVisitor;
    InstVisitor* fVectorVisitor;

    void Dispatch2Visitor(ValueInst* inst);

   public:
    using DispatchVisitor::visit;

    ScalVecDispatcherVisitor(InstVisitor* scal, InstVisitor* vec) : fScalarVisitor(scal), fVectorVisitor(vec) {}

    ~ScalVecDispatcherVisitor()
    {
        delete fScalarVisitor;
        delete fVectorVisitor;
    }

    virtual void visit(LoadVarInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(LoadVarAddressInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(TeeVarInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(StoreVarInst* inst)
    {
        /*
        if (inst->fValue->fSize == 1) {
            fScalarVisitor->visit(inst);
        } else {
            fVectorVisitor->visit(inst);
        }
        */

        fScalarVisitor->visit(inst);
    }

    virtual void visit(ShiftArrayVarInst* inst) { fScalarVisitor->visit(inst); }

    virtual void visit(FloatNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(FloatArrayNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(Int32NumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(Int64NumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(BoolNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(DoubleNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(DoubleArrayNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(FixedPointNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(FixedPointArrayNumInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(BinopInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(CastInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(BitcastInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(FunCallInst* inst) { Dispatch2Visitor(inst); }

    virtual void visit(Select2Inst* inst) { Dispatch2Visitor(inst); }

};


#endif
