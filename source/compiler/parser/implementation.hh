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

#ifndef __FAUST_SOURCE_COMPILER_PARSER_IMPLEMENTATION_HH__
#define __FAUST_SOURCE_COMPILER_PARSER_IMPLEMENTATION_HH__

#include <string>
#include <fstream>
#include <map>
#include <list>

#include "tlib/tree.hh"
#include "tlib/symbol.hh"

#include "compiler/parser/lexer/implementation.hh"
#include "compiler/parser/abstract/implementation.hh"

#include "compiler/block_diagram/boxes/boxes.hh"

/* The parser front-end driver class. */

namespace Faust {
  namespace Compiler {
    namespace Parser {
    
      struct Implementation
      {
        using AbstractParser = ::Faust::Compiler::Parser::AbstractImplementation;
        using Location = ::Faust::Compiler::Parser::location;
        using Lexer = ::Faust::Compiler::Parser::Lexer::Implementation;

        Implementation ()
        :
          _traceParsing(false),
          _traceScanning(false),
          _parser(*this)
        {
        }

        int
        scan()
        {
          _parser.set_debug_level( _traceParsing );
          int result_state = _parser();
          return result_state;
        }

        Tree parseStream(
          std::istream& in,
          const std::string& stream_name
        ) {
          _streamName = stream_name;

          Lexer lexer( *this, &in );
          _lexer = &lexer;
          _lexer->set_debug( _traceScanning );

          AbstractParser parser(*this);
          parser.set_debug_level( _traceParsing );
          _result = parser();
          _lexer = nullptr;

          if (_result) {
              std::stringstream error;
              error << "ERROR : parse code = " << _result << endl;
              throw faustexception(error.str());
          }

          /* We have parsed a valid file */
          checkName();

          return _ast;
        }

        Tree
        parseFile(
          const std::string& filename
        ) {
          std::ifstream in(filename.c_str());
          if (!in.good()) return nullptr;
          return parseStream(in, filename);
        }

        Tree
        parseString(
          const std::string& input,
          const std::string& stream_name
        ) {
          std::istringstream iss(input);
          return parseStream(iss, stream_name);
        }

        void
        error(
          const class location& l,
          const std::string& m
        ) {
          std::cerr << l << ": " << m << std::endl;
        }

        void error(const std::string& m)
        {
          std::cerr << m << std::endl;
        }

        Tree checkRulelist(Tree lr);

        string printPatternError(Tree symbol, Tree lhs1, Tree rhs1, Tree lhs2, Tree rhs2);

        string printRedefinitionError(Tree symbol, std::list<Tree>& variants);

        void checkName();

        void declareMetadata(Tree key, Tree value);

        /*
        fun -> (file*fun -> {key*value,...})

        gGlobal->gFunMetaDataSet[fun].insert(file*fun*key*value);
        gFunMetaDataSet = map<tree, tuple<Tree,Tree,Tree,Tree>>
        */

        // Called by parser to create function's metadata
        void declareDefinitionMetadata(Tree id, Tree key, Tree value);

        /**
         * Transforms a list of variants (arglist.body)
         * into an abstraction or a boxCase.
         * @param symbol name only used in case of error
         * @param variants list of variants (arglist.body)
         * @return the corresponding box expression
         */

        Tree makeDefinition(Tree symbol, std::list<Tree>& variants);

        /**
         * Formats a list of raw definitions represented by triplets
         * <name, arglist, body> into abstractions or pattern
         * matching rules when appropriate.
         *
         * @param rldef list of raw definitions in reverse order
         * @return the list of formatted definitions
         */

        Tree formatDefinitions(Tree rldef);

        /**
         * Checks an argument list for containing only
         * standard identifiers, no patterns and
         * is linear.
         * @param args the argument list to check
         * @return true if it contains only identifiers
         */

        static bool standardArgList(Tree args);

        std::string stripEnd(const std::string& name, const std::string& ext);

        //----------------------------------------------------------
        // unquote() : remove enclosing quotes and carriage return
        // characters from string. Returns a Tree
        //----------------------------------------------------------

        Tree unquote(const char* str);


        char replaceCR(char c);

        //----------------------------------------------------------
        // A definition is accepted if the prefixset is empty or if
        // the current float precision is member of the prefix set
        //----------------------------------------------------------
        bool acceptdefinition(int prefixset);

        //----------------------------------------------------------
        // 'atoi' does not work correctly on Windows with MSVC on values
        // greater than 2^31 (= 2147483648)
        //----------------------------------------------------------
        int str2int(const char* str);

        std::string _streamName;
        
        bool _traceParsing;
        bool _traceScanning;

        Lexer* _lexer = nullptr;
        AbstractParser _parser;
        Location _location;
        int _result = 0;
        Tree _ast = nullptr;
    
        // From gGlobal - for now we simply mirror

        using Sym = Symbol*;

        Sym NIL = symbol("nil");
        Tree _nil = tree(NIL);
        bool _stripDocSwitch = true;
        bool _lstDependenciesSwitch = true;
        bool _lstDistributedSwitch = true;

        
      };
      
    };
  };
};

#endif

