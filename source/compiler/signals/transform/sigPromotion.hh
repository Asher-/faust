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

#ifndef __SIGPROMOTION__
#define __SIGPROMOTION__

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "sigIdentity.hh"
#include "signalVisitor.hh"
#include "compiler/signals/sigtyperules.hh"

/*
 Check a signal:
 - for correct extended typing
 - for correct SinBinOp args typing
 - for proper SigIntCast and SigFloatCast use
 
 To be used on a type annotated signal.
*/
 
class SignalTreeChecker final : public SignalVisitor {
    
    protected:
        void visit(Tree sig) override;

    public:
        SignalTreeChecker(Tree L)
        {
            // Check that the root tree is properly type annotated
            getCertifiedSigType(L);
            visitRoot(L);
        }
};


//-------------------------SignalPromotion------------------------------
// Adds explicit int or float cast when needed. This is needed prior
// to any optimisations to avoid to scramble int and float expressions.
// To be used on a type annotated signal.
//----------------------------------------------------------------------

class SignalPromotion final : public SignalIdentity {
    
    private:
        Tree transformation(Tree sig);
        
        // Cast a sig to t1 if t1 != t2
        Tree smartCast(Type t1, Type t2, Tree sig);
        Tree smartCast(int t1, int t2, Tree sig);
        // Cast a sig to t
        Tree cast(Type t, Tree sig);
        Tree cast(int t, Tree sig);
        // Adds an intCast only if needed
        Tree smartIntCast(Type t, Tree sig);
        // Adds a floatCast only if needed
        Tree smartFloatCast(Type t, Tree sig);
    
    public:
        SignalPromotion()
        {
            // Go inside tables
            fVisitGen = true;
        }

};

//-------------------------SignalBool2IntPromotion----------------------
// Cast bool binary operations (comparison operations) to int
//----------------------------------------------------------------------
class SignalBool2IntPromotion final : public SignalIdentity {
    
    private:
        Tree transformation(Tree sig);

    public:
        SignalBool2IntPromotion()
        {
            // Go inside tables
            fVisitGen = true;
        }

};

//-------------------------SignalTablePromotion-------------------------
// Generate safe access to rdtable/rwtable (wdx/rdx in [0..size-1])
//----------------------------------------------------------------------
class SignalTablePromotion final : public SignalIdentity {
    
    private:
        Tree transformation(Tree sig);
    
        // Safe version of rtable/rwtable access
        Tree safeSigRDTbl(Tree sig, Tree tb, Tree size, Tree idx);
        Tree safeSigWRTbl(Tree sig, Tree id, Tree tb, Tree size, Tree idx, Tree ws);
        Tree getSize(Tree sig);
    
    public:
        SignalTablePromotion()
        {
            // Go inside tables
            fVisitGen = true;
        }
    
};

//-------------------------SignalUIPromotion-------------------------
// Generate safe access to range UI items (sliders and nentry)
//----------------------------------------------------------------------
class SignalUIPromotion final : public SignalIdentity {
    
    private:
        Tree transformation(Tree sig);
            
    public:
        SignalUIPromotion()
        {
            // Go inside tables
            fVisitGen = true;
        }
    
};

// Public API
Tree sigPromote(Tree sig, bool trace = false);
Tree sigBool2IntPromote(Tree sig);
Tree signalTablePromote(Tree sig);
Tree signalUIPromote(Tree sig);

#endif
