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

#ifndef __FAUST__PRIMITIVE__MATH__FTZ__HH__
#define __FAUST__PRIMITIVE__MATH__FTZ__HH__

#include <math.h>

#include "compiler/type_manager/Text.hh"
#include "compiler/types/floats.hh"
#include "compiler/signals/ppsig.hh"
#include "compiler/signals/sigtyperules.hh"
#include "faust/primitive/math/functions/xtended.hh"

namespace Faust {
  namespace Primitive {
    namespace Math {

      extern int  FTZMode;
      extern int  floatSize; // 0 for 'float', 1 for 'double', 2 for 'quad', 3 for 'fixed-point'

      /********************************************************************************************

      FTZ is a special primitive injected in recursive signals when the -ftz option is on.
      The injected code allows to flush to zero denormalized number. This option should be used only
      when it is not available on the CPU.

      *********************************************************************************************/

      constexpr const char* FTZPattern[4][3] = {
          // not a float
          {"???", "???", "???"},
          // float  (1)
          {"$0", "((fabsf($0)> FLT_MIN) ? $0 : 0.0f)", "((*(int*)&$0) & 0x7F800000) ? $0 : 0.0f"},
          // double (2)
          {"$0", "((fabs($0)> DBL_MIN) ? $0 : 0.0 )", "((*(long int*)&$0) & 0x7FF0000000000000) ? $0 : 0.0"},
          // quad   (3)
          {"$0", "((fabsl($0)> LDBL_MIN) ? $0 : 0.0L)", "((fabsl($0)>LDBL_MIN) ? $0 : 0.0L)"}
      };

      class Ftz : public ::Faust::Primitive::Math::xtended {
         private:
          static int freshnum;  // counter for fTempFTZxxx fresh variables

          public:
          Ftz() : ::Faust::Primitive::Math::xtended("ftz") {}

          virtual unsigned int arity() { return 1; }

          virtual bool needCache() { return true; }

          virtual ::Type infereSigType(ConstTypes types)
          {
              faustassert(types.size() == arity());
              return types[0];
          }

          virtual int infereSigOrder(const vector<int>& args)
          {
              faustassert(args.size() == arity());
              return args[0];
          }

          virtual Tree computeSigOutput(const vector<Tree>& args)
          {
              int    i;
              double r;

              faustassert(args.size() == arity());

              if (isSigInt(args[0], &i)) {
                  return args[0];
              } else if (isSigReal(args[0], &r)) {
                  return args[0];
              } else {
                  return tree(symbol(), args[0]);
              }
          }

          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type result, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ::Type t = infereSigType(types);
              if ((t->nature() == kReal) && (::Faust::Primitive::Math::FTZMode > 0)) {
                  switch (::Faust::Primitive::Math::FTZMode) {
                      case 1: {
                          // "fabs" function has to be declared
                          Names args_types;
                          args_types.push_back(InstBuilder::genNamedTyped("dummy", InstBuilder::genItFloatTyped()));
                          FunTyped* fun_type = InstBuilder::genFunTyped(args_types, InstBuilder::genItFloatTyped());
                          container->pushGlobalDeclare(InstBuilder::genDeclareFunInst(subst("fabs$0", isuffix()), fun_type));

                          // we need to create a temporary variable to store the expression
                          string vname = global::config().getFreshID("fTempFTZ");
                          container->addIncludeFile("<float.h>");
                          container->pushComputeDSPMethod(
                              InstBuilder::genDecStackVar(vname, InstBuilder::genItFloatTyped(), *args.begin()));
                          ValueInst* real_min;
                          if (::Faust::Primitive::Math::floatSize == 1) {
                              real_min = InstBuilder::genFloatNumInst(inummin());
                          } else {
                              real_min = InstBuilder::genDoubleNumInst(inummin());
                          }

                          Values args_value;
                          args_value.push_back(InstBuilder::genLoadStackVar(vname));
                          return InstBuilder::genSelect2Inst(
                              InstBuilder::genGreaterThan(InstBuilder::genFunCallInst(subst("fabs$0", isuffix()), args_value),
                                                          real_min),
                              InstBuilder::genLoadStackVar(vname), InstBuilder::genTypedZero(itfloat()));
                      } break;

                      case 2: {
                          // Bitcast based solution
                          string vname = global::config().getFreshID("fTempFTZ");
                          container->pushComputeDSPMethod(
                              InstBuilder::genDecStackVar(vname, InstBuilder::genItFloatTyped(), *args.begin()));
                          switch (::Faust::Primitive::Math::floatSize) {
                              case 1:
                                  return InstBuilder::genSelect2Inst(
                                      InstBuilder::genAnd(InstBuilder::genBitcastInst(InstBuilder::genLoadStackVar(vname),
                                                                                      InstBuilder::genInt32Typed()),
                                                          InstBuilder::genInt32NumInst(0x7F800000)),
                                      InstBuilder::genLoadStackVar(vname), InstBuilder::genTypedZero(itfloat()));
                              case 2:
                                  return InstBuilder::genSelect2Inst(
                                      InstBuilder::genAnd(
                                          InstBuilder::genBitcastInst(InstBuilder::genLoadStackVar(vname),
                                                                      InstBuilder::genBasicTyped(Typed::kInt64)),
                                          InstBuilder::genInt64NumInst(0x7FF0000000000000)),
                                      InstBuilder::genLoadStackVar(vname), InstBuilder::genTypedZero(itfloat()));
                              default:
                                  faustassert(false);
                                  return *args.begin();
                          }
                      } break;

                      default:
                          faustassert(false);
                          return *args.begin();
                  }

              } else {
                  // No ftz code for integer signals
                  return *args.begin();
              }
          }

          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());

              ::Type t = infereSigType(types);
              if ((t->nature() == kReal) && (::Faust::Primitive::Math::FTZMode > 0)) {
                  // we need to create a temporary variable to store the expression
                  string vname = subst("fTempFTZ$0", T(++freshnum));
                  klass->addIncludeFile("<float.h>");
                  klass->addExecCode(Statement("", subst("$0 $1 = $2;", ifloat(), vname, args[0])));
                  return subst(FTZPattern[::Faust::Primitive::Math::floatSize][::Faust::Primitive::Math::FTZMode], vname);
              } else {
                  // No ftz code for integer signals
                  return args[0];
              }
          }

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, ConstTypes types)
          {
              faustassert(args.size() == arity());
              faustassert(types.size() == arity());
              return args[0];
          }
      };


    }
  }
}

#endif
