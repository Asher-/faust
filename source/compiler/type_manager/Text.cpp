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

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "compiler/type_manager/Text.hh"
#include "tlib/compatibility.hh"
#include "compiler/types/floats.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

#include "compiler/parser/implementation.hh"

using namespace std;

static std::string substitution(const std::string& model, const vector<std::string>& args)
{
    char   c;
    int    i = 0, ilast = (int)model.length() - 1;
    string result;
    while (i < ilast) {
        c = model[i++];
        if (c != '$') {
            result += c;
        } else {
            c = model[i++];
            if (c >= '0' && c <= '9') {
                result += args[c - '0'];
            } else {
                result += c;
            }
        }
    }
    if (i == ilast) result += model[i];
    return result;
}

/**
 * Text substitution. Creates a string by replacing all the $n
 * occurences in the model string, with the corresponding arguments.
 * Example : subst("float $0 = $1;", "var", T(10.2))
 */
string subst(const std::string& model, const vector<std::string>& args)
{
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0)
{
    vector<std::string> args(10);
    args[0] = a0;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1, const std::string& a2)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1, const std::string& a2, const std::string& a3)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1, const std::string& a2, const std::string& a3,
             const std::string& a4)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = a4;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1, const std::string& a2, const std::string& a3,
             const std::string& a4, const std::string& a5)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = a4;
    args[5] = a5;
    return substitution(model, args);
}

string subst(const std::string& model, const std::string& a0, const std::string& a1, const std::string& a2, const std::string& a3,
             const std::string& a4, const std::string& a5, const std::string& a6)
{
    vector<std::string> args(10);
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = a4;
    args[5] = a5;
    args[6] = a6;
    return substitution(model, args);
}

string T(char* c)
{
    return string(c);
}

string T(int n)
{
    char c[64];
    snprintf(c, 63, "%d", n);
    return string(c);
}

string T(long n)
{
    char c[64];
    snprintf(c, 63, "%ld", n);
    return string(c);
}

/**
 * If needed add a trailing '.0' to the
 * the textual representation of a floating point number
 * to avoid confusions with an int.
 */
static std::string ensureFloat(const std::string& c)
{
    bool isInt = true;
    for (size_t i = 0; i < c.size(); i++) {
        if ((c[i] == '.') || (c[i] == 'e')) {
            isInt = false;
            break;
        }
    }
    return (isInt) ? (c + ".0") : c;
}

/**
 * Special encoding for Julia float numbers, see:
 * https://docs.julialang.org/en/v1/manual/integers-and-floating-point-numbers/#Floating-Point-Numbers
 */
static std::string encodeJuliaFloat(const std::string& c, bool& need_suffix)
{
    bool isInt = true;
    string res;
    for (size_t i = 0; i < c.size(); i++) {
        if ((c[i] == '.') || (c[i] == 'e')) {
            isInt = false;
        }
        if (c[i] == 'e') {
            res += 'f';
            need_suffix = false;
        } else {
            res += c[i];
        }
    }
    return (isInt) ? (res + ".0") : res;
}

static std::string addSuffix(const std::string& num)
{
    if (gOutputLang() == "julia") {
        bool need_suffix = true;
        string res = encodeJuliaFloat(num, need_suffix);
        return (need_suffix) ? (res + inumix()) : res;
    } else {
        return ensureFloat(num) + inumix();
    }
}

/**
 * Convert a single-precision float into a string.
 * Adjusts the precision p to the needs.
 */
string TAux(float n)
{
    char c[512];
    int  p = 1;
    
    do { snprintf(c, 512, "%.*g", p++, n); } while (strtof(c, 0) != n);
    
    ensureFloat(c);
    return string(c);
}

string T(float n) { return addSuffix(TAux(n)); }

/**
* Convert a double-precision float into a string.
* Adjusts the precision p to the needs.
*/
string TAux(double n)
{
    char  c[512];
    char* endp;
    int   p = 1;
    
    if (::Faust::Primitive::Math::floatSize == 1) {
        float v = (float)n;
        do { snprintf(c, 512, "%.*g", p++, v); endp = nullptr; } while (strtof(c, &endp) != v);
    } else if (::Faust::Primitive::Math::floatSize == 2) {
        do { snprintf(c, 512, "%.*g", p++, n); endp = nullptr; } while (strtod(c, &endp) != n);
    } if (::Faust::Primitive::Math::floatSize == 3) {
        long double q = (long double)n;
        do { snprintf(c, 512, "%.*Lg", p++, q); endp = nullptr; } while (strtold(c, &endp) != q);
    } else if (global::config().gFloatSize == 4) {
        do { snprintf(c, 512, "%.*g", p++, n); endp = nullptr; } while (strtod(c, &endp) != n);
    } else {
        faustassert(false);
    }
    
    ensureFloat(c);
    return string(c);
}

string T(double n) { return addSuffix(TAux(n)); }

/**
 * remove quotes from a string
 */
string unquote(const std::string& str)
{
    return (str[0] == '"') ? str.substr(1, str.size() - 2) : str;
}

/**
 * add quotes to a string
 */
string quote(const std::string& s)
{
    return "\"" + s + "\"";
}

/**
 * Print n tabs (for indentation purpose)
 * @param n number of tabs to print
 * @param fout output stream
 */
void tab(int n, ostream& fout)
{
    fout << '\n';
    while (n--) fout << '\t';
}

void back(int n, ostream& fout)
{
    long pos = fout.tellp();
    fout.seekp(pos-n);
}

/**
 * Print a list of lines
 * @param n number of tabs of indentation
 * @param lines list of lines to be printed
 * @param fout output stream
 */
void printlines(int n, list<std::string>& lines, ostream& fout, const std::string& sep)
{
    list<std::string>::const_iterator s;
    for (s = lines.begin(); s != lines.end(); s++) {
        if (s == lines.begin()) {
            tab(n, fout);
            fout << *s;  // No separator before first one
        } else {
            tab(n, fout);
            fout << sep << *s;
        }
    }
}

/**
 * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
 * (but not those in the middle of the string)
 */

string rmWhiteSpaces(const std::string& s)
{
    size_t i = s.find_first_not_of(" \t");
    size_t j = s.find_last_not_of(" \t");
    if ((i != string::npos) & (j != string::npos)) {
        return s.substr(i, 1 + j - i);
    } else {
        return "";
    }
}

// 'Quad' (= long double) are currectly treated like 'double'

string checkReal(double val)
{
    return (strcmp(ifloat(), "float") == 0) ? checkFloat(float(val)) : checkDouble(val);
}

string indent(const std::string& str, int tabs)
{
    stringstream instream(str);
    stringstream outstream;
    string       line;
    while (getline(instream, line, '\n')) {
        for (int i = 0; i != tabs; ++i) {
            outstream << '\t';
        }
        outstream << line << endl;
    }
    return outstream.str();
}

string replaceChar(string str, char src, char dst)
{
    replace(str.begin(), str.end(), src, dst);
    return str;
}

string replaceCharList(const std::string& str, const vector<char>& ch1, char ch2)
{
    auto beg = ch1.begin();
    auto end = ch1.end();
    string res = str;
    for (size_t i = 0; i < str.length(); ++i) {
        if (std::find(beg, end, str[i]) != end) res[i] = ch2;
    }
    return res;
}

vector<std::string> tokenizeString(const std::string& str, char sep)
{
    vector<std::string> res;
    istringstream is(str);
    string token;
    while (getline(is, token, sep)) res.push_back(token);
    return res;
}
    
