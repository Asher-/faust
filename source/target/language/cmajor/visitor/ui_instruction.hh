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

#ifndef __SOUL_VISITOR_UI_INSTRUCTION_HH__
#define __SOUL_VISITOR_UI_INSTRUCTION_HH__

#include <vector>

extern std::vector<char> gReplace;

struct SOULInstUIVisitor : public DispatchVisitor, public PathBuilder {
    std::stringstream     fOut;
    SOULStringTypeManager fTypeManager;
    int                   fTab;
    bool                  fHasBargraph;  // Whether the DSP code has some Bargraphs

    std::vector<std::pair <std::string, std::string> > fMetaAux;

    using DispatchVisitor::visit;


    SOULInstUIVisitor(int tab = 1) : fTypeManager(xfloat(), "*"), fTab(tab), fHasBargraph(false) {}

    void addMeta()
    {
        if (fMetaAux.size() > 0) {
            for (size_t i = 0; i < fMetaAux.size(); i++) {
                if (!std::isdigit(fMetaAux[i].first[0])) {
                    fOut << ", " << "meta_" + global::config().getFreshID(fMetaAux[i].first) << ": " << quote(fMetaAux[i].second);
                }
            }
        }
        fMetaAux.clear();
    }

    std::string getSoulMatadata()
    {
        if (fMetaAux.size() > 0) {
            for (size_t i = 0; i < fMetaAux.size(); i++) {
                if (fMetaAux[i].first == "soul") return fMetaAux[i].second;
            }
        }
        return "";
    }

    virtual void visit(AddMetaDeclareInst* inst)
    {
        fMetaAux.push_back(std::make_pair(inst->fKey, inst->fValue));
    }

    virtual void visit(AddButtonInst* inst)
    {
        if (global::config().gOutputLang == "soul-poly") {
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event_" << replaceCharList(inst->fLabel, gReplace, '_')
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel));
            if (inst->fType != AddButtonInst::kDefaultButton) {
                fOut << ", latching";
            }
            fOut<< ", text: \"off|on\""
            << ", boolean";
            addMeta();
            fOut << " ]];";
        } else if (global::config().gOutputLang == "soul-hybrid") {
            string soul_meta = getSoulMatadata();
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " " << ((soul_meta != "") ? soul_meta : replaceCharList(inst->fLabel, gReplace, '_'))
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel));
            if (inst->fType != AddButtonInst::kDefaultButton) {
                fOut << ", latching";
            }
            fOut << ", text: \"off|on\""
            << ", boolean";
            addMeta();
            fOut << " ]];";
        } else {
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event" << inst->fZone
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel));
            if (inst->fType != AddButtonInst::kDefaultButton) {
                fOut << ", latching";
            }
            fOut << ", text: \"off|on\""
            << ", boolean";
            addMeta();
            fOut << " ]];";
        }
        tab(fTab, fOut);
    }

    virtual void visit(AddSliderInst* inst)
    {
        if (global::config().gOutputLang == "soul-poly") {
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event_" << replaceCharList(inst->fLabel, gReplace, '_')
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax)
            << ", init: " << checkReal(inst->fInit)
            << ", step: " << checkReal(inst->fStep);
            addMeta();
            fOut << " ]];";
        } else if (global::config().gOutputLang == "soul-hybrid") {
            string soul_meta = getSoulMatadata();
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " " << ((soul_meta != "") ? soul_meta : replaceCharList(inst->fLabel, gReplace, '_'))
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax)
            << ", init: " << checkReal(inst->fInit)
            << ", step: " << checkReal(inst->fStep);
            addMeta();
            fOut << " ]];";
        } else {
            fOut << "input event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event" << inst->fZone
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax)
            << ", init: " << checkReal(inst->fInit)
            << ", step: " << checkReal(inst->fStep);
            addMeta();
            fOut << " ]];";
        }
        tab(fTab, fOut);
    }

    virtual void visit(AddBargraphInst* inst)
    {
        // We have bargraphs
        fHasBargraph = true;

        if (global::config().gOutputLang == "soul-poly") {
            fOut << "output event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event_" << quote(replaceCharList(inst->fLabel, gReplace, '_'))
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax);
            addMeta();
            fOut << " ]];";
        } else if (global::config().gOutputLang == "soul-hybrid") {
            string soul_meta = getSoulMatadata();
            fOut << "output event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " " << ((soul_meta != "") ? soul_meta : replaceCharList(inst->fLabel, gReplace, '_'))
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax);
            addMeta();
            fOut << " ]];";
        } else {
            fOut << "output event " << fTypeManager.fTypeDirectTable[itfloat()]
            << " event" << inst->fZone
            << " [[ name: " << quote(inst->fLabel)
            << ", group: " << quote(buildPath(inst->fLabel))
            << ", min: " << checkReal(inst->fMin)
            << ", max: " << checkReal(inst->fMax);
            addMeta();
            fOut << " ]];";
        }
        tab(fTab, fOut);
    }

    virtual void visit(OpenboxInst* inst)
    {
        switch (inst->fOrient) {
            case OpenboxInst::kVerticalBox:
                pushLabel("v:" + inst->fName);
                break;
            case OpenboxInst::kHorizontalBox:
                pushLabel("h:" + inst->fName);
                break;
            case OpenboxInst::kTabBox:
                pushLabel("t:" + inst->fName);
                break;
        }
        fMetaAux.clear();
    }

    virtual void visit(CloseboxInst* inst)
    {
        popLabel();
        fMetaAux.clear();
    }

};

#endif
