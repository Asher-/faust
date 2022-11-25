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

#include "compiler/signals/tree.hh"
#include "compiler/signals/ppsig.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/symbols.hh"

LIBFAUST_API Tree sigBinOp(SOperator op, Tree x, Tree y)
{
    return sigBinOp(int(op), x, y);
}

LIBFAUST_API Tree sigBinOp(int op, Tree x, Tree y)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigBinOp"), tree(op), x, y);
}

// Emulation of all fonctions
LIBFAUST_API Tree sigAdd(Tree x, Tree y)
{
    return sigBinOp(kAdd, x, y);
}
LIBFAUST_API Tree sigSub(Tree x, Tree y)
{
    return sigBinOp(kSub, x, y);
}
LIBFAUST_API Tree sigMul(Tree x, Tree y)
{
    return sigBinOp(kMul, x, y);
}
LIBFAUST_API Tree sigDiv(Tree x, Tree y)
{
    return sigBinOp(kDiv, x, y);
}

LIBFAUST_API Tree sigAND(Tree x, Tree y)
{
    return sigBinOp(kAND, x, y);
}
LIBFAUST_API Tree sigOR(Tree x, Tree y)
{
    return sigBinOp(kOR, x, y);
}
LIBFAUST_API Tree sigXOR(Tree x, Tree y)
{
    return sigBinOp(kXOR, x, y);
}

LIBFAUST_API Tree sigLeftShift(Tree x, Tree y)
{
    return sigBinOp(kLsh, x, y);
}
LIBFAUST_API Tree sigARightShift(Tree x, Tree y)
{
    return sigBinOp(kARsh, x, y);
}
LIBFAUST_API Tree sigLRightShift(Tree x, Tree y)
{
    return sigBinOp(kLRsh, x, y);
}

LIBFAUST_API Tree sigGT(Tree x, Tree y)
{
    return sigBinOp(kGT, x, y);
}
LIBFAUST_API Tree sigLT(Tree x, Tree y)
{
    return sigBinOp(kLT, x, y);
}
LIBFAUST_API Tree sigGE(Tree x, Tree y)
{
    return sigBinOp(kGE, x, y);
}
LIBFAUST_API Tree sigLE(Tree x, Tree y)
{
    return sigBinOp(kLE, x, y);
}
LIBFAUST_API Tree sigEQ(Tree x, Tree y)
{
    return sigBinOp(kEQ, x, y);
}
LIBFAUST_API Tree sigNE(Tree x, Tree y)
{
    return sigBinOp(kNE, x, y);
}

Tree sigDelay0(Tree t0)
{
    return sigDelay(t0, sigInt(0));
}

Tree sigDelay1(Tree t0)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigDelay1"), t0);
}
LIBFAUST_API bool isSigDelay1(Tree t, Tree& t0)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigDelay1"), t0);
}

LIBFAUST_API Tree sigDelay(Tree t0, Tree t1)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigDelay"), t0, t1);
}

Tree sigAssertBounds(Tree s1, Tree s2, Tree s3)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("sigAssertBounds"), s1, s2, s3);
}

Tree sigHighest(Tree s)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("sigHighest"), s);
}

Tree sigLowest(Tree s)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("sigLowest"), s);
}

Tree sigAttach(Tree t0, Tree t1)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigAttach"), t0, t1);
}

Tree sigEnable(Tree t0, Tree t1)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigEnable"), t0, t1);
}

Tree sigControl(Tree t0, Tree t1)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigControl"), t0, t1);
}

Tree sigPrefix(Tree t0, Tree t1)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigPrefix"), t0, t1);
}

LIBFAUST_API Tree sigSelect2(Tree selector, Tree s1, Tree s2)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigSelect2"), selector, s1, s2);
}
LIBFAUST_API Tree sigSelect3(Tree selector, Tree s1, Tree s2, Tree s3)
{
    return sigSelect2(sigBinOp(kEQ, selector, sigInt(0)), sigSelect2(sigBinOp(kEQ, selector, sigInt(1)), s3, s2), s1);
}

LIBFAUST_API Tree sigIntCast(Tree t)
{
    Node   n = t->node();
    int    i;
    double x;

    if (isInt(n, &i)) return t;
    if (isDouble(n, &x)) return tree(int(x));

    return tree(::Faust::Primitive::Symbols::internal().symbol("SigIntCast"), t);
}

LIBFAUST_API Tree sigFloatCast(Tree t)
{
    Node   n = t->node();
    int    i;
    double x;

    if (isInt(n, &i)) return tree(double(i));
    if (isDouble(n, &x)) return t;

    return tree(::Faust::Primitive::Symbols::internal().symbol("SigFloatCast"), t);
}

LIBFAUST_API Tree sigWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx)
{
    /*
     rwtable are parsed as boxPrim5, so do not have a special treatment in eval/propagate. So we do here:
     - the size argument is supposed to be known at compile time, so is casted at compilation time to int
     */
    return sigRDTbl(sigWRTbl(::Faust::Primitive::Symbols::asTree().nil, sigTable(::Faust::Primitive::Symbols::asTree().nil, sigInt(tree2int(n)), sigGen(init)), widx, wsig),
                    ridx);
}

LIBFAUST_API Tree sigReadOnlyTable(Tree n, Tree init, Tree ridx)
{
    /*
     rtable are parsed as boxPrim3, so do not have a special treatment in eval/propagate. So we do here:
     - the size argument is supposed to be known at compile time, so is casted at compilation time to int
     */
    return sigRDTbl(sigTable(::Faust::Primitive::Symbols::asTree().nil, sigInt(tree2int(n)), sigGen(init)), ridx);
}

LIBFAUST_API Tree sigRem(Tree x, Tree y)
{
    if (isZero(y)) {
        stringstream error;
        error << "ERROR : % by 0 in " << ppsig(x) << " % " << ppsig(y) << endl;
        throw faustexception(error.str());
    }
    return sigBinOp(kRem, x, y);
}

LIBFAUST_API Tree sigInt(int i)
{
    return tree(i);
}
LIBFAUST_API Tree sigReal(double r)
{
    return tree(r);
}

LIBFAUST_API Tree sigInput(int i)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigInput"), tree(i));
}

Tree sigRDTbl(Tree tb, Tree ri)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigRDTbl"), tb, ri);
}

Tree sigWRTbl(Tree id, Tree tb, Tree wi, Tree ws)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigWRTbl"), id, tb, wi, ws);
}

Tree sigTable(Tree id, Tree n, Tree sig)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigTable"), id, n, sig);
}

Tree sigGen(Tree s)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigGen"), s);
}

Tree sigOutput(int i, Tree t0)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigOutput"), tree(i), t0);
}Tree sigDocConstantTbl(Tree n, Tree sig)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigDocConstantTbl"), n, sig);
}
Tree sigDocWriteTbl(Tree n, Tree sig, Tree widx, Tree wsig)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigDocWriteTbl"), n, sig, widx, wsig);
}
Tree sigDocAccessTbl(Tree tbl, Tree ridx)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigDocAccessTbl"), tbl, ridx);
}

Tree sigFFun(Tree ff, Tree largs)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigFFun"), ff, largs);
}

LIBFAUST_API Tree sigFConst(Tree type, Tree name, Tree file)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigFConst"), type, name, file);
}

LIBFAUST_API Tree sigFVar(Tree type, Tree name, Tree file)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigFVar"), type, name, file);
}

Tree sigProj(int i, Tree rgroup)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigProj"), tree(i), rgroup);
}

LIBFAUST_API Tree sigButton(Tree lbl)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigButton"), lbl);
}

LIBFAUST_API Tree sigCheckbox(Tree lbl)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigCheckbox"), lbl);
}

LIBFAUST_API Tree sigWaveform(const tvec& wf)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigWaveform"), wf);
}

LIBFAUST_API Tree sigHSlider(Tree lbl, Tree init, Tree min, Tree max, Tree step)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigHSlider"), lbl, list4(init, min, max, step));
}

LIBFAUST_API Tree sigVSlider(Tree lbl, Tree init, Tree min, Tree max, Tree step)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigVSlider"), lbl, list4(init, min, max, step));
}

LIBFAUST_API Tree sigNumEntry(Tree lbl, Tree init, Tree min, Tree max, Tree step)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigNumEntry"), lbl, list4(init, min, max, step));
}

LIBFAUST_API Tree sigHBargraph(Tree lbl, Tree min, Tree max, Tree x)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigHBargraph"), lbl, min, max, x);
}

LIBFAUST_API Tree sigVBargraph(Tree lbl, Tree min, Tree max, Tree x)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigVBargraph"), lbl, min, max, x);
}


/*****************************************************************************
                             Soundfiles
*****************************************************************************/
/*
 A boxSoundfile(label,c) has 2 inputs and c+3 outputs:
 0   sigSoundfileLength(label, part):  the number of frames of the soundfile part (NK)
 1   sigSoundfileRate(label, part): the sampling rate encoded in the file (NK)
 2   sigSoundfileBuffer(label, c, part, ridx): the cth channel content (RK ou RS)
*/

LIBFAUST_API Tree sigSoundfile(Tree label)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigSoundfile"), label);
}

LIBFAUST_API Tree sigSoundfileLength(Tree sf, Tree part)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigSoundfileLength"), sf, part);
}
LIBFAUST_API Tree sigSoundfileRate(Tree sf, Tree part)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigSoundfileRate"), sf, part);
}
LIBFAUST_API Tree sigSoundfileBuffer(Tree sf, Tree chan, Tree part, Tree ridx)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigSoundfileBuffer"), sf, chan, part, ridx);
}

/*****************************************************************************
                             matrix extension
*****************************************************************************/

// a tuple of signals is basically a list of signals.
// mode = 0 means normal, mode = 1 means blocked
Tree sigTuple(int mode, Tree ls)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigTuple"), tree(mode), ls);
}

bool isSigTuple(Tree s, int* mode, Tree& ls)
{
    Tree m;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigTuple"), m, ls) && isInt(m->node(), mode);
}

// Access the components of a tuple.
// ts is tuple of signals, idx is a scalar signal between 0..n
Tree sigTupleAccess(Tree ts, Tree idx)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("SigTupleAccess"), ts, idx);
}

// create a tuple of signals
Tree sigCartesianProd(Tree s1, Tree s2)
{
    Tree l1, l2;
    int  m1, m2;

    if (isSigTuple(s1, &m1, l1) && (m1 == 0)) {
        // nothing to do
    } else {
        l1 = list1(s1);
    }

    if (isSigTuple(s2, &m2, l2) && (m2 == 0)) {
        // nothing to do
    } else {
        l2 = list1(s2);
    }

    return sigTuple(0, concat(l1, l2));
}

/*****************************************************************************
                             FTZ wrapping
    Add FTZ wrapping to a signal
*****************************************************************************/

// \(x).(select2(abs(x)<mmm, x, 0))

Tree sigFTZ(Tree s)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("ftz"), s);
}

Tree ffunction(Tree signature, Tree incfile, Tree libfile)
{
    return tree(::Faust::Primitive::Symbols::internal().symbol("ForeignFunction"), signature, incfile, libfile);
}

LIBFAUST_API bool isSigInt(Tree t, int* i)
{
    return isInt(t->node(), i);
}

LIBFAUST_API bool isSigReal(Tree t, double* r)
{
    return isDouble(t->node(), r);
}

LIBFAUST_API bool isSigInput(Tree t, int* i)
{
    Tree x;
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigInput"), x) && isInt(x->node(), i);
}


LIBFAUST_API bool isSigOutput(Tree t, int* i, Tree& t0)
{
    Tree x;
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigOutput"), x, t0) && isInt(x->node(), i);
}

LIBFAUST_API bool isSigDelay(Tree t, Tree& t0, Tree& t1)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigDelay"), t0, t1);
}

LIBFAUST_API bool isSigPrefix(Tree t, Tree& t0, Tree& t1)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigPrefix"), t0, t1);
}

LIBFAUST_API bool isSigBinOp(Tree s, int* op, Tree& x, Tree& y)
{
    Tree t;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigBinOp"), t, x, y) && isInt(t->node(), op);
}

// Read only and read write tables

LIBFAUST_API bool isSigRDTbl(Tree s, Tree& tb, Tree& ri)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigRDTbl"), tb, ri);
}

LIBFAUST_API bool isSigWRTbl(Tree u, Tree& id, Tree& tb, Tree& wi, Tree& ws)
{
    return isTree(u, ::Faust::Primitive::Symbols::internal().symbol("SigWRTbl"), id, tb, wi, ws);
}

LIBFAUST_API bool isSigTable(Tree t, Tree& id, Tree& n, Tree& sig)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigTable"), id, n, sig);
}

LIBFAUST_API bool isSigAttach(Tree t, Tree& t0, Tree& t1)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigAttach"), t0, t1);
}


LIBFAUST_API bool isSigEnable(Tree t, Tree& t0, Tree& t1)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigEnable"), t0, t1);
}

LIBFAUST_API bool isSigControl(Tree t, Tree& t0, Tree& t1)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigControl"), t0, t1);
}

bool isSigButton(Tree s)
{
    Tree lbl;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigButton"), lbl);
}
LIBFAUST_API bool isSigButton(Tree s, Tree& lbl)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigButton"), lbl);
}

bool isSigCheckbox(Tree s)
{
    Tree lbl;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigCheckbox"), lbl);
}
LIBFAUST_API bool isSigCheckbox(Tree s, Tree& lbl)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigCheckbox"), lbl);
}

LIBFAUST_API bool isSigWaveform(Tree s)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigWaveform"));
}

/*****************************************************************************
                             Soundfiles
*****************************************************************************/
/*
 A boxSoundfile(label,c) has 2 inputs and c+3 outputs:
 0   sigSoundfileLength(label, part):  the number of frames of the soundfile part (NK)
 1   sigSoundfileRate(label, part): the sampling rate encoded in the file (NK)
 2   sigSoundfileBuffer(label, c, part, ridx): the cth channel content (RK ou RS)
*/

LIBFAUST_API bool isSigSoundfile(Tree s, Tree& label)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigSoundfile"), label);
}
LIBFAUST_API bool isSigSoundfileLength(Tree s, Tree& sf, Tree& part)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigSoundfileLength"), sf, part);
}
LIBFAUST_API bool isSigSoundfileRate(Tree s, Tree& sf, Tree& part)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigSoundfileRate"), sf, part);
}
LIBFAUST_API bool isSigSoundfileBuffer(Tree s, Tree& sf, Tree& chan, Tree& part, Tree& ridx)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigSoundfileBuffer"), sf, chan, part, ridx);
}



// Foreign Functions


LIBFAUST_API bool isSigFFun(Tree s, Tree& ff, Tree& largs)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigFFun"), ff, largs);
}
bool isSigFConst(Tree s)
{
    Tree t, n, f;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigFConst"), t, n, f);
}
LIBFAUST_API bool isSigFConst(Tree s, Tree& type, Tree& name, Tree& file)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigFConst"), type, name, file);
}

bool isSigFVar(Tree s)
{
    Tree t, n, f;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigFVar"), t, n, f);
}
LIBFAUST_API bool isSigFVar(Tree s, Tree& type, Tree& name, Tree& file)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigFVar"), type, name, file);
}


/*****************************************************************************
                             User Interface Elements
*****************************************************************************/


bool isSigHSlider(Tree s)
{
    Tree lbl, params;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigHSlider"), lbl, params);
}

LIBFAUST_API bool isSigHSlider(Tree s, Tree& lbl, Tree& init, Tree& min, Tree& max, Tree& step)
{
    Tree params;
    if (isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigHSlider"), lbl, params)) {
        init = nth(params, 0);
        min  = nth(params, 1);
        max  = nth(params, 2);
        step = nth(params, 3);
        return true;
    } else {
        return false;
    }
}

bool isSigVSlider(Tree s)
{
    Tree lbl, params;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigVSlider"), lbl, params);
}

LIBFAUST_API bool isSigVSlider(Tree s, Tree& lbl, Tree& init, Tree& min, Tree& max, Tree& step)
{
    Tree params;
    if (isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigVSlider"), lbl, params)) {
        init = nth(params, 0);
        min  = nth(params, 1);
        max  = nth(params, 2);
        step = nth(params, 3);
        return true;
    } else {
        return false;
    }
}

bool isSigNumEntry(Tree s)
{
    Tree lbl, params;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigNumEntry"), lbl, params);
}

LIBFAUST_API bool isSigNumEntry(Tree s, Tree& lbl, Tree& init, Tree& min, Tree& max, Tree& step)
{
    Tree params;
    if (isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigNumEntry"), lbl, params)) {
        init = nth(params, 0);
        min  = nth(params, 1);
        max  = nth(params, 2);
        step = nth(params, 3);
        return true;
    } else {
        return false;
    }
}

// Output elements

bool isSigHBargraph(Tree s)
{
    Tree lbl, min, max, x;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigHBargraph"), lbl, min, max, x);
}
LIBFAUST_API bool isSigHBargraph(Tree s, Tree& lbl, Tree& min, Tree& max, Tree& x)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigHBargraph"), lbl, min, max, x);
}

bool isSigVBargraph(Tree s)
{
    Tree lbl, min, max, x;
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigVBargraph"), lbl, min, max, x);
}
LIBFAUST_API bool isSigVBargraph(Tree s, Tree& lbl, Tree& min, Tree& max, Tree& x)
{
    return isTree(s, ::Faust::Primitive::Symbols::internal().symbol("SigVBargraph"), lbl, min, max, x);
}

// Int and Float casting


bool isSigIntCast(Tree t)
{
    Tree x;
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigIntCast"), x);
}
LIBFAUST_API bool isSigIntCast(Tree t, Tree& x)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigIntCast"), x);
}

bool isSigFloatCast(Tree t)
{
    Tree x;
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigFloatCast"), x);
}
LIBFAUST_API bool isSigFloatCast(Tree t, Tree& x)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigFloatCast"), x);
}

// Select on signal among severals

LIBFAUST_API bool isSigSelect2(Tree t, Tree& selector, Tree& s1, Tree& s2)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigSelect2"), selector, s1, s2);
}


// Documentator Tables : special version of tables only for documentation purposes

LIBFAUST_API bool isSigDocConstantTbl(Tree t, Tree& n, Tree& sig)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigDocConstantTbl"), n, sig);
}

LIBFAUST_API bool isSigDocWriteTbl(Tree t, Tree& n, Tree& sig, Tree& widx, Tree& wsig)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigDocWriteTbl"), n, sig, widx, wsig);
}

LIBFAUST_API bool isSigDocAccessTbl(Tree t, Tree& tbl, Tree& ridx)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigDocAccessTbl"), tbl, ridx);
}


LIBFAUST_API bool isProj(Tree t, int* i, Tree& rgroup)
{
    Tree x;
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigProj"), x, rgroup) && isInt(x->node(), i);
}


// Signal used to generate the initial content of a table

LIBFAUST_API bool isSigGen(Tree t, Tree& x)
{
    return isTree(t, ::Faust::Primitive::Symbols::internal().symbol("SigGen"), x);
}
bool isSigGen(Tree t)
{
    return t->node() == Node(::Faust::Primitive::Symbols::internal().symbol("SigGen"));
}

Tree ffsignature(Tree ff)
{
    return ff->branch(0);
}


std::string ffname(Tree t)
{
    Tree namelist = nth(ffsignature(t), 1);
    return tree2str(nth(namelist, ::Faust::Primitive::Math::floatSize - 1));
}
