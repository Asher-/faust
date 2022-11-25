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

#ifndef __FAUST_COMPILE_WASM_HH__
#define __FAUST_COMPILE_WASM_HH__

#include "faust/api/faust.hh"
#include "faust/compiler/generator/common.hh"

#include "target/language/wasm/wasm_code_container.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

#include "compiler/parser/implementation.hh"

namespace Faust {
  namespace Compiler {

    struct WASM : public Common
    {
      static constexpr const char* TargetString = "WebAssembly (wasm)";
      static constexpr const char* LanguageString = "wasm";

      void compile(Tree signals, int numInputs, int numOutputs, ostream* out, const string& outpath)
      override
      {
      #ifndef WASM_BUILD
          throw faustexception("ERROR : -lang wasm not supported since WASM backend is not built\n");
      #endif

          assert(out!=nullptr);
          assert(outpath!="");

          global::config().gAllowForeignFunction = false;  // No foreign functions
          global::config().gAllowForeignConstant = false;  // No foreign constant
          global::config().gAllowForeignVar      = false;  // No foreign variable

          // FIR is generated with internal real instead of FAUSTFLOAT (see InstBuilder::genBasicTyped)
          global::config().gFAUSTFLOAT2Internal = true;
          // the 'i' variable used in the scalar loop moves by bytes instead of frames
          global::config().gLoopVarInBytes   = true;
          global::config().gWaveformInDSP    = true;   // waveform are allocated in the DSP and not as global data
          ::Faust::Primitive::Math::gMachinePtrSize   = 4;      // WASM is currently 32 bits
          ::Faust::Primitive::Math::needManualPow    = false;  // Standard pow function will be used in pow(x,y) when Y in an integer
          global::config().gRemoveVarAddress = true;   // To be used in -vec mode
                                               // global::config().gHasTeeLocal = true;     // combined store/load

          global::config().gUseDefaultSound = false;

          // This speedup (freeverb for instance) ==> to be done at signal level
          // global::config().gComputeIOTA = true;     // Ensure IOTA base fixed delays are computed once

          this->_codeContainer =
              WASMCodeContainer::createContainer(global::config().gClassName, numInputs, numOutputs, out,
                                                 ((gOutputLang() == "wasm") || (gOutputLang() == "wasm-i") ||
                                                  (gOutputLang() == "wasm-ib")));
          this->createHelperFile(outpath);

          if (global::config().gVectorSwitch) {
              this->_instructionCompiler = new DAGInstructionsCompiler(this->_codeContainer);
          } else {
              this->_instructionCompiler = new InstructionsCompiler(this->_codeContainer);
          }

          if (global::config().gPrintXMLSwitch || global::config().gPrintDocSwitch) this->_instructionCompiler->setDescription(new Description());
          this->_instructionCompiler->compileMultiSignal(signals);
      }
      void compile(Tree signals, int numInputs, int numOutputs) override { throw "std::ostream and std::string required."; };

      const char* const& targetString() override  { return TargetString; }

    };

  }
}

#endif
