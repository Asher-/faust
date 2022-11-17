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

#ifndef __FAUST__PRIMITIVE__MATH__LOG__HH__
#define __FAUST__PRIMITIVE__MATH__LOG__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "compiler/math_primitives/xtended.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern bool exceptions;  // whether to check math functions domains

      class Log : public ::Faust::Primitive::Math::xtended {
          public:
          static Log* self;
          Log() : ::Faust::Primitive::Math::xtended("log") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());
              interval i = args[0]->getInterval();
          
              if (i.valid) {
                  // log(0) gives -INF but is still in the function domain
                  if (i.lo >= 0) {
                      return castInterval(floatCast(args[0]), interval(log(i.lo), log(i.hi)));
                  } else if (::Faust::Primitive::Math::exceptions) {
                      cerr << "WARNING : potential out of domain in log(" << i << ")" << endl;
                  }
              }
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
          
              // log(exp(sig)) ==> sig
              ::Faust::Primitive::Math::xtended* xt = (::Faust::Primitive::Math::xtended*)getUserData(args[0]);
              if (xt == (::Faust::Primitive::Math::xtended*)&self) {
                  return args[0]->branch(0);
              } else if (isNum(args[0], n)) {
                  if (double(n) < 0) {
                      stringstream error;
                      error << "ERROR : out of domain log(" << ppsig(args[0]) << ")" << endl;
                      throw faustexception(error.str());
                  } else {
                      return tree(log(double(n)));
                  }
              } else {
                  return tree(symbol(), args[0]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return generateFun(container, subst("log$0", isuffix()), args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("log$1($0)", args[0], isuffix());
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("\\ln\\left( $0 \\right)", args[0]);
          }
      };

    }
  }
}

#endif
