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

#ifndef __FAUST__PRIMITIVE__SYMBOLS__INTERNAL__HH__
#define __FAUST__PRIMITIVE__SYMBOLS__INTERNAL__HH__

#include "faust/primitive/symbol/internal/table.hh"
#include "faust/primitive/symbol/internal/names.hh"

namespace Faust {
  namespace Primitive {
    namespace Symbols {
    
        namespace Name = ::Faust::Primitive::Symbol::Internal::Name;

        struct Internal
        :
          ::Faust::Primitive::Symbol::Internal::Table
          <
            Name::EvalProperty,
            Name::PMPROPERTY,
            Name::BoxIdent,
            Name::BoxCut,
            Name::BoxWaveform,
            Name::BoxRoute,
            Name::BoxWire,
            Name::BoxSlot,
            Name::BoxSymbolic,
            Name::BoxSeq,
            Name::BoxPar,
            Name::BoxRec,
            Name::BoxSplit,
            Name::BoxMerge,
            Name::BoxIPar,
            Name::BoxISeq,
            Name::BoxISum,
            Name::BoxIProd,
            Name::BoxAbstr,
            Name::BoxAppl,
            Name::Closure,
            Name::BoxError,
            Name::BoxAccess,
            Name::BoxWithLocalDef,
            Name::BoxModifLocalDef,
            Name::BoxEnvironment,
            Name::BoxComponent,
            Name::BoxLibrary,
            Name::ImportFile,
            Name::BoxPrim0,
            Name::BoxPrim1,
            Name::BoxPrim2,
            Name::BoxPrim3,
            Name::BoxPrim4,
            Name::BoxPrim5,
            Name::BoxFFun,
            Name::BoxFConst,
            Name::BoxFVar,
            Name::BoxButton,
            Name::BoxCheckbox,
            Name::BoxHSlider,
            Name::BoxVSlider,
            Name::BoxNumEntry,
            Name::BoxHGroup,
            Name::BoxVGroup,
            Name::BoxTGroup,
            Name::BoxHBargraph,
            Name::BoxVBargraph,
            Name::BoxCase,
            Name::BoxPatMatcher,
            Name::BoxPatVar,
            Name::BoxInputs,
            Name::BoxOutputs,
            Name::boxSoundfile,
            Name::boxMetadata,
            Name::DocEqn,
            Name::DocDgm,
            Name::DocNtc,
            Name::DocLst,
            Name::DocMtd,
            Name::DocTxt,
            Name::BARRIER,
            Name::uiFolder,
            Name::uiWidget,
            Name::ForeignFunction,
            Name::SigInput,
            Name::SigOutput,
            Name::SigDelay1,
            Name::SigDelay,
            Name::SigPrefix,
            Name::SigRDTbl,
            Name::SigWRTbl,
            Name::SigTable,
            Name::SigGen,
            Name::SigDocConstantTbl,
            Name::SigDocWriteTbl,
            Name::SigDocAccessTbl,
            Name::SigSelect2,
            Name::sigAssertBounds,
            Name::sigHighest,
            Name::sigLowest,
            Name::SigBinOp,
            Name::SigFFun,
            Name::SigFConst,
            Name::SigFVar,
            Name::SigProj,
            Name::SigIntCast,
            Name::SigFloatCast,
            Name::SigButton,
            Name::SigCheckbox,
            Name::SigWaveform,
            Name::SigHSlider,
            Name::SigVSlider,
            Name::SigNumEntry,
            Name::SigHBargraph,
            Name::SigVBargraph,
            Name::SigAttach,
            Name::SigEnable,
            Name::SigControl,
            Name::SigSoundfile,
            Name::SigSoundfileLength,
            Name::SigSoundfileRate,
            Name::SigSoundfileBuffer,
            Name::SigTuple,
            Name::SigTupleAccess,
            Name::SimpleType,
            Name::TableType,
            Name::TupletType,
            Name::DEBRUIJN,
            Name::DEBRUIJNREF,
            Name::SUBSTITUTE,
            Name::SYMREC,
            Name::SYMRECREF,
            Name::LIFTN,
            Name::cons,
            Name::nil,
            Name::process,
            Name::boxTypeProp,
            Name::NUMERICPROPERTY,
            Name::DefLineProp,
            Name::UseLineProp,
            Name::sigSimplifiedProp,
            Name::DocTablesProp,
            Name::NullRenameEnv,
            Name::ColorProperty,
            Name::OrderProp,
            Name::RecursivnessProp,
            Name::NullTypeEnv,
            Name::RECDEF,
            Name::deBruijn2Sym,
            Name::NormalForm,
            Name::DEFNAMEPROPERTY,
            Name::NICKNAMEPROPERTY,
            Name::PropagateProperty,
            Name::abs,
            Name::acos,
            Name::asin,
            Name::atan2,
            Name::atan,
            Name::ceil,
            Name::cos,
            Name::exp,
            Name::exp10,
            Name::floor,
            Name::fmod,
            Name::ftz,
            Name::log10,
            Name::log,
            Name::max,
            Name::min,
            Name::pow,
            Name::remainder,
            Name::rint,
            Name::sin,
            Name::sqrt,
            Name::tan,
            Name::QQQQ
          >
        {};
        
        Internal& internal();

    };
  };
};

#endif

