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

#pragma once

#include <cstdlib>
#include "signalVisitor.hh"
#include "global.hh"
#include "compiler/block_diagram/eval/patternmatcher/old_occurences.hh"

#include "faust/primitive/type/precision.hh"

//-------------------------Signal2VHDLVisitor-------------------------------
// A a signal visitor used to compile signals to vhdl code
//----------------------------------------------------------------------
using namespace std;

#define HIGH 8  //  global::config().gVHDLFloatMSB
#define LOW -23 //  global::config().gVHDLFloatLSB

class Signal2VHDLVisitor : public SignalVisitor {
    protected:

        using Precision = ::Faust::Primitive::Type::Precision;

    private:
        old_OccMarkup* fOccMarkup;
        map<string, bool> fEntity;
        /** Fields used to accumulate strings for different parts of the .vhd file */
        string fInput;
        string fDeclEntity;          // Entity block specification part
        string fFaustEntity;         // Faust block specification
        string fDeclSig;             // Signal declaration
        string fDeclCompnt;          // Declaration of components
        string fFaustProcess;        // Implement the Faust process
        string fMapCompnt;           // Instantiating blocks

        string addr_to_str(Tree t);
        string val_to_str(Tree t);

        void entity_header(string& str);
        void generic_decl(string& str);
        void port_decl(int input, const Precision& precision, string& str);

        /** Functions generating different Faust blocks, each block is treated as an entity with declaration of inputs and outputs:
          *  - Each design must have at least one entity and one corresponding architecture
          *    that specifies the external specification of the design.
          *  - Each entity has a name assigned to it and a port list
          *  - Each port list has a direction (in/out/inout) and a type
          */
        void entity_bin_op(const string& name, const char* op, const Precision& precision,  string& str);   // arithmetic and modulo operation
        void entity_bin_op_concat(const string& name, const char* op, const Precision& precision, string& str);   // arithmetic and modulo operation
        void entity_cmp_op(const string& name, const char* op, const Precision& precision, string& str);   // compare operation
        void entity_delay(const Precision& precision, string& str);                                       // delay
        void entity_delay_var_reg(const Precision& precision, string& str);                                // variable delay (Using Registers)
        void entity_delay_var_ram(const Precision& precision, string& str);                                // variable delay (Using Blocks RAM)
        void entity_bypass(const string& name, const Precision& precision, string& str);                   // bypass module
        void entity_cast(const string& name,const Precision& precision_in, const Precision& precision_out, string& str);   // bypass module
        void entity_select2(const string& name, const Precision& precision, string& str);                  // select module
        void entity_faust();                                                              // main module

        /** Functions declaring the design entity interface for blocks that will be used
          * later to form a hierarchical design
          */
        void component_standard(const string& name, int input, const Precision& precision, string& str);   // arith, mod, bypass, compare, select
        void component_cast(const string& name, int input,const Precision& precision_in, const Precision& precision_out, string& str); //cast
        void component_delay(const Precision& precision, string& str);                                     // delay
        void component_delay_var(const Precision& precision, string& str);                                 // variable delay
        void component_sincos(const Precision& precision, string& str);                                    // cosinus & sinus

        /* Generate the process of the Faust module, it determine the behavioral modeling of the Faust IP */
        void faust_process();

        /** Functions generating instance of components referenced in the declarative area
          * - The instances are constructed after the keyword “begin” and using
          *   the port map statements to connect the ports
          */
        void inst_bin_op(const string& name, Tree sig, Tree x, Tree y, string& str); // arith, mod, compare
        void inst_delay(Tree sig, Tree x, Tree y, string& str);                      // delay
        void inst_delay_var(Tree sig, Tree x, Tree y, string& str, int mxd);         // variable delay
        void inst_sincos(const string& name, Tree sig, Tree x, const Precision& precision, string& str);         // cosinus & sinus
        void inst_bypass(const string& name, Tree sig, Tree x, string& str);         // bypass
        void inst_select2(const string& name, Tree sig, Tree sel, Tree x, Tree y, string& str);  // select

        void decl_sig(Tree x, int msb, int lsb, const Precision& precision); // Declare the internal signals of the IP block with a type (and an initial value)
        void input_affectation(Tree sig,int i);

        void bin_op(const string& name, const char* op, Tree sig, Tree x, Tree y);
        void select_op(const string& name, Tree sig, Tree sel, Tree x, Tree y);
        void cmp_op(const string& name, const char* op, Tree sig, Tree x, Tree y);
        void sincos_op(const string& name, Tree sig, Tree x, const Precision& precision);
        void bypass(const string& name, Tree sig, Tree x);
        void cast(const string& name, Tree sig, Tree x);


        bool globalCodingFloat() {
            return global::config().gVHDLFloatType == 1;
        }

        bool globalCodingSfixed() {
            return global::config().gVHDLFloatType == 0;
        }

        string getObjectSuffix(const Precision& precision)
        {
            if (precision == Precision::Real) {
                return "_" + getRealCoding();
            }   else return "_int";
        }

        string getSignalType(const Precision& precision)
        {
            if (precision == Precision::Real) {
                return getRealCoding();
            }   else return "sfixed";
        }

        string getRealCoding() {
            return globalCodingFloat() ? "float" : "sfixed";
        }

        string getMSB(const Precision& precision)
        {
            return (precision == Precision::Real) ? " msb " : to_string(31);
        }

        string getFloatMSB(const Precision& precision)
        {
            return (precision == Precision::Real) ? ((globalCodingFloat()) ? "" : " msb ") : to_string(31);
        }

        string getFloatLSB(const Precision& precision)
        {
            return (precision == Precision::Real) ? ((globalCodingFloat()) ? "" : " lsb ") : to_string(0);
        }

        string getLSB(const Precision& precision)
        {
            return (precision == Precision::Real) ? " lsb " : to_string(0);
        }

        string getRange(const Precision& precision)
        {
            return "(" + getMSB(precision) + " downto " + getLSB(precision) + ")";
        }

        int getHigh(const Precision& precision)
        {
            return (precision == Precision::Real) ? HIGH : 31;
        }

        int getLow(const Precision& precision)
        {
            return (precision == Precision::Real) ? LOW : 0;
        }

    public:
        Signal2VHDLVisitor(old_OccMarkup* occ_markup) : SignalVisitor(), fOccMarkup(occ_markup) {};

        void sigToVHDL(Tree sig, ostream& fout);

    protected:
        void visit(Tree sig) override;
};

// Public API
void sigVHDLFile(old_OccMarkup* markup, Tree L, bool trace);
