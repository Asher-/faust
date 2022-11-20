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

#ifndef __FAUST__PRIMITIVE__MATH__MAX__HH__
#define __FAUST__PRIMITIVE__MATH__MAX__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "compiler/signals/sigtyperules.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/value.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Max : public ::Faust::Primitive::Math::xtended {
          protected:

            using Precision = ::Faust::Primitive::Type::Precision;
            using Value = ::Faust::Primitive::Type::Value;

          public:
          Max() : ::Faust::Primitive::Math::xtended("max") {}

          virtual unsigned int arity() { return 2; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());
              interval i = args[0]->interval();
              interval j = args[1]->interval();
              return Type::castInterval(args[0] | args[1], max(i, j));
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return max(args[0], args[1]);
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              double f, g;
              int    i, j;

              faustassert(args.size() == arity());

              if (isDouble(args[0]->node(), &f)) {
                  if (isDouble(args[1]->node(), &g)) {
                      return tree(max(f, g));
                  } else if (isInt(args[1]->node(), &j)) {
                      return tree(max(f, double(j)));
                  } else {
                      return tree(symbol(), args[0], args[1]);
                  }

              } else if (isInt(args[0]->node(), &i)) {
                  if (isDouble(args[1]->node(), &g)) {
                      return tree(max(double(i), g));
                  } else if (isInt(args[1]->node(), &j)) {
                      return tree(max(i, j));
                  } else {
                      return tree(symbol(), args[0], args[1]);
                  }

              } else {
                  return tree(symbol(), args[0], args[1]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());
          
              /*
               04/25/22 : this optimisation cannot be done because interval computation is buggy: like no.noise interval [O..inf] !
               */
          
              /*
                  // Max of disjoint intervals returns one of them
                  interval i1 = types[0]->interval();
                  interval i2 = types[1]->interval();
                  
                  if (i1.valid && i2.valid) {
                      if (i1.hi <= i2.lo) {
                          return *(std::next(args.begin(), 1));
                      } else if (i2.hi <= i1.lo) {
                          return *args.begin();
                      }
                  }
              */
          
              string fun_name = (result->precision() == Precision::Int) ? "max_i" : subst("max_$0", isuffix());
              return generateFun(container, fun_name, args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              // generates code compatible with overloaded max
              const Precision& n0 = types[0]->precision();
              const Precision& n1 = types[1]->precision();
              if (n0 == Precision::Real) {
                  if (n1 == Precision::Real) {
                      // both are floats, no need to cast
                      return subst("max($0, $1)", args[0], args[1]);
                  } else {
                      faustassert(n1 == Precision::Int);  // second argument is not float, cast it to float
                      return subst("max($0, $2($1))", args[0], args[1], icast());
                  }
              } else if (n1 == Precision::Real) {
                  faustassert(n0 == Precision::Int);  // first not float but second is, cast first to float
                  return subst("max($2($0), $1)", args[0], args[1], icast());
              } else {
                  faustassert(n0 == Precision::Int);
                  faustassert(n1 == Precision::Int);  // both are integers, check for booleans
                  const Value& b0 = types[0]->valueType();
                  const Value& b1 = types[1]->valueType();
                  if (b0 == Value::Num) {
                      if (b1 == Value::Num) {
                          // both are integers, no need to cast
                          return subst("max($0, $1)", args[0], args[1]);
                      } else {
                          faustassert(b1 == Value::Bool);  // second is boolean, cast to int
                          return subst("max($0, int($1))", args[0], args[1]);
                      }
                  } else if (b1 == Value::Num) {
                      faustassert(b0 == Value::Bool);  // first is boolean, cast to int
                      return subst("max(int($0), $1)", args[0], args[1], icast());
                  } else {
                      // both are booleans, theoretically no need to cast, but we still do it to be sure 'true' is actually
                      // '1' and 'false' is actually '0' (which is not the case if compiled in SSE mode)
                      faustassert(b0 == Value::Bool);
                      faustassert(b1 == Value::Bool);
                      return subst("max(int($0), int($1))", args[0], args[1]);
                  }
              }
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ::Type t = infereSigType(types);
              return subst("\\max\\left( $0, $1 \\right)", args[0], args[1]);
          }
      };

    }
  }
}

#endif
