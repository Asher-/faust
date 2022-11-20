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

#include <climits>
#include <iostream>
#include <sstream>

#include "compiler/errors/exception.hh"
#include "global.hh"
#include "tlib/property.hh"
#include "compiler/signals/sigtype.hh"
#include "tlib/tree.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

using namespace std;

using Availability = ::Faust::Primitive::Type::Availability;
using Precision = ::Faust::Primitive::Type::Precision;
using Priority = ::Faust::Primitive::Type::Priority;
using Value = ::Faust::Primitive::Type::Value;
using Vectorability = ::Faust::Primitive::Type::Vectorability;

// Uncomment to activate type inferrence tracing
//#define TRACE(x) x

#define TRACE(x) \
    {            \
        ;        \
    }

AudioType::AudioType(
  Precision      precision,
  Priority       priority,
  Availability   availability,
  Vectorability  vectorability,
  Value          value_type,
  ::interval     interval,
  res            resolution
)
:
  _precision(precision),
  _priority(priority),
  _availability(availability),
  _vectorability(vectorability),
  _valueType(value_type),
  _interval(interval),
  _resolution(resolution),
  _code(0)
{
    TRACE(cerr << global::config().TABBER << "Building audioType : n="
               << "NR"[precision] << ", v="
               << "KB?S"[priority] << ", c="
               << "CI?E"[availability] << ", vec="
               << "VS?TS"[vectorability] << ", b="
               << "N?B"[value_type] << ", i=" << i << endl);
}  ///< constructs an abstract audio type

///< true when type is maximal (and therefore can't change depending of hypothesis)
bool SimpleType::isMaximal() const
{
    return (_precision == Precision::Real)
        && (_priority == Priority::Samp)
        && (_availability == Availability::Exec);
}

//------------------------------------------------------------------------------------
//
//		Overloading << printing operator
//
//------------------------------------------------------------------------------------

ostream& operator<<(ostream& dst, const Type& t)
{
    return t->print(dst);
}

ostream& operator<<(ostream& dst, const SimpleType& t)
{
    return t.print(dst);
}

ostream& operator<<(ostream& dst, const TableType& t)
{
    return t.print(dst);
}

ostream& operator<<(ostream& dst, const TupletType& t)
{
    return t.print(dst);
}

//------------------------------------------------------------------------------------
//
//		Print method definition
//
//------------------------------------------------------------------------------------

/**
 * Print the content of a simple type on a stream
 */
ostream& SimpleType::print(ostream& dst) const
{
    return dst << "NR"[static_cast<unsigned int>(precision())]
               << "KB?S"[static_cast<unsigned int>(priority())]
               << "CI?E"[static_cast<unsigned int>(availability())]
               << "VS?TS"[static_cast<unsigned int>(vectorability())]
               << "N?B"[static_cast<unsigned int>(valueType())]
               << " " << _interval;
}

/**
 * Print the content of a table type on a stream
 */
ostream& TableType::print(ostream& dst) const
{
    dst << "NR"[static_cast<unsigned int>(precision())]
        << "KB?S"[static_cast<unsigned int>(priority())]
        << "CI?E"[static_cast<unsigned int>(availability())]
        << "VS?TS"[static_cast<unsigned int>(vectorability())]
        << "N?B"[static_cast<unsigned int>(valueType())]
        << " " << _interval
        << ":Table(";
    _content->print(dst);
    return dst << ')';
}

/**
 *  True when type is maximal (and therefore can't change depending of hypothesis)
 */
bool TableType::isMaximal() const
{
    return (_precision == Precision::Real) && (_priority == Priority::Samp) && (_availability == Availability::Exec);
}

/**
 * Print the content of a tuplet of types on a stream
 */
ostream& TupletType::print(ostream& dst) const
{
    dst << "KB?S"[static_cast<unsigned int>(priority())] << "CI?E"[static_cast<unsigned int>(availability())] << " " << _interval << " : {";
    string sep = "";
    for (unsigned int i = 0; i < _components.size(); i++, sep = "*") {
        dst << sep;
        _components[i]->print(dst);
    }
    dst << '}';
    return dst;
}

/**
 *  True when type is maximal (and therefore can't change depending of hypothesis)
 */
bool TupletType::isMaximal() const
{
    for (unsigned int i = 0; i < _components.size(); i++) {
        if (!_components[i]->isMaximal()) return false;
    }
    return true;
}

//------------------------------------------------------------------------------------
//
//		Types constructions
// 		t := p, table(t), t|t, t*t
//
//------------------------------------------------------------------------------------

Type operator|(const Type& t1, const Type& t2)
{
    SimpleType *st1, *st2;
    TableType * tt1, *tt2;
    TupletType *nt1, *nt2;

    if ((st1 = isSimpleType(t1)) && (st2 = isSimpleType(t2))) {
        return makeSimpleType(
          Precision( static_cast<unsigned int>(st1->precision())
          | static_cast<unsigned int>(st2->precision())),
          Priority( static_cast<unsigned int>(st1->priority())
          | static_cast<unsigned int>(st2->priority())),
          Availability( static_cast<unsigned int>(st1->availability())
          | static_cast<unsigned int>(st2->availability())),
          Vectorability( static_cast<unsigned int>(st1->vectorability())
          | static_cast<unsigned int>(st2->vectorability())),
          Value( static_cast<unsigned int>(st1->valueType())
          | static_cast<unsigned int>(st2->valueType())),
          reunion(st1->interval(),
          st2->interval())
        );

    } else if ((tt1 = isTableType(t1)) && (tt2 = isTableType(t2))) {
        return makeTableType(tt1->content() | tt2->content());

    } else if ((nt1 = isTupletType(t1)) && (nt2 = isTupletType(t2))) {
        vector<Type> v;
        int          n = (int)min(nt1->arity(), nt2->arity());
        for (int i = 0; i < n; i++) {
            v.push_back((*nt1)[i] | (*nt2)[i]);
        }
        return new TupletType(v);

    } else {
        stringstream error;
        error << "ERROR : trying to combine incompatible types, " << t1 << " and " << t2 << endl;
        throw faustexception(error.str());
    }
}

bool operator==(const Type& t1, const Type& t2)
{
    SimpleType *st1, *st2;
    TableType * tt1, *tt2;
    TupletType *nt1, *nt2;

    if (t1->priority() != t2->priority()) return false;
    if (t1->availability() != t2->availability()) return false;

    if ((st1 = isSimpleType(t1)) && (st2 = isSimpleType(t2)))
        return (st1->precision() == st2->precision()) && (st1->priority() == st2->priority()) &&
               (st1->availability() == st2->availability()) && (st1->vectorability() == st2->vectorability()) &&
               (st1->valueType() == st2->valueType()) && (st1->interval().lo == st2->interval().lo) &&
               (st1->interval().hi == st2->interval().hi) &&
               (st1->interval().valid == st2->interval().valid) && st1->resolution().valid == st2->resolution().valid &&
               st1->resolution().index == st2->resolution().index;
    if ((tt1 = isTableType(t1)) && (tt2 = isTableType(t2))) return tt1->content() == tt2->content();
    if ((nt1 = isTupletType(t1)) && (nt2 = isTupletType(t2))) {
        int a1 = nt1->arity();
        int a2 = nt2->arity();
        if (a1 == a2) {
            for (int i = 0; i < a1; i++) {
                if ((*nt1)[i] != (*nt2)[i]) return false;
            }
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool operator<=(const Type& t1, const Type& t2)
{
    return (t1 | t2) == t2;
}

Type operator*(const Type& t1, const Type& t2)
{
    vector<Type> v;

    TupletType* nt1 = dynamic_cast<TupletType*>((AudioType*)t1);
    TupletType* nt2 = dynamic_cast<TupletType*>((AudioType*)t2);

    if (nt1) {
        for (std::size_t i = 0; i < nt1->arity(); i++) {
            v.push_back((*nt1)[i]);
        }
    } else {
        v.push_back(t1);
    }

    if (nt2) {
        for (std::size_t i = 0; i < nt2->arity(); i++) {
            v.push_back((*nt2)[i]);
        }
    } else {
        v.push_back(t2);
    }
    return new TupletType(v);
}

SimpleType* isSimpleType(AudioType* t)
{
    return dynamic_cast<SimpleType*>(t);
}
TableType* isTableType(AudioType* t)
{
    return dynamic_cast<TableType*>(t);
}
TupletType* isTupletType(AudioType* t)
{
    return dynamic_cast<TupletType*>(t);
}

//--------------------------------------------------
// Type checking

Type checkInt(Type t)
{
    // check that t is an integer
    SimpleType* st = isSimpleType(t);
    if (st == nullptr || st->precision() > Precision::Int) {
        stringstream error;
        error << "ERROR : checkInt failed for type " << t << endl;
        throw faustexception(error.str());
    }
    return t;
}

Type checkKonst(Type t)
{
    // check that t is a constant
    if (t->priority() > Priority::Konst) {
        stringstream error;
        error << "ERROR : checkKonst failed for type " << t << endl;
        throw faustexception(error.str());
    }
    return t;
}

Type checkInit(Type t)
{
    // check that t is a known at init time
    if (t->availability() > Availability::Init) {
        stringstream error;
        error << "ERROR : checkInit failed for type " << t << endl;
        throw faustexception(error.str());
    }
    return t;
}

Type checkIntParam(Type t)
{
    return checkInit(checkKonst(checkInt(t)));
}

Type checkWRTbl(Type tbl, Type wr)
{
    // check that wr is compatible with tbl content
    if (wr->precision() > tbl->precision()) {
        stringstream error;
        error << "ERROR : checkWRTbl failed, the content of " << tbl << " is incompatible with " << wr << endl;
        throw faustexception(error.str());
    }
    return tbl;
}

/**
    \brief Check is a type is appropriate for a delay.
    @return an exception if not appropriate, mxd (max delay) if appropriate

 */
int checkDelayInterval(Type t)
{
    interval i = t->interval();
    if (i.valid && i.lo >= 0 && i.hi < INT_MAX) {
        return int(i.hi + 0.5);
    } else {
        stringstream error;
        error << "ERROR : invalid delay parameter range: " << i << ". The range must be between 0 and INT_MAX" << endl;
        throw faustexception(error.str());
    }
}

/*****************************************************************************
 *
 *      codeAudioType(Type) -> Tree
 *      Code an audio type as a tree in order to benefit of memoization
 *
 *****************************************************************************/

static Tree codeSimpleType(SimpleType* st);
static Tree codeTableType(TableType* st);
static Tree codeTupletType(TupletType* st);

/**
 * codeAudioType(Type) -> Tree
 * Code an audio type as a tree in order to benefit of memoization
 * The type field (of the coded type) is used to store the audio
 * type
 */
Tree codeAudioType(AudioType* t)
{
    SimpleType* st;
    TableType*  tt;
    TupletType* nt;

    Tree r;

    if ((r = t->code())) return r;

    if ((st = isSimpleType(t))) {
        r = codeSimpleType(st);
    } else if ((tt = isTableType(t))) {
        r = codeTableType(tt);
    } else if ((nt = isTupletType(t))) {
        r = codeTupletType(nt);
    } else {
        stringstream error;
        error << "ERROR : codeAudioType(), invalid pointer " << t << endl;
        throw faustexception(error.str());
    }

    r->setType(t);
    return r;
}

/**
 * Code a simple audio type as a tree in order to benefit of memoization
 */
static Tree codeSimpleType(SimpleType* st)
{
    vector<Tree> elems;
    elems.push_back(tree(static_cast<int>( st->precision())) );
    elems.push_back(tree(static_cast<int>( st->priority())) );
    elems.push_back(tree(static_cast<int>( st->availability())) );
    elems.push_back(tree(static_cast<int>( st->vectorability())) );
    elems.push_back(tree(static_cast<int>( st->valueType())) );

    elems.push_back(tree(st->interval().valid));
    elems.push_back(tree(st->interval().lo));
    elems.push_back(tree(st->interval().hi));

    elems.push_back(tree(st->resolution().valid));
    elems.push_back(tree(st->resolution().index));
    return CTree::make(::Faust::Primitive::Symbols::internal().symbol("SimpleType"), elems);
}

AudioType* makeSimpleType(
  Precision       precision,
  Priority        priority,
  Availability    availability,
  Vectorability   vectorability,
  Value           value_type,
  const interval& i
) {
    return makeSimpleType(
      precision,
      priority,
      availability,
      vectorability,
      value_type,
      i,
      global::config().RES
    );
}

AudioType* makeSimpleType(
  Precision       precision,
  Priority        priority,
  Availability    availability,
  Vectorability   vectorability,
  Value           value_type,
  const interval& i,
  const res&      resolution
) {
    SimpleType prototype(
      precision,
      priority,
      availability,
      vectorability,
      value_type,
      i,
      resolution
    );
    Tree code = codeAudioType( & prototype );

    AudioType* t;
    if ( global::config().gMemoizedTypes->get(code, t) ) {
        return t;
    }
    else {
        global::config().gAllocationCount++;
        t = new SimpleType(
          precision,
          priority,
          availability,
          vectorability,
          value_type,
          i,
          resolution
        );
        global::config().gMemoizedTypes->set(code, t);
        t->setCode(code);
        return t;
    }
}

/**
 * Code a table type as a tree in order to benefit of memoization
 */
static Tree codeTableType(TableType* tt)
{
    vector<Tree> elems;
    elems.push_back(tree(static_cast<int>( tt->precision())) );
    elems.push_back(tree(static_cast<int>( tt->priority())) );
    elems.push_back(tree(static_cast<int>( tt->availability())) );
    elems.push_back(tree(static_cast<int>( tt->vectorability())) );
    elems.push_back(tree(static_cast<int>( tt->valueType())) );

    elems.push_back(tree(tt->interval().valid));
    elems.push_back(tree(tt->interval().lo));
    elems.push_back(tree(tt->interval().hi));

    elems.push_back(tree(tt->resolution().valid));
    elems.push_back(tree(tt->resolution().index));

    return CTree::make(::Faust::Primitive::Symbols::internal().symbol("TableType"), elems);
}

AudioType* makeTableType(const Type& ct)
{
    TableType prototype(ct);
    Tree      code = codeAudioType(&prototype);

    AudioType* tt;
    if (global::config().gMemoizedTypes->get(code, tt)) {
        return tt;
    } else {
        global::config().gAllocationCount++;
        tt = new TableType(prototype);
        global::config().gMemoizedTypes->set(code, tt);
        tt->setCode(code);
        return tt;
    }
}

AudioType* makeTableType(
  const Type&     ct,
  Precision       precision,
  Priority        priority,
  Availability    availability,
  Vectorability   vectorability,
  Value           value_type,
  const interval& i
)
{
    TableType prototype(
      ct,
      precision,
      priority,
      availability,
      vectorability,
      value_type,
      i
    );
    Tree code = codeAudioType( & prototype );

    AudioType* tt;
    if (global::config().gMemoizedTypes->get(code, tt)) {
        return tt;
    } else {
        global::config().gAllocationCount++;
        tt = new TableType(
          ct,
          precision,
          priority,
          availability,
          vectorability,
          value_type,
          i
        );
        global::config().gMemoizedTypes->set(code, tt);
        tt->setCode(code);
        return tt;
    }
}

/**
 * Code a tuplet type as a tree in order to benefit of memoization
 */
static Tree codeTupletType(TupletType* nt)
{
    std::vector<Tree> elems;
    for (std::size_t i = 0; i < nt->arity(); i++) {
        elems.push_back(codeAudioType((*nt)[i]));
    }
    return CTree::make(::Faust::Primitive::Symbols::internal().symbol("TupletType"), elems);
}

AudioType* makeTupletType(ConstTypes vt)
{
    TupletType prototype(vt);
    Tree       code = codeAudioType(&prototype);

    AudioType* t;
    if (global::config().gMemoizedTypes->get(code, t)) {
        return t;
    } else {
        global::config().gAllocationCount++;
        t = new TupletType(vt);
        global::config().gMemoizedTypes->set(code, t);
        t->setCode(code);
        return t;
    }
}

AudioType* makeTupletType(
  ConstTypes      vt,
  Precision       precision,
  Priority        priority,
  Availability    availability,
  Vectorability   vectorability,
  Value           value_type,
  const interval& i
) {
    TupletType prototype(
      vt,
      precision,
      priority,
      availability,
      vectorability,
      value_type,
      i
    );
    Tree       code = codeAudioType(&prototype);

    AudioType* t;
    if (global::config().gMemoizedTypes->get(code, t)) {
        return t;
    } else {
        global::config().gAllocationCount++;
        t = new TupletType(
          vt,
          precision,
          priority,
          availability,
          vectorability,
          value_type,
          i
        );
        global::config().gMemoizedTypes->set(code, t);
        t->setCode(code);
        return t;
    }
}
