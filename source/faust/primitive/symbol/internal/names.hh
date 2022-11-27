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

#ifndef __FAUST__PRIMITIVE__SYMBOL__INTERNAL__NAME__HH__
#define __FAUST__PRIMITIVE__SYMBOL__INTERNAL__NAME__HH__

namespace Faust {
  namespace Primitive {
    namespace Symbol {
      namespace Internal {
        namespace Name {

          constexpr const char EvalProperty[] = "EvalProperty";
          constexpr const char PMPROPERTY[] = "PMPROPERTY";
          constexpr const char BCOMPLEXITY[] = "BCOMPLEXITY";
          constexpr const char BoxIdent[] = "BoxIdent";
          constexpr const char BoxCut[] = "BoxCut";
          constexpr const char BoxWaveform[] = "BoxWaveform";
          constexpr const char BoxRoute[] = "BoxRoute";
          constexpr const char BoxWire[] = "BoxWire";
          constexpr const char BoxSlot[] = "BoxSlot";
          constexpr const char BoxSymbolic[] = "BoxSymbolic";
          constexpr const char BoxSeq[] = "BoxSeq";
          constexpr const char BoxPar[] = "BoxPar";
          constexpr const char BoxRec[] = "BoxRec";
          constexpr const char BoxSplit[] = "BoxSplit";
          constexpr const char BoxMerge[] = "BoxMerge";
          constexpr const char BoxIPar[] = "BoxIPar";
          constexpr const char BoxISeq[] = "BoxISeq";
          constexpr const char BoxISum[] = "BoxISum";
          constexpr const char BoxIProd[] = "BoxIProd";
          constexpr const char BoxAbstr[] = "BoxAbstr";
          constexpr const char BoxAppl[] = "BoxAppl";
          constexpr const char Closure[] = "Closure";
          constexpr const char BoxError[] = "BoxError";
          constexpr const char BoxAccess[] = "BoxAccess";
          constexpr const char BoxWithLocalDef[] = "BoxWithLocalDef";
          constexpr const char BoxModifLocalDef[] = "BoxModifLocalDef";
          constexpr const char BoxEnvironment[] = "BoxEnvironment";
          constexpr const char BoxComponent[] = "BoxComponent";
          constexpr const char BoxLibrary[] = "BoxLibrary";
          constexpr const char ImportFile[] = "ImportFile";
          constexpr const char BoxPrim0[] = "BoxPrim0";
          constexpr const char BoxPrim1[] = "BoxPrim1";
          constexpr const char BoxPrim2[] = "BoxPrim2";
          constexpr const char BoxPrim3[] = "BoxPrim3";
          constexpr const char BoxPrim4[] = "BoxPrim4";
          constexpr const char BoxPrim5[] = "BoxPrim5";
          constexpr const char BoxFFun[] = "BoxFFun";
          constexpr const char BoxFConst[] = "BoxFConst";
          constexpr const char BoxFVar[] = "BoxFVar";
          constexpr const char BoxButton[] = "BoxButton";
          constexpr const char BoxCheckbox[] = "BoxCheckbox";
          constexpr const char BoxHSlider[] = "BoxHSlider";
          constexpr const char BoxVSlider[] = "BoxVSlider";
          constexpr const char BoxNumEntry[] = "BoxNumEntry";
          constexpr const char BoxHGroup[] = "BoxHGroup";
          constexpr const char BoxVGroup[] = "BoxVGroup";
          constexpr const char BoxTGroup[] = "BoxTGroup";
          constexpr const char BoxHBargraph[] = "BoxHBargraph";
          constexpr const char BoxVBargraph[] = "BoxVBargraph";
          constexpr const char BoxCase[] = "BoxCase";
          constexpr const char BoxPatMatcher[] = "BoxPatMatcher";
          constexpr const char BoxPatVar[] = "BoxPatVar";
          constexpr const char BoxInputs[] = "BoxInputs";
          constexpr const char BoxOutputs[] = "BoxOutputs";
          constexpr const char boxSoundfile[] = "boxSoundfile";
          constexpr const char boxMetadata[] = "boxMetadata";
          constexpr const char DocEqn[] = "DocEqn";
          constexpr const char DocDgm[] = "DocDgm";
          constexpr const char DocNtc[] = "DocNtc";
          constexpr const char DocLst[] = "DocLst";
          constexpr const char DocMtd[] = "DocMtd";
          constexpr const char DocTxt[] = "DocTxt";
          constexpr const char BARRIER[] = "BARRIER";
          constexpr const char uiFolder[] = "uiFolder";
          constexpr const char uiWidget[] = "uiWidget";
          constexpr const char ForeignFunction[] = "ForeignFunction";
          constexpr const char RECURSIVEBODY[] = "RECURSIVEBODY";
          constexpr const char SigInput[] = "SigInput";
          constexpr const char SigOutput[] = "SigOutput";
          constexpr const char SigDelay1[] = "SigDelay1";
          constexpr const char SigDelay[] = "SigDelay";
          constexpr const char SigPrefix[] = "SigPrefix";
          constexpr const char SigRDTbl[] = "SigRDTbl";
          constexpr const char SigWRTbl[] = "SigWRTbl";
          constexpr const char SigTable[] = "SigTable";
          constexpr const char SigGen[] = "SigGen";
          constexpr const char SigDocConstantTbl[] = "SigDocConstantTbl";
          constexpr const char SigDocWriteTbl[] = "SigDocWriteTbl";
          constexpr const char SigDocAccessTbl[] = "SigDocAccessTbl";
          constexpr const char SigSelect2[] = "SigSelect2";
          constexpr const char sigAssertBounds[] = "sigAssertBounds";
          constexpr const char sigHighest[] = "sigHighest";
          constexpr const char sigLowest[] = "sigLowest";
          constexpr const char SigBinOp[] = "SigBinOp";
          constexpr const char SigFFun[] = "SigFFun";
          constexpr const char SigFConst[] = "SigFConst";
          constexpr const char SigFVar[] = "SigFVar";
          constexpr const char SigProj[] = "SigProj";
          constexpr const char SigIntCast[] = "SigIntCast";
          constexpr const char SigFloatCast[] = "SigFloatCast";
          constexpr const char SigButton[] = "SigButton";
          constexpr const char SigCheckbox[] = "SigCheckbox";
          constexpr const char SigWaveform[] = "SigWaveform";
          constexpr const char SigHSlider[] = "SigHSlider";
          constexpr const char SigVSlider[] = "SigVSlider";
          constexpr const char SigNumEntry[] = "SigNumEntry";
          constexpr const char SigHBargraph[] = "SigHBargraph";
          constexpr const char SigVBargraph[] = "SigVBargraph";
          constexpr const char SigAttach[] = "SigAttach";
          constexpr const char SigEnable[] = "SigEnable";
          constexpr const char SigControl[] = "SigControl";
          constexpr const char SigSoundfile[] = "SigSoundfile";
          constexpr const char SigSoundfileLength[] = "SigSoundfileLength";
          constexpr const char SigSoundfileRate[] = "SigSoundfileRate";
          constexpr const char SigSoundfileBuffer[] = "SigSoundfileBuffer";
          constexpr const char SigTuple[] = "SigTuple";
          constexpr const char SigTupleAccess[] = "SigTupleAccess";
          constexpr const char SimpleType[] = "SimpleType";
          constexpr const char TableType[] = "TableType";
          constexpr const char TupletType[] = "TupletType";
          constexpr const char DEBRUIJN[] = "DEBRUIJN";
          constexpr const char DEBRUIJNREF[] = "DEBRUIJNREF";
          constexpr const char SUBSTITUTE[] = "SUBSTITUTE";
          constexpr const char SYMREC[] = "SYMREC";
          constexpr const char SYMRECREF[] = "SYMRECREF";
          constexpr const char LIFTN[] = "LIFTN";
          constexpr const char cons[] = "cons";
          constexpr const char nil[] = "nil";
          constexpr const char process[] = "process";
          constexpr const char boxTypeProp[] = "boxTypeProp";
          constexpr const char NUMERICPROPERTY[] = "NUMERICPROPERTY";
          constexpr const char DefLineProp[] = "DefLineProp";
          constexpr const char UseLineProp[] = "UseLineProp";
          constexpr const char sigSimplifiedProp[] = "sigSimplifiedProp";
          constexpr const char DocTablesProp[] = "DocTablesProp";
          constexpr const char NullRenameEnv[] = "NullRenameEnv";
          constexpr const char ColorProperty[] = "ColorProperty";
          constexpr const char OrderProp[] = "OrderProp";
          constexpr const char RecursivnessProp[] = "RecursivnessProp";
          constexpr const char NullTypeEnv[] = "NullTypeEnv";
          constexpr const char RECDEF[] = "RECDEF";
          constexpr const char deBruijn2Sym[] = "deBruijn2Sym";
          constexpr const char NormalForm[] = "NormalForm";
          constexpr const char DEFNAMEPROPERTY[] = "DEFNAMEPROPERTY";
          constexpr const char NICKNAMEPROPERTY[] = "NICKNAMEPROPERTY";
          constexpr const char PropagateProperty[] = "PropagateProperty";
          constexpr const char abs[] = "abs";
          constexpr const char acos[] = "acos";
          constexpr const char asin[] = "asin";
          constexpr const char atan2[] = "atan2";
          constexpr const char atan[] = "atan";
          constexpr const char ceil[] = "ceil";
          constexpr const char cos[] = "cos";
          constexpr const char exp[] = "exp";
          constexpr const char exp10[] = "exp10";
          constexpr const char floor[] = "floor";
          constexpr const char fmod[] = "fmod";
          constexpr const char ftz[] = "ftz";
          constexpr const char log10[] = "log10";
          constexpr const char log[] = "log";
          constexpr const char max[] = "max";
          constexpr const char min[] = "min";
          constexpr const char pow[] = "pow";
          constexpr const char remainder[] = "remainder";
          constexpr const char rint[] = "rint";
          constexpr const char sin[] = "sin";
          constexpr const char sqrt[] = "sqrt";
          constexpr const char tan[] = "tan";
          constexpr const char QQQQ[] = "????";

        };
      };
    };
  };
};

#endif

