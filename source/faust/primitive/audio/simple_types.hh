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

#ifndef __FAUST__PRIMITIVE__AUDIO__SIMPLE_TYPES__HH__
#define __FAUST__PRIMITIVE__AUDIO__SIMPLE_TYPES__HH__

#include "compiler/signals/sigtype.hh"
#include "compiler/types/typed.hh"
#include "tlib/smartpointer.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

namespace Faust {
  namespace Primitive {
    namespace Audio {

      struct SimpleTypes
      {
        using Availability = ::Faust::Primitive::Type::Availability;
        using Precision = ::Faust::Primitive::Type::Precision;
        using Priority = ::Faust::Primitive::Type::Priority;
        using Value = ::Faust::Primitive::Type::Value;
        using Vectorability = ::Faust::Primitive::Type::Vectorability;

        smartptr<AudioType> TINT  = makeSimpleType(Precision::Int, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TREAL = makeSimpleType(Precision::Real, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval());

        smartptr<AudioType> TKONST = makeSimpleType(Precision::Int, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TBLOCK = makeSimpleType(Precision::Int, Priority::Block, Availability::Comp, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TSAMP  = makeSimpleType(Precision::Int, Priority::Samp, Availability::Comp, Vectorability::Vect, Value::Num, interval());

        smartptr<AudioType> TCOMP = makeSimpleType(Precision::Int, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TINIT = makeSimpleType(Precision::Int, Priority::Konst, Availability::Init, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TEXEC = makeSimpleType(Precision::Int, Priority::Konst, Availability::Exec, Vectorability::Vect, Value::Num, interval());

        smartptr<AudioType> TINPUT   = makeSimpleType(Precision::Real, Priority::Samp, Availability::Exec, Vectorability::Vect, Value::Num, interval(-1, 1));
        smartptr<AudioType> TGUI     = makeSimpleType(Precision::Real, Priority::Block, Availability::Exec, Vectorability::Vect, Value::Num, interval());
        smartptr<AudioType> TGUI01   = makeSimpleType(Precision::Real, Priority::Block, Availability::Exec, Vectorability::Vect, Value::Num, interval(0, 1));
        smartptr<AudioType> INT_TGUI = makeSimpleType(Precision::Int, Priority::Block, Availability::Exec, Vectorability::Vect, Value::Num, interval());

        smartptr<AudioType> TREC = makeSimpleType(Precision::Int, Priority::Samp, Availability::Init, Vectorability::Scal, Value::Num, interval(0, 0));
        // !!! TRECMAX Maximal only in the last component of the type lattice
        smartptr<AudioType> TRECMAX = makeSimpleType(Precision::Int, Priority::Samp, Availability::Init, Vectorability::Scal, Value::Num, interval(-HUGE_VAL, HUGE_VAL));

      };
      
      SimpleTypes& simpleTypes();

    };
  };
};

#endif

