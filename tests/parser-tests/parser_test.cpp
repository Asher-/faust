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

#include <gtest/gtest.h>

#include "global.hh"
#include "compiler/file_handling/sourcereader.hh"
#include "compiler/block_diagram/boxes/boxes.hh"

#include "compiler/parser/driver.hh"

extern global* gGlobal;
extern int yydebug;

struct ParserTest
:
  ::testing::Test
{

    ParserTest
    ()
    {
      global::allocate();
      /* Uncomment for Bison trace output */
//       yydebug = 1;
    }

    virtual
    ~ParserTest

    ()
    {

    }

    SourceReader  sourceReader;
    Driver driver;

};

TEST_F( ParserTest, empty ) {
//  gGlobal->gInputString = R""""()"""";
//  Tree ast = sourceReader.parseString( "Empty.dsp" );
//  ASSERT_EQ( ast, nullptr );
}


//TEST_F( ParserTest, variants ) {
//  gGlobal->gInputString = R""""(
//    singleprecision one = 3.402823466e+38;
//    doubleprecision two = 1.7976931348623158e+308;
//  )"""";
//  Tree ast = sourceReader.parseString( "variants.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, simpleProgram ) {
//  gGlobal->gInputString = R""""(
//    declare name "Noise";
//    declare copyright "(c)GRAME 2018";
//
//    import("stdfaust.lib");
//
//    // noise level controlled by a slider
//    process = no.noise * hslider("gain",0,0,1,0.1);
//  )"""";
//  Tree ast = sourceReader.parseString( "simpleProgram.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, globalMetadata ) {
//  gGlobal->gInputString = R""""(
//    declare name "Noise";
//    declare name "MyProgram";
//    declare author "MySelf";
//    declare copyright "MyCompany";
//    declare version "1.00";
//    declare license "BSD";
//  )"""";
//  Tree ast = sourceReader.parseString( "globalMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, functionMetadata ) {
//  gGlobal->gInputString = R""""(
//    declare add author "John Doe";
//  )"""";
//  Tree ast = sourceReader.parseString( "functionMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, options ) {
//  gGlobal->gInputString = R""""(
//    declare options "[key0:value] [key1:value]";
//  )"""";
//  Tree ast = sourceReader.parseString( "options.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, importStatement ) {
//  gGlobal->gInputString = R""""(import("somefile.dsp");)"""";
//  Tree ast = sourceReader.parseString( "importStatement.dsp" );
//  Tree importStatement = ast->branch(0);
//  Tree fileString = importStatement->branch(0);
//  ASSERT_TRUE( isImportFile(importStatement, fileString) );
//}
//
//TEST_F( ParserTest, mdocEmpty ) {
//  gGlobal->gInputString = R""""(
//    <mdoc></mdoc>
//  )"""";
//  Tree ast = sourceReader.parseString( "mdocEmpty.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, mdoc ) {
//  gGlobal->gInputString = R""""(
//    declare name "Noise";
//    random  = +(12345)~*(1103515245);
//    noise   = random/2147483647.0;
//    <mdoc>
//      <equation>noise</equation>
//      <diagram>noise</diagram>
//      <metadata>name</metadata>
//      </notice>
//      </listing>
//    </mdoc>
//  )"""";
//  Tree ast = sourceReader.parseString( "mdoc.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, simpleDefinition ) {
//  gGlobal->gInputString = R""""(
//    random = +(12345) ~ *(1103515245);
//  )"""";
//  Tree ast = sourceReader.parseString( "simpleDefinition.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, function ) {
//  gGlobal->gInputString = R""""(
//    linear2db(x) = 20*log10(x);
//  )"""";
//  Tree ast = sourceReader.parseString( "function.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, lambda ) {
//  gGlobal->gInputString = R""""(
//    linear2db = \(x).(20*log10(x));
//  )"""";
//  Tree ast = sourceReader.parseString( "lambda.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, patternMatching ) {
//  gGlobal->gInputString = R""""(
//    duplicate(1,x) = x;
//    duplicate(n,x) = x, duplicate(n-1,x);
//  )"""";
//  Tree ast = sourceReader.parseString( "patternMatching.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, patternMatchingCase ) {
//  gGlobal->gInputString = R""""(
//    duplicate = case {
//      (1,x) => x;
//      (n,x) => x, duplicate(n-1,x);
//    };
//  )"""";
//  Tree ast = sourceReader.parseString( "patternMatching.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, duplicate5Generators ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    duplicate(1,x) = x;
//    duplicate(n,x) = x, duplicate(n-1,x);
//    process = duplicate(5,no.noise);
//  )"""";
//  Tree ast = sourceReader.parseString( "duplicate5Generators.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, countListElements ) {
//  gGlobal->gInputString = R""""(
//    count((x,xs)) = 1+count(xs);
//    count(x) = 1;
//  )"""";
//  Tree ast = sourceReader.parseString( "countListElements.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, oscillatorsInParallel ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = os.osc(440),os.sawtooth(550),os.triangle(660);
//  )"""";
//  Tree ast = sourceReader.parseString( "oscillatorsInParallel.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, stereoEffect ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    level = 1;
//    process = ve.autowah(level),ve.autowah(level);
//  )"""";
//  Tree ast = sourceReader.parseString( "stereoEffect.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, stereoEffectParIteration ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    level = 1;
//    process = par(i,2,ve.autowah(level));
//  )"""";
//  Tree ast = sourceReader.parseString( "stereoEffectParIteration.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sequentialCompositionSineOscillator ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = 440 : os.osc;
//  )"""";
//  Tree ast = sourceReader.parseString( "sequentialCompositionSineOscillator.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sequentialCompositionEffectChain ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    drive = 0.6;
//    offset = 0;
//    autoWahLevel = 1;
//    process = ef.cubicnl(drive,offset) : ve.autowah(autoWahLevel);
//  )"""";
//  Tree ast = sourceReader.parseString( "sequentialCompositionEffectChain.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, splitCompositionDuplicatingOscillatorOutput ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = os.sawtooth(440) <: _,_,_;
//  )"""";
//  Tree ast = sourceReader.parseString( "splitCompositionDuplicatingOscillatorOutput.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, splitCompositionConnectingMonoToStereo ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    drive = 0.6;
//    offset = 0;
//    process = ef.cubicnl(drive,offset) <: dm.zita_light;
//  )"""";
//  Tree ast = sourceReader.parseString( "splitCompositionConnectingMonoToStereo.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, splitCompositionArbitrarySignals ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    drive = 0.6;
//    offset = 0;
//    process = par(i,2,ef.cubicnl(drive,offset)) <: par(i,2,dm.zita_light);
//  )"""";
//  Tree ast = sourceReader.parseString( "splitCompositionArbitrarySignals.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, mergeCompositionSummingSignalsAdditiveSynthesis ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,3000,0.01);
//    gain = hslider("gain",1,0,1,0.01);
//    gate = button("gate");
//    envelope = gain*gate : si.smoo;
//    process = os.osc(freq),os.osc(freq*2),os.osc(freq*3) :> /(3)*envelope;
//  )"""";
//  Tree ast = sourceReader.parseString( "mergeCompositionSummingSignalsAdditiveSynthesis.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, mergeCompositionSummingSignalsAdditiveSynthesisAlternative ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,3000,0.01);
//    gain = hslider("gain",1,0,1,0.01);
//    gate = button("gate");
//    envelope = gain*gate : si.smoo;
//    process = (os.osc(freq) + os.osc(freq*2) + os.osc(freq*3))/(3)*envelope;
//  )"""";
//  Tree ast = sourceReader.parseString( "mergeCompositionSummingSignalsAdditiveSynthesis.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, mergeCompositionConnectingStereoToMono ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    drive = 0.6;
//    offset = 0;
//    process = dm.zita_light :> ef.cubicnl(drive,offset);
//  )"""";
//  Tree ast = sourceReader.parseString( "mergeCompositionConnectingStereoToMono.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, mergeCompositionConnectingStereoToMonoArbitrarySplit ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    drive = 0.6;
//    offset = 0;
//    process = par(i,2,dm.zita_light) :> par(i,2,ef.cubicnl(drive,offset));
//  )"""";
//  Tree ast = sourceReader.parseString( "mergeCompositionConnectingStereoToMonoArbitrarySplit.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, recursiveCompositionTimer ) {
//  gGlobal->gInputString = R""""(
//    process = _~+(1);
//  )"""";
//  Tree ast = sourceReader.parseString( "recursiveCompositionTimer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, recursiveCompositionOnePoleFilter ) {
//  gGlobal->gInputString = R""""(
//    a1 = 0.999; // the pole
//    process = +~*(a1);
//  )"""";
//  Tree ast = sourceReader.parseString( "recursiveCompositionOnePoleFilter.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, numberOfOutputs ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = outputs(os.osc(440));
//  )"""";
//  Tree ast = sourceReader.parseString( "numberOfOutputs.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, reverseOrderOfOutputs ) {
//  gGlobal->gInputString = R""""(
//    Xo(expr) = expr <: par(i,n,ba.selector(n-i-1,n))
//    with {
//      n = outputs(expr);
//    };
//  )"""";
//  Tree ast = sourceReader.parseString( "reverseOrderOfOutputs.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, reverseOrderOfInputs ) {
//  gGlobal->gInputString = R""""(
//    Xi(expr) = si.bus(n) <: par(i,n,ba.selector(n-i-1,n)) : expr
//    with {
//      n = inputs(expr);
//    };
//  )"""";
//  Tree ast = sourceReader.parseString( "reverseOrderOfInputs.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, reverseTwoInputs ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    Xi(expr) = si.bus(n) <: par(i,n,ba.selector(n-i-1,n)) : expr
//    with {
//      n = inputs(expr);
//    };
//    process = Xi(-);
//
//  )"""";
//  Tree ast = sourceReader.parseString( "reverseTwoInputs.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, parallelIterationSimpleAdditiveSynthesizer ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,3000,0.01);
//    gain = hslider("gain",1,0,1,0.01);
//    gate = button("gate");
//    envelope = gain*gate : si.smoo;
//    nHarmonics = 4;
//    process = par(i,nHarmonics,os.osc(freq*(i+1))) :> /(nHarmonics)*envelope;
//  )"""";
//  Tree ast = sourceReader.parseString( "parallelIterationSimpleAdditiveSynthesizer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sequenceIterationPeakEqualizer ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    nBands = 8;
//    filterBank(N) = hgroup("Filter Bank",seq(i,N,oneBand(i)))
//    with {
//        oneBand(j) = vgroup("[%j]Band %a",fi.peak_eq(l,f,b))
//        with {
//            a = j+1; // just so that band numbers don't start at 0
//            l = vslider("[2]Level[unit:db]",0,-70,12,0.01) : si.smoo;
//            f = nentry("[1]Freq",(80+(1000*8/N*(j+1)-80)),20,20000,0.01) : si.smoo;
//            b = f/hslider("[0]Q[style:knob]",1,1,50,0.01) : si.smoo;
//        };
//    };
//    process = filterBank(nBands);
//  )"""";
//  Tree ast = sourceReader.parseString( "sequenceIterationPeakEqualizer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sumIterationSimpleAdditiveSynthesizer ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,3000,0.01);
//    gain = hslider("gain",1,0,1,0.01);
//    gate = button("gate");
//    envelope = gain*gate : si.smoo;
//    nHarmonics = 4;
//    process = sum(i,nHarmonics,os.osc(freq*(i+1)))/(nHarmonics)*envelope;
//  )"""";
//  Tree ast = sourceReader.parseString( "sumIterationSimpleAdditiveSynthesizer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, productIterationAmplitudeModulationSynthesizer ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("[0]freq",440,50,3000,0.01);
//    gain = hslider("[1]gain",1,0,1,0.01);
//    shift = hslider("[2]shift",0,0,1,0.01);
//    gate = button("[3]gate");
//    envelope = gain*gate : si.smoo;
//    nOscs = 4;
//    process = prod(i,nOscs,os.osc(freq*(i+1+shift)))*envelope;
//  )"""";
//  Tree ast = sourceReader.parseString( "productIterationAmplitudeModulationSynthesizer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, partialApplicationGainController ) {
//  gGlobal->gInputString = R""""(
//    gain = hslider("gain",0.5,0,1,0.01);
//    process = *(gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "partialApplicationGainController.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, timeExpression ) {
//  gGlobal->gInputString = R""""(
//    process = _';
//  )"""";
//  Tree ast = sourceReader.parseString( "timeExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, timeExpressionChain ) {
//  gGlobal->gInputString = R""""(
//    process = 1'';
//  )"""";
//  Tree ast = sourceReader.parseString( "timeExpressionChain.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, atTimeExpression ) {
//  gGlobal->gInputString = R""""(
//    process = @(10);
//  )"""";
//  Tree ast = sourceReader.parseString( "atTimeExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, delaySlider ) {
//  gGlobal->gInputString = R""""(
//    process = @(hslider("delay",0,0,100,1));
//  )"""";
//  Tree ast = sourceReader.parseString( "delaySlider.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, withExpression ) {
//  gGlobal->gInputString = R""""(
//    pink = f : + ~ g
//    with {
//      f(x) = 0.04957526213389*x - 0.06305581334498*x' + 0.01483220320740*x'';
//      g(x) = 1.80116083982126*x - 0.80257737639225*x';
//    };
//    process = pink;
//  )"""";
//  Tree ast = sourceReader.parseString( "withExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, letrecExpression ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    ar(a,r,g) = v
//    letrec {
//      'n = (n+1) * (g<=g');
//      'v = max(0, v + (n<a)/a - (n>=a)/r) * (g<=g');
//    };
//    gate = button("gate");
//    process = os.osc(440)*ar(1000,1000,gate);
//  )"""";
//  Tree ast = sourceReader.parseString( "letrecExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, letrecExpressionFactorized ) {
//  gGlobal->gInputString = R""""(
//    ar(a,r,g) = v letrec {
//    'n = (n+1) * c;
//    'v = max(0, v + (n<a)/a - (n>=a)/r) * c;
//    where
//        c = g<=g';
//    };
//  )"""";
//  Tree ast = sourceReader.parseString( "letrecExpressionFactorized.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, environmentExpression ) {
//  gGlobal->gInputString = R""""(
//    constant = environment {
//      pi = 3.14159;
//      e = 2,718;
//    };
//  )"""";
//  Tree ast = sourceReader.parseString( "environmentExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, accessExpression ) {
//  gGlobal->gInputString = R""""(
//    access = environment{pi = 3.14159; e = 2,718;}.pi;
//  )"""";
//  Tree ast = sourceReader.parseString( "accessExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, libraryExpression ) {
//  gGlobal->gInputString = R""""(
//    import("filters.lib");
//  )"""";
//  Tree ast = sourceReader.parseString( "libraryExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, componentExpression ) {
//  gGlobal->gInputString = R""""(
//    freeverb = component("../examples/reverb/freeverb.dsp");
//  )"""";
//  Tree ast = sourceReader.parseString( "componentExpression.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, explicitSubstitution ) {
//  gGlobal->gInputString = R""""(
//    freeverb = component("../examples/reverb/freeverb.dsp")[foo(x) = 2;];
//  )"""";
//  Tree ast = sourceReader.parseString( "explicitSubstitution.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, ffunction ) {
//  gGlobal->gInputString = R""""(
//    asinh = ffunction(float asinh (float), <math.h>, "");
//  )"""";
//  Tree ast = sourceReader.parseString( "explicitSubstitution.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, polymorphicffunction ) {
//  gGlobal->gInputString = R""""(
//    sizeof = ffunction(int sizeof(any), "","");
//  )"""";
//  Tree ast = sourceReader.parseString( "polymorphicffunction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, foreignVariablesAndConstants ) {
//  gGlobal->gInputString = R""""(
//    SR = min(192000.0,max(1.0,fconstant(int fSamplingFreq, <math.h>)));
//    BS = fvariable(int count, <math.h>);
//  )"""";
//  Tree ast = sourceReader.parseString( "polymorphicffunction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, monoReverb ) {
//  gGlobal->gInputString = R""""(
//    reverb = _ <: dm.zita_light :> _;
//  )"""";
//  Tree ast = sourceReader.parseString( "monoReverb.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, monoReverbAbstraction ) {
//  gGlobal->gInputString = R""""(
//    abstraction = \(zita_light).(_ <: zita_light :> _);
//  )"""";
//  Tree ast = sourceReader.parseString( "monoReverbAbstraction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, monoReverbAbstractionApplied ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    mono = \(fx).(_ <: fx :> _);
//    process = mono(dm.zita_light);
//  )"""";
//  Tree ast = sourceReader.parseString( "monoReverbAbstractionApplied.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, monoReverbAbstractionAppliedTraditionalNotation ) {
//  gGlobal->gInputString = R""""(
//    mono(fx) = _ <: fx :> _;
//  )"""";
//  Tree ast = sourceReader.parseString( "monoReverbAbstractionApplied.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, patternMatchingReverb ) {
//  gGlobal->gInputString = R""""(
//    match = case{(x:y) => y:x; (x) => x;}(reverb : harmonizer);
//  )"""";
//  Tree ast = sourceReader.parseString( "patternMatchingReverb.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, routePrimitiveCrossTwoSignals ) {
//  gGlobal->gInputString = R""""(
//    process = route(2,2,1,2,2,1);
//  )"""";
//  Tree ast = sourceReader.parseString( "routePrimitiveCrossTwoSignals.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, routePrimitiveCrossTwoSignals2 ) {
//  gGlobal->gInputString = R""""(
//    process = route(2,2,(1,2),(2,1));
//  )"""";
//  Tree ast = sourceReader.parseString( "routePrimitiveCrossTwoSignals2.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, routePrimitiveCrossNSignals ) {
//  gGlobal->gInputString = R""""(
//    // cross 10 signals:
//    // input 0 -> output 10,
//    // input 1 -> output 9,
//    // ...,
//    // input 9 -> output 0
//
//    N = 10;
//    r = route(N,N,par(i,N,(i+1,N-i)));
//
//    process = r;
//  )"""";
//  Tree ast = sourceReader.parseString( "routePrimitiveCrossNSignals.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, waveformPrimitive ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    triangleWave = waveform{0,0.5,1,0.5,0,-0.5,-1,-.5};
//    triangleOsc(f) = triangleWave,int(os.phasor(8,f)) : rdtable;
//    f = hslider("freq",440,50,2000,0.01);
//    process = triangleOsc(f);
//  )"""";
//  Tree ast = sourceReader.parseString( "waveformPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, soundfilePrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0,_~+(1):soundfile("son[url:{'../tests/architecture-tests/s1.wav'}]",2):!,!,_,_;
//  )"""";
//  Tree ast = sourceReader.parseString( "soundfilePrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, addProcess ) {
//  gGlobal->gInputString = R""""(
//    process = +;
//  )"""";
//  Tree ast = sourceReader.parseString( "addProcess.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, signalToTupleTransformer ) {
//  gGlobal->gInputString = R""""(
//    process = _+_;
//  )"""";
//  Tree ast = sourceReader.parseString( "signalToTupleTransformer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, integerNumber ) {
//  gGlobal->gInputString = R""""(
//    process = 1;
//  )"""";
//  Tree ast = sourceReader.parseString( "integerNumber.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, floatNumber ) {
//  gGlobal->gInputString = R""""(
//    process = 0.5;
//  )"""";
//  Tree ast = sourceReader.parseString( "floatNumber.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, identity ) {
//  gGlobal->gInputString = R""""(
//    process = _;
//  )"""";
//  Tree ast = sourceReader.parseString( "identity.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, cutPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 1,2 : !,_;
//  )"""";
//  Tree ast = sourceReader.parseString( "cutPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, intPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 1.5 : int;
//  )"""";
//  Tree ast = sourceReader.parseString( "intPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, floatPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 1.5 : float;
//  )"""";
//  Tree ast = sourceReader.parseString( "floatPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, addPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = +;
//  )"""";
//  Tree ast = sourceReader.parseString( "addPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, subtractPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = -;
//  )"""";
//  Tree ast = sourceReader.parseString( "subtractPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, multiplyPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = *(0.5);
//  )"""";
//  Tree ast = sourceReader.parseString( "multiplyPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, dividePrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = /(2);
//  )"""";
//  Tree ast = sourceReader.parseString( "dividePrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, powerPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = ^(2);
//  )"""";
//  Tree ast = sourceReader.parseString( "powerPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, moduloPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _~+(1) : -(1) : %(10);
//  )"""";
//  Tree ast = sourceReader.parseString( "moduloPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, andPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ <: <(0.5) & >(0.7);
//  )"""";
//  Tree ast = sourceReader.parseString( "andPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, orPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ <: <(0.5) | >(0.7);
//  )"""";
//  Tree ast = sourceReader.parseString( "orPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, xorPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ <: <(0.5) xor >(0.7);
//  )"""";
//  Tree ast = sourceReader.parseString( "xorPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, leftShift ) {
//  gGlobal->gInputString = R""""(
//    process = 1 << 2;
//  )"""";
//  Tree ast = sourceReader.parseString( "leftShift.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, rightShift ) {
//  gGlobal->gInputString = R""""(
//    process = 1 >> 2;
//  )"""";
//  Tree ast = sourceReader.parseString( "rightShift.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, smallerThanPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = <(0.5);
//  )"""";
//  Tree ast = sourceReader.parseString( "smallerThanPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, smallerThanOrEqualToPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = <=(0.5);
//  )"""";
//  Tree ast = sourceReader.parseString( "smallerThanOrEqualToPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, greaterThanPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = >(0.5);
//  )"""";
//  Tree ast = sourceReader.parseString( "greaterThanPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, greaterThanOrEqualToPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = >=(0.5);
//  )"""";
//  Tree ast = sourceReader.parseString( "greaterThanOrEqualToPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, equalToPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0 == 1;
//  )"""";
//  Tree ast = sourceReader.parseString( "equalToPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, notEqualToPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0 != 1;
//  )"""";
//  Tree ast = sourceReader.parseString( "notEqualToPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, acosPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : acos;
//  )"""";
//  Tree ast = sourceReader.parseString( "acosPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, atanPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : atan;
//  )"""";
//  Tree ast = sourceReader.parseString( "atanPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, atan2Primitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1,-0.1 : atan2;
//  )"""";
//  Tree ast = sourceReader.parseString( "atan2Primitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, cosPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : cos;
//  )"""";
//  Tree ast = sourceReader.parseString( "cosPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sinPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : sin;
//  )"""";
//  Tree ast = sourceReader.parseString( "sinPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, expPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : exp;
//  )"""";
//  Tree ast = sourceReader.parseString( "expPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, logPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : log;
//  )"""";
//  Tree ast = sourceReader.parseString( "logPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, log10Primitive ) {
//  gGlobal->gInputString = R""""(
//    process = 0.1 : log10;
//  )"""";
//  Tree ast = sourceReader.parseString( "log10Primitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, powPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 2,4 : pow;
//  )"""";
//  Tree ast = sourceReader.parseString( "powPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, sqrtPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 4 : sqrt;
//  )"""";
//  Tree ast = sourceReader.parseString( "sqrtPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, absPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = -0.5 : abs;
//  )"""";
//  Tree ast = sourceReader.parseString( "absPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, minPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = -0.5,0.2 : min;
//  )"""";
//  Tree ast = sourceReader.parseString( "minPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, maxPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = -0.5,0.2 : max;
//  )"""";
//  Tree ast = sourceReader.parseString( "maxPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, fmodPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 5.3,2 : fmod;
//  )"""";
//  Tree ast = sourceReader.parseString( "fmodPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, remainderPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 5.3,2 : remainder;
//  )"""";
//  Tree ast = sourceReader.parseString( "remainderPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, floorPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 3.6 : floor;
//  )"""";
//  Tree ast = sourceReader.parseString( "floorPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, ceilPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 3.6 : ceil;
//  )"""";
//  Tree ast = sourceReader.parseString( "ceilPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, rintPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = 3.6 : rint;
//  )"""";
//  Tree ast = sourceReader.parseString( "rintPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, memPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = mem;
//  )"""";
//  Tree ast = sourceReader.parseString( "memPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, delayTickPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _';
//  )"""";
//  Tree ast = sourceReader.parseString( "delayTick.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, atPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ : @(N) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "atPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, staticNSampleDelay ) {
//  gGlobal->gInputString = R""""(
//    N = 10;
//    process = @(N);
//  )"""";
//  Tree ast = sourceReader.parseString( "staticNSampleDelay.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, dynamicNSampleDelay ) {
//  gGlobal->gInputString = R""""(
//    N = hslider("N",10,1,10,1);
//    process = @(N);
//  )"""";
//  Tree ast = sourceReader.parseString( "dynamicNSampleDelay.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, rdtablePrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = rdtable(n,s,r) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "rdtablePrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, basicTriangleWaveOscillatorUsingWaveformPrimitive ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    triangleWave = waveform{0,0.5,1,0.5,0,-0.5,-1,-.5};
//    triangleOsc(f) = triangleWave,int(os.phasor(8,f)) : rdtable;
//    f = hslider("freq",440,50,2000,0.01);
//    process = triangleOsc(f);
//  )"""";
//  Tree ast = sourceReader.parseString( "basicTriangleWaveOscillatorUsingWaveformPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, basicTriangleWaveOscillatorUsingSinPrimitiveAndTimer ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    tableSize = 1 << 16;
//    sineWave(tablesize) = float(ba.time)*(2.0*ma.PI)/float(tablesize) : sin;
//    triangleOsc(f) = tableSize,sineWave(tableSize),int(os.phasor(tableSize,f)) : rdtable;
//    f = hslider("freq",440,50,2000,0.01);
//    process = triangleOsc(f);
//  )"""";
//  Tree ast = sourceReader.parseString( "basicTriangleWaveOscillatorUsingSinPrimitiveAndTimer.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, rwtablePrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ : rwtable(n,s,w,_,r) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "rwtablePrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, simpleLooper ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    tableSize = 48000;
//    recIndex = (+(1) : %(tableSize)) ~ *(record);
//    readIndex = readSpeed/float(ma.SR) : (+ : ma.frac) ~ _ : *(float(tableSize)) : int;
//    readSpeed = hslider("[0]Read Speed",1,0.001,10,0.01);
//    record = button("[1]Record") : int;
//    looper = rwtable(tableSize,0.0,recIndex,_,readIndex);
//    process = looper;
//  )"""";
//  Tree ast = sourceReader.parseString( "simpleLooper.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, select2 ) {
//  gGlobal->gInputString = R""""(
//    process = _,_ : select2(s) : _;
//
//  )"""";
//  Tree ast = sourceReader.parseString( "select2.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, signalSelector2 ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = nentry("Selector",0,0,1,1) : int;
//    sig = os.osc(440),os.sawtooth(440) : select2(s);
//    process = sig;
//  )"""";
//  Tree ast = sourceReader.parseString( "signalSelector2.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, select2inFaust ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = nentry("Selector",0,0,1,1);
//    mySelect2(s) = *(s==0),*(s==1) :> _;
//    sig = os.osc(440),os.sawtooth(440) : mySelect2(s);
//    process = sig;
//  )"""";
//  Tree ast = sourceReader.parseString( "select2inFaust.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, select3 ) {
//  gGlobal->gInputString = R""""(
//    process = _,_,_ : select3(s) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "select3.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, signalSelector3 ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = nentry("Selector",0,0,1,1);
//    sig = os.osc(440),os.sawtooth(440),os.triangle(440) : select3(s);
//    process = sig;
//  )"""";
//  Tree ast = sourceReader.parseString( "signalSelector3.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, select3inFaust ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = nentry("Selector",0,0,2,1) : int;
//    mySelect3(s) = *(s==0),*(s==1),*(s==2) :> _;
//    sig = os.osc(440),os.sawtooth(440),os.triangle(440) : mySelect3(s);
//    process = sig;
//  )"""";
//  Tree ast = sourceReader.parseString( "select3inFaust.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, button ) {
//  gGlobal->gInputString = R""""(
//    process = button("DC");
//  )"""";
//  Tree ast = sourceReader.parseString( "button.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hslider ) {
//  gGlobal->gInputString = R""""(
//    process = @(hslider("N",1,1,20,1));
//  )"""";
//  Tree ast = sourceReader.parseString( "hslider.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, buttonPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = button("label") : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "buttonPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, buttonTrigger ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = no.noise*button("gate");
//  )"""";
//  Tree ast = sourceReader.parseString( "trigger.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, checkboxPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = checkbox("label") : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "checkboxPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, checkboxTrigger ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = no.noise*checkbox("gate");
//  )"""";
//  Tree ast = sourceReader.parseString( "checkboxTrigger.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hsliderPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = hslider("label",init,min,max,step) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "hsliderPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hsliderGainController ) {
//  gGlobal->gInputString = R""""(
//    gain = hslider("gain",0,0,1,0.01);
//    process = *(gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "hsliderGainController.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hsliderAdditiveOscillator ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = par(i,3,os.osc(hslider("Freq%i", 200+i*400, 200, 2000, 1)));
//  )"""";
//  Tree ast = sourceReader.parseString( "hsliderGainController.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, vsliderPrimitive ) {
//  gGlobal->gInputString = R""""(
//    gain = vslider("gain",0,0,1,0.01);
//    process = *(gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "vsliderPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, nentryPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = nentry("label",init,min,max,step) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "nentryPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, nentryGainController ) {
//  gGlobal->gInputString = R""""(
//    gain = nentry("gain",0,0,1,0.01);
//    process = *(gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "nentryGainController.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hgroupPrimitive ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = vslider("freq",440,50,1000,0.1);
//    gain = vslider("gain",0,0,1,0.01);
//    process = hgroup("Oscillator",os.sawtooth(freq)*gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "hgroupPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hgroupFunction ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    oscGroup(x) = hgroup("Oscillator",x);
//    freq = oscGroup(vslider("freq",440,50,1000,0.1));
//    gain = oscGroup(vslider("gain",0,0,1,0.01));
//    process = os.sawtooth(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "hgroupFunction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, vgroupPrimitive ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,1000,0.1);
//    gain = hslider("gain",0,0,1,0.01);
//    process = vgroup("Oscillator",os.sawtooth(freq)*gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "vgroupPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, vgroupFunction ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    oscGroup(x) = vgroup("Oscillator",x);
//    freq = oscGroup(hslider("freq",440,50,1000,0.1));
//    gain = oscGroup(hslider("gain",0,0,1,0.01));
//    process = os.sawtooth(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "vgroupFunction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, tgroupPrimitive ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,1000,0.1);
//    gain = hslider("gain",0,0,1,0.01);
//    process = tgroup("Oscillator",os.sawtooth(freq)*gain);
//  )"""";
//  Tree ast = sourceReader.parseString( "tgroupPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, tgroupFunction ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    oscGroup(x) = tgroup("Oscillator",x);
//    freq = oscGroup(hslider("freq",440,50,1000,0.1));
//    gain = oscGroup(hslider("gain",0,0,1,0.01));
//    process = os.sawtooth(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "tgroupFunction.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, vbargraphPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ : vbargraph("label",min,max) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "vbargraphPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, simpleVbargraphVUMeter ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level",-60,0));
//  )"""";
//  Tree ast = sourceReader.parseString( "simpleVbargraphVUMeter.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, hbargraphPrimitive ) {
//  gGlobal->gInputString = R""""(
//    process = _ : hbargraph("label",min,max) : _;
//  )"""";
//  Tree ast = sourceReader.parseString( "hbargraphPrimitive.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, simpleHbargraphVUMeter ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = _ <: attach(_,abs : ba.linear2db : hbargraph("Level",-60,0));
//  )"""";
//  Tree ast = sourceReader.parseString( "simpleHbargraphVUMeter.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, variableLabelParts ) {
//  gGlobal->gInputString = R""""(
//    process = par(i,8,hslider("Voice %i",0.9,0,1,0.01));
//  )"""";
//  Tree ast = sourceReader.parseString( "variableLabelParts.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, labelsAsPathnames ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = vslider("h:Oscillator/freq",440,50,1000,0.1);
//    gain = vslider("h:Oscillator/gain",0,0,1,0.01);
//    process = os.sawtooth(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "variableLabelParts.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, smoothing ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,1000,0.1);
//    gain = hslider("gain",0,0,1,0.01);
//    process = os.osc(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "smoothing.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, exponentialSmoothing ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = hslider("freq",440,50,1000,0.1) : si.smoo;
//    gain = hslider("gain",0,0,1,0.01) : si.smoo;
//    process = os.osc(freq)*gain;
//  )"""";
//  Tree ast = sourceReader.parseString( "exponentialSmoothing.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, uiLabelMetadata ) {
//  gGlobal->gInputString = R""""(
//    process = *(hslider("foo[key1: val 1][key2: val 2]",0,0,1,0.1));
//  )"""";
//  Tree ast = sourceReader.parseString( "uiLabelMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, orderingUIElements ) {
//  gGlobal->gInputString = R""""(
//    gain = vslider("h:Oscillator/[1]gain",0,0,1,0.01);
//    freq = vslider("h:Oscillator/[0]freq",440,50,1000,0.1);
//  )"""";
//  Tree ast = sourceReader.parseString( "orderingUIElements.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, orderingUIElementsOnMultipleLevels ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freqS = vslider("h:Oscillators/h:[0]Sawtooth/[0]freq",440,50,1000,0.1);
//    gainS = vslider("h:Oscillators/h:[0]Sawtooth/[1]gain",0,0,1,0.01);
//    freqT = vslider("h:Oscillators/h:[1]Triangle/[0]freq",440,50,1000,0.1);
//    gainT = vslider("h:Oscillators/h:[1]Triangle/[1]gain",0,0,1,0.01);
//    process = os.sawtooth(freqS)*gainS + os.triangle(freqT)*gainT;
//  )"""";
//  Tree ast = sourceReader.parseString( "orderingUIElementsOnMultipleLevels.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, orderingUIElementsOnMultipleLevelsRewritten ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freqS = vslider("[0]freq",440,50,1000,0.1);
//    gainS = vslider("[1]gain",0,0,1,0.01);
//    freqT = vslider("[0]freq",440,50,1000,0.1);
//    gainT = vslider("[1]gain",0,0,1,0.01);
//    process = hgroup("Oscillators",
//      hgroup("[0]Sawtooth",os.sawtooth(freqS)*gainS) +
//      hgroup("[1]Triangle",os.triangle(freqT)*gainT)
//    );
//  )"""";
//  Tree ast = sourceReader.parseString( "orderingUIElementsOnMultipleLevelsRewritten.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, globalUIMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = vslider("freq[style:knob]",440,50,1000,0.1);
//    process = os.sawtooth(freq);
//  )"""";
//  Tree ast = sourceReader.parseString( "globalUIMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, styleMenuMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = vslider("Signal[style:menu{'Noise':0;'Sawtooth':1}]",0,0,1,1);
//    process = select2(s,no.noise,os.sawtooth(440));
//  )"""";
//  Tree ast = sourceReader.parseString( "styleMenuMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, styleRadioMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    s = vslider("Signal[style:radio{'Noise':0;'Sawtooth':1}]",0,0,1,1);
//    process = select2(s,no.noise,os.sawtooth(440));
//  )"""";
//  Tree ast = sourceReader.parseString( "styleRadioMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, styleLedMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[style:led]",-60,0));
//  )"""";
//  Tree ast = sourceReader.parseString( "styleLedMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, styleNumbericalMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[style:numerical]",-60,0));
//  )"""";
//  Tree ast = sourceReader.parseString( "styleNumbericalMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, unitDbMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    process = _ <: attach(_,abs : ba.linear2db : vbargraph("Level[unit:dB]",-60,0));
//  )"""";
//  Tree ast = sourceReader.parseString( "unitDbMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, unitXxMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = vslider("freq[unit:Hz]",440,50,1000,0.1);
//    process = os.sawtooth(freq);
//  )"""";
//  Tree ast = sourceReader.parseString( "unitXxMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, scaleXxMetadata ) {
//  gGlobal->gInputString = R""""(
//    import("stdfaust.lib");
//    freq = vslider("freq[tooltip:The frequency of the oscillator]",440,50,1000,0.1);
//    process = os.sawtooth(freq);
//  )"""";
//  Tree ast = sourceReader.parseString( "scaleXxMetadata.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, accelerometerScreenUp ) {
//  gGlobal->gInputString = R""""(
//    g = nentry("gain[acc: 0 0 -10 0 10]",0.5,0,1,0.01);
//  )"""";
//  Tree ast = sourceReader.parseString( "accelerometerScreenUp.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
//
//TEST_F( ParserTest, accelerometerLeftSide ) {
//  gGlobal->gInputString = R""""(
//    g = nentry("gain[acc: 0 0 0 0 10]",0,0,1,0.01);
//  )"""";
//  Tree ast = sourceReader.parseString( "accelerometerLeftSide.dsp" );
//  ASSERT_NE( ast, nullptr );
//}

  /******************** Error Handling ********************/

//TEST_F( ParserTest, missingSemicolon ) {
//  gGlobal->gInputString = R""""(
//    g = nentry("gain[acc: 0 0 0 0 10]",0,0,1,0.01)
//    process = g;
//  )"""";
//  Tree ast = sourceReader.parseString( "missingSemicolon.dsp" );
//  ASSERT_NE( ast, nullptr );
//}
