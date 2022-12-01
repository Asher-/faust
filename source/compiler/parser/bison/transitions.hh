
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

#ifndef __FAUST__COMPILER__PARSER__TRANSITIONS__HH__
#define __FAUST__COMPILER__PARSER__TRANSITIONS__HH__

#include <string>
#include <map>
#include <vector>

#include "compiler/errors/exception.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {

      struct Context
      {
        Context() = default;
        Context(
          const std::string&               in_symbol,
          const std::vector<std::string>&  matched_parts,
          const std::vector<std::string>&  expected_parts
        )
        :
          symbol( in_symbol ),
          matched( matched_parts ),
          expected( expected_parts )
        {}
        std::string symbol;
        std::vector<std::string> matched;
        std::vector<std::string> expected;
      };

      struct Transition
      {
        Transition() = default;
        Transition( /* States with only error have no context (and should never match). */
          const std::map<std::string, int>& tokens,
          const std::map<std::string, int>& symbols
        )
        :
          tokens( tokens ),
          symbols( symbols )
        { throw faustexception("Should never have gotten here."); }
        Transition(
          const std::vector<Context>&       contexts,
          const std::map<std::string, int>& tokens,
          const std::map<std::string, int>& symbols
        )
        :
          context( contexts ),
          tokens( tokens ),
          symbols( symbols )
        {}
        std::vector<Context>       context;
        std::map<std::string, int> tokens;
        std::map<std::string, int> symbols;
      };

      const std::vector<Transition>& transitions();

    }
  }
}

#endif

