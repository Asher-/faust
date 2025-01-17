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

#ifndef __XTENDED__
#define __XTENDED__

#include <vector>

#include "documentator/lateq.hh"
//
#include "compiler/instruction/instructions.hh"
#include "compiler/dsp_factory/klass.hh"
#include "compiler/signals/sigtype.hh"
#include "compiler/signals/ppsig.hh"

#include "faust/primitive/symbols.hh"
#include "faust/primitive/symbol/abstract/data.hh"

#include "faust/primitive/type/precision.hh"

//#include "tlib/tlib.hh"
//#include "target/fir/fir_to_fir.hh"

class CodeContainer;

namespace Faust {
  namespace Primitive {
    namespace Math {


      /*
       Base class for math primitives:
       - most of them have same args and result type, except 'pow' which can have different value and exponent types
       - max/min, abs/fabs have polymorphic Precision::Int/Precision::Real versions
       - some of them have optimized versions for specific arguments (like 'pow') or with ::Faust::Primitive::Math::approx (experimental)
       */

      class xtended : public ::Faust::Primitive::Symbol::Abstract::Data {
         private:

          using Precision = ::Faust::Primitive::Type::Precision;

          Sym _symbol;  ///< the symbol the xtended is attached to

          public:

          xtended
          (const char* name)
          :
            Data(),
            _symbol(
              ::Faust::Primitive::Symbols::internal().symbol(name) // All xtended type symbols are now defined in Symbols::internal().
            ) {
            _symbol->data() = this;
          }

          virtual ~xtended() {}

          Sym         symbol() { return _symbol; }
          const std::string& name() { return _symbol->name(); }

          // Create the box
          Tree box()
          {
              Tree b = tree(_symbol);
              faustassert(getUserData(b) != nullptr);
              return b;
          }

          // virtual method to be implemented by subclasses
          virtual unsigned int arity() = 0;

          // FIR backends
          virtual ValueInst* generateCode(CodeContainer* container, Values& args, ::Type rtype, ConstTypes types) = 0;
          // Old CPP backend
          virtual string generateCode(Klass* klass, const vector<string>& args, ConstTypes types) = 0;

          virtual string generateLateq(Lateq* lateq, const vector<string>& args, const vector< ::Type>& types) = 0;
          virtual int    infereSigOrder(const vector<int>& args)                                               = 0;
          virtual ::Type infereSigType(ConstTypes args)                                                       = 0;
          virtual Tree   computeSigOutput(const vector<Tree>& args)                                            = 0;
          virtual bool   needCache()                                                                          = 0;

          virtual bool isSpecialInfix()
          {
              return false;
          }  ///< generally false, but true for binary op # such that #(x) == _#x

          ValueInst* generateFun(CodeContainer* container,
                                 const string& fun_name,
                                 const Values& args,
                                 ::Type rtype,
                                 ConstTypes types);
      };

      // True if two floating point numbers are close enough to be considered identical.
      // It is used to recognize PI/n and 0 in some symbolic simplifications.
      inline bool comparable(double x, double y)
      {
          return fabs(x - y) < 0.00001;
      }

      // Casting operations
      inline ValueInst* promote2real(
        const Type::Precision& type,
        ValueInst* val
      )
      {
          return (type == Type::Precision::Real) ? val : InstBuilder::genCastRealInst(val);
      }
      inline ValueInst* promote2int(
        const Type::Precision& type,
        ValueInst* val
      )
      {
          return (type == Type::Precision::Int) ? val : InstBuilder::genCastInt32Inst(val);
      }

      inline ValueInst* cast2real(
        const Type::Precision& type,
        ValueInst* val
      )
      {
          return (type == Type::Precision::Real) ? InstBuilder::genCastRealInst(val) : val;
      }
      inline ValueInst* cast2int(
        const Type::Precision& type,
        ValueInst* val
      )
      {
          return (type == Type::Precision::Int) ? InstBuilder::genCastInt32Inst(val) : val;
      }

    }
  }
}

#endif

