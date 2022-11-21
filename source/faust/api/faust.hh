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

#ifndef _FAUST_HH_
#define _FAUST_HH_

#include <sstream>

#include "tlib/tree.hh"
#include "compiler/compile/xml_description.hh"

LIBFAUST_API const std::string& xtendedName(Tree tree);
LIBFAUST_API unsigned int xtendedArity(Tree tree);
LIBFAUST_API Tree DSPToBoxes(const std::string& name_app, const std::string& dsp_content, int argc, const char* argv[], int* inputs, int* outputs, std::string& error_msg);


#endif
