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

#ifndef _SigType_
#define _SigType_

#include <iostream>
#include <string>
#include <vector>
#include "compiler/type_manager/garbageable.hh"
#include "compiler/signals/interval.hh"
#include "tlib/smartpointer.hh"
#include "tlib/smartable.hh"
#include "tlib/tree.hh"

#include "faust/primitive/type/availability.hh"
#include "faust/primitive/type/precision.hh"
#include "faust/primitive/type/priority.hh"
#include "faust/primitive/type/value.hh"
#include "faust/primitive/type/vectorability.hh"

/*********************************************************************
 *
 *						Type System for FAUST
 *
 *	<type> 			::= <simpletype> ||  table(<type>)
 *			 		 	||  <type>|<type>  || <type>*<type>
 *	<simpletype>	::= <nature><variability><computability><vectorability>||<boolean>
 *	<nature>		::= TINT || TREAL
 *	<variability>	::= TKONST || TBLOCK || TSAMP
 *	<computability>	::= TCOMP  || TINIT  || TEXEC
 *	<vectorability> ::= KVECT  || KSCAL  || KTRUESCAL
 *	<boolean>       ::= KNUM   || KBOOL
 *
 **********************************************************************/

/*---------------------------------------------------------------------

    AbstractType :
    The root class for SimpleType, TableType and TupletType

    Type :
    A smartPointer to type

----------------------------------------------------------------------*/

using namespace std;

class AudioType;

typedef smartptr<AudioType> Type;
typedef const vector<Type>& ConstTypes;

/**
 * The Root class for all audio data types.
 * All audio types have a "variability" (how fast the values change) and
 * a "computability" (when the values are available). Simple types have
 * also a "nature" (integer or floating point).
 */

class AudioType : public virtual Garbageable, public virtual smartable {

   protected:

    using Availability = ::Faust::Primitive::Type::Availability;
    using Precision = ::Faust::Primitive::Type::Precision;
    using Priority = ::Faust::Primitive::Type::Priority;
    using Value = ::Faust::Primitive::Type::Value;
    using Vectorability = ::Faust::Primitive::Type::Vectorability;

    Precision     _precision;     ///< the kind of data represented
    Priority      _priority;      ///< how fast values change
    Availability  _availability;  ///< when are values available
    Vectorability    _vectorability;    ///< when a signal can be vectorized
    Value         _valueType;     ///< when a signal stands for a boolean value
    ::interval    _interval;      ///< Minimal and maximal values the signal can take
    res           _resolution;    ///< Resolution (fixed-point)
    Tree          _code;          ///< Tree representation (for memoization purposes)

   public:
    AudioType(
      Precision     precision,
      Priority      priority,
      Availability  availability,
      Vectorability    vectorability     = Vectorability::Vect,
      Value         value_type     = Value::Num,
      ::interval    interval       = ::interval(),
      res           resolution     = res()
    );
    virtual ~AudioType() {}  ///< not really useful here, but make compiler happier

    Precision precision() const { return _precision; }  ///< returns the kind of values (integre or floating point)
    Priority priority() const
    {
        return _priority;
    }  ///< returns how fast values change (constant, by blocks, by samples)
    Availability availability() const
    {
        return _availability;
    }  ///< returns when values are available (compilation, initialisation, execution)
    Vectorability vectorability() const { return _vectorability; }  ///< returns when a signal can be vectorized
    Value valueType() const { return _valueType; }              ///< returns when a signal stands for a boolean value

    ::interval interval() const { return _interval; }  ///< returns the interval (min dn max values) of a signal
    res      resolution() const { return _resolution; }            ///< return the resolution of the signal (fixed)

    void setCode(Tree code) { _code = code; }  ///< returns the interval (min dn max values) of a signal
    Tree code() { return _code; }           ///< returns the interval (min dn max values) of a signal

    virtual AudioType* promotePrecision( const Precision& )               = 0;  ///< promote the nature of a type
    virtual AudioType* promotePriority( const Priority& )          = 0;  ///< promote the variability of a type
    virtual AudioType* promoteAvailability( const Availability& )        = 0;  ///< promote the computability of a type
    virtual AudioType* promoteVectorability( const Vectorability& )        = 0;  ///< promote the vectorability of a type
    virtual AudioType* promoteValueType( const Value& )              = 0;  ///< promote the booleanity of a type
    virtual AudioType* promoteInterval(const ::interval& i) = 0;  ///< promote the interval of a type

    virtual ostream& print(ostream& dst) const = 0;  ///< print nicely a type
    ///< true when type is maximal (and therefore can't change depending of hypothesis)
    virtual bool isMaximal() const = 0;

   protected:
    void setInterval(const ::interval& r) { _interval = r; }
};

// printing
inline ostream& operator<<(ostream& s, const AudioType& n)
{
    return n.print(s);
}

/**
 * Return the nature of a vector of types.
 */
inline ::Faust::Primitive::Type::Precision
mergePrecision(ConstTypes v)
{
    int r = 0;
    for (std::size_t i = 0; i < v.size(); i++) r |= static_cast<int>(v[i]->precision());
    return ::Faust::Primitive::Type::Precision(r);
}

/**
 * Return the variability of a vector of types.
 */
inline ::Faust::Primitive::Type::Priority
mergePriority(ConstTypes v)
{
    int r = 0;
    for (std::size_t i = 0; i < v.size(); i++) r |= static_cast<int>(v[i]->priority());
    return ::Faust::Primitive::Type::Priority(r);
}

/**
 * Return the computability of a vector of types.
 */
inline ::Faust::Primitive::Type::Availability
mergeAvailability(ConstTypes v)
{
    int r = 0;
    for (std::size_t i = 0; i < v.size(); i++) r |= static_cast<int>(v[i]->availability());
    return ::Faust::Primitive::Type::Availability(r);
}

/**
 * Return the vectorability of a vector of types.
 */
inline ::Faust::Primitive::Type::Vectorability
mergeVectorability(ConstTypes v)
{
    int r = 0;
    for (std::size_t i = 0; i < v.size(); i++) r |= static_cast<int>(v[i]->vectorability());
    return ::Faust::Primitive::Type::Vectorability(r);
}

/**
 * Return the booleanity of a vector of types.
 */
inline ::Faust::Primitive::Type::Value
mergeValueType(ConstTypes v)
{
    int r = 0;
    for (std::size_t i = 0; i < v.size(); i++) r |= static_cast<int>(v[i]->valueType());
    return ::Faust::Primitive::Type::Value(r);
}

/**
 * Return the interval of a vector of types.
 */
inline interval mergeinterval(ConstTypes v)
{
    if (v.size() == 0) {
        return interval();
    } else {
        double lo = 0, hi = 0;
        for (unsigned int i = 0; i < v.size(); i++) {
            interval r = v[i]->interval();
            if (!r.valid) return r;
            if (i == 0) {
                lo = r.lo;
                hi = r.hi;
            } else {
                lo = min(lo, r.lo);
                hi = max(hi, r.hi);
            }
        }
        return interval(lo, hi);
    }
}

AudioType* makeSimpleType(
  ::Faust::Primitive::Type::Precision       precision,
  ::Faust::Primitive::Type::Priority        priority,
  ::Faust::Primitive::Type::Availability    availability,
  ::Faust::Primitive::Type::Vectorability   vectorability,
  ::Faust::Primitive::Type::Value           value_type,
  const interval& i
);
AudioType* makeSimpleType(
  ::Faust::Primitive::Type::Precision       precision,
  ::Faust::Primitive::Type::Priority        priority,
  ::Faust::Primitive::Type::Availability    availability,
  ::Faust::Primitive::Type::Vectorability   vectorability,
  ::Faust::Primitive::Type::Value           value_type,
  const interval& i,
  const res& lsb
);
// didn't use a default arg, would have created a cyclic dependancy with global.hh

AudioType* makeTableType(const Type& ct);
AudioType* makeTableType(
  const Type&     t,
  ::Faust::Primitive::Type::Precision       precision,
  ::Faust::Primitive::Type::Priority        priority,
  ::Faust::Primitive::Type::Availability    availability,
  ::Faust::Primitive::Type::Vectorability   vectorability,
  ::Faust::Primitive::Type::Value           value_type,
  const interval& i
);

AudioType* makeTupletType(ConstTypes vt);
AudioType* makeTupletType(
  ConstTypes      vt,
  ::Faust::Primitive::Type::Precision       precision,
  ::Faust::Primitive::Type::Priority        priority,
  ::Faust::Primitive::Type::Availability    availability,
  ::Faust::Primitive::Type::Vectorability   vectorability,
  ::Faust::Primitive::Type::Value           value_type,
  const interval& i
);

/**
 * The type of a simple numeric audio signal.
 * Beside a computability and a variability, SimpleTypes have
 * a "nature" indicating if they represent an integer or floating
 * point audio signals.
 */
class SimpleType : public AudioType {
  protected:
  
    using Availability = ::Faust::Primitive::Type::Availability;
    using Precision = ::Faust::Primitive::Type::Precision;
    using Priority = ::Faust::Primitive::Type::Priority;
    using Value = ::Faust::Primitive::Type::Value;
    using Vectorability = ::Faust::Primitive::Type::Vectorability;
  
  public:
    SimpleType(
      ::Faust::Primitive::Type::Precision          precision,
      ::Faust::Primitive::Type::Priority           priority,
      ::Faust::Primitive::Type::Availability       availability,
      ::Faust::Primitive::Type::Vectorability      vectorability  = Vectorability::Vect,
      ::Faust::Primitive::Type::Value              value_type     = Value::Num,
      const ::interval&  interval       = ::interval(),
      const res&         resolution     = res()
    )
    :
      AudioType(
        precision,
        priority,
        availability,
        vectorability,
        value_type,
        interval,
        resolution
      )
    {
        // cerr << "new simple type " << i << " -> " << *this << endl;
    }  ///< constructs a SimpleType from a nature a variability and a computability

    virtual ostream& print(ostream& dst) const override;  ///< print a SimpleType

    AudioType* promotePrecision( const Precision& precision )
    override
    {
        return makeSimpleType(
          Precision( static_cast<unsigned int>(_precision) | static_cast<unsigned int>(precision) ),
          _priority,
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the nature of a type
    AudioType* promotePriority( const Priority& priority )
    override
    {
        return makeSimpleType(
          _precision,
          Priority( static_cast<unsigned int>(_priority) | static_cast<unsigned int>(priority) ),
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the variability of a type
    AudioType* promoteAvailability( const Availability& availability )
    override
    {
        return makeSimpleType(
          _precision,
          _priority,
          Availability( static_cast<unsigned int>(_availability) | static_cast<unsigned int>(availability) ),
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the computability of a type
    AudioType* promoteVectorability( const Vectorability& vectorability )
    override
    {
        return makeSimpleType(
          _precision,
          _priority,
          _availability,
          Vectorability( static_cast<unsigned int>(_vectorability) | static_cast<unsigned int>(vectorability) ),
          _valueType,
          _interval
        );
    }  ///< promote the vectorability of a type
    AudioType* promoteValueType( const Value& value_type )
    override
    {
        return makeSimpleType(
          _precision,
          _priority,
          _availability,
          _vectorability,
          Value( static_cast<unsigned int>(_valueType) | static_cast<unsigned int>(value_type) ),
          _interval
        );
    }  ///< promote the booleanity of a type
    AudioType* promoteInterval(const ::interval& i)
    override
    {
        // cerr << "promote to Interval " << i << endl;
        // cerr << "for type : " << *this << endl;
        Type t = makeSimpleType(
          _precision,
          _priority,
          _availability,
          _vectorability,
          _valueType,
          i
        );  ///< promote the interval of a type
        // cerr << "gives type " << *t << endl;
        return t;
    }
    bool isMaximal() const override;  ///< true when type is maximal (and therefore can't change depending of hypothesis)

    void addReference()
    override
    {
        smartable::addReference();
    }

    void removeReference()
    override
    {
        smartable::removeReference();
    }

};

inline Type intCast(Type t)
{
    interval I = t->getInterval();
    I.lo = std::isinf(I.lo) ? I.lo : int(I.lo);
    I.hi = std::isinf(I.hi) ? I.hi : int(I.hi);
    return makeSimpleType(kInt, t->variability(), t->computability(), t->vectorability(), t->boolean(), I);
}

inline Type floatCast(Type t)
{
    return makeSimpleType(kReal, t->variability(), t->computability(), t->vectorability(), t->boolean(),
                          t->getInterval());
}
inline Type sampCast(Type t)
{
    return makeSimpleType(t->nature(), kSamp, t->computability(), t->vectorability(), t->boolean(), t->getInterval());
}
inline Type boolCast(Type t)
{
    return makeSimpleType(kInt, t->variability(), t->computability(), t->vectorability(), kBool, t->getInterval());
}
inline Type numCast(Type t)
{
    return makeSimpleType(t->nature(), t->variability(), t->computability(), t->vectorability(), kNum,
                          t->getInterval());
}
inline Type vecCast(Type t)
{
    return makeSimpleType(t->nature(), t->variability(), t->computability(), kVect, t->boolean(), t->getInterval());
}
inline Type scalCast(Type t)
{
    return makeSimpleType(t->nature(), t->variability(), t->computability(), kScal, t->boolean(), t->getInterval());
}
inline Type truescalCast(Type t)
{
    return makeSimpleType(t->nature(), t->variability(), t->computability(), kTrueScal, t->boolean(), t->getInterval());
}

inline Type castInterval(Type t, const interval& i)
{
    return makeSimpleType(t->nature(), t->variability(), t->computability(), t->vectorability(), t->boolean(), i);
}

/**
 * The type of a table of audio data.
 * Beside a computability and a variability, TableTypes have
 * a "content" indicating the type of the data stored in the table.
 */
class TableType : public AudioType {
   protected:
    const Type _content;  ///< type of that data stored in the table

   public:
    TableType(const Type& t)
    :
      AudioType(
        t->precision(),
        Priority::Konst,
        Availability::Init,
        Vectorability::Vect,
        t->valueType(),
        t->interval()
      ),
      _content(t)
    {
    }  ///< construct a TableType with a content of a type t
#if 0
	TableType(
    const Type&  t,
    Priority     priority,
    Availability availability
  ) :
    AudioType(
      t->precision(),
      t->priority() | priority,
      t->availability() | availability,
      t->vectorability(),
      t->valueType()
    ),
    _content(t) {}		///< construct a TableType with a content of a type t, promoting variability and computability

	TableType(
    const Type&  t,
    Precision    precision,
    Priority     priority,
    Availability availability
  ) :
    AudioType(
      t->precision() | precision,
      t->priority() | priority,
      t->availability() | availability,
      t->vectorability(),
      t->valueType()
    ),
    _content(t) {}		///< construct a TableType with a content of a type t, promoting nature, variability and computability

	TableType(
    const Type&     t,
    Precision       precision,
    Priority        priority,
    Availability    availability,
    Vectorability   vectorability,
    Value           value_type
  ) :
    AudioType(
      t->precision() | precision,
      t->priority() | priority,
      t->availability() | availability,
      t->vectorability() | vectorability,
      t->valueType() | value_type
    ),
    _content(t) {}		///< construct a TableType with a content of a type t, promoting nature, variability, computability, vectorability and booleanity
#endif

    TableType(
      const Type&        t,
      Precision          precision,
      Priority           priority,
      Availability       availability,
      Vectorability      vectorability,
      Value              value_type,
      const ::interval&  i
    ) :
      AudioType(
        Precision( static_cast<unsigned int>( t->precision() )
                 | static_cast<unsigned int>( precision ) ),
        Priority( static_cast<unsigned int>( Priority::Konst )
                | static_cast<unsigned int>( priority ) ),
        Availability( static_cast<unsigned int>( Availability::Init )
                    | static_cast<unsigned int>( availability ) ),
        Vectorability( static_cast<unsigned int>( Vectorability::Vect )
                     | static_cast<unsigned int>( vectorability ) ),
        Value( static_cast<unsigned int>( t->valueType() )
             | static_cast<unsigned int>( value_type ) ),
        i
      ),
      _content(t)
    {
    }  ///< construct a TableType with a content of a type t, promoting nature, variability, computability,
       ///< vectorability and booleanity

    TableType(
      const Type&     t,
      Precision       precision,
      Priority        priority,
      Availability    availability,
      Vectorability   vectorability
    ) :
      AudioType(
        Precision( static_cast<unsigned int>( t->precision() )
                 | static_cast<unsigned int>( precision ) ),
        Priority( static_cast<unsigned int>( Priority::Konst )
                | static_cast<unsigned int>( priority ) ),
        Availability( static_cast<unsigned int>( Availability::Init )
                    | static_cast<unsigned int>( availability ) ),
        Vectorability( static_cast<unsigned int>( Vectorability::Vect )
                     | static_cast<unsigned int>( vectorability ) ),
        t->valueType()
      ),
      _content(t)
    {
    }  ///< construct a TableType with a content of a type t, promoting nature, variability, computability and
       ///< vectorability

    Type             content() const { return _content; }  ///< return the type of data store in the table
    virtual ostream& print(ostream& dst) const;            ///< print a TableType

    virtual AudioType* promotePrecision( const Precision& precision )
    {
        return makeTableType(
          _content,
          Precision( static_cast<unsigned int>(_precision) | static_cast<unsigned int>(precision) ),
          _priority,
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the nature of a type
    virtual AudioType* promotePriority( const Priority& priority )
    {
        return makeTableType(
          _content,
          _precision,
          Priority( static_cast<unsigned int>(_priority) | static_cast<unsigned int>(priority) ),
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the variability of a type
    virtual AudioType* promoteAvailability( const Availability& availability )
    {
        return makeTableType(
          _content,
          _precision,
          _priority,
          Availability( static_cast<unsigned int>(_availability) | static_cast<unsigned int>(availability) ),
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the computability of a type
    virtual AudioType* promoteVectorability( const Vectorability& vectorability )
    {
        return makeTableType(
          _content,
          _precision,
          _priority,
          _availability,
          Vectorability( static_cast<unsigned int>(_vectorability) | static_cast<unsigned int>(vectorability) ),
          _valueType,
          _interval
        );
    }  ///< promote the vectorability of a type
    virtual AudioType* promoteValueType( const Value& value_type )
    {
        return makeTableType(
          _content,
          _precision,
          _priority,
          _availability,
          _vectorability,
          Value( static_cast<unsigned int>(_valueType) | static_cast<unsigned int>(value_type) ),
          _interval
        );
    }  ///< promote the booleanity of a type
    virtual AudioType* promoteInterval(const ::interval& i)
    {
        return makeTableType(
          _content,
          _precision,
          _priority,
          _availability,
          _vectorability,
          _valueType,
          i
        );
    }  ///< promote the interval of a type

    virtual bool isMaximal() const;  ///< true when type is maximal (and therefore can't change depending of hypothesis)
};

/**
 * The type of a tuplet of data.
 * Beside a computability and a variability, TupletTypes have
 * a set of components.
 */
class TupletType : public AudioType {
   protected:
    vector<Type> _components;

   public:
    TupletType()
    : AudioType(
        Precision( 0 ),
        Priority( 0 ),
        Availability( 0 )
      )
    {}

    TupletType(ConstTypes vt)
    : AudioType(
        mergePrecision(vt),
        mergePriority(vt),
        mergeAvailability(vt),
        mergeVectorability(vt),
        mergeValueType(vt),
        mergeinterval(vt)
      ),
      _components(vt)
    {
    }

    TupletType(
      ConstTypes             vt,
      const Precision&       precision,
      const Priority&        priority,
      const Availability&    availability,
      const Vectorability&   vectorability,
      const Value&           value_type,
      const ::interval& i
    ) :
      AudioType(
        Precision( static_cast<unsigned int>(precision)
        | static_cast<unsigned int>(mergePrecision(vt)) ),
        Priority( static_cast<unsigned int>(priority)
        | static_cast<unsigned int>(mergePriority(vt)) ),
        Availability( static_cast<unsigned int>(availability)
        | static_cast<unsigned int>(mergeAvailability(vt)) ),
        Vectorability( static_cast<unsigned int>(vectorability)
        | static_cast<unsigned int>(mergeVectorability(vt)) ),
        Value( static_cast<unsigned int>(value_type)
        | static_cast<unsigned int>(mergeValueType(vt)) ),
        i
      ),
      _components(vt)
    {
    }

    std::size_t arity() const { return _components.size(); }
    Type operator[]( const std::size_t& i ) const { return _components[i]; }
    virtual ostream& print(ostream& dst) const;

    virtual AudioType* promotePrecision( const Precision& precision )
    {
        return new TupletType(
          _components,
          Precision( static_cast<unsigned int>(_precision) | static_cast<unsigned int>(precision) ),
          _priority,
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the nature of a type
    virtual AudioType* promotePriority( const Priority& priority )
    {
        return new TupletType(
          _components,
          _precision,
          Priority( static_cast<unsigned int>(_priority) | static_cast<unsigned int>(priority) ),
          _availability,
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the variability of a type
    virtual AudioType* promoteAvailability( const Availability& availability )
    {
        return new TupletType(
          _components,
          _precision,
          _priority,
          Availability( static_cast<unsigned int>(_availability) | static_cast<unsigned int>(availability) ),
          _vectorability,
          _valueType,
          _interval
        );
    }  ///< promote the computability of a type
    virtual AudioType* promoteVectorability( const Vectorability& vectorability )
    {
        return new TupletType(
          _components,
          _precision,
          _priority,
          _availability,
          Vectorability( static_cast<unsigned int>(_vectorability) | static_cast<unsigned int>(vectorability) ),
          _valueType,
          _interval
        );
    }  ///< promote the vectorability of a type
    virtual AudioType* promoteValueType( const Value& value_type )
    {
        return new TupletType(
          _components,
          _precision,
          _priority,
          _availability,
          _vectorability,
          Value( static_cast<unsigned int>(_valueType) | static_cast<unsigned int>(value_type) ),
          _interval
        );
    }  ///< promote the booleanity of a type
    virtual AudioType* promoteInterval(const ::interval& i)
    {
        return new TupletType(
          _components,
          _precision,
          _priority,
          _availability,
          _vectorability,
          _valueType,
          i
        );
    }  ///< promote the interval of a type

    virtual bool isMaximal() const;  ///< true when type is maximal (and therefore can't change depending of hypothesis)
};

//-------------------------------------------------
//-------------------------------------------------
// 				operations on types
//-------------------------------------------------
//-------------------------------------------------

//--------------------------------------------------
// types creation

Type table(const Type& t);
Type operator|(const Type& t1, const Type& t2);
Type operator*(const Type& t1, const Type& t2);

//--------------------------------------------------
// types comparaison

bool operator==(const Type& t1, const Type& t2);
bool operator<=(const Type& t1, const Type& t2);

inline bool operator!=(const Type& t1, const Type& t2)
{
    return !(t1 == t2);
}
inline bool operator<(const Type& t1, const Type& t2)
{
    return t1 <= t2 && t1 != t2;
}
inline bool operator>(const Type& t1, const Type& t2)
{
    return ! (t2 <= t1);
}
inline bool operator>=(const Type& t1, const Type& t2)
{
    return t2 <= t1;
}

//--------------------------------------------------
// types predicats-conversion

SimpleType* isSimpleType(AudioType* t);
TableType*  isTableType(AudioType* t);
TupletType* isTupletType(AudioType* t);

//--------------------------------------------------
// types impressions

ostream& operator<<(ostream& dst, const SimpleType& t);
ostream& operator<<(ostream& dst, const Type& t);
ostream& operator<<(ostream& dst, const TableType& t);
ostream& operator<<(ostream& dst, const TupletType& t);

//--------------------------------------------------
// type verification

Type checkInt(Type t);    ///< check that t is an integer
Type checkKonst(Type t);  ///< check that t is a constant
Type checkInit(Type t);   ///< check that t is a known at init time

Type checkIntParam(Type t);  ///< check that t is a known at init time, constant and an integer

Type checkWRTbl(Type tbl, Type wr);  ///< check that wr is compatible with tbl content

int checkDelayInterval(Type t);  ///< check if the interval of t is appropriate for a delay

//--------------------------------------------------
// Type conversion

Tree codeAudioType(AudioType* t);  ///< Code an audio type as a tree (memoization)

#endif
