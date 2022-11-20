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

#ifndef _WAST_CODE_CONTAINER_H
#define _WAST_CODE_CONTAINER_H

#include "target/code_container.hh"
#include "compiler/dsp_factory/dsp_factory.hh"
#include "target/fir/fir_to_fir.hh"
#include "vec_code_container.hh"
#include "wast_instructions.hh"
#include "compiler/visitor/json_instruction_visitor.hh"

using namespace std;

class WASTCodeContainer : public virtual CodeContainer {
      WASTInstVisitor* _visitor = nullptr;;
   protected:
    std::ostream*     fOut;
    std::stringstream fOutAux;
    std::stringstream fHelper;
    int               fInternalMemory;

    void generateWASTBlock(BlockInst* block)
    {
        // Moves all variables declaration at the beginning of the block
        MoveVariablesInFront3 mover;
        BlockInst*            block_res = mover.getCode(block);
        block_res->accept(this->_visitor);
    }

    DeclareFunInst* generateInstanceInitFun(const string& name, const string& obj, bool ismethod, bool isvirtual);

    void generateComputeAux1(int n);
    void generateComputeAux2(BlockInst* compute_block, int n);

    template <typename REAL>
    string generateJSON()
    {
        // JSON generation
        JSONInstVisitor<REAL> json_visitor_1;
        generateUserInterface(&json_visitor_1);

        PathTableType path_index_table;
        map<string, MemoryDesc>& fieldTable1 = this->_visitor->getFieldTable();
        for (const auto& it : json_visitor_1.fPathTable) {
            faustassert(path_index_table.find(it.second) == path_index_table.end());
            // Get field index
            MemoryDesc tmp              = fieldTable1[it.first];
            path_index_table[it.second] = tmp.fOffset;
        }

        // "name", "filename" found in medata
        JSONInstVisitor<REAL> json_visitor_2("", "", fNumInputs, fNumOutputs, -1,
                                            "", "", FAUSTVERSION, global::config().printCompilationOptions1(),
                                            global::config().gReader.listLibraryFiles(), global::config().gImportDirList,
                                            this->_visitor->getStructSize(), path_index_table, MemoryLayoutType());
        generateUserInterface(&json_visitor_2);
        generateMetaData(&json_visitor_2);

        return json_visitor_2.JSON(true);
    }

   public:
    WASTCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out, bool internal_memory);
    virtual ~WASTCodeContainer() {}

    virtual void produceClass();
    virtual void generateCompute(int tab) = 0;

    void                      produceInternal() {}
    virtual dsp_factory_base* produceFactory();

    CodeContainer* createScalarContainer(const string& name, const Precision& precision);
    CodeContainer* createScalarContainer(const string& name, const Precision& precision, bool internal_memory = true);

    static CodeContainer* createContainer(const string& name, int numInputs, int numOutputs, std::ostream* dst,
                                          bool internal_memory);
};

class WASTScalarCodeContainer : public WASTCodeContainer {
   protected:
   public:
    WASTScalarCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out,
                            const Precision& precision, bool internal_memory);
    virtual ~WASTScalarCodeContainer() {}

    void generateCompute(int tab);
};

class WASTVectorCodeContainer : public VectorCodeContainer, public WASTCodeContainer {
   protected:
   public:
    WASTVectorCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out, bool internal_memory);
    virtual ~WASTVectorCodeContainer() {}

    void generateCompute(int tab);
};

#endif
