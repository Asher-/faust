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

#ifndef _CLONE_VISITOR_
#define _CLONE_VISITOR_

#include "compiler/type_manager/garbageable.hh"
#include "compiler/instruction/declarations.hh"

// Clone a FIR expression

struct CloneVisitor : public virtual Garbageable {
    CloneVisitor() {}
    virtual ~CloneVisitor() {}

    virtual ValueInst*     visit(NullValueInst* inst)     = 0;
    virtual StatementInst* visit(NullStatementInst* inst) = 0;

    // Declarations
    virtual StatementInst* visit(DeclareVarInst* inst)        = 0;
    virtual StatementInst* visit(DeclareFunInst* inst)        = 0;
    virtual StatementInst* visit(DeclareStructTypeInst* inst) = 0;
    virtual StatementInst* visit(DeclareBufferIterators* inst) = 0;

    // Memory
    virtual ValueInst*     visit(LoadVarInst* inst)        = 0;
    virtual ValueInst*     visit(LoadVarAddressInst* inst) = 0;
    virtual ValueInst*     visit(TeeVarInst* inst)         = 0;
    virtual StatementInst* visit(StoreVarInst* inst)       = 0;
    virtual StatementInst* visit(ShiftArrayVarInst* inst)  = 0;

    // Numbers
    virtual ValueInst* visit(FloatNumInst* inst)       = 0;
    virtual ValueInst* visit(FloatArrayNumInst* inst)  = 0;
    virtual ValueInst* visit(Int32NumInst* inst)       = 0;
    virtual ValueInst* visit(Int64NumInst* inst)       = 0;
    virtual ValueInst* visit(Int32ArrayNumInst* inst)  = 0;
    virtual ValueInst* visit(BoolNumInst* inst)        = 0;
    virtual ValueInst* visit(DoubleNumInst* inst)      = 0;
    virtual ValueInst* visit(DoubleArrayNumInst* inst) = 0;
    virtual ValueInst* visit(FixedPointNumInst* inst)      = 0;
    virtual ValueInst* visit(FixedPointArrayNumInst* inst) = 0;

    // Math Binop
    virtual ValueInst* visit(BinopInst* inst) = 0;

    // Cast
    virtual ValueInst* visit(CastInst* inst)    = 0;
    virtual ValueInst* visit(BitcastInst* inst) = 0;

    // Function call
    virtual ValueInst*     visit(FunCallInst* inst) = 0;
    virtual StatementInst* visit(RetInst* inst)     = 0;
    virtual StatementInst* visit(DropInst* inst)    = 0;

    // Conditional
    virtual ValueInst*     visit(Select2Inst* inst) = 0;
    virtual StatementInst* visit(ControlInst* inst) = 0;
    virtual StatementInst* visit(IfInst* inst)      = 0;
    virtual StatementInst* visit(SwitchInst* inst)  = 0;

    // Loops
    virtual StatementInst* visit(ForLoopInst* inst)       = 0;
    virtual StatementInst* visit(SimpleForLoopInst* inst) = 0;
    virtual StatementInst* visit(IteratorForLoopInst* inst) = 0;
    virtual StatementInst* visit(WhileLoopInst* inst)     = 0;

    // Block
    virtual StatementInst* visit(BlockInst* inst) = 0;

    // User interface
    virtual StatementInst* visit(AddMetaDeclareInst* inst) = 0;
    virtual StatementInst* visit(OpenboxInst* inst)        = 0;
    virtual StatementInst* visit(CloseboxInst* inst)       = 0;
    virtual StatementInst* visit(AddButtonInst* inst)      = 0;
    virtual StatementInst* visit(AddSliderInst* inst)      = 0;
    virtual StatementInst* visit(AddBargraphInst* inst)    = 0;
    virtual StatementInst* visit(AddSoundfileInst* inst)   = 0;
    virtual StatementInst* visit(LabelInst* inst)          = 0;

    // Addresses
    virtual Address* visit(NamedAddress* address)   = 0;
    virtual Address* visit(IndexedAddress* address) = 0;

    // Types
    virtual Typed* visit(BasicTyped* type)  = 0;
    virtual Typed* visit(NamedTyped* type)  = 0;
    virtual Typed* visit(FunTyped* type)    = 0;
    virtual Typed* visit(ArrayTyped* type)  = 0;
    virtual Typed* visit(StructTyped* type) = 0;
    virtual Typed* visit(VectorTyped* type) = 0;
};

#endif
