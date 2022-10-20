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

#ifndef _INSTRUCTIONS_DECLARATIONS_
#define _INSTRUCTIONS_DECLARATIONS_

#include <list>

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

// Numbers
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

struct DropInst;
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
typedef std::list<ValueInst*> Values;
typedef std::list<ValueInst*>::const_iterator ValuesIt;
typedef std::list<NamedTyped*> Names;
typedef std::list<NamedTyped*>::const_iterator NamesIt;

#endif
