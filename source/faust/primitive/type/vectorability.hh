/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2022, GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1, of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675, Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef __FAUST__PRIMITIVE__TYPE__VECTORABLE__HH__
#define __FAUST__PRIMITIVE__TYPE__VECTORABLE__HH__

namespace Faust {
  namespace Primitive {
    namespace Type {

      ///< vectorability: when a signal can be vectorized (actually,
      ///< only Vectorability::Vect and Vectorability::Scal matter;
      ///< Vectorability::TrueScal and Vectorability::Index don't denote
      ///< types but are here to simplify code generation)
      enum struct Vectorability : unsigned int
      {
          Vect     = 0,
          Scal     = 1,
          TrueScal = 3
          /* Index = 4 */
      };

    };
  };
};

#endif

