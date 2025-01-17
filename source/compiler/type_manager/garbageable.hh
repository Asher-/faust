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

#ifndef __FAUST_GARBAGE__
#define __FAUST_GARBAGE__

#include <stdio.h>
#include <new>
#include <list>

#include "compiler/errors/exception.hh"
#include "faust/export.h"

// To be inherited by all garbageable classes

/* Garbageable denotes a type that is allocated in memory and can be deleted. */

class LIBFAUST_API Garbageable {
   public:
    Garbageable()
    {}
    virtual ~Garbageable()
    {}

    /* Defined in global.cpp */
    void* operator new(size_t size);
    void* operator new[](size_t size);
    void  operator delete(void* ptr);
    void  operator delete[](void* ptr);

    static void cleanup();

    static std::list<Garbageable*>& objectTable();
    static bool gHeapCleanup;
};

template <class P>
class GarbageablePtr : public virtual Garbageable {
   private:
    P* fPtr;

   public:
    GarbageablePtr(const P& data) { fPtr = new P(data); }

    virtual ~GarbageablePtr() { delete (fPtr); }

    P* getPointer() { return fPtr; }
};

#endif
