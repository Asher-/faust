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

#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "compiler/types/floats.hh"
#include "global.hh"

#include "faust/primitive/math.hh"

using namespace std;

//-----------------------------------------------
// float size coding :
//-----------------------------------------------
//   0: external float (macro name)
//   1: single precision float
//   2: double precision float
//   3: long double precision float
//   4: fixed-point float

static const char* mathsuffix[5];       // suffix for math functions
static const char* numsuffix[5];        // suffix for numeric constants
static const char* floatname[5];        // float types
static const char* floatptrname[5];     // float ptr types
static const char* floatptrptrname[5];  // float ptr ptr types
static const char* castname[5];         // float castings
static double      floatmin[5];         // minimum float values before denormals

void ::Faust::Type::Float::init()
{
    // Using in FIR code generation to code math functions type (float/double/quad), same for Rust and C/C++ backends
    mathsuffix[0] = "";
    mathsuffix[1] = "f";
    mathsuffix[2] = "";
    mathsuffix[3] = "l";
    mathsuffix[4] = "";

    // Specific for Rust backend
    if (global::config().gOutputLang == "rust") {
        numsuffix[0] = "";
        numsuffix[1] = "";
        numsuffix[2] = "";
        numsuffix[3] = "";
        numsuffix[4] = "";

        floatname[0] = FLOATMACRO;
        floatname[1] = "F32";
        floatname[2] = "F64";
        floatname[3] = "dummy";
        floatname[4] = "dummy";

        floatptrname[0] = FLOATMACROPTR;
        floatptrname[1] = "F32*";
        floatptrname[2] = "F64*";
        floatptrname[3] = "dummy*";
        floatptrname[4] = "dummy*";

        floatptrptrname[0] = FLOATMACROPTRPTR;
        floatptrptrname[1] = "F32**";
        floatptrptrname[2] = "F64**";
        floatptrptrname[3] = "dummy**";
        floatptrptrname[4] = "dummy**";

        castname[0] = FLOATCASTER;
        castname[1] = "as F32";
        castname[2] = "as F64";
        castname[3] = "(dummy)";
        castname[4] = "(dummy)";

        floatmin[0] = 0;
        floatmin[1] = FLT_MIN;
        floatmin[2] = DBL_MIN;
        floatmin[3] = LDBL_MIN;
        floatmin[4] = FLT_MIN;

    // Specific for Julia backend
    } else  if (global::config().gOutputLang == "julia") {
        numsuffix[0] = "";
        numsuffix[1] = "f0";
        numsuffix[2] = "";
        numsuffix[3] = "";
        numsuffix[4] = "";

        floatname[0] = FLOATMACRO;
        floatname[1] = "Float32";
        floatname[2] = "Float64";
        floatname[3] = "dummy";
        floatname[4] = "dummy";

        floatptrname[0] = FLOATMACROPTR;
        floatptrname[1] = "Float32*";
        floatptrname[2] = "Float64*";
        floatptrname[3] = "dummy*";
        floatptrname[4] = "dummy*";

        floatptrptrname[0] = FLOATMACROPTRPTR;
        floatptrptrname[1] = "Float32**";
        floatptrptrname[2] = "Float64**";
        floatptrptrname[3] = "dummy**";
        floatptrptrname[4] = "dummy**";

        castname[0] = FLOATCASTER;
        castname[1] = "(Float32)";
        castname[2] = "(Float64)";
        castname[3] = "(dummy)";
        castname[4] = "(dummy)";

        floatmin[0] = 0;
        floatmin[1] = FLT_MIN;
        floatmin[2] = DBL_MIN;
        floatmin[3] = LDBL_MIN;
        floatmin[4] = FLT_MIN;

    // Specific for JAX backend
    } else  if (global::config().gOutputLang == "jax") {
        numsuffix[0] = "";
        numsuffix[1] = "";
        numsuffix[2] = "";
        numsuffix[3] = "";
        numsuffix[4] = "";

        floatname[0] = FLOATMACRO;
        floatname[1] = "jnp.float32";
        floatname[2] = "jnp.float64";
        floatname[3] = "dummy";
        floatname[4] = "dummy";

        floatptrname[0] = FLOATMACROPTR;
        floatptrname[1] = "jnp.float32*";
        floatptrname[2] = "jnp.float64*";
        floatptrname[3] = "dummy*";
        floatptrname[4] = "dummy*";

        floatptrptrname[0] = FLOATMACROPTRPTR;
        floatptrptrname[1] = "jnp.float32**";
        floatptrptrname[2] = "jnp.float64**";
        floatptrptrname[3] = "dummy**";
        floatptrptrname[4] = "dummy**";

        castname[0] = FLOATCASTER;
        castname[1] = "(jnp.float32)";
        castname[2] = "(jnp.float64)";
        castname[3] = "(dummy)";
        castname[4] = "(dummy)";

        floatmin[0] = 0;
        floatmin[1] = FLT_MIN;
        floatmin[2] = DBL_MIN;
        floatmin[3] = LDBL_MIN;
        floatmin[4] = FLT_MIN;

    // Specific for D backend
    } else if (global::config().gOutputLang == "dlang") {
        numsuffix[0] = "";
        numsuffix[1] = "";
        numsuffix[2] = "";
        numsuffix[3] = "";
        numsuffix[4] = "";

        floatname[0] = FLOATMACRO;
        floatname[1] = "float";
        floatname[2] = "double";
        floatname[3] = "real";
        floatname[4] = "dummy";

        floatptrname[0] = FLOATMACROPTR;
        floatptrname[1] = "float*";
        floatptrname[2] = "double*";
        floatptrname[3] = "real*";
        floatptrname[4] = "dummy*";

        floatptrptrname[0] = FLOATMACROPTRPTR;
        floatptrptrname[1] = "float**";
        floatptrptrname[2] = "double**";
        floatptrptrname[3] = "real**";
        floatptrptrname[4] = "dummy**";

        castname[0] = FLOATCASTER;
        castname[1] = "cast(float)";
        castname[2] = "cast(double)";
        castname[3] = "cast(real)";
        castname[4] = "cast(dummy)";

        floatmin[0] = 0;
        floatmin[1] = FLT_MIN;
        floatmin[2] = DBL_MIN;
        floatmin[3] = LDBL_MIN;
        floatmin[4] = FLT_MIN;

    // Specific for C/C++ backends
    } else {
        numsuffix[0] = "";
        numsuffix[1] = "f";
        numsuffix[2] = "";
        numsuffix[3] = "L";
        numsuffix[4] = "";

        floatname[0] = FLOATMACRO;
        floatname[1] = "float";
        floatname[2] = "double";
        floatname[3] = "quad";
        floatname[4] = "fixpoint_t";

        floatptrname[0] = FLOATMACROPTR;
        floatptrname[1] = "float*";
        floatptrname[2] = "double*";
        floatptrname[3] = "quad*";
        floatptrname[4] = "fixpoint_t*";

        floatptrptrname[0] = FLOATMACROPTRPTR;
        floatptrptrname[1] = "float**";
        floatptrptrname[2] = "double**";
        floatptrptrname[3] = "quad**";
        floatptrptrname[4] = "fixpoint_t**";

        castname[0] = FLOATCASTER;
        castname[1] = "(float)";
        castname[2] = "(double)";
        castname[3] = "(quad)";
        castname[4] = "(fixpoint_t)";

        floatmin[0] = 0;
        floatmin[1] = FLT_MIN;
        floatmin[2] = DBL_MIN;
        floatmin[3] = LDBL_MIN;
        floatmin[4] = FLT_MIN;
    }
}

///< suffix for math functions
const char* isuffix()
{
    return mathsuffix[::Faust::Primitive::Math::floatSize];
}

///< suffix for numeric constants
const char* inumix()
{
    return numsuffix[::Faust::Primitive::Math::floatSize];
}

const char* ifloat()
{
    return floatname[::Faust::Primitive::Math::floatSize];
}

const char* ifloatptr()
{
    return floatptrname[::Faust::Primitive::Math::floatSize];
}

const char* ifloatptrptr()
{
    return floatptrptrname[::Faust::Primitive::Math::floatSize];
}

const char* icast()
{
    return castname[::Faust::Primitive::Math::floatSize];
}

double inummin()
{
    return floatmin[::Faust::Primitive::Math::floatSize];
}

const char* xfloat()
{
    return floatname[0];
}

const char* xcast()
{
    return castname[0];
}

int ifloatsize()
{
    switch (::Faust::Primitive::Math::floatSize) {
        case 1:
            return global::config().gMachineFloatSize;
        case 2:
            return global::config().gMachineDoubleSize;
        case 3:
            return global::config().gMachineQuadSize;
        case 4:
            return global::config().gMachineFixedPointSize;
        default:
            faustassert(false);
            return 0;
    }
}

Typed::VarType itfloat()
{
    switch (::Faust::Primitive::Math::floatSize) {
        case 1:
            return Typed::kFloat;
        case 2:
            return Typed::kDouble;
        case 3:
            return Typed::kQuad;
        case 4:
            return Typed::kFixedPoint;
        default:
            faustassert(false);
            return Typed::kNoType;
    }
}

Typed::VarType itfloatptr()
{
    switch (::Faust::Primitive::Math::floatSize) {
        case 1:
            return Typed::kFloat_ptr;
        case 2:
            return Typed::kDouble_ptr;
        case 3:
            return Typed::kQuad_ptr;
        case 4:
            return Typed::kFixedPoint_ptr;
        default:
            faustassert(false);
            return Typed::kNoType;
    }
}

Typed::VarType itfloatptrptr()
{
    switch (::Faust::Primitive::Math::floatSize) {
        case 1:
            return Typed::kFloat_ptr_ptr;
        case 2:
            return Typed::kDouble_ptr_ptr;
        case 3:
            return Typed::kQuad_ptr_ptr;
        case 4:
            return Typed::kFixedPoint_ptr_ptr;
        default:
            faustassert(false);
            return Typed::kNoType;
    }
}

void printfloatdef(std::ostream& fout)
{
    fout << "#ifndef " << FLOATMACRO << std::endl;
    fout << "#define " << FLOATMACRO << " float" << std::endl;
    fout << "#endif " << std::endl;
    fout << std::endl;
    if (::Faust::Primitive::Math::floatSize == 3) {
        fout << "typedef long double quad;" << std::endl;
    }
}