#!/bin/bash

# match state transition blocks
# State (?<state>\d+)[\s\n]+(^\s*)(?:\d+.+[\s]+\n)+(?<shifts>(?:\s*[A-Z0-9_]+\s+shift, and go to state \d+\n\s*)*)(?:\s*\$default.+\n+)*(?<reductions>(?:\s*[a-z\.]+\s+go to state \d+\n)*)

# state[$1] = {\n$2$3$4}

# match token shift transitions
# (?<token>[A-Z0-9_]+)\s+shift, and go to state (?<state>\d+)

# match rule reduce transitions
# ^\s*(?<rule>[a-z\.]+)\s+go to state (\d+)

GSED=`which gsed`   # GNU sed 4.9
GGREP=`which ggrep` # GNU grep 3.8
PERL=`which perl`

BISON_DETAIL_OUTPUT=bison/implementation.output
TRANSITIONS_FILE=bison/transitions
TRANSITIONS_FILE_HH=${TRANSITIONS_FILE}.hh
TRANSITIONS_FILE_CPP=${TRANSITIONS_FILE}.cpp

if [ ! -f ${BISON_DETAIL_OUTPUT} ] ; then
	if [ -z "${BISON_DETAIL_OUTPUT}"] ; then
		echo "BISON_DETAIL_OUTPUT not defined. Where is the Bison %verbose detail .output file?"
	else
		echo "Bison %verbose detail .output file ${BISON_DETAIL_OUTPUT} did not exist."
	fi
fi

OUTPUT_CPP_TOP="
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

=INCLUDE_GUARD_TOP=

#include \"compiler/errors/exception.hh\"

namespace Faust {
  namespace Compiler {
    namespace Parser {
"

OUTPUT_CPP_BOTTOM="
    }
  }
}

=INCLUDE_GUARD_BOTTOM=
"

TRANSITION_CLASS="
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
        { throw faustexception(\"Should never have gotten here.\"); }
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
"

# Create transitions.hh with all %verbose .output lines that include "State" or "go to".
${GGREP} -P -v 'error' ${BISON_DETAIL_OUTPUT} | ${GGREP} -P '(?=State|•|go to)' > ${TRANSITIONS_FILE_CPP}
echo "/* std::vector<std::map<std::string,int>> */" >> ${TRANSITIONS_FILE_CPP}
# Add brackets to state description.
${PERL} -i -p0e  's/((^.*•.*\n)+)/  \{\n$1  \}\n/mg' ${TRANSITIONS_FILE_CPP}
# Add brackets to transition blocks for tokens
${PERL} -i -p0e  's/(^(\s+([A-Za-z0-9_]+)\s+shift, and go to state [0-9]+\n)+)/  \{\n$1  \}\n/mg' ${TRANSITIONS_FILE_CPP}
# Add brackets to transition blocks for symbols
${PERL} -i -p0e  's/(^(\s+([A-Za-z0-9_\.]+)\s+(?<!shift, and )go to state [0-9]+\n)+)/  \{\n$1  \}\n/mg' ${TRANSITIONS_FILE_CPP}
# Add empty symbols to states that only have tokens
${PERL} -i -p0e  's/(State [0-9]+\s*\{[A-Za-z0-9\s\$\_|:•\.]+\}\s*\{[A-Za-z0-9\s,_]+\}\s*\n)(?=State|\/\* std::vector<std::map<std::string,int>> \*\/)/$1  \{\}\n/mg' ${TRANSITIONS_FILE_CPP}
# Add empty tokens to states that only have symbols
${PERL} -i -p0e  's/(State [0-9]+\s*\{[A-Za-z0-9\s\$_\|:•\.]+\}\s*\{[A-Za-z0-9\s,_]+\}\s*\n)(?=State|\/\* std::vector<std::map<std::string,int>> \*\/)/$1  \{\}\n/mg' ${TRANSITIONS_FILE_CPP}
# Add empty tokens and symbols to states that have no tokens or symbols
${PERL} -i -p0e  's/(State [0-9]+\s*\{[A-Za-z0-9\s\$_\|:•\.]+\}\n)(?=State|\/\* std::vector<std::map<std::string,int>> \*\/)/$1  \{\}\n  \{\}\n/mg' ${TRANSITIONS_FILE_CPP}
# Replace token transition lines
${PERL} -i -p0e  's/([A-Z0-9_]+|error)\s+shift, and go to state (\d+)/\{\"$1\", $2\}/g' ${TRANSITIONS_FILE_CPP}
# Replace rule transition lines
${PERL} -i -p0e  's/([a-z0-9_\.]+)\s+go to state (\d+)/{\"$1\", $2}/g' ${TRANSITIONS_FILE_CPP}
# Reformat Context description
${PERL} -i -p0e  's/^\s+[0-9]+ ([A-Za-z0-9 \$\|\._]*)(:|\|) ([A-Za-z0-9 \._]*) ?• ?([A-Za-z0-9 \._]*)/    Context(\n      "$1",\n      "$3 ",\n      "$4 "\n    )/mg' ${TRANSITIONS_FILE_CPP}
# Add State close bracket to each State
${PERL} -i -p0e  's/(\}\n)(?=State [0-9]+|\/\* std::vector<std::map<std::string,int>> \*\/)/$1\}\n$2/mg' ${TRANSITIONS_FILE_CPP}
# Add State open bracket to each State
${PERL} -i -p0e  's/(State [0-9]+)/\{ \/\* $1 \*\//mg' ${TRANSITIONS_FILE_CPP}
# Add empty Context to error states
${PERL} -i -p0e  's/(\{ \/\* State [0-9]+ \*\/)(?!\n  \{\n    Context)/$1\n  \{\n    Context\(\n      \"error\",\n      \{\}\n      \{\}\n    \)\n  \}/mg' ${TRANSITIONS_FILE_CPP}
# Add empty tokens and symbols to error states with neither.
${PERL} -i -p0e  's/(\)\s+\})(?=\s+\{ \/\* State)/$1\n  \{\}\n  \{\}\n\}/mg' ${TRANSITIONS_FILE_CPP}
# Add empty symbols to error states with only tokens.
${PERL} -i -p0e  's/([A-Z0-9_]+\", [0-9]+\}\n\s+\}\n)(\})/$1  \{\}\n$2/mg' ${TRANSITIONS_FILE_CPP}
# Reformat Context parts
#   Convert spaced strings to quoted strings
${PERL} -i -p0e  's/([A-Za-z0-9\._]+)\s+(?=[A-Za-z0-9\s.Z_]*\")/"$1", /mg' ${TRANSITIONS_FILE_CPP}
#   Replace '" "' with '{}'
${PERL} -i -p0e  's/\" \"/\{\}/mg' ${TRANSITIONS_FILE_CPP}
#   Replace '""' with '{ "'
${PERL} -i -p0e  's/\"\"/\{ \"/mg' ${TRANSITIONS_FILE_CPP}
#   Replace ', ",' with '" }'
${PERL} -i -p0e  's/\", \",?(?=\s+\)|\s+\{)/\" \}/mg' ${TRANSITIONS_FILE_CPP}

# Add commas
${PERL} -i -p0e  's/(\}|\))(?=\s*\{|\s*Context\()/$1,/g' ${TRANSITIONS_FILE_CPP}

# Add indentation
${PERL} -i -p0e  's/^/          /mg' ${TRANSITIONS_FILE_CPP}

TRANSITIONS=`cat ${TRANSITIONS_FILE_CPP}`

DECLARATION="      const std::vector<Transition>& transitions();"
DEFINITION_TOP="      const std::vector<Transition>& transitions()
      {
        static std::vector<Transition> transitions_map{"
DEFINITION_BOTTOM="        };
        return transitions_map;
      }"

echo "${OUTPUT_CPP_TOP}${TRANSITION_CLASS}
${DECLARATION}" > ${TRANSITIONS_FILE_HH}
${PERL} -i -p0e  "s/=INCLUDE_GUARD_TOP=/#ifndef __FAUST__COMPILER__PARSER__TRANSITIONS__HH__\n#define __FAUST__COMPILER__PARSER__TRANSITIONS__HH__\n\n#include <string>\n#include <map>\n#include <vector>/" ${TRANSITIONS_FILE_HH}
echo "${OUTPUT_CPP_BOTTOM}" >> ${TRANSITIONS_FILE_HH}
${PERL} -i -p0e  "s/=INCLUDE_GUARD_BOTTOM=/#endif/" ${TRANSITIONS_FILE_HH}

echo "${OUTPUT_CPP_TOP}" > ${TRANSITIONS_FILE_CPP}
echo "${DEFINITION_TOP}" >> ${TRANSITIONS_FILE_CPP}
echo "${TRANSITIONS}" >> ${TRANSITIONS_FILE_CPP}
echo "${DEFINITION_BOTTOM}" >> ${TRANSITIONS_FILE_CPP}
echo "${OUTPUT_CPP_BOTTOM}" >> ${TRANSITIONS_FILE_CPP}
${PERL} -i -p0e  "s/=INCLUDE_GUARD_TOP=/#include \"compiler\/parser\/bison\/transitions.hh\"/" ${TRANSITIONS_FILE_CPP}
${PERL} -i -p0e  "s/\n\n=INCLUDE_GUARD_BOTTOM=\n//" ${TRANSITIONS_FILE_CPP}

