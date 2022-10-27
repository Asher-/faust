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

#ifndef __FAUST_COMPILE_WAST_HH__
#define __FAUST_COMPILE_WAST_HH__

#include "faust.hh"
#include "faust/compiler/common.hh"
#include <cassert>

#include "wast_code_container.hh"

namespace Faust {
  namespace Compiler {

    struct WAST : public Common
    {
      static constexpr const char* TargetString = "WebAssembly (wast)";
      static constexpr const char* LanguageString = "wast";

      void compile(Tree signals, int numInputs, int numOutputs, ostream* out, const string& outpath)
      override
      {
        #ifndef WASM_BUILD
          throw faustexception("ERROR : -lang wast not supported since WAST backend is not built\n");
        #endif

          assert(out!=nullptr);
          assert(outpath!="");

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

          this->_codeContainer =
              WASTCodeContainer::createContainer(gGlobal->gClassName, numInputs, numOutputs, out,
                                                 ((gGlobal->gOutputLang == "wast") || (gGlobal->gOutputLang == "wast-i")));
          this->createHelperFile(outpath);

          if (gGlobal->gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler(this->_codeContainer);
          }

          if (gGlobal->gPrintXMLSwitch || gGlobal->gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());
          this->_instructionCompiler->compileMultiSignal(signals);
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "std::ostream and std::string required."; };

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
