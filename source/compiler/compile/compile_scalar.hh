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

#ifndef _COMPILE_SCAL_
#define _COMPILE_SCAL_

#define _DNF_ 1

#include <map>
#include <utility>

#include "compile.hh"
#include "dcond.hh"
#include "old_occurences.hh"
#include "tlib/property.hh"
#include "compiler/signals/sigtyperules.hh"

#include "faust/primitive/type/priority.hh"


////////////////////////////////////////////////////////////////////////
/**
 * Compile a list of FAUST signals into a scalar C++ class
 */
///////////////////////////////////////////////////////////////////////

class ScalarCompiler : public Compiler {
   protected:
    
    using Priority = ::Faust::Primitive::Type::Priority;

    property<std::string>                fCompileProperty;
    property<std::string>                fSoundfileVariableProperty;  // variable associated to a soundfile
    property<std::string>                fVectorProperty;
    property<pair<std::string, string> > fStaticInitProperty;    // property added to solve 20101208 kjetil bug
    property<pair<std::string, string> > fInstanceInitProperty;  // property added to solve 20101208 kjetil bug

    map<Tree, Tree> fConditionProperty;  // used with the new X,Y:enable --> sigControl(X*Y,Y>0) primitive

    static map<std::string, int> fIDCounters;
    Tree                    fSharingKey;
    old_OccMarkup*          fOccMarkup;
    int                     fMaxIota;

   public:
    ScalarCompiler(const std::string& name, const std::string& super, int numInputs, int numOutputs)
        : Compiler(name, super, numInputs, numOutputs, false), fOccMarkup(0), fMaxIota(-1)
    {
    }

    ScalarCompiler(Klass* k) : Compiler(k), fOccMarkup(0), fMaxIota(-1) {}

    virtual void compileMultiSignal(Tree lsig);
    virtual void compileSingleSignal(Tree lsig);

   protected:
    virtual std::string CS(Tree sig);
    virtual std::string generateCode(Tree sig);
    virtual std::string generateCacheCode(Tree sig, const std::string& exp);
    virtual std::string forceCacheCode(Tree sig, const std::string& exp);
    virtual std::string generateVariableStore(Tree sig, const std::string& exp);

    string getFreshID(const std::string& prefix);

    void compilePreparedSignalList(Tree lsig);
    Tree prepare(Tree L0);
    Tree prepare2(Tree L0);

    bool   getCompiledExpression(Tree sig, string& name);
    string setCompiledExpression(Tree sig, const std::string& name);

    void setVectorNameProperty(Tree sig, const std::string& vecname);
    bool getVectorNameProperty(Tree sig, string& vecname);

    int  getSharingCount(Tree t);
    void setSharingCount(Tree t, int count);
    void sharingAnalysis(Tree t);
    void sharingAnnotation(
      const Priority& priority,
      Tree sig
    );

    void   conditionAnnotation(Tree l);
    void   conditionAnnotation(Tree t, Tree nc);
    void   conditionStatistics(Tree l);
    string getConditionCode(Tree t);

    // code generation

    string         generateXtended(Tree sig);
    virtual std::string generateDelay(Tree sig, Tree arg, Tree size);
    string         generatePrefix(Tree sig, Tree x, Tree e);
    string         generateBinOp(Tree sig, int opcode, Tree arg1, Tree arg2);

    string         generateFFun(Tree sig, Tree ff, Tree largs);
    virtual std::string generateWaveform(Tree sig);

    string generateInput(Tree sig, const std::string& idx);
    string generateOutput(Tree sig, const std::string& idx, const std::string& arg1);

    string generateTable(Tree sig, Tree tsize, Tree content);
    string generateStaticTable(Tree sig, Tree tsize, Tree content);
    string generateWRTbl(Tree sig, Tree tbl, Tree idx, Tree data);
    string generateRDTbl(Tree sig, Tree tbl, Tree idx);
    string generateSigGen(Tree sig, Tree content);
    string generateStaticSigGen(Tree sig, Tree content);

    string generateSelect2(Tree sig, Tree sel, Tree s1, Tree s2);

    string generateRecProj(Tree sig, Tree exp, int i);
    void   generateRec(Tree sig, Tree var, Tree le);

    string generateIntCast(Tree sig, Tree x);
    string generateFloatCast(Tree sig, Tree x);

    string generateButton(Tree sig, Tree label);
    string generateCheckbox(Tree sig, Tree label);
    string generateVSlider(Tree sig, Tree label, Tree cur, Tree min, Tree max, Tree step);
    string generateHSlider(Tree sig, Tree label, Tree cur, Tree min, Tree max, Tree step);
    string generateNumEntry(Tree sig, Tree label, Tree cur, Tree min, Tree max, Tree step);

    string generateVBargraph(Tree sig, Tree label, Tree min, Tree max, const std::string& exp);
    string generateHBargraph(Tree sig, Tree label, Tree min, Tree max, const std::string& exp);
    string generateSoundfile(Tree sig, Tree path);

    string generateNumber(Tree sig, const std::string& exp);
    string generateFConst(Tree sig, const std::string& file, const std::string& name);
    string generateFVar(Tree sig, const std::string& file, const std::string& name);

    virtual std::string generateDelayVec(Tree sig, const std::string& exp, const std::string& ctype, const std::string& vname, int mxd);
    string       generateDelayVecNoTemp(Tree sig, const std::string& exp, const std::string& ctype, const std::string& vname, int mxd);
    virtual void generateDelayLine(const std::string& ctype, const std::string& vname, int mxd, const std::string& exp,
                                   const std::string& ccs);

    void getTypedNames(::Type t, const std::string& prefix, string& ctype, string& vname);
    void ensureIotaCode();
    int  pow2limit(int x);

    void declareWaveform(Tree sig, string& vname, int& size);

    virtual std::string generateControl(Tree sig, Tree x, Tree y);

    string cnf2code(Tree cc);
    string or2code(Tree oc);

    string dnf2code(Tree cc);
    string and2code(Tree oc);
};

#endif