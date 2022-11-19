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
      
      Functions& functions()
      {
        static Functions instance;
        return instance;
      }

      int   floatSize = 1;            // 0 for 'float', 1 for 'double', 2 for 'quad', 3 for 'fixed-point'
      bool  exceptions = true;    // whether to check math functions domains

      bool  needManualPow = true; // If manual pow(x, y) generation when y is an integer is needed
      bool  hasExp10 = false;     // If the 'exp10' math function is available

      bool  approx = false;       // Simpler/faster versions of 'floor/fmod/remainder' functions
      int   FTZMode = 0;

      int Ftz::freshnum = 0;

    };
  };
};
