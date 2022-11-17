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

#ifndef __CPP_GPU_OPENCL_KERNEL_INSTRUCTION_VISITOR_HH__
#define __CPP_GPU_OPENCL_KERNEL_INSTRUCTION_VISITOR_HH__

struct OpenCLKernelInstVisitor : public KernelInstVisitor {
    // Code will be generated as a string
    virtual void tab1(int n, ostream& fout)
    {
        fout << "  \\n\"  \\\n";
        fout << "\"";
        while (n--) fout << '\t';
    }

    OpenCLKernelInstVisitor(std::ostream* out, int tab) : KernelInstVisitor(out, tab)
    {
        fFunctionTable["sin"]    = "native_sin";
        fFunctionTable["sinf"]   = "native_sin";
        fFunctionTable["cos"]    = "native_cos";
        fFunctionTable["cosf"]   = "native_cos";
        fFunctionTable["tan"]    = "native_tan";
        fFunctionTable["tanf"]   = "native_tan";
        fFunctionTable["log"]    = "native_log";
        fFunctionTable["logf"]   = "native_log";
        fFunctionTable["log10"]  = "native_log10";
        fFunctionTable["log10f"] = "native_log10";
        fFunctionTable["log2"]   = "native_log2";
        fFunctionTable["log2f"]  = "native_log2";
        fFunctionTable["exp"]    = "native_exp";
        fFunctionTable["expf"]   = "native_exp";
        fFunctionTable["powf"]   = "native_powr";
        fFunctionTable["sqrt"]   = "native_sqrt";
        fFunctionTable["sqrtf"]  = "native_sqrt";
        fFunctionTable["fabsf"]  = "fabs";
        fFunctionTable["floorf"] = "floor";
        fFunctionTable["fmodf"]  = "fmod";
    }
};

#endif
