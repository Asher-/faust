
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
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"program", 9},
              {"statement", 10},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.list", 20},
              {"statement.list.start", 21},
              {"statement.list.start.qualified", 22},
              {"statement.list.append", 23},
              {"statement.list.append.qualified", 24},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 26},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 1 */
            {
              Context(
                "statement.import",
                { "IMPORT" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR", "statement.terminal" }
              )
            },
            {
              {"LPAR", 29}
            },
            {}
          },
          { /* State 2 */
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
          { /* State 3 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE" },
                { "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "statement.terminal" }
              ),
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE" },
                { "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "statement.terminal" }
              )
            },
            {
              {"IDENT", 30}
            },
            {
              {"statement.identifier.as.tree", 31}
            }
          },
          { /* State 4 */
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
          { /* State 5 */
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
          { /* State 6 */
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
          { /* State 7 */
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
          { /* State 8 */
            {
              Context(
                "statement.declare.doc",
                { "BDOC" },
                { "doc", "EDOC" }
              )
            },
            {
              {"BEQN", 32},
              {"BDGM", 33},
              {"BLST", 34},
              {"BMETADATA", 35},
              {"DOCCHAR", 36},
              {"NOTICE", 37}
            },
            {
              {"doc", 38},
              {"doc.text", 39},
              {"doc.equation", 40},
              {"doc.diagram", 41},
              {"doc.notice", 42},
              {"doc.metadata", 43},
              {"doc.list", 44}
            }
          },
          { /* State 9 */
            {
              Context(
                "$accept",
                { "program" },
                { "ENDOFINPUT" }
              )
            },
            {
              {"ENDOFINPUT", 45}
            },
            {}
          },
          { /* State 10 */
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
          { /* State 11 */
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
          { /* State 12 */
            {
              Context(
                "statement.definition.function",
                { "statement.definition.function.declaration" },
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 49}
            }
          },
          { /* State 13 */
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
          { /* State 14 */
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
          { /* State 15 */
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
          { /* State 16 */
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
          { /* State 17 */
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
          { /* State 18 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree" },
                { "LPAR", "statement.definition.function.args", "RPAR", "DEF", "expression" }
              ),
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree" },
                { "statement.definition.assignment.operator", "expression", "statement.terminal" }
              )
            },
            {
              {"LPAR", 50},
              {"DEF", 51}
            },
            {
              {"statement.definition.assignment.operator", 52}
            }
          },
          { /* State 19 */
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
          { /* State 20 */
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
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"statement", 53},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 54},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 21 */
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
          { /* State 22 */
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
          { /* State 23 */
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
          { /* State 24 */
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
          { /* State 25 */
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
          { /* State 26 */
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
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"statement", 55},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.math.precision", 56}
            }
          },
          { /* State 27 */
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
          { /* State 28 */
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
          { /* State 29 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR", "statement.terminal" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 59}
            }
          },
          { /* State 30 */
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
          { /* State 31 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree" },
                { "primitive.string.quoted.as.tree", "statement.terminal" }
              ),
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree" },
                { "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "statement.terminal" }
              )
            },
            {
              {"STRING", 60},
              {"IDENT", 30}
            },
            {
              {"primitive.string.quoted", 61},
              {"primitive.string.quoted.as.tree", 62},
              {"statement.identifier.as.tree", 63}
            }
          },
          { /* State 32 */
            {
              Context(
                "doc.equation",
                { "BEQN" },
                { "expression", "EEQN" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 148},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 33 */
            {
              Context(
                "doc.diagram",
                { "BDGM" },
                { "expression", "EDGM" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 232},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 34 */
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
              {"ELST", 233},
              {"LSTDEPENDENCIES", 234},
              {"LSTMDOCTAGS", 235},
              {"LSTDISTRIBUTED", 236}
            },
            {
              {"doc.attribute.list", 237},
              {"doc.attribute.definition", 238}
            }
          },
          { /* State 35 */
            {
              Context(
                "doc.metadata",
                { "BMETADATA" },
                { "statement.identifier.as.tree", "EMETADATA" }
              )
            },
            {
              {"IDENT", 30}
            },
            {
              {"statement.identifier.as.tree", 239}
            }
          },
          { /* State 36 */
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
          { /* State 37 */
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
          { /* State 38 */
            {
              Context(
                "statement.declare.doc",
                { "BDOC", "doc" },
                { "EDOC" }
              )
            },
            {
              {"EDOC", 240}
            },
            {}
          },
          { /* State 39 */
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
              {"DOCCHAR", 241}
            },
            {}
          },
          { /* State 40 */
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
          { /* State 41 */
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
          { /* State 42 */
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
          { /* State 43 */
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
          { /* State 44 */
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
          { /* State 45 */
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
          { /* State 46 */
            {
              Context(
                "statement.terminal",
                { "ENDOFINPUT" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 47 */
            {
              Context(
                "statement.terminal",
                { "ENDDEF" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 48 */
            {
              Context(
                "statement.terminal",
                { "ENDL" },
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
                { "statement.definition.function.declaration", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 50 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR" },
                { "statement.definition.function.args", "RPAR", "DEF", "expression" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 243},
              {"statement.definition.function.args", 244},
              {"statement.definition.function.args.start", 245},
              {"statement.definition.function.args.append", 246},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 51 */
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
          { /* State 52 */
            {
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree", "statement.definition.assignment.operator" },
                { "expression", "statement.terminal" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 247},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 53 */
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
          { /* State 54 */
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
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"statement", 248},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.math.precision", 56}
            }
          },
          { /* State 55 */
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
          { /* State 56 */
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
          { /* State 57 */
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
          { /* State 58 */
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
          { /* State 59 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR", "statement.terminal" }
              )
            },
            {
              {"RPAR", 249}
            },
            {}
          },
          { /* State 60 */
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
          { /* State 61 */
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
          { /* State 62 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree", "primitive.string.quoted.as.tree" },
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 250}
            }
          },
          { /* State 63 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree" },
                { "primitive.string.quoted.as.tree", "statement.terminal" }
              )
            },
            {
              {"STRING", 60}
            },
            {
              {"primitive.string.quoted", 61},
              {"primitive.string.quoted.as.tree", 251}
            }
          },
          { /* State 64 */
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
          { /* State 65 */
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
          { /* State 66 */
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
          { /* State 67 */
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
          { /* State 68 */
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
          { /* State 69 */
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
          { /* State 70 */
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
              {"INT", 252},
              {"FLOAT", 253}
            },
            {}
          },
          { /* State 71 */
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
              {"INT", 254},
              {"FLOAT", 255},
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 256}
            }
          },
          { /* State 72 */
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
          { /* State 73 */
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
          { /* State 74 */
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
          { /* State 75 */
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
          { /* State 76 */
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
          { /* State 77 */
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
          { /* State 78 */
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
          { /* State 79 */
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
          { /* State 80 */
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
          { /* State 81 */
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
          { /* State 82 */
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
          { /* State 83 */
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
          { /* State 84 */
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
          { /* State 85 */
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
          { /* State 86 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION" },
                { "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 257}
            },
            {}
          },
          { /* State 87 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT" },
                { "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
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
                "primitive.foreign.variable",
                { "FVARIABLE" },
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
                "primitive.ui.button",
                { "BUTTON" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
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
                "primitive.ui.checkbox",
                { "CHECKBOX" },
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
                "primitive.ui.vslider",
                { "VSLIDER" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
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
                "primitive.ui.hslider",
                { "HSLIDER" },
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
                "primitive.ui.nentry",
                { "NENTRY" },
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
                "primitive.ui.vgroup",
                { "VGROUP" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
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
                "primitive.ui.hgroup",
                { "HGROUP" },
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
                "primitive.ui.tgroup",
                { "TGROUP" },
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
                "primitive.ui.hbargraph",
                { "HBARGRAPH" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
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
                "primitive.ui.vbargraph",
                { "VBARGRAPH" },
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
                "primitive.signal.source.soundfile",
                { "SOUNDFILE" },
                { "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition", "RPAR" }
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
                "expression.signal.control",
                { "ATTACH" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 101 */
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
          { /* State 102 */
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
          { /* State 103 */
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
          { /* State 104 */
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
          { /* State 105 */
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
          { /* State 106 */
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
          { /* State 107 */
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
          { /* State 108 */
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
          { /* State 109 */
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
          { /* State 110 */
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
          { /* State 111 */
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
          { /* State 112 */
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
          { /* State 113 */
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
          { /* State 114 */
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
          { /* State 115 */
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
          { /* State 116 */
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
          { /* State 117 */
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
          { /* State 118 */
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
          { /* State 119 */
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
          { /* State 120 */
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
          { /* State 121 */
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
          { /* State 122 */
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
          { /* State 123 */
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
          { /* State 124 */
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
          { /* State 125 */
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
          { /* State 126 */
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
          { /* State 127 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA" },
                { "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 271}
            },
            {}
          },
          { /* State 128 */
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
          { /* State 129 */
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
          { /* State 130 */
            {
              Context(
                "expression.parenthesis",
                { "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 272},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 131 */
            {
              Context(
                "expression.component",
                { "COMPONENT" },
                { "LPAR", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"LPAR", 273}
            },
            {}
          },
          { /* State 132 */
            {
              Context(
                "expression.library",
                { "LIBRARY" },
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
                "expression.environment",
                { "ENVIRONMENT" },
                { "LBRAQ", "statement.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 275}
            },
            {}
          },
          { /* State 134 */
            {
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM" },
                { "LBRAQ", "primitive.type.number.list.as.tree", "RBRAQ" }
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
              {"LPAR", 277}
            },
            {}
          },
          { /* State 136 */
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
          { /* State 137 */
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
          { /* State 138 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL" },
                { "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 278}
            },
            {}
          },
          { /* State 139 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ" },
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
                "expression.iterate.sum",
                { "ISUM" },
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
                "expression.iterate.product",
                { "IPROD" },
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
                "primitive.signal.inputs",
                { "INPUTS" },
                { "LPAR", "expression", "RPAR" }
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
                "primitive.signal.outputs",
                { "OUTPUTS" },
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
                "expression.signal.logic",
                { "CASE" },
                { "LBRAQ", "statement.signal.pattern.rule.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 284}
            },
            {}
          },
          { /* State 145 */
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
          { /* State 146 */
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
          { /* State 147 */
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
          { /* State 148 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"EEQN", 288}
            },
            {}
          },
          { /* State 149 */
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
          { /* State 150 */
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
          { /* State 151 */
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
          { /* State 152 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292}
            },
            {}
          },
          { /* State 153 */
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
          { /* State 154 */
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
          { /* State 155 */
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
          { /* State 156 */
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
          { /* State 157 */
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
          { /* State 158 */
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
              {"LT", 293},
              {"LE", 294},
              {"EQ", 295},
              {"GT", 296},
              {"GE", 297},
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
            },
            {}
          },
          { /* State 159 */
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
          { /* State 160 */
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
          { /* State 161 */
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
          { /* State 162 */
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
          { /* State 163 */
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
          { /* State 164 */
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
          { /* State 165 */
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
          { /* State 166 */
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
          { /* State 167 */
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
          { /* State 168 */
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
          { /* State 169 */
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
          { /* State 170 */
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
          { /* State 171 */
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
          { /* State 172 */
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
          { /* State 173 */
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
          { /* State 174 */
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
          { /* State 175 */
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
          { /* State 176 */
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
          { /* State 177 */
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
          { /* State 178 */
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
          { /* State 179 */
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
          { /* State 180 */
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
          { /* State 181 */
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
          { /* State 182 */
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
          { /* State 183 */
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
          { /* State 184 */
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
          { /* State 185 */
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
          { /* State 186 */
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
          { /* State 187 */
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
          { /* State 188 */
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
          { /* State 189 */
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
          { /* State 190 */
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
          { /* State 191 */
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
          { /* State 192 */
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
          { /* State 193 */
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
          { /* State 194 */
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
          { /* State 195 */
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
          { /* State 196 */
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
          { /* State 197 */
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
          { /* State 198 */
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
          { /* State 199 */
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
          { /* State 200 */
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
          { /* State 201 */
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
          { /* State 202 */
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
          { /* State 203 */
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
          { /* State 204 */
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
          { /* State 205 */
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
          { /* State 206 */
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
          { /* State 207 */
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
          { /* State 208 */
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
          { /* State 209 */
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
          { /* State 210 */
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
          { /* State 211 */
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
          { /* State 212 */
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
          { /* State 213 */
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
          { /* State 214 */
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
          { /* State 215 */
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
          { /* State 216 */
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
          { /* State 217 */
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
          { /* State 218 */
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
          { /* State 219 */
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
          { /* State 220 */
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
          { /* State 221 */
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
          { /* State 222 */
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
          { /* State 223 */
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
          { /* State 224 */
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
          { /* State 225 */
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
          { /* State 226 */
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
          { /* State 227 */
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
          { /* State 228 */
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
          { /* State 229 */
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
          { /* State 230 */
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
          { /* State 231 */
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
          { /* State 232 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"EDGM", 315}
            },
            {}
          },
          { /* State 233 */
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
          { /* State 234 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES" },
                { "LSTEQ", "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTEQ", 316}
            },
            {}
          },
          { /* State 235 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS" },
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
                { "LSTDISTRIBUTED" },
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
              {"ELST", 319},
              {"LSTDEPENDENCIES", 234},
              {"LSTMDOCTAGS", 235},
              {"LSTDISTRIBUTED", 236}
            },
            {
              {"doc.attribute.definition", 320}
            }
          },
          { /* State 238 */
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
          { /* State 239 */
            {
              Context(
                "doc.metadata",
                { "BMETADATA", "statement.identifier.as.tree" },
                { "EMETADATA" }
              )
            },
            {
              {"EMETADATA", 321}
            },
            {}
          },
          { /* State 240 */
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
          { /* State 241 */
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
          { /* State 242 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292}
            },
            {}
          },
          { /* State 243 */
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
          { /* State 244 */
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
              {"COMMA", 322},
              {"RPAR", 323}
            },
            {}
          },
          { /* State 245 */
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
          { /* State 246 */
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
          { /* State 247 */
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
                { "statement.terminal" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 324}
            }
          },
          { /* State 248 */
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
          { /* State 249 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree", "RPAR" },
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 325}
            }
          },
          { /* State 250 */
            {
              Context(
                "statement.declare.metadata",
                { "DECLARE", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 251 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree" },
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 326}
            }
          },
          { /* State 252 */
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
          { /* State 253 */
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
          { /* State 254 */
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
          { /* State 255 */
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
          { /* State 256 */
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
          { /* State 257 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR" },
                { "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 84},
              {"FLOATCAST", 85}
            },
            {
              {"primitive.type.cast.number", 327},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.foreign.function.signature", 328}
            }
          },
          { /* State 258 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR" },
                { "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 84},
              {"FLOATCAST", 85}
            },
            {
              {"primitive.type.cast.number", 329},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205}
            }
          },
          { /* State 259 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR" },
                { "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"INTCAST", 84},
              {"FLOATCAST", 85}
            },
            {
              {"primitive.type.cast.number", 330},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205}
            }
          },
          { /* State 260 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 331}
            }
          },
          { /* State 261 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 332}
            }
          },
          { /* State 262 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 333}
            }
          },
          { /* State 263 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 334}
            }
          },
          { /* State 264 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 335}
            }
          },
          { /* State 265 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 336}
            }
          },
          { /* State 266 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 337}
            }
          },
          { /* State 267 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 338}
            }
          },
          { /* State 268 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 339}
            }
          },
          { /* State 269 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 340}
            }
          },
          { /* State 270 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR" },
                { "primitive.string.unquoted.as.tree", "COMMA", "expression.composition", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 341}
            }
          },
          { /* State 271 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR" },
                { "expression.lambda.params", "RPAR", "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"expression.lambda.params", 342},
              {"expression.lambda.params.start", 343},
              {"expression.lambda.params.append", 344},
              {"statement.box.identifier.as.tree", 345}
            }
          },
          { /* State 272 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 346}
            },
            {}
          },
          { /* State 273 */
            {
              Context(
                "expression.component",
                { "COMPONENT", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 347}
            }
          },
          { /* State 274 */
            {
              Context(
                "expression.library",
                { "LIBRARY", "LPAR" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 348}
            }
          },
          { /* State 275 */
            {
              Context(
                "expression.environment",
                { "ENVIRONMENT", "LBRAQ" },
                { "statement.list", "RBRAQ" }
              )
            },
            {
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"statement", 10},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.list", 349},
              {"statement.list.start", 21},
              {"statement.list.start.qualified", 22},
              {"statement.list.append", 23},
              {"statement.list.append.qualified", 24},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 26},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 276 */
            {
              Context(
                "primitive.signal.source.waveform.as.tree",
                { "WAVEFORM", "LBRAQ" },
                { "primitive.type.number.list.as.tree", "RBRAQ" }
              )
            },
            {
              {"ADD", 350},
              {"SUB", 351},
              {"INT", 125},
              {"FLOAT", 126}
            },
            {
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 352},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 353},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 354},
              {"primitive.type.number.float.as.tree", 355},
              {"primitive.type.number.int.list.member.as.tree", 356},
              {"primitive.type.number.list.as.tree", 357},
              {"primitive.type.number.list.member.as.tree", 358},
              {"primitive.type.number.list.start.as.tree", 359},
              {"primitive.type.number.list.append.as.tree", 360},
              {"primitive.type.number.float.list.member.as.tree", 361}
            }
          },
          { /* State 277 */
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
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 362},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 278 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 363}
            }
          },
          { /* State 279 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 364}
            }
          },
          { /* State 280 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 365}
            }
          },
          { /* State 281 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR" },
                { "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 366}
            }
          },
          { /* State 282 */
            {
              Context(
                "primitive.signal.inputs",
                { "INPUTS", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 367},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 283 */
            {
              Context(
                "primitive.signal.outputs",
                { "OUTPUTS", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 368},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 284 */
            {
              Context(
                "expression.signal.logic",
                { "CASE", "LBRAQ" },
                { "statement.signal.pattern.rule.list", "RBRAQ" }
              )
            },
            {
              {"LPAR", 369}
            },
            {
              {"statement.signal.pattern.rule", 370},
              {"statement.signal.pattern.rule.list", 371},
              {"statement.signal.pattern.rule.list.start", 372},
              {"statement.signal.pattern.rule.list.append", 373}
            }
          },
          { /* State 285 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH" },
                { "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"LBRAQ", 374}
            },
            {}
          },
          { /* State 286 */
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
              {"LBRAQ", 375}
            },
            {}
          },
          { /* State 287 */
            {
              Context(
                "expression.composition.parallel",
                { "expression", "COMMA" },
                { "expression" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 376},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 288 */
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
          { /* State 289 */
            {
              Context(
                "expression.composition.split",
                { "expression.composition.serial", "SPLIT" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 377},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 290 */
            {
              Context(
                "expression.composition.mix",
                { "expression.composition.serial", "MIX" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 378},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 291 */
            {
              Context(
                "expression.composition.sequence",
                { "expression.composition.serial", "SEQ" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 379},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 292 */
            {
              Context(
                "expression.composition.recursive",
                { "expression.composition.serial", "REC" },
                { "expression.composition.serial" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 380},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 293 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "LT" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 381},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 294 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "LE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 382},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 295 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "EQ" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 383},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 296 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "GT" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 384},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 297 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "GE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 385},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 298 */
            {
              Context(
                "expression.infix.math.comparison",
                { "expression.infix", "NE" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 386},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 299 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "ADD" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 387},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 300 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "SUB" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 388},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 301 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "OR" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 389},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 302 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "MUL" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 390},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 303 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "DIV" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 391},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 304 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "MOD" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 392},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 305 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "AND" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 393},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 306 */
            {
              Context(
                "expression.infix.math.logic",
                { "expression.infix", "XOR" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 394},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 307 */
            {
              Context(
                "expression.infix.math.shift",
                { "expression.infix", "LSH" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 395},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 308 */
            {
              Context(
                "expression.infix.math.shift",
                { "expression.infix", "RSH" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 396},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 309 */
            {
              Context(
                "expression.infix.math.algebra",
                { "expression.infix", "POWOP" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 397},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 310 */
            {
              Context(
                "expression.infix.signal.delay",
                { "expression.infix", "FDELAY" },
                { "expression.infix" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.environment", 157},
              {"expression.infix", 398},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 311 */
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
          { /* State 312 */
            {
              Context(
                "expression.infix.environment.access",
                { "expression.infix", "DOT" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 399}
            }
          },
          { /* State 313 */
            {
              Context(
                "expression.infix.prefix",
                { "expression.infix", "LPAR" },
                { "statement.definition.function.args", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 243},
              {"statement.definition.function.args", 400},
              {"statement.definition.function.args.start", 245},
              {"statement.definition.function.args.append", 246},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 314 */
            {
              Context(
                "expression.infix.definitions.substitution",
                { "expression.infix", "LCROC" },
                { "statement.definition.list", "RCROC" }
              )
            },
            {
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 401},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.definition.list", 402},
              {"statement.definition.list.start", 403},
              {"statement.definition.list.start.qualified", 404},
              {"statement.definition.list.append", 405},
              {"statement.definition.list.append.qualified", 406},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 407},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 315 */
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
          { /* State 316 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 408}
            },
            {}
          },
          { /* State 317 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 409}
            },
            {}
          },
          { /* State 318 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ" },
                { "LSTQ", "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTQ", 410}
            },
            {}
          },
          { /* State 319 */
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
          { /* State 320 */
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
          { /* State 321 */
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
          { /* State 322 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args", "COMMA" },
                { "statement.definition.function.arg" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 411},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 323 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args", "RPAR" },
                { "DEF", "expression" }
              )
            },
            {
              {"DEF", 412}
            },
            {}
          },
          { /* State 324 */
            {
              Context(
                "statement.definition.assignment",
                { "statement.box.identifier.as.tree", "statement.definition.assignment.operator", "expression", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 325 */
            {
              Context(
                "statement.import",
                { "IMPORT", "LPAR", "primitive.string.unquoted.as.tree", "RPAR", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 326 */
            {
              Context(
                "statement.declare.feature.metadata",
                { "DECLARE", "statement.identifier.as.tree", "statement.identifier.as.tree", "primitive.string.quoted.as.tree", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 327 */
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
              {"IDENT", 413}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 414}
            }
          },
          { /* State 328 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature" },
                { "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 415}
            },
            {}
          },
          { /* State 329 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number" },
                { "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"IDENT", 30}
            },
            {
              {"statement.identifier.as.tree", 416}
            }
          },
          { /* State 330 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number" },
                { "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"IDENT", 30}
            },
            {
              {"statement.identifier.as.tree", 417}
            }
          },
          { /* State 331 */
            {
              Context(
                "primitive.ui.button",
                { "BUTTON", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 418}
            },
            {}
          },
          { /* State 332 */
            {
              Context(
                "primitive.ui.checkbox",
                { "CHECKBOX", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 419}
            },
            {}
          },
          { /* State 333 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 420}
            },
            {}
          },
          { /* State 334 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"COMMA", 421}
            },
            {}
          },
          { /* State 335 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree" },
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
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression", "RPAR" }
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
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression", "RPAR" }
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
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree" },
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
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
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
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
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
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree" },
                { "COMMA", "expression.composition", "RPAR" }
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
              {"COMMA", 429},
              {"RPAR", 430}
            },
            {}
          },
          { /* State 343 */
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
          { /* State 344 */
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
          { /* State 345 */
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
          { /* State 346 */
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
          { /* State 347 */
            {
              Context(
                "expression.component",
                { "COMPONENT", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 431}
            },
            {}
          },
          { /* State 348 */
            {
              Context(
                "expression.library",
                { "LIBRARY", "LPAR", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 432}
            },
            {}
          },
          { /* State 349 */
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
              {"RBRAQ", 433},
              {"IMPORT", 1},
              {"IDENT", 2},
              {"DECLARE", 3},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7},
              {"BDOC", 8}
            },
            {
              {"statement", 53},
              {"statement.definition", 11},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.declare.metadata", 15},
              {"statement.declare.feature.metadata", 16},
              {"statement.declare.doc", 17},
              {"statement.box.identifier.as.tree", 18},
              {"statement.import", 19},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 54},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 350 */
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
              {"INT", 252},
              {"FLOAT", 253}
            },
            {}
          },
          { /* State 351 */
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
              {"INT", 254},
              {"FLOAT", 255}
            },
            {}
          },
          { /* State 352 */
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
          { /* State 353 */
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
          { /* State 354 */
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
          { /* State 355 */
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
          { /* State 356 */
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
          { /* State 357 */
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
              {"COMMA", 434},
              {"RBRAQ", 435}
            },
            {}
          },
          { /* State 358 */
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
          { /* State 359 */
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
          { /* State 360 */
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
          { /* State 361 */
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
          { /* State 362 */
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
              {"COMMA", 436},
              {"RPAR", 437}
            },
            {}
          },
          { /* State 363 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 438}
            },
            {}
          },
          { /* State 364 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"COMMA", 439}
            },
            {}
          },
          { /* State 365 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree" },
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
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree" },
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 442}
            },
            {}
          },
          { /* State 368 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 443}
            },
            {}
          },
          { /* State 369 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR" },
                { "statement.definition.function.args", "RPAR", "ARROW", "expression", "statement.terminal" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 243},
              {"statement.definition.function.args", 444},
              {"statement.definition.function.args.start", 245},
              {"statement.definition.function.args.append", 246},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 370 */
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
          { /* State 371 */
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
              {"LPAR", 369},
              {"RBRAQ", 445}
            },
            {
              {"statement.signal.pattern.rule", 446}
            }
          },
          { /* State 372 */
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
          { /* State 373 */
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
          { /* State 374 */
            {
              Context(
                "statement.definition.with",
                { "expression", "WITH", "LBRAQ" },
                { "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 401},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.definition.list", 447},
              {"statement.definition.list.start", 403},
              {"statement.definition.list.start.qualified", 404},
              {"statement.definition.list.append", 405},
              {"statement.definition.list.append.qualified", 406},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 407},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 375 */
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
              {"error", 448},
              {"DELAY1", 449},
              {"RBRAQ", 450}
            },
            {
              {"expression.letrec.list", 451},
              {"expression.letrec.list.start", 452},
              {"expression.letrec.list.append", 453},
              {"expression.letrec.equation", 454},
              {"expression.letrec.equation.name", 455}
            }
          },
          { /* State 376 */
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
              {"COMMA", 287}
            },
            {}
          },
          { /* State 377 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292}
            },
            {}
          },
          { /* State 378 */
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
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292}
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
              {"SEQ", 291},
              {"REC", 292}
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
          { /* State 381 */
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
              {"LE", 294},
              {"EQ", 295},
              {"GT", 296},
              {"GE", 297},
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
            },
            {}
          },
          { /* State 382 */
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
              {"EQ", 295},
              {"GT", 296},
              {"GE", 297},
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
            },
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
              {"GT", 296},
              {"GE", 297},
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"GE", 297},
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"NE", 298},
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"ADD", 299},
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"SUB", 300},
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"OR", 301},
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"MUL", 302},
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"DIV", 303},
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"MOD", 304},
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"AND", 305},
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"XOR", 306},
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"LSH", 307},
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"RSH", 308},
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"POWOP", 309},
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"FDELAY", 310},
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
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
              {"DELAY1", 311},
              {"DOT", 312},
              {"LPAR", 313},
              {"LCROC", 314}
            },
            {}
          },
          { /* State 399 */
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
          { /* State 400 */
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
              {"COMMA", 322},
              {"RPAR", 456}
            },
            {}
          },
          { /* State 401 */
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
          { /* State 402 */
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
              {"RCROC", 457},
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 458},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 459},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 403 */
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
          { /* State 404 */
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
          { /* State 405 */
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
          { /* State 406 */
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
          { /* State 407 */
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
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 460},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 56}
            }
          },
          { /* State 408 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 461},
              {"LSTFALSE", 462}
            },
            {
              {"doc.attribute.value", 463}
            }
          },
          { /* State 409 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 461},
              {"LSTFALSE", 462}
            },
            {
              {"doc.attribute.value", 464}
            }
          },
          { /* State 410 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ", "LSTQ" },
                { "doc.attribute.value", "LSTQ" }
              )
            },
            {
              {"LSTTRUE", 461},
              {"LSTFALSE", 462}
            },
            {
              {"doc.attribute.value", 465}
            }
          },
          { /* State 411 */
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
          { /* State 412 */
            {
              Context(
                "statement.definition.function.declaration",
                { "statement.box.identifier.as.tree", "LPAR", "statement.definition.function.args", "RPAR", "DEF" },
                { "expression" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 466},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 413 */
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
          { /* State 414 */
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
              {"OR", 467},
              {"LPAR", 468}
            },
            {}
          },
          { /* State 415 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA" },
                { "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 469},
              {"TAGSTRING", 470}
            },
            {
              {"primitive.string.tag", 471},
              {"primitive.string.tag.as.tree", 472}
            }
          },
          { /* State 416 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree" },
                { "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 473}
            },
            {}
          },
          { /* State 417 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree" },
                { "COMMA", "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 474}
            },
            {}
          },
          { /* State 418 */
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
          { /* State 419 */
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
          { /* State 420 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 475},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 421 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 476},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 422 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 477},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 423 */
            {
              Context(
                "primitive.ui.vgroup",
                { "VGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 478},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 424 */
            {
              Context(
                "primitive.ui.hgroup",
                { "HGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 479},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 425 */
            {
              Context(
                "primitive.ui.tgroup",
                { "TGROUP", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 480},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 426 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 481},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 427 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 482},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 428 */
            {
              Context(
                "primitive.signal.source.soundfile",
                { "SOUNDFILE", "LPAR", "primitive.string.unquoted.as.tree", "COMMA" },
                { "expression.composition", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 483},
              {"expression.component", 149},
              {"expression.composition", 484},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 429 */
            {
              Context(
                "expression.lambda.params.append",
                { "expression.lambda.params", "COMMA" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 485}
            }
          },
          { /* State 430 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR" },
                { "DOT", "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"DOT", 486}
            },
            {}
          },
          { /* State 431 */
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
          { /* State 432 */
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
          { /* State 433 */
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
          { /* State 434 */
            {
              Context(
                "primitive.type.number.list.append.as.tree",
                { "primitive.type.number.list.as.tree", "COMMA" },
                { "primitive.type.number.list.member.as.tree" }
              )
            },
            {
              {"ADD", 350},
              {"SUB", 351},
              {"INT", 125},
              {"FLOAT", 126}
            },
            {
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 352},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 353},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 354},
              {"primitive.type.number.float.as.tree", 355},
              {"primitive.type.number.int.list.member.as.tree", 356},
              {"primitive.type.number.list.member.as.tree", 487},
              {"primitive.type.number.float.list.member.as.tree", 361}
            }
          },
          { /* State 435 */
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
          { /* State 436 */
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
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 242},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.function.arg", 488},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 437 */
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
          { /* State 438 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 489},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 439 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 490},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 440 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 491},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 441 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 492},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 442 */
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
          { /* State 443 */
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
          { /* State 444 */
            {
              Context(
                "statement.definition.function.args.append",
                { "statement.definition.function.args" },
                { "COMMA", "statement.definition.function.arg" }
              ),
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args" },
                { "RPAR", "ARROW", "expression", "statement.terminal" }
              )
            },
            {
              {"COMMA", 322},
              {"RPAR", 493}
            },
            {}
          },
          { /* State 445 */
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
          { /* State 446 */
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
          { /* State 447 */
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
              {"RBRAQ", 494},
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 458},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 459},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 448 */
            {
              Context(
                "expression.letrec.equation",
                { "error" },
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 495}
            }
          },
          { /* State 449 */
            {
              Context(
                "expression.letrec.equation.name",
                { "DELAY1" },
                { "statement.box.identifier.as.tree" }
              )
            },
            {
              {"IDENT", 2}
            },
            {
              {"statement.box.identifier.as.tree", 496}
            }
          },
          { /* State 450 */
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
          { /* State 451 */
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
              {"error", 448},
              {"DELAY1", 449},
              {"RBRAQ", 497},
              {"WHERE", 498}
            },
            {
              {"expression.letrec.equation", 499},
              {"expression.letrec.equation.name", 455}
            }
          },
          { /* State 452 */
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
          { /* State 453 */
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
          { /* State 454 */
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
          { /* State 455 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name" },
                { "DEF", "expression", "statement.terminal" }
              )
            },
            {
              {"DEF", 500}
            },
            {}
          },
          { /* State 456 */
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
          { /* State 457 */
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
          { /* State 458 */
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
          { /* State 459 */
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
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 501},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 56}
            }
          },
          { /* State 460 */
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
          { /* State 461 */
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
          { /* State 462 */
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
          { /* State 463 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDEPENDENCIES", "LSTEQ", "LSTQ", "doc.attribute.value" },
                { "LSTQ" }
              )
            },
            {
              {"LSTQ", 502}
            },
            {}
          },
          { /* State 464 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTMDOCTAGS", "LSTEQ", "LSTQ", "doc.attribute.value" },
                { "LSTQ" }
              )
            },
            {
              {"LSTQ", 503}
            },
            {}
          },
          { /* State 465 */
            {
              Context(
                "doc.attribute.definition",
                { "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "doc.attribute.value" },
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287}
            },
            {}
          },
          { /* State 467 */
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
              {"IDENT", 413}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 505}
            }
          },
          { /* State 468 */
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
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"ANYCAST", 506},
              {"RPAR", 507}
            },
            {
              {"primitive.type", 508},
              {"primitive.type.cast.number", 509},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.type.cast.any", 510},
              {"primitive.type.list", 511},
              {"primitive.type.list.start", 512},
              {"primitive.type.list.append", 513}
            }
          },
          { /* State 469 */
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
          { /* State 470 */
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
          { /* State 471 */
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
          { /* State 472 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree" },
                { "COMMA", "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"COMMA", 514}
            },
            {}
          },
          { /* State 473 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA" },
                { "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 469},
              {"TAGSTRING", 470}
            },
            {
              {"primitive.string.tag", 471},
              {"primitive.string.tag.as.tree", 515}
            }
          },
          { /* State 474 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA" },
                { "primitive.string.tag.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 469},
              {"TAGSTRING", 470}
            },
            {
              {"primitive.string.tag", 471},
              {"primitive.string.tag.as.tree", 516}
            }
          },
          { /* State 475 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 517},
              {"REC", 292}
            },
            {}
          },
          { /* State 476 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 518},
              {"REC", 292}
            },
            {}
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
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 519},
              {"REC", 292}
            },
            {}
          },
          { /* State 478 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 520}
            },
            {}
          },
          { /* State 479 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 521}
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 522}
            },
            {}
          },
          { /* State 481 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 523},
              {"REC", 292}
            },
            {}
          },
          { /* State 482 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 524},
              {"REC", 292}
            },
            {}
          },
          { /* State 483 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287}
            },
            {}
          },
          { /* State 484 */
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
              {"RPAR", 525}
            },
            {}
          },
          { /* State 485 */
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
          { /* State 486 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT" },
                { "LPAR", "expression", "RPAR" }
              )
            },
            {
              {"LPAR", 526}
            },
            {}
          },
          { /* State 487 */
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
          { /* State 488 */
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
              {"COMMA", 527},
              {"RPAR", 528}
            },
            {}
          },
          { /* State 489 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 529},
              {"REC", 292}
            },
            {}
          },
          { /* State 490 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 530},
              {"REC", 292}
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
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 531},
              {"REC", 292}
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
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression", "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 532},
              {"REC", 292}
            },
            {}
          },
          { /* State 493 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR" },
                { "ARROW", "expression", "statement.terminal" }
              )
            },
            {
              {"ARROW", 533}
            },
            {}
          },
          { /* State 494 */
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
          { /* State 495 */
            {
              Context(
                "expression.letrec.equation",
                { "error", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 496 */
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
          { /* State 497 */
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
          { /* State 498 */
            {
              Context(
                "expression.letrec",
                { "expression", "LETREC", "LBRAQ", "expression.letrec.list", "WHERE" },
                { "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 401},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.definition.list", 534},
              {"statement.definition.list.start", 403},
              {"statement.definition.list.start.qualified", 404},
              {"statement.definition.list.append", 405},
              {"statement.definition.list.append.qualified", 406},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 407},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 499 */
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
          { /* State 500 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name", "DEF" },
                { "expression", "statement.terminal" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 535},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 501 */
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
          { /* State 502 */
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
          { /* State 503 */
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
          { /* State 504 */
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
          { /* State 505 */
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
              {"OR", 536},
              {"LPAR", 537}
            },
            {}
          },
          { /* State 506 */
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
          { /* State 507 */
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
          { /* State 508 */
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
          { /* State 509 */
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
          { /* State 510 */
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
          { /* State 511 */
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
              {"COMMA", 538},
              {"RPAR", 539}
            },
            {}
          },
          { /* State 512 */
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
          { /* State 513 */
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
          { /* State 514 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA" },
                { "primitive.string.unquoted.as.tree", "RPAR" }
              )
            },
            {
              {"STRING", 57}
            },
            {
              {"primitive.string.unquoted", 58},
              {"primitive.string.unquoted.as.tree", 540}
            }
          },
          { /* State 515 */
            {
              Context(
                "primitive.foreign.constant",
                { "FCONSTANT", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 541}
            },
            {}
          },
          { /* State 516 */
            {
              Context(
                "primitive.foreign.variable",
                { "FVARIABLE", "LPAR", "primitive.type.cast.number", "statement.identifier.as.tree", "COMMA", "primitive.string.tag.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 542}
            },
            {}
          },
          { /* State 517 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 543},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 518 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 544},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 519 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 545},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 520 */
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
          { /* State 521 */
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
          { /* State 522 */
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
          { /* State 523 */
            {
              Context(
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 546},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 524 */
            {
              Context(
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 547},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 525 */
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
          { /* State 526 */
            {
              Context(
                "expression.lambda",
                { "LAMBDA", "LPAR", "expression.lambda.params", "RPAR", "DOT", "LPAR" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 548},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 527 */
            {
              Context(
                "primitive.signal.route.explicit",
                { "ROUTE", "LPAR", "statement.definition.function.arg", "COMMA", "statement.definition.function.arg", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 549},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 528 */
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
          { /* State 529 */
            {
              Context(
                "expression.iterate.parallel",
                { "ITERATE_PARALLEL", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 550},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 530 */
            {
              Context(
                "expression.iterate.sequence",
                { "ISEQ", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 551},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 531 */
            {
              Context(
                "expression.iterate.sum",
                { "ISUM", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 552},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 532 */
            {
              Context(
                "expression.iterate.product",
                { "IPROD", "LPAR", "statement.box.identifier.as.tree", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 553},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 533 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR", "ARROW" },
                { "expression", "statement.terminal" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression", 554},
              {"expression.component", 149},
              {"expression.composition", 150},
              {"expression.composition.parallel", 151},
              {"expression.composition.serial", 152},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.letrec", 173},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.definition.with", 230},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 534 */
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
              {"RBRAQ", 555},
              {"IDENT", 2},
              {"FLOATMODE", 4},
              {"DOUBLEMODE", 5},
              {"QUADMODE", 6},
              {"FIXEDPOINTMODE", 7}
            },
            {
              {"statement.definition", 458},
              {"statement.definition.function.declaration", 12},
              {"statement.definition.function", 13},
              {"statement.definition.assignment", 14},
              {"statement.box.identifier.as.tree", 18},
              {"statement.math.precision", 25},
              {"statement.math.precision.list", 459},
              {"statement.math.precision.list.start", 27},
              {"statement.math.precision.list.append", 28}
            }
          },
          { /* State 535 */
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
                { "statement.terminal" }
              ),
              Context(
                "statement.definition.with",
                { "expression" },
                { "WITH", "LBRAQ", "statement.definition.list", "RBRAQ" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 556}
            }
          },
          { /* State 536 */
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
              {"IDENT", 413}
            },
            {
              {"statement.foreign.function.identifier.as.tree", 557}
            }
          },
          { /* State 537 */
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
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"ANYCAST", 506},
              {"RPAR", 558}
            },
            {
              {"primitive.type", 508},
              {"primitive.type.cast.number", 509},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.type.cast.any", 510},
              {"primitive.type.list", 559},
              {"primitive.type.list.start", 512},
              {"primitive.type.list.append", 513}
            }
          },
          { /* State 538 */
            {
              Context(
                "primitive.type.list.append",
                { "primitive.type.list", "COMMA" },
                { "primitive.type" }
              )
            },
            {
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"ANYCAST", 506}
            },
            {
              {"primitive.type", 560},
              {"primitive.type.cast.number", 509},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.type.cast.any", 510}
            }
          },
          { /* State 539 */
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
          { /* State 540 */
            {
              Context(
                "primitive.foreign.function",
                { "FFUNCTION", "LPAR", "primitive.foreign.function.signature", "COMMA", "primitive.string.tag.as.tree", "COMMA", "primitive.string.unquoted.as.tree" },
                { "RPAR" }
              )
            },
            {
              {"RPAR", 561}
            },
            {}
          },
          { /* State 541 */
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
          { /* State 542 */
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
          { /* State 543 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 562},
              {"REC", 292}
            },
            {}
          },
          { /* State 544 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 563},
              {"REC", 292}
            },
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
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 564},
              {"REC", 292}
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
                "primitive.ui.hbargraph",
                { "HBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292},
              {"RPAR", 565}
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
                "primitive.ui.vbargraph",
                { "VBARGRAPH", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292},
              {"RPAR", 566}
            },
            {}
          },
          { /* State 548 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"RPAR", 567}
            },
            {}
          },
          { /* State 549 */
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
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
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
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
                { "statement.terminal" }
              )
            },
            {
              {"ENDOFINPUT", 46},
              {"WITH", 285},
              {"LETREC", 286},
              {"COMMA", 287},
              {"ENDDEF", 47},
              {"ENDL", 48}
            },
            {
              {"statement.terminal", 573}
            }
          },
          { /* State 555 */
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
          { /* State 556 */
            {
              Context(
                "expression.letrec.equation",
                { "expression.letrec.equation.name", "DEF", "expression", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 557 */
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
              {"LPAR", 574}
            },
            {}
          },
          { /* State 558 */
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
          { /* State 559 */
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
              {"COMMA", 538},
              {"RPAR", 575}
            },
            {}
          },
          { /* State 560 */
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
          { /* State 561 */
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
          { /* State 562 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 576},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 563 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 577},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 564 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 578},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 565 */
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
          { /* State 566 */
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
          { /* State 567 */
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
          { /* State 568 */
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
          { /* State 569 */
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
          { /* State 570 */
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
          { /* State 571 */
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
          { /* State 572 */
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
          { /* State 573 */
            {
              Context(
                "statement.signal.pattern.rule",
                { "LPAR", "statement.definition.function.args", "RPAR", "ARROW", "expression", "statement.terminal" },
                {}
              )
            },
            {},
            {}
          },
          { /* State 574 */
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
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"ANYCAST", 506},
              {"RPAR", 579}
            },
            {
              {"primitive.type", 508},
              {"primitive.type.cast.number", 509},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.type.cast.any", 510},
              {"primitive.type.list", 580},
              {"primitive.type.list.start", 512},
              {"primitive.type.list.append", 513}
            }
          },
          { /* State 575 */
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
          { /* State 576 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 581},
              {"REC", 292}
            },
            {}
          },
          { /* State 577 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 582},
              {"REC", 292}
            },
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
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "COMMA", "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"COMMA", 583},
              {"REC", 292}
            },
            {}
          },
          { /* State 579 */
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
          { /* State 580 */
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
              {"COMMA", 538},
              {"RPAR", 584}
            },
            {}
          },
          { /* State 581 */
            {
              Context(
                "primitive.ui.vslider",
                { "VSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 585},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 582 */
            {
              Context(
                "primitive.ui.hslider",
                { "HSLIDER", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 586},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 583 */
            {
              Context(
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA" },
                { "expression.composition.serial", "RPAR" }
              )
            },
            {
              {"LT", 64},
              {"LE", 65},
              {"EQ", 66},
              {"GT", 67},
              {"GE", 68},
              {"NE", 69},
              {"ADD", 70},
              {"SUB", 71},
              {"OR", 72},
              {"MUL", 73},
              {"DIV", 74},
              {"MOD", 75},
              {"AND", 76},
              {"XOR", 77},
              {"LSH", 78},
              {"RSH", 79},
              {"POWOP", 80},
              {"FDELAY", 81},
              {"MEM", 82},
              {"PREFIX", 83},
              {"INTCAST", 84},
              {"FLOATCAST", 85},
              {"FFUNCTION", 86},
              {"FCONSTANT", 87},
              {"FVARIABLE", 88},
              {"BUTTON", 89},
              {"CHECKBOX", 90},
              {"VSLIDER", 91},
              {"HSLIDER", 92},
              {"NENTRY", 93},
              {"VGROUP", 94},
              {"HGROUP", 95},
              {"TGROUP", 96},
              {"HBARGRAPH", 97},
              {"VBARGRAPH", 98},
              {"SOUNDFILE", 99},
              {"ATTACH", 100},
              {"ACOS", 101},
              {"ASIN", 102},
              {"ATAN", 103},
              {"ATAN2", 104},
              {"COS", 105},
              {"SIN", 106},
              {"TAN", 107},
              {"EXP", 108},
              {"LOG", 109},
              {"LOG10", 110},
              {"POWFUN", 111},
              {"SQRT", 112},
              {"ABS", 113},
              {"MIN", 114},
              {"MAX", 115},
              {"FMOD", 116},
              {"REMAINDER", 117},
              {"FLOOR", 118},
              {"CEIL", 119},
              {"RINT", 120},
              {"RDTBL", 121},
              {"RWTBL", 122},
              {"SELECT2", 123},
              {"SELECT3", 124},
              {"INT", 125},
              {"FLOAT", 126},
              {"LAMBDA", 127},
              {"WIRE", 128},
              {"CUT", 129},
              {"LPAR", 130},
              {"COMPONENT", 131},
              {"LIBRARY", 132},
              {"ENVIRONMENT", 133},
              {"WAVEFORM", 134},
              {"ROUTE", 135},
              {"ENABLE", 136},
              {"CONTROL", 137},
              {"ITERATE_PARALLEL", 138},
              {"ISEQ", 139},
              {"ISUM", 140},
              {"IPROD", 141},
              {"INPUTS", 142},
              {"OUTPUTS", 143},
              {"IDENT", 2},
              {"CASE", 144},
              {"ASSERTBOUNDS", 145},
              {"LOWEST", 146},
              {"HIGHEST", 147}
            },
            {
              {"expression.component", 149},
              {"expression.composition.serial", 587},
              {"expression.composition.mix", 153},
              {"expression.composition.recursive", 154},
              {"expression.composition.sequence", 155},
              {"expression.composition.split", 156},
              {"expression.environment", 157},
              {"expression.infix", 158},
              {"expression.infix.definitions.substitution", 159},
              {"expression.infix.environment.access", 160},
              {"expression.infix.math", 161},
              {"expression.infix.math.algebra", 162},
              {"expression.infix.math.comparison", 163},
              {"expression.infix.math.logic", 164},
              {"expression.infix.math.shift", 165},
              {"expression.infix.prefix", 166},
              {"expression.infix.signal.delay", 167},
              {"expression.iterate.parallel", 168},
              {"expression.iterate.sequence", 169},
              {"expression.iterate.sum", 170},
              {"expression.iterate.product", 171},
              {"expression.lambda", 172},
              {"expression.library", 174},
              {"expression.math", 175},
              {"expression.math.comparison", 176},
              {"expression.math.rounding", 177},
              {"expression.math.signal", 178},
              {"expression.math.signal.algebra", 179},
              {"expression.math.signal.shift", 180},
              {"expression.math.signal.power", 181},
              {"expression.math.scalar.as.tree", 182},
              {"expression.math.scalar.int", 183},
              {"expression.math.scalar.int.as.tree", 184},
              {"expression.math.scalar.float", 185},
              {"expression.math.scalar.float.as.tree", 186},
              {"expression.math.trigonometry.as.tree", 187},
              {"expression.parenthesis", 188},
              {"expression.signal", 189},
              {"expression.signal.control", 190},
              {"expression.signal.delay", 191},
              {"expression.signal.logic", 192},
              {"primitive", 193},
              {"primitive.foreign", 194},
              {"primitive.type.number.as.tree", 195},
              {"primitive.type.number.int", 196},
              {"primitive.type.number.float", 197},
              {"primitive.type.number.int.as.tree", 198},
              {"primitive.type.number.float.as.tree", 199},
              {"primitive.signal", 200},
              {"primitive.signal.input.wire", 201},
              {"primitive.signal.input.terminate", 202},
              {"primitive.type.cast.number", 203},
              {"primitive.type.cast.number.int", 204},
              {"primitive.type.cast.number.float", 205},
              {"primitive.signal.route", 206},
              {"primitive.signal.route.implied.outputs", 207},
              {"primitive.signal.route.implied.connections", 208},
              {"primitive.signal.route.explicit", 209},
              {"primitive.signal.source", 210},
              {"primitive.signal.source.table", 211},
              {"primitive.signal.source.soundfile", 212},
              {"primitive.signal.source.waveform.as.tree", 213},
              {"primitive.ui", 214},
              {"primitive.ui.button", 215},
              {"primitive.ui.checkbox", 216},
              {"primitive.ui.vslider", 217},
              {"primitive.ui.hslider", 218},
              {"primitive.ui.nentry", 219},
              {"primitive.ui.vgroup", 220},
              {"primitive.ui.hgroup", 221},
              {"primitive.ui.tgroup", 222},
              {"primitive.ui.vbargraph", 223},
              {"primitive.ui.hbargraph", 224},
              {"primitive.foreign.function", 225},
              {"primitive.foreign.constant", 226},
              {"primitive.foreign.variable", 227},
              {"primitive.signal.inputs", 228},
              {"primitive.signal.outputs", 229},
              {"statement.box.identifier.as.tree", 231}
            }
          },
          { /* State 584 */
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
          { /* State 585 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292},
              {"RPAR", 588}
            },
            {}
          },
          { /* State 586 */
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
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292},
              {"RPAR", 589}
            },
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
                "primitive.ui.nentry",
                { "NENTRY", "LPAR", "primitive.string.unquoted.as.tree", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial", "COMMA", "expression.composition.serial" },
                { "RPAR" }
              )
            },
            {
              {"SPLIT", 289},
              {"MIX", 290},
              {"SEQ", 291},
              {"REC", 292},
              {"RPAR", 590}
            },
            {}
          },
          { /* State 588 */
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
          { /* State 589 */
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
          { /* State 590 */
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
