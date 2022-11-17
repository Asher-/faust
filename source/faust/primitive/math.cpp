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

#include "faust/primitive/math.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      bool  needManualPow = true; // If manual pow(x, y) generation when y is an integer is needed
      bool  hasExp10 = false;     // If the 'exp10' math function is available

      bool  exceptions = true;    // whether to check math functions domains
      bool  approx = false;       // Simpler/faster versions of 'floor/fmod/remainder' functions
      int   FTZMode = 0;
      int   floatSize = 1;            // 0 for 'float', 1 for 'double', 2 for 'quad', 3 for 'fixed-point'


      Abs abs;
      Abs* Abs::self = & abs;

      Acos acos;
      Acos* Acos::self = & acos;

      Tan tan;
      Tan* Tan::self = & tan;

      Sqrt sqrt;
      Sqrt* Sqrt::self = & sqrt;

      Sin sin;
      Sin* Sin::self = & sin;

      Rint rint;
      Rint* Rint::self = & rint;

      Remainder remainder;
      Remainder* Remainder::self = & remainder;

      Pow pow;
      Pow* Pow::self = & pow;

      Min min;
      Min* Min::self = & min;

      Max max;
      Max* Max::self = & max;

      Log log;
      Log* Log::self = & log;

      Log10 log10;
      Log10* Log10::self = & log10;

      Fmod fmod;
      Fmod* Fmod::self = & fmod;

      Floor floor;
      Floor* Floor::self = & floor;

      Exp exp;
      Exp* Exp::self = & exp;

      Exp10 exp10;
      Exp10* Exp10::self = & exp10;

      Cos cos;
      Cos* Cos::self = & cos;

      Ceil ceil;
      Ceil* Ceil::self = & ceil;

      Atan atan;
      Atan* Atan::self = & atan;

      Atan2 atan2;
      Atan2* Atan2::self = & atan2;

      Asin asin;
      Asin* Asin::self = & asin;

      Ftz ftz;
      Ftz* Ftz::self = & ftz;
      int Ftz::freshnum = 0;

    };
  };
};
