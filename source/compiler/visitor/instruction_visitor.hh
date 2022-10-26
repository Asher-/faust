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

#ifndef _INSTRUCTION_VISITOR_
#define _INSTRUCTION_VISITOR_

#include "garbageable.hh"
#include "compiler/instruction/declarations.hh"

struct AddMetaDeclareInst; // Cyclic reference

struct InstVisitor : public virtual Garbageable {
    InstVisitor() {}
    virtual ~InstVisitor() {}

    // User interface
    virtual void visit(AddMetaDeclareInst* inst) {}
    virtual void visit(OpenboxInst* inst) {}
    virtual void visit(CloseboxInst* inst) {}
    virtual void visit(AddButtonInst* inst) {}
    virtual void visit(AddSliderInst* inst) {}
    virtual void visit(AddBargraphInst* inst) {}
    virtual void visit(AddSoundfileInst* inst) {}

    virtual void visit(LabelInst* inst) {}

    virtual void visit(Printable* inst) {}
    virtual void visit(NullValueInst* inst) {}
    virtual void visit(NullStatementInst* inst) {}

    // Declarations
    virtual void visit(DeclareVarInst* inst) {}
    virtual void visit(DeclareFunInst* inst) {}
    virtual void visit(DeclareStructTypeInst* inst) {}
    virtual void visit(DeclareBufferIterators* inst) {}

    // Memory
    virtual void visit(LoadVarInst* inst) {}
    virtual void visit(LoadVarAddressInst* inst) {}
    virtual void visit(TeeVarInst* inst) {}
    virtual void visit(StoreVarInst* inst) {}
    virtual void visit(ShiftArrayVarInst* inst) {}

    // Numbers
    virtual void visit(FloatNumInst* inst) {}
    virtual void visit(FloatArrayNumInst* inst) {}
    virtual void visit(Int32NumInst* inst) {}
    virtual void visit(Int64NumInst* inst) {}
    virtual void visit(Int32ArrayNumInst* inst) {}
    virtual void visit(BoolNumInst* inst) {}
    virtual void visit(DoubleNumInst* inst) {}
    virtual void visit(DoubleArrayNumInst* inst) {}
    virtual void visit(FixedPointNumInst* inst) {}
    virtual void visit(FixedPointArrayNumInst* inst) {}

    // Numerical computation
    virtual void visit(BinopInst* inst) {}

    // Cast
    virtual void visit(CastInst* inst) {}
    virtual void visit(BitcastInst* inst) {}

    // Function call
    virtual void visit(FunCallInst* inst) {}
    virtual void visit(RetInst* inst) {}
    virtual void visit(DropInst* inst) {}

    // Conditional
    virtual void visit(Select2Inst* inst) {}
    virtual void visit(ControlInst* inst) {}
    virtual void visit(IfInst* inst) {}
    virtual void visit(SwitchInst* inst) {}

    // Loops
    virtual void visit(ForLoopInst* inst) {}
    virtual void visit(SimpleForLoopInst* inst) {}
    virtual void visit(IteratorForLoopInst* inst) {}
    virtual void visit(WhileLoopInst* inst) {}

    // Block
    virtual void visit(BlockInst* inst) {}

    // Addresses
    virtual void visit(NamedAddress* address) {}
    virtual void visit(IndexedAddress* address) {}

    // Types
    virtual void visit(BasicTyped* typed) {}
    virtual void visit(NamedTyped* typed) {}
    virtual void visit(FunTyped* typed) {}
    virtual void visit(ArrayTyped* typed) {}
    virtual void visit(StructTyped* typed) {}
    virtual void visit(VectorTyped* typed) {}
};


#endif
