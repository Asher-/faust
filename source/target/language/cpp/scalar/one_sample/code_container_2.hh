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

#ifndef __CPP_SCALAR_ONE_SAMPLE_CODE_CONTAINER_2_HH__
#define __CPP_SCALAR_ONE_SAMPLE_CODE_CONTAINER_2_HH__

#include "target/language/cpp/scalar/code_container.hh"

/**
 * Implement C++ FIR scalar container (special version for -os1 generation mode with iZone and fZone).
 */

class CPPScalarOneSampleCodeContainer2 : public CPPScalarCodeContainer {
    protected:
        virtual void produceClass();
    public:
        CPPScalarOneSampleCodeContainer2()
        {}
        CPPScalarOneSampleCodeContainer2(const std::string& name, const std::string& super, int numInputs, int numOutputs, std::ostream* out,
                                         int sub_container_type)
        {
            initialize(numInputs, numOutputs);
            fKlassName = name;
            fOut = out;

            // For mathematical functions
            if (gGlobal->gFastMath) {
                addIncludeFile((gGlobal->gFastMathLib == "def") ? "\"faust/dsp/fastmath.cpp\""
                               : ("\"" + gGlobal->gFastMathLib + "\""));
            } else {
                addIncludeFile("<cmath>");
                addIncludeFile("<algorithm>");
                // For int64_t type
                addIncludeFile("<cstdint>");
            }

            fCodeProducer = new CPPInstVisitor1(out);
        }
        virtual ~CPPScalarOneSampleCodeContainer2()
        {}

        void generateCompute(int tab);
};

#endif
