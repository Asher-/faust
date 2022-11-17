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

#ifndef _TYPED_IS_TYPE_
#define _TYPED_IS_TYPE_

#include <string>

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

DeclareStructTypeInst* isStructType(const std::string& name);

#endif
