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

#ifndef _CPP_CODE_CONTAINER_H
#define _CPP_CODE_CONTAINER_H

#include "compiler/dsp_factory/dsp_factory.hh"

#include "target/language/cpp/visitor/instruction.hh"

/**
 * Implement C++ FIR base container.
 */

class CPPCodeContainer : public virtual CodeContainer {
   protected:
    CPPInstVisitor* fCodeProducer;
    std::ostream*  fOut;
    std::string    fSuperKlassName;

    void produceMetadata(int tabs);
    void produceInit(int tabs);

    std::string genVirtual();
    std::string genFinal();

   public:
    CPPCodeContainer()
    {}
    CPPCodeContainer(const std::string& name, const std::string& super, int numInputs, int numOutputs, std::ostream* out) : fSuperKlassName(super)
    {
        initialize(numInputs, numOutputs);
        fKlassName = name;
        fOut = out;

        // For mathematical functions
        if (global::config().gFastMath) {
            addIncludeFile((global::config().gFastMathLib == "def") ? "\"faust/dsp/fastmath.cpp\""
                                                            : ("\"" + global::config().gFastMathLib + "\""));
        } else {
            addIncludeFile("<cmath>");
            addIncludeFile("<algorithm>");
            // For int64_t type
            addIncludeFile("<cstdint>");
        }

        fCodeProducer = new CPPInstVisitor(out);
    }

    virtual ~CPPCodeContainer()
    {
        // fCodeProducer is a 'Garbageable'
    }

    virtual void produceClass();
    virtual void generateCompute(int tab) = 0;
    virtual void produceInternal();

    virtual dsp_factory_base* produceFactory();

    virtual void printHeader()
    {
        CodeContainer::printHeader(*fOut);

        tab(0, *fOut);
        *fOut << "#ifndef  __" << global::config().gClassName << "_H__";
        tab(0, *fOut);
        *fOut << "#define  __" << global::config().gClassName << "_H__" << std::endl << std::endl;
    }

    virtual void printFloatDef() { printfloatdef(*fOut); }

    virtual void printFooter()
    {
        tab(0, *fOut);
        *fOut << "#endif" << std::endl;
    }

    CodeContainer* createScalarContainer(const std::string& name, int sub_container_type);
    static CodeContainer* createScalarContainer(const std::string& name, const std::string& super, int numInputs, int numOutputs, ostream* dst, int sub_container_type);

    static CodeContainer* createContainer(const std::string& name, const std::string& super, int numInputs, int numOutputs,
                                          ostream* dst = new std::stringstream());
};


#endif
