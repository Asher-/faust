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

#include <gtest/gtest.h>

#include "compiler/parser/implementation.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"

using Parser = ::Faust::Compiler::Parser::Implementation;

struct ParserManualExamplesTest
:
  ::testing::Test
{

    ParserManualExamplesTest
    ()
    {
      /* Uncomment for Bison/Flex trace output */
      parser._traceParsing = false;
      parser._traceScanning = false;
    }

    virtual
    ~ParserManualExamplesTest

    ()
    {

    }
    

    Parser parser;

};

TEST_F( ParserManualExamplesTest, empty ) {
  std::string source = R""""()"""";
  Tree ast = parser.parseString( source, "Empty.dsp" );
  ASSERT_EQ( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, variants ) {
  std::string source = R""""(
    singleprecision one = 3.402823466e+38;
    doubleprecision two = 1.7976931348623158e+308;
  )"""";
  Tree ast = parser.parseString( source, "variants.dsp" );
  ASSERT_NE( ast, nullptr );
  std::stringstream pprint;
  pprint << boxpp(ast);
  std::string printed(pprint.str());
  std::cout << pprint.str() << std::endl;
}

TEST_F( ParserManualExamplesTest, simpleProgram ) {
  std::string source = R""""(
    declare name "Noise";
    declare copyright "(c)GRAME 2022";

    import("stdfaust.lib");

    // noise level controlled by a slider
    process = no.noise * hslider("gain",0,0,1,0.1);
  )"""";
  Tree ast = parser.parseString( source, "simpleProgram.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, globalMetadata ) {
  std::string source = R""""(
    declare name "Noise";
    declare name "MyProgram";
    declare author "MySelf";
    declare copyright "MyCompany";
    declare version "1.00";
    declare license "BSD";
  )"""";
  Tree ast = parser.parseString( source, "globalMetadata.dsp" );
  ast->location().printStack(std::cout);
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, functionMetadata ) {
  std::string source = R""""(
    declare add author "John Doe";
  )"""";
  Tree ast = parser.parseString( source, "functionMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, options ) {
  std::string source = R""""(
    declare options "[key0:value] [key1:value]";
  )"""";
  Tree ast = parser.parseString( source, "options.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, importStatement ) {
  std::string source = R""""(import("somefile.dsp");)"""";
  Tree ast = parser.parseString( source, "importStatement.dsp" );
  Tree importStatement = ast->branch(0);
  Tree fileString = importStatement->branch(0);
  ASSERT_TRUE( isImportFile(importStatement, fileString) );
}

TEST_F( ParserManualExamplesTest, mdocEmpty ) {
  std::string source = R""""(
    <mdoc></mdoc>
  )"""";
  Tree ast = parser.parseString( source, "mdocEmpty.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, mdoc ) {
  std::string source = R""""(
    declare name "Noise";
    random  = +(12345)~*(1103515245);
  )"""";
  Tree ast = parser.parseString( source, "mdoc.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, simpleDefinition ) {
  std::string source = R""""(
    random = +(12345) ~ *(1103515245);
  )"""";
  Tree ast = parser.parseString( source, "simpleDefinition.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, function ) {
  std::string source = R""""(
    linear2db(x) = 20*log10(x);
  )"""";
  Tree ast = parser.parseString( source, "function.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, lambda ) {
  std::string source = R""""(
    linear2db = \(x).(20*log10(x));
  )"""";
  Tree ast = parser.parseString( source, "lambda.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, patternMatching ) {
  std::string source = R""""(
    duplicate(1,x) = x;
    duplicate(n,x) = x, duplicate(n-1,x);
  )"""";
  Tree ast = parser.parseString( source, "patternMatching.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, patternMatchingCase ) {
  std::string source = R""""(
    duplicate = case {
      (1,x) => x;
      (n,x) => x, duplicate(n-1,x);
    };
  )"""";
  Tree ast = parser.parseString( source, "patternMatching.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, duplicate5Generators ) {
  std::string source = R""""(
    import("stdfaust.lib");
    duplicate(1,x) = x;
    duplicate(n,x) = x, duplicate(n-1,x);
    process = duplicate(5,no.noise);
  )"""";
  Tree ast = parser.parseString( source, "duplicate5Generators.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, countListElements ) {
  std::string source = R""""(
    count((x,xs)) = 1+count(xs);
    count(x) = 1;
  )"""";
  Tree ast = parser.parseString( source, "countListElements.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, oscillatorsInParallel ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = os.osc(440),os.sawtooth(550),os.triangle(660);
  )"""";
  Tree ast = parser.parseString( source, "oscillatorsInParallel.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, stereoEffect ) {
  std::string source = R""""(
    import("stdfaust.lib");
    level = 1;
    process = ve.autowah(level),ve.autowah(level);
  )"""";
  Tree ast = parser.parseString( source, "stereoEffect.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, stereoEffectParIteration ) {
  std::string source = R""""(
    import("stdfaust.lib");
    level = 1;
    process = par(i,2,ve.autowah(level));
  )"""";
  Tree ast = parser.parseString( source, "stereoEffectParIteration.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sequentialCompositionSineOscillator ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = 440 : os.osc;
  )"""";
  Tree ast = parser.parseString( source, "sequentialCompositionSineOscillator.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sequentialCompositionEffectChain ) {
  std::string source = R""""(
    import("stdfaust.lib");
    drive = 0.6;
    offset = 0;
    autoWahLevel = 1;
    process = ef.cubicnl(drive,offset) : ve.autowah(autoWahLevel);
  )"""";
  Tree ast = parser.parseString( source, "sequentialCompositionEffectChain.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, splitCompositionDuplicatingOscillatorOutput ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = os.sawtooth(440) <: _,_,_;
  )"""";
  Tree ast = parser.parseString( source, "splitCompositionDuplicatingOscillatorOutput.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, splitCompositionConnectingMonoToStereo ) {
  std::string source = R""""(
    import("stdfaust.lib");
    drive = 0.6;
    offset = 0;
    process = ef.cubicnl(drive,offset) <: dm.zita_light;
  )"""";
  Tree ast = parser.parseString( source, "splitCompositionConnectingMonoToStereo.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, splitCompositionArbitrarySignals ) {
  std::string source = R""""(
    import("stdfaust.lib");
    drive = 0.6;
    offset = 0;
    process = par(i,2,ef.cubicnl(drive,offset)) <: par(i,2,dm.zita_light);
  )"""";
  Tree ast = parser.parseString( source, "splitCompositionArbitrarySignals.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, mergeCompositionSummingSignalsAdditiveSynthesis ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,3000,0.01);
    gain = hslider("gain",1,0,1,0.01);
    gate = button("gate");
    envelope = gain*gate : si.smoo;
    process = os.osc(freq),os.osc(freq*2),os.osc(freq*3) :> /(3)*envelope;
  )"""";
  Tree ast = parser.parseString( source, "mergeCompositionSummingSignalsAdditiveSynthesis.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, mergeCompositionSummingSignalsAdditiveSynthesisAlternative ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,3000,0.01);
    gain = hslider("gain",1,0,1,0.01);
    gate = button("gate");
    envelope = gain*gate : si.smoo;
    process = (os.osc(freq) + os.osc(freq*2) + os.osc(freq*3))/(3)*envelope;
  )"""";
  Tree ast = parser.parseString( source, "mergeCompositionSummingSignalsAdditiveSynthesis.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, mergeCompositionConnectingStereoToMono ) {
  std::string source = R""""(
    import("stdfaust.lib");
    drive = 0.6;
    offset = 0;
    process = dm.zita_light :> ef.cubicnl(drive,offset);
  )"""";
  Tree ast = parser.parseString( source, "mergeCompositionConnectingStereoToMono.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, mergeCompositionConnectingStereoToMonoArbitrarySplit ) {
  std::string source = R""""(
    import("stdfaust.lib");
    drive = 0.6;
    offset = 0;
    process = par(i,2,dm.zita_light) :> par(i,2,ef.cubicnl(drive,offset));
  )"""";
  Tree ast = parser.parseString( source, "mergeCompositionConnectingStereoToMonoArbitrarySplit.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, recursiveCompositionTimer ) {
  std::string source = R""""(
    process = _~+(1);
  )"""";
  Tree ast = parser.parseString( source, "recursiveCompositionTimer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, recursiveCompositionOnePoleFilter ) {
  std::string source = R""""(
    a1 = 0.999; // the pole
    process = +~*(a1);
  )"""";
  Tree ast = parser.parseString( source, "recursiveCompositionOnePoleFilter.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, numberOfOutputs ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = outputs(os.osc(440));
  )"""";
  Tree ast = parser.parseString( source, "numberOfOutputs.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, reverseOrderOfOutputs ) {
  std::string source = R""""(
    Xo(expr) = expr <: par(i,n,ba.selector(n-i-1,n))
    with {
      n = outputs(expr);
    };
  )"""";
  Tree ast = parser.parseString( source, "reverseOrderOfOutputs.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, reverseOrderOfInputs ) {
  std::string source = R""""(
    Xi(expr) = si.bus(n) <: par(i,n,ba.selector(n-i-1,n)) : expr
    with {
      n = inputs(expr);
    };
  )"""";
  Tree ast = parser.parseString( source, "reverseOrderOfInputs.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, reverseTwoInputs ) {
  std::string source = R""""(
    import("stdfaust.lib");
    Xi(expr) = si.bus(n) <: par(i,n,ba.selector(n-i-1,n)) : expr
    with {
      n = inputs(expr);
    };
    process = Xi(-);

  )"""";
  Tree ast = parser.parseString( source, "reverseTwoInputs.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, parallelIterationSimpleAdditiveSynthesizer ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,3000,0.01);
    gain = hslider("gain",1,0,1,0.01);
    gate = button("gate");
    envelope = gain*gate : si.smoo;
    nHarmonics = 4;
    process = par(i,nHarmonics,os.osc(freq*(i+1))) :> /(nHarmonics)*envelope;
  )"""";
  Tree ast = parser.parseString( source, "parallelIterationSimpleAdditiveSynthesizer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sequenceIterationPeakEqualizer ) {
  std::string source = R""""(
    import("stdfaust.lib");
    nBands = 8;
    filterBank(N) = hgroup("Filter Bank",seq(i,N,oneBand(i)))
    with {
        oneBand(j) = vgroup("[%j]Band %a",fi.peak_eq(l,f,b))
        with {
            a = j+1; // just so that band numbers don't start at 0
            l = vslider("[2]Level[unit:db]",0,-70,12,0.01) : si.smoo;
            f = nentry("[1]Freq",(80+(1000*8/N*(j+1)-80)),20,20000,0.01) : si.smoo;
            b = f/hslider("[0]Q[style:knob]",1,1,50,0.01) : si.smoo;
        };
    };
    process = filterBank(nBands);
  )"""";
  Tree ast = parser.parseString( source, "sequenceIterationPeakEqualizer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sumIterationSimpleAdditiveSynthesizer ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,3000,0.01);
    gain = hslider("gain",1,0,1,0.01);
    gate = button("gate");
    envelope = gain*gate : si.smoo;
    nHarmonics = 4;
    process = sum(i,nHarmonics,os.osc(freq*(i+1)))/(nHarmonics)*envelope;
  )"""";
  Tree ast = parser.parseString( source, "sumIterationSimpleAdditiveSynthesizer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, productIterationAmplitudeModulationSynthesizer ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("[0]freq",440,50,3000,0.01);
    gain = hslider("[1]gain",1,0,1,0.01);
    shift = hslider("[2]shift",0,0,1,0.01);
    gate = button("[3]gate");
    envelope = gain*gate : si.smoo;
    nOscs = 4;
    process = prod(i,nOscs,os.osc(freq*(i+1+shift)))*envelope;
  )"""";
  Tree ast = parser.parseString( source, "productIterationAmplitudeModulationSynthesizer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, partialApplicationGainController ) {
  std::string source = R""""(
    gain = hslider("gain",0.5,0,1,0.01);
    process = *(gain);
  )"""";
  Tree ast = parser.parseString( source, "partialApplicationGainController.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, timeExpression ) {
  std::string source = R""""(
    process = _';
  )"""";
  Tree ast = parser.parseString( source, "timeExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, timeExpressionChain ) {
  std::string source = R""""(
    process = 1'';
  )"""";
  Tree ast = parser.parseString( source, "timeExpressionChain.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, atTimeExpression ) {
  std::string source = R""""(
    process = @(10);
  )"""";
  Tree ast = parser.parseString( source, "atTimeExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, delaySlider ) {
  std::string source = R""""(
    process = @(hslider("delay",0,0,100,1));
  )"""";
  Tree ast = parser.parseString( source, "delaySlider.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, withExpression ) {
  std::string source = R""""(
    pink = f : + ~ g
    with {
      f(x) = 0.04957526213389*x - 0.06305581334498*x' + 0.01483220320740*x'';
      g(x) = 1.80116083982126*x - 0.80257737639225*x';
    };
    process = pink;
  )"""";
  Tree ast = parser.parseString( source, "withExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, letrecExpression ) {
  std::string source = R""""(
    import("stdfaust.lib");
    ar(a,r,g) = v
    letrec {
      'n = (n+1) * (g<=g');
      'v = max(0, v + (n<a)/a - (n>=a)/r) * (g<=g');
    };
    gate = button("gate");
    process = os.osc(440)*ar(1000,1000,gate);
  )"""";
  Tree ast = parser.parseString( source, "letrecExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, letrecExpressionFactorized ) {
  std::string source = R""""(
    ar(a,r,g) = v letrec {
    'n = (n+1) * c;
    'v = max(0, v + (n<a)/a - (n>=a)/r) * c;
    where
        c = g<=g';
    };
  )"""";
  Tree ast = parser.parseString( source, "letrecExpressionFactorized.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, environmentExpression ) {
  std::string source = R""""(
    constant = environment {
      pi = 3.14159;
      e = 2,718;
    };
  )"""";
  Tree ast = parser.parseString( source, "environmentExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, accessExpression ) {
  std::string source = R""""(
    access = environment{pi = 3.14159; e = 2,718;}.pi;
  )"""";
  Tree ast = parser.parseString( source, "accessExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, libraryExpression ) {
  std::string source = R""""(
    import("filters.lib");
  )"""";
  Tree ast = parser.parseString( source, "libraryExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, componentExpression ) {
  std::string source = R""""(
    freeverb = component("../examples/reverb/freeverb.dsp");
  )"""";
  Tree ast = parser.parseString( source, "componentExpression.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, explicitSubstitution ) {
  std::string source = R""""(
    freeverb = component("../examples/reverb/freeverb.dsp")[foo(x) = 2;];
  )"""";
  Tree ast = parser.parseString( source, "explicitSubstitution.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, ffunction ) {
  std::string source = R""""(
    asinh = ffunction(float asinh (float), <math.h>, "");
  )"""";
  Tree ast = parser.parseString( source, "explicitSubstitution.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, polymorphicffunction ) {
  std::string source = R""""(
    sizeof = ffunction(int sizeof(any), "","");
  )"""";
  Tree ast = parser.parseString( source, "polymorphicffunction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, foreignVariablesAndConstants ) {
  std::string source = R""""(
    SR = min(192000.0,max(1.0,fconstant(int fSamplingFreq, <math.h>)));
    BS = fvariable(int count, <math.h>);
  )"""";
  Tree ast = parser.parseString( source, "polymorphicffunction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, monoReverb ) {
  std::string source = R""""(
    reverb = _ <: dm.zita_light :> _;
  )"""";
  Tree ast = parser.parseString( source, "monoReverb.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, monoReverbAbstraction ) {
  std::string source = R""""(
    abstraction = \(zita_light).(_ <: zita_light :> _);
  )"""";
  Tree ast = parser.parseString( source, "monoReverbAbstraction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, monoReverbAbstractionApplied ) {
  std::string source = R""""(
    import("stdfaust.lib");
    mono = \(fx).(_ <: fx :> _);
    process = mono(dm.zita_light);
  )"""";
  Tree ast = parser.parseString( source, "monoReverbAbstractionApplied.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, monoReverbAbstractionAppliedTraditionalNotation ) {
  std::string source = R""""(
    mono(fx) = _ <: fx :> _;
  )"""";
  Tree ast = parser.parseString( source, "monoReverbAbstractionApplied.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, patternMatchingReverb ) {
  std::string source = R""""(
    match = case{(x:y) => y:x; (x) => x;}(reverb : harmonizer);
  )"""";
  Tree ast = parser.parseString( source, "patternMatchingReverb.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, routePrimitiveCrossTwoSignals ) {
  std::string source = R""""(
    process = route(2,2,1,2,2,1);
  )"""";
  Tree ast = parser.parseString( source, "routePrimitiveCrossTwoSignals.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, routePrimitiveCrossTwoSignals2 ) {
  std::string source = R""""(
    process = route(2,2,(1,2),(2,1));
  )"""";
  Tree ast = parser.parseString( source, "routePrimitiveCrossTwoSignals2.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, routePrimitiveCrossNSignals ) {
  std::string source = R""""(
    // cross 10 signals:
    // input 0 -> output 10,
    // input 1 -> output 9,
    // ...,
    // input 9 -> output 0

    N = 10;
    r = route(N,N,par(i,N,(i+1,N-i)));

    process = r;
  )"""";
  Tree ast = parser.parseString( source, "routePrimitiveCrossNSignals.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, waveformPrimitive ) {
  std::string source = R""""(
    import("stdfaust.lib");
    triangleWave = waveform{0.0,0.5,1,0.5,0,-0.5,-1,-.5};
  )"""";
  Tree ast = parser.parseString( source, "waveformPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, soundfilePrimitive ) {
  std::string source = R""""(
    process = 0,_~+(1):soundfile("son[url:{'../tests/architecture-tests/s1.wav'}]",2):!,!,_,_;
  )"""";
  Tree ast = parser.parseString( source, "soundfilePrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, addProcess ) {
  std::string source = R""""(
    process = +;
  )"""";
  Tree ast = parser.parseString( source, "addProcess.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, signalToTupleTransformer ) {
  std::string source = R""""(
    process = _+_;
  )"""";
  Tree ast = parser.parseString( source, "signalToTupleTransformer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, integerNumber ) {
  std::string source = R""""(
    process = 1;
  )"""";
  Tree ast = parser.parseString( source, "integerNumber.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, floatNumber ) {
  std::string source = R""""(
    process = 0.5;
  )"""";
  Tree ast = parser.parseString( source, "floatNumber.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, identity ) {
  std::string source = R""""(
    process = _;
  )"""";
  Tree ast = parser.parseString( source, "identity.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, cutPrimitive ) {
  std::string source = R""""(
    process = 1,2 : !,_;
  )"""";
  Tree ast = parser.parseString( source, "cutPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, intPrimitive ) {
  std::string source = R""""(
    process = 1.5 : int;
  )"""";
  Tree ast = parser.parseString( source, "intPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, floatPrimitive ) {
  std::string source = R""""(
    process = 1.5 : float;
  )"""";
  Tree ast = parser.parseString( source, "floatPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, addPrimitive ) {
  std::string source = R""""(
    process = +;
  )"""";
  Tree ast = parser.parseString( source, "addPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, subtractPrimitive ) {
  std::string source = R""""(
    process = -;
  )"""";
  Tree ast = parser.parseString( source, "subtractPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, multiplyPrimitive ) {
  std::string source = R""""(
    process = *(0.5);
  )"""";
  Tree ast = parser.parseString( source, "multiplyPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, dividePrimitive ) {
  std::string source = R""""(
    process = /(2);
  )"""";
  Tree ast = parser.parseString( source, "dividePrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, powerPrimitive ) {
  std::string source = R""""(
    process = ^(2);
  )"""";
  Tree ast = parser.parseString( source, "powerPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, moduloPrimitive ) {
  std::string source = R""""(
    process = _~+(1) : -(1) : %(10);
  )"""";
  Tree ast = parser.parseString( source, "moduloPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, andPrimitive ) {
  std::string source = R""""(
    process = _ <: <(0.5) & >(0.7);
  )"""";
  Tree ast = parser.parseString( source, "andPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, orPrimitive ) {
  std::string source = R""""(
    process = _ <: <(0.5) | >(0.7);
  )"""";
  Tree ast = parser.parseString( source, "orPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, xorPrimitive ) {
  std::string source = R""""(
    process = _ <: <(0.5) xor >(0.7);
  )"""";
  Tree ast = parser.parseString( source, "xorPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, leftShift ) {
  std::string source = R""""(
    process = 1 << 2;
  )"""";
  Tree ast = parser.parseString( source, "leftShift.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, rightShift ) {
  std::string source = R""""(
    process = 1 >> 2;
  )"""";
  Tree ast = parser.parseString( source, "rightShift.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, smallerThanPrimitive ) {
  std::string source = R""""(
    process = <(0.5);
  )"""";
  Tree ast = parser.parseString( source, "smallerThanPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, smallerThanOrEqualToPrimitive ) {
  std::string source = R""""(
    process = <=(0.5);
  )"""";
  Tree ast = parser.parseString( source, "smallerThanOrEqualToPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, greaterThanPrimitive ) {
  std::string source = R""""(
    process = >(0.5);
  )"""";
  Tree ast = parser.parseString( source, "greaterThanPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, greaterThanOrEqualToPrimitive ) {
  std::string source = R""""(
    process = >=(0.5);
  )"""";
  Tree ast = parser.parseString( source, "greaterThanOrEqualToPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, equalToPrimitive ) {
  std::string source = R""""(
    process = 0 == 1;
  )"""";
  Tree ast = parser.parseString( source, "equalToPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, notEqualToPrimitive ) {
  std::string source = R""""(
    process = 0 != 1;
  )"""";
  Tree ast = parser.parseString( source, "notEqualToPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, acosPrimitive ) {
  std::string source = R""""(
    process = 0.1 : acos;
  )"""";
  Tree ast = parser.parseString( source, "acosPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, atanPrimitive ) {
  std::string source = R""""(
    process = 0.1 : atan;
  )"""";
  Tree ast = parser.parseString( source, "atanPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, atan2Primitive ) {
  std::string source = R""""(
    process = 0.1,-0.1 : atan2;
  )"""";
  Tree ast = parser.parseString( source, "atan2Primitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, cosPrimitive ) {
  std::string source = R""""(
    process = 0.1 : cos;
  )"""";
  Tree ast = parser.parseString( source, "cosPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sinPrimitive ) {
  std::string source = R""""(
    process = 0.1 : sin;
  )"""";
  Tree ast = parser.parseString( source, "sinPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, expPrimitive ) {
  std::string source = R""""(
    process = 0.1 : exp;
  )"""";
  Tree ast = parser.parseString( source, "expPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, logPrimitive ) {
  std::string source = R""""(
    process = 0.1 : log;
  )"""";
  Tree ast = parser.parseString( source, "logPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, log10Primitive ) {
  std::string source = R""""(
    process = 0.1 : log10;
  )"""";
  Tree ast = parser.parseString( source, "log10Primitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, powPrimitive ) {
  std::string source = R""""(
    process = 2,4 : pow;
  )"""";
  Tree ast = parser.parseString( source, "powPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, sqrtPrimitive ) {
  std::string source = R""""(
    process = 4 : sqrt;
  )"""";
  Tree ast = parser.parseString( source, "sqrtPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, absPrimitive ) {
  std::string source = R""""(
    process = -0.5 : abs;
  )"""";
  Tree ast = parser.parseString( source, "absPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, minPrimitive ) {
  std::string source = R""""(
    process = -0.5,0.2 : min;
  )"""";
  Tree ast = parser.parseString( source, "minPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, maxPrimitive ) {
  std::string source = R""""(
    process = -0.5,0.2 : max;
  )"""";
  Tree ast = parser.parseString( source, "maxPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, fmodPrimitive ) {
  std::string source = R""""(
    process = 5.3,2 : fmod;
  )"""";
  Tree ast = parser.parseString( source, "fmodPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, remainderPrimitive ) {
  std::string source = R""""(
    process = 5.3,2 : remainder;
  )"""";
  Tree ast = parser.parseString( source, "remainderPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, floorPrimitive ) {
  std::string source = R""""(
    process = 3.6 : floor;
  )"""";
  Tree ast = parser.parseString( source, "floorPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, ceilPrimitive ) {
  std::string source = R""""(
    process = 3.6 : ceil;
  )"""";
  Tree ast = parser.parseString( source, "ceilPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, rintPrimitive ) {
  std::string source = R""""(
    process = 3.6 : rint;
  )"""";
  Tree ast = parser.parseString( source, "rintPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, memPrimitive ) {
  std::string source = R""""(
    process = mem;
  )"""";
  Tree ast = parser.parseString( source, "memPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, delayTickPrimitive ) {
  std::string source = R""""(
    process = _';
  )"""";
  Tree ast = parser.parseString( source, "delayTick.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, atPrimitive ) {
  std::string source = R""""(
    process = _ : @(N) : _;
  )"""";
  Tree ast = parser.parseString( source, "atPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, staticNSampleDelay ) {
  std::string source = R""""(
    N = 10;
    process = @(N);
  )"""";
  Tree ast = parser.parseString( source, "staticNSampleDelay.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, dynamicNSampleDelay ) {
  std::string source = R""""(
    N = hslider("N",10,1,10,1);
    process = @(N);
  )"""";
  Tree ast = parser.parseString( source, "dynamicNSampleDelay.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, rdtablePrimitive ) {
  std::string source = R""""(
    process = rdtable(n,s,r) : _;
  )"""";
  Tree ast = parser.parseString( source, "rdtablePrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, basicTriangleWaveOscillatorUsingWaveformPrimitive ) {
  std::string source = R""""(
    import("stdfaust.lib");
    triangleWave = waveform{0,0.5,1,0.5,0,-0.5,-1,-.5};
    triangleOsc(f) = triangleWave,int(os.phasor(8,f)) : rdtable;
    f = hslider("freq",440,50,2000,0.01);
    process = triangleOsc(f);
  )"""";
  Tree ast = parser.parseString( source, "basicTriangleWaveOscillatorUsingWaveformPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, basicTriangleWaveOscillatorUsingSinPrimitiveAndTimer ) {
  std::string source = R""""(
    import("stdfaust.lib");
    tableSize = 1 << 16;
    sineWave(tablesize) = float(ba.time)*(2.0*ma.PI)/float(tablesize) : sin;
    triangleOsc(f) = tableSize,sineWave(tableSize),int(os.phasor(tableSize,f)) : rdtable;
    f = hslider("freq",440,50,2000,0.01);
    process = triangleOsc(f);
  )"""";
  Tree ast = parser.parseString( source, "basicTriangleWaveOscillatorUsingSinPrimitiveAndTimer.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, rwtablePrimitive ) {
  std::string source = R""""(
    process = _ : rwtable(n,s,w,_,r) : _;
  )"""";
  Tree ast = parser.parseString( source, "rwtablePrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, simpleLooper ) {
  std::string source = R""""(
    import("stdfaust.lib");
    tableSize = 48000;
    recIndex = (+(1) : %(tableSize)) ~ *(record);
    readIndex = readSpeed/float(ma.SR) : (+ : ma.frac) ~ _ : *(float(tableSize)) : int;
    readSpeed = hslider("[0]Read Speed",1,0.001,10,0.01);
    record = button("[1]Record") : int;
    looper = rwtable(tableSize,0.0,recIndex,_,readIndex);
    process = looper;
  )"""";
  Tree ast = parser.parseString( source, "simpleLooper.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, select2 ) {
  std::string source = R""""(
    process = _,_ : select2(s) : _;

  )"""";
  Tree ast = parser.parseString( source, "select2.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, signalSelector2 ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = nentry("Selector",0,0,1,1) : int;
    sig = os.osc(440),os.sawtooth(440) : select2(s);
    process = sig;
  )"""";
  Tree ast = parser.parseString( source, "signalSelector2.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, select2inFaust ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = nentry("Selector",0,0,1,1);
    mySelect2(s) = *(s==0),*(s==1) :> _;
    sig = os.osc(440),os.sawtooth(440) : mySelect2(s);
    process = sig;
  )"""";
  Tree ast = parser.parseString( source, "select2inFaust.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, select3 ) {
  std::string source = R""""(
    process = _,_,_ : select3(s) : _;
  )"""";
  Tree ast = parser.parseString( source, "select3.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, signalSelector3 ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = nentry("Selector",0,0,1,1);
    sig = os.osc(440),os.sawtooth(440),os.triangle(440) : select3(s);
    process = sig;
  )"""";
  Tree ast = parser.parseString( source, "signalSelector3.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, select3inFaust ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = nentry("Selector",0,0,2,1) : int;
    mySelect3(s) = *(s==0),*(s==1),*(s==2) :> _;
    sig = os.osc(440),os.sawtooth(440),os.triangle(440) : mySelect3(s);
    process = sig;
  )"""";
  Tree ast = parser.parseString( source, "select3inFaust.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, button ) {
  std::string source = R""""(
    process = button("DC");
  )"""";
  Tree ast = parser.parseString( source, "button.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hslider ) {
  std::string source = R""""(
    process = @(hslider("N",1,1,20,1));
  )"""";
  Tree ast = parser.parseString( source, "hslider.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, buttonPrimitive ) {
  std::string source = R""""(
    process = button("label") : _;
  )"""";
  Tree ast = parser.parseString( source, "buttonPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, buttonTrigger ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = no.noise*button("gate");
  )"""";
  Tree ast = parser.parseString( source, "trigger.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, checkboxPrimitive ) {
  std::string source = R""""(
    process = checkbox("label") : _;
  )"""";
  Tree ast = parser.parseString( source, "checkboxPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, checkboxTrigger ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = no.noise*checkbox("gate");
  )"""";
  Tree ast = parser.parseString( source, "checkboxTrigger.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hsliderPrimitive ) {
  std::string source = R""""(
    process = hslider("label",init,min,max,step) : _;
  )"""";
  Tree ast = parser.parseString( source, "hsliderPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hsliderGainController ) {
  std::string source = R""""(
    gain = hslider("gain",0,0,1,0.01);
    process = *(gain);
  )"""";
  Tree ast = parser.parseString( source, "hsliderGainController.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hsliderAdditiveOscillator ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = par(i,3,os.osc(hslider("Freq%i", 200+i*400, 200, 2000, 1)));
  )"""";
  Tree ast = parser.parseString( source, "hsliderGainController.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, vsliderPrimitive ) {
  std::string source = R""""(
    gain = vslider("gain",0,0,1,0.01);
    process = *(gain);
  )"""";
  Tree ast = parser.parseString( source, "vsliderPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, nentryPrimitive ) {
  std::string source = R""""(
    process = nentry("label",init,min,max,step) : _;
  )"""";
  Tree ast = parser.parseString( source, "nentryPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, nentryGainController ) {
  std::string source = R""""(
    gain = nentry("gain",0,0,1,0.01);
    process = *(gain);
  )"""";
  Tree ast = parser.parseString( source, "nentryGainController.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hgroupPrimitive ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = vslider("freq",440,50,1000,0.1);
    gain = vslider("gain",0,0,1,0.01);
    process = hgroup("Oscillator",os.sawtooth(freq)*gain);
  )"""";
  Tree ast = parser.parseString( source, "hgroupPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hgroupFunction ) {
  std::string source = R""""(
    import("stdfaust.lib");
    oscGroup(x) = hgroup("Oscillator",x);
    freq = oscGroup(vslider("freq",440,50,1000,0.1));
    gain = oscGroup(vslider("gain",0,0,1,0.01));
    process = os.sawtooth(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "hgroupFunction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, vgroupPrimitive ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,1000,0.1);
    gain = hslider("gain",0,0,1,0.01);
    process = vgroup("Oscillator",os.sawtooth(freq)*gain);
  )"""";
  Tree ast = parser.parseString( source, "vgroupPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, vgroupFunction ) {
  std::string source = R""""(
    import("stdfaust.lib");
    oscGroup(x) = vgroup("Oscillator",x);
    freq = oscGroup(hslider("freq",440,50,1000,0.1));
    gain = oscGroup(hslider("gain",0,0,1,0.01));
    process = os.sawtooth(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "vgroupFunction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, tgroupPrimitive ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,1000,0.1);
    gain = hslider("gain",0,0,1,0.01);
    process = tgroup("Oscillator",os.sawtooth(freq)*gain);
  )"""";
  Tree ast = parser.parseString( source, "tgroupPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, tgroupFunction ) {
  std::string source = R""""(
    import("stdfaust.lib");
    oscGroup(x) = tgroup("Oscillator",x);
    freq = oscGroup(hslider("freq",440,50,1000,0.1));
    gain = oscGroup(hslider("gain",0,0,1,0.01));
    process = os.sawtooth(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "tgroupFunction.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, vbargraphPrimitive ) {
  std::string source = R""""(
    process = _ : vbargraph("label",min,max) : _;
  )"""";
  Tree ast = parser.parseString( source, "vbargraphPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, simpleVbargraphVUMeter ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level",-60,0));
  )"""";
  Tree ast = parser.parseString( source, "simpleVbargraphVUMeter.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, hbargraphPrimitive ) {
  std::string source = R""""(
    process = _ : hbargraph("label",min,max) : _;
  )"""";
  Tree ast = parser.parseString( source, "hbargraphPrimitive.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, simpleHbargraphVUMeter ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = _ <: attach(_,abs : ba.linear2db : hbargraph("Level",-60,0));
  )"""";
  Tree ast = parser.parseString( source, "simpleHbargraphVUMeter.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, variableLabelParts ) {
  std::string source = R""""(
    process = par(i,8,hslider("Voice %i",0.9,0,1,0.01));
  )"""";
  Tree ast = parser.parseString( source, "variableLabelParts.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, labelsAsPathnames ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = vslider("h:Oscillator/freq",440,50,1000,0.1);
    gain = vslider("h:Oscillator/gain",0,0,1,0.01);
    process = os.sawtooth(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "variableLabelParts.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, smoothing ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,1000,0.1);
    gain = hslider("gain",0,0,1,0.01);
    process = os.osc(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "smoothing.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, exponentialSmoothing ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = hslider("freq",440,50,1000,0.1) : si.smoo;
    gain = hslider("gain",0,0,1,0.01) : si.smoo;
    process = os.osc(freq)*gain;
  )"""";
  Tree ast = parser.parseString( source, "exponentialSmoothing.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, uiLabelMetadata ) {
  std::string source = R""""(
    process = *(hslider("foo[key1: val 1][key2: val 2]",0,0,1,0.1));
  )"""";
  Tree ast = parser.parseString( source, "uiLabelMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, orderingUIElements ) {
  std::string source = R""""(
    gain = vslider("h:Oscillator/[1]gain",0,0,1,0.01);
    freq = vslider("h:Oscillator/[0]freq",440,50,1000,0.1);
  )"""";
  Tree ast = parser.parseString( source, "orderingUIElements.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, orderingUIElementsOnMultipleLevels ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freqS = vslider("h:Oscillators/h:[0]Sawtooth/[0]freq",440,50,1000,0.1);
    gainS = vslider("h:Oscillators/h:[0]Sawtooth/[1]gain",0,0,1,0.01);
    freqT = vslider("h:Oscillators/h:[1]Triangle/[0]freq",440,50,1000,0.1);
    gainT = vslider("h:Oscillators/h:[1]Triangle/[1]gain",0,0,1,0.01);
    process = os.sawtooth(freqS)*gainS + os.triangle(freqT)*gainT;
  )"""";
  Tree ast = parser.parseString( source, "orderingUIElementsOnMultipleLevels.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, orderingUIElementsOnMultipleLevelsRewritten ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freqS = vslider("[0]freq",440,50,1000,0.1);
    gainS = vslider("[1]gain",0,0,1,0.01);
    freqT = vslider("[0]freq",440,50,1000,0.1);
    gainT = vslider("[1]gain",0,0,1,0.01);
    process = hgroup("Oscillators",
      hgroup("[0]Sawtooth",os.sawtooth(freqS)*gainS) +
      hgroup("[1]Triangle",os.triangle(freqT)*gainT)
    );
  )"""";
  Tree ast = parser.parseString( source, "orderingUIElementsOnMultipleLevelsRewritten.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, globalUIMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = vslider("freq[style:knob]",440,50,1000,0.1);
    process = os.sawtooth(freq);
  )"""";
  Tree ast = parser.parseString( source, "globalUIMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, styleMenuMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = vslider("Signal[style:menu{'Noise':0;'Sawtooth':1}]",0,0,1,1);
    process = select2(s,no.noise,os.sawtooth(440));
  )"""";
  Tree ast = parser.parseString( source, "styleMenuMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, styleRadioMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    s = vslider("Signal[style:radio{'Noise':0;'Sawtooth':1}]",0,0,1,1);
    process = select2(s,no.noise,os.sawtooth(440));
  )"""";
  Tree ast = parser.parseString( source, "styleRadioMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, styleLedMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[style:led]",-60,0));
  )"""";
  Tree ast = parser.parseString( source, "styleLedMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, styleNumbericalMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[style:numerical]",-60,0));
  )"""";
  Tree ast = parser.parseString( source, "styleNumbericalMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, unitDbMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[unit:dB]",-60,0));
  )"""";
  Tree ast = parser.parseString( source, "unitDbMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, unitXxMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = vslider("freq[unit:Hz]",440,50,1000,0.1);
    process = os.sawtooth(freq);
  )"""";
  Tree ast = parser.parseString( source, "unitXxMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, scaleXxMetadata ) {
  std::string source = R""""(
    import("stdfaust.lib");
    freq = vslider("freq[tooltip:The frequency of the oscillator]",440,50,1000,0.1);
    process = os.sawtooth(freq);
  )"""";
  Tree ast = parser.parseString( source, "scaleXxMetadata.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, accelerometerScreenUp ) {
  std::string source = R""""(
    g = nentry("gain[acc: 0 0 -10 0 10]",0.5,0,1,0.01);
  )"""";
  Tree ast = parser.parseString( source, "accelerometerScreenUp.dsp" );
  ASSERT_NE( ast, nullptr );
}

TEST_F( ParserManualExamplesTest, accelerometerLeftSide ) {
  std::string source = R""""(
    g = nentry("gain[acc: 0 0 0 0 10]",0,0,1,0.01);
  )"""";
  Tree ast = parser.parseString( source, "accelerometerLeftSide.dsp" );
  ASSERT_NE( ast, nullptr );
}
