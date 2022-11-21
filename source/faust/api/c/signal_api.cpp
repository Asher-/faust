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

// =============
// Signal C API
// =============

#include "faust/api/faust.hh"
#include "faust/api/cpp/signal_api.hh"
#include "normalform.hh"


namespace Faust { namespace Primitive { namespace Math { class xtended; } } }
using xtended = ::Faust::Primitive::Math::xtended;

#ifdef __cplusplus
extern "C" {
#endif

LIBFAUST_API bool CisNil(Tree s)
{
    return isNil(s);
}

LIBFAUST_API const char * Ctree2str(Tree s)
{
    return tree2str(s).c_str();
}

LIBFAUST_API int Ctree2int(Tree s)
{
    return tree2int(s);
}

LIBFAUST_API xtended* CgetUserData(Tree s)
{
    return getUserData(s);
}

LIBFAUST_API Tree CsigInt(int n)
{
    return sigInt(n);
}

LIBFAUST_API Tree CsigReal(double n)
{
    return sigReal(n);
}

LIBFAUST_API Tree CsigInput(int idx)
{
    return sigInput(idx);
}

LIBFAUST_API Tree CsigDelay(Tree t0, Tree del)
{
    return sigDelay(t0, del);
}

LIBFAUST_API Tree CsigIntCast(Tree s)
{
    return sigIntCast(s);
}

LIBFAUST_API Tree CsigFloatCast(Tree s)
{
    return sigFloatCast(s);
}

LIBFAUST_API Tree CsigReadOnlyTable(Tree n, Tree init, Tree ridx)
{
    return sigReadOnlyTable(n, init, ridx);
}

LIBFAUST_API Tree CsigWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx)
{
    return sigWriteReadTable(n, init, widx, wsig, ridx);
}

LIBFAUST_API Tree CsigWaveform(Tree* wf_aux)
{
    tvec wf;
    int  i = 0;
    while (wf_aux[i]) {
        wf.push_back(wf_aux[i]);
        i++;
    }
    return sigWaveform(wf);
}

LIBFAUST_API Tree CsigSoundfile(const char* label)
{
    return sigSoundfile(label);
}

LIBFAUST_API Tree CsigSoundfileLength(Tree sf, Tree part)
{
    return sigSoundfileLength(sf, part);
}

LIBFAUST_API Tree CsigSoundfileRate(Tree sf, Tree part)
{
    return sigSoundfileRate(sf, part);
}

LIBFAUST_API Tree CsigSoundfileBuffer(Tree sf, Tree chan, Tree part, Tree ridx)
{
    return sigSoundfileBuffer(sf, chan, part, ridx);
}

LIBFAUST_API Tree CsigSelect2(Tree selector, Tree s1, Tree s2)
{
    return sigSelect2(selector, s1, s2);
}

LIBFAUST_API Tree CsigSelect3(Tree selector, Tree s1, Tree s2, Tree s3)
{
    return sigSelect3(selector, s1, s2, s3);
}

LIBFAUST_API Tree CsigFConst(SType type, const char* name, const char* file)
{
    return sigFConst(type, name, file);
}

LIBFAUST_API Tree CsigFVar(SType type, const char* name, const char* file)
{
    return sigFVar(type, name, file);
}

LIBFAUST_API Tree CsigBinOp(SOperator op, Tree x, Tree y)
{
    return sigBinOp(op, x, y);
}

LIBFAUST_API Tree CsigAdd(Tree x, Tree y)
{
    return sigAdd(x, y);
}
LIBFAUST_API Tree CsigSub(Tree x, Tree y)
{
    return sigSub(x, y);
}
LIBFAUST_API Tree CsigMul(Tree x, Tree y)
{
    return sigMul(x, y);
}
LIBFAUST_API Tree CsigDiv(Tree x, Tree y)
{
    return sigDiv(x, y);
}
LIBFAUST_API Tree CsigRem(Tree x, Tree y)
{
    return sigRem(x, y);
}

LIBFAUST_API Tree CsigLeftShift(Tree x, Tree y)
{
    return sigLeftShift(x, y);
}
LIBFAUST_API Tree CsigLRightShift(Tree x, Tree y)
{
    return sigLRightShift(x, y);
}
LIBFAUST_API Tree CsigARightShift(Tree x, Tree y)
{
    return sigARightShift(x, y);
}

LIBFAUST_API Tree CsigGT(Tree x, Tree y)
{
    return sigGT(x, y);
}
LIBFAUST_API Tree CsigLT(Tree x, Tree y)
{
    return sigLT(x, y);
}
LIBFAUST_API Tree CsigGE(Tree x, Tree y)
{
    return sigGE(x, y);
}
LIBFAUST_API Tree CsigLE(Tree x, Tree y)
{
    return sigLE(x, y);
}
LIBFAUST_API Tree CsigEQ(Tree x, Tree y)
{
    return sigEQ(x, y);
}
LIBFAUST_API Tree CsigNE(Tree x, Tree y)
{
    return sigNE(x, y);
}

LIBFAUST_API Tree CsigAND(Tree x, Tree y)
{
    return sigAND(x, y);
}
LIBFAUST_API Tree CsigOR(Tree x, Tree y)
{
    return sigOR(x, y);
}
LIBFAUST_API Tree CsigXOR(Tree x, Tree y)
{
    return sigXOR(x, y);
}

LIBFAUST_API Tree CsigAbs(Tree x)
{
    return sigAbs(x);
}
LIBFAUST_API Tree CsigAcos(Tree x)
{
    return sigAcos(x);
}
LIBFAUST_API Tree CsigTan(Tree x)
{
    return sigTan(x);
}
LIBFAUST_API Tree CsigSqrt(Tree x)
{
    return sigSqrt(x);
}
LIBFAUST_API Tree CsigSin(Tree x)
{
    return sigSin(x);
}
LIBFAUST_API Tree CsigRint(Tree x)
{
    return sigRint(x);
}
LIBFAUST_API Tree CsigRemainder(Tree x, Tree y)
{
    return sigRemainder(x, y);
}
LIBFAUST_API Tree CsigPow(Tree x, Tree y)
{
    return sigPow(x, y);
}
LIBFAUST_API Tree CsigMin(Tree x, Tree y)
{
    return sigMin(x, y);
}
LIBFAUST_API Tree CsigMax(Tree x, Tree y)
{
    return sigMax(x, y);
}
LIBFAUST_API Tree CsigLog(Tree x)
{
    return sigLog(x);
}
LIBFAUST_API Tree CsigLog10(Tree x)
{
    return sigLog10(x);
}
LIBFAUST_API Tree CsigFmod(Tree x, Tree y)
{
    return sigFmod(x, y);
}
LIBFAUST_API Tree CsigFloor(Tree x)
{
    return sigFloor(x);
}
LIBFAUST_API Tree CsigExp(Tree x)
{
    return sigExp(x);
}
LIBFAUST_API Tree CsigExp10(Tree x)
{
    return sigExp10(x);
}
LIBFAUST_API Tree CsigCos(Tree x)
{
    return sigCos(x);
}
LIBFAUST_API Tree CsigCeil(Tree x)
{
    return sigCeil(x);
}
LIBFAUST_API Tree CsigAtan(Tree x)
{
    return sigAtan(x);
}
LIBFAUST_API Tree CsigAtan2(Tree x, Tree y)
{
    return sigAtan2(x, y);
}
LIBFAUST_API Tree CsigAsin(Tree x)
{
    return sigAsin(x);
}

LIBFAUST_API Tree CsigSelf()
{
    return sigSelf();
}

LIBFAUST_API Tree CsigRecursion(Tree s1)
{
    return sigRecursion(s1);
}

LIBFAUST_API Tree CsigButton(const char* label)
{
    return sigButton(label);
}

LIBFAUST_API Tree CsigCheckbox(const char* label)
{
    return sigCheckbox(label);
}

LIBFAUST_API Tree CsigVSlider(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return sigVSlider(label, init, min, max, step);
}

LIBFAUST_API Tree CsigHSlider(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return sigHSlider(label, init, min, max, step);
}

LIBFAUST_API Tree CsigNumEntry(const char* label, Tree init, Tree min, Tree max, Tree step)
{
    return sigNumEntry(label, init, min, max, step);
}

LIBFAUST_API Tree CsigVBargraph(const char* label, Tree min, Tree max, Tree x)
{
    return sigVBargraph(label, min, max, x);
}

LIBFAUST_API Tree CsigHBargraph(const char* label, Tree min, Tree max, Tree x)
{
    return sigHBargraph(label, min, max, x);
}

LIBFAUST_API Tree CsigAttach(Tree x, Tree y)
{
    return sigAttach(y, y);
}

// Signal test API
LIBFAUST_API bool CisSigInt(Tree t, int* i)
{
    return isSigInt(t, i);
}
LIBFAUST_API bool CisSigReal(Tree t, double* r)
{
    return isSigReal(t, r);
}
LIBFAUST_API bool CisSigInput(Tree t, int* i)
{
    return isSigInput(t, i);
}
LIBFAUST_API bool CisSigOutput(Tree t, int* i, Tree* t0_aux)
{
    Tree t0;
    if (isSigOutput(t, i, t0)) {
        *t0_aux = t0;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigDelay1(Tree t, Tree* t0_aux)
{
    Tree t0;
    if (isSigDelay1(t, t0)) {
        *t0_aux = t0;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigDelay(Tree t, Tree* t0_aux, Tree* t1_aux)
{
    Tree t0, t1;
    if (isSigDelay(t, t0, t1)) {
        *t0_aux = t0;
        *t1_aux = t1;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigPrefix(Tree t, Tree* t0_aux, Tree* t1_aux)
{
    Tree t0, t1;
    if (isSigPrefix(t, t0, t1)) {
        *t0_aux = t0;
        *t1_aux = t1;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigRDTbl(Tree s, Tree* t_aux, Tree* i_aux)
{
    Tree t, i;
    if (isSigRDTbl(s, t, i)) {
        *t_aux = t;
        *i_aux = i;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigWRTbl(Tree u, Tree* id_aux, Tree* t_aux, Tree* i_aux, Tree* s_aux)
{
    Tree id, t, i, s;
    if (isSigWRTbl(u, id, t, i, s)) {
        *id_aux = id;
        *t_aux  = t;
        *i_aux  = i;
        *s_aux  = s;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigTable(Tree t, Tree* id_aux, Tree* n_aux, Tree* sig_aux)
{
    Tree id, n, sig;
    if (isSigTable(t, id, n, sig)) {
        *id_aux  = id;
        *n_aux   = n;
        *sig_aux = sig;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigGen(Tree t, Tree* x_aux)
{
    Tree x;
    if (isSigGen(t, x)) {
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigDocConstantTbl(Tree t, Tree* n_aux, Tree* sig_aux)
{
    Tree n, sig;
    if (isSigDocConstantTbl(t, n, sig)) {
        *n_aux   = n;
        *sig_aux = sig;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigDocWriteTbl(Tree t, Tree* n_aux, Tree* sig_aux, Tree* widx_aux, Tree* wsig_aux)
{
    Tree n, sig, widx, wsig;
    if (isSigDocWriteTbl(t, n, sig, widx, wsig)) {
        *n_aux    = n;
        *sig_aux  = sig;
        *widx_aux = widx;
        *wsig_aux = wsig;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigDocAccessTbl(Tree t, Tree* tbl_aux, Tree* ridx_aux)
{
    Tree tbl, ridx;
    if (isSigDocAccessTbl(t, tbl, ridx)) {
        *tbl_aux  = tbl;
        *ridx_aux = ridx;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigSelect2(Tree t, Tree* selector_aux, Tree* s1_aux, Tree* s2_aux)
{
    Tree selector, s1, s2;
    if (isSigSelect2(t, selector, s1, s2)) {
        *selector_aux = selector;
        *s1_aux       = s1;
        *s2_aux       = s2;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigAssertBounds(Tree t, Tree* s1_aux, Tree* s2_aux, Tree* s3_aux)
{
    Tree s1, s2, s3;
    if (isSigAssertBounds(t, s1, s2, s3)) {
        *s1_aux = s1;
        *s2_aux = s2;
        *s2_aux = s2;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigHighest(Tree t, Tree* s_aux)
{
    Tree s;
    if (isSigHighest(t, s)) {
        *s_aux = s;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigLowest(Tree t, Tree* s_aux)
{
    Tree s;
    if (isSigLowest(t, s)) {
        *s_aux = s;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigBinOp(Tree s, int* op, Tree* x_aux, Tree* y_aux)
{
    Tree x, y;
    if (isSigBinOp(s, op, x, y)) {
        *x_aux = x;
        *y_aux = y;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigFFun(Tree s, Tree* ff_aux, Tree* largs_aux)
{
    Tree ff, largs;
    if (isSigFFun(s, ff, largs)) {
        *ff_aux    = ff;
        *largs_aux = largs;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigFConst(Tree s, Tree* type_aux, Tree* name_aux, Tree* file_aux)
{
    Tree type, name, file;
    if (isSigFConst(s, type, name, file)) {
        *type_aux = type;
        *name_aux = name;
        *file_aux = file;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigFVar(Tree s, Tree* type_aux, Tree* name_aux, Tree* file_aux)
{
    Tree type, name, file;
    if (isSigFVar(s, type, name, file)) {
        *type_aux = type;
        *name_aux = name;
        *file_aux = file;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisProj(Tree s, int* i, Tree* rgroup_aux)
{
    Tree rgroup;
    if (isProj(s, i, rgroup)) {
        *rgroup_aux = rgroup;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisRec(Tree s, Tree* var_aux, Tree* body_aux)
{
    Tree var, body;
    if (isRec(s, var, body)) {
        *var_aux  = var;
        *body_aux = body;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigIntCast(Tree s, Tree* x_aux)
{
    Tree x;
    if (isSigIntCast(s, x)) {
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigFloatCast(Tree s, Tree* x_aux)
{
    Tree x;
    if (isSigFloatCast(s, x)) {
        *x_aux = x;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigButton(Tree s, Tree* lbl_aux)
{
    Tree lbl;
    if (isSigButton(s, lbl)) {
        *lbl_aux = lbl;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigCheckbox(Tree s, Tree* lbl_aux)
{
    Tree lbl;
    if (isSigCheckbox(s, lbl)) {
        *lbl_aux = lbl;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigWaveform(Tree s)
{
    return isSigWaveform(s);
}

LIBFAUST_API bool CisSigHSlider(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, init, min, max, step;
    if (isSigHSlider(s, lbl, init, min, max, step)) {
        *lbl_aux  = lbl;
        *init_aux = init;
        *min_aux  = min;
        *max_aux  = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigVSlider(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, init, min, max, step;
    if (isSigVSlider(s, lbl, init, min, max, step)) {
        *lbl_aux  = lbl;
        *init_aux = init;
        *min_aux  = min;
        *max_aux  = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigNumEntry(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux)
{
    Tree lbl, init, min, max, step;
    if (isSigNumEntry(s, lbl, init, min, max, step)) {
        *lbl_aux  = lbl;
        *init_aux = init;
        *min_aux  = min;
        *max_aux  = max;
        *step_aux = step;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigHBargraph(Tree s, Tree* lbl_aux, Tree* min_aux, Tree* max_aux, Tree* x_aux)
{
    Tree lbl, min, max, x0;
    if (isSigHBargraph(s, lbl, min, max, x0)) {
        *lbl_aux = lbl;
        *min_aux = min;
        *max_aux = max;
        *x_aux   = x0;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigVBargraph(Tree s, Tree* lbl_aux, Tree* min_aux, Tree* max_aux, Tree* x_aux)
{
    Tree lbl, min, max, x0;
    if (isSigVBargraph(s, lbl, min, max, x0)) {
        *lbl_aux = lbl;
        *min_aux = min;
        *max_aux = max;
        *x_aux   = x0;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigAttach(Tree s, Tree* s0_aux, Tree* s1_aux)
{
    Tree s0, s1;
    if (isSigAttach(s, s0, s1)) {
        *s0_aux = s0;
        *s1_aux = s1;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigEnable(Tree s, Tree* s0_aux, Tree* s1_aux)
{
    Tree s0, s1;
    if (isSigEnable(s, s0, s1)) {
        *s0_aux = s0;
        *s1_aux = s1;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigControl(Tree s, Tree* s0_aux, Tree* s1_aux)
{
    Tree s0, s1;
    if (isSigControl(s, s0, s1)) {
        *s0_aux = s0;
        *s1_aux = s1;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API bool CisSigSoundfile(Tree s, Tree* label_aux)
{
    Tree label;
    if (isSigSoundfile(s, label)) {
        *label_aux = label;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigSoundfileLength(Tree s, Tree* sf_aux, Tree* part_aux)
{
    Tree sf, part;
    if (isSigSoundfileLength(s, sf, part)) {
        *sf_aux   = sf;
        *part_aux = part;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigSoundfileRate(Tree s, Tree* sf_aux, Tree* part_aux)
{
    Tree sf, part;
    if (isSigSoundfileRate(s, sf, part)) {
        *sf_aux   = sf;
        *part_aux = part;
        return true;
    } else {
        return false;
    }
}
LIBFAUST_API bool CisSigSoundfileBuffer(Tree s, Tree* sf_aux, Tree* chan_aux, Tree* part_aux, Tree* ridx_aux)
{
    Tree sf, chan, part, ridx;
    if (isSigSoundfileBuffer(s, sf, chan, part, ridx)) {
        *sf_aux   = sf;
        *chan_aux = chan;
        *part_aux = part;
        *ridx_aux = ridx;
        return true;
    } else {
        return false;
    }
}

LIBFAUST_API Tree CsimplifyToNormalForm(Tree s)
{
    return simplifyToNormalForm(s);
}

LIBFAUST_API Tree* CsimplifyToNormalForm2(Tree* s)
{
    tvec inputs;
    int  in = 0;
    while (s[in]) {
        inputs.push_back(s[in]);
        in++;
    }
    tvec outputs = simplifyToNormalForm2(inputs);
    if (outputs.size() > 0) {
        Tree*  res = (Tree*)malloc(sizeof(Tree) * (outputs.size() + 1));
        size_t i;
        for (i = 0; i < outputs.size(); i++) res[i] = outputs[i];
        res[i] = nullptr;
        return res;
    } else {
        return nullptr;
    }
}

#ifdef __cplusplus
}
#endif
