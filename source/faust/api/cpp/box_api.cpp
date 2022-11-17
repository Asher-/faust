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

#include "global.hh"
#include "faust.hh"
#include "libfaust.h"
#include "boxes/ppbox.hh"
#include "propagate.hh"
#include "normalform.hh"
#include "compiler/math_primitives/xtended.hh"

#include "faust/api/c/signal_api.hh"

#include "faust/primitive/math.hh"

// ============
// Box C++ API
// ============

// Can generate faustexception, used in createDSPFactoryFromBoxes and createInterpreterDSPFactoryFromBoxes
tvec boxesToSignalsAux(Tree box)
{
    int numInputs, numOutputs;
    if (!getBoxType(box, &numInputs, &numOutputs)) {
        stringstream error;
        error << "ERROR during the evaluation of process : " << boxpp(box) << endl;
        throw faustexception(error.str());
    }

    Tree outputs   = boxPropagateSig(global::config().nil, box, makeSigInputList(numInputs));
    Tree ouputs_nf = simplifyToNormalForm(outputs);
    return treeConvert(ouputs_nf);
}

LIBFAUST_API tvec boxesToSignals(Tree box, std::string& error_msg)
{
    try {
        return boxesToSignalsAux(box);
    } catch (faustexception& e) {
        error_msg = e.Message();
        return {};
    }
}

LIBFAUST_API std::string createSourceFromSignals(const std::string& name_app, tvec signals,
                                                 const std::string& lang,
                                                 int argc, const char* argv[],
                                                 std::string& error_msg);

LIBFAUST_API std::string createSourceFromBoxes(const std::string& name_app, Tree box,
                                               const std::string& lang,
                                               int argc, const char* argv[],
                                               std::string& error_msg)
{
    try {
        tvec signals = boxesToSignalsAux(box);
        return createSourceFromSignals(name_app, signals, lang, argc, argv, error_msg);
    } catch (faustexception& e) {
        return e.Message();
    }
}

LIBFAUST_API Tree boxDelay()
{
    return boxPrim2(sigDelay);
}

LIBFAUST_API Tree boxIntCast()
{
    return boxPrim1(sigIntCast);
}

LIBFAUST_API Tree boxFloatCast()
{
    return boxPrim1(sigFloatCast);
}

LIBFAUST_API Tree boxReadOnlyTable()
{
    return boxPrim3(sigReadOnlyTable);
}

LIBFAUST_API Tree boxWriteReadTable()
{
    return boxPrim5(sigWriteReadTable);
}

LIBFAUST_API Tree boxSoundfile(const std::string& label, Tree chan)
{
    return boxSoundfile(tree(label), chan);
}

LIBFAUST_API Tree boxSelect2()
{
    return boxPrim3(sigSelect2);
}

LIBFAUST_API Tree boxSelect3()
{
    return boxPrim4(sigSelect3);
}

LIBFAUST_API Tree boxFConst(SType type, const std::string& name, const std::string& file)
{
    return boxFConst(tree(type), tree(name), tree(file));
}

LIBFAUST_API Tree boxFVar(SType type, const std::string& name, const std::string& file)
{
    return boxFVar(tree(type), tree(name), tree(file));
}

LIBFAUST_API Tree boxBinOp(SOperator op)
{
    static sigFun fun[] = {sigAdd, sigSub, sigMul, sigDiv, sigRem, sigLeftShift, sigLRightShift, sigARightShift, sigGT,
                           sigLT,  sigGE,  sigLE,  sigEQ,  sigNE,  sigAND,       sigOR,          sigXOR};
    faustassert(op >= kAdd && op <= kXOR);
    return boxPrim2(fun[op]);
}

// Specific binary mathematical functions

LIBFAUST_API Tree boxAdd()
{
    return boxPrim2(sigAdd);
}
LIBFAUST_API Tree boxSub()
{
    return boxPrim2(sigSub);
}
LIBFAUST_API Tree boxMul()
{
    return boxPrim2(sigMul);
}
LIBFAUST_API Tree boxDiv()
{
    return boxPrim2(sigDiv);
}
LIBFAUST_API Tree boxRem()
{
    return boxPrim2(sigRem);
}

LIBFAUST_API Tree boxLeftShift()
{
    return boxPrim2(sigLeftShift);
}
LIBFAUST_API Tree boxLRightShift()
{
    return boxPrim2(sigLRightShift);
}
LIBFAUST_API Tree boxARightShift()
{
    return boxPrim2(sigARightShift);
}

LIBFAUST_API Tree boxGT()
{
    return boxPrim2(sigGT);
}
LIBFAUST_API Tree boxLT()
{
    return boxPrim2(sigLT);
}
LIBFAUST_API Tree boxGE()
{
    return boxPrim2(sigGE);
}
LIBFAUST_API Tree boxLE()
{
    return boxPrim2(sigLE);
}
LIBFAUST_API Tree boxEQ()
{
    return boxPrim2(sigEQ);
}
LIBFAUST_API Tree boxNE()
{
    return boxPrim2(sigNE);
}

LIBFAUST_API Tree boxAND()
{
    return boxPrim2(sigAND);
}
LIBFAUST_API Tree boxOR()
{
    return boxPrim2(sigOR);
}
LIBFAUST_API Tree boxXOR()
{
    return boxPrim2(sigXOR);
}

// Extended unary of binary mathematical functions

LIBFAUST_API Tree boxAbs()
{
    return ::Faust::Primitive::Math::abs.box();
}
LIBFAUST_API Tree boxAcos()
{
    return ::Faust::Primitive::Math::acos.box();
}
LIBFAUST_API Tree boxTan()
{
    return ::Faust::Primitive::Math::tan.box();
}
LIBFAUST_API Tree boxSqrt()
{
    return ::Faust::Primitive::Math::sqrt.box();
}
LIBFAUST_API Tree boxSin()
{
    return ::Faust::Primitive::Math::sin.box();
}
LIBFAUST_API Tree boxRint()
{
    return ::Faust::Primitive::Math::rint.box();
}
LIBFAUST_API Tree boxRemainder()
{
    return ::Faust::Primitive::Math::remainder.box();
}
LIBFAUST_API Tree boxPow()
{
    return ::Faust::Primitive::Math::pow.box();
}
LIBFAUST_API Tree boxMin()
{
    return ::Faust::Primitive::Math::min.box();
}
LIBFAUST_API Tree boxMax()
{
    return ::Faust::Primitive::Math::max.box();
}
LIBFAUST_API Tree boxLog()
{
    return ::Faust::Primitive::Math::log.box();
}
LIBFAUST_API Tree boxLog10()
{
    return ::Faust::Primitive::Math::log10.box();
}
LIBFAUST_API Tree boxFmod()
{
    return ::Faust::Primitive::Math::abs.box();
}
LIBFAUST_API Tree boxFloor()
{
    return ::Faust::Primitive::Math::floor.box();
}
LIBFAUST_API Tree boxExp()
{
    return ::Faust::Primitive::Math::exp.box();
}
LIBFAUST_API Tree boxExp10()
{
    return ::Faust::Primitive::Math::exp10.box();
}
LIBFAUST_API Tree boxCos()
{
    return ::Faust::Primitive::Math::abs.box();
}
LIBFAUST_API Tree boxCeil()
{
    return ::Faust::Primitive::Math::ceil.box();
}
LIBFAUST_API Tree boxAtan()
{
    return ::Faust::Primitive::Math::atan.box();
}
LIBFAUST_API Tree boxAtan2()
{
    return ::Faust::Primitive::Math::atan2.box();
}
LIBFAUST_API Tree boxAsin()
{
    return ::Faust::Primitive::Math::asin.box();
}

// User Interface

LIBFAUST_API Tree boxButton(const std::string& label)
{
    return boxButton(tree(label));
}

LIBFAUST_API Tree boxCheckbox(const std::string& label)
{
    return boxButton(tree(label));
}

LIBFAUST_API Tree boxVSlider(const std::string& label, Tree init, Tree min, Tree max, Tree step)
{
    return boxVSlider(tree(label), init, min, max, step);
}

LIBFAUST_API Tree boxHSlider(const std::string& label, Tree init, Tree min, Tree max, Tree step)
{
    return boxHSlider(tree(label), init, min, max, step);
}

LIBFAUST_API Tree boxNumEntry(const std::string& label, Tree init, Tree min, Tree max, Tree step)
{
    return boxNumEntry(tree(label), init, min, max, step);
}

LIBFAUST_API Tree boxVBargraph(const std::string& label, Tree min, Tree max)
{
    return boxVBargraph(tree(label), min, max);
}

LIBFAUST_API Tree boxHBargraph(const std::string& label, Tree min, Tree max)
{
    return boxHBargraph(tree(label), min, max);
}

LIBFAUST_API Tree boxAttach()
{
    return boxPrim2(sigAttach);
}

// Helpers

LIBFAUST_API Tree boxPar3(Tree x, Tree y, Tree z)
{
    return boxPar(x, boxPar(y, z));
}

LIBFAUST_API Tree boxPar4(Tree a, Tree b, Tree c, Tree d)
{
    return boxPar(a, boxPar3(b, c, d));
}

LIBFAUST_API Tree boxPar5(Tree a, Tree b, Tree c, Tree d, Tree e)
{
    return boxPar(a, boxPar4(b, c, d, e));
}

LIBFAUST_API Tree boxDelay(Tree s, Tree del)
{
    return boxSeq(boxPar(s, del), boxDelay());
}

LIBFAUST_API Tree boxIntCast(Tree s)
{
    return boxSeq(s, boxIntCast());
}

LIBFAUST_API Tree boxFloatCast(Tree s)
{
    return boxSeq(s, boxFloatCast());
}

LIBFAUST_API Tree boxReadOnlyTable(Tree n, Tree init, Tree ridx)
{
    return boxSeq(boxPar3(n, init, ridx), boxReadOnlyTable());
}

LIBFAUST_API Tree boxWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx)
{
    return boxSeq(boxPar5(n, init, widx, wsig, ridx), boxWriteReadTable());
}

LIBFAUST_API Tree boxSoundfile(const std::string& label, Tree chan, Tree part, Tree ridx)
{
    return boxSeq(boxPar(part, ridx), boxSoundfile(label, chan));
}

LIBFAUST_API Tree boxSelect2(Tree selector, Tree s1, Tree s2)
{
    return boxSeq(boxPar3(selector, s1, s2), boxSelect2());
}

LIBFAUST_API Tree boxSelect3(Tree selector, Tree s1, Tree s2, Tree s3)
{
    return boxSeq(boxPar4(selector, s1, s2, s3), boxSelect3());
}

LIBFAUST_API Tree boxBinOp(SOperator op, Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxBinOp(op));
}

LIBFAUST_API Tree boxAdd(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxAdd());
}

LIBFAUST_API Tree boxSub(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxSub());
}

LIBFAUST_API Tree boxMul(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxMul());
}

LIBFAUST_API Tree boxDiv(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxDiv());
}

LIBFAUST_API Tree boxRem(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxRem());
}

LIBFAUST_API Tree boxLeftShift(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxLeftShift());
}

LIBFAUST_API Tree boxLRightShift(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxLRightShift());
}

LIBFAUST_API Tree boxARightShift(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxARightShift());
}

LIBFAUST_API Tree boxGT(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxGT());
}

LIBFAUST_API Tree boxLT(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxLT());
}

LIBFAUST_API Tree boxGE(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxGE());
}

LIBFAUST_API Tree boxLE(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxLE());
}

LIBFAUST_API Tree boxEQ(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxEQ());
}

LIBFAUST_API Tree boxNE(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxNE());
}

LIBFAUST_API Tree boxAND(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxAND());
}

LIBFAUST_API Tree boxOR(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxOR());
}

LIBFAUST_API Tree boxXOR(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxXOR());
}

LIBFAUST_API Tree boxAbs(Tree x)
{
    return boxSeq(x, boxAbs());
}

LIBFAUST_API Tree boxAcos(Tree x)
{
    return boxSeq(x, boxAcos());
}

LIBFAUST_API Tree boxTan(Tree x)
{
    return boxSeq(x, boxTan());
}

LIBFAUST_API Tree boxSqrt(Tree x)
{
    return boxSeq(x, boxSqrt());
}

LIBFAUST_API Tree boxSin(Tree x)
{
    return boxSeq(x, boxSin());
}

LIBFAUST_API Tree boxRint(Tree x)
{
    return boxSeq(x, boxRint());
}

LIBFAUST_API Tree boxLog(Tree x)
{
    return boxSeq(x, boxLog());
}

LIBFAUST_API Tree boxLog10(Tree x)
{
    return boxSeq(x, boxLog10());
}

LIBFAUST_API Tree boxFloor(Tree x)
{
    return boxSeq(x, boxFloor());
}

LIBFAUST_API Tree boxExp(Tree x)
{
    return boxSeq(x, boxExp());
}

LIBFAUST_API Tree boxExp10(Tree x)
{
    return boxSeq(x, boxExp10());
}

LIBFAUST_API Tree boxCos(Tree x)
{
    return boxSeq(x, boxCos());
}

LIBFAUST_API Tree boxCeil(Tree x)
{
    return boxSeq(x, boxCeil());
}

LIBFAUST_API Tree boxAtan(Tree x)
{
    return boxSeq(x, boxAtan());
}

LIBFAUST_API Tree boxAsin(Tree x)
{
    return boxSeq(x, boxAsin());
}

LIBFAUST_API Tree boxRemainder(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxRemainder());
}

LIBFAUST_API Tree boxPow(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxPow());
}

LIBFAUST_API Tree boxMin(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxMin());
}

LIBFAUST_API Tree boxMax(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxMax());
}

LIBFAUST_API Tree boxFmod(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxFmod());
}

LIBFAUST_API Tree boxAtan2(Tree b1, Tree b2)
{
    return boxSeq(boxPar(b1, b2), boxAtan2());
}

LIBFAUST_API Tree boxVBargraph(const std::string& label, Tree min, Tree max, Tree x)
{
    return boxSeq(x, boxVBargraph(label, min, max));
}

LIBFAUST_API Tree boxHBargraph(const std::string& label, Tree min, Tree max, Tree x)
{
    return boxSeq(x, boxHBargraph(label, min, max));
}

LIBFAUST_API Tree boxAttach(Tree s1, Tree s2)
{
    return boxSeq(boxPar(s1, s2), boxAttach());
}
