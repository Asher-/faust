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

#ifndef __FAUST_SOURCE_COMPILER_PARSER_IMPLEMENTATION_HH__
#define __FAUST_SOURCE_COMPILER_PARSER_IMPLEMENTATION_HH__

#include <string>
#include <fstream>
#include <map>
#include <list>
#include <set>

#include "tlib/tree.hh"
#include "faust/primitive/symbols.hh"

#include "compiler/parser/lexer/implementation.hh"
#include "compiler/parser/bison/implementation.hh"
#include "compiler/parser/abstract/implementation.hh"

#include "compiler/block_diagram/boxes/boxes.hh"

/* The parser front-end driver class. */

namespace Faust {
  namespace Compiler {
    namespace Parser {
    
      struct Implementation
      :
        ::Faust::Compiler::Parser::Abstract::Implementation
      {
        using AbstractParser = ::Faust::Compiler::Parser::BisonImplementation;
        using Location = ::Faust::Compiler::Parser::Location::Implementation;
        using Lexer = ::Faust::Compiler::Parser::Lexer::Implementation;
        using symbol_type = typename AbstractParser::symbol_type;

        Implementation ()
        :
          _traceParsing(false),
          _traceScanning(false),
          _parser(*this),
          _location("Scanner")
        {
        }
        
        void setTraceParsing( const bool& true_or_false = true )
        {
          _traceParsing = true_or_false;
        }

        const bool& traceParsing()
        const
        {
          return _traceParsing;
        }

        void setTraceScanning( const bool& true_or_false = true )
        {
          _traceScanning = true_or_false;
        }

        const bool& traceScanning()
        const
        {
          return _traceScanning;
        }

        Tree parseStream(
          std::istream& in,
          const std::string& stream_name
        )
        override
        {
          _streamName = stream_name;

          Lexer lexer( *this, &in );
          _lexer = &lexer;
          _lexer->set_debug( _traceScanning );

          _parser.set_debug_level( _traceParsing );

          _result = _parser();
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
        )
        override
        {
          std::ifstream in(filename.c_str());
          if (!in.good()) return nullptr;
          return parseStream(in, filename);
        }

        Tree
        parseString(
          const std::string& input,
          const std::string& stream_name
        )
        override
        {
          std::istringstream iss(input);
          return parseStream(iss, stream_name);
        }
        
        template
        <
          typename RHSLocations,
          typename StackSymbolType
        >
        void
        tokenDidMatch(
          StackSymbolType&    symbol,
          const std::size_t&  count,
          RHSLocations&       rhs_locations
        ) {
          Location& location = symbol.location;
          location.streamName() = _location.streamName();
          location.name() = _parser.symbol_name( symbol.kind() );
          if ( count ) {
            location.begin()   = rhs_locations[1].location.begin();
            location.end()     = rhs_locations[count-1].location.end();
            for ( std::size_t index = 0 ; index < count - 1 ; ++index ) {
              const auto& this_symbol_part{rhs_locations[index+1]};
              Location this_location_part{this_symbol_part.location};
              this_location_part.name() = _parser.symbol_name( this_symbol_part.kind() );
              location.parts().push_back(this_location_part);
            }
          }
          else {
            location = _location;
          }
          /* Advance our tracking location. */
          _location = location;
          _location.begin() = _location.end();
        }
        
        template <typename StackType>
        void
        copyStackToLocationParts(
          StackType& stack,
          Location& location
        )
        {
          auto iterator = stack.begin() + 1;
          auto iterator_last = stack.end() - 1;
          location.begin()   = iterator->location.begin();
          location.end()     = iterator_last->location.end();
          location.streamName() = _location.streamName();
          location.name() = _parser.symbol_name( iterator->kind() );
          for ( ++iterator; iterator < stack.end() ; ++iterator ) {
            const auto& this_symbol_part{*iterator};
            Location this_location_part{this_symbol_part.location};
            this_location_part.name() = _parser.symbol_name( this_symbol_part.kind() );
            location.parts().push_back(this_location_part);
          }
        }

        void
        error(
          const Location& l,
          const std::string& m
        ) {
          std::cerr << l << ": " << m << std::endl;
        }

        void error(const std::string& m)
        {
          std::cerr << m << std::endl;
        }

        void
        report_syntax_error (
          const BisonImplementation::context& context
        )
        {
          std::cerr << "Syntax error: " << std::endl;

          auto& stack = _parser.yystack();
          Location syntax_error;
          copyStackToLocationParts( stack, syntax_error );

          /* Ask Parser to provide expected tokens. */
          int expected_token_count = context.expected_tokens( nullptr, 0 );
          BisonImplementation::symbol_kind_type expected_tokens[expected_token_count];
          context.expected_tokens(expected_tokens, expected_token_count);
          

          // now we want to create a fake location to append to parts
          // it will hold all the possible matches we are looking for (from state)
          
          auto state = _parser.yy_lr_goto_state_( stack[2].state, _parser.yyr1()[expected_tokens[0]]);
 
          auto symbol = YY_CAST(BisonImplementation::symbol_kind_type, _parser.yystos()[+state]);
          auto symbol_name = _parser.symbol_name(symbol);
          
          syntax_error.printStack(std::cerr);
          
          constexpr std::array<std::string_view, 2> phrase{ ": expected ", " or " };
          for ( int index = 0; index < expected_token_count; ++index ) {
            std::cerr << phrase[!!index]
                      << BisonImplementation::symbol_name( expected_tokens[index] );
          }
          BisonImplementation::symbol_kind_type token_type = context.token();
          if ( token_type != BisonImplementation::symbol_kind::S_YYEMPTY ) {
            std::cerr << " before " << BisonImplementation::symbol_name(token_type);
          }
          std::cerr << std::endl;
        }
        
        Tree checkRulelist(Tree lr);

        string printPatternError(Tree symbol, Tree lhs1, Tree rhs1, Tree lhs2, Tree rhs2);

        string printRedefinitionError(Tree symbol, std::list<Tree>& variants);

        void checkName();

        void declareMetadata(Tree key, Tree value);

        /*
        fun -> (file*fun -> {key*value,...})

        gFunMDSet()[fun].insert(file*fun*key*value);
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
        // characters from string.
        //----------------------------------------------------------

        std::string unquote(const char* str);


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
        
        Location& location() { return _location; }
        const Location& location() const { return _location; }
        



        std::string _streamName;
        
        bool _traceParsing;
        bool _traceScanning;

        Lexer* _lexer = nullptr;
        AbstractParser _parser;
        Location _location;
        int _result = 0;
        Tree _ast = nullptr;
    
        // From gGlobal - for now we simply mirror

        using Sym = ::Faust::Primitive::Symbol::Abstract::Implementation*;

        bool _stripDocSwitch = true;
        bool _lstDependenciesSwitch = true;
        bool _lstDistributedSwitch = true;

        
      };


    };
  };
};

struct comp_str {
    bool operator()(Tree s1, Tree s2) const { return tree2str(s1) == tree2str(s2); }
};

typedef map<Tree, set<Tree>> FunMDSet;  // foo -> {(file/foo/key,value)...}
typedef map<Tree, std::set<Tree>, comp_str> MetaDataSet;

std::string& gMasterDocument();
MetaDataSet& gMetaDataSet();
FunMDSet& gFunMDSet();

std::string& gOutputLang();

#endif

