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

#ifndef __SOUL__SCALAR__CODE_CONTAINER_HH__
#define __SOUL__SCALAR__CODE_CONTAINER_HH__

#include "target/language/soul/code_container.hh"

class SOULScalarCodeContainer : public SOULCodeContainer {
   private:
   public:
    SOULScalarCodeContainer(const string& name, int numInputs, int numOutputs, int sub_container_type, ostream* dst)
        : SOULCodeContainer(name, numInputs, numOutputs, dst)
    {
        fSubContainerType = sub_container_type;
    }

    void generateCompute(int tab);
};

#endif