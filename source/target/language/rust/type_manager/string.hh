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

#ifndef _STRING_TYPE_MANAGER_RUST_
#define _STRING_TYPE_MANAGER_RUST_

 #include "type_manager/string.hh"

// StringTypeManager for Rust backend

class RustStringTypeManager : public StringTypeManager {
   public:
    RustStringTypeManager(const std::string& float_macro_name, const std::string& ptr_ref)
        : StringTypeManager(float_macro_name, ptr_ref)
    {
        fPtrRef = ptr_ref;

        fTypeDirectTable[Typed::kInt32]     = "i32";
        fTypeDirectTable[Typed::kInt32_ptr] = fPtrRef + "i32";
        fTypeDirectTable[Typed::kInt32_vec] = "vector<i32>";

        fTypeDirectTable[Typed::kInt64]     = "i64";
        fTypeDirectTable[Typed::kInt64_ptr] =  fPtrRef + "i64";
        fTypeDirectTable[Typed::kInt64_vec] = "vector<i64>";

        fTypeDirectTable[Typed::kFloat]     = "F32";
        fTypeDirectTable[Typed::kFloat_ptr] = fPtrRef + "F32";
        fTypeDirectTable[Typed::kFloat_ptr_ptr] =  fPtrRef + fPtrRef + "F32";
        fTypeDirectTable[Typed::kFloat_vec] = "vector<F32>";

        fTypeDirectTable[Typed::kDouble]     = "F64";
        fTypeDirectTable[Typed::kDouble_ptr] = fPtrRef + "F64";
        fTypeDirectTable[Typed::kDouble_ptr_ptr] = fPtrRef + fPtrRef + "F64";
        fTypeDirectTable[Typed::kDouble_vec] = "vector<F64>";

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

        fTypeDirectTable[Typed::kObj]     = "";
        fTypeDirectTable[Typed::kObj_ptr] = fPtrRef;

        // TODO : handling kUint_ptr
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
            return named_typed->fName + ((ty_str != "") ? (": " + ty_str) : "");
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
            return name + ": " + fTypeDirectTable[basic_typed->fType];
        } else if (named_typed) {
            string ty_str = named_typed->fName + generateType(named_typed->fType);
            return name + ((ty_str != "") ? (": " + ty_str) : "");
        } else if (array_typed) {
            return (array_typed->fSize == 0)
                       ? name + ": " + fPtrRef + generateType(array_typed->fType)
                       : name + ": [" + generateType(array_typed->fType) + ";" + std::to_string(array_typed->fSize) + "]";
        } else {
            faustassert(false);
            return "";
        }
    }
};

#endif
