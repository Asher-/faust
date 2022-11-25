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

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern int   floatSize;            // 0 for 'float', 1 for 'double', 2 for 'quad', 3 for 'fixed-point'
      extern bool  exceptions;    // whether to check math functions domains

      extern bool  needManualPow; // If manual pow(x, y) generation when y is an integer is needed
      extern bool  hasExp10;     // If the 'exp10' math function is available

      extern bool  approx;       // Simpler/faster versions of 'floor/fmod/remainder' functions
      extern int   FTZMode;

      extern int gMachineFloatSize;
      extern int gMachineInt32Size;
      extern int gMachineInt64Size;
      extern int gMachineDoubleSize;
      extern int gMachineQuadSize;
      extern int gMachineFixedPointSize;
      extern int gMachineBoolSize;
      extern int gMachinePtrSize;
      extern int gMachineMaxStackSize;

    };
  };
};

#endif
