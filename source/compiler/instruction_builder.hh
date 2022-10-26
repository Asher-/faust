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

#ifndef _INSTRUCTION_BUILDER_
#define _INSTRUCTION_BUILDER_

#include <string>
#include <list>
#include <vector>

#include "binop.hh"

#include "address/indexed_address.hh"
#include "address/named_address.hh"

#include "types/array_typed.hh"
#include "types/basic_typed.hh"
#include "types/function_typed.hh"
#include "types/named_typed.hh"
#include "types/struct_typed.hh"
#include "types/vector_typed.hh"

#include "instruction/cast/cast_instruction.hh"
#include "instruction/cast/bit_cast_instruction.hh"

#include "instruction/control_flow/control_instruction.hh"
#include "instruction/control_flow/function_call_instruction.hh"
#include "instruction/control_flow/if_instruction.hh"
#include "instruction/control_flow/return_instruction.hh"
#include "instruction/control_flow/select_2_instruction.hh"
#include "instruction/control_flow/switch_instruction.hh"

#include "instruction/declarations/declare_buffer_iterators.hh"
#include "instruction/declarations/declare_function_instruction.hh"
#include "instruction/declarations/declare_struct_type_instruction.hh"
#include "instruction/declarations/declare_var_instruction.hh"

#include "instruction/loops/for_loop_instruction.hh"
#include "instruction/loops/iterator_for_loop_instruction.hh"
#include "instruction/loops/simple_for_loop_instruction.hh"
#include "instruction/loops/while_loop_instruction.hh"

#include "instruction/math/binary_op_instruction.hh"

#include "instruction/memory/drop_instruction.hh"
#include "instruction/memory/load_var_address_instruction.hh"
#include "instruction/memory/load_var_instruction.hh"
#include "instruction/memory/shift_array_var_instruction.hh"
#include "instruction/memory/store_var_instruction.hh"
#include "instruction/memory/tee_var_instruction.hh"

#include "instruction/numbers/array_fixed_point_number_instruction.hh"
#include "instruction/numbers/array_double_number_instruction.hh"
#include "instruction/numbers/array_float_number_instruction.hh"
#include "instruction/numbers/array_int32_number_instruction.hh"
#include "instruction/numbers/array_number_instruction.hh"
#include "instruction/numbers/bool_number_instruction.hh"
#include "instruction/numbers/double_number_instruction.hh"
#include "instruction/numbers/fixed_point_number_instruction.hh"
#include "instruction/numbers/float_number_instruction.hh"
#include "instruction/numbers/int32_number_instruction.hh"
#include "instruction/numbers/int64_number_instruction.hh"
#include "instruction/numbers/number_value_instruction.hh"

#include "instruction/ui/add_bargraph_instruction.hh"
#include "instruction/ui/add_button_instruction.hh"
#include "instruction/ui/add_meta_declare_instruction.hh"
#include "instruction/ui/add_slider_instruction.hh"
#include "instruction/ui/add_soundfile_instruction.hh"
#include "instruction/ui/closebox_instruction.hh"
#include "instruction/ui/label_instruction.hh"
#include "instruction/ui/openbox_instruction.hh"

#include "instruction/block_instruction.hh"
#include "instruction/statement_instruction.hh"
#include "instruction/value_instruction.hh"
#include "instruction/null_value_instruction.hh"
#include "instruction/null_statement_instruction.hh"

#define castInt32(e) dynamic_cast<Int32NumInst*>(e)
#define castInt64(e) dynamic_cast<Int64NumInst*>(e)
#define castFloat(e) dynamic_cast<FloatNumInst*>(e)
#define castDouble(e) dynamic_cast<DoubleNumInst*>(e)

struct InstBuilder {
    // User interface
    static AddMetaDeclareInst* genAddMetaDeclareInst(const std::string& zone, const std::string& key, const std::string& value)
    {
        return new AddMetaDeclareInst(zone, key, value);
    }

    static OpenboxInst* genOpenboxInst(const std::string& name, OpenboxInst::BoxType orient)
    {
        faustassert(orient >= OpenboxInst::kVerticalBox && orient <= OpenboxInst::kTabBox);
        return new OpenboxInst(name, orient);
    }

    static CloseboxInst* genCloseboxInst() { return new CloseboxInst(); }

    static AddButtonInst* genAddButtonInst(const std::string& label, const std::string& zone)
    {
        return new AddButtonInst(label, zone, AddButtonInst::kDefaultButton);
    }

    static AddButtonInst* genAddCheckbuttonInst(const std::string& label, const std::string& zone)
    {
        return new AddButtonInst(label, zone, AddButtonInst::kCheckButton);
    }

    static AddSliderInst* genAddHorizontalSliderInst(const std::string& label, const std::string& zone, double init, double min,
                                                     double max, double step)
    {
        std::stringstream error;
        if (min > max) {
            error << "ERROR : horizontal slider \'"<< label << "\' min = " << min << " should be less than max = " << max << "\n";
            throw faustexception(error.str());
        } else if (init < min || init > max) {
            error << "ERROR : horizontal slider \'"<< label << "\' init = " << init << " outside of [" << min << " " << max << "] range\n";
            throw faustexception(error.str());
        }
        return new AddSliderInst(label, zone, init, min, max, step, AddSliderInst::kHorizontal);
    }

    static AddSliderInst* genAddVerticalSliderInst(const std::string& label, const std::string& zone, double init, double min,
                                                   double max, double step)
    {
        std::stringstream error;
        if (min > max) {
            error << "ERROR : vertical slider \'"<< label << "\' min = " << min << " should be less than max = " << max << "\n";
            throw faustexception(error.str());
        } else if (init < min || init > max) {
            error << "ERROR : vertical slider \'" << label << "\' init = " << init << " outside of [" << min << " " << max << "] range\n";
            throw faustexception(error.str());
        }
        return new AddSliderInst(label, zone, init, min, max, step, AddSliderInst::kVertical);
    }

    static AddSliderInst* genAddNumEntryInst(const std::string& label, const std::string& zone, double init, double min,
                                             double max, double step)
    {
        std::stringstream error;
        if (min > max) {
            error << "ERROR : num entry \'"<< label << "\' min = " << min << " should be less than max = " << max << "\n";
            throw faustexception(error.str());
        } else if (init < min || init > max) {
            error << "ERROR : num entry \'" << label << "\' init = " << init << " outside of [" << min << " " << max << "] range\n";
            throw faustexception(error.str());
        }
        return new AddSliderInst(label, zone, init, min, max, step, AddSliderInst::kNumEntry);
    }

    static AddBargraphInst* genAddHorizontalBargraphInst(const std::string& label, const std::string& zone, double min,
                                                         double max)
    {
        return new AddBargraphInst(label, zone, min, max, AddBargraphInst::kHorizontal);
    }

    static AddBargraphInst* genAddVerticalBargraphInst(const std::string& label, const std::string& zone, double min, double max)
    {
        return new AddBargraphInst(label, zone, min, max, AddBargraphInst::kVertical);
    }

    static AddSoundfileInst* genAddSoundfileInst(const std::string& label, const std::string& url, const std::string& sf_zone)
    {
        return new AddSoundfileInst(label, url, sf_zone);
    }

    static LabelInst* genLabelInst(const std::string& label) { return new LabelInst(label); }

    // Null instruction
    static NullValueInst*     genNullValueInst() { return new NullValueInst(); }
    static NullStatementInst* genNullStatementInst() { return new NullStatementInst(); }

    // Declarations
    static DeclareVarInst* genDeclareVarInst(Address* address, Typed* typed, ValueInst* value = nullptr)
    {
        return new DeclareVarInst(address, typed, value);
    }

    static DeclareFunInst* genDeclareFunInst(const std::string& name, FunTyped* typed, BlockInst* code)
    {
        return new DeclareFunInst(name, typed, code);
    }
    static DeclareFunInst* genDeclareFunInst(const std::string& name, FunTyped* typed)
    {
        return new DeclareFunInst(name, typed);
    }

    static DeclareStructTypeInst* genDeclareStructTypeInst(StructTyped* type)
    {
        return new DeclareStructTypeInst(type);
    }

    static DeclareBufferIterators* genDeclareBufferIterators(const std::string& name1, const std::string& name2, int channels, Typed* type, bool mut)
    {
        return new DeclareBufferIterators(name1, name2, channels, type, mut);
    }

    // Memory
    static LoadVarInst*        genLoadVarInst(Address* address) { return new LoadVarInst(address); }
    static LoadVarAddressInst* genLoadVarAddressInst(Address* address) { return new LoadVarAddressInst(address); }
    static TeeVarInst*         genTeeVar(const std::string& vname, ValueInst* value)
    {
        return new TeeVarInst(InstBuilder::genNamedAddress(vname, Address::kStack), value);
    }
    static StoreVarInst* genStoreVarInst(Address* address, ValueInst* value)
    {
        return new StoreVarInst(address, value);
    }
    static ShiftArrayVarInst* genShiftArrayVarInst(Address* address, int delay)
    {
        return new ShiftArrayVarInst(address, delay);
    }

    // Numbers
    static FloatNumInst*       genFloatNumInst(float num) { return new FloatNumInst(num); }
    static FloatArrayNumInst*  genFloatArrayNumInst(int size) { return new FloatArrayNumInst(size); }
    static DoubleNumInst*      genDoubleNumInst(double num) { return new DoubleNumInst(num); }
    static DoubleArrayNumInst* genDoubleArrayNumInst(int size) { return new DoubleArrayNumInst(size); }
    static FixedPointNumInst*       genFixedPointNumInst(double num) { return new FixedPointNumInst(num); }
    static FixedPointArrayNumInst*  genFixedPointArrayNumInst(int size) { return new FixedPointArrayNumInst(size); }
    static DoubleNumInst*      genQuadNumInst(double num) { return new DoubleNumInst(num); }  // Use DoubleNumInst

    static ValueInst* genTypedNum(Typed::VarType type, double num);
    static ValueInst* genTypedZero(Typed::VarType type);
    static ValueInst* genRealNumInst(Typed::VarType ctype, double num);

    static ValueInst* genArrayNumInst(Typed::VarType ctype, int size)
    {
        if (ctype == Typed::kInt32) {
            return new Int32ArrayNumInst(size);
        } else if (ctype == Typed::kFloat) {
            return new FloatArrayNumInst(size);
        } else if (ctype == Typed::kDouble) {
            return new DoubleArrayNumInst(size);
        } else if (ctype == Typed::kFixedPoint) {
            return new FixedPointArrayNumInst(size);
        } else {
            faustassert(false);
        }
        return nullptr;
    }

    static Int32NumInst* genInt32NumInst(int num) { return new Int32NumInst(num); }
    static Int64NumInst* genInt64NumInst(int64_t num) { return new Int64NumInst(num); }
    static BoolNumInst*  genBoolNumInst(bool num) { return new BoolNumInst(num); }

    // Numerical computation
    static BinopInst* genBinopInst(int opcode, ValueInst* inst1, ValueInst* inst2)
    {
        return new BinopInst(opcode, inst1, inst2);
    }

    static ValueInst* genCastInst(ValueInst* inst, Typed* typed_ext)
    {
        return new CastInst(inst, typed_ext);
    }

    static ValueInst* genBitcastInst(ValueInst* inst, Typed* typed) { return new BitcastInst(inst, typed); }
    // Cast float/double/quad
    static ValueInst* genCastRealInst(ValueInst* inst);
    static ValueInst* genCastFloatMacroInst(ValueInst* inst);
    static ValueInst* genCastInt32Inst(ValueInst* inst);

    // Control flow
    static RetInst*  genRetInst(ValueInst* result = nullptr) { return new RetInst(result); }
    static DropInst* genDropInst(ValueInst* result = nullptr) { return new DropInst(result); }

    // Conditional
    static Select2Inst* genSelect2Inst(ValueInst* cond_inst, ValueInst* then_inst, ValueInst* else_inst)
    {
        return new Select2Inst(cond_inst, then_inst, else_inst);
    }

    static StatementInst* genControlInst(ValueInst* cond_inst, StatementInst* exp_inst)
    {
        // If called with a NullValueInst, then the exp_inst is going to be always computed
        return (dynamic_cast<NullValueInst*>(cond_inst)) ? exp_inst : new ControlInst(cond_inst, exp_inst);
    }

    static IfInst* genIfInst(ValueInst* cond_inst, BlockInst* then_inst, BlockInst* else_inst)
    {
        return new IfInst(cond_inst, then_inst, else_inst);
    }
    static IfInst* genIfInst(ValueInst* cond_inst, BlockInst* then_inst) { return new IfInst(cond_inst, then_inst); }
    static SwitchInst* genSwitchInst(ValueInst* cond) { return new SwitchInst(cond); }

    // Function management
    static FunCallInst* genFunCallInst(const std::string& name, const Values& args)
    {
        return new FunCallInst(name, args, false);
    }
    static FunCallInst* genFunCallInst(const std::string& name, const Values& args, bool method)
    {
        return new FunCallInst(name, args, method);
    }
    static DropInst* genVoidFunCallInst(const std::string& name, const Values& args)
    {
        return new DropInst(new FunCallInst(name, args, false));
    }
    static DropInst* genVoidFunCallInst(const std::string& name, const Values& args, bool method)
    {
        return new DropInst(new FunCallInst(name, args, method));
    }

    // Loop
    static ForLoopInst* genForLoopInst(StatementInst* init, ValueInst* end, StatementInst* increment,
                                       BlockInst* code = new BlockInst(), bool is_recursive = false)
    {
        faustassert(dynamic_cast<DeclareVarInst*>(init) || dynamic_cast<StoreVarInst*>(init));
        return new ForLoopInst(init, end, increment, code, is_recursive);
    }

    // TODO: add access to the loop variable, generate ascending/descending loops...
    static ForLoopInst* genForLoopInst(const std::string& index, int init, int size, int step = 1)
    {
        DeclareVarInst* dec = genDecLoopVar(index, genInt32Typed(), genInt32NumInst(init));
        ValueInst*      end = genLessThan(dec->load(), genInt32NumInst(size));
        StoreVarInst*   inc = dec->store(genAdd(dec->load(), step));
        return genForLoopInst(dec, end, inc);
    }

    // Used for Rust backend
    static SimpleForLoopInst* genSimpleForLoopInst(const std::string& name, ValueInst* upperBound,
                                                   ValueInst* lowerBound = new Int32NumInst(0), bool reverse = false,
                                                   BlockInst* code = new BlockInst())
    {
        faustassert(castInt32(upperBound) || dynamic_cast<LoadVarInst*>(upperBound));
        faustassert(castInt32(lowerBound) || dynamic_cast<LoadVarInst*>(lowerBound));
        return new SimpleForLoopInst(name, upperBound, lowerBound, reverse, code);
    }
    static IteratorForLoopInst* genIteratorForLoopInst(const std::vector<NamedAddress*>& iterators, bool reverse = false,
                                                       BlockInst* code = new BlockInst())
    {
        return new IteratorForLoopInst(iterators, reverse, code);
    }

    static WhileLoopInst* genWhileLoopInst(ValueInst* cond, BlockInst* code) { return new WhileLoopInst(cond, code); }

    static BlockInst* genBlockInst(const std::list<StatementInst*>& code) { return new BlockInst(code); }
    static BlockInst* genBlockInst() { return new BlockInst(); }

    // Types
    static BasicTyped* genBasicTyped(Typed::VarType type);  // moved in instructions.cpp

    static BasicTyped* genInt32Typed() { return genBasicTyped(Typed::kInt32); }
    static BasicTyped* genInt64Typed() { return genBasicTyped(Typed::kInt64); }
    static BasicTyped* genVoidTyped() { return genBasicTyped(Typed::kVoid); }
    static BasicTyped* genFloatTyped() { return genBasicTyped(Typed::kFloat); }
    static BasicTyped* genDoubleTyped() { return genBasicTyped(Typed::kDouble); }

    static BasicTyped* genFloatMacroTyped() { return genBasicTyped(Typed::kFloatMacro); }
    static BasicTyped* genItFloatTyped();

    static NamedTyped* genNamedTyped(const std::string& name, Typed* type);
    static NamedTyped* genNamedTyped(const std::string& name, Typed::VarType type);

    static FunTyped* genFunTyped(const Names& args, BasicTyped* result,
                                 FunTyped::FunAttribute attribute = FunTyped::kDefault)
    {
        return new FunTyped(args, result, attribute);
    }
    static VectorTyped* genVectorTyped(BasicTyped* type, int size) { return new VectorTyped(type, size); }
    static ArrayTyped* genArrayTyped(Typed* type, int size)
    {
        return new ArrayTyped(type, size);
    }
    static StructTyped* genStructTyped(const std::string& name, const std::vector<NamedTyped*>& fields)
    {
        return new StructTyped(name, fields);
    }

    // Addresses
    static NamedAddress* genNamedAddress(const std::string& name, Address::AccessType access)
    {
        return new NamedAddress(name, access);
    }
    static IndexedAddress* genIndexedAddress(Address* address, ValueInst* index)
    {
        return new IndexedAddress(address, index);
    }

    static IndexedAddress* genIndexedAddress(Address* address, const std::vector<ValueInst*>& indices)
    {
        return new IndexedAddress(address, indices);
    }

    // Helper build methods
    static DeclareVarInst* genDecArrayVar(const std::string& vname, Address::AccessType var_access, Typed* type, int size)
    {
        return genDeclareVarInst(genNamedAddress(vname, var_access), genArrayTyped(type, size));
    }

    static LoadVarInst* genLoadArrayVar(const std::string& vname, Address::AccessType var_access, ValueInst* index)
    {
        return genLoadVarInst(genIndexedAddress(genNamedAddress(vname, var_access), index));
    }

    // Actually same as genLoadArrayVar
    static LoadVarInst* genLoadStructPtrVar(const std::string& vname, Address::AccessType var_access, ValueInst* index)
    {
        return genLoadArrayVar(vname, var_access, index);
    }

    static StoreVarInst* genStoreArrayVar(const std::string& vname, Address::AccessType var_access, ValueInst* index,
                                          ValueInst* exp)
    {
        return genStoreVarInst(genIndexedAddress(genNamedAddress(vname, var_access), index), exp);
    }

    // Struct variable
    static DeclareVarInst* genDecStructVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, Address::kStruct), type, exp);
    }

    static DeclareVarInst* genDecVolatileStructVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, (Address::AccessType)(Address::kStruct | Address::kVolatile)),
                                 type, exp);
    }

    static DeclareVarInst* genDecArrayStructVar(const std::string& vname, Typed* type, int size)
    {
        return genDecArrayVar(vname, Address::kStruct, type, size);
    }

    static LoadVarInst* genLoadStructVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kStruct));
    }

    static LoadVarInst* genLoadMutRefStructVar(const std::string& vname)
    {
        return genLoadVarInst(
            genNamedAddress(vname, (Address::AccessType)(Address::kStruct | Address::kReference | Address::kMutable)));
    }

    static LoadVarInst* genVolatileLoadStructVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, (Address::AccessType)(Address::kStruct | Address::kVolatile)));
    }

    template <typename Iterator>
    static LoadVarInst* genLoadArrayVar(const std::string& vname, Address::AccessType access, Iterator begin, Iterator end)
    {
        Address* address = genNamedAddress(vname, access);
        std::vector<ValueInst*> indices;
        for (Iterator it = begin; it != end; ++it) {
            indices.push_back(*it);
        }
        address = genIndexedAddress(address, indices);

        return genLoadVarInst(address);
    }

    template <typename Iterator>
    static LoadVarInst* genLoadArrayStructVar(const std::string& vname, Iterator indexBegin, Iterator indexEnd)
    {
        return genLoadArrayVar(vname, Address::kStruct, indexBegin, indexEnd);
    }

    static LoadVarInst* genLoadArrayStructVar(const std::string& vname, ValueInst* index)
    {
        std::vector<ValueInst*> indices = { index };
        return genLoadArrayStructVar(vname, indices.begin(), indices.end());
    }

    static LoadVarInst* genLoadArrayStructVar(const std::string& vname, const std::vector<ValueInst*>& indices)
    {
        return genLoadArrayStructVar(vname, indices.begin(), indices.end());
    }

    static LoadVarInst* genLoadArrayStructVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kStruct));
    }

    static LoadVarAddressInst* genLoadArrayStructVarAddress(const std::string& vname, ValueInst* index)
    {
        return genLoadVarAddressInst(genIndexedAddress(genNamedAddress(vname, Address::kStruct), index));
    }

    static StoreVarInst* genStoreStructVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kStruct), exp);
    }

    static StoreVarInst* genVolatileStoreStructVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, (Address::AccessType)(Address::kStruct | Address::kVolatile)),
                               exp);
    }


    template <typename Iterator>
    static StoreVarInst* genStoreArrayVar(const std::string& vname,
                                          ValueInst* exp,
                                          Address::AccessType access,
                                          Iterator begin,
                                          Iterator end)
    {
        Address* address = genNamedAddress(vname, access);
        std::vector<ValueInst*> indices;
        for (Iterator it = begin; it != end; ++it) {
            indices.push_back(*it);
        }
        address = genIndexedAddress(address, indices);

        return genStoreVarInst(address, exp);
    }

    template <typename Iterator>
    static StoreVarInst* genStoreArrayStructVar(const std::string& vname,
                                                ValueInst* exp,
                                                Iterator indexBegin,
                                                Iterator indexEnd)
    {
        return genStoreArrayVar(vname, exp, Address::kStruct, indexBegin, indexEnd);
    }

    static StoreVarInst* genStoreArrayStructVar(const std::string& vname, ValueInst* index, ValueInst* exp)
    {
        std::vector<ValueInst*> indices = {index};
        return genStoreArrayStructVar(vname, exp, indices.begin(), indices.end());
    }

    static StoreVarInst* genStoreArrayStructVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kStruct), exp);
    }

    // Static struct variable
    static DeclareVarInst* genDecStaticStructVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, Address::kStaticStruct), type, exp);
    }

    static DeclareVarInst* genDecConstStaticStructVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(
            genNamedAddress(vname, (Address::AccessType)(Address::kStaticStruct | Address::kConst)), type, exp);
    }

    static LoadVarInst* genLoadStaticStructVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kStaticStruct));
    }

    static LoadVarInst* genLoadStaticMutRefStructVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(
            vname, (Address::AccessType)(Address::kStaticStruct | Address::kReference | Address::kMutable)));
    }

    static StoreVarInst* genStoreStaticStructVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kStaticStruct), exp);
    }

    template <typename Iterator>
    static LoadVarInst* genLoadArrayStaticStructVar(const std::string& vname, Iterator indexBegin, Iterator indexEnd)
    {
        return genLoadArrayVar(vname, Address::kStaticStruct, indexBegin, indexEnd);
    }

    static LoadVarInst* genLoadArrayStaticStructVar(const std::string& vname, ValueInst* index)
    {
        std::vector<ValueInst*> indices = {index};
        return genLoadArrayStaticStructVar(vname, indices.begin(), indices.end());
    }

    template <typename Iterator>
    static StoreVarInst* genStoreArrayStaticStructVar(const std::string& vname, ValueInst* exp, Iterator indexBegin,
                                                      Iterator indexEnd)
    {
        return genStoreArrayVar(vname, exp, Address::kStaticStruct, indexBegin, indexEnd);
    }

    static StoreVarInst* genStoreArrayStaticStructVar(const std::string& vname, ValueInst* index, ValueInst* exp)
    {
        std::vector<ValueInst*> indices = {index};
        return genStoreArrayStructVar(vname, exp, indices.begin(), indices.end());
    }

    // Stack variable
    static DeclareVarInst* genDecStackVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, Address::kStack), type, exp);
    }

    static DeclareVarInst* genDecArrayStackVar(const std::string& vname, Typed* type, int size)
    {
        return genDecArrayVar(vname, Address::kStack, type, size);
    }

    static LoadVarInst* genLoadStackVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kStack));
    }

    static LoadVarAddressInst* genLoadStackVarAddress(const std::string& vname)
    {
        return genLoadVarAddressInst(genNamedAddress(vname, Address::kStack));
    }

    static LoadVarInst* genLoadArrayStackVar(const std::string& vname, ValueInst* index)
    {
        return genLoadVarInst(genIndexedAddress(genNamedAddress(vname, Address::kStack), index));
    }

    static LoadVarAddressInst* genLoadArrayStackVarAddress(const std::string& vname, ValueInst* index)
    {
        return genLoadVarAddressInst(genIndexedAddress(genNamedAddress(vname, Address::kStack), index));
    }

    static StoreVarInst* genStoreStackVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kStack), exp);
    }

    static StoreVarInst* genStoreArrayStackVar(const std::string& vname, ValueInst* index, ValueInst* exp)
    {
        return genStoreVarInst(genIndexedAddress(genNamedAddress(vname, Address::kStack), index), exp);
    }

    // Loop variable
    static DeclareVarInst* genDecLoopVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, Address::kLoop), type, exp);
    }

    static LoadVarInst* genLoadLoopVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kLoop));
    }

    static StoreVarInst* genStoreLoopVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kLoop), exp);
    }

    // FunArgs variable
    static LoadVarInst* genLoadFunArgsVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kFunArgs));
    }

    static LoadVarInst* genLoadArrayFunArgsVar(const std::string& vname, ValueInst* index)
    {
        return genLoadVarInst(genIndexedAddress(genNamedAddress(vname, Address::kFunArgs), index));
    }

    static StoreVarInst* genStoreArrayFunArgsVar(const std::string& vname, ValueInst* index, ValueInst* exp)
    {
        return genStoreVarInst(genIndexedAddress(genNamedAddress(vname, Address::kFunArgs), index), exp);
    }

    // Global variable
    static DeclareVarInst* genDecGlobalVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, Address::kGlobal), type, exp);
    }

    static DeclareVarInst* genDecConstGlobalVar(const std::string& vname, Typed* type, ValueInst* exp = nullptr)
    {
        return genDeclareVarInst(genNamedAddress(vname, (Address::AccessType)(Address::kGlobal | Address::kConst)),
                                 type, exp);
    }

    static LoadVarInst* genLoadGlobalVar(const std::string& vname)
    {
        return genLoadVarInst(genNamedAddress(vname, Address::kGlobal));
    }

    static StoreVarInst* genStoreGlobalVar(const std::string& vname, ValueInst* exp)
    {
        return genStoreVarInst(genNamedAddress(vname, Address::kGlobal), exp);
    }

    static bool isZero(ValueInst* val)
    {
        return (castInt32(val) && castInt32(val)->fNum == 0)
            || (castInt64(val) && castInt64(val)->fNum == 0)
            || (castFloat(val) && castFloat(val)->fNum == 0.f)
            || (castDouble(val) && castDouble(val)->fNum == 0.);
    }

    static bool isOne(ValueInst* val)
    {
        return (castInt32(val) && castInt32(val)->fNum == 1)
            || (castInt64(val) && castInt64(val)->fNum == 1)
            || (castFloat(val) && castFloat(val)->fNum == 1.f)
            || (castDouble(val) && castDouble(val)->fNum == 1.);
    }

    // Binop operations
    static ValueInst* genAdd(ValueInst* a1, ValueInst* a2)
    {
        if (isZero(a1)) {
            return a2;
        } else if (isZero(a2)) {
            return a1;
        } else if (castInt32(a1) && castInt32(a2)) {
            return genInt32NumInst(castInt32(a1)->fNum + castInt32(a2)->fNum);
        } else if (castInt64(a1) && castInt64(a2)) {
            return genInt64NumInst(castInt64(a1)->fNum + castInt64(a2)->fNum);
        } else if (castFloat(a1) && castFloat(a2)) {
            return genFloatNumInst(castFloat(a1)->fNum + castFloat(a2)->fNum);
        } else if (castDouble(a1) && castDouble(a2)) {
            return genDoubleNumInst(castDouble(a1)->fNum + castDouble(a2)->fNum);
        }  else {
            return genBinopInst(kAdd, a1, a2);
        }
    }

    static ValueInst* genAdd(ValueInst* a1, int a2) { return genAdd(a1, genInt32NumInst(a2)); }

    static ValueInst* genSub(ValueInst* a1, ValueInst* a2)
    {
        return isZero(a2) ? a1 : genBinopInst(kSub, a1, a2);
    }

    static ValueInst* genSub(ValueInst* a1, int a2) { return genSub(a1, genInt32NumInst(a2)); }

    static ValueInst* genMul(ValueInst* a1, ValueInst* a2)
    {
        return isOne(a1) ? a2 : (isOne(a2) ? a1 : genBinopInst(kMul, a1, a2));
    }

    static ValueInst* genDiv(ValueInst* a1, ValueInst* a2)
    {
        return isOne(a2) ? a1 : genBinopInst(kDiv, a1, a2);
    }

    static BinopInst* genRem(ValueInst* a1, ValueInst* a2) { return genBinopInst(kRem, a1, a2); }

    static BinopInst* genGreaterThan(ValueInst* a1, ValueInst* a2) { return genBinopInst(kGT, a1, a2); }

    static BinopInst* genLessThan(ValueInst* a1, ValueInst* a2) { return genBinopInst(kLT, a1, a2); }

    static BinopInst* genGreaterEqual(ValueInst* a1, ValueInst* a2) { return genBinopInst(kGE, a1, a2); }

    static BinopInst* genLessEqual(ValueInst* a1, ValueInst* a2) { return genBinopInst(kLE, a1, a2); }

    static BinopInst* genEqual(ValueInst* a1, ValueInst* a2) { return genBinopInst(kEQ, a1, a2); }

    static BinopInst* genNotEqual(ValueInst* a1, ValueInst* a2) { return genBinopInst(kNE, a1, a2); }

    static BinopInst* genAnd(ValueInst* a1, ValueInst* a2) { return genBinopInst(kAND, a1, a2); }

    static BinopInst* genOr(ValueInst* a1, ValueInst* a2) { return genBinopInst(kOR, a1, a2); }

    static BinopInst* genXOr(ValueInst* a1, ValueInst* a2) { return genBinopInst(kXOR, a1, a2); }

    // Functions
    static DeclareFunInst* genVoidFunction(const std::string& name, BlockInst* code = new BlockInst());
    static DeclareFunInst* genVoidFunction(const std::string& name, Names& args, BlockInst* code,
                                           bool isvirtual = false);
    static DeclareFunInst* genFunction0(const std::string& name, Typed::VarType res, BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction1(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction2(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                        BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction3(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                        const std::string& arg3, Typed::VarType arg3_ty, BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction4(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                        const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                        Typed::VarType arg4_ty, BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction5(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                        const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                        Typed::VarType arg4_ty, const std::string& arg5, Typed::VarType arg5_ty,
                                        BlockInst* code = new BlockInst());
    static DeclareFunInst* genFunction6(const std::string& name, Typed::VarType res, const std::string& arg1,
                                        Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                        const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                        Typed::VarType arg4_ty, const std::string& arg5, Typed::VarType arg5_ty,
                                        const std::string& arg6, Typed::VarType arg6_ty, BlockInst* code = new BlockInst());
};

#endif
