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

#ifndef _DISPATCH_VISITOR_
#define _DISPATCH_VISITOR_

#include "compiler/visitor/instruction_visitor.hh"

#include "compiler/type_manager/address/indexed_address.hh"
#include "compiler/type_manager/address/named_address.hh"

#include "compiler/types/array_typed.hh"
#include "compiler/types/basic_typed.hh"
#include "compiler/types/function_typed.hh"
#include "compiler/types/named_typed.hh"
#include "compiler/types/struct_typed.hh"
#include "compiler/types/vector_typed.hh"

#include "compiler/instruction/cast/cast_instruction.hh"
#include "compiler/instruction/cast/bit_cast_instruction.hh"

#include "compiler/instruction/control_flow/control_instruction.hh"
#include "compiler/instruction/control_flow/function_call_instruction.hh"
#include "compiler/instruction/control_flow/if_instruction.hh"
#include "compiler/instruction/control_flow/return_instruction.hh"
#include "compiler/instruction/control_flow/select_2_instruction.hh"
#include "compiler/instruction/control_flow/switch_instruction.hh"

#include "compiler/instruction/declarations/declare_buffer_iterators.hh"
#include "compiler/instruction/declarations/declare_function_instruction.hh"
#include "compiler/instruction/declarations/declare_struct_type_instruction.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"

#include "compiler/instruction/loops/for_loop_instruction.hh"
#include "compiler/instruction/loops/iterator_for_loop_instruction.hh"
#include "compiler/instruction/loops/simple_for_loop_instruction.hh"
#include "compiler/instruction/loops/while_loop_instruction.hh"

#include "compiler/instruction/math/binary_op_instruction.hh"

#include "compiler/instruction/memory/drop_instruction.hh"
#include "compiler/instruction/memory/load_var_address_instruction.hh"
#include "compiler/instruction/memory/load_var_instruction.hh"
#include "compiler/instruction/memory/shift_array_var_instruction.hh"
#include "compiler/instruction/memory/store_var_instruction.hh"
#include "compiler/instruction/memory/tee_var_instruction.hh"

#include "compiler/instruction/value/numbers/array_fixed_point_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_double_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_float_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_int32_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_number_instruction.hh"
#include "compiler/instruction/value/numbers/bool_number_instruction.hh"
#include "compiler/instruction/value/numbers/double_number_instruction.hh"
#include "compiler/instruction/value/numbers/fixed_point_number_instruction.hh"
#include "compiler/instruction/value/numbers/float_number_instruction.hh"
#include "compiler/instruction/value/numbers/int32_number_instruction.hh"
#include "compiler/instruction/value/numbers/int64_number_instruction.hh"
#include "compiler/instruction/value/numbers/number_value_instruction.hh"

#include "compiler/instruction/statement/block_instruction.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/value/null_value_instruction.hh"
#include "compiler/instruction/statement/null_statement_instruction.hh"

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
        if (inst->_code) {
            inst->_code->accept(this);
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
        if (inst->_resolutionult) {
            inst->_resolutionult->accept(this);
        }
    }

    virtual void visit(DropInst* inst)
    {
        if (inst->_resolutionult) {
            inst->_resolutionult->accept(this);
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
        inst->_code->accept(this);
    }

    virtual void visit(SimpleForLoopInst* inst)
    {
        inst->fInit->accept(this);
        inst->fUpperBound->accept(this);
        inst->fLowerBound->accept(this);
        inst->_code->accept(this);
    }

    virtual void visit(IteratorForLoopInst* inst)
    {
        for (const auto& it : inst->fIterators) {
            it->accept(this);
        }
        inst->_code->accept(this);
    }

    virtual void visit(WhileLoopInst* inst)
    {
        inst->fCond->accept(this);
        inst->_code->accept(this);
    }

    virtual void visit(SwitchInst* inst)
    {
        inst->fCond->accept(this);
        for (const auto& it : inst->_code) {
            (it.second)->accept(this);
        }
    }

    virtual void visit(BlockInst* inst)
    {
        for (const auto& it : inst->_code) {
            it->accept(this);
        }
    }

    // Typed
    virtual void visit(FunTyped* typed)
    {
        typed->_resolutionult->accept(this);
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
