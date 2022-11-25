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

#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include "compiler/block_diagram/boxes/boxes.hh"
#include "documentator/doc.hh"
#include "documentator/doc_autodoc.hh"
#include "global.hh"
#include "tlib/tlib.hh"

#include "faust/primitive/symbols/as_tree.hh"
#include "compiler/parser/implementation.hh"


/*****************************************************************************
                        Public functions
 *****************************************************************************/

/**
 * @brief Declare an automatic documentation.
 *
 * This function simulates a default documentation :
 * if no <mdoc> tag was found in the input faust file,
 * and yet the '-mdoc' option was called,
 * then print a complete 'process' doc.
 */
void declareAutoDoc()
{
    Tree autodoc = ::Faust::Primitive::Symbols::asTree().nil;
    Tree process = boxIdent("process");

    /** Autodoc's "head", with title, author, date, and metadatas. */

    /** The latex title macro is bound to the metadata "name" if it exists,
     (corresponding to "declare name") or else just to the file name. */
    autodoc = cons(docTxt("\\title{"), autodoc);
    if (gMetaDataSet().count(tree("name"))) {
        autodoc = cons(docMtd(tree("name")), autodoc);
    } else {
        autodoc = cons(docTxt(global::config().gDocName.c_str()), autodoc);
    }
    autodoc = cons(docTxt("}\n"), autodoc);

    /** The latex author macro is bound to the metadata "author" if it exists,
     (corresponding to "declare author") or else no author item is printed. */
    if (gMetaDataSet().count(tree("author"))) {
        autodoc = cons(docTxt("\\author{"), autodoc);
        autodoc = cons(docMtd(tree("author")), autodoc);
        autodoc = cons(docTxt("}\n"), autodoc);
    }

    /** The latex date macro is bound to the metadata "date" if it exists,
     (corresponding to "declare date") or else to the today latex macro. */
    autodoc = cons(docTxt("\\date{"), autodoc);
    if (gMetaDataSet().count(tree("date"))) {
        autodoc = cons(docMtd(tree("date")), autodoc);
    } else {
        autodoc = cons(docTxt("\\today"), autodoc);
    }
    autodoc = cons(docTxt("}\n"), autodoc);

    /** The latex maketitle macro. */
    autodoc = cons(docTxt("\\maketitle\n"), autodoc);

    /** Insert all declared metadatas in a latex tabular environment. */
    if (!gMetaDataSet().empty()) {
        autodoc = cons(docTxt("\\begin{tabular}{ll}\n"), autodoc);
        autodoc = cons(docTxt("\t\\hline\n"), autodoc);
        for (const auto& it : gMetaDataSet()) {
            string mtdkey           = tree2str(it.first);
            string mtdTranslatedKey = global::config().gDocMetadatasStringMap[mtdkey];
            if (mtdTranslatedKey.empty()) {
                mtdTranslatedKey = mtdkey;
            }
            autodoc = cons(docTxt("\t\\textbf{"), autodoc);
            autodoc = cons(docTxt(mtdTranslatedKey.c_str()), autodoc);
            autodoc = cons(docTxt("} & "), autodoc);
            autodoc = cons(docMtd(tree(mtdkey.c_str())), autodoc);
            autodoc = cons(docTxt(" \\\\\n"), autodoc);
        }
        autodoc = cons(docTxt("\t\\hline\n"), autodoc);
        autodoc = cons(docTxt("\\end{tabular}\n"), autodoc);
        autodoc = cons(docTxt("\\bigskip\n"), autodoc);
    }

    /** Autodoc's "body", with equation and diagram of process, and notice and listing. */

    string autoPresentationTxt = "\n\\bigskip \\\\ " + global::config().gDocAutodocStringMap["thisdoc"] + " \\\\ ";
    autodoc                    = cons(docTxt(autoPresentationTxt.c_str()), autodoc);

    string autoEquationTxt = "\n" + global::config().gDocAutodocStringMap["autoeqntitle"] + "\n\n";
    autoEquationTxt += global::config().gDocAutodocStringMap["autoeqntext"] + "\n";
    autodoc = cons(docTxt(autoEquationTxt.c_str()), autodoc);
    autodoc = cons(docEqn(process), autodoc);

    string autoDiagramTxt = "\n" + global::config().gDocAutodocStringMap["autodgmtitle"] + "\n\n";
    autoDiagramTxt += global::config().gDocAutodocStringMap["autodgmtext"] + "\n";
    autodoc = cons(docTxt(autoDiagramTxt.c_str()), autodoc);
    autodoc = cons(docDgm(process), autodoc);

    string autoNoticeTxt = "\n" + global::config().gDocAutodocStringMap["autontctitle"] + "\n\n";
    //	autoNoticeTxt += global::config().gDocAutodocStringMap["autontctext"] + "\n";
    autodoc = cons(docTxt(autoNoticeTxt.c_str()), autodoc);
    autodoc = cons(docNtc(), autodoc);

    string         autoListingTxt;
    vector<string> pathnames = global::config().gReader.listSrcFiles();
    if (pathnames.size() > 1) {
        autoListingTxt = "\n" + global::config().gDocAutodocStringMap["autolsttitle2"] + "\n\n";
        autoListingTxt += global::config().gDocAutodocStringMap["autolsttext2"] + "\n";
    } else {
        autoListingTxt = "\n" + global::config().gDocAutodocStringMap["autolsttitle1"] + "\n\n";
        autoListingTxt += global::config().gDocAutodocStringMap["autolsttext1"] + "\n";
    }
    autodoc = cons(docTxt(autoListingTxt.c_str()), autodoc);
    autodoc = cons(docLst(), autodoc);

    declareDoc(autodoc);
}

/**
 * Initialize global::config().gDocAutodocKeySet, a set containing all the keywords.
 */
void initDocAutodoc()
{
    global::config().gDocAutodocKeySet.insert("thisdoc");

    global::config().gDocAutodocKeySet.insert("autoeqntitle");
    global::config().gDocAutodocKeySet.insert("autoeqntext");

    global::config().gDocAutodocKeySet.insert("autodgmtitle");
    global::config().gDocAutodocKeySet.insert("autodgmtext");

    global::config().gDocAutodocKeySet.insert("autontctitle");
    global::config().gDocAutodocKeySet.insert("autontctext");

    global::config().gDocAutodocKeySet.insert("autolsttitle1");
    global::config().gDocAutodocKeySet.insert("autolsttext1");

    global::config().gDocAutodocKeySet.insert("autolsttitle2");
    global::config().gDocAutodocKeySet.insert("autolsttext2");
}

#if 0
/** 
 * Simple trace function.
 */
static void printDocAutodocStringMapContent()
{
	bool trace = false;
	if (trace) {
		cout << "global::config().gDocAutodocStringMap.size() = " << global::config().gDocAutodocStringMap.size() << endl;
		map<string,string>::iterator it;
		int i = 1;
		for (it = global::config().gDocAutodocStringMap.begin(); it!=global::config().gDocAutodocStringMap.end(); ++it)
			cout << i++ << ".\tglobal::config().gDocNoticeStringMap[" << it->first << "] \t= '" << it->second << "'" << endl;
	}
}
#endif
