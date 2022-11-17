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

#ifndef __FAUST__PRIMITIVE__MATH__HH__
#define __FAUST__PRIMITIVE__MATH__HH__

#include "compiler/math_primitives/absprim.hh"
#include "compiler/math_primitives/acosprim.hh"
#include "compiler/math_primitives/asinprim.hh"
#include "compiler/math_primitives/atan2prim.hh"
#include "compiler/math_primitives/atanprim.hh"
#include "compiler/math_primitives/ceilprim.hh"
#include "compiler/math_primitives/cosprim.hh"
#include "compiler/math_primitives/exp10prim.hh"
#include "compiler/math_primitives/expprim.hh"
#include "compiler/math_primitives/floorprim.hh"
#include "compiler/math_primitives/fmodprim.hh"
#include "compiler/math_primitives/ftzprim.hh"
#include "compiler/math_primitives/log10prim.hh"
#include "compiler/math_primitives/logprim.hh"
#include "compiler/math_primitives/maxprim.hh"
#include "compiler/math_primitives/minprim.hh"
#include "compiler/math_primitives/powprim.hh"
#include "compiler/math_primitives/remainderprim.hh"
#include "compiler/math_primitives/rintprim.hh"
#include "compiler/math_primitives/sinprim.hh"
#include "compiler/math_primitives/sqrtprim.hh"
#include "compiler/math_primitives/tanprim.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {
    
      extern bool needManualPow;         // If manual pow(x, y) generation when y is an integer is needed
      extern bool hasExp10;              // If the 'exp10' math function is available

      extern bool exceptions;  // whether to check math functions domains
      extern bool approx;            // Simpler/faster versions of 'floor/fmod/remainder' functions
      extern int  FTZMode;
      extern int  floatSize; // 0 for 'float', 1 for 'double', 2 for 'quad', 3 for 'fixed-point'

      extern Abs abs;
      extern Acos acos;
      extern Tan tan;
      extern Sqrt sqrt;
      extern Sin sin;
      extern Rint rint;
      extern Remainder remainder;
      extern Pow pow;
      extern Min min;
      extern Max max;
      extern Log log;
      extern Log10 log10;
      extern Fmod fmod;
      extern Floor floor;
      extern Exp exp;
      extern Exp10 exp10;
      extern Cos cos;
      extern Ceil ceil;
      extern Atan atan;
      extern Atan2 atan2;
      extern Asin asin;
      extern Ftz ftz;

    };
  };
};

#endif
