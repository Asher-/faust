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

#ifndef _KLASS_H
#define _KLASS_H

/**********************************************************************
        - klass.h : class C++ to be filled (FAUST project) -

         History :
         -----------
         17-10-2001 : initial implementation  (yo)
         18-10-2001 : add getFreshID (yo)
         02-11-2001 : add sub-classes (yo)
         06-11-2001 : change classers impression (yo)

***********************************************************************/

#include <list>
#include <map>
#include <set>
#include <string>

#include "property.hh"
#include "sigtype.hh"
#include "tlib.hh"
#include "uitree.hh"
#include "graphSorting.hh"
#include "loop.hh"

using namespace std;

class Klass
{
   protected:
    // we make it global because several classes may need
    // power def but we want the code to be generated only once
    static bool fNeedPowerDef;

    Klass* fParentKlass;  ///< Klass in which this Klass is embedded, void if toplevel Klass
    string fKlassName;
    string fSuperKlassName;
    int    fNumInputs;
    int    fNumOutputs;
    int    fNumActives;   ///< number of active controls in the UI (sliders, buttons, etc.)
    int    fNumPassives;  ///< number of passive widgets in the UI (bargraphs, etc.)

    set<std::string> fIncludeFileSet;
    set<std::string> fLibrarySet;

    list<Klass*> fSubClassList;

    list<std::string> fDeclCode;
    list<std::string> fStaticInitCode;     ///< static init code for class constant tables
    list<std::string> fStaticDestroyCode;  ///< static destroy code for class constant tables
    list<std::string> fStaticFields;       ///< static fields after class
    list<std::string> fInitCode;
    list<std::string> fInitUICode;
    list<std::string> fClearCode;
    list<std::string> fUICode;
    list<std::string> fUIMacro;

#if 0
    list<std::string>        fSlowDecl;
    list<std::string>        fSharedDecl;            ///< declare shared variables for openMP
    list<std::string>        fCommonCode;            ///< code executed by all threads
    list<std::string>        fSlowCode;
    list<std::string>        fEndCode;
#endif
    list<std::string> fSharedDecl;        ///< shared declarations
    list<std::string> fFirstPrivateDecl;  ///< first private declarations

    list<std::string> fZone1Code;   ///< shared vectors
    list<std::string> fZone2Code;   ///< first private
    list<std::string> fZone2bCode;  ///< single once per block
    list<std::string> fZone2cCode;  ///< single once per block
    list<std::string> fZone3Code;   ///< private every sub block
    list<std::string> fZone4Code;   ///< code after all loops

    Loop*           fTopLoop;       ///< active loops currently open
    property<Loop*> fLoopProperty;  ///< loops used to compute some signals

    bool fVec;

   public:
    Klass(const std::string& name, const std::string& super, int numInputs, int numOutputs, bool __vec = false)
        : fParentKlass(0),
          fKlassName(name),
          fSuperKlassName(super),
          fNumInputs(numInputs),
          fNumOutputs(numOutputs),
          fNumActives(0),
          fNumPassives(0),
          fTopLoop(new Loop(0, "count")),
          fVec(__vec)
    {
    }

    virtual ~Klass() {}

    void setParentKlass(Klass* parent)
    {
        // std::cerr << this << " setParentKlass(" << parent << ")" << std::endl;
        fParentKlass = parent;
    }
    Klass* getParentKlass() { return fParentKlass; }
    Klass* getTopParentKlass() { return (fParentKlass != 0) ? fParentKlass->getTopParentKlass() : this; }
    string getFullClassName()
    {
        return (fParentKlass != 0) ? fParentKlass->getFullClassName() + "::" + getClassName() : getClassName();
    }  ///< Returns the name of the class

    void openLoop(const std::string& size);
    void openLoop(Tree recsymbol, const std::string& size);
    void closeLoop(Tree sig);

    void setLoopProperty(Tree sig, Loop* l);   ///< Store the loop used to compute a signal
    bool getLoopProperty(Tree sig, Loop*& l);  ///< Returns the loop used to compute a signal
    void listAllLoopProperties(Tree sig, set<Loop*>&, set<Tree>& visited);  ///< Returns all the loop used to compute a signal

    const std::string& getClassName() const { return fKlassName; }  ///< Returns the name of the class

    Loop* topLoop() { return fTopLoop; }

    void buildTasksList();

    void addIncludeFile(const std::string& str) { fIncludeFileSet.insert(str); }

    void addLibrary(const std::string& str) { fLibrarySet.insert(str); }

    void rememberNeedPowerDef() { fNeedPowerDef = true; }

    void collectIncludeFile(set<std::string>& S);

    void collectLibrary(set<std::string>& S);

    void addSubKlass(Klass* son) { fSubClassList.push_back(son); }

    void addDeclCode(const std::string& str) { fDeclCode.push_back(str); }

    void addInitCode(const std::string& str) { fInitCode.push_back(str); }
    void addInitUICode(const std::string& str) { fInitUICode.push_back(str); }
    void addClearCode(const std::string& str) { fClearCode.push_back(str); }

    void addStaticInitCode(const std::string& str) { fStaticInitCode.push_back(str); }
    void addStaticDestroyCode(const std::string& str) { fStaticDestroyCode.push_back(str); }

    void addStaticFields(const std::string& str) { fStaticFields.push_back(str); }

    void addUICode(const std::string& str) { fUICode.push_back(str); }

    void addUIMacro(const std::string& str) { fUIMacro.push_back(str); }

    void incUIActiveCount() { fNumActives++; }
    void incUIPassiveCount() { fNumPassives++; }

    void addSharedDecl(const std::string& str) { fSharedDecl.push_back(str); }
    void addFirstPrivateDecl(const std::string& str) { fFirstPrivateDecl.push_back(str); }

    void addZone1(const std::string& str) { fZone1Code.push_back(str); }
    void addZone2(const std::string& str) { fZone2Code.push_back(str); }
    void addZone2b(const std::string& str) { fZone2bCode.push_back(str); }
    void addZone2c(const std::string& str) { fZone2cCode.push_back(str); }
    void addZone3(const std::string& str) { fZone3Code.push_back(str); }
    void addZone4(const std::string& str) { fZone4Code.push_back(str); }

    void addPreCode(const Statement& stmt) { fTopLoop->addPreCode(stmt); }
    void addExecCode(const Statement& stmt) { fTopLoop->addExecCode(stmt); }
    void addPostCode(const Statement& stmt) { fTopLoop->addPostCode(stmt); }

    virtual void println(int n, ostream& fout);

    virtual void printComputeMethod(int n, ostream& fout);
    virtual void printComputeMethodScalar(int n, ostream& fout);
    virtual void printComputeMethodVectorFaster(int n, ostream& fout);
    virtual void printComputeMethodVectorSimple(int n, ostream& fout);
    virtual void printComputeMethodOpenMP(int n, ostream& fout);
    virtual void printComputeMethodScheduler(int n, ostream& fout);

    virtual void printLoopGraphScalar(int n, ostream& fout);
    virtual void printLoopGraphVector(int n, ostream& fout);
    virtual void printLoopGraphOpenMP(int n, ostream& fout);
    virtual void printLoopGraphScheduler(int n, ostream& fout);
    virtual void printLoopGraphInternal(int n, ostream& fout);
    virtual void printGraphDotFormat(ostream& fout);

    // experimental
    virtual void printLoopDeepFirst(int n, ostream& fout, Loop* l, set<Loop*>& visited);

    virtual void printLastLoopLevelScheduler(int n, int lnum, const lset& L, ostream& fout);
    virtual void printLoopLevelScheduler(int n, int lnum, const lset& L, ostream& fout);
    virtual void printOneLoopScheduler(lset::const_iterator p, int n, ostream& fout);
    virtual void printLoopLevelOpenMP(int n, int lnum, const lset& L, ostream& fout);

    virtual void printMetadata(int n, const MetaDataSet& S, ostream& fout);

    virtual void printIncludeFile(ostream& fout);

    virtual void printLibrary(ostream& fout);
    virtual void printAdditionalCode(ostream& fout);

    int inputs() { return fNumInputs; }
    int outputs() { return fNumOutputs; }
};

class SigIntGenKlass : public Klass {
   public:
    SigIntGenKlass(Klass* parent, const std::string& name) : Klass(name, "", 0, 1, false) { fParentKlass = parent; }

    virtual void println(int n, ostream& fout);
};

class SigFloatGenKlass : public Klass {
   public:
    SigFloatGenKlass(Klass* parent, const std::string& name) : Klass(name, "", 0, 1, false) { fParentKlass = parent; }

    virtual void println(int n, ostream& fout);
};

#endif