/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
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

#ifndef _C_SIGNAL_API_H_
#define _C_SIGNAL_API_H_

#include "faust/api/cpp/signal_api.hh"

#ifdef __cplusplus
extern "C" {
#endif

LIBFAUST_API bool CisNil(Tree s);
LIBFAUST_API const char* Ctree2str(Tree s);
LIBFAUST_API int Ctree2int(Tree s);
LIBFAUST_API void* CgetUserData(Tree s);
LIBFAUST_API Tree CsigInt(int n);
LIBFAUST_API Tree CsigReal(double n);
LIBFAUST_API Tree CsigInput(int idx);
LIBFAUST_API Tree CsigDelay(Tree t0, Tree del);
LIBFAUST_API Tree CsigIntCast(Tree s);
LIBFAUST_API Tree CsigFloatCast(Tree s);
LIBFAUST_API Tree CsigReadOnlyTable(Tree n, Tree init, Tree ridx);
LIBFAUST_API Tree CsigWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx);
LIBFAUST_API Tree CsigWaveform(Tree* wf_aux);
LIBFAUST_API Tree CsigSoundfile(const char* label);
LIBFAUST_API Tree CsigSoundfileLength(Tree sf, Tree part);
LIBFAUST_API Tree CsigSoundfileRate(Tree sf, Tree part);
LIBFAUST_API Tree CsigSoundfileBuffer(Tree sf, Tree chan, Tree part, Tree ridx);
LIBFAUST_API Tree CsigSelect2(Tree selector, Tree s1, Tree s2);
LIBFAUST_API Tree CsigSelect3(Tree selector, Tree s1, Tree s2, Tree s3);
LIBFAUST_API Tree CsigFConst(SType type, const char* name, const char* file);
LIBFAUST_API Tree CsigFVar(SType type, const char* name, const char* file);
LIBFAUST_API Tree CsigBinOp(SOperator op, Tree x, Tree y);
LIBFAUST_API Tree CsigAdd(Tree x, Tree y);
LIBFAUST_API Tree CsigSub(Tree x, Tree y);
LIBFAUST_API Tree CsigMul(Tree x, Tree y);
LIBFAUST_API Tree CsigDiv(Tree x, Tree y);
LIBFAUST_API Tree CsigRem(Tree x, Tree y);
LIBFAUST_API Tree CsigLeftShift(Tree x, Tree y);
LIBFAUST_API Tree CsigLRightShift(Tree x, Tree y);
LIBFAUST_API Tree CsigARightShift(Tree x, Tree y);
LIBFAUST_API Tree CsigGT(Tree x, Tree y);
LIBFAUST_API Tree CsigLT(Tree x, Tree y);
LIBFAUST_API Tree CsigGE(Tree x, Tree y);
LIBFAUST_API Tree CsigLE(Tree x, Tree y);
LIBFAUST_API Tree CsigEQ(Tree x, Tree y);
LIBFAUST_API Tree CsigNE(Tree x, Tree y);
LIBFAUST_API Tree CsigAND(Tree x, Tree y);
LIBFAUST_API Tree CsigOR(Tree x, Tree y);
LIBFAUST_API Tree CsigXOR(Tree x, Tree y);
LIBFAUST_API Tree CsigAbs(Tree x);
LIBFAUST_API Tree CsigAcos(Tree x);
LIBFAUST_API Tree CsigTan(Tree x);
LIBFAUST_API Tree CsigSqrt(Tree x);
LIBFAUST_API Tree CsigSin(Tree x);
LIBFAUST_API Tree CsigRint(Tree x);
LIBFAUST_API Tree CsigRemainder(Tree x, Tree y);
LIBFAUST_API Tree CsigPow(Tree x, Tree y);
LIBFAUST_API Tree CsigMin(Tree x, Tree y);
LIBFAUST_API Tree CsigMax(Tree x, Tree y);
LIBFAUST_API Tree CsigLog(Tree x);
LIBFAUST_API Tree CsigLog10(Tree x);
LIBFAUST_API Tree CsigFmod(Tree x, Tree y);
LIBFAUST_API Tree CsigFloor(Tree x);
LIBFAUST_API Tree CsigExp(Tree x);
LIBFAUST_API Tree CsigExp10(Tree x);
LIBFAUST_API Tree CsigCos(Tree x);
LIBFAUST_API Tree CsigCeil(Tree x);
LIBFAUST_API Tree CsigAtan(Tree x);
LIBFAUST_API Tree CsigAtan2(Tree x, Tree y);
LIBFAUST_API Tree CsigAsin(Tree x);
LIBFAUST_API Tree CsigSelf();
LIBFAUST_API Tree CsigRecursion(Tree s1);
LIBFAUST_API Tree CsigButton(const char* label);
LIBFAUST_API Tree CsigCheckbox(const char* label);
LIBFAUST_API Tree CsigVSlider(const char* label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree CsigHSlider(const char* label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree CsigNumEntry(const char* label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree CsigVBargraph(const char* label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree CsigHBargraph(const char* label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree CsigAttach(Tree x, Tree y);
LIBFAUST_API bool CisSigInt(Tree t, int* i);
LIBFAUST_API bool CisSigReal(Tree t, double* r);
LIBFAUST_API bool CisSigInput(Tree t, int* i);
LIBFAUST_API bool CisSigOutput(Tree t, int* i, Tree* t0_aux);
LIBFAUST_API bool CisSigDelay1(Tree t, Tree* t0_aux);
LIBFAUST_API bool CisSigDelay(Tree t, Tree* t0_aux, Tree* t1_aux);
LIBFAUST_API bool CisSigPrefix(Tree t, Tree* t0_aux, Tree* t1_aux);
LIBFAUST_API bool CisSigRDTbl(Tree s, Tree* t_aux, Tree* i_aux);
LIBFAUST_API bool CisSigWRTbl(Tree u, Tree* id_aux, Tree* t_aux, Tree* i_aux, Tree* s_aux);
LIBFAUST_API bool CisSigTable(Tree t, Tree* id_aux, Tree* n_aux, Tree* sig_aux);
LIBFAUST_API bool CisSigGen(Tree t, Tree* x_aux);
LIBFAUST_API bool CisSigDocConstantTbl(Tree t, Tree* n_aux, Tree* sig_aux);
LIBFAUST_API bool CisSigDocWriteTbl(Tree t, Tree* n_aux, Tree* sig_aux, Tree* widx_aux, Tree* wsig_aux);
LIBFAUST_API bool CisSigDocAccessTbl(Tree t, Tree* tbl_aux, Tree* ridx_aux);
LIBFAUST_API bool CisSigSelect2(Tree t, Tree* selector_aux, Tree* s1_aux, Tree* s2_aux);
LIBFAUST_API bool CisSigAssertBounds(Tree t, Tree* s1_aux, Tree* s2_aux, Tree* s3_aux);
LIBFAUST_API bool CisSigHighest(Tree t, Tree* s_aux);
LIBFAUST_API bool CisSigLowest(Tree t, Tree* s_aux);
LIBFAUST_API bool CisSigBinOp(Tree s, int* op, Tree* x_aux, Tree* y_aux);
LIBFAUST_API bool CisSigFFun(Tree s, Tree* ff_aux, Tree* largs_aux);
LIBFAUST_API bool CisSigFConst(Tree s, Tree* type_aux, Tree* name_aux, Tree* file_aux);
LIBFAUST_API bool CisSigFVar(Tree s, Tree* type_aux, Tree* name_aux, Tree* file_aux);
LIBFAUST_API bool CisProj(Tree s, int* i, Tree* rgroup_aux);
LIBFAUST_API bool CisRec(Tree s, Tree* var_aux, Tree* body_aux);
LIBFAUST_API bool CisSigIntCast(Tree s, Tree* x_aux);
LIBFAUST_API bool CisSigFloatCast(Tree s, Tree* x_aux);
LIBFAUST_API bool CisSigButton(Tree s, Tree* lbl_aux);
LIBFAUST_API bool CisSigCheckbox(Tree s, Tree* lbl_aux);
LIBFAUST_API bool CisSigWaveform(Tree s);
LIBFAUST_API bool CisSigHSlider(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux);
LIBFAUST_API bool CisSigVSlider(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux);
LIBFAUST_API bool CisSigNumEntry(Tree s, Tree* lbl_aux, Tree* init_aux, Tree* min_aux, Tree* max_aux, Tree* step_aux);
LIBFAUST_API bool CisSigHBargraph(Tree s, Tree* lbl_aux, Tree* min_aux, Tree* max_aux, Tree* x_aux);
LIBFAUST_API bool CisSigVBargraph(Tree s, Tree* lbl_aux, Tree* min_aux, Tree* max_aux, Tree* x_aux);
LIBFAUST_API bool CisSigAttach(Tree s, Tree* s0_aux, Tree* s1_aux);
LIBFAUST_API bool CisSigEnable(Tree s, Tree* s0_aux, Tree* s1_aux);
LIBFAUST_API bool CisSigControl(Tree s, Tree* s0_aux, Tree* s1_aux);
LIBFAUST_API bool CisSigSoundfile(Tree s, Tree* label_aux);
LIBFAUST_API bool CisSigSoundfileLength(Tree s, Tree* sf_aux, Tree* part_aux);
LIBFAUST_API bool CisSigSoundfileRate(Tree s, Tree* sf_aux, Tree* part_aux);
LIBFAUST_API bool CisSigSoundfileBuffer(Tree s, Tree* sf_aux, Tree* chan_aux, Tree* part_aux, Tree* ridx_aux);
LIBFAUST_API Tree CsimplifyToNormalForm(Tree s);
LIBFAUST_API Tree* CsimplifyToNormalForm2(Tree* s);

#ifdef __cplusplus
}
#endif

#endif
