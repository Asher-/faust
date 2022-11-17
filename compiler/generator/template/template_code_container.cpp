/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2022 GRAME, Centre National de Creation Musicale
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

#include "template_code_container.hh"
#include "Text.hh"
#include "exception.hh"
#include "fir_function_builder.hh"
#include "floats.hh"
#include "global.hh"

using namespace std;

map<string, bool> TemplateInstVisitor::gFunctionSymbolTable;

dsp_factory_base* TemplateCodeContainer::produceFactory()
{
    return new text_dsp_factory_aux(
        fKlassName, "", "",
        ((dynamic_cast<ostringstream*>(fOut)) ? dynamic_cast<ostringstream*>(fOut)->str() : ""), "");
}

TemplateCodeContainer::TemplateCodeContainer(const std::string& name, int numInputs, int numOutputs, std::ostream* out)
{
    // Mandatory
    initialize(numInputs, numOutputs);
    fKlassName = name;
    fOut = out;
    
    // Allocate one static visitor
    if (!global::config().gTemplateVisitor) {
        global::config().gTemplateVisitor = new TemplateInstVisitor(out, name);
    }
}

CodeContainer* TemplateCodeContainer::createScalarContainer(const string& name, int sub_container_type)
{
    return new TemplateScalarCodeContainer(name, 0, 1, fOut, sub_container_type);
}

/*
    The given template implements -scalar (= default) and -vec mode.
    For  options like -omp, -sch, the corresponding TemplateOpenMPCodeContainer
    and TemplateWorkStealingCodeContainer classes would have to be implemented
    and activated.
*/
CodeContainer* TemplateCodeContainer::createContainer(const string& name, int numInputs, int numOutputs, ostream* dst)
{
    global::config().gDSPStruct = true;
    CodeContainer* container;

    if (global::config().gOpenCLSwitch) {
        throw faustexception("ERROR : OpenCL not supported for Template\n");
    }
    if (global::config().gCUDASwitch) {
        throw faustexception("ERROR : CUDA not supported for Template\n");
    }

    if (global::config().gOpenMPSwitch) {
        throw faustexception("ERROR : OpenMP not supported for Template\n");
    } else if (global::config().gSchedulerSwitch) {
        throw faustexception("ERROR : Scheduler not supported for Template\n");
    } else if (global::config().gVectorSwitch) {
        container = new TemplateVectorCodeContainer(name, numInputs, numOutputs, dst);
    } else {
        container = new TemplateScalarCodeContainer(name, numInputs, numOutputs, dst, kInt);
    }

    return container;
}

// Used for subcontainers if 'inlining sub containers' model is not used
void TemplateCodeContainer::produceInternal()
{}

/*
 Given as an example of what a real backend would have to do: add or remove FIR visiting code etc.
*/
void TemplateCodeContainer::produceClass()
{
    int n = 0;
    *fOut << "TemplateCodeContainer::produceClass\n";
    
    // Print header
    
    // Possibly missing mathematical functions
    
    // Possibly merge sub containers (with an empty 'produceInternal' method)
    // mergeSubContainers();

    // Functions
    /*
    // Only generate globals functions
    for (const auto& it : fGlobalDeclarationInstructions->fCode) {
        if (dynamic_cast<DeclareFunInst*>(it)) {
            it->accept(global::config().gTemplateVisitor);
        }
    }
    */
    
    // Fields
    /*
    generateDeclarations(global::config().gTemplateVisitor);
    // Generate global variables definition
    for (const auto& it : fGlobalDeclarationInstructions->fCode) {
        if (dynamic_cast<DeclareVarInst*>(it)) {
            it->accept(global::config().gTemplateVisitor);
        }
    }
    */
    
    /*
    TemplateInitFieldsVisitor initializer(fOut, n + 2);
    generateDeclarations(&initializer);
    // Generate global variables initialisation
    for (const auto& it : fGlobalDeclarationInstructions->fCode) {
        if (dynamic_cast<DeclareVarInst*>(it)) {
            it->accept(&initializer);
        }
    }
    */
    
    // Print metadata declaration
    // produceMetadata(n);

    // getSampleRate
    // generateGetSampleRate("getSampleRate", "dsp", false, false)->accept(global::config().gTemplateVisitor);
  
    // Info functions: getNumInputs/getNumOuputs
    
    // classInit
    // TODO if mergeSubContainers() is used
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    // inlineSubcontainersFunCalls(fStaticInitInstructions)->accept(global::config().gTemplateVisitor);
    
    // instanceResetUserInterface
    // generateResetUserInterface(global::config().gTemplateVisitor);
    
    // instanceClear
    // generateClear(global::config().gTemplateVisitor);
  
    // instanceConstants
    // TODO if mergeSubContainers() is used
    // Rename 'sig' in 'dsp', remove 'dsp' allocation, inline subcontainers 'instanceInit' and 'fill' function call
    // inlineSubcontainersFunCalls(fInitInstructions)->accept(global::config().gTemplateVisitor);

    // instanceInit
    // TODO
    
    // init
    // TODO
    
    // buildUserInterface
    
    // TODO
    // Compute
    generateCompute(n);
}

void TemplateCodeContainer::produceMetadata(int tabs)
{}

// Scalar
TemplateScalarCodeContainer::TemplateScalarCodeContainer(const string& name,
                                                    int numInputs, int numOutputs,
                                                    std::ostream* out,
                                                    int sub_container_type)
    : TemplateCodeContainer(name, numInputs, numOutputs, out)
{
    fSubContainerType = sub_container_type;
}

// Given as an example of what a real backend would have to implement.
void TemplateScalarCodeContainer::generateCompute(int n)
{
    *fOut << "TemplateScalarCodeContainer::generateCompute\n";
    
    // Generates declarations
    // TODO

    // Generates local variables declaration and setup
    // generateComputeBlock(global::config().gTemplateVisitor);

    // Generates one single scalar loop
    // TO CHECK
    // SimpleForLoopInst* loop = fCurLoop->generateSimpleScalarLoop(fFullCount);
    // loop->accept(global::config().gTemplateVisitor);

    // Generates post compute
    // generatePostComputeBlock(global::config().gTemplateVisitor);
}

// Vector
TemplateVectorCodeContainer::TemplateVectorCodeContainer(const string& name,
                                                    int numInputs, int numOutputs,
                                                    std::ostream* out)
    : VectorCodeContainer(numInputs, numOutputs), TemplateCodeContainer(name, numInputs, numOutputs, out)
{}

// Given as an example of what a real backend would have to implement.
void TemplateVectorCodeContainer::generateCompute(int n)
{
    *fOut << "TemplateVectorCodeContainer::generateCompute\n";
    
    // Possibly generate separated functions
    
    // Generates declarations
    
    // Generates local variables declaration and setup
    
    // Generates the DSP loop
}
