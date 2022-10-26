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

#ifndef _STRING_TYPE_MANAGER_JULIA_
#define _STRING_TYPE_MANAGER_JULIA_

 #include "type_manager/string.hh"

// StringTypeManager for Julia backend

class JuliaStringTypeManager : public StringTypeManager {
   public:
    JuliaStringTypeManager(const std::string& float_macro_name, const std::string& ptr_ref, const std::string& struct_name = "")
        : StringTypeManager(float_macro_name, ptr_ref)
    {
        fPtrRef = ptr_ref;

        fTypeDirectTable[Typed::kInt32]     = "Int32";
        fTypeDirectTable[Typed::kInt32_ptr] = "Int32";
        fTypeDirectTable[Typed::kInt32_vec] = "vector<Int32>";

        fTypeDirectTable[Typed::kInt64]     = "Int64";
        fTypeDirectTable[Typed::kInt64_ptr] = "Int64";
        fTypeDirectTable[Typed::kInt64_vec] = "vector<Int64>";

        fTypeDirectTable[Typed::kFloat]     = "T";
        fTypeDirectTable[Typed::kFloat_ptr] = "T";
        fTypeDirectTable[Typed::kFloat_ptr_ptr] = "T";
        fTypeDirectTable[Typed::kFloat_vec] = "vector<T>";

        fTypeDirectTable[Typed::kDouble]     = "T";
        fTypeDirectTable[Typed::kDouble_ptr] = "T";
        fTypeDirectTable[Typed::kDouble_ptr_ptr] = "T";
        fTypeDirectTable[Typed::kDouble_vec] = "vector<T>";

        fTypeDirectTable[Typed::kQuad]     = "quad";
        fTypeDirectTable[Typed::kQuad_ptr] = fPtrRef + "quad";

        fTypeDirectTable[Typed::kFixedPoint]     = "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_ptr] = fPtrRef + "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_ptr] = fPtrRef + fPtrRef + "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_vec] = "vector<fixpoint_t>";

        fTypeDirectTable[Typed::kBool]     = "bool";
        fTypeDirectTable[Typed::kBool_ptr] = fPtrRef + "bool";
        fTypeDirectTable[Typed::kBool_vec] = "vector<bool>";

        fTypeDirectTable[Typed::kVoid]     = "void";
        fTypeDirectTable[Typed::kVoid_ptr] = fPtrRef + "void";

        fTypeDirectTable[Typed::kSound]     = "Soundfile";
        fTypeDirectTable[Typed::kSound_ptr] = fPtrRef + "Soundfile";

        // DSP has to be empty here
        fTypeDirectTable[Typed::kObj]     = struct_name + "{T}";
        fTypeDirectTable[Typed::kObj_ptr] = struct_name + "{T}";

        fTypeDirectTable[Typed::kUint_ptr] = "uintptr_t";
    }

    virtual std::string generateType(Typed* type, NamedTyped::Attribute attr = NamedTyped::kDefault)
    {
        BasicTyped* basic_typed = dynamic_cast<BasicTyped*>(type);
        NamedTyped* named_typed = dynamic_cast<NamedTyped*>(type);
        ArrayTyped* array_typed = dynamic_cast<ArrayTyped*>(type);

        if (basic_typed) {
            return fTypeDirectTable[basic_typed->fType];
        } else if (named_typed) {
            string ty_str = generateType(named_typed->fType);
            return named_typed->fName + ((ty_str != "") ? ("::" + ty_str) : "");
        } else if (array_typed) {
            return fTypeDirectTable[array_typed->getType()];
        } else {
            faustassert(false);
            return "";
        }
    }

    virtual std::string generateType(Typed* type, const std::string& name)
    {
        BasicTyped* basic_typed = dynamic_cast<BasicTyped*>(type);
        NamedTyped* named_typed = dynamic_cast<NamedTyped*>(type);
        ArrayTyped* array_typed = dynamic_cast<ArrayTyped*>(type);

        if (basic_typed) {
            return name + "::" + fTypeDirectTable[basic_typed->fType];
        } else if (named_typed) {
            string ty_str = named_typed->fName + generateType(named_typed->fType);
            return name + ((ty_str != "") ? ("::" + ty_str) : "");
        } else if (array_typed) {
            return (array_typed->fSize == 0)
                    ? name + "::" + fPtrRef + generateType(array_typed->fType)
                    : name + "::Vector{" + generateType(array_typed->fType) + "}";
        } else {
            faustassert(false);
            return "";
        }
    }
};

#endif
