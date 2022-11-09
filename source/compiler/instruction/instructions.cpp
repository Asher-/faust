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

#include <fstream>

#include "compiler/instruction/instructions.hh"
#include "compiler/types/floats.hh"
#include "global.hh"
#include "compiler/signals/sigtype.hh"
#include "target/fir/fir_to_fir.hh"

DeclareStructTypeInst* isStructType(const std::string& name)
{
    if (gGlobal->gVarTypeTable.find(name) != gGlobal->gVarTypeTable.end()) {
        Typed*         type     = gGlobal->gVarTypeTable[name];
        Typed::VarType ext_type = Typed::getTypeFromPtr(type->getType());
        // If type is an external Structured type
        if (gGlobal->gExternalStructTypes.find(ext_type) != gGlobal->gExternalStructTypes.end()) {
            return gGlobal->gExternalStructTypes[ext_type];
        }
    }
    return nullptr;
}

string Typed::gTypeString[] =
{
    "kInt32",         "kInt32_ptr",      "kInt32_vec",          "kInt32_vec_ptr",
    "kInt64",         "kInt64_ptr",      "kInt64_vec",          "kInt64_vec_ptr",
    "kBool",          "kBool_ptr",       "kBool_vec",           "kBool_vec_ptr",
    "kFloat",         "kFloat_ptr",      "kFloat_ptr_ptr",      "kFloat_vec",
    "kFloat_vec_ptr", "kFloatMacro",     "kFloatMacro_ptr",     "kFloatMacro_ptr_ptr",
    "kDouble",        "kDouble_ptr",     "kDouble_ptr_ptr",     "kDouble_vec",     "kDouble_vec_ptr",
    "kQuad",          "kQuad_ptr",       "kQuad_ptr_ptr",       "kQuad_vec",       "kQuad_vec_ptr",
    "kFixedPoint",    "kFixedPoint_ptr", "kFixedPoint_ptr_ptr", "kFixedPoint_vec", "kFixedPoint_vec_ptr",
    "kVoid",          "kVoid_ptr",
    "kObj",           "kObj_ptr",
    "kSound",         "kSound_ptr",
    "kUint_ptr",      "kNoType"
};
