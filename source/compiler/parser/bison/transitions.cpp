
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

#include "compiler/parser/bison/transitions.hh"

namespace Faust {
  namespace Compiler {
    namespace Parser {

      const std::vector<Transition>& transitions()
      {
        static std::vector<Transition> transitions_map{
          { /* State 0 */
            {
              Context(
                "$accept",
                {},
                { "program", "ENDOFINPUT" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"program", 10},
              {"statement", 11},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.list", 21},
              {"statement.list.start", 22},
              {"statement.list.start.qualified", 23},
              {"statement.list.append", 24},
              {"statement.list.append.qualified", 25},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 27},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 1 */
            {
              Context(
                "statement.definition.function",
                { "ENDDEF" },
                { "error" }
              )
            },
            {
              {"error", 30}
            },
            {}
          },
          { /* State 2 */
            {
              Context(
                "statement.import",
                { "IMPORT" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR", "ENDDEF" }
              )
            },
            {
              {"LPAR", 31}
            },
            {}
          },
          { /* State 3 */
            {
              Context(
                "statement.box.identifier.as.tree",
                { "IDENT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 4 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE" },
                { "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "ENDDEF" }
              ),
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE" },
                { "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "ENDDEF" }
              )
            },
            {
              {"IDENT", 32}
            },
            {
              {"statement.identifier.as.tree", 33}
            }
          },
          { /* State 5 */
            {
              Context(
                "statement.math.precision",
                { "FLOATMODE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 6 */
            {
              Context(
                "statement.math.precision",
                { "DOUBLEMODE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 7 */
            {
              Context(
                "statement.math.precision",
                { "QUADMODE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 8 */
            {
              Context(
                "statement.math.precision",
                { "FIXEDPOINTMODE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 9 */
            {
              Context(
                "statement.declare.doc",
                { "BDOC" },
                { "doc", "EDOC" }
              )
            },
            {
              {"BEQN", 34},
              {"BDGM", 35},
              {"BLST", 36},
              {"BMETADATA", 37},
              {"DOCCHAR", 38},
              {"NOTICE", 39}
            },
            {
              {"doc", 40},
              {"doc.text", 41},
              {"doc.equation", 42},
              {"doc.diagram", 43},
              {"doc.notice", 44},
              {"doc.metadata", 45},
              {"doc.list", 46}
            }
          },
          { /* State 10 */
            {
              Context(
                "$accept",
                { "program" },
                { "ENDOFINPUT" }
              )
            },
            {
              {"ENDOFINPUT", 47}
            },
            {}
          },
          { /* State 11 */
            {
              Context(
                "statement.list.start",
                { "statement" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 12 */
            {
              Context(
                "statement",
                { "statement.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 13 */
            {
              Context(
                "statement.definition.function",
                { "statement.definition.function.declaration" },
                { "ENDDEF" }
              ),
              Context(
                "                             ",
                { "statement.definition.function.declaration" },
                { "ENDOFINPUT" }
              ),
              Context(
                "                             ",
                { "statement.definition.function.declaration" },
                { "ENDL" }
              )
            },
            {
              {"ENDOFINPUT", 48},
              {"ENDDEF", 49},
              {"ENDL", 50}
            },
            {}
          },
          { /* State 14 */
            {
              Context(
                "statement.definition",
                { "statement.definition.function" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 15 */
            {
              Context(
                "statement.definition",
                { "statement.definition.assignment" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 16 */
            {
              Context(
                "statement",
                { "statement.declare.metadata" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 17 */
            {
              Context(
                "statement",
                { "statement.declare.feature.metadata" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 18 */
            {
              Context(
                "statement",
                { "statement.declare.doc" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 19 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree" },
                { "LPAR", "statement.definition.function.args", "RPAR", "DEF", "expression" }
              ),
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree" },
                { "statement.definition.assignment.operator", "expression", "statement.definition.assignment.terminal" }
              )
            },
            {
              {"LPAR", 51},
              {"DEF", 52}
            },
            {
              {"statement.definition.assignment.operator", 53}
            }
          },
          { /* State 20 */
            {
              Context(
                "statement",
                { "statement.import" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 21 */
            {
              Context(
                "program",
                { "statement.list" },
                {}
              ),
              Context(
                "statement.list.append",
                { "statement.list" },
                { "statement" }
              ),
              Context(
                "statement.list.append.qualified",
                { "statement.list" },
                { "statement.math.precision.list", "statement" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"statement", 54},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 55},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 22 */
            {
              Context(
                "statement.list",
                { "statement.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 23 */
            {
              Context(
                "statement.list",
                { "statement.list.start.qualified" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 24 */
            {
              Context(
                "statement.list",
                { "statement.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 25 */
            {
              Context(
                "statement.list",
                { "statement.list.append.qualified" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 26 */
            {
              Context(
                "statement.math.precision.list.start",
                { "statement.math.precision" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 27 */
            {
              Context(
                "statement.list.start.qualified",
                { "statement.math.precision.list" },
                { "statement" }
              ),
              Context(
                "statement.math.precision.list.append",
                { "statement.math.precision.list" },
                { "statement.math.precision" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"statement", 56},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.math.precision", 57}
            }
          },
          { /* State 28 */
            {
              Context(
                "statement.math.precision.list",
                { "statement.math.precision.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 29 */
            {
              Context(
                "statement.math.precision.list",
                { "statement.math.precision.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 30 */
            {
              Context(
                "statement.definition.function",
                { "ENDDEF", "error" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 31 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR", "ENDDEF" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 60}
            }
          },
          { /* State 32 */
            {
              Context(
                "statement.identifier.as.tree",
                { "IDENT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 33 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree" },
                { "primitive.string.quoted.as.tree", "ENDDEF" }
              ),
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree" },
                { "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "ENDDEF" }
              )
            },
            {
              {"STRING", 61},
              {"IDENT", 32}
            },
            {
              {"primitive.string.quoted", 62},
              {"primitive.string.quoted.as.tree", 63},
              {"statement.identifier.as.tree", 64}
            }
          },
          { /* State 34 */
            {
              Context(
                "doc.equation",
                { "BEQN" },
                { "expression", "EEQN" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 149},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 35 */
            {
              Context(
                "doc.diagram",
                { "BDGM" },
                { "expression", "EDGM" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 233},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 36 */
            {
              Context(
                "doc.list",
                { "BLST" },
                { "doc.attribute.list", "ELST" }
              ),
              Context(
                "        ",
                { "BLST" },
                { "ELST" }
              )
            },
            {
              {"ELST", 234},
              {"LSTDEPENDENCIES", 235},
              {"LSTMDOCTAGS", 236},
              {"LSTDISTRIBUTED", 237}
            },
            {
              {"doc.attribute.list", 238},
              {"doc.attribute.definition", 239}
            }
          },
          { /* State 37 */
            {
              Context(
                "doc.metadata",
                { "BMETADATA" },
                { "statement.identifier.as.tree", "EMETADATA" }
              )
            },
            {
              {"IDENT", 32}
            },
            {
              {"statement.identifier.as.tree", 240}
            }
          },
          { /* State 38 */
            {
              Context(
                "doc.text",
                { "DOCCHAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 39 */
            {
              Context(
                "doc.notice",
                { "NOTICE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 40 */
            {
              Context(
                "statement.declare.doc",
                { "BDOC", "doc" },
                { "EDOC" }
              )
            },
            {
              {"EDOC", 241}
            },
            {}
          },
          { /* State 41 */
            {
              Context(
                "doc",
                { "doc.text" },
                {}
              ),
              Context(
                "doc.text",
                { "doc.text" },
                { "DOCCHAR" }
              )
            },
            {
              {"DOCCHAR", 242}
            },
            {}
          },
          { /* State 42 */
            {
              Context(
                "doc",
                { "doc.equation" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 43 */
            {
              Context(
                "doc",
                { "doc.diagram" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 44 */
            {
              Context(
                "doc",
                { "doc.notice" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 45 */
            {
              Context(
                "doc",
                { "doc.metadata" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 46 */
            {
              Context(
                "doc",
                { "doc.list" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 47 */
            {
              Context(
                "$accept",
                { "program", "ENDOFINPUT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 48 */
            {
              Context(
                "statement.definition.function",
                { "statement.definition.function.declaration", "ENDOFINPUT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 49 */
            {
              Context(
                "statement.definition.function",
                { "statement.definition.function.declaration", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 50 */
            {
              Context(
                "statement.definition.function",
                { "statement.definition.function.declaration", "ENDL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 51 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR" },
                { "statement.definition.function.args", "RPAR", "DEF", "expression" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 244},
              {"statement.definition.function.args", 245},
              {"statement.definition.function.args.start", 246},
              {"statement.definition.function.args.append", 247},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 52 */
            {
              Context(
                "statement.definition.assignment.operator",
                { "DEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 53 */
            {
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree", "statement.definition.assignment.operator" },
                { "expression", "statement.definition.assignment.terminal" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 248},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 54 */
            {
              Context(
                "statement.list.append",
                { "statement.list", "statement" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 55 */
            {
              Context(
                "statement.list.append.qualified",
                { "statement.list", "statement.math.precision.list" },
                { "statement" }
              ),
              Context(
                "statement.math.precision.list.append",
                { "statement.math.precision.list" },
                { "statement.math.precision" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"statement", 249},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.math.precision", 57}
            }
          },
          { /* State 56 */
            {
              Context(
                "statement.list.start.qualified",
                { "statement.math.precision.list", "statement" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 57 */
            {
              Context(
                "statement.math.precision.list.append",
                { "statement.math.precision.list", "statement.math.precision" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 58 */
            {
              Context(
                "primitive.string.unquoted",
                { "STRING" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 59 */
            {
              Context(
                "primitive.string.unquoted.as.tree",
                { "primitive.string.unquoted" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 60 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR", "ENDDEF" }
              )
            },
            {
              {"RPAR", 250}
            },
            {}
          },
          { /* State 61 */
            {
              Context(
                "primitive.string.quoted",
                { "STRING" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 62 */
            {
              Context(
                "primitive.string.quoted.as.tree",
                { "primitive.string.quoted" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 63 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree", "primitive.string.quoted.as.tree" },
                { "ENDDEF" }
              )
            },
            {
              {"ENDDEF", 251}
            },
            {}
          },
          { /* State 64 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree" },
                { "primitive.string.quoted.as.tree", "ENDDEF" }
              )
            },
            {
              {"STRING", 61}
            },
            {
              {"primitive.string.quoted", 62},
              {"primitive.string.quoted.as.tree", 252}
            }
          },
          { /* State 65 */
            {
              Context(
                "expression.math.comparison",
                { "LT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 66 */
            {
              Context(
                "expression.math.comparison",
                { "LE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 67 */
            {
              Context(
                "expression.math.comparison",
                { "EQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 68 */
            {
              Context(
                "expression.math.comparison",
                { "GT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 69 */
            {
              Context(
                "expression.math.comparison",
                { "GE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 70 */
            {
              Context(
                "expression.math.comparison",
                { "NE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 71 */
            {
              Context(
                "expression.math.signal.algebra",
                { "ADD" },
                {}
              ),
              Context(
                "expression.math.scalar.int",
                { "ADD" },
                { "INT" }
              ),
              Context(
                "expression.math.scalar.float",
                { "ADD" },
                { "FLOAT" }
              )
            },
            {
              {"INT", 253},
              {"FLOAT", 254}
            },
            {}
          },
          { /* State 72 */
            {
              Context(
                "expression.math.signal.algebra",
                { "SUB" },
                {}
              ),
              Context(
                "                              ",
                { "SUB" },
                { "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.math.scalar.int",
                { "SUB" },
                { "INT" }
              ),
              Context(
                "expression.math.scalar.float",
                { "SUB" },
                { "FLOAT" }
              )
            },
            {
              {"INT", 255},
              {"FLOAT", 256},
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 257}
            }
          },
          { /* State 73 */
            {
              Context(
                "expression.signal.logic",
                { "OR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 74 */
            {
              Context(
                "expression.math.signal.algebra",
                { "MUL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 75 */
            {
              Context(
                "expression.math.signal.algebra",
                { "DIV" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 76 */
            {
              Context(
                "expression.math.signal.algebra",
                { "MOD" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 77 */
            {
              Context(
                "expression.signal.logic",
                { "AND" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 78 */
            {
              Context(
                "expression.signal.logic",
                { "XOR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 79 */
            {
              Context(
                "expression.math.signal.shift",
                { "LSH" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 80 */
            {
              Context(
                "expression.math.signal.shift",
                { "RSH" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 81 */
            {
              Context(
                "expression.math.signal.power",
                { "POWOP" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 82 */
            {
              Context(
                "expression.signal.delay",
                { "FDELAY" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 83 */
            {
              Context(
                "expression.signal.delay",
                { "MEM" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 84 */
            {
              Context(
                "expression.signal.delay",
                { "PREFIX" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 85 */
            {
              Context(
                "primitive.type.cast.number.int",
                { "INTCAST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 86 */
            {
              Context(
                "primitive.type.cast.number.float",
                { "FLOATCAST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 87 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION" },
                { "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 258}
            },
            {}
          },
          { /* State 88 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT" },
                { "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 259}
            },
            {}
          },
          { /* State 89 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE" },
                { "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 260}
            },
            {}
          },
          { /* State 90 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 261}
            },
            {}
          },
          { /* State 91 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 262}
            },
            {}
          },
          { /* State 92 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LPAR", 263}
            },
            {}
          },
          { /* State 93 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LPAR", 264}
            },
            {}
          },
          { /* State 94 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LPAR", 265}
            },
            {}
          },
          { /* State 95 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 266}
            },
            {}
          },
          { /* State 96 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 267}
            },
            {}
          },
          { /* State 97 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 268}
            },
            {}
          },
          { /* State 98 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LPAR", 269}
            },
            {}
          },
          { /* State 99 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LPAR", 270}
            },
            {}
          },
          { /* State 100 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition", "RPAR" }
              )
            },
            {
              {"LPAR", 271}
            },
            {}
          },
          { /* State 101 */
            {
              Context(
                "expression.signal.control",
                { "ATTACH" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 102 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "ACOS" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 103 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "ASIN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 104 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "ATAN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 105 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "ATAN2" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 106 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "COS" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 107 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "SIN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 108 */
            {
              Context(
                "expression.math.trigonometry.as.tree",
                { "TAN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 109 */
            {
              Context(
                "expression.math.signal.power",
                { "EXP" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 110 */
            {
              Context(
                "expression.math.signal.power",
                { "LOG" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 111 */
            {
              Context(
                "expression.math.signal.power",
                { "LOG10" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 112 */
            {
              Context(
                "expression.math.signal.power",
                { "POWFUN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 113 */
            {
              Context(
                "expression.math.signal.power",
                { "SQRT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 114 */
            {
              Context(
                "expression.math.rounding",
                { "ABS" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 115 */
            {
              Context(
                "expression.math.rounding",
                { "MIN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 116 */
            {
              Context(
                "expression.math.rounding",
                { "MAX" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 117 */
            {
              Context(
                "expression.math.signal.algebra",
                { "FMOD" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 118 */
            {
              Context(
                "expression.math.signal.algebra",
                { "REMAINDER" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 119 */
            {
              Context(
                "expression.math.rounding",
                { "FLOOR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 120 */
            {
              Context(
                "expression.math.rounding",
                { "CEIL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 121 */
            {
              Context(
                "expression.math.rounding",
                { "RINT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 122 */
            {
              Context(
                "primitive.signal.source.table",
                { "RDTBL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 123 */
            {
              Context(
                "primitive.signal.source.table",
                { "RWTBL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 124 */
            {
              Context(
                "expression.signal.logic",
                { "SELECT2" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 125 */
            {
              Context(
                "expression.signal.logic",
                { "SELECT3" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 126 */
            {
              Context(
                "primitive.type.number.int",
                { "INT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 127 */
            {
              Context(
                "primitive.type.number.float",
                { "FLOAT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 128 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA" },
                { "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 272}
            },
            {}
          },
          { /* State 129 */
            {
              Context(
                "primitive.signal.input.wire",
                { "WIRE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 130 */
            {
              Context(
                "primitive.signal.input.terminate",
                { "CUT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 131 */
            {
              Context(
                "expression.parenthesis",
                { "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 273},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 132 */
            {
              Context(
                "expression.component",
                { "COMPONENT" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 274}
            },
            {}
          },
          { /* State 133 */
            {
              Context(
                "expression.library",
                { "LIBRARY" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 275}
            },
            {}
          },
          { /* State 134 */
            {
              Context(
                "expression.environment",
                { "ENVIRONMENT" },
                { "LBRAQ", "statement.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 276}
            },
            {}
          },
          { /* State 135 */
            {
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM" },
                { "LBRAQ", "primitive.type.number.list.as.tree", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 277}
            },
            {}
          },
          { /* State 136 */
            {
              Context(
                "primitive.signal.route.implied.outputs",
                { "ROUTE" },
                { "LPAR", "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE" },
                { "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE" },
                { "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 278}
            },
            {}
          },
          { /* State 137 */
            {
              Context(
                "expression.signal.control",
                { "ENABLE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 138 */
            {
              Context(
                "expression.signal.control",
                { "CONTROL" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 139 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL" },
                { "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 279}
            },
            {}
          },
          { /* State 140 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ" },
                { "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 280}
            },
            {}
          },
          { /* State 141 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM" },
                { "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 281}
            },
            {}
          },
          { /* State 142 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD" },
                { "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 282}
            },
            {}
          },
          { /* State 143 */
            {
              Context(
                "primitive.signal.inputs",
                { "INPUTS" },
                { "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 283}
            },
            {}
          },
          { /* State 144 */
            {
              Context(
                "primitive.signal.outputs",
                { "OUTPUTS" },
                { "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 284}
            },
            {}
          },
          { /* State 145 */
            {
              Context(
                "expression.signal.logic",
                { "CASE" },
                { "LBRAQ", "statement.signal.pattern.rule.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 285}
            },
            {}
          },
          { /* State 146 */
            {
              Context(
                "expression.math.rounding",
                { "ASSERTBOUNDS" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 147 */
            {
              Context(
                "expression.math.rounding",
                { "LOWEST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 148 */
            {
              Context(
                "expression.math.rounding",
                { "HIGHEST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 149 */
            {
              Context(
                "doc.equation",
                { "BEQN", "expression" },
                { "EEQN" }
              ),
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"EEQN", 289}
            },
            {}
          },
          { /* State 150 */
            {
              Context(
                "expression.infix",
                { "expression.component" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 151 */
            {
              Context(
                "expression",
                { "expression.composition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 152 */
            {
              Context(
                "expression.composition",
                { "expression.composition.parallel" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 153 */
            {
              Context(
                "expression.composition",
                { "expression.composition.serial" },
                {}
              ),
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293}
            },
            {}
          },
          { /* State 154 */
            {
              Context(
                "expression.composition.serial",
                { "expression.composition.mix" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 155 */
            {
              Context(
                "expression.composition.serial",
                { "expression.composition.recursive" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 156 */
            {
              Context(
                "expression.composition.serial",
                { "expression.composition.sequence" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 157 */
            {
              Context(
                "expression.composition.serial",
                { "expression.composition.split" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 158 */
            {
              Context(
                "expression.infix",
                { "expression.environment" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 159 */
            {
              Context(
                "expression.composition.serial",
                { "expression.infix" },
                {}
              ),
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"LT", 294},
              {"LE", 295},
              {"EQ", 296},
              {"GT", 297},
              {"GE", 298},
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 160 */
            {
              Context(
                "expression.infix",
                { "expression.infix.definitions.substitution" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 161 */
            {
              Context(
                "expression.infix",
                { "expression.infix.environment.access" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 162 */
            {
              Context(
                "expression.infix",
                { "expression.infix.math" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 163 */
            {
              Context(
                "expression.infix.math",
                { "expression.infix.math.algebra" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 164 */
            {
              Context(
                "expression.infix.math",
                { "expression.infix.math.comparison" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 165 */
            {
              Context(
                "expression.infix.math",
                { "expression.infix.math.logic" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 166 */
            {
              Context(
                "expression.infix.math",
                { "expression.infix.math.shift" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 167 */
            {
              Context(
                "expression.infix",
                { "expression.infix.prefix" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 168 */
            {
              Context(
                "expression.infix",
                { "expression.infix.signal.delay" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 169 */
            {
              Context(
                "expression.infix",
                { "expression.iterate.parallel" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 170 */
            {
              Context(
                "expression.infix",
                { "expression.iterate.sequence" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 171 */
            {
              Context(
                "expression.infix",
                { "expression.iterate.sum" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 172 */
            {
              Context(
                "expression.infix",
                { "expression.iterate.product" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 173 */
            {
              Context(
                "expression.infix",
                { "expression.lambda" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 174 */
            {
              Context(
                "expression",
                { "expression.letrec" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 175 */
            {
              Context(
                "expression.infix",
                { "expression.library" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 176 */
            {
              Context(
                "expression.infix",
                { "expression.math" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 177 */
            {
              Context(
                "expression.math",
                { "expression.math.comparison" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 178 */
            {
              Context(
                "expression.math",
                { "expression.math.rounding" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 179 */
            {
              Context(
                "expression.math",
                { "expression.math.signal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 180 */
            {
              Context(
                "expression.math.signal",
                { "expression.math.signal.algebra" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 181 */
            {
              Context(
                "expression.math.signal",
                { "expression.math.signal.shift" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 182 */
            {
              Context(
                "expression.math.signal",
                { "expression.math.signal.power" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 183 */
            {
              Context(
                "expression.math",
                { "expression.math.scalar.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 184 */
            {
              Context(
                "expression.math.scalar.int.as.tree",
                { "expression.math.scalar.int" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 185 */
            {
              Context(
                "expression.math.scalar.as.tree",
                { "expression.math.scalar.int.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 186 */
            {
              Context(
                "expression.math.scalar.float.as.tree",
                { "expression.math.scalar.float" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 187 */
            {
              Context(
                "expression.math.scalar.as.tree",
                { "expression.math.scalar.float.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 188 */
            {
              Context(
                "expression.math",
                { "expression.math.trigonometry.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 189 */
            {
              Context(
                "expression.infix",
                { "expression.parenthesis" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 190 */
            {
              Context(
                "expression.infix",
                { "expression.signal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 191 */
            {
              Context(
                "expression.signal",
                { "expression.signal.control" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 192 */
            {
              Context(
                "expression.signal",
                { "expression.signal.delay" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 193 */
            {
              Context(
                "expression.signal",
                { "expression.signal.logic" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 194 */
            {
              Context(
                "expression.infix",
                { "primitive" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 195 */
            {
              Context(
                "primitive",
                { "primitive.foreign" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 196 */
            {
              Context(
                "primitive",
                { "primitive.type.number.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 197 */
            {
              Context(
                "primitive.type.number.int.as.tree",
                { "primitive.type.number.int" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 198 */
            {
              Context(
                "primitive.type.number.float.as.tree",
                { "primitive.type.number.float" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 199 */
            {
              Context(
                "primitive.type.number.as.tree",
                { "primitive.type.number.int.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 200 */
            {
              Context(
                "primitive.type.number.as.tree",
                { "primitive.type.number.float.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 201 */
            {
              Context(
                "primitive",
                { "primitive.signal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 202 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.input.wire" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 203 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.input.terminate" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 204 */
            {
              Context(
                "primitive",
                { "primitive.type.cast.number" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 205 */
            {
              Context(
                "primitive.type.cast.number",
                { "primitive.type.cast.number.int" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 206 */
            {
              Context(
                "primitive.type.cast.number",
                { "primitive.type.cast.number.float" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 207 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.route" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 208 */
            {
              Context(
                "primitive.signal.route",
                { "primitive.signal.route.implied.outputs" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 209 */
            {
              Context(
                "primitive.signal.route",
                { "primitive.signal.route.implied.connections" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 210 */
            {
              Context(
                "primitive.signal.route",
                { "primitive.signal.route.explicit" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 211 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.source" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 212 */
            {
              Context(
                "primitive.signal.source",
                { "primitive.signal.source.table" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 213 */
            {
              Context(
                "primitive.signal.source",
                { "primitive.signal.source.soundfile" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 214 */
            {
              Context(
                "primitive.signal.source",
                { "primitive.signal.source.waveform.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 215 */
            {
              Context(
                "primitive",
                { "primitive.ui" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 216 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.button" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 217 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.checkbox" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 218 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.vslider" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 219 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.hslider" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 220 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.nentry" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 221 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.vgroup" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 222 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.hgroup" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 223 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.tgroup" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 224 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.vbargraph" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 225 */
            {
              Context(
                "primitive.ui",
                { "primitive.ui.hbargraph" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 226 */
            {
              Context(
                "primitive.foreign",
                { "primitive.foreign.function" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 227 */
            {
              Context(
                "primitive.foreign",
                { "primitive.foreign.constant" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 228 */
            {
              Context(
                "primitive.foreign",
                { "primitive.foreign.variable" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 229 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.inputs" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 230 */
            {
              Context(
                "primitive.signal",
                { "primitive.signal.outputs" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 231 */
            {
              Context(
                "expression",
                { "statement.definition.with" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 232 */
            {
              Context(
                "expression.infix",
                { "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 233 */
            {
              Context(
                "doc.diagram",
                { "BDGM", "expression" },
                { "EDGM" }
              ),
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"EDGM", 316}
            },
            {}
          },
          { /* State 234 */
            {
              Context(
                "doc.list",
                { "BLST", "ELST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 235 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES" },
                { "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTEQ", 317}
            },
            {}
          },
          { /* State 236 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS" },
                { "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTEQ", 318}
            },
            {}
          },
          { /* State 237 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED" },
                { "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTEQ", 319}
            },
            {}
          },
          { /* State 238 */
            {
              Context(
                "doc.list",
                { "BLST", "doc.attribute.list" },
                { "ELST" }
              ),
              Context(
                "doc.attribute.list",
                { "doc.attribute.list" },
                { "doc.attribute.definition" }
              )
            },
            {
              {"ELST", 320},
              {"LSTDEPENDENCIES", 235},
              {"LSTMDOCTAGS", 236},
              {"LSTDISTRIBUTED", 237}
            },
            {
              {"doc.attribute.definition", 321}
            }
          },
          { /* State 239 */
            {
              Context(
                "doc.attribute.list",
                { "doc.attribute.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 240 */
            {
              Context(
                "doc.metadata",
                { "BMETADATA", "statement.identifier.as.tree" },
                { "EMETADATA" }
              )
            },
            {
              {"EMETADATA", 322}
            },
            {}
          },
          { /* State 241 */
            {
              Context(
                "statement.declare.doc",
                { "BDOC", "doc", "EDOC" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 242 */
            {
              Context(
                "doc.text",
                { "doc.text", "DOCCHAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 243 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "statement.definition.function.arg",
                { "expression.composition.serial" },
                {}
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293}
            },
            {}
          },
          { /* State 244 */
            {
              Context(
                "statement.definition.function.args.start",
                { "statement.definition.function.arg" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 245 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args" },
                { "COMMA", "statement.definition.function.arg" }
              ),
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args" },
                { "RPAR", "DEF", "expression" }
              )
            },
            {
              {"COMMA", 323},
              {"RPAR", 324}
            },
            {}
          },
          { /* State 246 */
            {
              Context(
                "statement.definition.function.args",
                { "statement.definition.function.args.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 247 */
            {
              Context(
                "statement.definition.function.args",
                { "statement.definition.function.args.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 248 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree", "statement.definition.assignment.operator", "expression" },
                { "statement.definition.assignment.terminal" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"ENDDEF", 325}
            },
            {
              {"statement.definition.assignment.terminal", 326}
            }
          },
          { /* State 249 */
            {
              Context(
                "statement.list.append.qualified",
                { "statement.list", "statement.math.precision.list", "statement" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 250 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                { "ENDDEF" }
              )
            },
            {
              {"ENDDEF", 327}
            },
            {}
          },
          { /* State 251 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 252 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree" },
                { "ENDDEF" }
              )
            },
            {
              {"ENDDEF", 328}
            },
            {}
          },
          { /* State 253 */
            {
              Context(
                "expression.math.scalar.int",
                { "ADD", "INT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 254 */
            {
              Context(
                "expression.math.scalar.float",
                { "ADD", "FLOAT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 255 */
            {
              Context(
                "expression.math.scalar.int",
                { "SUB", "INT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 256 */
            {
              Context(
                "expression.math.scalar.float",
                { "SUB", "FLOAT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 257 */
            {
              Context(
                "expression.math.signal.algebra",
                { "SUB", "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 258 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR" },
                { "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86}
            },
            {
              {"primitive.type.cast.number", 329},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.foreign.function.signature", 330}
            }
          },
          { /* State 259 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR" },
                { "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86}
            },
            {
              {"primitive.type.cast.number", 331},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206}
            }
          },
          { /* State 260 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR" },
                { "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86}
            },
            {
              {"primitive.type.cast.number", 332},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206}
            }
          },
          { /* State 261 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 333}
            }
          },
          { /* State 262 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 334}
            }
          },
          { /* State 263 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 335}
            }
          },
          { /* State 264 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 336}
            }
          },
          { /* State 265 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 337}
            }
          },
          { /* State 266 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 338}
            }
          },
          { /* State 267 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 339}
            }
          },
          { /* State 268 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 340}
            }
          },
          { /* State 269 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 341}
            }
          },
          { /* State 270 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 342}
            }
          },
          { /* State 271 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 343}
            }
          },
          { /* State 272 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR" },
                { "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"expression.lambda.params", 344},
              {"expression.lambda.params.start", 345},
              {"expression.lambda.params.append", 346},
              {"statement.box.identifier.as.tree", 347}
            }
          },
          { /* State 273 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "expression.parenthesis",
                { "LPAR", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 348}
            },
            {}
          },
          { /* State 274 */
            {
              Context(
                "expression.component",
                { "COMPONENT", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 349}
            }
          },
          { /* State 275 */
            {
              Context(
                "expression.library",
                { "LIBRARY", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 350}
            }
          },
          { /* State 276 */
            {
              Context(
                "expression.environment",
                { "ENVIRONMENT", "LBRAQ" },
                { "statement.list", "RBRAQ" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"statement", 11},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.list", 351},
              {"statement.list.start", 22},
              {"statement.list.start.qualified", 23},
              {"statement.list.append", 24},
              {"statement.list.append.qualified", 25},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 27},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 277 */
            {
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM", "LBRAQ" },
                { "primitive.type.number.list.as.tree", "RBRAQ" }
              )
            },
            {
              {"ADD", 352},
              {"SUB", 353},
              {"INT", 126},
              {"FLOAT", 127}
            },
            {
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 354},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 355},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 356},
              {"primitive.type.number.float.as.tree", 357},
              {"primitive.type.number.int.list.member.as.tree", 358},
              {"primitive.type.number.list.as.tree", 359},
              {"primitive.type.number.list.member.as.tree", 360},
              {"primitive.type.number.list.start.as.tree", 361},
              {"primitive.type.number.list.append.as.tree", 362},
              {"primitive.type.number.float.list.member.as.tree", 363}
            }
          },
          { /* State 278 */
            {
              Context(
                "primitive.signal.route.implied.outputs",
                { "ROUTE", "LPAR" },
                { "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE", "LPAR" },
                { "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR" },
                { "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 364},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 279 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 365}
            }
          },
          { /* State 280 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 366}
            }
          },
          { /* State 281 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 367}
            }
          },
          { /* State 282 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 368}
            }
          },
          { /* State 283 */
            {
              Context(
                "primitive.signal.inputs",
                { "INPUTS", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 369},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 284 */
            {
              Context(
                "primitive.signal.outputs",
                { "OUTPUTS", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 370},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 285 */
            {
              Context(
                "expression.signal.logic",
                { "CASE", "LBRAQ" },
                { "statement.signal.pattern.rule.list", "RBRAQ" }
              )
            },
            {
              {"LPAR", 371}
            },
            {
              {"statement.signal.pattern.rule", 372},
              {"statement.signal.pattern.rule.list", 373},
              {"statement.signal.pattern.rule.list.start", 374},
              {"statement.signal.pattern.rule.list.append", 375}
            }
          },
          { /* State 286 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH" },
                { "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 376}
            },
            {}
          },
          { /* State 287 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC" },
                { "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression", "LETREC" },
                { "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression", "LETREC" },
                { "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 377}
            },
            {}
          },
          { /* State 288 */
            {
              Context(
                "expression.composition.parallel",
                { "expression", "COMMA" },
                { "expression" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 378},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 289 */
            {
              Context(
                "doc.equation",
                { "BEQN", "expression", "EEQN" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 290 */
            {
              Context(
                "expression.composition.split",
                { "expression.composition.serial", "SPLIT" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 379},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 291 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial", "MIX" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 380},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 292 */
            {
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial", "SEQ" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 381},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 293 */
            {
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial", "REC" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 382},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 294 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "LT" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 383},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 295 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "LE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 384},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 296 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "EQ" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 385},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 297 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "GT" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 386},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 298 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "GE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 387},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 299 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "NE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 388},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 300 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "ADD" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 389},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 301 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "SUB" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 390},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 302 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "OR" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 391},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 303 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "MUL" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 392},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 304 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "DIV" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 393},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 305 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "MOD" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 394},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 306 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "AND" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 395},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 307 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "XOR" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 396},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 308 */
            {
              Context(
                "expression.infix.math.shift",
                { "expression.infix", "LSH" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 397},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 309 */
            {
              Context(
                "expression.infix.math.shift",
                { "expression.infix", "RSH" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 398},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 310 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "POWOP" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 399},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 311 */
            {
              Context(
                "expression.infix.signal.delay",
                { "expression.infix", "FDELAY" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.environment", 158},
              {"expression.infix", 400},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 312 */
            {
              Context(
                "expression.infix.signal.delay",
                { "expression.infix", "DELAY1" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 313 */
            {
              Context(
                "expression.infix.environment.access",
                { "expression.infix", "DOT" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 401}
            }
          },
          { /* State 314 */
            {
              Context(
                "expression.infix.prefix",
                { "expression.infix", "LPAR" },
                { "statement.definition.function.args", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 244},
              {"statement.definition.function.args", 402},
              {"statement.definition.function.args.start", 246},
              {"statement.definition.function.args.append", 247},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 315 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix", "LCROC" },
                { "statement.definition.list", "RCROC" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 403},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.definition.list", 404},
              {"statement.definition.list.start", 405},
              {"statement.definition.list.start.qualified", 406},
              {"statement.definition.list.append", 407},
              {"statement.definition.list.append.qualified", 408},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 409},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 316 */
            {
              Context(
                "doc.diagram",
                { "BDGM", "expression", "EDGM" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 317 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 410}
            },
            {}
          },
          { /* State 318 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 411}
            },
            {}
          },
          { /* State 319 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 412}
            },
            {}
          },
          { /* State 320 */
            {
              Context(
                "doc.list",
                { "BLST", "doc.attribute.list", "ELST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 321 */
            {
              Context(
                "doc.attribute.list",
                { "doc.attribute.list", "doc.attribute.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 322 */
            {
              Context(
                "doc.metadata",
                { "BMETADATA", "statement.identifier.as.tree", "EMETADATA" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 323 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args", "COMMA" },
                { "statement.definition.function.arg" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 413},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 324 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args", "RPAR" },
                { "DEF", "expression" }
              )
            },
            {
              {"DEF", 414}
            },
            {}
          },
          { /* State 325 */
            {
              Context(
                "statement.definition.assignment.terminal",
                { "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 326 */
            {
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree", "statement.definition.assignment.operator", "expression", "statement.definition.assignment.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 327 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree", "RPAR", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 328 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 329 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              )
            },
            {
              {"IDENT", 415}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 416}
            }
          },
          { /* State 330 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature" },
                { "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 417}
            },
            {}
          },
          { /* State 331 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number" },
                { "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"IDENT", 32}
            },
            {
              {"statement.identifier.as.tree", 418}
            }
          },
          { /* State 332 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number" },
                { "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"IDENT", 32}
            },
            {
              {"statement.identifier.as.tree", 419}
            }
          },
          { /* State 333 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 420}
            },
            {}
          },
          { /* State 334 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 421}
            },
            {}
          },
          { /* State 335 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 422}
            },
            {}
          },
          { /* State 336 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 423}
            },
            {}
          },
          { /* State 337 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 424}
            },
            {}
          },
          { /* State 338 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 425}
            },
            {}
          },
          { /* State 339 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 426}
            },
            {}
          },
          { /* State 340 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 427}
            },
            {}
          },
          { /* State 341 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 428}
            },
            {}
          },
          { /* State 342 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 429}
            },
            {}
          },
          { /* State 343 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition", "RPAR" }
              )
            },
            {
              {"COMMA", 430}
            },
            {}
          },
          { /* State 344 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params" },
                { "RPAR", "DOT", "LPAR", "expression", "RPAR" }
              ),
              Context(
                "expression.lambda.params.append",
                { "expression.lambda.params" },
                { "COMMA", "statement.box.identifier.as.tree" }
              )
            },
            {
              {"COMMA", 431},
              {"RPAR", 432}
            },
            {}
          },
          { /* State 345 */
            {
              Context(
                "expression.lambda.params",
                { "expression.lambda.params.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 346 */
            {
              Context(
                "expression.lambda.params",
                { "expression.lambda.params.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 347 */
            {
              Context(
                "expression.lambda.params.start",
                { "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 348 */
            {
              Context(
                "expression.parenthesis",
                { "LPAR", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 349 */
            {
              Context(
                "expression.component",
                { "COMPONENT", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 433}
            },
            {}
          },
          { /* State 350 */
            {
              Context(
                "expression.library",
                { "LIBRARY", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 434}
            },
            {}
          },
          { /* State 351 */
            {
              Context(
                "expression.environment",
                { "ENVIRONMENT", "LBRAQ", "statement.list" },
                { "RBRAQ" }
              ),
              Context(
                "statement.list.append",
                { "statement.list" },
                { "statement" }
              ),
              Context(
                "statement.list.append.qualified",
                { "statement.list" },
                { "statement.math.precision.list", "statement" }
              )
            },
            {
              {"ENDDEF", 1},
              {"RBRAQ", 435},
              {"IMPORT", 2},
              {"IDENT", 3},
              {"DECLARE", 4},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8},
              {"BDOC", 9}
            },
            {
              {"statement", 54},
              {"statement.definition", 12},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.declare.metadata", 16},
              {"statement.declare.feature.metadata", 17},
              {"statement.declare.doc", 18},
              {"statement.box.identifier.as.tree", 19},
              {"statement.import", 20},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 55},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 352 */
            {
              Context(
                "expression.math.scalar.int",
                { "ADD" },
                { "INT" }
              ),
              Context(
                "expression.math.scalar.float",
                { "ADD" },
                { "FLOAT" }
              )
            },
            {
              {"INT", 253},
              {"FLOAT", 254}
            },
            {}
          },
          { /* State 353 */
            {
              Context(
                "expression.math.scalar.int",
                { "SUB" },
                { "INT" }
              ),
              Context(
                "expression.math.scalar.float",
                { "SUB" },
                { "FLOAT" }
              )
            },
            {
              {"INT", 255},
              {"FLOAT", 256}
            },
            {}
          },
          { /* State 354 */
            {
              Context(
                "primitive.type.number.int.list.member.as.tree",
                { "expression.math.scalar.int.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 355 */
            {
              Context(
                "primitive.type.number.float.list.member.as.tree",
                { "expression.math.scalar.float.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 356 */
            {
              Context(
                "primitive.type.number.int.list.member.as.tree",
                { "primitive.type.number.int.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 357 */
            {
              Context(
                "primitive.type.number.float.list.member.as.tree",
                { "primitive.type.number.float.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 358 */
            {
              Context(
                "primitive.type.number.list.member.as.tree",
                { "primitive.type.number.int.list.member.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 359 */
            {
              Context(
                "primitive.type.number.list.append.as.tree",
                { "primitive.type.number.list.as.tree" },
                { "COMMA", "primitive.type.number.list.member.as.tree" }
              ),
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM", "LBRAQ", "primitive.type.number.list.as.tree" },
                { "RBRAQ" }
              )
            },
            {
              {"COMMA", 436},
              {"RBRAQ", 437}
            },
            {}
          },
          { /* State 360 */
            {
              Context(
                "primitive.type.number.list.start.as.tree",
                { "primitive.type.number.list.member.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 361 */
            {
              Context(
                "primitive.type.number.list.as.tree",
                { "primitive.type.number.list.start.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 362 */
            {
              Context(
                "primitive.type.number.list.as.tree",
                { "primitive.type.number.list.append.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 363 */
            {
              Context(
                "primitive.type.number.list.member.as.tree",
                { "primitive.type.number.float.list.member.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 364 */
            {
              Context(
                "primitive.signal.route.implied.outputs",
                { "ROUTE", "LPAR", "statement.definition.function.arg" },
                { "RPAR" }
              ),
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE", "LPAR", "statement.definition.function.arg" },
                { "COMMA", "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg" },
                { "COMMA", "statement.definition.function.arg", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 438},
              {"RPAR", 439}
            },
            {}
          },
          { /* State 365 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 440}
            },
            {}
          },
          { /* State 366 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 441}
            },
            {}
          },
          { /* State 367 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 442}
            },
            {}
          },
          { /* State 368 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 443}
            },
            {}
          },
          { /* State 369 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.signal.inputs",
                { "INPUTS", "LPAR", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 444}
            },
            {}
          },
          { /* State 370 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.signal.outputs",
                { "OUTPUTS", "LPAR", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 445}
            },
            {}
          },
          { /* State 371 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR" },
                { "statement.definition.function.args", "RPAR", "ARROW", "expression", "ENDDEF" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 244},
              {"statement.definition.function.args", 446},
              {"statement.definition.function.args.start", 246},
              {"statement.definition.function.args.append", 247},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 372 */
            {
              Context(
                "statement.signal.pattern.rule.list.start",
                { "statement.signal.pattern.rule" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 373 */
            {
              Context(
                "expression.signal.logic",
                { "CASE", "LBRAQ", "statement.signal.pattern.rule.list" },
                { "RBRAQ" }
              ),
              Context(
                "statement.signal.pattern.rule.list.append",
                { "statement.signal.pattern.rule.list" },
                { "statement.signal.pattern.rule" }
              )
            },
            {
              {"LPAR", 371},
              {"RBRAQ", 447}
            },
            {
              {"statement.signal.pattern.rule", 448}
            }
          },
          { /* State 374 */
            {
              Context(
                "statement.signal.pattern.rule.list",
                { "statement.signal.pattern.rule.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 375 */
            {
              Context(
                "statement.signal.pattern.rule.list",
                { "statement.signal.pattern.rule.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 376 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH", "LBRAQ" },
                { "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 403},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.definition.list", 449},
              {"statement.definition.list.start", 405},
              {"statement.definition.list.start.qualified", 406},
              {"statement.definition.list.append", 407},
              {"statement.definition.list.append.qualified", 408},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 409},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 377 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ" },
                { "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression", "LETREC", "LBRAQ" },
                { "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression", "LETREC", "LBRAQ" },
                { "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"error", 450},
              {"DELAY1", 451},
              {"RBRAQ", 452}
            },
            {
              {"expression.letrec.list", 453},
              {"expression.letrec.list.start", 454},
              {"expression.letrec.list.append", 455},
              {"expression.letrec.equation", 456},
              {"expression.letrec.equation.name", 457}
            }
          },
          { /* State 378 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "                               ",
                { "expression", "COMMA", "expression" },
                {}
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"COMMA", 288}
            },
            {}
          },
          { /* State 379 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "                            ",
                { "expression.composition.serial", "SPLIT", "expression.composition.serial" },
                {}
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293}
            },
            {}
          },
          { /* State 380 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "                          ",
                { "expression.composition.serial", "MIX", "expression.composition.serial" },
                {}
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              )
            },
            {
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293}
            },
            {}
          },
          { /* State 381 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "                               ",
                { "expression.composition.serial", "SEQ", "expression.composition.serial" },
                {}
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              )
            },
            {
              {"SEQ", 292},
              {"REC", 293}
            },
            {}
          },
          { /* State 382 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "                                ",
                { "expression.composition.serial", "REC", "expression.composition.serial" },
                {}
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              )
            },
            {},
            {}
          },
          { /* State 383 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "LT", "expression.infix" },
                {}
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"LE", 295},
              {"EQ", 296},
              {"GT", 297},
              {"GE", 298},
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 384 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "LE", "expression.infix" },
                {}
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"EQ", 296},
              {"GT", 297},
              {"GE", 298},
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 385 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "EQ", "expression.infix" },
                {}
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"GT", 297},
              {"GE", 298},
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 386 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "GT", "expression.infix" },
                {}
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"GE", 298},
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 387 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "GE", "expression.infix" },
                {}
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"NE", 299},
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 388 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix", "NE", "expression.infix" },
                {}
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"ADD", 300},
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 389 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "ADD", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"SUB", 301},
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 390 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "SUB", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"OR", 302},
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 391 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix", "OR", "expression.infix" },
                {}
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"MUL", 303},
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 392 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "MUL", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"DIV", 304},
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 393 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "DIV", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"MOD", 305},
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 394 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "MOD", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"AND", 306},
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 395 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix", "AND", "expression.infix" },
                {}
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"XOR", 307},
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 396 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix", "XOR", "expression.infix" },
                {}
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"LSH", 308},
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 397 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix", "LSH", "expression.infix" },
                {}
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"RSH", 309},
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 398 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix", "RSH", "expression.infix" },
                {}
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"POWOP", 310},
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 399 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "POWOP", "expression.infix" },
                {}
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"FDELAY", 311},
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 400 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix" },
                { "LCROC", "statement.definition.list", "RCROC" }
              ),
              Context(
                "expression.infix.environment.access",
                { "expression.infix" },
                { "DOT", "statement.box.identifier.as.tree" }
              ),
              Context(
                "expression.infix.math.algebra",
                { "expression.infix" },
                { "ADD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "SUB", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MUL", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DIV", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "MOD", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "POWOP", "expression.infix" }
              ),
              Context(
                "expression.infix.math.comparison",
                { "expression.infix" },
                { "LT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "LE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GT", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "GE", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "EQ", "expression.infix" }
              ),
              Context(
                "                                ",
                { "expression.infix" },
                { "NE", "expression.infix" }
              ),
              Context(
                "expression.infix.math.logic",
                { "expression.infix" },
                { "AND", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "OR", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "XOR", "expression.infix" }
              ),
              Context(
                "expression.infix.math.shift",
                { "expression.infix" },
                { "LSH", "expression.infix" }
              ),
              Context(
                "                           ",
                { "expression.infix" },
                { "RSH", "expression.infix" }
              ),
              Context(
                "expression.infix.prefix",
                { "expression.infix" },
                { "LPAR", "statement.definition.function.args", "RPAR" }
              ),
              Context(
                "expression.infix.signal.delay",
                { "expression.infix" },
                { "FDELAY", "expression.infix" }
              ),
              Context(
                "                             ",
                { "expression.infix", "FDELAY", "expression.infix" },
                {}
              ),
              Context(
                "                             ",
                { "expression.infix" },
                { "DELAY1" }
              )
            },
            {
              {"DELAY1", 312},
              {"DOT", 313},
              {"LPAR", 314},
              {"LCROC", 315}
            },
            {}
          },
          { /* State 401 */
            {
              Context(
                "expression.infix.environment.access",
                { "expression.infix", "DOT", "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 402 */
            {
              Context(
                "expression.infix.prefix",
                { "expression.infix", "LPAR", "statement.definition.function.args" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args" },
                { "COMMA", "statement.definition.function.arg" }
              )
            },
            {
              {"COMMA", 323},
              {"RPAR", 458}
            },
            {}
          },
          { /* State 403 */
            {
              Context(
                "statement.definition.list.start",
                { "statement.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 404 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix", "LCROC", "statement.definition.list" },
                { "RCROC" }
              ),
              Context(
                "statement.definition.list.append",
                { "statement.definition.list" },
                { "statement.definition" }
              ),
              Context(
                "statement.definition.list.append.qualified",
                { "statement.definition.list" },
                { "statement.math.precision.list", "statement.definition" }
              )
            },
            {
              {"ENDDEF", 1},
              {"RCROC", 459},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 460},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 461},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 405 */
            {
              Context(
                "statement.definition.list",
                { "statement.definition.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 406 */
            {
              Context(
                "statement.definition.list",
                { "statement.definition.list.start.qualified" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 407 */
            {
              Context(
                "statement.definition.list",
                { "statement.definition.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 408 */
            {
              Context(
                "statement.definition.list",
                { "statement.definition.list.append.qualified" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 409 */
            {
              Context(
                "statement.definition.list.start.qualified",
                { "statement.math.precision.list" },
                { "statement.definition" }
              ),
              Context(
                "statement.math.precision.list.append",
                { "statement.math.precision.list" },
                { "statement.math.precision" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 462},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 57}
            }
          },
          { /* State 410 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 463},
              {"LSTFALSE", 464}
            },
            {
              {"doc.attribute.value", 465}
            }
          },
          { /* State 411 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 463},
              {"LSTFALSE", 464}
            },
            {
              {"doc.attribute.value", 466}
            }
          },
          { /* State 412 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 463},
              {"LSTFALSE", 464}
            },
            {
              {"doc.attribute.value", 467}
            }
          },
          { /* State 413 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args", "COMMA", "statement.definition.function.arg" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 414 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args", "RPAR", "DEF" },
                { "expression" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 468},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 415 */
            {
              Context(
                "statement.foreign.function.identifier.as.tree",
                { "IDENT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 416 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              )
            },
            {
              {"OR", 469},
              {"LPAR", 470}
            },
            {}
          },
          { /* State 417 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA" },
                { "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 471},
              {"TAGSTRING", 472}
            },
            {
              {"primitive.string.tag", 473},
              {"primitive.string.tag.as.tree", 474}
            }
          },
          { /* State 418 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree" },
                { "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 475}
            },
            {}
          },
          { /* State 419 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree" },
                { "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 476}
            },
            {}
          },
          { /* State 420 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 421 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 422 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 477},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 423 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 478},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 424 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 479},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 425 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 480},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 426 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 481},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 427 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 482},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 428 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 483},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 429 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 484},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 430 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 485},
              {"expression.component", 150},
              {"expression.composition", 486},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 431 */
            {
              Context(
                "expression.lambda.params.append",
                { "expression.lambda.params", "COMMA" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 487}
            }
          },
          { /* State 432 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR" },
                { "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"DOT", 488}
            },
            {}
          },
          { /* State 433 */
            {
              Context(
                "expression.component",
                { "COMPONENT", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 434 */
            {
              Context(
                "expression.library",
                { "LIBRARY", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 435 */
            {
              Context(
                "expression.environment",
                { "ENVIRONMENT", "LBRAQ", "statement.list", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 436 */
            {
              Context(
                "primitive.type.number.list.append.as.tree",
                { "primitive.type.number.list.as.tree", "COMMA" },
                { "primitive.type.number.list.member.as.tree" }
              )
            },
            {
              {"ADD", 352},
              {"SUB", 353},
              {"INT", 126},
              {"FLOAT", 127}
            },
            {
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 354},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 355},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 356},
              {"primitive.type.number.float.as.tree", 357},
              {"primitive.type.number.int.list.member.as.tree", 358},
              {"primitive.type.number.list.member.as.tree", 489},
              {"primitive.type.number.float.list.member.as.tree", 363}
            }
          },
          { /* State 437 */
            {
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM", "LBRAQ", "primitive.type.number.list.as.tree", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 438 */
            {
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA" },
                { "statement.definition.function.arg", "RPAR" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA" },
                { "statement.definition.function.arg", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 243},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.function.arg", 490},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 439 */
            {
              Context(
                "primitive.signal.route.implied.outputs",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 440 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 491},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 441 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 492},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 442 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 493},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 443 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 494},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 444 */
            {
              Context(
                "primitive.signal.inputs",
                { "INPUTS", "LPAR", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 445 */
            {
              Context(
                "primitive.signal.outputs",
                { "OUTPUTS", "LPAR", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 446 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args" },
                { "COMMA", "statement.definition.function.arg" }
              ),
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args" },
                { "RPAR", "ARROW", "expression", "ENDDEF" }
              )
            },
            {
              {"COMMA", 323},
              {"RPAR", 495}
            },
            {}
          },
          { /* State 447 */
            {
              Context(
                "expression.signal.logic",
                { "CASE", "LBRAQ", "statement.signal.pattern.rule.list", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 448 */
            {
              Context(
                "statement.signal.pattern.rule.list.append",
                { "statement.signal.pattern.rule.list", "statement.signal.pattern.rule" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 449 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH", "LBRAQ", "statement.definition.list" },
                { "RBRAQ" }
              ),
              Context(
                "statement.definition.list.append",
                { "statement.definition.list" },
                { "statement.definition" }
              ),
              Context(
                "statement.definition.list.append.qualified",
                { "statement.definition.list" },
                { "statement.math.precision.list", "statement.definition" }
              )
            },
            {
              {"ENDDEF", 1},
              {"RBRAQ", 496},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 460},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 461},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 450 */
            {
              Context(
                "expression.letrec.equation",
                { "error" },
                { "ENDDEF" }
              )
            },
            {
              {"ENDDEF", 497}
            },
            {}
          },
          { /* State 451 */
            {
              Context(
                "expression.letrec.equation.name",
                { "DELAY1" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 3}
            },
            {
              {"statement.box.identifier.as.tree", 498}
            }
          },
          { /* State 452 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 453 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list" },
                { "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list" },
                { "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "expression.letrec.list.append",
                { "expression.letrec.list" },
                { "expression.letrec.equation" }
              )
            },
            {
              {"error", 450},
              {"DELAY1", 451},
              {"RBRAQ", 499},
              {"WHERE", 500}
            },
            {
              {"expression.letrec.equation", 501},
              {"expression.letrec.equation.name", 457}
            }
          },
          { /* State 454 */
            {
              Context(
                "expression.letrec.list",
                { "expression.letrec.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 455 */
            {
              Context(
                "expression.letrec.list",
                { "expression.letrec.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 456 */
            {
              Context(
                "expression.letrec.list.start",
                { "expression.letrec.equation" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 457 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name" },
                { "DEF", "expression", "ENDDEF" }
              )
            },
            {
              {"DEF", 502}
            },
            {}
          },
          { /* State 458 */
            {
              Context(
                "expression.infix.prefix",
                { "expression.infix", "LPAR", "statement.definition.function.args", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 459 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix", "LCROC", "statement.definition.list", "RCROC" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 460 */
            {
              Context(
                "statement.definition.list.append",
                { "statement.definition.list", "statement.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 461 */
            {
              Context(
                "statement.definition.list.append.qualified",
                { "statement.definition.list", "statement.math.precision.list" },
                { "statement.definition" }
              ),
              Context(
                "statement.math.precision.list.append",
                { "statement.math.precision.list" },
                { "statement.math.precision" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 503},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 57}
            }
          },
          { /* State 462 */
            {
              Context(
                "statement.definition.list.start.qualified",
                { "statement.math.precision.list", "statement.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 463 */
            {
              Context(
                "doc.attribute.value",
                { "LSTTRUE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 464 */
            {
              Context(
                "doc.attribute.value",
                { "LSTFALSE" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 465 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ", "LSTQ", "doc.attribute.value" },
                { "LSTQ" }
              )
            },
            {
              {"LSTQ", 504}
            },
            {}
          },
          { /* State 466 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ", "LSTQ", "doc.attribute.value" },
                { "LSTQ" }
              )
            },
            {
              {"LSTQ", 505}
            },
            {}
          },
          { /* State 467 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "doc.attribute.value" },
                { "LSTQ" }
              )
            },
            {
              {"LSTQ", 506}
            },
            {}
          },
          { /* State 468 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args", "RPAR", "DEF", "expression" },
                {}
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288}
            },
            {}
          },
          { /* State 469 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              )
            },
            {
              {"IDENT", 415}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 507}
            }
          },
          { /* State 470 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"ANYCAST", 508},
              {"RPAR", 509}
            },
            {
              {"primitive.type", 510},
              {"primitive.type.cast.number", 511},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.type.cast.any", 512},
              {"primitive.type.list", 513},
              {"primitive.type.list.start", 514},
              {"primitive.type.list.append", 515}
            }
          },
          { /* State 471 */
            {
              Context(
                "primitive.string.tag",
                { "STRING" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 472 */
            {
              Context(
                "primitive.string.tag",
                { "TAGSTRING" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 473 */
            {
              Context(
                "primitive.string.tag.as.tree",
                { "primitive.string.tag" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 474 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree" },
                { "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 516}
            },
            {}
          },
          { /* State 475 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA" },
                { "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 471},
              {"TAGSTRING", 472}
            },
            {
              {"primitive.string.tag", 473},
              {"primitive.string.tag.as.tree", 517}
            }
          },
          { /* State 476 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA" },
                { "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 471},
              {"TAGSTRING", 472}
            },
            {
              {"primitive.string.tag", 473},
              {"primitive.string.tag.as.tree", 518}
            }
          },
          { /* State 477 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 519},
              {"REC", 293}
            },
            {}
          },
          { /* State 478 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 520},
              {"REC", 293}
            },
            {}
          },
          { /* State 479 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 521},
              {"REC", 293}
            },
            {}
          },
          { /* State 480 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 522}
            },
            {}
          },
          { /* State 481 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 523}
            },
            {}
          },
          { /* State 482 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 524}
            },
            {}
          },
          { /* State 483 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 525},
              {"REC", 293}
            },
            {}
          },
          { /* State 484 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 526},
              {"REC", 293}
            },
            {}
          },
          { /* State 485 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288}
            },
            {}
          },
          { /* State 486 */
            {
              Context(
                "expression",
                { "expression.composition" },
                {}
              ),
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 527}
            },
            {}
          },
          { /* State 487 */
            {
              Context(
                "expression.lambda.params.append",
                { "expression.lambda.params", "COMMA", "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 488 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT" },
                { "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 528}
            },
            {}
          },
          { /* State 489 */
            {
              Context(
                "primitive.type.number.list.append.as.tree",
                { "primitive.type.number.list.as.tree", "COMMA", "primitive.type.number.list.member.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 490 */
            {
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg" },
                { "RPAR" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 529},
              {"RPAR", 530}
            },
            {}
          },
          { /* State 491 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 531},
              {"REC", 293}
            },
            {}
          },
          { /* State 492 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 532},
              {"REC", 293}
            },
            {}
          },
          { /* State 493 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 533},
              {"REC", 293}
            },
            {}
          },
          { /* State 494 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 534},
              {"REC", 293}
            },
            {}
          },
          { /* State 495 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR" },
                { "ARROW", "expression", "ENDDEF" }
              )
            },
            {
              {"ARROW", 535}
            },
            {}
          },
          { /* State 496 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 497 */
            {
              Context(
                "expression.letrec.equation",
                { "error", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 498 */
            {
              Context(
                "expression.letrec.equation.name",
                { "DELAY1", "statement.box.identifier.as.tree" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 499 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 500 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list", "WHERE" },
                { "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"ENDDEF", 1},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 403},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.definition.list", 536},
              {"statement.definition.list.start", 405},
              {"statement.definition.list.start.qualified", 406},
              {"statement.definition.list.append", 407},
              {"statement.definition.list.append.qualified", 408},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 409},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 501 */
            {
              Context(
                "expression.letrec.list.append",
                { "expression.letrec.list", "expression.letrec.equation" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 502 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name", "DEF" },
                { "expression", "ENDDEF" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 537},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 503 */
            {
              Context(
                "statement.definition.list.append.qualified",
                { "statement.definition.list", "statement.math.precision.list", "statement.definition" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 504 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 505 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 506 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 507 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              )
            },
            {
              {"OR", 538},
              {"LPAR", 539}
            },
            {}
          },
          { /* State 508 */
            {
              Context(
                "primitive.type.cast.any",
                { "ANYCAST" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 509 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 510 */
            {
              Context(
                "primitive.type.list.start",
                { "primitive.type" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 511 */
            {
              Context(
                "primitive.type",
                { "primitive.type.cast.number" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 512 */
            {
              Context(
                "primitive.type",
                { "primitive.type.cast.any" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 513 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list" },
                { "COMMA", "primitive.type" }
              ),
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list" },
                { "RPAR" }
              )
            },
            {
              {"COMMA", 540},
              {"RPAR", 541}
            },
            {}
          },
          { /* State 514 */
            {
              Context(
                "primitive.type.list",
                { "primitive.type.list.start" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 515 */
            {
              Context(
                "primitive.type.list",
                { "primitive.type.list.append" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 516 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 58}
            },
            {
              {"primitive.string.unquoted", 59},
              {"primitive.string.unquoted.as.tree", 542}
            }
          },
          { /* State 517 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 543}
            },
            {}
          },
          { /* State 518 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 544}
            },
            {}
          },
          { /* State 519 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 545},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 520 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 546},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 521 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 547},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 522 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 523 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 524 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 525 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 548},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 526 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 549},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 527 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 528 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 550},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 529 */
            {
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 551},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 530 */
            {
              Context(
                "primitive.signal.route.implied.connections",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 531 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 552},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 532 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 553},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 533 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 554},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 534 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 555},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 535 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR", "ARROW" },
                { "expression", "ENDDEF" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression", 556},
              {"expression.component", 150},
              {"expression.composition", 151},
              {"expression.composition.parallel", 152},
              {"expression.composition.serial", 153},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.letrec", 174},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.definition.with", 231},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 536 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list" },
                { "RBRAQ" }
              ),
              Context(
                "statement.definition.list.append",
                { "statement.definition.list" },
                { "statement.definition" }
              ),
              Context(
                "statement.definition.list.append.qualified",
                { "statement.definition.list" },
                { "statement.math.precision.list", "statement.definition" }
              )
            },
            {
              {"ENDDEF", 1},
              {"RBRAQ", 557},
              {"IDENT", 3},
              {"FLOATMODE", 5},
              {"DOUBLEMODE", 6},
              {"QUADMODE", 7},
              {"FIXEDPOINTMODE", 8}
            },
            {
              {"statement.definition", 460},
              {"statement.definition.function.declaration", 13},
              {"statement.definition.function", 14},
              {"statement.definition.assignment", 15},
              {"statement.box.identifier.as.tree", 19},
              {"statement.math.precision", 26},
              {"statement.math.precision.list", 461},
              {"statement.math.precision.list.start", 28},
              {"statement.math.precision.list.append", 29}
            }
          },
          { /* State 537 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name", "DEF", "expression" },
                { "ENDDEF" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"ENDDEF", 558}
            },
            {}
          },
          { /* State 538 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR" },
                { "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" }
              )
            },
            {
              {"IDENT", 415}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 559}
            }
          },
          { /* State 539 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"ANYCAST", 508},
              {"RPAR", 560}
            },
            {
              {"primitive.type", 510},
              {"primitive.type.cast.number", 511},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.type.cast.any", 512},
              {"primitive.type.list", 561},
              {"primitive.type.list.start", 514},
              {"primitive.type.list.append", 515}
            }
          },
          { /* State 540 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list", "COMMA" },
                { "primitive.type" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"ANYCAST", 508}
            },
            {
              {"primitive.type", 562},
              {"primitive.type.cast.number", 511},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.type.cast.any", 512}
            }
          },
          { /* State 541 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 542 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 563}
            },
            {}
          },
          { /* State 543 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 544 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 545 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 564},
              {"REC", 293}
            },
            {}
          },
          { /* State 546 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 565},
              {"REC", 293}
            },
            {}
          },
          { /* State 547 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 566},
              {"REC", 293}
            },
            {}
          },
          { /* State 548 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293},
              {"RPAR", 567}
            },
            {}
          },
          { /* State 549 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293},
              {"RPAR", 568}
            },
            {}
          },
          { /* State 550 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression" },
                { "RPAR" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 569}
            },
            {}
          },
          { /* State 551 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 570}
            },
            {}
          },
          { /* State 552 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 571}
            },
            {}
          },
          { /* State 553 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 572}
            },
            {}
          },
          { /* State 554 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 573}
            },
            {}
          },
          { /* State 555 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression" },
                { "RPAR" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"RPAR", 574}
            },
            {}
          },
          { /* State 556 */
            {
              Context(
                "expression.composition.parallel",
                { "expression" },
                { "COMMA", "expression" }
              ),
              Context(
                "expression.letrec",
                { "expression" },
                { "LETREC", "LBRAQ", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "RBRAQ" }
              ),
              Context(
                "                 ",
                { "expression" },
                { "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              ),
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR", "ARROW", "expression" },
                { "ENDDEF" }
              )
            },
            {
              {"WITH", 286},
              {"LETREC", 287},
              {"COMMA", 288},
              {"ENDDEF", 575}
            },
            {}
          },
          { /* State 557 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list", "WHERE", "statement.definition.list", "RBRAQ" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 558 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name", "DEF", "expression", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 559 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree" },
                { "LPAR", "RPAR" }
              )
            },
            {
              {"LPAR", 576}
            },
            {}
          },
          { /* State 560 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 561 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list" },
                { "COMMA", "primitive.type" }
              ),
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list" },
                { "RPAR" }
              )
            },
            {
              {"COMMA", 540},
              {"RPAR", 577}
            },
            {}
          },
          { /* State 562 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list", "COMMA", "primitive.type" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 563 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 564 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 578},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 565 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 579},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 566 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 580},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 567 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 568 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 569 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 570 */
            {
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 571 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 572 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 573 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 574 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 575 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR", "ARROW", "expression", "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 576 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "primitive.type.list", "RPAR" }
              ),
              Context(
                "                                    ",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR" },
                { "RPAR" }
              )
            },
            {
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"ANYCAST", 508},
              {"RPAR", 581}
            },
            {
              {"primitive.type", 510},
              {"primitive.type.cast.number", 511},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.type.cast.any", 512},
              {"primitive.type.list", 582},
              {"primitive.type.list.start", 514},
              {"primitive.type.list.append", 515}
            }
          },
          { /* State 577 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 578 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 583},
              {"REC", 293}
            },
            {}
          },
          { /* State 579 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 584},
              {"REC", 293}
            },
            {}
          },
          { /* State 580 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"COMMA", 585},
              {"REC", 293}
            },
            {}
          },
          { /* State 581 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 582 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list" },
                { "COMMA", "primitive.type" }
              ),
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list" },
                { "RPAR" }
              )
            },
            {
              {"COMMA", 540},
              {"RPAR", 586}
            },
            {}
          },
          { /* State 583 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 587},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 584 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 588},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 585 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 65},
              {"LE", 66},
              {"EQ", 67},
              {"GT", 68},
              {"GE", 69},
              {"NE", 70},
              {"ADD", 71},
              {"SUB", 72},
              {"OR", 73},
              {"MUL", 74},
              {"DIV", 75},
              {"MOD", 76},
              {"AND", 77},
              {"XOR", 78},
              {"LSH", 79},
              {"RSH", 80},
              {"POWOP", 81},
              {"FDELAY", 82},
              {"MEM", 83},
              {"PREFIX", 84},
              {"INTCAST", 85},
              {"FLOATCAST", 86},
              {"FFUNCTION", 87},
              {"FCONSTANT", 88},
              {"FVARIABLE", 89},
              {"BUTTON", 90},
              {"CHECKBOX", 91},
              {"VSLIDER", 92},
              {"HSLIDER", 93},
              {"NENTRY", 94},
              {"VGROUP", 95},
              {"HGROUP", 96},
              {"TGROUP", 97},
              {"HBARGRAPH", 98},
              {"VBARGRAPH", 99},
              {"SOUNDFILE", 100},
              {"ATTACH", 101},
              {"ACOS", 102},
              {"ASIN", 103},
              {"ATAN", 104},
              {"ATAN2", 105},
              {"COS", 106},
              {"SIN", 107},
              {"TAN", 108},
              {"EXP", 109},
              {"LOG", 110},
              {"LOG10", 111},
              {"POWFUN", 112},
              {"SQRT", 113},
              {"ABS", 114},
              {"MIN", 115},
              {"MAX", 116},
              {"FMOD", 117},
              {"REMAINDER", 118},
              {"FLOOR", 119},
              {"CEIL", 120},
              {"RINT", 121},
              {"RDTBL", 122},
              {"RWTBL", 123},
              {"SELECT2", 124},
              {"SELECT3", 125},
              {"INT", 126},
              {"FLOAT", 127},
              {"LAMBDA", 128},
              {"WIRE", 129},
              {"CUT", 130},
              {"LPAR", 131},
              {"COMPONENT", 132},
              {"LIBRARY", 133},
              {"ENVIRONMENT", 134},
              {"WAVEFORM", 135},
              {"ROUTE", 136},
              {"ENABLE", 137},
              {"CONTROL", 138},
              {"ITERATE_PARALLEL", 139},
              {"ISEQ", 140},
              {"ISUM", 141},
              {"IPROD", 142},
              {"INPUTS", 143},
              {"OUTPUTS", 144},
              {"IDENT", 3},
              {"CASE", 145},
              {"ASSERTBOUNDS", 146},
              {"LOWEST", 147},
              {"HIGHEST", 148}
            },
            {
              {"expression.component", 150},
              {"expression.composition.serial", 589},
              {"expression.composition.mix", 154},
              {"expression.composition.recursive", 155},
              {"expression.composition.sequence", 156},
              {"expression.composition.split", 157},
              {"expression.environment", 158},
              {"expression.infix", 159},
              {"expression.infix.definitions.substitution", 160},
              {"expression.infix.environment.access", 161},
              {"expression.infix.math", 162},
              {"expression.infix.math.algebra", 163},
              {"expression.infix.math.comparison", 164},
              {"expression.infix.math.logic", 165},
              {"expression.infix.math.shift", 166},
              {"expression.infix.prefix", 167},
              {"expression.infix.signal.delay", 168},
              {"expression.iterate.parallel", 169},
              {"expression.iterate.sequence", 170},
              {"expression.iterate.sum", 171},
              {"expression.iterate.product", 172},
              {"expression.lambda", 173},
              {"expression.library", 175},
              {"expression.math", 176},
              {"expression.math.comparison", 177},
              {"expression.math.rounding", 178},
              {"expression.math.signal", 179},
              {"expression.math.signal.algebra", 180},
              {"expression.math.signal.shift", 181},
              {"expression.math.signal.power", 182},
              {"expression.math.scalar.as.tree", 183},
              {"expression.math.scalar.int", 184},
              {"expression.math.scalar.int.as.tree", 185},
              {"expression.math.scalar.float", 186},
              {"expression.math.scalar.float.as.tree", 187},
              {"expression.math.trigonometry.as.tree", 188},
              {"expression.parenthesis", 189},
              {"expression.signal", 190},
              {"expression.signal.control", 191},
              {"expression.signal.delay", 192},
              {"expression.signal.logic", 193},
              {"primitive", 194},
              {"primitive.foreign", 195},
              {"primitive.type.number.as.tree", 196},
              {"primitive.type.number.int", 197},
              {"primitive.type.number.float", 198},
              {"primitive.type.number.int.as.tree", 199},
              {"primitive.type.number.float.as.tree", 200},
              {"primitive.signal", 201},
              {"primitive.signal.input.wire", 202},
              {"primitive.signal.input.terminate", 203},
              {"primitive.type.cast.number", 204},
              {"primitive.type.cast.number.int", 205},
              {"primitive.type.cast.number.float", 206},
              {"primitive.signal.route", 207},
              {"primitive.signal.route.implied.outputs", 208},
              {"primitive.signal.route.implied.connections", 209},
              {"primitive.signal.route.explicit", 210},
              {"primitive.signal.source", 211},
              {"primitive.signal.source.table", 212},
              {"primitive.signal.source.soundfile", 213},
              {"primitive.signal.source.waveform.as.tree", 214},
              {"primitive.ui", 215},
              {"primitive.ui.button", 216},
              {"primitive.ui.checkbox", 217},
              {"primitive.ui.vslider", 218},
              {"primitive.ui.hslider", 219},
              {"primitive.ui.nentry", 220},
              {"primitive.ui.vgroup", 221},
              {"primitive.ui.hgroup", 222},
              {"primitive.ui.tgroup", 223},
              {"primitive.ui.vbargraph", 224},
              {"primitive.ui.hbargraph", 225},
              {"primitive.foreign.function", 226},
              {"primitive.foreign.constant", 227},
              {"primitive.foreign.variable", 228},
              {"primitive.signal.inputs", 229},
              {"primitive.signal.outputs", 230},
              {"statement.box.identifier.as.tree", 232}
            }
          },
          { /* State 586 */
            {
              Context(
                "primitive.foreign.function.signature",
                { "primitive.type.cast.number", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "OR", "statement.foreign.function.identifier.as.tree", "LPAR", "primitive.type.list", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 587 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293},
              {"RPAR", 590}
            },
            {}
          },
          { /* State 588 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293},
              {"RPAR", 591}
            },
            {}
          },
          { /* State 589 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial" },
                { "MIX", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial" },
                { "REC", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial" },
                { "SEQ", "expression.composition.serial" }
              ),
              Context(
                "expression.composition.split",
                { "expression.composition.serial" },
                { "SPLIT", "expression.composition.serial" }
              ),
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 290},
              {"MIX", 291},
              {"SEQ", 292},
              {"REC", 293},
              {"RPAR", 592}
            },
            {}
          },
          { /* State 590 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 591 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 592 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" },
                {}
              )
            },
            {},
            {}
          }
          /* std::vector<std::map<std::string,int>> */
        };
        return transitions_map;
      }

    }
  }
}
