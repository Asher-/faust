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

#ifndef _INTERPRETER_CODE_CONTAINER_H
#define _INTERPRETER_CODE_CONTAINER_H

#include "target/code_container.hh"
#include "target/fir/fir_to_fir.hh"
#include "compiler/instruction_compiler/instruction_compiler.hh"
#include "interpreter_dsp.hh"
#include "compiler/visitor/interpreter_instruction_visitor.hh"
#include "target/vector/vec_code_container.hh"

#include "faust/primitive/type/precision.hh"

using namespace std;

template <class REAL>
class InterpreterCodeContainer : public virtual CodeContainer {
   protected:
    InterpreterInstVisitor<REAL>* _visitor = nullptr;;

    FIRMetaBlockInstruction* produceMetadata(string& name);

    virtual void generateSR()
    {
        if (!fGeneratedSR) {
            pushDeclare(InstBuilder::genDecStructVar("fSampleRate", InstBuilder::genInt32Typed()));
        }
    }

    // To be implemented in each InterpreterScalarCodeContainer and InterpreterVectorCodeContainer classes
    virtual FBCBlockInstruction<REAL>* generateCompute() = 0;

    FBCBlockInstruction<REAL>* getCurrentBlock();
    InterpreterInstVisitor<REAL>* getInterpreterVisitor();
    void setCurrentBlock(FBCBlockInstruction<REAL>* block);

   public:
    InterpreterCodeContainer(const string& name, int numInputs, int numOutputs);

    virtual ~InterpreterCodeContainer() {}

    void                      produceInternal() {}
    virtual dsp_factory_base* produceFactory();

    CodeContainer* createScalarContainer(const string& name, const Precision& precision);

    static CodeContainer* createContainer(const string& name, int numInputs, int numOutputs);
};

template <class REAL>
class InterpreterScalarCodeContainer : public InterpreterCodeContainer<REAL> {
   protected:

    using Precision = ::Faust::Primitive::Type::Precision;

    virtual FBCBlockInstruction<REAL>* generateCompute();

   public:
    InterpreterScalarCodeContainer(const string& name, int numInputs, int numOutputs, const Precision& precision);
    virtual ~InterpreterScalarCodeContainer();
};

template <class REAL>
class InterpreterVectorCodeContainer : public VectorCodeContainer, public InterpreterCodeContainer<REAL> {
   protected:
    virtual FBCBlockInstruction<REAL>* generateCompute();

   public:
    InterpreterVectorCodeContainer(const string& name, int numInputs, int numOutputs)
        : VectorCodeContainer(numInputs, numOutputs), InterpreterCodeContainer<REAL>(name, numInputs, numOutputs)
    {
    }
    virtual ~InterpreterVectorCodeContainer() {}
};

class InterpreterInstructionsCompiler : public virtual InstructionsCompiler {
   public:
    InterpreterInstructionsCompiler(CodeContainer* container) : InstructionsCompiler(container) {}

   protected:

    StatementInst* generateShiftArray(const string& vname, int delay) override
    {
        return InstBuilder::genShiftArrayVarInst(InstBuilder::genNamedAddress(vname, Address::kStruct), delay);
    }

    ValueInst* generateSoundfile(Tree sig, Tree path) override
    {
        string varname = global::config().getFreshID("fSoundfile");
        string SFcache = varname + "ca";

        addUIWidget(reverse(tl(path)), uiWidget(hd(path), tree(varname), sig));

        pushDeclare(InstBuilder::genDecStructVar(varname, InstBuilder::genBasicTyped(Typed::kSound_ptr)));

        if (global::config().gUseDefaultSound) {
            BlockInst* block = InstBuilder::genBlockInst();
            block->pushBackInst(InstBuilder::genStoreStructVar(varname, InstBuilder::genLoadGlobalVar("defaultsound")));

            pushResetUIInstructions(InstBuilder::genIfInst(
                InstBuilder::genEqual(InstBuilder::genCastInst(InstBuilder::genLoadStructVar(varname),
                        InstBuilder::genBasicTyped(Typed::kUint_ptr)),
                        InstBuilder::genTypedZero(Typed::kSound_ptr)),
                        block, InstBuilder::genBlockInst()));
        }

        return InstBuilder::genLoadStructVar(varname);
    }

    // Soundfile struct access are fully generated, instead of using intermediate local stack variables as in InstructionsCompiler

    // x = part
    ValueInst* generateSoundfileLength(Tree sig, ValueInst* sf, ValueInst* x) override
    {
        LoadVarInst* load = dynamic_cast<LoadVarInst*>(sf);
        faustassert(load);

        // In reverse order for the Interp stack
        vector<ValueInst*> indices = { x, InstBuilder::genInt32NumInst(Soundfile::kLength) };
        return InstBuilder::genLoadArrayStructVar(load->fAddress->getName(), indices);
    }

    // x = part
    ValueInst* generateSoundfileRate(Tree sig, ValueInst* sf, ValueInst* x) override
    {
        LoadVarInst* load = dynamic_cast<LoadVarInst*>(sf);
        faustassert(load);

        // In reverse order for the Interp stack
        vector<ValueInst*> indices = { x, InstBuilder::genInt32NumInst(Soundfile::kSR) };
        return InstBuilder::genLoadArrayStructVar(load->fAddress->getName(), indices);
    }

    // x = chan, y = part, z = ridx
    ValueInst* generateSoundfileBuffer(Tree sig, ValueInst* sf, ValueInst* x, ValueInst* y, ValueInst* z) override
    {
        LoadVarInst* load = dynamic_cast<LoadVarInst*>(sf);
        faustassert(load);

        // In reverse order for the Interp stack
        vector<ValueInst*> indices1 = { y, InstBuilder::genInt32NumInst(Soundfile::kOffset) };
        ValueInst* offset = InstBuilder::genLoadArrayStructVar(load->fAddress->getName(), indices1);
        // In reverse order for the Interp stack
        vector<ValueInst*> indices2 = { InstBuilder::genAdd(offset, z), x, InstBuilder::genInt32NumInst(Soundfile::kBuffers) };

        return InstBuilder::genLoadArrayStructVar(load->fAddress->getName(), indices2);
     }

};

#endif
