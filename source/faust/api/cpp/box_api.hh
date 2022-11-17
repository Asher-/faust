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

// ============
// Box C++ API
// ============

#include "faust/api/cpp/signal_api.hh"

#ifndef _BOX_API_H_
#define _BOX_API_H_

tvec boxesToSignalsAux(Tree box);
LIBFAUST_API tvec boxesToSignals(Tree box, std::string& error_msg);
LIBFAUST_API std::string createSourceFromBoxes(const std::string& name_app, Tree box,
                                               const std::string& lang,
                                               int argc, const char* argv[],
                                               std::string& error_msg);
LIBFAUST_API Tree boxDelay();
LIBFAUST_API Tree boxIntCast();
LIBFAUST_API Tree boxFloatCast();
LIBFAUST_API Tree boxReadOnlyTable();
LIBFAUST_API Tree boxWriteReadTable();
LIBFAUST_API Tree boxSoundfile(const std::string& label, Tree chan);
LIBFAUST_API Tree boxSelect2();
LIBFAUST_API Tree boxSelect3();
LIBFAUST_API Tree boxFConst(SType type, const std::string& name, const std::string& file);
LIBFAUST_API Tree boxFVar(SType type, const std::string& name, const std::string& file);
LIBFAUST_API Tree boxBinOp(SOperator op);
LIBFAUST_API Tree boxAdd();
LIBFAUST_API Tree boxSub();
LIBFAUST_API Tree boxMul();
LIBFAUST_API Tree boxDiv();
LIBFAUST_API Tree boxRem();
LIBFAUST_API Tree boxLeftShift();
LIBFAUST_API Tree boxLRightShift();
LIBFAUST_API Tree boxARightShift();
LIBFAUST_API Tree boxGT();
LIBFAUST_API Tree boxLT();
LIBFAUST_API Tree boxGE();
LIBFAUST_API Tree boxLE();
LIBFAUST_API Tree boxEQ();
LIBFAUST_API Tree boxNE();
LIBFAUST_API Tree boxAND();
LIBFAUST_API Tree boxOR();
LIBFAUST_API Tree boxXOR();
LIBFAUST_API Tree boxAbs();
LIBFAUST_API Tree boxAcos();
LIBFAUST_API Tree boxTan();
LIBFAUST_API Tree boxSqrt();
LIBFAUST_API Tree boxSin();
LIBFAUST_API Tree boxRint();
LIBFAUST_API Tree boxRemainder();
LIBFAUST_API Tree boxPow();
LIBFAUST_API Tree boxMin();
LIBFAUST_API Tree boxMax();
LIBFAUST_API Tree boxLog();
LIBFAUST_API Tree boxLog10();
LIBFAUST_API Tree boxFmod();
LIBFAUST_API Tree boxFloor();
LIBFAUST_API Tree boxExp();
LIBFAUST_API Tree boxExp10();
LIBFAUST_API Tree boxCos();
LIBFAUST_API Tree boxCeil();
LIBFAUST_API Tree boxAtan();
LIBFAUST_API Tree boxAtan2();
LIBFAUST_API Tree boxAsin();
LIBFAUST_API Tree boxButton(const std::string& label);
LIBFAUST_API Tree boxCheckbox(const std::string& label);
LIBFAUST_API Tree boxVSlider(const std::string& label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree boxHSlider(const std::string& label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree boxNumEntry(const std::string& label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree boxVBargraph(const std::string& label, Tree min, Tree max);
LIBFAUST_API Tree boxHBargraph(const std::string& label, Tree min, Tree max);
LIBFAUST_API Tree boxAttach();
LIBFAUST_API Tree boxPar3(Tree x, Tree y, Tree z);
LIBFAUST_API Tree boxPar4(Tree a, Tree b, Tree c, Tree d);
LIBFAUST_API Tree boxPar5(Tree a, Tree b, Tree c, Tree d, Tree e);
LIBFAUST_API Tree boxDelay(Tree s, Tree del);
LIBFAUST_API Tree boxIntCast(Tree s);
LIBFAUST_API Tree boxFloatCast(Tree s);
LIBFAUST_API Tree boxReadOnlyTable(Tree n, Tree init, Tree ridx);
LIBFAUST_API Tree boxWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx);
LIBFAUST_API Tree boxSoundfile(const std::string& label, Tree chan, Tree part, Tree ridx);
LIBFAUST_API Tree boxSelect2(Tree selector, Tree s1, Tree s2);
LIBFAUST_API Tree boxSelect3(Tree selector, Tree s1, Tree s2, Tree s3);
LIBFAUST_API Tree boxBinOp(SOperator op, Tree b1, Tree b2);
LIBFAUST_API Tree boxAdd(Tree b1, Tree b2);
LIBFAUST_API Tree boxSub(Tree b1, Tree b2);
LIBFAUST_API Tree boxMul(Tree b1, Tree b2);
LIBFAUST_API Tree boxDiv(Tree b1, Tree b2);
LIBFAUST_API Tree boxRem(Tree b1, Tree b2);
LIBFAUST_API Tree boxLeftShift(Tree b1, Tree b2);
LIBFAUST_API Tree boxLRightShift(Tree b1, Tree b2);
LIBFAUST_API Tree boxARightShift(Tree b1, Tree b2);
LIBFAUST_API Tree boxGT(Tree b1, Tree b2);
LIBFAUST_API Tree boxLT(Tree b1, Tree b2);
LIBFAUST_API Tree boxGE(Tree b1, Tree b2);
LIBFAUST_API Tree boxLE(Tree b1, Tree b2);
LIBFAUST_API Tree boxEQ(Tree b1, Tree b2);
LIBFAUST_API Tree boxNE(Tree b1, Tree b2);
LIBFAUST_API Tree boxAND(Tree b1, Tree b2);
LIBFAUST_API Tree boxOR(Tree b1, Tree b2);
LIBFAUST_API Tree boxXOR(Tree b1, Tree b2);
LIBFAUST_API Tree boxAbs(Tree x);
LIBFAUST_API Tree boxAcos(Tree x);
LIBFAUST_API Tree boxTan(Tree x);
LIBFAUST_API Tree boxSqrt(Tree x);
LIBFAUST_API Tree boxSin(Tree x);
LIBFAUST_API Tree boxRint(Tree x);
LIBFAUST_API Tree boxLog(Tree x);
LIBFAUST_API Tree boxLog10(Tree x);
LIBFAUST_API Tree boxFloor(Tree x);
LIBFAUST_API Tree boxExp(Tree x);
LIBFAUST_API Tree boxExp10(Tree x);
LIBFAUST_API Tree boxCos(Tree x);
LIBFAUST_API Tree boxCeil(Tree x);
LIBFAUST_API Tree boxAtan(Tree x);
LIBFAUST_API Tree boxAsin(Tree x);
LIBFAUST_API Tree boxRemainder(Tree b1, Tree b2);
LIBFAUST_API Tree boxPow(Tree b1, Tree b2);
LIBFAUST_API Tree boxMin(Tree b1, Tree b2);
LIBFAUST_API Tree boxMax(Tree b1, Tree b2);
LIBFAUST_API Tree boxFmod(Tree b1, Tree b2);
LIBFAUST_API Tree boxAtan2(Tree b1, Tree b2);
LIBFAUST_API Tree boxVBargraph(const std::string& label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree boxHBargraph(const std::string& label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree boxAttach(Tree s1, Tree s2);

#endif
