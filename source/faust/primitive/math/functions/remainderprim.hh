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

#ifndef __FAUST__PRIMITIVE__MATH__REMAINDER__HH__
#define __FAUST__PRIMITIVE__MATH__REMAINDER__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "tlib/compatibility.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "faust/primitive/type/cast.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern bool exceptions;  // whether to check math functions domains
      extern bool approx;            // Simpler/faster versions of 'floor/fmod/remainder' functions

      class Remainder : public ::Faust::Primitive::Math::xtended {
          public:
          Remainder() : ::Faust::Primitive::Math::xtended("remainder") {}

          virtual unsigned int arity() { return 2; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());
          
              interval i = args[0]->interval();
              interval j = args[1]->interval();
              if (j.valid && ::Faust::Primitive::Math::exceptions && j.haszero()) {
                  cerr << "WARNING : potential division by zero in remainder(" << i << ", " << j << ")" << endl;
              }
          
              return Type::castInterval(Type::floatCast(args[0] | args[1]), interval());  // temporary rule !!!
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return max(args[0], args[1]);
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              num n, m;
              faustassert(args.size() == arity());
              if (isZero(args[1])) {
                  stringstream error;
                  error << "ERROR : remainder by 0 in remainder(" << ppsig(args[0]) << ", " << ppsig(args[1]) << ")" << endl;
                  throw faustexception(error.str());
              } else if (isNum(args[0], n) && isNum(args[1], m)) {
                  return tree(remainder(double(n), double(m)));
              } else {
                  if (::Faust::Primitive::Math::approx) {
                      // res = x - (y * T(int(0.5f + x / y)));
                      return sigSub(args[0], sigBinOp(kMul, args[1], sigFloatCast(sigIntCast(sigAdd( sigReal(0.5), sigDiv(args[0], args[1]))))));
                  } else {
                      return tree(symbol(), args[0], args[1]);
                  }
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());
              
              return generateFun(container, subst("remainder$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("remainder$2($0,$1)", args[0], args[1], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("$0\\pmod{$1}", args[0], args[1]);  // Same as fmodprim.cpp.
          }
      };

    }
  }
}

#endif
