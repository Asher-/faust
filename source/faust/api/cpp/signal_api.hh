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

#ifndef _SIGNAL_API_H_
#define _SIGNAL_API_H_

#include "faust.hh"

// ===============
// Signal C++ API
// ===============

enum SType { kSInt, kSReal };

LIBFAUST_API std::string createSourceFromSignals(const std::string& name_app, tvec signals,
                                                 const std::string& lang,
                                                 int argc, const char* argv[],
                                                 std::string& error_msg);
LIBFAUST_API Tree sigFFun(Tree ff, tvec largs);
LIBFAUST_API Tree sigFConst(SType type, const string& name, const string& file);
LIBFAUST_API Tree sigFVar(SType type, const string& name, const string& file);
LIBFAUST_API Tree sigButton(const std::string& label);
LIBFAUST_API Tree sigCheckbox(const std::string& label);
LIBFAUST_API Tree sigVSlider(const std::string& label, Tree cur, Tree min, Tree max, Tree step);
LIBFAUST_API Tree sigHSlider(const std::string& label, Tree cur, Tree min, Tree max, Tree step);
LIBFAUST_API Tree sigNumEntry(const std::string& label, Tree cur, Tree min, Tree max, Tree step);
LIBFAUST_API Tree sigVBargraph(const std::string& label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree sigHBargraph(const std::string& label, Tree min, Tree max, Tree x);
LIBFAUST_API Tree sigSoundfile(const std::string& label);
LIBFAUST_API Tree sigSelf();
LIBFAUST_API Tree sigRecursion(Tree s);
extern "C" LIBFAUST_API void createLibContext();
extern "C" LIBFAUST_API void destroyLibContext();

#endif
