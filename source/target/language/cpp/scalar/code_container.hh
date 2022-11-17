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

#ifndef __CPP_SCALAR_CODE_CONTAINER_HH__
#define __CPP_SCALAR_CODE_CONTAINER_HH__

#include "target/language/cpp/code_container.hh"

/**
 * Implement C++ FIR scalar container.
 */

class CPPScalarCodeContainer : public CPPCodeContainer {
   protected:
   public:
    CPPScalarCodeContainer()
    {}
    CPPScalarCodeContainer(const std::string& name, const std::string& super, int numInputs, int numOutputs, std::ostream* out,
                           int sub_container_type);
    virtual ~CPPScalarCodeContainer()
    {}

    void generateCompute(int tab);
};

#endif
