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

#ifndef _FUNCTION_TYPED_
#define _FUNCTION_TYPED_

#include "compiler/types/basic_typed.hh"
#include "compiler/types/named_typed.hh"
#include "compiler/types/is_type.hh"
#include "compiler/type_manager/Text.hh"
#include "compiler/types/typed.hh"

struct FunTyped : public Typed {
    enum FunAttribute { kDefault = 0x1, kLocal = 0x2, kVirtual = 0x4, kStatic = 0x8, kStaticConstExpr = 0x10, kInline = 0x20 };

    Names         fArgsTypes;
    BasicTyped*   fResult;
    FunAttribute  fAttribute;

    FunTyped(const Names& args, BasicTyped* result, FunAttribute attribute = kDefault)
        : fArgsTypes(args), fResult(result), fAttribute(attribute)
    {
    }

    VarType getType() const { return fResult->getType(); }

    Typed* getTyped() { return fResult; }

    // Arguments type encoded as a string
    std::string getPrototype()
    {
        std::string res, sep = "[";
        if (fArgsTypes.size() > 0) {
            for (const auto& it : fArgsTypes) {
                res += sep + gTypeString[it->getType()];
                sep =  ":";
            }
            res += "]";
        } else {
            res = "[void]";
        }
        return res;
    }

    // Check if 'name' is paired with another argument, like "fRec0" and "fRec0_tmp" when generating functions in -fun mode
    bool isPairedFunArg(const std::string& name)
    {
        for (const auto& it : fArgsTypes) {
            if (isPtrType(it->getType()) && (name != it->fName) && (startWith(it->fName, name) || startWith(name, it->fName))) return true;
        }
        return false;
    }

    int getSizeBytes() const;  // moved in "instructions.cpp"

    virtual void accept(InstVisitor* visitor) { visitor->visit(this); }

    Typed* clone(CloneVisitor* cloner) { return cloner->visit(this); }
};

#endif
