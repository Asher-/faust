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

/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
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
#include "xml_description.hh"

/****************************************************************
 Global context
 *****************************************************************/

void* threadBoxPropagateSig(void* arg);

/****************************************************************
                Command line tools and arguments
*****************************************************************/

bool isCmd(const char* cmd, const char* kw1);
bool isCmd(const char* cmd, const char* kw1, const char* kw2);

/****************************************************************
                     Help and Version information
*****************************************************************/

LIBFAUST_API const char* xtendedName(Tree tree);
LIBFAUST_API unsigned int xtendedArity(Tree tree);

/**
 * transform a filename "faust/example/noise.dsp" into
 * the corresponding fx name "noise"
 */
string fxName(const string& filename);
void includeFile(const string& file, ostream& dst);
void compileCLLVM(Tree signals, int numInputs, int numOutputs);
void compileLLVM(Tree signals, int numInputs, int numOutputs, bool generate);
void compileInterp(Tree signals, int numInputs, int numOutputs);
void compileFIR(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileC(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileCPP(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileOCPP(Tree signals, int numInputs, int numOutputs);
void compileRust(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileJava(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileJulia(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileJAX(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileCSharp(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileSOUL(Tree signals, int numInputs, int numOutputs, ostream* out);
void compileWAST(Tree signals, int numInputs, int numOutputs, ostream* out, const string& outpath);
void compileWASM(Tree signals, int numInputs, int numOutputs, ostream* out, const string& outpath);
void generateCodeAux1(unique_ptr<ostream>& dst);
void printHeader(ostream& dst);
void generateCodeAux2(unique_ptr<ostream>& dst);
void generateCode(Tree signals, int numInputs, int numOutputs, bool generate);
void printXML(Description* D, int inputs, int outputs);
void generateOutputFiles();
void expandDSPInternalAux(ostream& out);
string expandDSPInternal(int argc, const char* argv[], const char* name, const char* dsp_content);
LIBFAUST_API Tree DSPToBoxes(const std::string& name_app, const std::string& dsp_content, int argc, const char* argv[], int* inputs, int* outputs, std::string& error_msg);
void createFactoryAux(const char* name, const char* dsp_content, int argc, const char* argv[], bool generate);
void createFactoryAux(const char* name, Tree signals, int argc, const char* argv[], int numInputs,
                             int numOutputs, bool generate);


#endif
