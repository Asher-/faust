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

#include "signalVisitor.hh"
#include "dsp_factory.hh"
#include "global.hh"
#include "faust.hh"
#include "libfaust.h"
#include "normalform.hh"

// ============
// Backend API
// ============

// Keep the maximum index of inputs signals
struct MaxInputsCounter : public SignalVisitor {
    int fMaxInputs = 0;

    MaxInputsCounter(Tree L)
    {
        // L is in normal form
        while (!isNil(L)) {
            self(hd(L));
            L = tl(L);
        }
    }

    void visit(Tree sig)
    {
        int input;
        if (isSigInput(sig, &input)) {
            fMaxInputs = std::max(fMaxInputs, input + 1);
        } else {
            SignalVisitor::visit(sig);
        }
    }
};

dsp_factory_base* createFactory(const char* name, const char* dsp_content, int argc, const char* argv[],
                                string& error_msg, bool generate)
{
    gGlobal                   = nullptr;
    dsp_factory_base* factory = nullptr;

    try {
        global::allocate();
        createFactoryAux(name, dsp_content, argc, argv, generate);
        error_msg = gGlobal->gErrorMsg;
        factory   = gGlobal->gDSPFactory;
    } catch (faustexception& e) {
        error_msg = e.Message();
    }

    global::destroy();
    return factory;
}

dsp_factory_base* createFactory(const char* name, tvec signals, int argc, const char* argv[], std::string& error_msg)
{
    dsp_factory_base* factory = nullptr;

    try {
        Tree             outputs    = listConvert(signals);
        Tree             outputs_nf = simplifyToNormalForm(outputs);
        MaxInputsCounter counter(outputs_nf);
        createFactoryAux(name, outputs_nf, argc, argv, counter.fMaxInputs, signals.size(), true);
        error_msg = gGlobal->gErrorMsg;
        factory   = gGlobal->gDSPFactory;
    } catch (faustexception& e) {
        error_msg = e.Message();
    }

    return factory;
}

string expandDSP(int argc, const char* argv[], const char* name, const char* dsp_content, string& sha_key,
                 string& error_msg)
{
    gGlobal    = nullptr;
    string res = "";

    try {
        global::allocate();
        res       = expandDSPInternal(argc, argv, name, dsp_content);
        sha_key   = generateSHA1(res);
        error_msg = gGlobal->gErrorMsg;
    } catch (faustexception& e) {
        error_msg = e.Message();
    }

    global::destroy();
    return res;
}
