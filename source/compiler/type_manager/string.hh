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

#ifndef _TYPE_MANAGER_H
#define _TYPE_MANAGER_H

#include <list>
#include <map>
#include <set>
#include <string>

#include "exception.hh"
#include "compiler/instruction/instructions.hh"

// Base class for type manager

struct StringTypeManager {
    std::map<Typed::VarType, std::string> fTypeDirectTable;
    std::string                           fPtrRef;

    StringTypeManager(const std::string& float_macro_name, const std::string& ptr_ref)
    {
        fTypeDirectTable[Typed::kFloatMacro]         = float_macro_name;
        fTypeDirectTable[Typed::kFloatMacro_ptr]     = float_macro_name + ptr_ref;
        fTypeDirectTable[Typed::kFloatMacro_ptr_ptr] = float_macro_name + ptr_ref + ptr_ref;
    }

    virtual ~StringTypeManager() {}

    virtual std::string generateType(Typed* type, NamedTyped::Attribute attr = NamedTyped::kDefault) = 0;
    virtual std::string generateType(Typed* type, const std::string& name) = 0;
};

#endif
