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

// ===============
// Signal C++ API
// ===============

#include "faust/api/cpp/signal_api.hh"
#include "compiler/dsp_factory/dsp_factory.hh"
#include "global.hh"
#include "faust.hh"
#include "libfaust.h"
#include "normalform.hh"
#include "labels.hh"

LIBFAUST_API std::string createSourceFromSignals(const std::string& name_app, tvec signals,
                                                 const std::string& lang,
                                                 int argc, const char* argv[],
                                                 std::string& error_msg)
{
    int         argc1 = 0;
    const char* argv1[64];
    argv1[argc1++] = "faust";
    argv1[argc1++] = "-lang";
    argv1[argc1++] = lang.c_str();
    argv1[argc1++] = "-o";
    argv1[argc1++] = "string";

    // Copy arguments
    for (int i = 0; i < argc; i++) {
        argv1[argc1++] = argv[i];
    }
    argv1[argc1] = nullptr;  // NULL terminated argv

    dsp_factory_base* factory = createFactory(name_app.c_str(), signals, argc1, argv1, error_msg);
    if (factory) {
        // Print the textual class
        stringstream str;
        factory->write(&str);
        delete factory;
        return str.str();
    } else {
        // the caller of this function should check that error_msg is blank.
        return "";
    }
}

// Foreign

LIBFAUST_API Tree sigFFun(Tree ff, tvec largs)
{
    return sigFFun(ff, listConvert(largs));
}

LIBFAUST_API Tree sigFConst(SType type, const string& name, const string& file)
{
    return sigFConst(tree(type), tree(name), tree(file));
}

LIBFAUST_API Tree sigFVar(SType type, const string& name, const string& file)
{
    return sigFVar(tree(type), tree(name), tree(file));
}

// User Interface

LIBFAUST_API Tree sigButton(const std::string& label)
{
    return sigButton(normalizePath(cons(tree(label), gGlobal->nil)));
}

LIBFAUST_API Tree sigCheckbox(const std::string& label)
{
    return sigCheckbox(normalizePath(cons(tree(label), gGlobal->nil)));
}

LIBFAUST_API Tree sigVSlider(const std::string& label, Tree cur, Tree min, Tree max, Tree step)
{
    return sigVSlider(normalizePath(cons(tree(label), gGlobal->nil)), cur, min, max, step);
}

LIBFAUST_API Tree sigHSlider(const std::string& label, Tree cur, Tree min, Tree max, Tree step)
{
    return sigHSlider(normalizePath(cons(tree(label), gGlobal->nil)), cur, min, max, step);
}

LIBFAUST_API Tree sigNumEntry(const std::string& label, Tree cur, Tree min, Tree max, Tree step)
{
    return sigNumEntry(normalizePath(cons(tree(label), gGlobal->nil)), cur, min, max, step);
}

LIBFAUST_API Tree sigVBargraph(const std::string& label, Tree min, Tree max, Tree x)
{
    return sigVBargraph(normalizePath(cons(tree(label), gGlobal->nil)), min, max, x);
}

LIBFAUST_API Tree sigHBargraph(const std::string& label, Tree min, Tree max, Tree x)
{
    return sigHBargraph(normalizePath(cons(tree(label), gGlobal->nil)), min, max, x);
}

LIBFAUST_API Tree sigSoundfile(const std::string& label)
{
    return sigSoundfile(normalizePath(cons(tree(label), gGlobal->nil)));
}

LIBFAUST_API Tree sigSelf()
{
    return sigDelay1(sigProj(0, ref(1)));
}

// Tree liftn(Tree t, int threshold);

LIBFAUST_API Tree sigRecursion(Tree s)
{
    // return sigDelay0(sigProj(0, rec(cons(liftn(s, 0), gGlobal->nil))));
    return sigDelay0(sigProj(0, rec(cons(s, gGlobal->nil))));
}

// Global context, to be used in C and C++ API

extern "C" LIBFAUST_API void createLibContext()
{
    gGlobal = nullptr;
    global::allocate();
}

extern "C" LIBFAUST_API void destroyLibContext()
{
    global::destroy();
}
