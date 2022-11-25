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

#ifndef __FAUST__COMPILER__PARSER__ABSTRACT__VISITOR__HH__
#define __FAUST__COMPILER__PARSER__ABSTRACT__VISITOR__HH__

#include "tlib/tree.hh"
#include "tlib/list.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {
      namespace Abstract {

        struct Visitor
        {
          /********** Types **********/

          /********** Accessors **********/
          
          // documentator/tree.hh
          virtual Tree docTxt(const char*) = 0;
          virtual Tree docEqn(Tree x) = 0;
          virtual Tree docDgm(Tree x) = 0;
          virtual Tree docNtc() = 0;
          virtual Tree docLst() = 0;
          virtual Tree docMtd(Tree x) = 0;
  
          // compiler/file_handling/sourcereader.hh
          virtual void declareDoc(Tree t) = 0; 
          
          // compiler/block_diagram/boxes.hh
          virtual Tree boxComponent(Tree filename) = 0;
          virtual LIBFAUST_API Tree boxSeq(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree boxPar(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree boxRec(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree boxSplit(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree boxMerge(Tree x, Tree y) = 0;
          virtual Tree boxEnvironment() = 0;
          virtual Tree boxWithLocalDef(Tree body, Tree ldef) = 0;
          virtual Tree boxAccess(Tree exp, Tree id) = 0;
          virtual Tree boxIdent(const char* name) = 0;
          virtual Tree boxLibrary(Tree filename) = 0;
          virtual LIBFAUST_API Tree boxInt(int n) = 0;
          virtual LIBFAUST_API Tree boxReal(double n) = 0;
          virtual LIBFAUST_API Tree boxWire() = 0;
          virtual LIBFAUST_API Tree boxCut() = 0;
          virtual Tree boxIPar(Tree x, Tree y, Tree z) = 0;
          virtual Tree boxISeq(Tree x, Tree y, Tree z) = 0;
          virtual Tree boxISum(Tree x, Tree y, Tree z) = 0;
          virtual Tree boxIProd(Tree x, Tree y, Tree z) = 0;
          virtual LIBFAUST_API Tree boxRoute(Tree n, Tree m, Tree r) = 0;
          virtual LIBFAUST_API Tree boxButton(Tree label) = 0;
          virtual LIBFAUST_API Tree boxCheckbox(Tree label) = 0;
          virtual LIBFAUST_API Tree boxVSlider(Tree label, Tree cur, Tree min, Tree max, Tree step) = 0;
          virtual LIBFAUST_API Tree boxHSlider(Tree label, Tree cur, Tree min, Tree max, Tree step) = 0;
          virtual LIBFAUST_API Tree boxNumEntry(Tree label, Tree cur, Tree min, Tree max, Tree step) = 0;
          virtual Tree boxVGroup(Tree label, Tree x) = 0;
          virtual Tree boxHGroup(Tree label, Tree x) = 0;
          virtual Tree boxTGroup(Tree label, Tree x) = 0;
          virtual LIBFAUST_API Tree boxVBargraph(Tree label, Tree min, Tree max) = 0;
          virtual LIBFAUST_API Tree boxHBargraph(Tree label, Tree min, Tree max) = 0;
          virtual LIBFAUST_API Tree boxFFun(Tree ff) = 0;
          virtual LIBFAUST_API Tree boxFConst(Tree type, Tree name, Tree file) = 0;
          virtual LIBFAUST_API Tree boxFVar(Tree type, Tree name, Tree file) = 0;
          virtual Tree boxInputs(Tree x) = 0;
          virtual Tree boxOutputs(Tree x) = 0;
          virtual Tree boxCase(Tree rules) = 0;
          virtual LIBFAUST_API Tree boxSoundfile(Tree label, Tree chan) = 0;
          virtual LIBFAUST_API Tree boxWaveform(const tvec& br) = 0;

          typedef Tree (*prim0)();
          typedef Tree (*prim1)(Tree x);
          typedef Tree (*prim2)(Tree x, Tree y);
          typedef Tree (*prim3)(Tree x, Tree y, Tree z);
          typedef Tree (*prim4)(Tree w, Tree x, Tree y, Tree z);
          typedef Tree (*prim5)(Tree v, Tree w, Tree x, Tree y, Tree z);
          
          virtual LIBFAUST_API Tree boxPrim1(prim1 foo) = 0;
          virtual LIBFAUST_API Tree boxPrim2(prim2 foo) = 0;
          virtual LIBFAUST_API Tree boxPrim3(prim3 foo) = 0;
          virtual LIBFAUST_API Tree boxPrim4(prim4 foo) = 0;
          virtual LIBFAUST_API Tree boxPrim5(prim5 foo) = 0;

          virtual Tree buildBoxAppl(Tree fun, Tree revarglist) = 0;
          virtual Tree buildBoxAbstr(Tree largs, Tree body) = 0;

          virtual Tree importFile(Tree filename) = 0;

          
          // compiler/signals/tree.hh
          virtual LIBFAUST_API Tree sigAdd(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigSub(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigMul(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigDiv(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigRem(Tree x, Tree y) = 0;

          virtual LIBFAUST_API Tree sigAND(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigOR(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigXOR(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigLeftShift(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigLRightShift(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigARightShift(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigGT(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigLT(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigGE(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigLE(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigEQ(Tree x, Tree y) = 0;
          virtual LIBFAUST_API Tree sigNE(Tree x, Tree y) = 0;

          virtual LIBFAUST_API Tree sigDelay(Tree t0, Tree t1) = 0;
          virtual Tree sigDelay0(Tree t) = 0;
          virtual Tree sigDelay1(Tree t) = 0;

          virtual Tree sigAssertBounds(Tree s1, Tree s2, Tree s3) = 0;
          virtual Tree sigLowest(Tree s) = 0;
          virtual Tree sigHighest(Tree s) = 0;
          virtual LIBFAUST_API Tree sigAttach(Tree x, Tree y) = 0;
          virtual Tree sigEnable(Tree x, Tree y) = 0;
          virtual Tree sigControl(Tree x, Tree y) = 0;
          virtual Tree sigPrefix(Tree t0, Tree t1) = 0;
          virtual LIBFAUST_API Tree sigSelect2(Tree selector, Tree s1, Tree s2) = 0;
          virtual LIBFAUST_API Tree sigSelect3(Tree selector, Tree s1, Tree s2, Tree s3) = 0;

          virtual LIBFAUST_API Tree sigIntCast(Tree t) = 0;
          virtual LIBFAUST_API Tree sigFloatCast(Tree t) = 0;
          virtual LIBFAUST_API Tree sigReadOnlyTable(Tree n, Tree init, Tree ridx) = 0;
          virtual LIBFAUST_API Tree sigWriteReadTable(Tree n, Tree init, Tree widx, Tree wsig, Tree ridx) = 0;
                      
          // tlib/tree.hh
          virtual Tree tree(const Node& n) = 0;
          virtual Tree tree(const Node& n, const Tree& a) = 0;
          virtual Tree tree(const Node& n, const Tree& a, const Tree& b) = 0;
          virtual Tree tree(const Node& n, const Tree& a, const Tree& b, const Tree& c) = 0;
          virtual Tree tree(const Node& n, const Tree& a, const Tree& b, const Tree& c, const Tree& d) = 0;
          virtual Tree tree(const Node& n, const Tree& a, const Tree& b, const Tree& c, const Tree& d, const Tree& e) = 0;
          virtual Tree tree(const Node& n, const tvec& br) = 0;
                              
          virtual Tree ffunction( Tree signature, Tree incfile, Tree libfile ) = 0;

          // tlib/list.hh
          virtual Tree        cons(Tree a, Tree b) = 0;

        };

      }
    }
  }
}

#endif 
