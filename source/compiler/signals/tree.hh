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

#ifndef __FAUST__COMPILER__SIGNALS__TREE__HH__
#define __FAUST__COMPILER__SIGNALS__TREE__HH__

#include "tlib/tlib.hh"
#include "compiler/signals/binop.hh"
#include "faust/primitive/symbols.hh"
#include "faust/primitive/symbols/as_tree.hh"

LIBFAUST_API Tree sigBinOp(SOperator op, Tree x, Tree y);
LIBFAUST_API Tree sigBinOp(int op, Tree x, Tree y);

LIBFAUST_API Tree sigAdd(Tree x, Tree y);
LIBFAUST_API Tree sigSub(Tree x, Tree y);
LIBFAUST_API Tree sigMul(Tree x, Tree y);
LIBFAUST_API Tree sigDiv(Tree x, Tree y);
LIBFAUST_API Tree sigRem(Tree x, Tree y);

LIBFAUST_API Tree sigAND(Tree x, Tree y);
LIBFAUST_API Tree sigOR(Tree x, Tree y);
LIBFAUST_API Tree sigXOR(Tree x, Tree y);
LIBFAUST_API Tree sigLeftShift(Tree x, Tree y);
LIBFAUST_API Tree sigLRightShift(Tree x, Tree y);
LIBFAUST_API Tree sigARightShift(Tree x, Tree y);
LIBFAUST_API Tree sigGT(Tree x, Tree y);
LIBFAUST_API Tree sigLT(Tree x, Tree y);
LIBFAUST_API Tree sigGE(Tree x, Tree y);
LIBFAUST_API Tree sigLE(Tree x, Tree y);
LIBFAUST_API Tree sigEQ(Tree x, Tree y);
LIBFAUST_API Tree sigNE(Tree x, Tree y);

// Delay
LIBFAUST_API Tree sigDelay(Tree t0, Tree t1);
Tree sigDelay0(Tree t);
Tree sigDelay1(Tree t);

// Interval annotation
Tree sigAssertBounds(Tree s1, Tree s2, Tree s3);
Tree sigLowest(Tree s);
Tree sigHighest(Tree s);

LIBFAUST_API Tree sigAttach(Tree x, Tree y);
Tree sigEnable(Tree x, Tree y);

Tree sigControl(Tree x, Tree y);
Tree sigPrefix(Tree t0, Tree t1);

LIBFAUST_API Tree sigSelect2(Tree selector, Tree s1, Tree s2);
LIBFAUST_API Tree sigSelect3(Tree selector, Tree s1, Tree s2, Tree s3);

LIBFAUST_API Tree sigIntCast(Tree t);
LIBFAUST_API Tree sigFloatCast(Tree t);

LIBFAUST_API Tree sigWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx);
LIBFAUST_API Tree sigReadOnlyTable(Tree n, Tree init, Tree ridx);

LIBFAUST_API Tree sigInt(int n);
LIBFAUST_API Tree sigReal(double n);

LIBFAUST_API Tree sigWaveform(const tvec& wf);

// Inputs and outputs
LIBFAUST_API Tree sigInput(int i);
Tree sigOutput(int i, Tree t);

// Tables
Tree sigRDTbl(Tree tb, Tree ri);
Tree sigWRTbl(Tree id, Tree tb, Tree wi, Tree ws);
Tree sigTable(Tree id, Tree n, Tree sig);
Tree sigGen(Tree content);

// Tables for documentator
// used to replace real tables for documentation purposes only
Tree sigDocConstantTbl(Tree n, Tree init);
Tree sigDocWriteTbl(Tree n, Tree init, Tree widx, Tree wsig);
Tree sigDocAccessTbl(Tree doctbl, Tree ridx);

Tree sigFFun(Tree ff, Tree largs);

LIBFAUST_API Tree sigFConst(Tree type, Tree name, Tree file);

LIBFAUST_API Tree sigFVar(Tree type, Tree name, Tree file);

// Emulation of all fonctions
typedef Tree (* sigFun)(Tree, Tree);



Tree sigProj(int i, Tree rgroup);

LIBFAUST_API Tree sigButton(Tree label);
LIBFAUST_API Tree sigCheckbox(Tree label);

LIBFAUST_API Tree sigVSlider(Tree label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree sigHSlider(Tree label, Tree init, Tree min, Tree max, Tree step);
LIBFAUST_API Tree sigNumEntry(Tree label, Tree init, Tree min, Tree max, Tree step);

LIBFAUST_API Tree sigVBargraph(Tree label, Tree min, Tree max, Tree t0);
LIBFAUST_API Tree sigHBargraph(Tree label, Tree min, Tree max, Tree t0);


/*****************************************************************************
                             Sounfiles (also UI elements)
*****************************************************************************/
/*
A boxSounfile(label,c) has 2 inputs and c+3 outputs:
    0   sigSoundfileLength(label, part):  the number of frames of the soundfile part (NK)
    1   sigSoundfileRate(label): the sampling rate encoded in the file (NK)
    2.. sigSoundfileBuffer(label, c, part, ridx): the cth channel content (RK or RS)
*/

LIBFAUST_API Tree sigSoundfile(Tree label);
LIBFAUST_API Tree sigSoundfileLength(Tree sf, Tree part);
LIBFAUST_API Tree sigSoundfileRate(Tree sf, Tree part);
LIBFAUST_API Tree sigSoundfileBuffer(Tree sf, Tree chan, Tree part, Tree ridx);

/*****************************************************************************
                             matrix extension
*****************************************************************************/

Tree sigTuple(int mode, Tree ls);
Tree sigTupleAccess(Tree ts, Tree idx);
Tree sigCartesianProd(Tree s1, Tree s2);

/*****************************************************************************
                             FTZ wrapping
    Add FTZ wrapping to a signal
*****************************************************************************/

Tree sigFTZ(Tree s);

Tree ffunction(Tree signature, Tree incfile, Tree libfile);

LIBFAUST_API bool isSigInt(Tree t, int* i);
LIBFAUST_API bool isSigReal(Tree t, double* r);

// Waveforms
LIBFAUST_API bool isSigWaveform(Tree s);


LIBFAUST_API bool isSigInput(Tree t, int* i);
LIBFAUST_API bool isSigOutput(Tree t, int* i, Tree& t0);

// Delay
LIBFAUST_API bool isSigDelay1(Tree t, Tree& t0);

LIBFAUST_API bool isSigDelay(Tree t, Tree& t0, Tree& t1);

LIBFAUST_API bool isSigPrefix(Tree t, Tree& t0, Tree& t1);

// Arithmetical operations
LIBFAUST_API bool isSigBinOp(Tree s, int* op, Tree& x, Tree& y);

LIBFAUST_API bool isSigRDTbl(Tree s, Tree& tb, Tree& ri);
LIBFAUST_API bool isSigWRTbl(Tree u, Tree& id, Tree& tb, Tree& wi, Tree& ws);
LIBFAUST_API bool isSigTable(Tree t, Tree& id, Tree& n, Tree& sig);

LIBFAUST_API bool isSigAttach(Tree s, Tree& x, Tree& y);

LIBFAUST_API bool isSigEnable(Tree s, Tree& x, Tree& y);

LIBFAUST_API bool isSigControl(Tree s, Tree& x, Tree& y);

/*****************************************************************************
                             User Interface Elements
*****************************************************************************/

bool isSigButton(Tree s);
LIBFAUST_API bool isSigButton(Tree s, Tree& label);

bool isSigCheckbox(Tree s);
LIBFAUST_API bool isSigCheckbox(Tree s, Tree& label);

bool isSigVSlider(Tree s);
LIBFAUST_API bool isSigVSlider(Tree s, Tree& label, Tree& init, Tree& min, Tree& max, Tree& step);

bool isSigHSlider(Tree s);
LIBFAUST_API bool isSigHSlider(Tree s, Tree& label, Tree& init, Tree& min, Tree& max, Tree& step);

bool isSigNumEntry(Tree s);
LIBFAUST_API bool isSigNumEntry(Tree s, Tree& label, Tree& init, Tree& min, Tree& max, Tree& step);

// Output elements
bool isSigVBargraph(Tree s);
LIBFAUST_API bool isSigVBargraph(Tree s, Tree& label, Tree& min, Tree& max, Tree& t0);

bool isSigHBargraph(Tree s);
LIBFAUST_API bool isSigHBargraph(Tree s, Tree& label, Tree& min, Tree& max, Tree& t0);

/*****************************************************************************
                             Sounfiles (also UI elements)
*****************************************************************************/
/*
A boxSounfile(label,c) has 2 inputs and c+3 outputs:
    0   sigSoundfileLength(label, part):  the number of frames of the soundfile part (NK)
    1   sigSoundfileRate(label): the sampling rate encoded in the file (NK)
    2.. sigSoundfileBuffer(label, c, part, ridx): the cth channel content (RK or RS)
*/

LIBFAUST_API bool isSigSoundfile(Tree s, Tree& label);
LIBFAUST_API bool isSigSoundfileLength(Tree s, Tree& sf, Tree& part);
LIBFAUST_API bool isSigSoundfileRate(Tree s, Tree& sf, Tree& part);
LIBFAUST_API bool isSigSoundfileBuffer(Tree s, Tree& sf, Tree& chan, Tree& part, Tree& ridx);

// Foreign functions
LIBFAUST_API bool isSigFFun(Tree s, Tree& ff, Tree& largs);

// Foreign constants
bool isSigFConst(Tree s);
LIBFAUST_API bool isSigFConst(Tree s, Tree& type, Tree& name, Tree& file);

// Foreign variables
bool isSigFVar(Tree s);
LIBFAUST_API bool isSigFVar(Tree s, Tree& type, Tree& name, Tree& file);


bool isSigIntCast(Tree t);
bool isSigFloatCast(Tree t);

LIBFAUST_API bool isSigIntCast(Tree t, Tree& x);
LIBFAUST_API bool isSigFloatCast(Tree t, Tree& x);

LIBFAUST_API bool isSigSelect2(Tree t, Tree& selector, Tree& s1, Tree& s2);

LIBFAUST_API bool isSigDocConstantTbl(Tree s, Tree& n, Tree& init);
LIBFAUST_API bool isSigDocWriteTbl(Tree s, Tree& n, Tree& init, Tree& widx, Tree& wsig);
LIBFAUST_API bool isSigDocAccessTbl(Tree s, Tree& doctbl, Tree& ridx);

// Projection for recursive groups
LIBFAUST_API bool isProj(Tree t, int* i, Tree& rgroup);

LIBFAUST_API bool isSigGen(Tree t, Tree& content);
bool isSigGen(Tree t);


/**
 *  Return the name parameter of a foreign function.
 *
 * @param  t - the signal
 * @return the name
 */
LIBFAUST_API std::string ffname(Tree t);
Tree ffsignature(Tree t);

#endif



