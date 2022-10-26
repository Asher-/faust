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

#ifndef __FAUST_CONTROL_EXPANDER_HH__
#define __FAUST_CONTROL_EXPANDER_HH__

#include "visitor/basic_clone_visitor.hh"
#include "instruction/value_instruction.hh"
#include "instruction/control_flow/if_instruction.hh"
#include "instruction/statement_instruction.hh"

// Expand and rewrite ControlInst as 'IF (cond) {....}' instructions
struct ControlExpander : public BasicCloneVisitor {

    // To keep the current condition with the IfInst block which is progressively filled
    struct IfBlock {

        ValueInst* fCond;
        IfInst* fIfInst;

        IfBlock() { init(); }
        void init()
        {
            fCond = nullptr;
            fIfInst = nullptr;
        }
    };

    std::stack<BlockInst*> fBlockStack;
    std::stack<IfBlock> fIfBlockStack;

    void beginCond(ControlInst* inst);
    void continueCond(ControlInst* inst);
    void endCond();

    StatementInst* visit(ControlInst* inst);
    StatementInst* visit(BlockInst* inst);

};

#endif
