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

#ifndef _STRING_TYPE_MANAGER_C_
#define _STRING_TYPE_MANAGER_C_

 #include "string_type_manager.hh"

// StringTypeManager for C/C++, Java and FIR backends

class CStringTypeManager : public StringTypeManager {
   public:
    CStringTypeManager(const std::string& float_macro_name, const std::string& ptr_ref, const std::string& struct_name = "")
        : StringTypeManager(float_macro_name, ptr_ref)
    {
        fPtrRef = ptr_ref;

        fTypeDirectTable[Typed::kInt32]     = "int";
        fTypeDirectTable[Typed::kInt32_ptr] = "int" + fPtrRef;
        fTypeDirectTable[Typed::kInt32_vec] = "vector<int>";

        fTypeDirectTable[Typed::kInt64]     = "int64_t";
        fTypeDirectTable[Typed::kInt64_ptr] = "int64_t" + fPtrRef;
        fTypeDirectTable[Typed::kInt64_vec] = "vector<int64_t>";

        fTypeDirectTable[Typed::kFloat]         = "float";
        fTypeDirectTable[Typed::kFloat_ptr]     = "float" + fPtrRef;
        fTypeDirectTable[Typed::kFloat_ptr_ptr] = "float" + fPtrRef + fPtrRef;
        fTypeDirectTable[Typed::kFloat_vec]     = "vector<float>";

        fTypeDirectTable[Typed::kDouble]         = "double";
        fTypeDirectTable[Typed::kDouble_ptr]     = "double" + fPtrRef;
        fTypeDirectTable[Typed::kDouble_ptr_ptr] = "double" + fPtrRef + fPtrRef;
        fTypeDirectTable[Typed::kDouble_vec]     = "vector<double>";

        fTypeDirectTable[Typed::kQuad]         = "quad";
        fTypeDirectTable[Typed::kQuad_ptr]     = "quad" + fPtrRef;
        fTypeDirectTable[Typed::kQuad_ptr_ptr] = "quad" + fPtrRef + fPtrRef;
        fTypeDirectTable[Typed::kQuad_vec]     = "vector<quad>";

        fTypeDirectTable[Typed::kFixedPoint]     = "fixpoint_t";
        fTypeDirectTable[Typed::kFixedPoint_ptr] = "fixpoint_t" + fPtrRef;
        fTypeDirectTable[Typed::kFixedPoint_ptr] = "fixpoint_t" + fPtrRef + fPtrRef;
        fTypeDirectTable[Typed::kFixedPoint_vec] = "vector<fixpoint_t>";

        fTypeDirectTable[Typed::kBool]     = "bool";
        fTypeDirectTable[Typed::kBool_ptr] = "bool" + fPtrRef;
        fTypeDirectTable[Typed::kBool_vec] = "vector<bool>";

        fTypeDirectTable[Typed::kVoid]     = "void";
        fTypeDirectTable[Typed::kVoid_ptr] = "void" + fPtrRef;

        fTypeDirectTable[Typed::kSound]     = "Soundfile";
        fTypeDirectTable[Typed::kSound_ptr] = "Soundfile" + fPtrRef;

        // DSP has to be empty here
        fTypeDirectTable[Typed::kObj]     = struct_name;
        fTypeDirectTable[Typed::kObj_ptr] = struct_name + fPtrRef;

        fTypeDirectTable[Typed::kUint_ptr] = "uintptr_t";
    }

    virtual std::string generateType(Typed* type, NamedTyped::Attribute attr = NamedTyped::kDefault)
    {
        BasicTyped* basic_typed = dynamic_cast<BasicTyped*>(type);
        NamedTyped* named_typed = dynamic_cast<NamedTyped*>(type);
        ArrayTyped* array_typed = dynamic_cast<ArrayTyped*>(type);
        StructTyped* struct_typed = dynamic_cast<StructTyped*>(type);

        if (basic_typed) {
            return fTypeDirectTable[basic_typed->fType];
        } else if (named_typed) {
            return generateType(named_typed->fType) + NamedTyped::AttributeMap[attr] + named_typed->fName;
        } else if (array_typed) {
            return fTypeDirectTable[array_typed->getType()];
        } else if (struct_typed) {
            std::string res = "typedef struct " + struct_typed->fName + " { ";
            for (const auto& it : struct_typed->fFields) {
                res = res + generateType(it) + "; ";
            }
            res += "} " + struct_typed->fName + ";";
            return res;
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
            return fTypeDirectTable[basic_typed->fType] + " " + name;
        } else if (named_typed) {
            return named_typed->fName + generateType(named_typed->fType) + " " + name;
        } else if (array_typed) {
            return (array_typed->fSize == 0)
                    ? generateType(array_typed->fType) + fPtrRef + " " + name
                    : generateType(array_typed->fType) + " " + name + "[" + std::to_string(array_typed->fSize) + "]";
        } else {
            faustassert(false);
            return "";
        }
    }
};

#endif
