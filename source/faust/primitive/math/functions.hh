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

#ifndef __FAUST__PRIMITIVE__MATH__FUNCTIONS__HH__
#define __FAUST__PRIMITIVE__MATH__FUNCTIONS__HH__

#include "faust/primitive/math/functions/absprim.hh"
#include "faust/primitive/math/functions/acosprim.hh"
#include "faust/primitive/math/functions/asinprim.hh"
#include "faust/primitive/math/functions/atan2prim.hh"
#include "faust/primitive/math/functions/atanprim.hh"
#include "faust/primitive/math/functions/ceilprim.hh"
#include "faust/primitive/math/functions/cosprim.hh"
#include "faust/primitive/math/functions/exp10prim.hh"
#include "faust/primitive/math/functions/expprim.hh"
#include "faust/primitive/math/functions/floorprim.hh"
#include "faust/primitive/math/functions/fmodprim.hh"
#include "faust/primitive/math/functions/ftzprim.hh"
#include "faust/primitive/math/functions/log10prim.hh"
#include "faust/primitive/math/functions/logprim.hh"
#include "faust/primitive/math/functions/maxprim.hh"
#include "faust/primitive/math/functions/minprim.hh"
#include "faust/primitive/math/functions/powprim.hh"
#include "faust/primitive/math/functions/remainderprim.hh"
#include "faust/primitive/math/functions/rintprim.hh"
#include "faust/primitive/math/functions/sinprim.hh"
#include "faust/primitive/math/functions/sqrtprim.hh"
#include "faust/primitive/math/functions/tanprim.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      struct Functions {

        Abs abs;

        Acos acos;

        Tan tan;

        Sqrt sqrt;

        Sin sin;

        Rint rint;

        Remainder remainder;

        Pow pow;

        Min min;

        Max max;

        Log log;

        Log10 log10;

        Fmod fmod;

        Floor floor;

        Exp exp;

        Exp10 exp10;

        Cos cos;

        Ceil ceil;

        Atan atan;

        Atan2 atan2;

        Asin asin;

        Ftz ftz;


      };
      
      Functions& functions();
 
    };
  };
};

#endif
