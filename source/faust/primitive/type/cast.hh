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

#ifndef __FAUST__PRIMITIVE__TYPE__CAST__HH__
#define __FAUST__PRIMITIVE__TYPE__CAST__HH__

#include "compiler/signals/sigtype.hh"

#include "tlib/smartpointer.hh"

#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

namespace Faust {
  namespace Primitive {
    namespace Type {

      inline smartptr<AudioType> intCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            Precision::Int,
            t->priority(),
            t->availability(),
            t->vectorability(),
            t->valueType(),
            t->interval()
          );
      }
      inline smartptr<AudioType> floatCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            Precision::Real,
            t->priority(),
            t->availability(),
            t->vectorability(),
            t->valueType(),
            t->interval()
          );
      }
      inline smartptr<AudioType> sampCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            t->precision(),
            Priority::Samp,
            t->availability(),
            t->vectorability(),
            t->valueType(),
            t->interval()
          );
      }
      inline smartptr<AudioType> boolCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            Precision::Int,
            t->priority(),
            t->availability(),
            t->vectorability(),
            Value::Bool,
            t->interval()
          );
      }
      inline smartptr<AudioType> numCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            t->precision(),
            t->priority(),
            t->availability(),
            t->vectorability(),
            Value::Num,
            t->interval()
          );
      }
      inline smartptr<AudioType> vecCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            t->precision(),
            t->priority(),
            t->availability(),
            Vectorability::Vect,
            t->valueType(),
            t->interval()
          );
      }
      inline smartptr<AudioType> scalCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            t->precision(),
            t->priority(),
            t->availability(),
            Vectorability::Scal,
            t->valueType(),
            t->interval()
          );
      }
      inline smartptr<AudioType> truescalCast(smartptr<AudioType> t)
      {
          return makeSimpleType(
            t->precision(),
            t->priority(),
            t->availability(),
            Vectorability::TrueScal,
            t->valueType(),
            t->interval()
          );
      }

      inline smartptr<AudioType> castInterval(smartptr<AudioType> t, const ::interval& i)
      {
          return makeSimpleType(
            t->precision(),
            t->priority(),
            t->availability(),
            t->vectorability(),
            t->valueType(),
            i
          );
      }

    };
  };
};

#endif

