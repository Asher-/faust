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

#include <errno.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>

#include "tlib/compatibility.hh"
#include "documentator/doc_lang.hh"
#include "documentator/doc_notice.hh"
#include "compiler/file_handling/string_substitution.hh"
#include "global.hh"

static void initDocNoticeKeySet();
static void initDocNoticeFlagMap();

/*****************************************************************************
                            Public functions
 *****************************************************************************/

/**
 * Print the content of the notice (a string map),
 * as LaTeX items inside an itemize environment.
 *
 * @remark
 * This function is meant to make it easier to reorder
 * the notice printing by gathering all the items.
 *
 * @param[in]	notice			The set containing the strings to print as items.
 * @param[in]	faustversion	The current version of this Faust compiler.
 * @param[out]	docout			The LaTeX output file to print into.
 */
void printDocNotice(const string& faustversion, ostream& docout)
{
    if (!global::config().gDocNoticeStringMap.empty()) {
        // cerr << "Documentator : printDocNotice : printing..." << endl;

        docout << endl << "\\begin{itemize}" << endl;

        /* Presentations. */
        docout << "\t\\item " << global::config().gDocAutodocStringMap["autontctext"] << endl;
        if (global::config().gDocNoticeFlagMap["faustapply"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["faustapply"] << endl;
        if (global::config().gDocNoticeFlagMap["faustpresentation"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["faustpresentation"] << endl;
        if (global::config().gDocNoticeFlagMap["causality"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["causality"] << endl;
        if (global::config().gDocNoticeFlagMap["blockdiagrams"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["blockdiagrams"] << endl;

        /* Naming conventions of variables and functions. */
        if (global::config().gDocNoticeFlagMap["foreignfun"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["foreignfun"] << endl;
        if (global::config().gDocNoticeFlagMap["intcast"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["intcast"] << endl;

        /* Integer arithmetic into a tabular environment. */
        if (global::config().gDocNoticeFlagMap["intplus"] || global::config().gDocNoticeFlagMap["intminus"] ||
            global::config().gDocNoticeFlagMap["intmult"] || global::config().gDocNoticeFlagMap["intdiv"] ||
            global::config().gDocNoticeFlagMap["intand"] || global::config().gDocNoticeFlagMap["intor"] ||
            global::config().gDocNoticeFlagMap["intxor"]) {
            global::config().gDocNoticeFlagMap["operators"]  = true;
            global::config().gDocNoticeFlagMap["optabtitle"] = true;
            global::config().gDocNoticeFlagMap["integerops"] = true;

            docout << "\t\\item " << endl;
            docout << "\t\t" << global::config().gDocNoticeStringMap["operators"] << endl;
            docout << "\t\\begin{center}" << endl;
            docout << "\t\\begin{tabular}{|c|l|l|} " << endl;
            docout << "\t\t\\hline " << endl;
            docout << "\t\t" << global::config().gDocNoticeStringMap["optabtitle"] << endl;
            docout << "\t\t\\hline " << endl;
            if (global::config().gDocNoticeFlagMap["intplus"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intplus"] << endl;
            if (global::config().gDocNoticeFlagMap["intminus"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intminus"] << endl;
            if (global::config().gDocNoticeFlagMap["intmult"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intmult"] << endl;
            if (global::config().gDocNoticeFlagMap["intdiv"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intdiv"] << endl;
            if (global::config().gDocNoticeFlagMap["intand"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intand"] << endl;
            if (global::config().gDocNoticeFlagMap["intor"]) docout << "\t\t" << global::config().gDocNoticeStringMap["intor"] << endl;
            if (global::config().gDocNoticeFlagMap["intxor"])
                docout << "\t\t" << global::config().gDocNoticeStringMap["intxor"] << endl;
            docout << "\t\t\\hline " << endl;
            docout << "\t\\end{tabular} " << endl;
            docout << "\t\\end{center}" << endl;
            docout << "\t\t" << global::config().gDocNoticeStringMap["integerops"] << endl;
        }

        if (global::config().gDocNoticeFlagMap["faustdocdir"])
            docout << "\t\\item " << global::config().gDocNoticeStringMap["faustdocdir"] << endl;

        docout << "\\end{itemize}" << endl << endl;
    }
    // cerr << "  ... Documentator : printDocNotice : end of printing." << endl;
}

/**
 * Dispatch initialization of notice containers,
 * after default notice file loading.
 *
 * @remark
 * The default (english) notice is already loaded at this stage
 * to ensure that all keywords will receive a definition.
 */
void initDocNotice()
{
    initDocNoticeKeySet();
    initDocNoticeFlagMap();
}

/*****************************************************************************
                                Static functions
 *****************************************************************************/

/**
 * Initialize global::config().gDocNoticeKeySet, a set containing all the keywords.
 */
static void initDocNoticeKeySet()
{
    global::config().gDocNoticeKeySet.insert("faustpresentation");
    global::config().gDocNoticeKeySet.insert("faustapply");
    global::config().gDocNoticeKeySet.insert("faustdocdir");
    global::config().gDocNoticeKeySet.insert("causality");
    global::config().gDocNoticeKeySet.insert("blockdiagrams");

    global::config().gDocNoticeKeySet.insert("foreignfun");
    global::config().gDocNoticeKeySet.insert("intcast");

    global::config().gDocNoticeKeySet.insert("operators");
    global::config().gDocNoticeKeySet.insert("optabtitle");
    global::config().gDocNoticeKeySet.insert("integerops");
    global::config().gDocNoticeKeySet.insert("intplus");
    global::config().gDocNoticeKeySet.insert("intminus");
    global::config().gDocNoticeKeySet.insert("intmult");
    global::config().gDocNoticeKeySet.insert("intdiv");
    global::config().gDocNoticeKeySet.insert("intand");
    global::config().gDocNoticeKeySet.insert("intor");
    global::config().gDocNoticeKeySet.insert("intxor");
}

/**
 * Initialize global::config().gDocNoticeFlagMap, a map containing all the flags.
 */
static void initDocNoticeFlagMap()
{
    for (set<string>::iterator it = global::config().gDocNoticeKeySet.begin(); it != global::config().gDocNoticeKeySet.end(); ++it) {
        global::config().gDocNoticeFlagMap[*it] = false;
    }
    global::config().gDocNoticeFlagMap["faustpresentation"] = true;
    global::config().gDocNoticeFlagMap["faustapply"]        = true;
    global::config().gDocNoticeFlagMap["faustdocdir"]       = true;
    global::config().gDocNoticeFlagMap["causality"]         = true;
    global::config().gDocNoticeFlagMap["blockdiagrams"]     = true;
}
