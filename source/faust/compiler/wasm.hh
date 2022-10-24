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

#ifndef __FAUST_COMPILE_WASM_HH__
#define __FAUST_COMPILE_WASM_HH__

#include "faust.hh"
#include "faust/compiler/common.hh"

#ifdef WASM_BUILD
#include "wasm_code_container.hh"
#include "wast_code_container.hh"
#endif

namespace Faust {
  namespace Compiler {

    struct WASM : public Common
    {
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out, const string& outpath)
      {
      #ifdef WASM_BUILD
          assert(out!=nullptr);
          assert(outpath!="");
          static ::Faust::Compiler::Return compiler_return;

          gGlobal->gAllowForeignFunction = false;  // No foreign functions
          gGlobal->gAllowForeignConstant = false;  // No foreign constant
          gGlobal->gAllowForeignVar      = false;  // No foreign variable

          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          gGlobal->gFAUSTFLOAT2Internal = true;
          // the 'i' variable used in the scalar loop moves by bytes instead of frames
          gGlobal->gLoopVarInBytes   = true;
          gGlobal->gWaveformInDSP    = true;   // waveform are allocated in the DSP and not as global data
          gGlobal->gMachinePtrSize   = 4;      // WASM is currently 32 bits
          gGlobal->gNeedManualPow    = false;  // Standard pow function will be used in pow(x,y) when Y in an integer
          gGlobal->gRemoveVarAddress = true;   // To be used in -vec mode
                                               // gGlobal->gHasTeeLocal = true;     // combined store/load

          gGlobal->gUseDefaultSound = false;

          // This speedup (freeverb for instance) ==> to be done at signal level
          // gGlobal->gComputeIOTA = true;     // Ensure IOTA base fixed delays are computed once

          compiler_return.container =
              WASMCodeContainer::createContainer(gGlobal->gClassName, numInputs, numOutputs, out,
                                                 ((gGlobal->gOutputLang == "wasm") || (gGlobal->gOutputLang == "wasm-i") ||
                                                  (gGlobal->gOutputLang == "wasm-ib")));
          this->createHelperFile(outpath);

          if (gGlobal->gVectorSwitch) {
              compiler_return.new_comp = new DAGInstructionsCompiler(compiler_return.container);
          } else {
              compiler_return.new_comp = new InstructionsCompiler(compiler_return.container);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) compiler_return.new_comp->setDescription(new Description());
          compiler_return.new_comp->compileMultiSignal(signals);
          return compiler_return;
      #else
          throw faustexception("ERROR : -lang wasm not supported since WASM backend is not built\n");
      #endif
      }
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs) { return compile(signals, numInputs, numOutputs, nullptr, ""); };
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, bool generate) { return compile(signals, numInputs, numOutputs, nullptr, ""); };
      virtual ::Faust::Compiler::Return compile(Tree signals, int numInputs, int numOutputs, ostream* out) { return compile(signals, numInputs, numOutputs, out, ""); };

      virtual void enumBackends(ostream& out)
      {
          Common::enumBackends(out);
          out << "WebAssembly (wasm)" << endl;
      }

    };

  }
}

#endif
