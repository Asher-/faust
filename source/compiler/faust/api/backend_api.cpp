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

#include "dsp_factory.hh"
#include "global.hh"
#include "faust.hh"
#include "libfaust.h"
#include "normalform.hh"
#include "Text.hh"

#include "tlib/compatibility.hh"

#include "faust/architectures.hh"
#include "faust/cli.hh"
#include "faust/compiler/common.hh"

#include "visitors/max_inputs_visitor.hh"

// ============
// Backend API
// ============

/* From Source */
dsp_factory_base* createFactory(const char* name, const char* dsp_content, int argc, const char* argv[],
                                string& error_msg, bool generate)
{
    gGlobal = nullptr;
    dsp_factory_base* factory{nullptr};
    try {
      ::Faust::CLI faust_cli(argc, argv);
      ::Faust::Compiler::Common* compiler = faust_cli.parse();
      compiler->_dspContent = dsp_content;
      compiler->_generate = generate;
      compiler->createFactory();
      error_msg = gGlobal->gErrorMsg;
      factory   = gGlobal->gDSPFactory;
    } catch (faustexception& e) {
        error_msg = e.Message();
    }
    global::destroy();
    return factory;
}

/* From Signals */
dsp_factory_base* createFactory(const char* name, tvec signals, int argc, const char* argv[], std::string& error_msg)
{
    dsp_factory_base* factory = nullptr;

    try {
        Tree             outputs    = listConvert(signals);
        Tree             outputs_nf = simplifyToNormalForm(outputs);
        MaxInputsCounter counter(outputs_nf);
        ::Faust::CLI faust_cli(argc, argv);
        ::Faust::Compiler::Common* compiler = faust_cli.parse();
        compiler->createFactory(name, outputs_nf, counter.fMaxInputs, signals.size());
        error_msg = gGlobal->gErrorMsg;
      factory   = gGlobal->gDSPFactory;
    } catch (faustexception& e) {
        error_msg = e.Message();
    }

    return factory;
}

/* From Sources with encryption */
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
