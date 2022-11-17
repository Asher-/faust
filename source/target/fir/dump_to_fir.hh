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

#ifndef __FAUST__DUMP_TO_FIR_HH__
#define __FAUST__DUMP_TO_FIR_HH__

#include "target/fir/fir_instructions.hh"

// Tools to dump FIR
inline void dump2FIR(StatementInst* inst, std::ostream& out = cerr, bool complete = true)
{
    std::stringstream str;
    if (complete) str << "========== dump2FIR " << inst << " statement begin ========== " << std::endl;
    FIRInstVisitor fir_visitor(&str);
    inst->accept(&fir_visitor);
    if (complete) str << "========== dump2FIR statement end ==========" << std::endl;
    out << str.str();
}

inline void dump2FIR(ValueInst* value, std::ostream& out = cerr, bool complete = true)
{
    std::stringstream str;
    if (complete) str << "========== dump2FIR " << value << " value begin ========== " << std::endl;
    FIRInstVisitor fir_visitor(&str);
    value->accept(&fir_visitor);
    if (complete) str << "\n========== dump2FIR value end ==========" << std::endl;
    out << str.str();
}

inline void dump2FIR(Address* address, std::ostream& out = cerr, bool complete = true)
{
    std::stringstream str;
    if (complete) str << "========== dump2FIR " << address << " address begin ========== " << std::endl;
    FIRInstVisitor fir_visitor(&str);
    address->accept(&fir_visitor);
    if (complete) str << "\n========== dump2FIR address end ==========" << std::endl;
    out << str.str();
}

inline void dump2FIR(Typed* type, std::ostream& out = cerr, bool complete = true)
{
    std::stringstream str;
    if (complete) str << "========== dump2FIR " << type << " type begin ========== " << std::endl;
    FIRInstVisitor fir_visitor(&str);
    str << fir_visitor.generateType(type);
    if (complete) str << "\n========== dump2FIR type end ==========" << std::endl;
    out << str.str();
}

#endif
