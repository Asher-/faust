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

#ifndef __FAUST__MOVE_VARIABLES_IN_FRONT_2_HH__
#define __FAUST__MOVE_VARIABLES_IN_FRONT_2_HH__

#include <list>

#include "visitor/basic_clone_visitor.hh"
#include "types/array_typed.hh"
#include "instruction_builder.hh"

#include "compiler/instruction/numbers/array_double_number_instruction.hh"
#include "compiler/instruction/numbers/array_fixed_point_number_instruction.hh"
#include "compiler/instruction/numbers/array_float_number_instruction.hh"
#include "compiler/instruction/numbers/array_int32_number_instruction.hh"
#include "compiler/instruction/numbers/array_number_instruction.hh"
#include "compiler/instruction/numbers/bool_number_instruction.hh"
#include "compiler/instruction/numbers/double_number_instruction.hh"
#include "compiler/instruction/numbers/fixed_point_number_instruction.hh"
#include "compiler/instruction/numbers/float_number_instruction.hh"
#include "compiler/instruction/numbers/int32_number_instruction.hh"
#include "compiler/instruction/numbers/int64_number_instruction.hh"

// Moves all variables declaration at the beginning of the block and rewrite them as 'declaration' followed by 'store'
struct MoveVariablesInFront2 : public BasicCloneVisitor {
    std::list<StatementInst*> fVarTable;

    virtual StatementInst* visit(DeclareVarInst* inst)
    {
        BasicCloneVisitor cloner;
        ArrayTyped*       array_typed = dynamic_cast<ArrayTyped*>(inst->fType);

        if (inst->fValue) {
            if (dynamic_cast<NumValueInst*>(inst->fValue)) {
                fVarTable.push_back(inst->clone(&cloner));
                return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner));
                // "In extension" array definition
            } else if (array_typed) {
                fVarTable.push_back(InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner),
                                                                   inst->fType->clone(&cloner),
                                                                   InstBuilder::genTypedZero(inst->fType->getType())));
                Typed::VarType ctype = array_typed->fType->getType();
                if (array_typed->fSize > 0) {
                    if (ctype == Typed::kInt32) {
                        Int32ArrayNumInst* int_array = dynamic_cast<Int32ArrayNumInst*>(inst->fValue);
                        if (int_array) {
                            for (int i = 0; i < array_typed->fSize; i++) {
                                fVarTable.push_back(InstBuilder::genStoreArrayStaticStructVar(
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
                                fVarTable.push_back(InstBuilder::genStoreArrayStaticStructVar(
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
                                fVarTable.push_back(InstBuilder::genStoreArrayStaticStructVar(
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
                fVarTable.push_back(InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner),
                                                                   inst->fType->clone(&cloner),
                                                                   InstBuilder::genTypedZero(inst->fType->getType())));
                return InstBuilder::genStoreVarInst(inst->fAddress->clone(&cloner), inst->fValue->clone(&cloner));
            }

        } else {
            fVarTable.push_back(InstBuilder::genDeclareVarInst(inst->fAddress->clone(&cloner),
                                                               inst->fType->clone(&cloner),
                                                               InstBuilder::genTypedZero(inst->fType->getType())));
            return InstBuilder::genDropInst();
        }
    }

    BlockInst* getCode(BlockInst* src, bool local = false)
    {
        BlockInst* dst = static_cast<BlockInst*>(src->clone(this));

        if (local) {
            // Separate with a list of pure DeclareVarInst (with no value), followed by a list of StoreVarInst
            BasicCloneVisitor    cloner;
            std::list<StatementInst*> dec;
            std::list<StatementInst*> store;

            for (std::list<StatementInst*>::reverse_iterator it = fVarTable.rbegin(); it != fVarTable.rend(); ++it) {
                DeclareVarInst* dec_inst   = dynamic_cast<DeclareVarInst*>(*it);
                StoreVarInst*   store_inst = dynamic_cast<StoreVarInst*>(*it);
                if (dec_inst) {
                    dec.push_back(InstBuilder::genDeclareVarInst(dec_inst->fAddress->clone(&cloner),
                                                                 dec_inst->fType->clone(&cloner)));
                    store.push_back(InstBuilder::genStoreVarInst(dec_inst->fAddress->clone(&cloner),
                                                                 dec_inst->fValue->clone(&cloner)));
                } else if (store_inst) {
                    store.push_back(store_inst->clone(&cloner));
                } else {
                    faustassert(false);
                }
            }

            for (const auto& it : store) {
                dst->pushFrontInst(it);
            }

            for (const auto& it : dec) {
                dst->pushFrontInst(it);
            }
        } else {
            // Separate with a list of DeclareVarInst with a value, followed by a list of StoreVarInst
            for (std::list<StatementInst*>::reverse_iterator it = fVarTable.rbegin(); it != fVarTable.rend(); ++it) {
                dst->pushFrontInst(*it);
            }
        }

        return dst;
    }
};

#endif
