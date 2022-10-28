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

#ifndef __FAUST_CAST_REMOVER_HH__
#define __FAUST_CAST_REMOVER_HH__

#include "visitor/basic_clone_visitor.hh"
#include "visitor/typing_instruction_visitor.hh"
#include "compiler/instruction/value/value_instruction.hh"
#include "compiler/instruction/cast/cast_instruction.hh"

// Remove unneeded cast
struct CastRemover : public BasicCloneVisitor {

    virtual ValueInst* visit(::CastInst* inst)
    {
        Typed::VarType value_type = TypingVisitor::getType(inst->fInst);
        Typed::VarType cast_type = inst->fType->getType();

        if (isInt32Type(cast_type)) {
            if (isInt32Type(value_type)) {
                //std::cerr << "CastInst : cast to int, but arg already int !" << std::endl;
                //dump2FIR(inst);
                return inst->fInst->clone(this);
            } else {
                /*
                // TODO = protection out-of [-2147483647, 2147483647] range
                ValueInst* max = InstBuilder::genRealNumInst(Typed::kFloat, double(std::numeric_limits<int>::max()));
                ValueInst* min = InstBuilder::genRealNumInst(Typed::kFloat, double(std::numeric_limits<int>::min()));

                return InstBuilder::genSelect2Inst(InstBuilder::genGreater(inst->fInst->clone(this), max),
                                                   InstBuilder::genInt32NumInst(std::numeric_limits<int>::max()),
                                                   InstBuilder::genSelect2Inst(InstBuilder::genLess(inst->fInst->clone(this), min),
                                                                               InstBuilder::genInt32NumInst(std::numeric_limits<int>::min()),
                                                                               BasicTypingCloneVisitor::visit(inst)));
                */
                return BasicCloneVisitor::visit(inst);
            }
        } else if (isRealType(cast_type)) {
            if (isRealType(value_type)) {
                //std::cerr << "CastInst : cast to real, but arg already real !" << std::endl;
                //dump2FIR(inst);
                return inst->fInst->clone(this);
            } else {
                return BasicCloneVisitor::visit(inst);
            }
        } else {
            return BasicCloneVisitor::visit(inst);
        }
    }

};

#endif
