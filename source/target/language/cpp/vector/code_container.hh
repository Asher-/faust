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

#ifndef __CPP_VECTOR_CODE_CONTAINER_HH__
#define __CPP_VECTOR_CODE_CONTAINER_HH__

#include "vec_code_container.hh"

#include "target/language/cpp/code_container.hh"

/**
 Implement C++ FIR vector container.
 */

class CPPVectorCodeContainer : public VectorCodeContainer, public CPPCodeContainer {
   protected:
   public:
    CPPVectorCodeContainer(const std::string& name, const std::string& super, int numInputs, int numOutputs, std::ostream* out);
    virtual ~CPPVectorCodeContainer()
    {}

    void generateCompute(int tab);
};

#endif
