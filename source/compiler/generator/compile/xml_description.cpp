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

//------------------------------------
// generation of an xml description
//------------------------------------

#include <map>
#include <set>
#include <string>

#include "Text.hh"
#include "compatibility.hh"
#include "xml_description.hh"
#include "exception.hh"
#include "global.hh"

using namespace std;

/**
 * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata
 */
void extractMetadata(const std::string& fulllabel, string& label, map<std::string, set<std::string>>& metadata)
{
    enum { kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue };
    int    state = kLabel;
    int    deep  = 0;
    string key, value;

    for (size_t i = 0; i < fulllabel.size(); i++) {
        char c = fulllabel[i];
        switch (state) {
            case kLabel:
                faustassert(deep == 0);
                switch (c) {
                    case '\\':
                        state = kEscape1;
                        break;
                    case '[':
                        state = kKey;
                        deep++;
                        break;
                    default:
                        label += c;
                }
                break;

            case kEscape1:
                label += c;
                state = kLabel;
                break;

            case kEscape2:
                key += c;
                state = kKey;
                break;

            case kEscape3:
                value += c;
                state = kValue;
                break;

            case kKey:
                faustassert(deep > 0);
                switch (c) {
                    case '\\':
                        state = kEscape2;
                        break;

                    case '[':
                        deep++;
                        key += c;
                        break;

                    case ':':
                        if (deep == 1) {
                            state = kValue;
                        } else {
                            key += c;
                        }
                        break;
                    case ']':
                        deep--;
                        if (deep < 1) {
                            metadata[rmWhiteSpaces(key)].insert("");
                            state = kLabel;
                            key   = "";
                            value = "";
                        } else {
                            key += c;
                        }
                        break;
                    default:
                        key += c;
                }
                break;

            case kValue:
                faustassert(deep > 0);
                switch (c) {
                    case '\\':
                        state = kEscape3;
                        break;

                    case '[':
                        deep++;
                        value += c;
                        break;

                    case ']':
                        deep--;
                        if (deep < 1) {
                            metadata[rmWhiteSpaces(key)].insert(rmWhiteSpaces(value));
                            state = kLabel;
                            key   = "";
                            value = "";
                        } else {
                            value += c;
                        }
                        break;
                    default:
                        value += c;
                }
                break;

            default: {
                stringstream error;
                error << "ERROR unrecognized state " << state << endl;
                gGlobal->gErrorMessage = error.str();
            }
        }
    }
    label = rmWhiteSpaces(label);
}

//------------------------ specific schema -------------------------

string extractName(Tree full_label)
{
    string                   name;
    map<std::string, set<std::string>> metadata;

    extractMetadata(tree2str(full_label), name, metadata);
    return name;
}

/**
 * removes enclosing quotes and transforms '<', '>' and '&' characters
 */
static std::string xmlize(const std::string& fullsrc)
{
    map<std::string, set<std::string>> metadata;
    string                   dst;
    string                   src;

    extractMetadata(fullsrc, src, metadata);

    for (size_t i = 0; i < src.size(); i++) {
        if (src[i] == '"' && ((i == 0) || (i == src.size() - 1))) {
            // nothing to do just skip the quotes
        } else {
            switch (src[i]) {
                case '<':
                    dst += "&lt;";
                    break;
                case '>':
                    dst += "&gt;";
                    break;
                case '&':
                    dst += "&amp;";
                    break;
                default:
                    dst += src[i];
            }
        }
    }
    return dst;
}

static list<std::string> xmlOfMetadata(const map<std::string, set<std::string>>& metadata, int level)
{
    list<std::string> lines;
    string       line;

    line.reserve(128);

    for (const auto& it1 : metadata) {
        const std::string& key = it1.first;
        for (const auto& it2 : it1.second) {
            const std::string& value = it2;
            line.assign(level, '\t');
            line += "<meta key=\"";
            line += xmlize(key);
            line += "\">";
            line += xmlize(value);
            line += "</meta>";
            lines.push_back(line);
        }
    }

    return lines;
}

void Description::print(int n, ostream& fout)
{
    list<std::string> metaDataLines = xmlOfMetadata(fMetadata, 0);

    tab(n, fout);
    fout << "<faust>";

    tab(n + 1, fout);
    fout << "<name>" << xmlize(fName) << "</name>";
    tab(n + 1, fout);
    fout << "<author>" << xmlize(fAuthor) << "</author>";
    tab(n + 1, fout);
    fout << "<copyright>" << xmlize(fCopyright) << "</copyright>";
    tab(n + 1, fout);
    fout << "<license>" << xmlize(fLicense) << "</license>";
    tab(n + 1, fout);
    fout << "<version>" << xmlize(fVersion) << "</version>";
    tab(n + 1, fout);
    fout << "<classname>" << xmlize(fClassName) << "</classname>";
    tab(n + 1, fout);
    fout << "<inputs>" << fInputs << "</inputs>";
    tab(n + 1, fout);
    fout << "<outputs>" << fOutputs << "</outputs>";

    for (const auto& s : metaDataLines) {
        tab(n + 1, fout);
        fout << s;
    }

    tab(n + 1, fout);
    fout << "<ui>";

    // active widget list
    tab(n + 2, fout);
    fout << "<activewidgets>";
    tab(n + 3, fout);
    fout << "<count>" << fActiveWidgetCount << "</count>";
    for (const auto& s : fActiveLines) {
        tab(n + 3, fout);
        fout << s;
    }
    tab(n + 2, fout);
    fout << "</activewidgets>";

    tab(n + 2, fout);

    // passive widget list
    tab(n + 2, fout);
    fout << "<passivewidgets>";
    tab(n + 3, fout);
    fout << "<count>" << fPassiveWidgetCount << "</count>";
    for (const auto& s : fPassiveLines) {
        tab(n + 3, fout);
        fout << s;
    }
    tab(n + 2, fout);
    fout << "</passivewidgets>";

    tab(n + 2, fout);

    // widget layout
    tab(n + 2, fout);
    fout << "<layout>";
    list<int>::iterator t;
    list<std::string>::iterator s;
    for (t = fLayoutTabs.begin(), s = fLayoutLines.begin(); s != fLayoutLines.end(); t++, s++) {
        tab(n + 3 + *t, fout);
        fout << *s;
    }
    tab(n + 2, fout);
    fout << "</layout>";

    tab(n + 1, fout);
    fout << "</ui>";

    tab(n, fout);
    fout << "</faust>" << endl;
}

void Description::ui(Tree t)
{
    addGroup(0, t);
}

void Description::addGroup(int level, Tree t)
{
    Tree        label, elements, varname, sig;
    const char* groupnames[] = {"vgroup", "hgroup", "tgroup"};

    if (isUiFolder(t, label, elements)) {
        const int orient = tree2int(left(label));

        addLayoutLine(level, subst("<group type=\"$0\">", groupnames[orient]));
        addLayoutLine(level + 1, subst("<label>$0</label>", checkNullLabel(t, xmlize(tree2str(right(label))), false)));
        while (!isNil(elements)) {
            addGroup(level + 1, right(hd(elements)));
            elements = tl(elements);
        }
        addLayoutLine(level, "</group>");

    } else if (isUiWidget(t, label, varname, sig)) {
        int w = addWidget(label, varname, sig);
        addLayoutLine(level, subst("<widgetref id=\"$0\" />", T(w)));

    } else {
        cerr << "ERROR : user interface generation\n";
        faustassert(false);
    }
}

void Description::tab(int n, ostream& fout)
{
    fout << '\n';
    while (n--) fout << '\t';
}

int Description::addWidget(Tree label, Tree varname, Tree sig)
{
    Tree path, c, x, y, z;

    // add an active widget description

    if (isSigButton(sig, path)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"button\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveMetadata(label);
        addActiveLine("</widget>");

    } else if (isSigCheckbox(sig, path)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"checkbox\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveMetadata(label);
        addActiveLine("</widget>");

    } else if (isSigVSlider(sig, path, c, x, y, z)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"vslider\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveLine(subst("\t<init>$0</init>", T(tree2double(c))));
        addActiveLine(subst("\t<min>$0</min>", T(tree2double(x))));
        addActiveLine(subst("\t<max>$0</max>", T(tree2double(y))));
        addActiveLine(subst("\t<step>$0</step>", T(tree2double(z))));
        addActiveMetadata(label);
        addActiveLine("</widget>");

    } else if (isSigHSlider(sig, path, c, x, y, z)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"hslider\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveLine(subst("\t<init>$0</init>", T(tree2double(c))));
        addActiveLine(subst("\t<min>$0</min>", T(tree2double(x))));
        addActiveLine(subst("\t<max>$0</max>", T(tree2double(y))));
        addActiveLine(subst("\t<step>$0</step>", T(tree2double(z))));
        addActiveMetadata(label);
        addActiveLine("</widget>");

    } else if (isSigNumEntry(sig, path, c, x, y, z)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"nentry\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveLine(subst("\t<init>$0</init>", T(tree2double(c))));
        addActiveLine(subst("\t<min>$0</min>", T(tree2double(x))));
        addActiveLine(subst("\t<max>$0</max>", T(tree2double(y))));
        addActiveLine(subst("\t<step>$0</step>", T(tree2double(z))));
        addActiveMetadata(label);
        addActiveLine("</widget>");

    } else if (isSigSoundfile(sig, path)) {
        fWidgetID++;
        fActiveWidgetCount++;
        addActiveLine(subst("<widget type=\"soundfile\" id=\"$0\">", T(fWidgetID)));
        addActiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addActiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addActiveMetadata(label);
        addActiveLine("</widget>");

        // add a passive widget description

    } else if (isSigVBargraph(sig, path, x, y, z)) {
        fWidgetID++;
        fPassiveWidgetCount++;
        addPassiveLine(subst("<widget type=\"vbargraph\" id=\"$0\">", T(fWidgetID)));
        addPassiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addPassiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addPassiveLine(subst("\t<min>$0</min>", T(tree2double(x))));
        addPassiveLine(subst("\t<max>$0</max>", T(tree2double(y))));
        addPassiveMetadata(label);
        addPassiveLine("</widget>");

    } else if (isSigHBargraph(sig, path, x, y, z)) {
        fWidgetID++;
        fPassiveWidgetCount++;
        addPassiveLine(subst("<widget type=\"hbargraph\" id=\"$0\">", T(fWidgetID)));
        addPassiveLine(subst("\t<label>$0</label>", checkNullLabel(sig, xmlize(tree2str(label)), true)));
        addPassiveLine(subst("\t<varname>$0</varname>", tree2str(varname)));
        addPassiveLine(subst("\t<min>$0</min>", T(tree2double(x))));
        addPassiveLine(subst("\t<max>$0</max>", T(tree2double(y))));
        addPassiveMetadata(label);
        addPassiveLine("</widget>");

    } else {
        cerr << "ERROR : describing widget : unrecognized expression\n";
        faustassert(false);
    }

    return fWidgetID;
}

void Description::addActiveMetadata(Tree label)
{
    map<std::string, set<std::string>>     metadata;
    string                       shortLabel;
    list<std::string>                 lines;
  
    extractMetadata(tree2str(label), shortLabel, metadata);
    lines = xmlOfMetadata(metadata, 1);

    for (const auto& it : lines) fActiveLines.push_back(it);
}

void Description::addPassiveMetadata(Tree label)
{
    map<std::string, set<std::string>>     metadata;
    string                       shortLabel;
    list<std::string>                 lines;
  
    extractMetadata(tree2str(label), shortLabel, metadata);
    lines = xmlOfMetadata(metadata, 1);

    for (const auto& it : lines) fPassiveLines.push_back(it);
}