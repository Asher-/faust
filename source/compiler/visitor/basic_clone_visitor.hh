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

#ifndef _BASIC_CLONE_INSTRUCTION_
#define _BASIC_CLONE_INSTRUCTION_

#include <vector>
#include <stack>

#include "compiler/type_manager/address/indexed_address.hh"
#include "compiler/type_manager/address/named_address.hh"

#include "compiler/visitor/clone_visitor.hh"
#include "compiler/visitor/instruction_visitor.hh"

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

#include "compiler/instruction/ui/add_bargraph_instruction.hh"
#include "compiler/instruction/ui/add_button_instruction.hh"
#include "compiler/instruction/ui/add_meta_declare_instruction.hh"
#include "compiler/instruction/ui/add_slider_instruction.hh"
#include "compiler/instruction/ui/add_soundfile_instruction.hh"
#include "compiler/instruction/ui/closebox_instruction.hh"
#include "compiler/instruction/ui/label_instruction.hh"
#include "compiler/instruction/ui/openbox_instruction.hh"

#include "compiler/instruction/statement/block_instruction.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/value/null_value_instruction.hh"
#include "compiler/instruction/statement/null_statement_instruction.hh"

#include "compiler/types/array_typed.hh"
#include "compiler/types/basic_typed.hh"
#include "compiler/types/function_typed.hh"
#include "compiler/types/named_typed.hh"
#include "compiler/types/struct_typed.hh"
#include "compiler/types/vector_typed.hh"

class BasicCloneVisitor : public CloneVisitor {
   protected:
    // Used when inlining functions
    static std::stack<BlockInst*> fBlockStack;

   public:
    BasicCloneVisitor() {}

    virtual NullValueInst*     visit(NullValueInst* inst) { return new NullValueInst(); }
    virtual NullStatementInst* visit(NullStatementInst* inst) { return new NullStatementInst(); }

    // Declarations
    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        // To be sure args are evaluated in order
        Address* cloned_address = inst->fAddress->clone(this);
        Typed* cloned_type = inst->fType->clone(this);
        return new DeclareVarInst(cloned_address, cloned_type, ((inst->fValue) ? inst->fValue->clone(this) : nullptr));
    }
    virtual StatementInst* visit(DeclareFunInst* inst)
    {
        // To be sure args are evaluated in order
        FunTyped* cloned_fun = static_cast<FunTyped*>(inst->fType->clone(this));
        return new DeclareFunInst(inst->fName, cloned_fun, static_cast<BlockInst*>(inst->_code->clone(this)));
    }
    virtual StatementInst* visit(DeclareStructTypeInst* inst)
    {
        return new DeclareStructTypeInst(static_cast<StructTyped*>(inst->fType->clone(this)));
    }
    virtual StatementInst* visit(DeclareBufferIterators* inst)
    {
        return new DeclareBufferIterators(inst->fBufferName1, inst->fBufferName2, inst->fChannels, inst->fType, inst->fMutable);
    }

    // Memory
    virtual ValueInst* visit(LoadVarInst* inst) { return new LoadVarInst(inst->fAddress->clone(this)); }
    virtual ValueInst* visit(LoadVarAddressInst* inst) { return new LoadVarAddressInst(inst->fAddress->clone(this)); }
    virtual ValueInst* visit(TeeVarInst* inst)
    {
        // To be sure args are evaluated in order
        Address* cloned_address = inst->fAddress->clone(this);
        ValueInst* cloned_value = inst->fValue->clone(this);
        return new TeeVarInst(cloned_address, cloned_value);
    }
    virtual StatementInst* visit(StoreVarInst* inst)
    {
        // To be sure args are evaluated in order
        Address* cloned_address = inst->fAddress->clone(this);
        ValueInst* cloned_value = inst->fValue->clone(this);
        return new StoreVarInst(cloned_address, cloned_value);
    }
    virtual StatementInst* visit(ShiftArrayVarInst* inst)
    {
        return new ShiftArrayVarInst(inst->fAddress->clone(this), inst->fDelay);
    }

    // Addresses
    virtual Address* visit(NamedAddress* address) { return new NamedAddress(address->fName, address->fAccess); }
    virtual Address* visit(IndexedAddress* address)
    {
        std::vector<ValueInst*> indices;
        for (const auto& it : address->fIndices) {
            indices.push_back(static_cast<ValueInst*>(it->clone(this)));
        }
        return new IndexedAddress(address->fAddress->clone(this), indices);
    }

    // Numbers
    virtual ValueInst* visit(FloatNumInst* inst) { return new FloatNumInst(inst->fNum); }
    virtual ValueInst* visit(FloatArrayNumInst* inst) { return new FloatArrayNumInst(inst->fNumTable); }
    virtual ValueInst* visit(Int32NumInst* inst) { return new Int32NumInst(inst->fNum); }
    virtual ValueInst* visit(Int64NumInst* inst) { return new Int64NumInst(inst->fNum); }
    virtual ValueInst* visit(Int32ArrayNumInst* inst) { return new Int32ArrayNumInst(inst->fNumTable); }
    virtual ValueInst* visit(BoolNumInst* inst) { return new BoolNumInst(inst->fNum); }
    virtual ValueInst* visit(DoubleNumInst* inst) { return new DoubleNumInst(inst->fNum); }
    virtual ValueInst* visit(DoubleArrayNumInst* inst) { return new DoubleArrayNumInst(inst->fNumTable); }
    virtual ValueInst* visit(FixedPointNumInst* inst) { return new FixedPointNumInst(inst->fNum); }
    virtual ValueInst* visit(FixedPointArrayNumInst* inst) { return new FixedPointArrayNumInst(inst->fNumTable); }

    // Numerical computation
    virtual ValueInst* visit(BinopInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_arg1 = inst->fInst1->clone(this);
        ValueInst* cloned_arg2 = inst->fInst2->clone(this);
        return new BinopInst(inst->fOpcode, cloned_arg1, cloned_arg2);
    }

    // Cast
    virtual ValueInst* visit(CastInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_value = inst->fInst->clone(this);
        Typed* cloned_type = inst->fType->clone(this);
        return new CastInst(cloned_value, cloned_type);
    }

    virtual ValueInst* visit(BitcastInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_value = inst->fInst->clone(this);
        Typed* cloned_type = inst->fType->clone(this);
        return new BitcastInst(cloned_value, cloned_type);
    }

    // Function call
    virtual ValueInst* visit(FunCallInst* inst)
    {
        Values cloned_args;
        for (const auto& it : inst->fArgs) {
            cloned_args.push_back(it->clone(this));
        }
        return new FunCallInst(inst->fName, cloned_args, inst->fMethod);
    }

    virtual StatementInst* visit(RetInst* inst)
    {
        return new RetInst((inst->_resolutionult) ? inst->_resolutionult->clone(this) : nullptr);
    }

    virtual StatementInst* visit(DropInst* inst)
    {
        return new DropInst((inst->_resolutionult) ? inst->_resolutionult->clone(this) : nullptr);
    }

    // Conditional
    virtual ValueInst* visit(Select2Inst* inst)
    {
        ValueInst* cloned_then = inst->fThen->clone(this);
        ValueInst* cloned_else = inst->fElse->clone(this);
        ValueInst* cloned_cond = inst->fCond->clone(this);
        // cond_exp has to be evaluated last for FunctionInliner to correctly work in gHasTeeLocal mode
        return new Select2Inst(cloned_cond, cloned_then, cloned_else);
    }

    virtual StatementInst* visit(ControlInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_cond = inst->fCond->clone(this);
        StatementInst* cloned_statement = inst->fStatement->clone(this);
        return new ControlInst(cloned_cond, cloned_statement);
    }

    virtual StatementInst* visit(IfInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cond_exp = inst->fCond->clone(this);
        BlockInst* then_exp = static_cast<BlockInst*>(inst->fThen->clone(this));
        BlockInst* else_exp = static_cast<BlockInst*>(inst->fElse->clone(this));
        return new IfInst(cond_exp, then_exp, else_exp);
    }
    virtual StatementInst* visit(SwitchInst* inst)
    {
        SwitchInst* cloned = new SwitchInst(inst->fCond->clone(this));
        for (const auto& it : inst->_code) {
            cloned->addCase(it.first, static_cast<BlockInst*>((it.second)->clone(this)));
        }
        return cloned;
    }

    // Loop
    virtual StatementInst* visit(ForLoopInst* inst)
    {
        // To be sure args are evaluated in order
        StatementInst* cloned_init = inst->fInit->clone(this);
        ValueInst* cloned_end = inst->fEnd->clone(this);
        StatementInst* cloned_increment = inst->fIncrement->clone(this);
        return new ForLoopInst(cloned_init, cloned_end, cloned_increment,
                               static_cast<BlockInst*>(inst->_code->clone(this)), inst->fIsRecursive);
    }

    virtual StatementInst* visit(SimpleForLoopInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_upper = inst->fUpperBound->clone(this);
        ValueInst* cloned_lower = inst->fLowerBound->clone(this);
        return new SimpleForLoopInst(inst->fName, cloned_upper, cloned_lower,
                                     inst->fReverse, static_cast<BlockInst*>(inst->_code->clone(this)));
    }

    virtual StatementInst* visit(IteratorForLoopInst* inst)
    {
        std::vector<NamedAddress*> iterators;
        for (const auto& it : inst->fIterators) {
            iterators.push_back(static_cast<NamedAddress*>(it->clone(this)));
        }
        return new IteratorForLoopInst(iterators, inst->fReverse, static_cast<BlockInst*>(inst->_code->clone(this)));
    }

    virtual StatementInst* visit(WhileLoopInst* inst)
    {
        // To be sure args are evaluated in order
        ValueInst* cloned_cond = inst->fCond->clone(this);
        BlockInst* cloned_code = static_cast<BlockInst*>(inst->_code->clone(this));
        return new WhileLoopInst(cloned_cond, cloned_code);
    }

    // Block
    virtual StatementInst* visit(BlockInst* inst)
    {
        // fBlockStack is used when inlining functions
        BlockInst* cloned = new BlockInst();
        fBlockStack.push(cloned);
        for (const auto& it : inst->_code) {
            cloned->pushBackInst(it->clone(this));
        }
        fBlockStack.pop();
        return cloned;
    }

    // User interface
    virtual StatementInst* visit(AddMetaDeclareInst* inst)
    {
        return new AddMetaDeclareInst(inst->fZone, inst->fKey, inst->fValue);
    }
    virtual StatementInst* visit(OpenboxInst* inst) { return new OpenboxInst(inst->fName, inst->fOrient); }
    virtual StatementInst* visit(CloseboxInst* inst) { return new CloseboxInst(); }
    virtual StatementInst* visit(AddButtonInst* inst)
    {
        return new AddButtonInst(inst->fLabel, inst->fZone, inst->fType);
    }
    virtual StatementInst* visit(AddSliderInst* inst)
    {
        return new AddSliderInst(inst->fLabel, inst->fZone, inst->fInit, inst->fMin, inst->fMax, inst->fStep,
                                 inst->fType);
    }
    virtual StatementInst* visit(AddBargraphInst* inst)
    {
        return new AddBargraphInst(inst->fLabel, inst->fZone, inst->fMin, inst->fMax, inst->fType);
    }
    virtual StatementInst* visit(AddSoundfileInst* inst)
    {
        return new AddSoundfileInst(inst->fLabel, inst->fURL, inst->fSFZone);
    }
    virtual StatementInst* visit(LabelInst* inst) { return new LabelInst(inst->fLabel); }

    // Typed
    virtual Typed* visit(BasicTyped* typed);  // Moved in instructions.cpp
    virtual Typed* visit(NamedTyped* typed) { return new NamedTyped(typed->fName, typed->fType); }
    virtual Typed* visit(FunTyped* typed)
    {
        Names cloned;
        for (const auto& it : typed->fArgsTypes) {
            cloned.push_back(static_cast<NamedTyped*>(it->clone(this)));
        }
        return new FunTyped(cloned, static_cast<BasicTyped*>(typed->_resolutionult->clone(this)), typed->fAttribute);
    }
    virtual Typed* visit(ArrayTyped* typed)
    {
        return new ArrayTyped(typed->fType->clone(this), typed->fSize);
    }
    virtual Typed* visit(StructTyped* typed)
    {
        std::vector<NamedTyped*> cloned;
        for (const auto& it : typed->fFields) {
            cloned.push_back(static_cast<NamedTyped*>(it->clone(this)));
        }
        return new StructTyped(typed->fName, cloned);
    }

    virtual Typed* visit(VectorTyped* typed)
    {
        return new VectorTyped(static_cast<BasicTyped*>(typed->fType->clone(this)), typed->fSize);
    }

    // Return the cloned block, possibly refined in subclasses.
    virtual BlockInst* getCode(BlockInst* src) { return static_cast<BlockInst*>(src->clone(this)); }

};

#endif
