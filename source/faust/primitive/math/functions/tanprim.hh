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

#ifndef __FAUST__PRIMITIVE__MATH__TAN__HH__
#define __FAUST__PRIMITIVE__MATH__TAN__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "faust/primitive/type/cast.hh"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Tan : public ::Faust::Primitive::Math::xtended {
          public:
          Tan() : ::Faust::Primitive::Math::xtended("tan") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == 1);
              interval     srcInterval = args[0]->interval();
              const double halfpi      = M_PI / 2;
              interval     resultInterval;

              // the check can be improved to ensure that no infinity is in the range
              if (srcInterval.valid) {
                  if ((-halfpi < srcInterval.lo) && (srcInterval.hi < halfpi))
                      resultInterval = interval(tan(srcInterval.lo), tan(srcInterval.hi));
              }
              return Type::castInterval(Type::floatCast(args[0]), resultInterval);
          }

          virtual int infereSigOrder(const vector<int>& args) { return args[0]; }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              num n;
              if (isNum(args[0], n)) {
                  return tree(tan(double(n)));
              } else {
                  return tree(symbol(), args[0]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return generateFun(container, subst("tan$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("tan$1($0)", args[0], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("\\tan\\left($0\\right)", args[0]);
          }
      };

    }
  }
}

#endif
