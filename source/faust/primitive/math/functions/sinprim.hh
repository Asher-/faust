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

#ifndef __FAUST__PRIMITIVE__MATH__SIN__HH__
#define __FAUST__PRIMITIVE__MATH__SIN__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "faust/primitive/type/cast.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Sin : public ::Faust::Primitive::Math::xtended {
          public:
          Sin() : ::Faust::Primitive::Math::xtended("sin") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == 1);
              return Type::castInterval(Type::floatCast(args[0]), interval(-1, 1));
          }

          virtual int infereSigOrder(const vector<int>& args) { return args[0]; }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              num n;
              if (isNum(args[0], n)) {
                  // Symbolic computation of sin(n)
                  double x = fmod(n, 2 * M_PI);
                  if (comparable(x, 0)) {  // sin(0)
                      return tree(0.0);    // sin(0) = 0
                  } else if (comparable(x, 2 * M_PI)) {
                      return tree(0.0);    // sin(2.PI) = 0
                  } else if (comparable(x, M_PI)) {
                      return tree(0.0);    // sin(PI) = 0
                  } else if (comparable(x, M_PI / 2)) {
                      return tree(1.0);    // sin(PI/2) = 1
                  } else if (comparable(x, 3 * M_PI / 2)) {
                      return tree(-1.0);   // sin(3*PI/2) = -1
                  } else {
                      return tree(sin(x));  // sin(x)
                  }
              } else {
                  return tree(symbol(), args[0]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return generateFun(container, subst("sin$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("sin$1($0)", args[0], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("\\sin\\left($0\\right)", args[0]);
          }
      };

    }
  }
}

#endif