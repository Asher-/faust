/************************************************************************
 ************************************************************************
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale

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
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

 ************************************************************************
 ************************************************************************/

#ifndef __FAUST_SMARTABLE_HH__
#define __FAUST_SMARTABLE_HH__

#include "exception.hh"

/*!
    \brief the base class for smart pointers implementation

    Any object that want to support smart pointers should
    inherit from the smartable class which provides reference counting
    and automatic delete when the reference count drops to zero.
 */
class smartable {
   private:
    unsigned refCount;

   public:
    //! gives the reference count of the object
    unsigned refs() const { return refCount; }
    //! addReference increments the ref count and checks for refCount overflow
    void addReference()
    {
        refCount++;
        faustassert(refCount != 0);
    }
    //! removeReference delete the object when refCount is zero
    void removeReference()
    {
        if (--refCount == 0) delete this;
    }

   protected:
    smartable() : refCount(0) {}
    smartable(const smartable&) : refCount(0) {}
    //! destructor checks for non-zero refCount
    virtual ~smartable() { faustassert(refCount == 0); }
    smartable& operator=(const smartable&) { return *this; }
};

#endif
