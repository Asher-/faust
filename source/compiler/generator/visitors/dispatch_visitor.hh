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

#ifndef _DISPATCH_VISITOR_
#define _DISPATCH_VISITOR_

#include "visitors/instruction_visitor.hh"

#include "address/indexed_address.hh"
#include "address/named_address.hh"

#include "types/array_typed.hh"
#include "types/basic_typed.hh"
#include "types/function_typed.hh"
#include "types/named_typed.hh"
#include "types/struct_typed.hh"
#include "types/vector_typed.hh"

#include "instructions/cast/cast_instruction.hh"
#include "instructions/cast/bit_cast_instruction.hh"

#include "instructions/control_flow/control_instruction.hh"
#include "instructions/control_flow/function_call_instruction.hh"
#include "instructions/control_flow/if_instruction.hh"
#include "instructions/control_flow/return_instruction.hh"
#include "instructions/control_flow/select_2_instruction.hh"
#include "instructions/control_flow/switch_instruction.hh"

#include "instructions/declarations/declare_buffer_iterators.hh"
#include "instructions/declarations/declare_function_instruction.hh"
#include "instructions/declarations/declare_struct_type_instruction.hh"
#include "instructions/declarations/declare_var_instruction.hh"

#include "instructions/loops/for_loop_instruction.hh"
#include "instructions/loops/iterator_for_loop_instruction.hh"
#include "instructions/loops/simple_for_loop_instruction.hh"
#include "instructions/loops/while_loop_instruction.hh"

#include "instructions/math/binary_op_instruction.hh"

#include "instructions/memory/drop_instruction.hh"
#include "instructions/memory/load_var_address_instruction.hh"
#include "instructions/memory/load_var_instruction.hh"
#include "instructions/memory/shift_array_var_instruction.hh"
#include "instructions/memory/store_var_instruction.hh"
#include "instructions/memory/tee_var_instruction.hh"

#include "instructions/numbers/array_fixed_point_number_instruction.hh"
#include "instructions/numbers/array_double_number_instruction.hh"
#include "instructions/numbers/array_float_number_instruction.hh"
#include "instructions/numbers/array_int32_number_instruction.hh"
#include "instructions/numbers/array_number_instruction.hh"
#include "instructions/numbers/bool_number_instruction.hh"
#include "instructions/numbers/double_number_instruction.hh"
#include "instructions/numbers/fixed_point_number_instruction.hh"
#include "instructions/numbers/float_number_instruction.hh"
#include "instructions/numbers/int32_number_instruction.hh"
#include "instructions/numbers/int64_number_instruction.hh"
#include "instructions/numbers/number_value_instruction.hh"

#include "instructions/block_instruction.hh"
#include "instructions/statement_instruction.hh"
#include "instructions/value_instruction.hh"
#include "instructions/null_value_instruction.hh"
#include "instructions/null_statement_instruction.hh"

// =======================
// Basic dispatch visitor
// =======================

struct DispatchVisitor : public InstVisitor {
    using InstVisitor::visit;

    virtual void visit(DeclareVarInst* inst)
    {
        inst->fAddress->accept(this);
        inst->fType->accept(this);
        if (inst->fValue) {
            inst->fValue->accept(this);
        }
    }

    virtual void visit(DeclareFunInst* inst)
    {
        if (inst->fCode) {
            inst->fCode->accept(this);
        }
    }

    virtual void visit(LoadVarInst* inst) { inst->fAddress->accept(this); }
    virtual void visit(LoadVarAddressInst* inst) { inst->fAddress->accept(this); }
    virtual void visit(TeeVarInst* inst)
    {
        inst->fAddress->accept(this);
        inst->fValue->accept(this);
    }
    virtual void visit(StoreVarInst* inst)
    {
        inst->fAddress->accept(this);
        inst->fValue->accept(this);
    }

    virtual void visit(ShiftArrayVarInst* inst) { inst->fAddress->accept(this); }

    virtual void visit(IndexedAddress* address)
    {
        address->fAddress->accept(this);
        for (const auto& it : address->fIndices) {
            it->accept(this);
        }
    }

    virtual void visit(BinopInst* inst)
    {
        inst->fInst1->accept(this);
        inst->fInst2->accept(this);
    }

    virtual void visit(CastInst* inst) { inst->fInst->accept(this); }

    virtual void visit(BitcastInst* inst) { inst->fInst->accept(this); }

    virtual void visit(FunCallInst* inst)
    {
        for (const auto& it : inst->fArgs) {
            it->accept(this);
        }
    }

    virtual void visit(RetInst* inst)
    {
        if (inst->fResult) {
            inst->fResult->accept(this);
        }
    }

    virtual void visit(DropInst* inst)
    {
        if (inst->fResult) {
            inst->fResult->accept(this);
        }
    }

    virtual void visit(Select2Inst* inst)
    {
        inst->fCond->accept(this);
        inst->fThen->accept(this);
        inst->fElse->accept(this);
    }

    virtual void visit(ControlInst* inst)
    {
        inst->fCond->accept(this);
        inst->fStatement->accept(this);
    }

    virtual void visit(IfInst* inst)
    {
        inst->fCond->accept(this);
        inst->fThen->accept(this);
        inst->fElse->accept(this);
    }

    virtual void visit(ForLoopInst* inst)
    {
        inst->fInit->accept(this);
        inst->fEnd->accept(this);
        inst->fIncrement->accept(this);
        inst->fCode->accept(this);
    }

    virtual void visit(SimpleForLoopInst* inst)
    {
        inst->fInit->accept(this);
        inst->fUpperBound->accept(this);
        inst->fLowerBound->accept(this);
        inst->fCode->accept(this);
    }

    virtual void visit(IteratorForLoopInst* inst)
    {
        for (const auto& it : inst->fIterators) {
            it->accept(this);
        }
        inst->fCode->accept(this);
    }

    virtual void visit(WhileLoopInst* inst)
    {
        inst->fCond->accept(this);
        inst->fCode->accept(this);
    }

    virtual void visit(SwitchInst* inst)
    {
        inst->fCond->accept(this);
        for (const auto& it : inst->fCode) {
            (it.second)->accept(this);
        }
    }

    virtual void visit(BlockInst* inst)
    {
        for (const auto& it : inst->fCode) {
            it->accept(this);
        }
    }

    // Typed
    virtual void visit(FunTyped* typed)
    {
        typed->fResult->accept(this);
        for (const auto& it : typed->fArgsTypes) {
            it->accept(this);
        }
    }
    virtual void visit(ArrayTyped* typed) { typed->fType->accept(this); }
    virtual void visit(StructTyped* typed)
    {
        for (const auto& it : typed->fFields) {
            it->accept(this);
        }
    }

    virtual void visit(VectorTyped* typed) { typed->fType->accept(this); }
};

#endif
