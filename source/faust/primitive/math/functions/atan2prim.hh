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

#ifndef __FAUST__PRIMITIVE__MATH__ATAN2__HH__
#define __FAUST__PRIMITIVE__MATH__ATAN2__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Atan2 : public ::Faust::Primitive::Math::xtended {
          public:
          Atan2() : ::Faust::Primitive::Math::xtended("atan2") {}

          virtual unsigned int arity() { return 2; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == 2);
              return floatCast(args[0] | args[1]);
          }

          virtual int infereSigOrder(const vector<int>& args) { return max(args[0], args[1]); }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              faustassert(args.size() == 2);
              num n, m;
              if (isNum(args[0], n) && isNum(args[1], m)) {
                  return tree(atan2(double(n), double(m)));
              } else {
                  return tree(symbol(), args[0], args[1]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return generateFun(container, subst("atan2$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("atan2$2($0,$1)", args[0], args[1], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("\\arctan\\frac{$0}{$1}", args[0], args[1]);
          }
      };

    }
  }
}

#endif
