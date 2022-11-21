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

          constexpr const char EvalProperty[] = "EvalProperty\0";
          constexpr const char PMPROPERTY[] = "PMPROPERTY\0";
          constexpr const char BoxIdent[] = "BoxIdent\0";
          constexpr const char BoxCut[] = "BoxCut\0";
          constexpr const char BoxWaveform[] = "BoxWaveform\0";
          constexpr const char BoxRoute[] = "BoxRoute\0";
          constexpr const char BoxWire[] = "BoxWire\0";
          constexpr const char BoxSlot[] = "BoxSlot\0";
          constexpr const char BoxSymbolic[] = "BoxSymbolic\0";
          constexpr const char BoxSeq[] = "BoxSeq\0";
          constexpr const char BoxPar[] = "BoxPar\0";
          constexpr const char BoxRec[] = "BoxRec\0";
          constexpr const char BoxSplit[] = "BoxSplit\0";
          constexpr const char BoxMerge[] = "BoxMerge\0";
          constexpr const char BoxIPar[] = "BoxIPar\0";
          constexpr const char BoxISeq[] = "BoxISeq\0";
          constexpr const char BoxISum[] = "BoxISum\0";
          constexpr const char BoxIProd[] = "BoxIProd\0";
          constexpr const char BoxAbstr[] = "BoxAbstr\0";
          constexpr const char BoxAppl[] = "BoxAppl\0";
          constexpr const char Closure[] = "Closure\0";
          constexpr const char BoxError[] = "BoxError\0";
          constexpr const char BoxAccess[] = "BoxAccess\0";
          constexpr const char BoxWithLocalDef[] = "BoxWithLocalDef\0";
          constexpr const char BoxModifLocalDef[] = "BoxModifLocalDef\0";
          constexpr const char BoxEnvironment[] = "BoxEnvironment\0";
          constexpr const char BoxComponent[] = "BoxComponent\0";
          constexpr const char BoxLibrary[] = "BoxLibrary\0";
          constexpr const char ImportFile[] = "ImportFile\0";
          constexpr const char BoxPrim0[] = "BoxPrim0\0";
          constexpr const char BoxPrim1[] = "BoxPrim1\0";
          constexpr const char BoxPrim2[] = "BoxPrim2\0";
          constexpr const char BoxPrim3[] = "BoxPrim3\0";
          constexpr const char BoxPrim4[] = "BoxPrim4\0";
          constexpr const char BoxPrim5[] = "BoxPrim5\0";
          constexpr const char BoxFFun[] = "BoxFFun\0";
          constexpr const char BoxFConst[] = "BoxFConst\0";
          constexpr const char BoxFVar[] = "BoxFVar\0";
          constexpr const char BoxButton[] = "BoxButton\0";
          constexpr const char BoxCheckbox[] = "BoxCheckbox\0";
          constexpr const char BoxHSlider[] = "BoxHSlider\0";
          constexpr const char BoxVSlider[] = "BoxVSlider\0";
          constexpr const char BoxNumEntry[] = "BoxNumEntry\0";
          constexpr const char BoxHGroup[] = "BoxHGroup\0";
          constexpr const char BoxVGroup[] = "BoxVGroup\0";
          constexpr const char BoxTGroup[] = "BoxTGroup\0";
          constexpr const char BoxHBargraph[] = "BoxHBargraph\0";
          constexpr const char BoxVBargraph[] = "BoxVBargraph\0";
          constexpr const char BoxCase[] = "BoxCase\0";
          constexpr const char BoxPatMatcher[] = "BoxPatMatcher\0";
          constexpr const char BoxPatVar[] = "BoxPatVar\0";
          constexpr const char BoxInputs[] = "BoxInputs\0";
          constexpr const char BoxOutputs[] = "BoxOutputs\0";
          constexpr const char boxSoundfile[] = "boxSoundfile\0";
          constexpr const char boxMetadata[] = "boxMetadata\0";
          constexpr const char DocEqn[] = "DocEqn\0";
          constexpr const char DocDgm[] = "DocDgm\0";
          constexpr const char DocNtc[] = "DocNtc\0";
          constexpr const char DocLst[] = "DocLst\0";
          constexpr const char DocMtd[] = "DocMtd\0";
          constexpr const char DocTxt[] = "DocTxt\0";
          constexpr const char BARRIER[] = "BARRIER\0";
          constexpr const char uiFolder[] = "uiFolder\0";
          constexpr const char uiWidget[] = "uiWidget\0";
          constexpr const char ForeignFunction[] = "ForeignFunction\0";
          constexpr const char SigInput[] = "SigInput\0";
          constexpr const char SigOutput[] = "SigOutput\0";
          constexpr const char SigDelay1[] = "SigDelay1\0";
          constexpr const char SigDelay[] = "SigDelay\0";
          constexpr const char SigPrefix[] = "SigPrefix\0";
          constexpr const char SigRDTbl[] = "SigRDTbl\0";
          constexpr const char SigWRTbl[] = "SigWRTbl\0";
          constexpr const char SigTable[] = "SigTable\0";
          constexpr const char SigGen[] = "SigGen\0";
          constexpr const char SigDocConstantTbl[] = "SigDocConstantTbl\0";
          constexpr const char SigDocWriteTbl[] = "SigDocWriteTbl\0";
          constexpr const char SigDocAccessTbl[] = "SigDocAccessTbl\0";
          constexpr const char SigSelect2[] = "SigSelect2\0";
          constexpr const char sigAssertBounds[] = "sigAssertBounds\0";
          constexpr const char sigHighest[] = "sigHighest\0";
          constexpr const char sigLowest[] = "sigLowest\0";
          constexpr const char SigBinOp[] = "SigBinOp\0";
          constexpr const char SigFFun[] = "SigFFun\0";
          constexpr const char SigFConst[] = "SigFConst\0";
          constexpr const char SigFVar[] = "SigFVar\0";
          constexpr const char SigProj[] = "SigProj\0";
          constexpr const char SigIntCast[] = "SigIntCast\0";
          constexpr const char SigFloatCast[] = "SigFloatCast\0";
          constexpr const char SigButton[] = "SigButton\0";
          constexpr const char SigCheckbox[] = "SigCheckbox\0";
          constexpr const char SigWaveform[] = "SigWaveform\0";
          constexpr const char SigHSlider[] = "SigHSlider\0";
          constexpr const char SigVSlider[] = "SigVSlider\0";
          constexpr const char SigNumEntry[] = "SigNumEntry\0";
          constexpr const char SigHBargraph[] = "SigHBargraph\0";
          constexpr const char SigVBargraph[] = "SigVBargraph\0";
          constexpr const char SigAttach[] = "SigAttach\0";
          constexpr const char SigEnable[] = "SigEnable\0";
          constexpr const char SigControl[] = "SigControl\0";
          constexpr const char SigSoundfile[] = "SigSoundfile\0";
          constexpr const char SigSoundfileLength[] = "SigSoundfileLength\0";
          constexpr const char SigSoundfileRate[] = "SigSoundfileRate\0";
          constexpr const char SigSoundfileBuffer[] = "SigSoundfileBuffer\0";
          constexpr const char SigTuple[] = "SigTuple\0";
          constexpr const char SigTupleAccess[] = "SigTupleAccess\0";
          constexpr const char SimpleType[] = "SimpleType\0";
          constexpr const char TableType[] = "TableType\0";
          constexpr const char TupletType[] = "TupletType\0";
          constexpr const char DEBRUIJN[] = "DEBRUIJN\0";
          constexpr const char DEBRUIJNREF[] = "DEBRUIJNREF\0";
          constexpr const char SUBSTITUTE[] = "SUBSTITUTE\0";
          constexpr const char SYMREC[] = "SYMREC\0";
          constexpr const char SYMRECREF[] = "SYMRECREF\0";
          constexpr const char LIFTN[] = "LIFTN\0";
          constexpr const char cons[] = "cons\0";
          constexpr const char nil[] = "nil\0";
          constexpr const char process[] = "process\0";
          constexpr const char boxTypeProp[] = "boxTypeProp\0";
          constexpr const char NUMERICPROPERTY[] = "NUMERICPROPERTY\0";
          constexpr const char DefLineProp[] = "DefLineProp\0";
          constexpr const char UseLineProp[] = "UseLineProp\0";
          constexpr const char sigSimplifiedProp[] = "sigSimplifiedProp\0";
          constexpr const char DocTablesProp[] = "DocTablesProp\0";
          constexpr const char NullRenameEnv[] = "NullRenameEnv\0";
          constexpr const char ColorProperty[] = "ColorProperty\0";
          constexpr const char OrderProp[] = "OrderProp\0";
          constexpr const char RecursivnessProp[] = "RecursivnessProp\0";
          constexpr const char NullTypeEnv[] = "NullTypeEnv\0";
          constexpr const char RECDEF[] = "RECDEF\0";
          constexpr const char deBruijn2Sym[] = "deBruijn2Sym\0";
          constexpr const char NormalForm[] = "NormalForm\0";
          constexpr const char DEFNAMEPROPERTY[] = "DEFNAMEPROPERTY\0";
          constexpr const char NICKNAMEPROPERTY[] = "NICKNAMEPROPERTY\0";
          constexpr const char PropagateProperty[] = "PropagateProperty\0";
          constexpr const char abs[] = "abs\0";
          constexpr const char acos[] = "acos\0";
          constexpr const char asin[] = "asin\0";
          constexpr const char atan2[] = "atan2\0";
          constexpr const char atan[] = "atan\0";
          constexpr const char ceil[] = "ceil\0";
          constexpr const char cos[] = "cos\0";
          constexpr const char exp[] = "exp\0";
          constexpr const char exp10[] = "exp10\0";
          constexpr const char floor[] = "floor\0";
          constexpr const char fmod[] = "fmod\0";
          constexpr const char ftz[] = "ftz\0";
          constexpr const char log10[] = "log10\0";
          constexpr const char log[] = "log\0";
          constexpr const char max[] = "max\0";
          constexpr const char min[] = "min\0";
          constexpr const char pow[] = "pow\0";
          constexpr const char remainder[] = "remainder\0";
          constexpr const char rint[] = "rint\0";
          constexpr const char sin[] = "sin\0";
          constexpr const char sqrt[] = "sqrt\0";
          constexpr const char tan[] = "tan\0";
          constexpr const char QQQQ[] = "????\0";

        };
      };
    };
  };
};

#endif

