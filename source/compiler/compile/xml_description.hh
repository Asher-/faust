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

#ifndef __DESCRIPTION__
#define __DESCRIPTION__

//------------------------------------
// generation of an xml description
//------------------------------------

#include <list>
#include <map>
#include <set>
#include <string>

#include "compiler/type_manager/garbageable.hh"
#include "compiler/signals/signals.hh"
#include "tlib/tlib.hh"
#include "compiler/dsp_factory/uitree.hh"

using namespace std;

void extractMetadata(const std::string& fulllabel, string& label, map<std::string, set<std::string> >& metadata);

LIBFAUST_API string extractName(Tree full_label);

class Description : public virtual Garbageable {
    string                    fName;
    string                    fAuthor;
    string                    fCopyright;
    string                    fLicense;
    string                    fVersion;
    map<std::string, set<std::string> > fMetadata;

    string       fClassName;
    int          fInputs;
    int          fOutputs;
    int          fWidgetID;
    int          fActiveWidgetCount;
    int          fPassiveWidgetCount;
    list<std::string> fActiveLines;
    list<std::string> fPassiveLines;
    list<std::string> fLayoutLines;
    list<int>    fLayoutTabs;

   public:
    Description()
        : fInputs(0),
          fOutputs(0),
          fWidgetID(0),
          fActiveWidgetCount(0),
          fPassiveWidgetCount(0)
    {
    }

    Description* name(const std::string& s)
    {
        fName = s;
        return this;
    }
    Description* author(const std::string& s)
    {
        fAuthor = s;
        return this;
    }
    Description* copyright(const std::string& s)
    {
        fCopyright = s;
        return this;
    }
    Description* license(const std::string& s)
    {
        fLicense = s;
        return this;
    }
    Description* version(const std::string& s)
    {
        fVersion = s;
        return this;
    }

    Description* className(const std::string& s)
    {
        fClassName = s;
        return this;
    }
    Description* inputs(int n)
    {
        fInputs = n;
        return this;
    }
    Description* outputs(int n)
    {
        fOutputs = n;
        return this;
    }
    Description* declare(const std::string& key, const std::string& value)
    {
        fMetadata[key].insert(value);
        return this;
    }

    void ui(Tree t);
    void print(int n, ostream& fout);

   private:
    void addGroup(int level, Tree t);
    int  addWidget(Tree label, Tree varname, Tree sig);

    void tab(int n, ostream& fout);
    void addActiveLine(const std::string& l) { fActiveLines.push_back(l); }
    void addPassiveLine(const std::string& l) { fPassiveLines.push_back(l); }
    void addActiveMetadata(Tree label);
    void addPassiveMetadata(Tree label);
    void addLayoutLine(int n, const std::string& l)
    {
        fLayoutTabs.push_back(n);
        fLayoutLines.push_back(l);
    }
};

#endif
