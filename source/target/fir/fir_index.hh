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

#ifndef _FIR_INDEX_
#define _FIR_INDEX_

struct InstBuilder; // Cyclic

/* Syntactic sugar for index computations.
 *
 * wrapper for ValueInst* with support for basic arithmetics
 *
 */
class FIRIndex {

  public:

    /* explicit constructors in order to avoid the generation of implicit conversions */
    explicit FIRIndex(ValueInst* inst) : fValue(inst) {}

    explicit FIRIndex(int num) : fValue(InstBuilder::genInt32NumInst(num)) {}

    FIRIndex(FIRIndex const& rhs) : fValue(rhs.fValue) {}

    /* implicitly convert to ValueInst* in order to simplify the usage */
    operator ValueInst*(void)const { return fValue; }

    // Add
    friend FIRIndex operator+(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genAdd(lhs.fValue, rhs));
    }

    friend FIRIndex operator+(FIRIndex const& lhs, FIRIndex const& rhs) { return operator+(lhs, rhs.fValue); }

    friend FIRIndex operator+(FIRIndex const& lhs, int rhs)
    {
        return operator+(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Sub
    friend FIRIndex operator-(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genSub(lhs.fValue, rhs));
    }

    friend FIRIndex operator-(FIRIndex const& lhs, FIRIndex const& rhs) { return operator-(lhs, rhs.fValue); }

    friend FIRIndex operator-(FIRIndex const& lhs, int rhs)
    {
        return operator-(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Mult
    friend FIRIndex operator*(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genMul(lhs.fValue, rhs));
    }

    friend FIRIndex operator*(FIRIndex const& lhs, FIRIndex const& rhs) { return operator*(lhs, rhs.fValue); }

    friend FIRIndex operator*(FIRIndex const& lhs, int rhs)
    {
        return operator*(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Div
    friend FIRIndex operator/(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genDiv(lhs.fValue, rhs));
    }

    friend FIRIndex operator/(FIRIndex const& lhs, FIRIndex const& rhs) { return operator/(lhs, rhs.fValue); }

    friend FIRIndex operator/(FIRIndex const& lhs, int rhs)
    {
        return operator/(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // And
    friend FIRIndex operator&(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genAnd(lhs.fValue, rhs));
    }

    friend FIRIndex operator&(FIRIndex const& lhs, FIRIndex const& rhs) { return operator&(lhs, rhs.fValue); }

    friend FIRIndex operator&(FIRIndex const& lhs, int rhs)
    {
        return operator&(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Modulo
    friend FIRIndex operator%(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genRem(lhs.fValue, rhs));
    }

    friend FIRIndex operator%(FIRIndex const& lhs, FIRIndex const& rhs) { return operator%(lhs, rhs.fValue); }

    friend FIRIndex operator%(FIRIndex const& lhs, int rhs)
    {
        return operator%(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Equal
    friend FIRIndex operator==(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genEqual(lhs.fValue, rhs));
    }

    friend FIRIndex operator==(FIRIndex const& lhs, FIRIndex const& rhs) { return operator==(lhs, rhs.fValue); }

    friend FIRIndex operator==(FIRIndex const& lhs, int rhs)
    {
        return operator==(lhs, InstBuilder::genInt32NumInst(rhs));
    }

    // Inf
    friend FIRIndex operator<(FIRIndex const& lhs, ValueInst* rhs)
    {
        return FIRIndex(InstBuilder::genLessThan(lhs.fValue, rhs));
    }

    friend FIRIndex operator<(FIRIndex const& lhs, FIRIndex const& rhs) { return operator<(lhs, rhs.fValue); }

    friend FIRIndex operator<(FIRIndex const& lhs, int rhs)
    {
        return operator<(lhs, InstBuilder::genInt32NumInst(rhs));
    }

   private:
    ValueInst* fValue;
};

Typed::VarType convert2FIRType(int type);

#endif
