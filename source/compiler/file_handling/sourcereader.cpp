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

/*
 sourcereader : Faust source file reader
 This component is in charge of mapping filenames to
 the list of Faust definitions they contain.
*/

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>

#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef EMCC
#include <emscripten.h>
#endif

#include "tlib/compatibility.hh"
#include "compiler/file_handling/sourcereader.hh"
#include "sourcefetcher.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"
#include "compiler/errors/exception.hh"
#include "global.hh"
#include "compiler/type_manager/Text.hh"

#include "compiler/file_handling/string_substitution.hh"

#include "compiler/parser/implementation.hh"

extern global* gGlobal;

using namespace std;

/**
 * Test absolute pathname.
 */
static bool isAbsolutePathname(const string& filename)
{
    // test windows absolute pathname "x:xxxxxx"
    if (filename.size() > 1 && filename[1] == ':') return true;

    // test unix absolute pathname "/xxxxxx"
    if (filename.size() > 0 && filename[0] == '/') return true;

    return false;
}

/**
 * Build a full pathname of <filename>.
 * <fullpath> = <currentdir>/<filename>
 */
static void buildFullPathname(string& fullpath, const char* filename)
{
    char old[FAUST_PATH_MAX];

    if (isAbsolutePathname(filename)) {
        fullpath = filename;
    } else {
        char* newdir = getcwd(old, FAUST_PATH_MAX);
        if (!newdir) {
            stringstream error;
            error << "ERROR : getcwd : " << strerror(errno) << endl;
            throw faustexception(error.str());
        }
        fullpath = newdir;
        fullpath += '/';
        fullpath += filename;
    }
}

/**
 * Try to open the file <filename> searching in various directories. If succesful
 * place its full pathname in the string <fullpath>
 */
FILE* fopenSearch(const char* filename, string& fullpath)
{
    FILE* f;

    // tries to open file with its filename
    if ((f = fopen(filename, "r"))) {
        buildFullPathname(fullpath, filename);
        // enrich the supplied directories paths with the directory containing the loaded file,
        // so that local files relative to this added directory can then be loaded
        gGlobal->gImportDirList.push_back(fileDirname(fullpath));
        return f;
    }

    // otherwise search file in user supplied directories paths
    for (string dirname : gGlobal->gImportDirList) {
        if ((f = fopenAt(fullpath, dirname, filename))) {
            return f;
        }
    }
    return nullptr;
}


/****************************************************************
 Parser variables
 *****************************************************************/


/**
 * Parse a single Faust source file, returns the list of
 * definitions it contains.
 *
 * @param fname the name of the file to parse
 * @return the list of definitions it contains
 */

inline bool isURL(const char* name) { return (strstr(name, "http://") != 0) || (strstr(name, "https://") != 0); }
inline bool isFILE(const char* name) { return strstr(name, "file://") != 0; }

Tree SourceReader::parseFile(const char* fname)
{
    // We are requested to parse an URL file
    if (isURL(fname)) {
        char* buffer = nullptr;
    #ifdef EMCC
        // Call JS code to load URL
        buffer = (char*)EM_ASM_INT({
            var dsp_code = "";
            try {
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.open("GET", Module.UTF8ToString($0), false);
                xmlhttp.send();
                if (xmlhttp.status == 200) {
                    dsp_code = xmlhttp.responseText;
                }
            } catch(e) {
                console.log(e);
            }
            return allocate(intArrayFromString(dsp_code), 'i8', ALLOC_STACK);
        }, fname);

        Tree res = nullptr;
        if (strlen(buffer) == 0) {
            stringstream error;
            error << "ERROR : unable to access URL '" << fname << "'" << endl;
            throw faustexception(error.str());
        } else {
            res = parseString(buffer, fname);
        }
    #else
        // Otherwise use http URL fetch code
        if (http_fetch(fname, &buffer) == -1) {
            stringstream error;
            error << "ERROR : unable to access URL '" << fname << "' : " << http_strerror() << endl;
            throw faustexception(error.str());
        }
        Tree res = parseString(buffer, fname);
        // 'http_fetch' result must be deallocated
        free(buffer);
    #endif
        return res;

    } else {

        // Test for local url
        if (isFILE(fname)) {
            fname = &fname[7]; // skip 'file://'
        }

        // Try to open local file
        string fullpath1;
        FILE* tmp_file = fopenSearch(fname, fullpath1); // Keep file to properly close it
        if (tmp_file) {
            fclose(tmp_file);
            Tree res = parseLocal(fullpath1.c_str());
            return res;
        } else {
        #ifdef EMCC
            // Try to open with the complete URL
            Tree res = nullptr;
            for (size_t i = 0; i < gGlobal->gImportDirList.size(); i++) {
                if (isURL(gGlobal->gImportDirList[i].c_str())) {
                    // Keep the created filename in the global state, so that the 'fname'
                    // global variable always points to a valid string
                    gGlobal->gImportFilename = gGlobal->gImportDirList[i] + fname;
                    if ((res = parseFile(gGlobal->gImportFilename.c_str()))) return res;
                }
            }
        #endif
            stringstream error;
            error << "ERROR : unable to open file " << fullpath1 << endl;
            throw faustexception(error.str());
        }
    }
}

void declareDoc(Tree t)
{
	gGlobal->gDocVector.push_back(t);
}

Tree SourceReader::parseString(const char* stream_name)
{
    // Clear global "inputstring" so that imported files will be correctly parsed with "parse"
    std::string parse_string( gGlobal->gInputString );
    gGlobal->gInputString = nullptr;

    gGlobal->gParser.parseString(parse_string, stream_name);
    /* We have parsed a valid file */
    fFilePathnames.push_back(gGlobal->gParser._streamName);
    gGlobal->gResult = gGlobal->gParser._ast;
    return gGlobal->gParser._ast;
}

Tree SourceReader::parseString(const char* buffer, const char* stream_name)
{
    gGlobal->gInputString = buffer;

    return parseString( stream_name );
}


Tree SourceReader::parseLocal(const char* fname)
{
    gGlobal->gParser.parseFile(fname);
    /* We have parsed a valid file */
    fFilePathnames.push_back(gGlobal->gParser._streamName);
    gGlobal->gResult = gGlobal->gParser._ast;
    return gGlobal->gParser._ast;
}

/**
 * Check if a file as been read and is in the "cache"
 *
 * @param fname the name of the file to check
 * @return true if the file is in the cache
 */

bool SourceReader::cached(string fname)
{
	return fFileCache.find(fname) != fFileCache.end();
}

// Add function metadata (using a boxMetadata construction) to a list of definitions
static Tree addFunctionMetadata(Tree ldef, FunMDSet& M)
{
    Tree lresult = gGlobal->nil; // the transformed list of definitions

    // for each definition def of ldef
    for (; !isNil(ldef); ldef = tl(ldef)) {
        Tree def = hd(ldef);
        Tree fname;
        if (isNil(def)) {
            // skip null definitions produced by declarations
        } else if (isImportFile(def, fname)) {
            lresult = cons(def, lresult);
        } else {
            Tree foo = hd(def);
            Tree exp = tl(def);
            for (const auto& m : M[foo]) {
                exp = boxMetadata(exp, m);
            }
            lresult = cons(cons(foo,exp), lresult);
        }
    }
    return lresult;
}

void SourceReader::checkName()
{
    if (gGlobal->gMasterDocument == yyfilename) {
        Tree name = tree("name");
        if (gGlobal->gMetaDataSet.find(name) == gGlobal->gMetaDataSet.end()) {
            gGlobal->gMetaDataSet[name].insert(tree(quote(stripEnd(basename((char*)yyfilename), ".dsp"))));
        }
        gGlobal->gMetaDataSet[tree("filename")].insert(tree(quote(basename((char*)yyfilename))));
    }
}

/**
 * Parse a single Faust source file, returns the list of
 * definitions it contains.
 *
 * @param fname the name of the file to parse
 * @return the list of definitions it contains
 */

inline bool isURL(const char* name) { return (strstr(name, "http://") != 0) || (strstr(name, "https://") != 0); }
inline bool isFILE(const char* name) { return strstr(name, "file://") != 0; }

Tree SourceReader::parseFile(const char* fname)
{
    yyerr = 0;
    yylineno = 1;
    yyfilename = fname;

    // We are requested to parse an URL file
    if (isURL(yyfilename)) {
        char* buffer = nullptr;
    #ifdef EMCC
        // Call JS code to load URL
        buffer = (char*)EM_ASM_INT({
            var dsp_code = "";
            try {
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.open("GET", Module.UTF8ToString($0), false);
                xmlhttp.send();
                if (xmlhttp.status == 200) {
                    dsp_code = xmlhttp.responseText;
                }
            } catch(e) {
                console.log(e);
            }
            return allocate(intArrayFromString(dsp_code), 'i8', ALLOC_STACK);
        }, yyfilename);

        Tree res = nullptr;
        if (strlen(buffer) == 0) {
            stringstream error;
            error << "ERROR : unable to access URL '" << fname << "'" << endl;
            throw faustexception(error.str());
        } else {
            yy_scan_string(buffer);
            res = parseLocal(yyfilename);
        }
    #else
        // Otherwise use http URL fetch code
        if (http_fetch(yyfilename, &buffer) == -1) {
            stringstream error;
            error << "ERROR : unable to access URL '" << fname << "' : " << http_strerror() << endl;
            throw faustexception(error.str());
        }
        yy_scan_string(buffer);
        Tree res = parseLocal(yyfilename);
        // 'http_fetch' result must be deallocated
        free(buffer);
    #endif
        return res;

    } else {

        // Test for local url
        if (isFILE(yyfilename)) {
            yyfilename = &yyfilename[7]; // skip 'file://'
        }

        // Try to open local file
        string fullpath1;
        FILE* tmp_file = yyin = fopenSearch(yyfilename, fullpath1); // Keep file to properly close it
        if (yyin) {
            Tree res = parseLocal(fullpath1.c_str());
            fclose(tmp_file);
            return res;
        } else {
        #ifdef EMCC
            // Try to open with the complete URL
            Tree res = nullptr;
            for (size_t i = 0; i < gGlobal->gImportDirList.size(); i++) {
                if (isURL(gGlobal->gImportDirList[i].c_str())) {
                    // Keep the created filename in the global state, so that the 'yyfilename'
                    // global variable always points to a valid string
                    gGlobal->gImportFilename = gGlobal->gImportDirList[i] + fname;
                    if ((res = parseFile(gGlobal->gImportFilename.c_str()))) return res;
                }
            }
        #endif
            stringstream error;
            error << "ERROR : unable to open file " << fullpath1 << endl;
            throw faustexception(error.str());
        }
    }
}

Tree SourceReader::parseString(const char* fname)
{
    yyerr = 0;
    yylineno = 1;
    yyfilename = fname;
    yy_scan_string(gGlobal->gInputString.c_str());

    // Clear global "inputstring" so that imported files will be correctly parsed with "parse"
    gGlobal->gInputString = "";
    return parseLocal(fname);
}

Tree SourceReader::parseLocal(const char* fname)
{
    int r = yyparse();
    stringstream error;

    if (r) {
        error << "ERROR : parse code = " << r << endl;
        throw faustexception(error.str());
    }
    if (yyerr > 0) {
        error << "ERROR : parse code = " << yyerr << endl;
        throw faustexception(error.str());
    }

    yylex_destroy();

    // We have parsed a valid file
    checkName();
    fFilePathnames.push_back(fname);
    return gGlobal->gResult;
}

/**
 * Check if a file as been read and is in the "cache"
 *
 * @param fname the name of the file to check
 * @return true if the file is in the cache
 */

bool SourceReader::cached(string fname)
{
	return fFileCache.find(fname) != fFileCache.end();
}

/**
 * Return the list of definitions file contains. Cache the result.
 *
 * @param fname the name of the file to check
 * @return the list of definitions it contains
 */

Tree SourceReader::getList(const char* fname)
{
	if (!cached(fname)) {
        // Previous metadata need to be cleared before parsing a file
        gGlobal->gFunMDSet.clear();
        Tree ldef = (gGlobal->gInputString != "") ? parseString(fname) : parseFile(fname);
        // Definitions with metadata have to be wrapped into a boxMetadata construction
        fFileCache[fname] = addFunctionMetadata(ldef, gGlobal->gFunMDSet);
	}
    return fFileCache[fname];
}

/**
 * Return a vector of pathnames representing the list
 * of all the source files that have been required
 * to evaluate process (those in fFileCache)
 */

vector<string> SourceReader::listSrcFiles()
{
    return fFilePathnames;
}

/**
 * Return a vector of pathnames representing the list
 * of all the source files that have been required
 * to evaluate process, without the DSP file itself
 */

vector<string> SourceReader::listLibraryFiles()
{
    vector<string> tmp = fFilePathnames;
    if (tmp.size() > 0) tmp.erase(tmp.begin());
    return tmp;
}

/**
 * Return the list of definitions where all imports have been expanded.
 *
 * @param ldef the list of definitions to expand
 * @return the expanded list of definitions
 */

Tree SourceReader::expandList(Tree ldef)
{
	set<string> visited;
	return expandRec(ldef, visited, gGlobal->nil);
}

Tree SourceReader::expandRec(Tree ldef, set<string>& visited, Tree lresult)
{
	for (;!isNil(ldef); ldef = tl(ldef)) {
		Tree d = hd(ldef);
		Tree fname;
		if (isNil(d)) {
			// skill null definitions produced by declarations
		} else if (isImportFile(d, fname)) {
			const char* f = tree2str(fname);
			if (visited.find(f) == visited.end()) {
				visited.insert(f);
				lresult = expandRec(getList(f), visited, lresult);
			}
		} else {
			lresult = cons(d, lresult);
		}
	}
	return lresult;
}
