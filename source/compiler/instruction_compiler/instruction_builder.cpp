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

#include "compiler/instruction_compiler/instruction_builder.hh"
#include "compiler/types/floats.hh"
#include "global.hh"

BasicTyped* InstBuilder::genItFloatTyped() { return genBasicTyped(itfloat()); }

ValueInst* InstBuilder::genTypedZero(Typed::VarType type)
{
    if (type == Typed::kInt32) {
        return genInt32NumInst(0);
    } else if (type == Typed::kInt64) {
        return genInt64NumInst(0);
    } else if (isRealType(type)) {
        return genRealNumInst(type, 0.0);
    } else {
        // Pointer type
        if (gGlobal->gMachinePtrSize == 4) {
            return genInt32NumInst(0);
        } else {
            return genInt64NumInst(0);
        }
    }
}

// Handle all possible cast at compile time, and use genCastInst only with the 'unknown at compile time' kFloatMacro
ValueInst* InstBuilder::genRealNumInst(Typed::VarType ctype, double num)
{
    if (ctype == Typed::kFloat) {
        return new FloatNumInst(float(num));
    } else if (ctype == Typed::kFloatMacro) {
        if (gGlobal->gFAUSTFLOAT2Internal) {
            return genRealNumInst(itfloat(), num);
        } else {
            return genCastInst(new DoubleNumInst(num), genBasicTyped(Typed::kFloatMacro));
        }
    } else if (ctype == Typed::kDouble) {
        return new DoubleNumInst(num);
    } else if (ctype == Typed::kQuad) {
        return new DoubleNumInst(num);
    } else if (ctype == Typed::kFixedPoint) {
        return new FixedPointNumInst(num);
    } else {
        faustassert(false);
    }
    return nullptr;
}

ValueInst* InstBuilder::genTypedNum(Typed::VarType type, double num)
{
    if (type == Typed::kInt32) {
        return genInt32NumInst(int(num));
    } else if (type == Typed::kInt64) {
        return genInt64NumInst(int64_t(num));
    } else if (isRealType(type)) {
        return genRealNumInst(type, num);
    } else {
        faustassert(false);
    }
    return nullptr;
}

BasicTyped* InstBuilder::genBasicTyped(Typed::VarType type)
{
    return gGlobal->genBasicTyped(type);
}

// Function argument variable types are kept in the global num <===> type table
NamedTyped* InstBuilder::genNamedTyped(const std::string& name, Typed* type)
{
    if (gGlobal->gVarTypeTable.find(name) == gGlobal->gVarTypeTable.end()) {
        // cout << "InstBuilder::genNamedTyped " << name << " " << Typed::gTypeString[type->getType()] << endl;
        gGlobal->gVarTypeTable[name] = type;
    }
    return new NamedTyped(name, type);
}

// Function argument variable types are kept in the global num <===> type table
NamedTyped* InstBuilder::genNamedTyped(const std::string& name, Typed::VarType type)
{
    return genNamedTyped(name, genBasicTyped(type));
}

// Casting
ValueInst* InstBuilder::genCastRealInst(ValueInst* inst)
{
    return InstBuilder::genCastInst(inst, InstBuilder::genItFloatTyped());
}

ValueInst* InstBuilder::genCastFloatMacroInst(ValueInst* inst)
{
    return InstBuilder::genCastInst(inst, InstBuilder::genFloatMacroTyped());
}

ValueInst* InstBuilder::genCastInt32Inst(ValueInst* inst)
{
    return InstBuilder::genCastInst(inst, InstBuilder::genInt32Typed());
}

// Function calls
DeclareFunInst* InstBuilder::genVoidFunction(const std::string& name, BlockInst* code)
{
    Names args;
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped());
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genVoidFunction(const std::string& name, Names& args, BlockInst* code,
                                             bool isvirtual)
{
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genVoidTyped(),
                                                  (isvirtual) ? FunTyped::kVirtual : FunTyped::kDefault);
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction0(const std::string& name, Typed::VarType res, BlockInst* code)
{
    Names args;
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction1(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction2(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                          BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    args.push_back(InstBuilder::genNamedTyped(arg2, arg2_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction3(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                          const std::string& arg3, Typed::VarType arg3_ty, BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    args.push_back(InstBuilder::genNamedTyped(arg2, arg2_ty));
    args.push_back(InstBuilder::genNamedTyped(arg3, arg3_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction4(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                          const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                          Typed::VarType arg4_ty, BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    args.push_back(InstBuilder::genNamedTyped(arg2, arg2_ty));
    args.push_back(InstBuilder::genNamedTyped(arg3, arg3_ty));
    args.push_back(InstBuilder::genNamedTyped(arg4, arg4_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction5(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                          const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                          Typed::VarType arg4_ty, const std::string& arg5, Typed::VarType arg5_ty,
                                          BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    args.push_back(InstBuilder::genNamedTyped(arg2, arg2_ty));
    args.push_back(InstBuilder::genNamedTyped(arg3, arg3_ty));
    args.push_back(InstBuilder::genNamedTyped(arg4, arg4_ty));
    args.push_back(InstBuilder::genNamedTyped(arg5, arg5_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}

DeclareFunInst* InstBuilder::genFunction6(const std::string& name, Typed::VarType res, const std::string& arg1,
                                          Typed::VarType arg1_ty, const std::string& arg2, Typed::VarType arg2_ty,
                                          const std::string& arg3, Typed::VarType arg3_ty, const std::string& arg4,
                                          Typed::VarType arg4_ty, const std::string& arg5, Typed::VarType arg5_ty,
                                          const std::string& arg6, Typed::VarType arg6_ty, BlockInst* code)
{
    Names args;
    args.push_back(InstBuilder::genNamedTyped(arg1, arg1_ty));
    args.push_back(InstBuilder::genNamedTyped(arg2, arg2_ty));
    args.push_back(InstBuilder::genNamedTyped(arg3, arg3_ty));
    args.push_back(InstBuilder::genNamedTyped(arg4, arg4_ty));
    args.push_back(InstBuilder::genNamedTyped(arg5, arg5_ty));
    args.push_back(InstBuilder::genNamedTyped(arg6, arg6_ty));
    FunTyped* fun_type = InstBuilder::genFunTyped(args, InstBuilder::genBasicTyped(res));
    return InstBuilder::genDeclareFunInst(name, fun_type, code);
}
