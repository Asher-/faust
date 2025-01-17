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

#ifndef __FAUST__PRIMITIVE__MATH__ABSOLUTE__HH__
#define __FAUST__PRIMITIVE__MATH__ABSOLUTE__HH__

#include <math.h>

#include "faust/primitive/math/functions/xtended.hh"

#include "compiler/type_manager/Text.hh"
#include "target/code_container.hh"
#include "compiler/types/floats.hh"
#include "compiler/signals/sigtyperules.hh"

#include "compiler/signals/sigtype.hh"

#include "faust/primitive/type/precision.hh"

#include "faust/primitive/type/cast.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      class Abs : public ::Faust::Primitive::Math::xtended {
        protected:

          using Precision = ::Faust::Primitive::Type::Precision;

        public:
                  
          Abs() : ::Faust::Primitive::Math::xtended("abs") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());
              ::Type t = args[0];
              return Type::castInterval(t, abs(t->interval()));
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return args[0];
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              double f;
              int    i;
              faustassert(args.size() == arity());
          
              // abs(abs(sig)) ==> abs(sig)
              auto xt = getUserData(args[0]);
              if (xt->symbol() == this->symbol()) {
                  return args[0];
                  
              } else if (isDouble(args[0]->node(), &f)) {
                  return tree(fabs(f));

              } else if (isInt(args[0]->node(), &i)) {
                  return tree(abs(i));

              } else {
                  return tree(symbol(), args[0]);
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
                  if (i.valid && i.lo >= 0) {
                      return *args.begin();
                  } else {
                      // Only compute abs when arg is < 0
                      if (t->precision() == Precision::Real) {
                          Values cargs;
                          prepareTypeArgsResult(result, args, types, rtype, atypes, cargs);
                          return container->pushFunction(subst("fabs$0", isuffix()), rtype, atypes, cargs);
                      } else {
                          // "Int" abs
                          rtype = Typed::kInt32;
                          atypes.push_back(Typed::kInt32);
                          return container->pushFunction("abs", rtype, atypes, args);
                      }
                  }
              */
          
              string fun_name = (result->precision() == Precision::Int) ? "abs" : subst("fabs$0", isuffix());
              return generateFun(container, fun_name, args, result, types);
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ::Type t = infereSigType(types);
              if (t->precision() == Precision::Real) {
                  return subst("fabs$1($0)", args[0], isuffix());
              } else {
                  return subst("abs($0)", args[0]);
              }
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ::Type t = infereSigType(types);
              return subst("\\left\\lvert{$0}\\right\\rvert", args[0]);
          }
      };
      
    }
  }
}

#endif

