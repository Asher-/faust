/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
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

#ifndef _CMAJ_CODE_CONTAINER_H
#define _CMAJ_CODE_CONTAINER_H

#include "target/code_container.hh"
#include "omp_code_container.hh"

#include "vec_code_container.hh"
#include "wss_code_container.hh"

#include "target/language/cmajor/visitor/instruction.hh"
#include "target/language/cmajor/visitor/table_size.hh"
#include "target/language/cmajor/visitor/table_size_clone.hh"
#include "target/language/cmajor/visitor/ui_instruction.hh"
#include "target/language/cmajor/visitor/sub_container_instruction.hh"

class CmajorCodeContainer : public virtual CodeContainer {
    TableSizeVisitor* _visitor = nullptr;

   protected:
    CmajorInstVisitor fCodeProducer;
    CmajorInstUIVisitor fUIVisitor;
    std::ostream*   fOut;

    void produceInit(int tabs);

    virtual void printHeader() { CodeContainer::printHeader(*fOut); }

   protected:
    CmajorCodeContainer(const string& name, int numInputs, int numOutputs, ostream* out) : fCodeProducer(out), fOut(out)
    {
        initialize(numInputs, numOutputs);
        fKlassName = name;

        if (!this->_visitor) {
            this->_visitor = new TableSizeVisitor();
        }
    }

    CodeContainer* createScalarContainer(const string& name, int sub_container_type);
    void           produceInternal();
    void           produceClass();
    virtual void   generateCompute(int tab) = 0;

    virtual dsp_factory_base* produceFactory();

   public:
    static CodeContainer* createContainer(const string& name, int numInputs, int numOutputs, ostream* dst);
};

#endif
