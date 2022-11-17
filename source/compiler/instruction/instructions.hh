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

#ifndef _INSTRUCTIONS_H
#define _INSTRUCTIONS_H

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


#include "compiler/type_manager/Text.hh"
#include "compiler/signals/binop.hh"
#include "compiler/errors/exception.hh"
#include "compiler/type_manager/garbageable.hh"
#include "compiler/types/typed.hh"
#include "tlib/property.hh"

#include "compiler/instruction/declarations.hh"

#include "compiler/types/is_type.hh"
// =========
// Visitors
// =========

#include "compiler/visitor/clone_visitor.hh"
#include "compiler/visitor/combiner_visitor.hh"
#include "compiler/visitor/dispatch_visitor.hh"
#include "compiler/visitor/instruction_visitor.hh"
#include "compiler/visitor/scalar_vector_dispatch_visitor.hh"
#include "compiler/visitor/variable_scope_visitor.hh"

struct Printable;

// ===============
// User Interface
// ===============
struct AddMetaDeclareInst;
struct OpenboxInst;
struct CloseboxInst;
struct AddButtonInst;
struct AddSliderInst;
struct AddBargraphInst;
struct AddSoundfileInst;
struct LabelInst;

// =======
// Values
// =======
struct ValueInst;

// Memory load
struct LoadVarInst;
struct LoadVarAddressInst;
struct TeeVarInst;

// Base class for array of numbers
template <class TYPE>
struct ArrayNumInst;

// Numbers and array of numbers
struct FloatNumInst;
struct FloatArrayNumInst;
struct Int32NumInst;
struct Int64NumInst;
struct Int32ArrayNumInst;
struct BoolNumInst;
struct DoubleNumInst;
struct DoubleArrayNumInst;
struct FixedPointNumInst;
struct FixedPointArrayNumInst;

// Math Binop
struct BinopInst;

// Cast
struct CastInst;
struct BitcastInst;

// Selector
struct Select2Inst;

// Null value
struct NullValueInst;

// ===========
// Statements
// ===========
struct StatementInst;

// Declarations
struct DeclareVarInst;
struct DeclareBufferIterators;
struct DeclareFunInst;
struct DeclareStructTypeInst;

// Memory store
struct StoreVarInst;
// Array move
struct ShiftArrayVarInst;

// Function call
struct FunCallInst;
struct RetInst;
struct ControlInst;

// Control flow
struct IfInst;
struct SwitchInst;

// Loops
struct ForLoopInst;
struct SimpleForLoopInst;
struct IteratorForLoopInst;
struct WhileLoopInst;

// Block of statements
struct BlockInst;

// A no-op statement
struct DropInst;

// Null statement
struct NullStatementInst;

// ======
// Types
// ======
struct Typed;

struct BasicTyped;
struct NamedTyped;
struct FunTyped;
struct ArrayTyped;
struct StructTyped;
struct VectorTyped;

// =========
// Adresses
// =========
struct Address;
struct NamedAddress;
struct IndexedAddress;

// =============
// Naming tools
// =============
typedef ValueInst* ValueType;
typedef list<ValueInst*> Values;
typedef list<ValueInst*>::const_iterator ValuesIt;
typedef list<NamedTyped*> Names;
typedef list<NamedTyped*>::const_iterator NamesIt;

// ==============
// Type checking
// ==============

inline bool isRealType(Typed::VarType type)
{
    return (type == Typed::kFloat || type == Typed::kFloatMacro || type == Typed::kDouble);
}

inline bool isRealPtrType(Typed::VarType type)
{
    return (type == Typed::kFloat_ptr
            || type == Typed::kFloat_ptr_ptr
            || type == Typed::kFloatMacro_ptr
            || type == Typed::kFloatMacro_ptr_ptr
            || type == Typed::kDouble_ptr
            || type == Typed::kDouble_ptr_ptr);
}

inline bool isIntType(Typed::VarType type)
{
    return (type == Typed::kInt32 || type == Typed::kInt64);
}

inline bool isInt32Type(Typed::VarType type)
{
    return (type == Typed::kInt32);
}

inline bool isInt64Type(Typed::VarType type)
{
    return (type == Typed::kInt64);
}

inline bool isFloatType(Typed::VarType type)
{
    return (type == Typed::kFloat);
}

inline bool isDoubleType(Typed::VarType type)
{
    return (type == Typed::kDouble);
}

inline bool isFloatMacroType(Typed::VarType type)
{
    return (type == Typed::kFloatMacro);
}

inline bool isIntPtrType(Typed::VarType type)
{
    return (type == Typed::kInt32_ptr || type == Typed::kInt64_ptr);
}

inline bool isPtrType(Typed::VarType type)
{
    return isRealPtrType(type) || isIntPtrType(type);
}

inline bool isBoolType(Typed::VarType type)
{
    return (type == Typed::kBool);
}

inline bool isIntOrPtrType(Typed::VarType type)
{
    return (isIntType(type)
            || isIntPtrType(type)
            || isRealPtrType(type)
            || type == Typed::kVoid_ptr
            || type == Typed::kObj_ptr
            || type == Typed::kSound_ptr);
}

DeclareStructTypeInst* isStructType(const string& name);

// =========
// Visitors
// =========

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

// =======================
// Clone a FIR expression
// =======================

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

// ============================
// Base class for instructions
// ============================

// Printable is defined in instructions_type.h

#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/statement/statement_instruction.hh"
#include "compiler/instruction/value/null_value_instruction.hh"
#include "compiler/instruction/statement/null_statement_instruction.hh"

// =======
//  Types
// =======

#include "compiler/types/array_typed.hh"
#include "compiler/types/basic_typed.hh"
#include "compiler/types/function_typed.hh"
#include "compiler/types/named_typed.hh"
#include "compiler/types/struct_typed.hh"
#include "compiler/types/vector_typed.hh"

// ===========
//  Addresses
// ===========

#include "compiler/type_manager/address/address.hh"
#include "compiler/type_manager/address/named_address.hh"
#include "compiler/type_manager/address/indexed_address.hh"

// ===============
// User interface
// ===============

#include "compiler/instruction/ui/add_bargraph_instruction.hh"
#include "compiler/instruction/ui/add_button_instruction.hh"
#include "compiler/instruction/ui/add_meta_declare_instruction.hh"
#include "compiler/instruction/ui/add_slider_instruction.hh"
#include "compiler/instruction/ui/add_soundfile_instruction.hh"
#include "compiler/instruction/ui/closebox_instruction.hh"
#include "compiler/instruction/ui/label_instruction.hh"
#include "compiler/instruction/ui/openbox_instruction.hh"

// ====================
// Block of statements
// ====================

#include "compiler/instruction/statement/block_instruction.hh"

// =============
// Declarations
// =============

#include "compiler/instruction/declarations/declare_buffer_iterators.hh"
#include "compiler/instruction/declarations/declare_function_instruction.hh"
#include "compiler/instruction/declarations/declare_struct_type_instruction.hh"
#include "compiler/instruction/declarations/declare_var_instruction.hh"

// ==============
// Memory access
// ==============

#include "compiler/instruction/memory/drop_instruction.hh"
#include "compiler/instruction/memory/load_var_address_instruction.hh"
#include "compiler/instruction/memory/load_var_instruction.hh"
#include "compiler/instruction/memory/shift_array_var_instruction.hh"
#include "compiler/instruction/memory/store_var_instruction.hh"
#include "compiler/instruction/memory/tee_var_instruction.hh"

// ========
// Numbers
// ========

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

// ===========
// Math Binop
// ===========

#include "compiler/instruction/math/binary_op_instruction.hh"

// =====
// Cast
// =====

#include "compiler/instruction/cast/cast_instruction.hh"
#include "compiler/instruction/cast/bit_cast_instruction.hh"

// =============
// Control flow
// =============

#include "compiler/instruction/control_flow/control_instruction.hh"
#include "compiler/instruction/control_flow/function_call_instruction.hh"
#include "compiler/instruction/control_flow/if_instruction.hh"
#include "compiler/instruction/control_flow/return_instruction.hh"
#include "compiler/instruction/control_flow/select_2_instruction.hh"
#include "compiler/instruction/control_flow/switch_instruction.hh"

// ======
// Loops
// ======

#include "compiler/instruction/loops/for_loop_instruction.hh"
#include "compiler/instruction/loops/iterator_for_loop_instruction.hh"
#include "compiler/instruction/loops/simple_for_loop_instruction.hh"
#include "compiler/instruction/loops/while_loop_instruction.hh"

// ====================
// Basic clone visitor
// ====================

#include "compiler/visitor/basic_clone_visitor.hh"

// ======================
// Instruction generator
// ======================

#include "compiler/instruction_compiler/instruction_builder.hh"


#endif

/*

Name := sequence of char

Size := digits

Opcode := + | - | * | / |...etc...

Access := kGlobal | kStruct | kStaticStruct | kFunArgs | kStack | kLoop

Type := kFloat | kInt32 | kDouble | kVoid | Type* --> Type | Vector (Type) | Array (Type) if size = 0, then
equivalent to a pointer on the considered type

Address := Access name | Address index

Statement   := DeclareVar (Address, Type, Value)
            | DeclareFun (Name, Type, Block)
            | ForLoop (Statement, Value, Statement, Block)
            | SimpleForLoop (string, Value, Block)
            | WhileLoop (Value, Block)
            | StoreVar (Address, Value)
            | Drop (Value)
            | Return (Value)
            | BlockInst (Statement*)
            | If (Value, BlockInst, BlockInst)
            | Switch (Value, <int>, BlockInst>*)

Value       := LoadVar (Address)
            | Float | Int | Double | Bool
            | Select (Value1, Value2, Value3)
            | Binop (Opcode, Value1, Value2)
            | Cast (Type, Value)
            | Null ()

Code rewritting:

For WSS:

1) change access of variable of type kStack in kStruct

Loop to function rewritting (faster compilation ?):

Two methods:

I)

1) change kStack variables in kStruct
2) transform Loop (Name, Value, Statement*) in DeclareFun (Name, Type, Statement*) : function type kVoid --> kVoid
3) in Compute, replace each loop with a call to the created function

II)

1) in each loop, transform in put vector access from kStack in kFunArgs
2) transform Loop (Name, Value, Statement*) in DeclareFun (Name, Type, Statement*) : all input variables become function
parameters 3) in Compute, replace each loop with a call to the created function giving it the good parameters

Scalarisation (some ideas, possibly not correct or not complete...):

1) transform all vectors *without delay* on the stack (used in loops) in scalar
2) in each loop, transform input vector accessing scalar access (Load/Store)
3) regroup all "postcode" of all loop at the end
4) rename loop variable into the Compute variable name
5) extract code and put it in Compute, suppress Loop statements

 Vision of the loops (count, list of input vectors, list of output vectors) different from the external prototype
 compute(count, float**, float**) or want to homogenize.

 Hence:

 DAG of loops in the format (count, list of input vectors, list of output vectors)
 compute(count, float**, float**)

 1) generate the header that prepares the separate input and output arrays
 2) compile the loops

 How to differentiate vectors without delay (which can be transformed into a scalar) from vectors with delay? With a specific
 specific naming?

 TODO: management of loop indices

 - in IndexedAddress, put a ValueInst instead of fIndex, update visitors

 - in InstructionsCompiler, generate accesses with "LoadVar" (loop-index)

 - in ForLoopInst, fName becomes a "DeclareVarInst" (allows to name and initialize the index), add a test expression,
addition of ValueInst fNext, calculation using fName.

 - new kLoop access type for loop variables

 - when transforming loops, Loop2FunctionBuider, SeqLoopBuilderVisitor, "disable" statements that
 manipulate the indices of the loop ? (no need, they don't appear in the loop body, but
 the loop index is used in the loop body, it must be matched with the new loop index,
 renaming necessary?)

 - use the *same* index name in ForLoopInst and in the internal code of the loop

*/
