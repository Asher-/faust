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

#ifndef __FAUST__PRIMITIVE__MATH__CEIL__HH__
#define __FAUST__PRIMITIVE__MATH__CEIL__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern bool approx;            // Simpler/faster versions of 'floor/fmod/remainder' functions

      class Ceil : public ::Faust::Primitive::Math::xtended {
          public:
          Ceil() : ::Faust::Primitive::Math::xtended("ceil") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());
              return floatCast(args[0]);
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return args[0];
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              num n;
              faustassert(args.size() == arity());
              if (isNum(args[0], n)) {
                  return tree(ceil(double(n)));
              } else {
                  if (::Faust::Primitive::Math::approx) {
                      // res = T(int(n)); return (r == n) ? n : (n >= 0 ? r + 1 : r);
                      Tree r = sigFloatCast(sigIntCast(args[0]));
                      return sigSelect2(sigEQ(args[0], r), sigSelect2(sigGE(args[0], sigInt(0)), r, sigAdd(r, sigInt(1))), args[0]);
                  } else {
                      return tree(symbol(), args[0]);
                  }
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, vector< ::Type> const& types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());
          
              return generateFun(container, subst("ceil$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("ceil$1($0)", args[0], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("\\left\\lceil $0 \\right\\rceil", args[0]);
          }
      };

    }
  }
}

#endif
