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

#ifndef __FAUST__MOVE_VARIABLES_IN_FRONT_3_HH__
#define __FAUST__MOVE_VARIABLES_IN_FRONT_3_HH__

#include "visitor/basic_clone_visitor.hh"
#include "types/array_typed.hh"
#include "instruction_builder.hh"

#include "compiler/instruction/value/numbers/array_double_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_fixed_point_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_float_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_int32_number_instruction.hh"
#include "compiler/instruction/value/numbers/array_number_instruction.hh"
#include "compiler/instruction/value/numbers/bool_number_instruction.hh"
#include "compiler/instruction/value/numbers/double_number_instruction.hh"
#include "compiler/instruction/value/numbers/fixed_point_number_instruction.hh"
#include "compiler/instruction/value/numbers/float_number_instruction.hh"
#include "compiler/instruction/value/numbers/int32_number_instruction.hh"
#include "compiler/instruction/value/numbers/int64_number_instruction.hh"

// Moves all variables declaration at the beginning of the block and rewrite them as 'declaration' followed by 'store'
struct MoveVariablesInFront3 : public BasicCloneVisitor {
    list<StatementInst*> fVarTableDeclaration;
    list<StatementInst*> fVarTableStore;

    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        BasicCloneVisitor cloner;
        ArrayTyped*       array_typed = dynamic_cast<ArrayTyped*>(inst->fType);

        if (inst->fValue) {
            if (dynamic_cast<NumValueInst*>(inst->fValue)) {
                // Declaration rewriten as simple DeclareVarInst (without value) and a store
                fVarTableDeclaration.push_back(
                    InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner), inst->fType->clone(&cloner)));
                fVarTableStore.push_back(
                    InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner)));
                return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner));
                // "In extension" array definition
            } else if (array_typed) {
                fVarTableDeclaration.push_back(
                    InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner), inst->fType->clone(&cloner)));
                Typed::VarType ctype = array_typed->fType->getType();
                if (array_typed->fSize > 0) {
                    if (ctype == Typed::kInt32) {
                        Int32ArrayNumInst* int_array = dynamic_cast<Int32ArrayNumInst*>(inst->fValue);
                        if (int_array) {
                            for (int i = 0; i < array_typed->fSize; i++) {
                                fVarTableStore.push_back(InstBuilder::genStoreArrayStaticStructVar(
                                    inst->fAddress->getName(), InstBuilder::genInt32NumInst(i),
                                    InstBuilder::genInt32NumInst(int_array->getValue(i))));
                            }
                        } else {
                            return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner),
                                                                inst->fValue->clone(&cloner));
                        }
                    } else if (ctype == Typed::kFloat || ctype == Typed::kFloatMacro) {
                        FloatArrayNumInst* float_array = dynamic_cast<FloatArrayNumInst*>(inst->fValue);
                        if (float_array) {
                            for (int i = 0; i < array_typed->fSize; i++) {
                                fVarTableStore.push_back(InstBuilder::genStoreArrayStaticStructVar(
                                    inst->fAddress->getName(), InstBuilder::genInt32NumInst(i),
                                    InstBuilder::genFloatNumInst(float_array->getValue(i))));
                            }
                        } else {
                            return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner),
                                                                inst->fValue->clone(&cloner));
                        }
                    } else if (ctype == Typed::kDouble) {
                        DoubleArrayNumInst* double_array = dynamic_cast<DoubleArrayNumInst*>(inst->fValue);
                        if (double_array) {
                            for (int i = 0; i < array_typed->fSize; i++) {
                                fVarTableStore.push_back(InstBuilder::genStoreArrayStaticStructVar(
                                    inst->fAddress->getName(), InstBuilder::genInt32NumInst(i),
                                    InstBuilder::genDoubleNumInst(double_array->getValue(i))));
                            }
                        } else {
                            return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner),
                                                                inst->fValue->clone(&cloner));
                        }
                    } else {
                        faustassert(false);
                    }
                    return InstBuilder::genDropInst();
                } else {
                    return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner));
                }
            } else {
                // Declaration rewriten as simple DeclareVarInst (without value) and a store
                fVarTableDeclaration.push_back(
                    InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner), inst->fType->clone(&cloner)));
                fVarTableStore.push_back(
                    InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner)));
                return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner));
            }

        } else {
            fVarTableDeclaration.push_back(dynamic_cast<DeclareVarInst*>(inst->clone(&cloner)));
            return InstBuilder::genDropInst();
        }
    }

    BlockInst* getCode(BlockInst* src)
    {
        BlockInst* dst = static_cast<BlockInst*>(src->clone(this));
        // Variable store moved in front of block
        for (list<StatementInst*>::reverse_iterator it = fVarTableStore.rbegin(); it != fVarTableStore.rend(); ++it) {
            dst->pushFrontInst(*it);
        }
        // Then pure declaration
        for (list<StatementInst*>::reverse_iterator it = fVarTableDeclaration.rbegin();
             it != fVarTableDeclaration.rend(); ++it) {
            dst->pushFrontInst(*it);
        }
        return dst;
    }
};


#endif
