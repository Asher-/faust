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

#ifndef _DLANG_CODE_CONTAINER_H
#define _DLANG_CODE_CONTAINER_H

#include "target/code_container.hh"
#include "target/language/dlang/dlang_instructions.hh"
#include "compiler/dsp_factory/dsp_factory.hh"
#include "target/openmp/omp_code_container.hh"
#include "target/vector/vec_code_container.hh"
#include "target/wss/wss_code_container.hh"

#ifdef WIN32
#pragma warning(disable : 4250)
#endif

using namespace std;

class DLangCodeContainer : public virtual CodeContainer {
   protected:
    DLangInstVisitor _codeProducer;
    std::ostream*  fOut;
    string         fSuperKlassName;

    void produceMetadata(int tabs);
    void produceInit(int tabs);

   public:
    DLangCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out)
        : _codeProducer(out), fOut(out), fSuperKlassName(super)
    {
        initialize(numInputs, numOutputs);
        fKlassName = name;
    }

    virtual ~DLangCodeContainer() {}

    virtual void produceClass();
    virtual void generateCompute(int tab) = 0;
    virtual void produceInternal();
  
    void generateImports();
    static string dModuleName(const string& klassName);

    virtual dsp_factory_base* produceFactory();

    virtual void printHeader();

    static void printDRecipeComment(ostream& dst, const string& klassName);
    static void printDModuleStmt(ostream& dst, const string& klassName);

    CodeContainer* createScalarContainer(const string& name, const Precision& precision);

    static CodeContainer* createContainer(const string& name, const string& super, int numInputs, int numOutputs,
                                          ostream* dst = new stringstream());
};

class DLangScalarCodeContainer : public DLangCodeContainer {
   protected:
   public:
    DLangScalarCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out,
                           const Precision& precision);
    virtual ~DLangScalarCodeContainer()
    {}

    void generateCompute(int tab);
};

class DLangScalarOneSampleCodeContainer : public DLangScalarCodeContainer {
   protected:
    virtual void produceClass();
   public:
    DLangScalarOneSampleCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out,
                                    const Precision& precision)
    : DLangScalarCodeContainer(name, super, numInputs, numOutputs, out, precision)
    {}
    virtual ~DLangScalarOneSampleCodeContainer()
    {}

    void generateCompute(int tab);
};

class DLangVectorCodeContainer : public VectorCodeContainer, public DLangCodeContainer {
   protected:
   public:
    DLangVectorCodeContainer(const string& name, const string& super, int numInputs, int numOutputs, std::ostream* out);
    virtual ~DLangVectorCodeContainer()
    {}

    void generateCompute(int tab);
};

#endif
