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

#include "compiler/instruction/declarations/declare_function_instruction.hh"
#include "compiler/types/function_typed.hh"
#include "global.hh"

#include "compiler/parser/implementation.hh"

// Function types (return type) are kept in the global name <===> type table
DeclareFunInst::DeclareFunInst(const std::string& name, FunTyped* type, BlockInst* code)
    : fName(name), fType(type), _code(code)
{
    if (global::config().gVarTypeTable.find(name) == global::config().gVarTypeTable.end()) {
        global::config().gVarTypeTable[name] = type;
    } else {
        FunTyped* fun_type = static_cast<FunTyped*>(global::config().gVarTypeTable[name]);
        // If same result type
        if (fun_type->getTyped() == type->getTyped()) {
            if ((gOutputLang() == "llvm") && (fun_type->getPrototype() != type->getPrototype())) {
                std::stringstream str;
                str << "ERROR : foreign function '" << name
                    << "' conflicts with another (possibly compiler internally defined) function with a different "
                       "prototype\n";
                throw faustexception(str.str());
            }
        } else {
            std::stringstream str;
            str << "ERROR : foreign function '" << name
                << "' conflicts with another (possibly compiler internally defined) function with a different return "
                   "type\n";
            throw faustexception(str.str());
        }
    }
}
