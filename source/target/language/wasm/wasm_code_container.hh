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

#ifndef _WASM_CODE_CONTAINER_H
#define _WASM_CODE_CONTAINER_H

#include "target/code_container.hh"
#include "compiler/dsp_factory/dsp_factory.hh"
#include "target/fir/fir_to_fir.hh"
#include "target/vector/vec_code_container.hh"
#include "wasm_instructions.hh"
#include "compiler/visitor/json_instruction_visitor.hh"

using namespace std;

class WASMCodeContainer : public virtual CodeContainer {
      WASMInstVisitor* _visitor = nullptr;;
   protected:
    std::ostream*          fOut;
    BufferWithRandomAccess fBinaryOut;
    std::stringstream      fHelper;
    int                    fInternalMemory;  // Whether memory is allocated inside wasm module or JS

    DeclareFunInst* generateInstanceInitFun(const string& name, const string& obj, bool ismethod, bool isvirtual);
    DeclareFunInst* generateClassInit(const string& name);
    DeclareFunInst* generateInstanceClear(const string& name, const string& obj, bool ismethod, bool isvirtual);
    DeclareFunInst* generateInstanceConstants(const string& name, const string& obj, bool ismethod, bool isvirtual);
    DeclareFunInst* generateInstanceResetUserInterface(const string& name, const string& obj, bool ismethod,
                                                       bool isvirtual);

    void generateComputeAux(BlockInst* compute_block);

    template <typename REAL>
    string generateJSON()
    {
        // JSON generation
        JSONInstVisitor<REAL> json_visitor_1;
        generateUserInterface(&json_visitor_1);

        PathTableType path_index_table;
        map<string, MemoryDesc>&      fieldTable1 = this->_visitor->getFieldTable();
        for (const auto& it : json_visitor_1.fPathTable) {
            faustassert(path_index_table.find(it.second) == path_index_table.end());
            // Get field index
            MemoryDesc tmp              = fieldTable1[it.first];
            path_index_table[it.second] = tmp.fOffset;
        }

        // "name", "filename" found in metadata
        JSONInstVisitor<REAL> json_visitor_2("", "", fNumInputs, fNumOutputs,
                                            -1, "", "", FAUSTVERSION, global::config().printCompilationOptions1(),
                                            global::config().gReader.listLibraryFiles(), global::config().gImportDirList,
                                            this->_visitor->getStructSize(), path_index_table, MemoryLayoutType());
        generateUserInterface(&json_visitor_2);
        generateMetaData(&json_visitor_2);

        return json_visitor_2.JSON(true);
    }

   public:
    WASMCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out,
                      bool internal_memory = true);
    virtual ~WASMCodeContainer() {}

    virtual void produceClass();
    virtual void generateCompute() = 0;

    void                      produceInternal() {}
    virtual dsp_factory_base* produceFactory();

    CodeContainer* createScalarContainer(const string& name, const Precision& precision);
    CodeContainer* createScalarContainer(const string& name, const Precision& precision, bool internal_memory = true);

    static CodeContainer* createContainer(const string& name, int numInputs, int numOutputs, std::ostream* dst,
                                          bool internal_memory);
};

class WASMScalarCodeContainer : public WASMCodeContainer {
   protected:
   public:
    WASMScalarCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out,
                            const Precision& precision, bool internal_memory);
    virtual ~WASMScalarCodeContainer() {}

    void generateCompute();
};

class WASMVectorCodeContainer : public VectorCodeContainer, public WASMCodeContainer {
   protected:
   public:
    WASMVectorCodeContainer(const string& name, int numInputs, int numOutputs, std::ostream* out, bool internal_memory);
    virtual ~WASMVectorCodeContainer() {}

    void generateCompute();
};

#endif
