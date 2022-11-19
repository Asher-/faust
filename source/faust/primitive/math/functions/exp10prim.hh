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

#ifndef __FAUST__PRIMITIVE__MATH__EXT10__HH__
#define __FAUST__PRIMITIVE__MATH__EXT10__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Exp10 : public ::Faust::Primitive::Math::xtended {
          public:
          Exp10() : ::Faust::Primitive::Math::xtended("exp10") {}

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
          
              // exp10(log10(sig)) ==> sig
              auto xt = getUserData(args[0]);
              if (xt->symbol() == this->symbol()) {
                  return args[0]->branch(0);
              } else if (isNum(args[0], n)) {
                  return tree(pow(10, double(n)));
              } else {
                  return tree(symbol(), args[0]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return generateFun(container, subst("exp10$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("exp10$1($0)", args[0], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("e10^{$0}", args[0]);
          }
      };

    }
  }
}

#endif
