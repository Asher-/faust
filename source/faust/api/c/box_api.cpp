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

// ==========
// Box C API
// ==========

#include "faust/api/faust.hh"
#include "faust/api/cpp/box_api.hh"

#ifdef __cplusplus
extern "C" {
#endif

LIBFAUST_API Tree CDSPToBoxes(const char* name_app, const char* dsp_content, int argc, const char* argv[], int* inputs, int* outputs, char* error_msg)
{
    string error_msg_aux;
    Tree   box = DSPToBoxes(name_app, dsp_content, argc, argv, inputs, outputs, error_msg_aux);
    strncpy(error_msg, error_msg_aux.c_str(), 4096);
    return box;
}

LIBFAUST_API bool CgetBoxType(Tree box, int* inputs, int* outputs)
{
    return getBoxType(box, inputs, outputs);
}

LIBFAUST_API Tree* CboxesToSignals(Tree box, char* error_msg)
{
    string error_msg_aux;
    tvec   signals = boxesToSignals(box, error_msg_aux);
    strncpy(error_msg, error_msg_aux.c_str(), 4096);
    if (signals.size() > 0) {
        Tree*  res = (Tree*)malloc(sizeof(Tree) * (signals.size() + 1));
        size_t i;
        for (i = 0; i < signals.size(); i++) res[i] = signals[i];
        res[i] = nullptr;
        return res;
    } else {
        return nullptr;
    }
}

LIBFAUST_API Tree CboxInt(int n)
{
    return boxInt(n);
}

LIBFAUST_API Tree CboxReal(double n)
{
    return boxReal(n);
}

LIBFAUST_API Tree CboxWire()
{
    return boxWire();
}

LIBFAUST_API Tree CboxCut()
{
    return boxCut();
}

LIBFAUST_API Tree CboxSeq(Tree x, Tree y)
{
    return boxSeq(x, y);
}

LIBFAUST_API Tree CboxPar(Tree x, Tree y)
{
    return boxPar(x, y);
}

LIBFAUST_API Tree CboxSplit(Tree x, Tree y)
{
    return boxSplit(x, y);
}

LIBFAUST_API Tree CboxMerge(Tree x, Tree y)
{
    return boxMerge(x, y);
}

LIBFAUST_API Tree CboxRec(Tree x, Tree y)
{
    return boxRec(x, y);
}

LIBFAUST_API Tree CboxRoute(Tree n, Tree m, Tree r)
{
    return boxRoute(n, m, r);
}

LIBFAUST_API Tree CboxDelay()
{
    return boxDelay();
}

LIBFAUST_API Tree CboxIntCast()
{
    return boxIntCast();
}

LIBFAUST_API Tree CboxFloatCast()
{
    return boxFloatCast();
}

LIBFAUST_API Tree CboxReadOnlyTable()
{
    return boxReadOnlyTable();
}

LIBFAUST_API Tree CboxWriteReadTable()
{
    return boxWriteReadTable();
}

LIBFAUST_API Tree CboxWaveform(Tree* wf_aux)
{
    tvec wf;
    int  i = 0;
    while (wf_aux[i]) {
        wf.push_back(wf_aux[i]);
        i++;
    }
    return boxWaveform(wf);
}

LIBFAUST_API Tree CboxSoundfile(const char* label, Tree chan)
{
    return boxSoundfile(label, chan);
}

LIBFAUST_API Tree CboxSelect2()
{
    return boxSelect2();
}

LIBFAUST_API Tree CboxSelect3()
{
    return boxSelect3();
}

LIBFAUST_API Tree CboxFConst(SType type, const char* name, const char* file)
{
    return boxFConst(type, name, file);
}

LIBFAUST_API Tree CboxFVar(SType type, const char* name, const char* file)
{
    return boxFVar(type, name, file);
}

LIBFAUST_API Tree CboxBinOp(SOperator op)
{
    return boxBinOp(op);
}

// Specific binary mathematical functions

LIBFAUST_API Tree CboxAdd()
{
    return boxAdd();
}
LIBFAUST_API Tree CboxSub()
{
    return boxSub();
}
LIBFAUST_API Tree CboxMul()
{
    return boxMul();
}
LIBFAUST_API Tree CboxDiv()
{
    return boxDiv();
}
LIBFAUST_API Tree CboxRem()
{
    return boxRem();
}

LIBFAUST_API Tree CboxLeftShift()
{
    return boxLeftShift();
}
LIBFAUST_API Tree CboxLRightShift()
{
    return boxLRightShift();
}
LIBFAUST_API Tree CboxARightShift()
{
    return boxARightShift();
}

LIBFAUST_API Tree CboxGT()
{
    return boxGT();
}
LIBFAUST_API Tree CboxLT()
{
    return boxLT();
}
LIBFAUST_API Tree CboxGE()
{
    return boxGE();
}
LIBFAUST_API Tree CboxLE()
{
    return boxLE();
}
LIBFAUST_API Tree CboxEQ()
{
    return boxEQ();
}
LIBFAUST_API Tree CboxNE()
{
    return boxNE();
}

LIBFAUST_API Tree CboxAND()
{
    return boxAND();
}
LIBFAUST_API Tree CboxOR()
{
    return boxOR();
}
LIBFAUST_API Tree CboxXOR()
{
    return boxXOR();
}

// Extended unary of binary mathematical functions

LIBFAUST_API Tree CboxAbs()
{
    return boxAbs();
}
LIBFAUST_API Tree CboxAcos()
{
    return boxAcos();
}
LIBFAUST_API Tree CboxTan()
{
    return boxTan();
}
LIBFAUST_API Tree CboxSqrt()
{
    return boxSqrt();
}
LIBFAUST_API Tree CboxSin()
{
    return boxSin();
}
LIBFAUST_API Tree CboxRint()
{
    return boxRint();
}
LIBFAUST_API Tree CboxRemainder()
{
    return boxRemainder();
}
LIBFAUST_API Tree CboxPow()
{
    return boxPow();
}
LIBFAUST_API Tree CboxMin()
{
    return boxMin();
}
LIBFAUST_API Tree CboxMax()
{
    return boxMax();
}
LIBFAUST_API Tree CboxLog()
{
    return boxLog();
}
LIBFAUST_API Tree CboxLog10()
{
    return boxLog10();
}
LIBFAUST_API Tree CboxFmod()
{
    return boxFmod();
}
LIBFAUST_API Tree CboxFloor()
{
    return boxFloor();
}
LIBFAUST_API Tree CboxExp()
{
    return boxExp();
}
LIBFAUST_API Tree CboxExp10()
{
    return boxExp10();
}
LIBFAUST_API Tree CboxCos()
{
    return boxCos();
}
LIBFAUST_API Tree CboxCeil()
{
    return boxCeil();
}
LIBFAUST_API Tree CboxAtan()
{
    return boxAtan();
}
LIBFAUST_API Tree CboxAtan2()
{
    return boxAtan2();
}
LIBFAUST_API Tree CboxAsin()
{
    return boxAsin();
}

// User Interface

LIBFAUST_API Tree CboxButton(const char* label)
{
    return boxButton(label);
}

LIBFAUST_API Tree CboxCheckbox(const char* label)
{
    return boxButton(label);
}

LIBFAUST_API Tree CboxVSlider(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return boxVSlider(label, init, min, max, step);
}

LIBFAUST_API Tree CboxHSlider(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return boxHSlider(label, init, min, max, step);
}

LIBFAUST_API Tree CboxNumEntry(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return boxNumEntry(label, init, min, max, step);
}

LIBFAUST_API Tree CboxVBargraph(const char* label, Tree min, Tree max)
{
    return boxVBargraph(label, min, max);
}

LIBFAUST_API Tree CboxHBargraph(const char* label, Tree min, Tree max)
{
    return boxHBargraph(label, min, max);
}

LIBFAUST_API Tree CboxAttach()
{
    return boxAttach();
}

// Box test API

LIBFAUST_API bool CisBoxAbstr(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxAbstr(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxAccess(Tree t, Tree* exp_aux, Tree* id_aux)
{
    Tree exp, id;
    if (isBoxAccess(t, exp, id)) {
        *exp_aux = exp;
        *id_aux = id;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxAppl(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxAppl(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxButton(Tree t, Tree* lbl_aux)
{
    Tree lbl;
    if (isBoxButton(t, lbl)) {
        *lbl_aux = lbl;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxCase(Tree t, Tree* rules_aux)
{
    Tree rules;
    if (isBoxCase(t, rules)) {
        *rules_aux = rules;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxCheckbox(Tree t, Tree* lbl_aux)
{
    Tree lbl;
    if (isBoxCheckbox(t, lbl)) {
        *lbl_aux = lbl;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxComponent(Tree t, Tree* filename_aux)
{
    Tree filename;
    if (isBoxComponent(t, filename)) {
        *filename_aux = filename;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxCut(Tree t)
{
    return isBoxCut(t);
}

LIBFAUST_API bool CisBoxEnvironment(Tree t)
{
    return isBoxEnvironment(t);
}

LIBFAUST_API bool CisBoxError(Tree t)
{
    return isBoxError(t);
}

LIBFAUST_API bool CisBoxFConst(Tree t, Tree* type_aux, Tree* name_aux, Tree* file_aux)
{
    Tree type, name, file;
    if (isBoxFConst(t, type, name, file)) {
        *type_aux = type;
        *name_aux = name;
        *file_aux = file;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxFFun(Tree t, Tree* ff_aux)
{
    Tree ff;
    if (isBoxFFun(t, ff)) {
        *ff_aux = ff;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxFVar(Tree t, Tree* type_aux, Tree* name_aux, Tree* file_aux)
{
    Tree type, name, file;
    if (isBoxFVar(t, type, name, file)) {
        *type_aux = type;
        *name_aux = name;
        *file_aux = file;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxHBargraph(Tree t, Tree* lbl_aux, Tree* min_aux, Tree* max_aux)
{
    Tree lbl, min, max;
    if (isBoxHBargraph(t, lbl, min, max)) {
        *lbl_aux = lbl;
        *min_aux = min;
        *max_aux = max;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxHGroup(Tree t, Tree* lbl_aux, Tree* x_aux)
{
    Tree lbl, x;
    if (isBoxHGroup(t, lbl, x)) {
        *lbl_aux = lbl;
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxHSlider(Tree t, Tree* lbl_aux, Tree* cur_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, cur, min, max, step;
    if (isBoxHSlider(t, lbl, cur, min, max, step)) {
        *lbl_aux = lbl;
        *cur_aux = cur;
        *min_aux = min;
        *max_aux = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxIdent(Tree t, const char** str)
{
    return isBoxIdent(t, str);
}

LIBFAUST_API bool CisBoxInputs(Tree t, Tree* x_aux)
{
    Tree x;
    if (isBoxInputs(t, x)) {
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxInt(Tree t, int* i)
{
    return isBoxInt(t, i);
}

LIBFAUST_API bool CisBoxIPar(Tree t, Tree* x_aux, Tree* y_aux, Tree* z_aux)
{
    Tree x, y, z;
    if (isBoxIPar(t, x, y, z)) {
        *x_aux = x;
        *y_aux = y;
        *z_aux = z;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxIProd(Tree t, Tree* x_aux, Tree* y_aux, Tree* z_aux)
{
    Tree x, y, z;
    if (isBoxIProd(t, x, y, z)) {
        *x_aux = x;
        *y_aux = y;
        *z_aux = z;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxISeq(Tree t, Tree* x_aux, Tree* y_aux, Tree* z_aux)
{
    Tree x, y, z;
    if (isBoxISeq(t, x, y, z)) {
        *x_aux = x;
        *y_aux = y;
        *z_aux = z;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxISum(Tree t, Tree* x_aux, Tree* y_aux, Tree* z_aux)
{
    Tree x, y, z;
    if (isBoxISum(t, x, y, z)) {
        *x_aux = x;
        *y_aux = y;
        *z_aux = z;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxLibrary(Tree t, Tree* filename_aux)
{
    Tree filename;
    if (isBoxLibrary(t, filename)) {
        *filename_aux = filename;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxMerge(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxMerge(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxMetadata(Tree t, Tree* exp_aux, Tree* mdlist_aux)
{
    Tree exp, mdlist;
    if (isBoxMetadata(t, exp, mdlist)) {
        *exp_aux = exp;
        *mdlist_aux = mdlist;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxNumEntry(Tree t, Tree* lbl_aux, Tree* cur_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, cur, min, max, step;
    if (isBoxNumEntry(t, lbl, cur, min, max, step)) {
        *lbl_aux = lbl;
        *cur_aux = cur;
        *min_aux = min;
        *max_aux = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxOutputs(Tree t, Tree* x_aux)
{
    Tree x;
    if (isBoxOutputs(t, x)) {
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxPar(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxPar(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxPrim0(Tree t)
{
    return isBoxPrim0(t);
}

LIBFAUST_API bool CisBoxPrim1(Tree t)
{
    return isBoxPrim1(t);
}

LIBFAUST_API bool CisBoxPrim2(Tree t)
{
    return isBoxPrim2(t);
}

LIBFAUST_API bool CisBoxPrim3(Tree t)
{
    return isBoxPrim3(t);
}

LIBFAUST_API bool CisBoxPrim4(Tree t)
{
    return isBoxPrim4(t);
}

LIBFAUST_API bool CisBoxPrim5(Tree t)
{
    return isBoxPrim5(t);
}

LIBFAUST_API bool CisBoxReal(Tree t, double* r)
{
    return isBoxReal(t, r);
}

LIBFAUST_API bool CisBoxRec(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxRec(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxRoute(Tree t, Tree* n_aux, Tree* m_aux, Tree* r_aux)
{
    Tree n, m, r;
    if (isBoxRoute(t, n, m, r)) {
        *n_aux = n;
        *m_aux = m;
        *r_aux = r;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxSeq(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxSeq(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxSlot(Tree t, int* id)
{
    return isBoxSlot(t, id);
}

LIBFAUST_API bool CisBoxSoundfile(Tree t, Tree* label_aux, Tree* chan_aux)
{
    Tree label, chan;
    if (isBoxSoundfile(t, label, chan)) {
        *label_aux = label;
        *chan_aux = chan;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxSplit(Tree t, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isBoxSplit(t, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxSymbolic(Tree t, Tree* slot_aux, Tree* body_aux)
{
    Tree slot, body;
    if (isBoxSymbolic(t, slot, body)) {
        *slot_aux = slot;
        *body_aux = body;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxTGroup(Tree t, Tree* lbl_aux, Tree* x_aux)
{
    Tree lbl, x;
    if (isBoxTGroup(t, lbl, x)) {
        *lbl_aux = lbl;
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxVBargraph(Tree t, Tree* lbl_aux, Tree* min_aux, Tree* max_aux)
{
    Tree lbl, min, max;
    if (isBoxVBargraph(t, lbl, min, max)) {
        *lbl_aux = lbl;
        *min_aux = min;
        *max_aux = max;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxVGroup(Tree t, Tree* lbl_aux, Tree* x_aux)
{
    Tree lbl, x;
    if (isBoxVGroup(t, lbl, x)) {
        *lbl_aux = lbl;
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxVSlider(Tree t, Tree* lbl_aux, Tree* cur_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, cur, min, max, step;
    if (isBoxVSlider(t, lbl, cur, min, max, step)) {
        *lbl_aux = lbl;
        *cur_aux = cur;
        *min_aux = min;
        *max_aux = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisBoxWaveform(Tree t)
{
    return isBoxWaveform(t);
}

LIBFAUST_API bool CisBoxWire(Tree t)
{
    return isBoxWire(t);
}

LIBFAUST_API bool CisBoxWithLocalDef(Tree t, Tree* body_aux, Tree* ldef_aux)
{
    Tree body, ldef;
    if (isBoxWithLocalDef(t, body, ldef)) {
        *body_aux = body;
        *ldef_aux = ldef;
        return true;
    } else {
        return false;
    }
}

// Helpers

LIBFAUST_API Tree CboxPar3(Tree x, Tree y, Tree z)
{
    return CboxPar(x, CboxPar(y, z));
}

LIBFAUST_API Tree CboxPar4(Tree a, Tree b, Tree c, Tree d)
{
    return CboxPar(a, CboxPar3(b, c, d));
}

LIBFAUST_API Tree CboxPar5(Tree a, Tree b, Tree c, Tree d, Tree e)
{
    return CboxPar(a, CboxPar4(b, c, d, e));
}

LIBFAUST_API Tree CboxDelayAux(Tree s, Tree del)
{
    return CboxSeq(CboxPar(s, del), CboxDelay());
}

LIBFAUST_API Tree CboxIntCastAux(Tree s)
{
    return CboxSeq(s, CboxIntCast());
}

LIBFAUST_API Tree CboxFloatCastAux(Tree s)
{
    return CboxSeq(s, CboxFloatCast());
}

LIBFAUST_API Tree CboxReadOnlyTableAux(Tree n, Tree init, Tree ridx)
{
    return CboxSeq(CboxPar3(n, init, ridx), CboxReadOnlyTable());
}

LIBFAUST_API Tree CboxWriteReadTableAux(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx)
{
    return CboxSeq(boxPar5(n, init, widx, wsig, ridx), CboxWriteReadTable());
}

LIBFAUST_API Tree CoxSoundfileAux(const char* label, Tree chan, Tree part, Tree ridx)
{
    return CboxSeq(CboxPar(part, ridx), CboxSoundfile(label, chan));
}

LIBFAUST_API Tree CboxSelect2Aux(Tree selector, Tree s1, Tree s2)
{
    return CboxSeq(CboxPar3(selector, s1, s2), CboxSelect2());
}

LIBFAUST_API Tree CboxSelect3Aux(Tree selector, Tree s1, Tree s2, Tree s3)
{
    return CboxSeq(CboxPar4(selector, s1, s2, s3), CboxSelect3());
}

LIBFAUST_API Tree CboxBinOpAux(SOperator op, Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxBinOp(op));
}

LIBFAUST_API Tree CboxAddAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxAdd());
}

LIBFAUST_API Tree CboxSubAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxSub());
}

LIBFAUST_API Tree CboxMulAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxMul());
}

LIBFAUST_API Tree CboxDivAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxDiv());
}

LIBFAUST_API Tree CboxRemAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxRem());
}

LIBFAUST_API Tree CboxLeftShiftAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxLeftShift());
}

LIBFAUST_API Tree CboxLRightShiftAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxLRightShift());
}

LIBFAUST_API Tree CboxARightShiftAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxARightShift());
}

LIBFAUST_API Tree CboxGTAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxGT());
}

LIBFAUST_API Tree CboxLTAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxLT());
}

LIBFAUST_API Tree CboxGEAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxGE());
}

LIBFAUST_API Tree CboxLEAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxLE());
}

LIBFAUST_API Tree CboxEQAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxEQ());
}

LIBFAUST_API Tree CboxNEAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxNE());
}

LIBFAUST_API Tree CboxANDAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxAND());
}

LIBFAUST_API Tree CboxORAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxOR());
}

LIBFAUST_API Tree CboxXORAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxXOR());
}

LIBFAUST_API Tree CboxAbsAux(Tree x)
{
    return CboxSeq(x, CboxAbs());
}

LIBFAUST_API Tree CboxAcosAux(Tree x)
{
    return CboxSeq(x, CboxAcos());
}

LIBFAUST_API Tree CboxTanAux(Tree x)
{
    return CboxSeq(x, CboxTan());
}

LIBFAUST_API Tree CboxSqrtAux(Tree x)
{
    return CboxSeq(x, CboxSqrt());
}

LIBFAUST_API Tree CboxSinAux(Tree x)
{
    return CboxSeq(x, CboxSin());
}

LIBFAUST_API Tree CboxRintAux(Tree x)
{
    return CboxSeq(x, CboxRint());
}

LIBFAUST_API Tree CboxLogAux(Tree x)
{
    return CboxSeq(x, CboxLog());
}

LIBFAUST_API Tree CboxLog10Aux(Tree x)
{
    return CboxSeq(x, CboxLog10());
}

LIBFAUST_API Tree CboxFloorAux(Tree x)
{
    return CboxSeq(x, CboxFloor());
}

LIBFAUST_API Tree CboxExpAux(Tree x)
{
    return CboxSeq(x, CboxExp());
}

LIBFAUST_API Tree CboxExp10Aux(Tree x)
{
    return CboxSeq(x, CboxExp10());
}

LIBFAUST_API Tree CboxCosAux(Tree x)
{
    return CboxSeq(x, CboxCos());
}

LIBFAUST_API Tree CboxCeilAux(Tree x)
{
    return CboxSeq(x, CboxCeil());
}

LIBFAUST_API Tree CboxAtanAux(Tree x)
{
    return CboxSeq(x, CboxAtan());
}

LIBFAUST_API Tree CboxAsinAux(Tree x)
{
    return CboxSeq(x, CboxAsin());
}

LIBFAUST_API Tree CboxRemainderAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxRemainder());
}

LIBFAUST_API Tree CboxPowAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxPow());
}

LIBFAUST_API Tree CboxMinAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxMin());
}

LIBFAUST_API Tree CboxMaxAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxMax());
}

LIBFAUST_API Tree CboxFmodAux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxFmod());
}

LIBFAUST_API Tree CboxAtan2Aux(Tree b1, Tree b2)
{
    return CboxSeq(CboxPar(b1, b2), CboxAtan2());
}

LIBFAUST_API Tree CboxVBargraphAux(const char* label, Tree min, Tree max, Tree x)
{
    return CboxSeq(x, CboxVBargraph(label, min, max));
}

LIBFAUST_API Tree CboxHBargraphAux(const char* label, Tree min, Tree max, Tree x)
{
    return CboxSeq(x, CboxHBargraph(label, min, max));
}

LIBFAUST_API Tree CboxAttachAux(Tree s1, Tree s2)
{
    return CboxSeq(CboxPar(s1, s2), CboxAttach());
}

#ifdef __cplusplus
}
#endif
