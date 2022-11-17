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

#ifndef __CPP_SCALAR_ONE_SAMPLE_CODE_CONTAINER_3_HH__
#define __CPP_SCALAR_ONE_SAMPLE_CODE_CONTAINER_3_HH__

#include "target/language/cpp/scalar/one_sample/code_container_2.hh"

/**
 Implement C++ FIR scalar container (special version for -os2 generation mode with iZone and fZone). Some of the DSP struct fields will be moved in the iZone/fZone (typically long delay lines). The others will stay in the DSP structure.
 */

class CPPScalarOneSampleCodeContainer3 : public CPPScalarOneSampleCodeContainer2 {
    protected:
        virtual void produceClass();
    public:
        CPPScalarOneSampleCodeContainer3(const std::string& name, const std::string& super, int numInputs, int numOutputs, std::ostream* out,
                                         int sub_container_type)
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

            // Setup in produceClass
            fCodeProducer = nullptr;
        }
        virtual ~CPPScalarOneSampleCodeContainer3()
        {}

};

#endif
