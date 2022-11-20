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

#ifndef __FAUST__PRIMITIVE__MATH__POWER__HH__
#define __FAUST__PRIMITIVE__MATH__POWER__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "target/fir/fir_to_fir.hh"

#include "faust/primitive/symbols.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern bool needManualPow;         // If manual pow(x, y) generation when y is an integer is needed
      extern bool hasExp10;              // If the 'exp10' math function is available

      /*
       When argument is Precision::Int and exponent is Precision::Int (or Precision::Real without decimal part),
       an explicit mydsp_faustpowerXX_i(..) is generated.
       When argument is Precision::Real and exponent is Precision::Int (or Precision::Real without decimal part),
       an explicit mydsp_faustpowerXX_f(..) is generated.
       Otherwise pow[f||l](argument,exponent) is generated.
       */

      class Pow : public ::Faust::Primitive::Math::xtended {
          protected:

            using Availability = ::Faust::Primitive::Type::Availability;
            using Precision = ::Faust::Primitive::Type::Precision;
            using Priority = ::Faust::Primitive::Type::Priority;

          public:
          Pow() : ::Faust::Primitive::Math::xtended("pow") {}

          virtual unsigned int arity() { return 2; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes args)
          {
              faustassert(args.size() == arity());

              interval i = args[0]->interval();
              interval j = args[1]->interval();
              return Type::castInterval(args[0] | args[1], pow(i, j));
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return max(args[0], args[1]);
          }

          // Fast integer based power, for positive exponent
          template <typename Type1, typename Type2>
          Type1 ipow(Type1 a, Type2 ex)
          {
              if (0 == ex) return 1;
              else {
                  Type1 z = a;
                  Type1 y = 1;
                  while (true) {
                      if (ex & 1) y *= z;
                      ex /= 2;
                      if (0 == ex) break;
                      z *= z;
                  }
                  return y;
              }
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              num n, m;
              faustassert(args.size() == arity());
              if (isNum(args[0], n) && isNum(args[1], m)) {
                  if (!isfloat(n) && !isfloat(m) && int(m) > 0) {
                      return tree(ipow(int(n), int(m)));
                  } else {
                      return tree(pow(double(n), double(m)));
                  }
              } else if (isNum(args[1], m)) {
                  double exponent = double(m);
                  if (exponent == 0.0) {
                      // pow(x, 0) ==> 1
                      return tree(1.0);
                  } else if (exponent == 1.0) {
                      // pow(x, 1) = => x
                      return args[0];
                  } else if ((exponent == 10.) && ::Faust::Primitive::Math::hasExp10) {
                      // pow(x, 10) ==> exp10(x)
                      return tree(::Faust::Primitive::Symbols::internal().symbol("exp10"), args[0]);
                  } else if (exponent == 0.5) {
                      // pow(x, 0.5) ==> sqrt(x)
                      return tree(::Faust::Primitive::Symbols::internal().symbol("sqrt"), args[0]);
                  } else if (exponent == 0.25) {
                      // pow(x, 0.25) ==> sqrt(sqrt(x))
                      auto sqrt_symbol = ::Faust::Primitive::Symbols::internal().symbol("sqrt");
                      return tree(sqrt_symbol, tree(sqrt_symbol, args[0]));
                  }
              }
              return tree(symbol(), args[0], args[1]);
          }

          // Check that power argument is an integer or possibly represents an integer, up to 32
          bool isIntPowArg(::Type ty, ValueInst* val, int& pow_arg)
          {
              if (ty->precision() == Precision::Int) {
                  Int32NumInst* int_val = dynamic_cast<Int32NumInst*>(val);
                  if (int_val) {
                      pow_arg = int_val->fNum;
                      return (pow_arg <= 8);
                  } else {
                      return false;
                  }
              } else {
                  FloatNumInst* float_val = dynamic_cast<FloatNumInst*>(val);
                  DoubleNumInst* double_val = dynamic_cast<DoubleNumInst*>(val);
                  if (float_val) {
                      pow_arg = int(float_val->fNum);
                      double intpart;
                      return (std::modf(float_val->fNum, &intpart) == 0.) && (pow_arg >= 0) && (pow_arg <= 8);
                  } else if (double_val) {
                      pow_arg = int(double_val->fNum);
                      double intpart;
                      return (std::modf(double_val->fNum, &intpart) == 0.) && (pow_arg >= 0) && (pow_arg <= 8);
                  } else {
                      return false;
                  }
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ValuesIt it = args.begin(); it++;
              int pow_arg = 0;

              if (isIntPowArg(types[1], *it, pow_arg)
                  && (types[1]->priority() == Priority::Konst)
                  && (types[1]->availability() == Availability::Comp)
                  && (::Faust::Primitive::Math::needManualPow)) {

                  Typed::VarType t0 = convert2FIRType(types[0]->precision());
                  vector<Typed::VarType> atypes = { t0, Typed::kInt32};
                  Typed::VarType rtype = convert2FIRType(result->precision());

                  // Expand the pow depending of the exposant argument
                  BlockInst* block = InstBuilder::genBlockInst();
                  string faust_power_name = container->getFaustPowerName() + to_string(pow_arg) + ((rtype == Typed::kInt32) ? "_i" : "_f");

                  Names named_args;
                  named_args.push_back(InstBuilder::genNamedTyped("value", InstBuilder::genBasicTyped(t0)));

                  if (pow_arg == 0) {
                      block->pushBackInst(InstBuilder::genRetInst(InstBuilder::genTypedNum(t0, 1.0)));
                  } else {
                      ValueInst* res = InstBuilder::genLoadFunArgsVar("value");
                      for (int i = 0; i < pow_arg - 1; i++) {
                          res = InstBuilder::genMul(res, InstBuilder::genLoadFunArgsVar("value"));
                      }
                      block->pushBackInst(InstBuilder::genRetInst(res));
                  }

                  container->pushGlobalDeclare(InstBuilder::genDeclareFunInst(faust_power_name,
                                                                              InstBuilder::genFunTyped(named_args, InstBuilder::genBasicTyped(rtype),
                                                                                                       FunTyped::kLocal), block));

                  Values truncated_args;
                  truncated_args.push_back((*args.begin()));
                  return InstBuilder::genFunCallInst(faust_power_name, truncated_args);

              } else {

                  // Both arguments forced to itfloat()
                  vector<Typed::VarType> atypes = {itfloat(), itfloat()};

                  Values cargs;
                  ValuesIt it2 = args.begin();
                  vector<::Type>::const_iterator it1;

                  for (it1 = types.begin(); it1 != types.end(); it1++, it2++) {
                      cargs.push_back(promote2real((*it1)->precision(), (*it2)));
                  }

                  return cast2int(result->precision(), container->pushFunction(subst("pow$0", isuffix()), itfloat(), atypes, cargs));
              }
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              if ((types[1]->precision() == Precision::Int) && (types[1]->priority() == Priority::Konst) &&
                  (types[1]->availability() == Availability::Comp)) {
                  klass->rememberNeedPowerDef();
                  return subst("faustpower<$1>($0)", args[0], args[1]);
              } else {
                  return subst("pow$2($0,$1)", args[0], args[1], isuffix());
              }
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              return subst("{$0}^{$1}", args[0], args[1]);
          }

          // power is now used as an infix binary operator, we return true to
          // indicate that we want ^(n) to be equivalent to _^n
          virtual bool isSpecialInfix() { return true; }
      };

    }
  }
}

#endif
