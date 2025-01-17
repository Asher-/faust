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

#include <filesystem>

#include "compiler/parser/implementation.hh"
#include "tlib/compatibility.hh"
#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"
#include "compiler/type_manager/Text.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"
#include "faust/primitive/symbols.hh"
#include "faust/primitive/symbols/as_tree.hh"

using namespace ::Faust::Compiler::Parser;

std::string& gMasterDocument()
{
  static std::string g_master_document;
  return g_master_document;
}

MetaDataSet& gMetaDataSet()
{
  static MetaDataSet g_meta_data_set;
  return g_meta_data_set;
}

FunMDSet& gFunMDSet()
{
  static FunMDSet g_fun_md_set;
  return g_fun_md_set;
}

std::string& gOutputLang()
{
  static std::string g_output_lang;
  return g_output_lang;
}

Tree Implementation::checkRulelist(Tree lr)
{
    Tree lrules = lr;
    if (isNil(lrules)) {
        stringstream error;
        error << "ERROR (file " << this->_streamName << ":" << this->_lexer->lineno() << ") : a case expression can't be empty" << endl;
        throw faustexception(error.str());
    }
    // first pattern used as a reference
    Tree lhs1 = hd(hd(lrules));
    Tree rhs1 = tl(hd(lrules));
    int npat = len(lhs1);
    lrules = tl(lrules);
    while (!isNil(lrules)) {
        Tree lhs2 = hd(hd(lrules));
        Tree rhs2 = tl(hd(lrules));
        if (npat != len(lhs2)) {
            throw faustexception(printPatternError(nullptr, lhs1, rhs1, lhs2, rhs2));
        }
        lhs1 = lhs2;
        rhs1 = rhs2;
        lrules = tl(lrules);
    }
    return lr;
}

string Implementation::printPatternError(Tree symbol, Tree lhs1, Tree rhs1, Tree lhs2, Tree rhs2)
{
    stringstream error;

    if (!symbol) {
        error << "ERROR : inconsistent number of parameters in pattern-matching rule: "
        << ::boxpp(reverse(lhs2)) << " => " << ::boxpp(rhs2) << ";"
        << " previous rule was: "
        << ::boxpp(reverse(lhs1)) << " => " << ::boxpp(rhs1) << ";"
        << endl;
    } else {
        error << "ERROR (file " << this->_streamName << ":" << this->_lexer->lineno() << ") : in the definition of " << ::boxpp(symbol) << endl
        << "Inconsistent number of parameters in pattern-matching rule: "
        << ::boxpp(reverse(lhs2)) << " => " << ::boxpp(rhs2) << ";"
        << " previous rule was: "
        << ::boxpp(reverse(lhs1)) << " => " << ::boxpp(rhs1) << ";"
        << endl;
    }

    return error.str();
}

string Implementation::printRedefinitionError(Tree symbol, std::list<Tree>& variants)
{
    stringstream error;

    error << "ERROR (file " << this->_streamName << ":" << this->_lexer->lineno() << ") : multiple definitions of symbol " << ::boxpp(symbol) << endl;
    for (const auto& p : variants) {
        Tree params = hd(p);
        Tree body = tl(p);
        if (isNil(params)) {
            error << ::boxpp(symbol) << " = " << ::boxpp(body) << ";" << endl;
        } else {
            error << ::boxpp(symbol) << ::boxpp(params) << " = " << ::boxpp(body) << ";" << endl;
        }
    }

    return error.str();
}

void Implementation::checkName()
{
    if (gMasterDocument() == this->_streamName) {
        Tree name = tree("name");
        if (gMetaDataSet().find(name) == gMetaDataSet().end()) {
            gMetaDataSet()[name].insert(tree(quote(this->stripEnd(std::filesystem::path(this->_streamName).filename(), ".dsp"))));
        }
        gMetaDataSet()[tree("filename")].insert(tree(quote(std::filesystem::path(this->_streamName).filename())));
    }
}

void Implementation::declareMetadata(Tree key, Tree value)
{
    if (gMasterDocument() == this->_streamName) {
        // Inside master document, no prefix needed to declare metadata
        gMetaDataSet()[key].insert(value);
    } else {
        string fkey(this->_streamName);
        if (fkey != "") {
            fkey += "/";
        }
        fkey += tree2str(key);
        gMetaDataSet()[tree(fkey.c_str())].insert(value);
    }
}

/*
fun -> (file*fun -> {key*value,...})

gFunMDSet()[fun].insert(file*fun*key*value);
gFunMetaDataSet = map<tree, tuple<Tree,Tree,Tree,Tree>>
*/

// Called by parser to create function's metadata
void Implementation::declareDefinitionMetadata(Tree id, Tree key, Tree value)
{
    stringstream fullkeystream;
    fullkeystream << this->_streamName << "/" << tree2str(id) << ":" << tree2str(key);
    string fullkey = fullkeystream.str();
    Tree md = cons(tree(fullkey), value);
    //cout << "Creation of a function metadata : " << *md << endl;
    gFunMDSet()[boxIdent(tree2str(id).c_str())].insert(md);
}

/**
 * Transforms a list of variants (arglist.body)
 * into an abstraction or a boxCase.
 * @param symbol name only used in case of error
 * @param variants list of variants (arglist.body)
 * @return the corresponding box expression
 */

Tree Implementation::makeDefinition(Tree symbol, std::list<Tree>& variants)
{
  if (variants.size() == 1) {
    Tree rhs = *variants.begin();
    Tree args = hd(rhs);
    Tree body = tl(rhs);

    if ( isNil(args) ) {
      return body;
    }
    else if ( standardArgList(args) ) {
      return buildBoxAbstr(args, body);
    }
    else {
      Tree rules = TREE_JOIN( "makeDefinition(1).boxCase( rules )", rhs );
      return boxCase( rules );
    }
  }
  else {
    Tree prev = *variants.begin();
    Tree l = ::Faust::Primitive::Symbols::asTree().nil;

    int npat = len(hd(prev));
    if (npat == 0) {
        throw faustexception(printRedefinitionError(symbol, variants));
    }

    for (const auto& p : variants) {
      Tree cur = p;
      if ( (npat == 0)
        || (npat != len(hd(cur)))) {
          throw faustexception(printPatternError(
            symbol,
            hd(prev),
            tl(prev),
            hd(cur),
            tl(cur)
          ));
      }
      prev = cur;
      l = TREE_JOIN( "makeDefinition(n).boxCase( rules )", p, l );
    }
    return boxCase(l);
  }
}

/**
 * Formats a list of raw definitions represented by triplets
 * <name, arglist, body> into abstractions or pattern
 * matching rules when appropriate.
 *
 * @param rldef list of raw definitions in reverse order
 * @return the list of formatted definitions
 */

Tree Implementation::formatDefinitions(Tree rldef)
{
    map<Tree, std::list<Tree> > statements;
    Tree ldef2 = ::Faust::Primitive::Symbols::asTree().nil;
    Tree file;

    // Collects the definitions in a dictionnary
    while (!isNil(rldef)) { // while we have rhs branch
        Tree def = hd(rldef); // lhs of rhs branch
        rldef = tl(rldef);    // rhs of rhs branch
        if ( isImportFile(def, file) ) {
            // collect imports in ldef2
            ldef2 = TREE_JOIN("formatDefinitions.importFile()", def,ldef2);
        }
        else if (! isNil(def) ) {
            //cout << " def : " << *def << endl;
            std::list<Tree>& list = statements[hd(def)];
            list.push_front( tl(def) );
        }
    }

    // Produces the definitions
    map<Tree, list<Tree> >::iterator tree_iterator;
    for ( tree_iterator = statements.begin();
          tree_iterator != statements.end();
          ++tree_iterator ) {
        Tree definition = TREE_JOIN( "formatDefinitions().definition",
          tree_iterator->first,
          makeDefinition( tree_iterator->first, tree_iterator->second )
        );
        
        ldef2 = TREE_JOIN( "formatDefinitions().list",
          definition,
          ldef2
        );
    }
    return ldef2;

}

/**
 * Checks an argument list for containing only
 * standard identifiers, no patterns and
 * is linear.
 * @param args the argument list to check
 * @return true if it contains only identifiers
 */

bool Implementation::standardArgList(Tree args)
{
  map<Tree,int> L;
  while (isList(args)) {
    if (!isBoxIdent(hd(args))) return false;
    if (++L[hd(args)] > 1) return false;
    args = tl(args);
  }
  return true;
}

std::string Implementation::stripEnd(const std::string& name, const std::string& ext)
{
    if (name.length() >= 4 && name.substr(name.length() - ext.length()) == ext) {
        return name.substr(0, name.length() - ext.length());
    } else {
        return name;
    }
}

char Implementation::replaceCR(char c)
{
	return (c!='\n') ? c : ' ';
}

//----------------------------------------------------------
// A definition is accepted if the prefixset is empty or if
// the current float precision is member of the prefix set
//----------------------------------------------------------
bool Implementation::acceptdefinition(int prefixset)
{
	int precisions[] = {0, 1, 2, 4, 8};
	return (prefixset==0) || (prefixset & precisions[::Faust::Primitive::Math::floatSize]);
}

//----------------------------------------------------------
// 'atoi' does not work correctly on Windows with MSVC on values
// greater than 2^31 (= 2147483648)
//----------------------------------------------------------
int Implementation::str2int(const char* str)
{
    int result = 0;
    while (*str != 0) {
        result = result * 10 + *str - '0';
        str++;
    }
    return result;
}

//----------------------------------------------------------
// unquote() : remove enclosing quotes and carriage return
// characters from string. Returns a Tree
//----------------------------------------------------------

std::string Implementation::unquote(const char* str)
{
    size_t size = strlen(str) + 1;

    //-----------copy unquoted filename-------------
    char* buf = (char*)alloca(size);
    size_t j=0;

    if (str[0] == '"') {
        // it is a quoted string, we remove the quotes
        for (size_t i=1; j<size-1 && str[i];) {
            buf[j++] = replaceCR(str[i++]);
        }
        // remove last quote
        if (j>0) buf[j-1] = 0;
    } else {
        for (size_t i=0; j<size-1 && str[i];) {
            buf[j++] = replaceCR(str[i++]);
        }
    }
    buf[j] = 0;

    return std::string(buf);
    //----------------------------------------------
}

void BisonImplementation::error (
  const location_type& loc,
  const std::string& msg
) {
    this->self.error( loc, msg );
}

void
BisonImplementation::report_syntax_error (
  const BisonImplementation::context& context
)
const
{
  this->self.reportSyntaxError( context );
}

