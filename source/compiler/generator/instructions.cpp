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

#include "instructions.hh"
#include "floats.hh"
#include "global.hh"
#include "sigtype.hh"
#include "fir_to_fir.hh"

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

//-----------------------
// Coding Types as trees
//-----------------------

// // 09/12/11 : HACK
/*
static Sym TYPEINT = symbol("TypeInt");
Tree  typeInt() { return tree(TYPEINT); }
bool  isTypeInt(Tree t) { return isTree(t, TYPEINT); }

static Sym TYPEFLOAT = symbol ("TypeFloat");
Tree  typeFloat() { return tree(TYPEFLOAT); }
bool  isTypeFloat(Tree t) { return isTree(t, TYPEFLOAT); }

static Sym TYPEARRAY = symbol("TypeArray");
Tree  typeArray(int n, Tree t) { return tree(TYPEARRAY, tree(n), t); }
bool  isTypeArray(Tree t, int* n, Tree& u) { Tree x; return isTree(t, TYPEARRAY, x, u) && isInt(x->node(), n); }

static property<DeclareTypeInst* > gFirTypeProperty;

map<std::string, int> InstBuilder::fIDCounters;

static Tree signalTypeToSharedType(AudioType* type)
{
    if (isSimpleType(type)) {
        if (type->nature() == kInt32) {
            return typeInt();
        } else if (type->nature() == kReal) {
            return typeFloat();
        } else {
            faustassert(false);
        }
    } else if (FaustVectorType* vec = isVectorType(type)) {
        return typeArray(vec->size(), signalTypeToSharedType(vec->dereferenceType()));
    } else {
        faustassert(false);
    }
}

DeclareTypeInst* InstBuilder::genType(AudioType* type)
{
    Tree shared_type = signalTypeToSharedType(type);
    DeclareTypeInst* dec_type;

    if (gFirTypeProperty.get(shared_type, dec_type)) {
        return dec_type;
    } else {
        if (isSimpleType(type)) {
            if (type->nature() == kInt32) {
                printf("FaustVectorType intType \n");
                dec_type = genDeclareTypeInst(InstBuilder::genInt32Typed());
            } else if (type->nature() == kReal) {
                printf("FaustVectorType floatType \n");
                dec_type = genDeclareTypeInst(InstBuilder::genFloatTyped());
            } else {
                faustassert(false);
            }
        } else if (FaustVectorType* vec = isVectorType(type)) {
            printf("FaustVectorType size %d\n", vec->size());
            DeclareTypeInst* sub_type = genType(vec->dereferenceType());
            dec_type = genDeclareTypeInst(
                    genStructTyped(getFreshID("vecType"),
                    InstBuilder::genArrayTyped(sub_type->fType, vec->size())));
        } else {
            faustassert(false);
        }
    }

    gFirTypeProperty.set(shared_type, dec_type);
    return dec_type;
}

static Typed* sharedTypeToFirType(Tree t)
{
    int size;
    Tree subtree;

    if (isTypeInt(t)) {
        printf("sharedTypeToFirType isTypeInt\n");
        return InstBuilder::genInt32Typed();
    } else if (isTypeFloat(t)) {
        printf("sharedTypeToFirType isTypeFloat\n");
        return InstBuilder::genFloatTyped();
    } else if (isTypeArray(t, &size, subtree)) {
        printf("sharedTypeToFirType isTypeArray size %d\n", size);
        return InstBuilder::genArrayTyped(sharedTypeToFirType(subtree), size);
    } else {
        faustassert(false);
        return nullptr;
    }
}

DeclareTypeInst* InstBuilder::genType(AudioType* type)
{
    Tree shared_type = signalTypeToSharedType(type);
    DeclareTypeInst* dec_type;

    if (gFirTypeProperty.get(shared_type, dec_type)) {
        return dec_type;
    } else {
        DeclareTypeInst* dec_type
            = genDeclareTypeInst(getFreshID("vecType"), sharedTypeToFirType(shared_type));
        gFirTypeProperty.set(shared_type, dec_type);
        return dec_type;
    }
}
*/