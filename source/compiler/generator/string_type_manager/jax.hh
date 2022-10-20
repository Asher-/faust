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

#ifndef _STRING_TYPE_MANAGER_JAX_
#define _STRING_TYPE_MANAGER_JAX_

 #include "string_type_manager.hh"

// StringTypeManager for JAX backend

class JAXStringTypeManager : public StringTypeManager {
   public:
    JAXStringTypeManager(const std::string& float_macro_name, const std::string& ptr_ref, const std::string& struct_name = "")
        : StringTypeManager(float_macro_name, ptr_ref)
    {
        fPtrRef = ptr_ref;

        fTypeDirectTable[Typed::kInt32]     = "jnp.int32";
        fTypeDirectTable[Typed::kInt32_ptr] = "jnp.int32";
        fTypeDirectTable[Typed::kInt32_vec] = "vector<Int32>"; // todo:

        fTypeDirectTable[Typed::kInt64]     = "jnp.int64";
        fTypeDirectTable[Typed::kInt64_ptr] = "jnp.int64";
        fTypeDirectTable[Typed::kInt64_vec] = "vector<Int64>"; // todo:

        fTypeDirectTable[Typed::kFloat]     = "";
        fTypeDirectTable[Typed::kFloat_ptr] = "";
        fTypeDirectTable[Typed::kFloat_ptr_ptr] = "";
        fTypeDirectTable[Typed::kFloat_vec] = ""; // todo:

        fTypeDirectTable[Typed::kDouble]     = "";
        fTypeDirectTable[Typed::kDouble_ptr] = "";
        fTypeDirectTable[Typed::kDouble_ptr_ptr] = "";
        fTypeDirectTable[Typed::kDouble_vec] = ""; // todo:

        fTypeDirectTable[Typed::kQuad]     = "";
        fTypeDirectTable[Typed::kQuad_ptr] = "";

        fTypeDirectTable[Typed::kFixedPoint]     = "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_ptr] = "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_ptr] = "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_vec] = "vector<fixpoint_t>";

        fTypeDirectTable[Typed::kBool]     = "jnp.bool";
        fTypeDirectTable[Typed::kBool_ptr] = "jnp.bool";
        fTypeDirectTable[Typed::kBool_vec] = "jnp.array[jnp.bool]";  // todo:

        fTypeDirectTable[Typed::kVoid]     = "void";
        fTypeDirectTable[Typed::kVoid_ptr] = "void";

        fTypeDirectTable[Typed::kSound]     = "Soundfile";
        fTypeDirectTable[Typed::kSound_ptr] = "Soundfile";

        // DSP has to be empty here
        fTypeDirectTable[Typed::kObj]     = "";  // struct_name
        fTypeDirectTable[Typed::kObj_ptr] = "";

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
            if (ty_str != "") {
                return ty_str + "(" + named_typed->fName + ")";
            }
            return named_typed->fName;
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
            return name;
            //return name + "::" + fTypeDirectTable[basic_typed->fType];
        } else if (named_typed) {
            string ty_str = named_typed->fName + generateType(named_typed->fType);
            //return name + ((ty_str != "") ? ("::" + ty_str) : "");
            return name;
        } else if (array_typed) {
            // return (array_typed->fSize == 0)
            //         ? name + "::" + fPtrRef + generateType(array_typed->fType)
            //         : name + "::Vector{" + generateType(array_typed->fType) + "}";
            return name;
        } else {
            faustassert(false);
            return "";
        }
    }
};

#endif
