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

#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "compiler/errors/exception.hh"
#include "global.hh"
#include "compiler/signals/ppsig.hh"
#include "compiler/signals/prim2.hh"
#include "recursivness.hh"
#include "sigprint.hh"
#include "compiler/signals/sigtype.hh"
#include "compiler/signals/sigtyperules.hh"
#include "tlib/tlib.hh"
#include "faust/primitive/math/functions/xtended.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

#include "faust/primitive/type/cast.hh"

#include "faust/primitive/audio/simple_types.hh"

#include "faust/primitive/symbols/as_tree.hh"

using Availability = ::Faust::Primitive::Type::Availability;
using Precision = ::Faust::Primitive::Type::Precision;
using Priority = ::Faust::Primitive::Type::Priority;
using Value = ::Faust::Primitive::Type::Value;
using Vectorability = ::Faust::Primitive::Type::Vectorability;

//--------------------------------------------------------------------------
// prototypes
//--------------------------------------------------------------------------

static void        setSigType(Tree sig, Type t);
static Type        getSigType(Tree sig);
static TupletType* initialRecType(Tree t);
static TupletType* maximalRecType(Tree t);

static Type T(Tree term, Tree env);

static Type infereSigType(Tree term, Tree env);
static Type infereFFType(Tree ff, Tree ls, Tree env);
static Type infereFConstType(Tree type);
static Type infereFVarType(Tree type);
static Type infereRecType(Tree var, Tree body, Tree env);
static Type infereReadTableType(Type tbl, Type ri);
static Type infereWriteTableType(Type tbl, Type wi, Type wd);
static Type infereProjType(
  Type t,
  const int& i,
  const ::Faust::Primitive::Type::Vectorability& vec
);
static Type infereXType(Tree sig, Tree env);
static Type infereDocConstantTblType(Type size, Type init);
static Type infereDocWriteTblType(Type size, Type init, Type widx, Type wsig);
static Type infereDocAccessTblType(Type tbl, Type ridx);
static Type infereWaveformType(Tree lv, Tree env);

/**
 * convert a constant signal into a double using its bounds (not very safe)
 * @param sig the signal to be converted
 * @return the mean of its biggest and smallest value
 */
static double constSig2double(Tree sig)
{
    Type ty = getSigType(sig);
    if (ty->priority() != Priority::Konst) {
        throw faustexception(
            "ERROR : constSig2double, the parameter must be a constant value"
            " known at compile time\n");
    }
    interval bds = ty->interval();
    if (bds.lo != bds.hi) {
        throw faustexception(
            "ERROR : constSig2double, constant value with non-singleton interval, don't know what"
            " to do, please report");
    }
    return bds.lo;
}

/**
 * dereference a Type to AudioType and promote its type to TupletType
 * if the AudioType is not a TupletType, then fails
 * @param t the type to promote
 * @return the *t as a TupletType
 */
static ::TupletType derefRecCert(Type t)
{
    TupletType* p = isTupletType(t);
    faustassert(p);
    return *p;
}

/**
 * Compute the resulting interval of an arithmetic operation
 * @param op code of the operation
 * @param s1 interval of the left operand
 * @param s2 interval of the right operand
 * @return the resulting interval
 */
static interval arithmetic(int opcode, const interval& x, const interval& y)
{
    switch (opcode) {
        case kAdd:
            return x + y;
        case kSub:
            return x - y;
        case kMul:
            return x * y;
        case kDiv:
            return x / y;
        case kRem:
            return x % y;
        case kLsh:
            return x << y;
        case kARsh:
            return x >> y;
        case kGT:
            return x > y;
        case kLT:
            return x < y;
        case kGE:
            return x >= y;
        case kLE:
            return x <= y;
        case kEQ:
            return x == y;
        case kNE:
            return x != y;
        case kAND:
            return x & y;
        case kOR:
            return x | y;
        case kXOR:
            return x ^ y;
        default:
            cerr << "ERROR : unrecognized opcode : " << opcode << endl;
            faustassert(false);
            return {};
    }

    return interval();
}

// Uncomment to activate type inferrence tracing
//#define TRACE(x) x

#define TRACE(x) \
    {            \
        ;        \
    }

/**
 * The empty type environment (also property key for closed term type)
 */

/**
 * Do one step of type inference on the recursive signal groups of a signal
 * The types of the recursive signals are updated to vtype and then vtype is updated to the next step.
 *
 * @param vrec array of all the recursive signal groups
 * @param vdef definitions of all the recursive signal groups (vector of _lists_)
 * @param vdefSizes number of signals in each recursive signal groups
 * @param vtype types of the recursive signals
 * @param inter if set to false, the interval of the new type is the union of the old one and the computed one,
 * otherwise it is the intersection
 */
void updateRecTypes(vector<Tree>& vrec, const vector<Tree>& vdef, const vector<int>& vdefSizes, vector<Type>& vtype,
                    const bool inter)
{
    Type         newType;
    vector<Type> newTuplet;
    TupletType   newRecType;
    TupletType   oldRecType;
    interval     newI;
    interval     oldI;

    const int n = vdef.size();

    CTree::startNewVisit();

    // init recursive types
    for (int i = 0; i < n; i++) {
        setSigType(vrec[i], vtype[i]);
        // cerr << i << "-" << *getSigType(vrec[i]) << endl;
        vrec[i]->setVisited();
    }

    // cerr << "compute recursive types" << endl;
    for (int i = 0; i < n; i++) {
        newType = T(vdef[i], ::Faust::Primitive::Symbols::asTree().NULLTYPEENV);
        newTuplet.clear();
        oldRecType = derefRecCert(getSigType(vrec[i]));
        newRecType = derefRecCert(newType);

        for (int j = 0; j < vdefSizes[i]; j++) {
            newTuplet.push_back(newRecType[j]);
            newI = newRecType[j]->interval();
            oldI = oldRecType[j]->interval();

            newI         = inter ? intersection(newI, oldI) : reunion(newI, oldI);
            newTuplet[j] = newTuplet[j]->promoteInterval(newI);
        }
        vtype[i] = new TupletType(newTuplet);
    }
}

/**
 * Fully annotate every subtree of term with type information.
 * @param sig the signal term tree to annotate
 * @param causality when true check causality issues
 */
void typeAnnotation(Tree sig, bool causality)
{
    global::config().gCausality = causality;
    Tree sl             = symlist(sig);
    int  n              = len(sl);

    int  size;
    bool finished = false;

    vector<Tree>       vrec;       ///< array of all the recursive signal groups
    vector<Tree>       vdef;       ///< definitions of all the recursive signal groups (vector of _lists_)
    vector<int>        vdefSizes;  ///< number of signals for each group
    vector<Type>       vtype;      ///< type of the recursive signals
    vector<Type>       vtypeUp;    ///< an upperbound of the recursive signals type
    vector<TupletType> vUp;        ///< the unfolded version of the variable above

    vector<vector<int>> vAgeMin;  ///< age of the minimum of every subsignal of the recursive signal
    vector<vector<int>> vAgeMax;  ///< age of the maximum of every subsignal of the recursive signal

    // work variables used in widening loop

    Type         newType;
    vector<Type> newTuplet;
    TupletType   newRecType;
    TupletType   oldRecType;
    interval     newI;
    interval     oldI;

    // cerr << "Symlist " << *sl << endl;
    for (Tree l = sl; isList(l); l = tl(l)) {
        Tree id, body;
        faustassert(isRec(hd(l), id, body));
        if (!isRec(hd(l), id, body)) {
            continue;
        }
        vrec.push_back(hd(l));
        vdef.push_back(body);

        size = len(body);
        vdefSizes.push_back(size);
        vAgeMin.push_back(vector<int>(size, 0));
        vAgeMax.push_back(vector<int>(size, 0));
    }

    // init recursive types
    for (int i = 0; i < n; i++) {
        vtypeUp.push_back(maximalRecType(vdef[i]));
        vtype.push_back(initialRecType(vdef[i]));
    }

    faustassert(int(vrec.size()) == n);
    faustassert(int(vdef.size()) == n);
    faustassert(int(vtype.size()) == n);
    faustassert((int)vAgeMin.size() == n);
    faustassert((int)vAgeMax.size() == n);

    // cerr << "compute upper bounds for recursive types" << endl;

    for (int k = 0; k < global::config().gNarrowingLimit; k++) {
        updateRecTypes(vrec, vdef, vdefSizes, vtypeUp, true);
    }

    for (const auto& ty : vtypeUp) {
        vUp.push_back(derefRecCert(ty));
    }

    // cerr << "find an upperbound of the least fixpoint" << endl;

    while (!finished) {
        updateRecTypes(vrec, vdef, vdefSizes, vtype, false);

        // check finished
        finished = true;
        for (int i = 0; i < n; i++) {
            newTuplet.clear();
            // cerr << i << "-" << *vrec[i] << ":" << *getSigType(vrec[i]) << " => " << *vtype[i] << endl;
            if (vtype[i] != getSigType(vrec[i])) {
                finished   = false;
                newRecType = derefRecCert(vtype[i]);
                oldRecType = derefRecCert(getSigType(vrec[i]));
                for (int j = 0; j < vdefSizes[i]; j++) {
                    newTuplet.push_back(newRecType[j]);
                    newI = newRecType[j]->interval();
                    oldI = oldRecType[j]->interval();

                    TRACE(cerr << global::config().TABBER << "inspecting " << newTuplet[j] << endl;)
                    if (newI.lo != oldI.lo) {
                        faustassert(newI.lo < oldI.lo);
                        vAgeMin[i][j]++;
                        if (vAgeMin[i][j] > global::config().gWideningLimit) {
                            TRACE(cerr << global::config().TABBER << "low widening of " << newTuplet[j] << endl;)
                            newI.lo = vUp[i][j]->interval().lo;
                        }
                    }

                    if (newI.hi != oldI.hi) {
                        faustassert(newI.hi > oldI.hi);
                        vAgeMax[i][j]++;
                        if (vAgeMax[i][j] > global::config().gWideningLimit) {
                            TRACE(cerr << global::config().TABBER << "up widening of " << newTuplet[j] << endl;)
                            newI.hi = vUp[i][j]->interval().hi;
                        }
                    }

                    newTuplet[j] = newTuplet[j]->promoteInterval(newI);
                    TRACE(cerr << global::config().TABBER << "widening ended : " << newTuplet[j] << endl;)
                }
                vtype[i] = new TupletType(newTuplet);
            }
        }
    }
    // type full term
    T(sig, ::Faust::Primitive::Symbols::asTree().NULLTYPEENV);
    TRACE(cerr << "type success : " << endl << "BYE" << endl;)
}

/**
 * Print annotation statistics.
 */
static void annotationStatistics()
{
    cerr << global::config().TABBER << "COUNT INFERENCE  " << global::config().gCountInferences << " AT TIME "
         << clock() / CLOCKS_PER_SEC << 's' << endl;
    cerr << global::config().TABBER << "COUNT ALLOCATION " << global::config().gAllocationCount << endl;
    cerr << global::config().TABBER << "COUNT MAXIMAL " << global::config().gCountMaximal << endl;
}

/**
 * Retrieve the type of sig and check it exists. Produces an
 * error if the signal has no type associated
 * @param sig the signal we want to know the type
 * @return the type of the signal
 */
::Type getCertifiedSigType(Tree sig)
{
    Type ty = getSigType(sig);
    faustassert(ty);
    return ty;
}

/***********************************************
 * Set and get the type property of a signal
 * (we suppose the signal have been previously
 * annotated with type information)
 ***********************************************/

/**
 * Set the type annotation of sig
 * @param sig the signal we want to type
 * @param t the type of the signal
 */
static void setSigType(Tree sig, Type t)
{
    TRACE(cerr << global::config().TABBER << "SET FIX TYPE OF " << ppsig(sig) << " TO TYPE " << *t << endl;)
    sig->setType(t);
}

/**
 * Retrieve the type annotation of sig
 * @param sig the signal we want to know the type
 */
static Type getSigType(Tree sig)
{
    AudioType* ty = (AudioType*)sig->getType();
    if (ty == nullptr) {
        TRACE(cerr << global::config().TABBER << "GET FIX TYPE OF " << ppsig(sig) << " HAS NO TYPE YET" << endl;)
    } else {
        TRACE(cerr << global::config().TABBER << "GET FIX TYPE OF " << ppsig(sig) << " IS TYPE " << *ty << endl;)
    }
    return ty;
}

/**************************************************************************

                        Type Inference System

***************************************************************************/

/**************************************************************************

                        Infered Type property

***************************************************************************/

/**
 * Shortcut to getOrInferType, retrieve or infere the type of a term according to its surrounding type environment
 * @param sig the signal to analyze
 * @param env the type environment
 * @return the type of sig according to environment env
 * @see getCertifiedSigType
 */
static Type T(Tree term, Tree ignoreenv)
{
    TRACE(cerr << ++global::config().TABBER << "ENTER T() " << ppsig(term) << endl;)

    if (term->isAlreadyVisited()) {
        Type ty = getSigType(term);
        TRACE(cerr << --global::config().TABBER << "EXIT 1 T() " << ppsig(term) << " AS TYPE " << *ty << endl);
        return ty;

    } else {
        Type ty = infereSigType(term, ignoreenv);
        setSigType(term, ty);
        term->setVisited();
        TRACE(cerr << --global::config().TABBER << "EXIT 2 T() " << ppsig(term) << " AS TYPE " << *ty << endl);
        return ty;
    }
}

static void CheckPartInterval(Tree s, Type t)
{
    interval i = t->interval();
    if (!i.valid || (i.lo < 0) || (i.hi >= MAX_SOUNDFILE_PARTS)) {
        stringstream error;
        error << "ERROR : out of range soundfile part number (" << i << " instead of interval(0,"
              << MAX_SOUNDFILE_PARTS - 1 << ")) in expression : " << ppsig(s) << endl;
        throw faustexception(error.str());
    }
}

/**
 * Infere the type of a term according to its surrounding type environment
 * @param sig the signal to analyse
 * @param env the type environment
 * @return the type of sig according to environment env
 */
static Type infereSigType(Tree sig, Tree env)
{
    int    i;
    double r;
    Tree   sel, s1, s2, s3, ff, id, ls, l, x, y, z, part, u, var, body, type, name, file, sf;
    Tree   label, cur, min, max, step;

    global::config().gCountInferences++;

    if (getUserData(sig))
        return infereXType(sig, env);

    else if (isSigInt(sig, &i)) {
        Type t = makeSimpleType(Precision::Int, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval(i));
        /*sig->setType(t);*/ return t;
    }

    else if (isSigReal(sig, &r)) {
        Type t = makeSimpleType(Precision::Real, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval(r));
        /*sig->setType(t);*/ return t;
    }

    else if (isSigWaveform(sig)) {
        return infereWaveformType(sig, env);
    }

    else if (isSigInput(sig, &i)) { /*sig->setType(TINPUT);*/
        return ::Faust::Primitive::Audio::simpleTypes().TINPUT;
    }

    else if (isSigOutput(sig, &i, s1))
        return ::Faust::Primitive::Type::sampCast(T(s1, env));

    else if (isSigDelay1(sig, s1)) {
        Type t = T(s1, env);
        return ::Faust::Primitive::Type::castInterval(
          ::Faust::Primitive::Type::sampCast(t),
          reunion(t->interval(),
          interval(0, 0))
        );
    }

    else if (isSigPrefix(sig, s1, s2)) {
        Type t1 = T(s1, env);
        Type t2 = T(s2, env);
        checkInit(t1);
        return ::Faust::Primitive::Type::castInterval(
          ::Faust::Primitive::Type::sampCast(t1 | t2),
          reunion(t1->interval(), t2->interval())
        );
    }

    else if (isSigDelay(sig, s1, s2)) {
        Type     t1 = T(s1, env);
        Type     t2 = T(s2, env);
        interval i1 = t2->interval();

        //        cerr << "for sig fix delay : s1 = "
        //				<< t1 << ':' << ppsig(s1) << ", s2 = "
        //                << t2 << ':' << ppsig(s2) << endl;
        if (global::config().gCausality) {
            if (!(i1.valid) || !(i1.isbounded())) {
                stringstream error;
                error << "ERROR : can't compute the min and max values of : " << ppsig(s2) << endl
                      << "        used in delay expression : " << ppsig(sig) << endl
                      << "        (probably a recursive signal)" << endl;
                throw faustexception(error.str());
            } else if (i1.lo < 0) {
                stringstream error;
                error << "ERROR : possible negative values of : " << ppsig(s2) << endl
                      << "        used in delay expression : " << ppsig(sig) << endl
                      << "        " << i1 << endl;
                throw faustexception(error.str());
            }
        }

        return ::Faust::Primitive::Type::castInterval(
          ::Faust::Primitive::Type::sampCast(t1),
          reunion(t1->interval(),
          interval(0, 0))
        );
    }

    else if (isSigBinOp(sig, &i, s1, s2)) {
        // Type t = T(s1,env)|T(s2,env);
        Type t1 = T(s1, env);
        Type t2 = T(s2, env);
        Type t3 = ::Faust::Primitive::Type::castInterval(t1 | t2, arithmetic(i, t1->interval(), t2->interval()));
        // cerr <<"type rule for : " << ppsig(sig) << " -> " << *t3 << endl;

        if (i == kDiv) {
            return ::Faust::Primitive::Type::floatCast(t3);  // division always result in a float even with int arguments
        } else if ((i >= kGT) && (i <= kNE)) {
            return ::Faust::Primitive::Type::boolCast(t3);  // comparison always result in a boolean int
        } else if (((i >= kLsh) && (i <= kLRsh)) || ((i >= kAND) && (i <= kXOR))) {
            return ::Faust::Primitive::Type::intCast(t3);  // boolean and logical operators always result in an int
        } else {
            return t3;  //  otherwise most general of t1 and t2
        }
    }

    else if (isSigIntCast(sig, s1))
        return ::Faust::Primitive::Type::intCast(T(s1, env));

    else if (isSigFloatCast(sig, s1))
        return ::Faust::Primitive::Type::floatCast(T(s1, env));

    else if (isSigFFun(sig, ff, ls))
        return infereFFType(ff, ls, env);

    else if (isSigFConst(sig, type, name, file))
        return infereFConstType(type);

    else if (isSigFVar(sig, type, name, file))
        return infereFVarType(type);

    else if (isSigButton(sig)) { /*sig->setType(TGUI01);*/
        return ::Faust::Primitive::Audio::simpleTypes().TGUI01;
    }

    else if (isSigCheckbox(sig)) { /*sig->setType(TGUI01);*/
        return ::Faust::Primitive::Audio::simpleTypes().TGUI01;
    }

    else if (isSigVSlider(sig, label, cur, min, max, step)) {
        Type t1 = T(cur, env);
        Type t2 = T(min, env);
        Type t3 = T(max, env);
        Type t4 = T(step, env);
        return ::Faust::Primitive::Type::castInterval(::Faust::Primitive::Audio::simpleTypes().TGUI, interval(tree2float(min), tree2float(max)));
    }

    else if (isSigHSlider(sig, label, cur, min, max, step)) {
        Type t1 = T(cur, env);
        Type t2 = T(min, env);
        Type t3 = T(max, env);
        Type t4 = T(step, env);
        return ::Faust::Primitive::Type::castInterval(::Faust::Primitive::Audio::simpleTypes().TGUI, interval(tree2float(min), tree2float(max)));
    }

    else if (isSigNumEntry(sig, label, cur, min, max, step)) {
        Type t1 = T(cur, env);
        Type t2 = T(min, env);
        Type t3 = T(max, env);
        Type t4 = T(step, env);
        return ::Faust::Primitive::Type::castInterval(::Faust::Primitive::Audio::simpleTypes().TGUI, interval(tree2float(min), tree2float(max)));
    }

    else if (isSigHBargraph(sig, l, x, y, s1)) {
        Type t1 = T(x, env);
        Type t2 = T(y, env);
        return T(s1, env)->promotePriority(Priority::Block);
    }

    else if (isSigVBargraph(sig, l, x, y, s1)) {
        Type t1 = T(x, env);
        Type t2 = T(y, env);
        return T(s1, env)->promotePriority(Priority::Block);
    }

    else if (isSigSoundfile(sig, l)) {
        return makeSimpleType(Precision::Int, Priority::Block, Availability::Exec, Vectorability::Vect, Value::Num, interval(0, 0x7FFFFFFF));
    }

    else if (isSigSoundfileLength(sig, sf, part)) {
        Type t1 = T(sf, env);
        Type t2 = T(part, env);
        CheckPartInterval(sig, t2);
        Priority priority = Priority(std::max(static_cast<int>(Priority::Block), static_cast<int>(t2->priority())));
        return makeSimpleType(
          Precision::Int,
          priority,
          Availability::Exec,
          Vectorability::Vect,
          Value::Num,
          interval(0, 0x7FFFFFFF)
        );  // A REVOIR (YO)
    }

    else if (isSigSoundfileRate(sig, sf, part)) {
        Type t1 = T(sf, env);
        Type t2 = T(part, env);
        CheckPartInterval(sig, t2);
        Priority priority = Priority(std::max(static_cast<int>(Priority::Block), static_cast<int>(t2->priority())));
        return makeSimpleType(
          Precision::Int,
          priority,
          Availability::Exec,
          Vectorability::Vect,
          Value::Num,
          interval(0, 0x7FFFFFFF)
        );
    }

    else if (isSigSoundfileBuffer(sig, sf, x, part, z)) {
        T(sf, env);
        T(x, env);
        Type tp = T(part, env);
        T(z, env);

        CheckPartInterval(sig, tp);
        return makeSimpleType(Precision::Real, Priority::Samp, Availability::Exec, Vectorability::Vect, Value::Num, interval());
    }

    else if (isSigAttach(sig, s1, s2)) {
        T(s2, env);
        return T(s1, env);
    }

    else if (isSigEnable(sig, s1, s2)) {
        T(s2, env);
        return T(s1, env);
    }

    else if (isSigControl(sig, s1, s2)) {
        T(s2, env);
        return T(s1, env);
    }

    else if (isRec(sig, var, body))
        return infereRecType(sig, body, env);

    else if (isProj(sig, &i, s1))
        return infereProjType(
          T(s1, env),
          i,
          Vectorability::Scal
        );

    else if (isSigTable(sig, id, s1, s2)) {
        checkInt(checkInit(T(s1, env)));
        return makeTableType(checkInit(T(s2, env)));
    }

    else if (isSigWRTbl(sig, id, s1, s2, s3))
        return infereWriteTableType(T(s1, env), T(s2, env), T(s3, env));

    else if (isSigRDTbl(sig, s1, s2))
        return infereReadTableType(T(s1, env), T(s2, env));

    else if (isSigGen(sig, s1))
        return T(s1, ::Faust::Primitive::Symbols::asTree().NULLTYPEENV);

    else if (isSigDocConstantTbl(sig, x, y))
        return infereDocConstantTblType(T(x, env), T(y, env));
    else if (isSigDocWriteTbl(sig, x, y, z, u))
        return infereDocWriteTblType(T(x, env), T(y, env), T(z, env), T(u, env));
    else if (isSigDocAccessTbl(sig, x, y))
        return infereDocAccessTblType(T(x, env), T(y, env));

    else if (isSigSelect2(sig, sel, s1, s2)) {
        SimpleType *st1, *st2, *stsel;

        st1   = isSimpleType(T(s1, env));
        st2   = isSimpleType(T(s2, env));
        stsel = isSimpleType(T(sel, env));

        return makeSimpleType(
          Precision(static_cast<int>( st1->precision() )
         | static_cast<int>( st2->precision() )),
         Priority (static_cast<int>( st1->priority() )
         | static_cast<int>( st2->priority() )
         | static_cast<int>( stsel->priority() )),
          Availability(static_cast<int>( st1->availability() )
         | static_cast<int>( st2->availability() )
         | static_cast<int>( stsel->availability() )),
          Vectorability(static_cast<int>( st1->vectorability() )
         | static_cast<int>( st2->vectorability() )
         | static_cast<int>( stsel->vectorability() )),
          Value(static_cast<int>( st1->valueType() )
         | static_cast<int>( st2->valueType() )),
          reunion(st1->interval(), st2->interval())
        );
    }

    else if (isNil(sig)) {
        Type t = new TupletType(); /*sig->setType(t);*/
        return t;
    }

    else if (isList(sig)) {
        return T(hd(sig), env) * T(tl(sig), env);
    }

    else if (isSigAssertBounds(sig, min, max, cur)) {
        Type     t1 = T(min, env);
        Type     t2 = T(max, env);
        Type     t3 = T(cur, env);
        interval i3 = t3->interval();
        interval iEnd;
        constSig2double(min);
        if (i3.valid) {
            iEnd = interval(std::max(i3.lo, constSig2double(min)), std::min(i3.hi, constSig2double(max)));
        } else {
            iEnd = interval(constSig2double(min), constSig2double(max));
        }
        return t3->promoteInterval(iEnd);
    }

    else if (isSigLowest(sig, s1)) {
        interval i1 = T(s1, env)->interval();
        return makeSimpleType(Precision::Real, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval(i1.lo));
        // change this part   ^^^^^ once there are interval bounds depending on signal type
    }

    else if (isSigHighest(sig, s1)) {
        interval i1 = T(s1, env)->interval();
        return makeSimpleType(Precision::Real, Priority::Konst, Availability::Comp, Vectorability::Vect, Value::Num, interval(i1.hi));
        // change this part   ^^^^^ once there are interval bounds depending on signal type
    }

    // unrecognized signal here
    throw faustexception("ERROR : inferring signal type, unrecognized signal\n");
    return 0;
}

/**
 *	Infere the type of a projection (selection) of a tuplet element
 */
static Type infereProjType(
  Type t,
  const int& i,
  const ::Faust::Primitive::Type::Vectorability& vec
)
{
    TupletType* tt = isTupletType(t);
    if (tt == nullptr) {
        stringstream error;
        error << "ERROR : inferring projection type, not a tuplet type : " << t << endl;
        throw faustexception(error.str());
    }
    // return (*tt)[i]	->promotePriority(t->priority())
    //		->promoteAvailability(t->availability());
    Type temp = (*tt)[i]
                    ->promotePriority(t->priority())
                    ->promoteAvailability(t->availability())
                    ->promoteVectorability(vec /*t->vectorability()*/);
    //->promoteValueTypeity(t->valueType());

    if (vec == Vectorability::Vect) temp = ::Faust::Primitive::Type::vecCast(temp);
    // cerr << "infereProjType(" << t << ',' << i << ',' << vec << ")" << " -> " << temp << endl;

    return temp;
}

/**
 *	Infere the type of the result of writing into a table
 */
static Type infereWriteTableType(Type tbl, Type wi, Type ws)
{
    TableType* tt = isTableType(tbl);
    if (tt == nullptr) {
        stringstream error;
        error << "ERROR : inferring write table type, wrong table type : " << tbl << endl;
        throw faustexception(error.str());
    }
    SimpleType* st = isSimpleType(wi);
    if (st == nullptr) {
        stringstream error;
        error << "ERROR : inferring write table type, wrong write index type : " << wi << endl;
        throw faustexception(error.str());
    }
    TRACE(cerr << global::config().TABBER << "infering write table type : wi type = " << wi << endl);
    TRACE(cerr << global::config().TABBER << "infering write table type : wd type = " << ws << endl);

    const Precision& precision   = ws->precision();
    const Value&     value   = ws->valueType();
    const Priority   priority   = Priority(
      static_cast<int>( wi->priority() )
    | static_cast<int>( ws->priority()) );
    const Availability  availability  = Availability(
      static_cast<int>( wi->availability() )
    | static_cast<int>( ws->availability()) );
    const Vectorability vectorability = Vectorability(
      static_cast<int>( wi->vectorability() )
    | static_cast<int>( ws->vectorability()) );
    interval i   = ws->interval();
    // return dst << "NR"[precision()] << "KB?S"[priority()] << "CI?E"[availability()] << "VS?TS"[vectorability()]
    //            << "N?B"[valueType()] << " " << _interval;

    TRACE(cerr << global::config().TABBER << "infering write table type : n="
               << "NR"[static_cast<int>(precision)]
               << ", v=" << "KB?S"[static_cast<int>(value)]
               << ", c=" << "CI?E"[static_cast<int>(availability)]
               << ", vec=" << "VS?TS"[static_cast<int>(vectorability)]
               << ", b=" << "N?B"[static_cast<int>(value)]
               << ", i=" << i << endl);
    Type tbltype = makeTableType(
      tt->content(),
      precision,
      priority,
      availability,
      vectorability,
      value,
      i
    );
    TRACE(cerr << global::config().TABBER << "infering write table type : result=" << tbltype << endl);
    return tbltype;
}

/**
 *	Infere the type of the result of reading a table
 */
static Type infereReadTableType(Type tbl, Type ri)
{
    TableType* tt = isTableType(tbl);
    if (tt == nullptr) {
        stringstream error;
        error << "ERROR : inferring read table type, no table type : " << tbl << endl;
        throw faustexception(error.str());
    }
    SimpleType* st = isSimpleType(ri);
    if (st == nullptr) {
        stringstream error;
        error << "ERROR : inferring read table type, no read index type : " << ri << endl;
        throw faustexception(error.str());
    }
    // Type temp = makeSimpleType(tbl->precision(), ri->priority(), Availability::Init | ri->availability(), ri->vectorability(),
    //                            tbl->valueType(), tbl->interval());
    Type temp = makeSimpleType(
      tbl->precision(),
      Priority(
        static_cast<int>(tbl->priority())
      | static_cast<int>(ri->priority()) ),
      Availability(
        static_cast<int>(tbl->availability())
      | static_cast<int>(ri->availability()) ),
      Vectorability(
        static_cast<int>(tbl->vectorability())
      | static_cast<int>(ri->vectorability()) ),
      tbl->valueType(),
      tbl->interval());

    return temp;
}

static Type infereDocConstantTblType(Type size, Type init)
{
    checkKonst(checkInt(checkInit(size)));

    return init;
}

static Type infereDocWriteTblType(Type size, Type init, Type widx, Type wsig)
{
    checkKonst(checkInt(checkInit(size)));

    Type temp = init->promotePriority(Priority::Samp)  // difficult to tell, therefore Priority::Samp to be safe
                    ->promoteAvailability(
                      Availability(
                        static_cast<int>(widx->availability())
                      | static_cast<int>(wsig->availability()) )
                    )
                    ->promoteVectorability(Vectorability::Scal)       // difficult to tell, therefore Vectorability::Scal to be safe
                    ->promotePrecision(wsig->precision())     // nature of the initial and written signal
                    ->promoteValueType(wsig->valueType());  // booleanity of the initial and written signal
    return temp;
}

static Type infereDocAccessTblType(Type tbl, Type ridx)
{
    Type temp = tbl->promotePriority(ridx->priority())
                    ->promoteAvailability(ridx->availability())
                    ->promoteVectorability(ridx->vectorability());
    return temp;
}

/**
 * Compute an initial type solution for a recursive block
 * E1,E2,...En -> TREC,TREC,...TREC
 */
static TupletType* initialRecType(Tree t)
{
    faustassert(isList(t));
    return new TupletType(vector<Type>(len(t), ::Faust::Primitive::Audio::simpleTypes().TREC));
}

/**
 * Compute a maximal type solution for a recursive block
 * useful for widening approx
 * E1,E2,...En -> TRECMAX,TRECMAX,...TRECMAX
 */
static TupletType* maximalRecType(Tree t)
{
    faustassert(isList(t));
    return new TupletType(vector<Type>(
      len(t),
      ::Faust::Primitive::Audio::simpleTypes().TRECMAX)
    );
}

/**
 * Infere the type of a recursive block by trying solutions of
 * increasing generality
 */
static Type infereRecType(Tree sig, Tree body, Tree env)
{
    faustassert(false);  // we should not come here
    return 0;
}

/**
 *	Infere the type of a foreign function call
 */
static Type infereFFType(Tree ff, Tree ls, Tree env)
{
    // An external primitive can't be computed earlier than at initialization.
    // Its variability depends on the variability of its arguments unless it has no arguments,
    // in which case it is considered as rand(), i.e. the result varies at each call.

    if (ffarity(ff) == 0) {
        // case of functions like rand()
        return makeSimpleType(
          Precision(ffrestype(ff)),
          Priority::Samp,
          Availability::Init,
          Vectorability::Vect,
          Value::Num,
          interval()
        );
    } else {
        // otherwise variability and computability depends
        // arguments (OR of all arg types)
        Type t = makeSimpleType(
          Precision::Int,
          Priority::Konst,
          Availability::Init,
          Vectorability::Vect,
          Value::Num,
          interval()
        );
        while (isList(ls)) {
            t  = t | T(hd(ls), env);
            ls = tl(ls);
        }
        // but the result type is defined by the function
        return makeSimpleType(
          Precision(ffrestype(ff)),
          t->priority(),
          t->availability(),
          t->vectorability(),
          t->valueType(),
          interval()
        );
    }
}

/**
 *  Infere the type of a foreign constant
 */
static Type infereFConstType(Tree type)
{
    // An external constant cannot be calculated at the earliest possible time the initialization.
    // It is constant, in which case it is considered a rand() i.e. the result varies at each call.
    return makeSimpleType(
      Precision(tree2int(type)),
      Priority::Konst,
      Availability::Init,
      Vectorability::Vect,
      Value::Num,
      interval()
    );
}

/**
 *  Infere the type of a foreign variable
 */
static Type infereFVarType(Tree type)
{
    // An external variable cannot be calculated as soon as it is executed.
    // It varies by blocks like the user interface elements.
    return makeSimpleType(
      Precision(tree2int(type)),
      Priority::Block,
      Availability::Exec,
      Vectorability::Vect,
      Value::Num,
      interval()
    );
}

/**
 *  Infere the type of a waveform:
 *  - the nature is int if all values are int, otherwise it is float
 *  - the variability is by samples
 *  - the waveform is known at compile time
 *  - it can be vectorized because all values are known
 *  - knum ???
 *  - the interval is min and max of values
 */
static Type infereWaveformType(Tree wfsig, Tree env)
{
    bool   iflag = isInt(wfsig->branch(0)->node());
    int    n     = wfsig->arity();
    double lo, hi;

    lo = hi = tree2float(wfsig->branch(0));
    T(wfsig->branch(0), env);

    for (int i = 1; i < n; i++) {
        Tree v = wfsig->branch(i);
        T(v, env);
        // compute range
        double f = tree2float(v);
        if (f < lo) {
            lo = f;
        } else if (f > hi) {
            hi = f;
        }
        iflag &= isInt(v->node());
    }

    return makeSimpleType((iflag) ? Precision::Int : Precision::Real, Priority::Samp, Availability::Comp, Vectorability::Scal, Value::Num, interval(lo, hi));
}

/**
 *	Infere the type of an extended (primitive) block
 */
static Type infereXType(Tree sig, Tree env)
{
    // cerr << "infereXType :" << endl;
    // cerr << "infereXType of " << *sig << endl;
    auto     p = getUserData(sig);
    vector<Type> vt;

    for (int i = 0; i < sig->arity(); i++) vt.push_back(T(sig->branch(i), env));
    return p->infereSigType(vt);
}
