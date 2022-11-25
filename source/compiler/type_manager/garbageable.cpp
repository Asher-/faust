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

#include <list>

#include "compiler/type_manager/garbageable.hh"

bool  Garbageable::gHeapCleanup = false;

std::list<Garbageable*>& Garbageable::objectTable()
{
  static std::list<Garbageable*> objectTable;
  return objectTable;
}

void Garbageable::cleanup()
{
    std::list<Garbageable*>::iterator it;

    // Here removing the deleted pointer from the list is pointless
    // and takes time, thus we don't do it.
    Garbageable::gHeapCleanup = true;
    std::size_t index = 0;
    for (it = Garbageable::objectTable().begin(); it != Garbageable::objectTable().end(); ++index, it++) {
#ifdef _WIN32
        // Hack : "this" and actual pointer are not the same: destructor cannot be called...
        Garbageable::operator delete(*it);
#else
        delete (*it);
#endif
    }

    // Reset to default state
    Garbageable::objectTable().clear();
    Garbageable::gHeapCleanup = false;
}

void* Garbageable::operator new(size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);

    Garbageable::objectTable().push_back(res);
    return res;
}

void Garbageable::operator delete(void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!Garbageable::gHeapCleanup) {
        Garbageable::objectTable().remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}

void* Garbageable::operator new[](size_t size)
{
    // HACK : add 16 bytes to avoid unsolved memory smashing bug...
    Garbageable* res = (Garbageable*)malloc(size + 16);
    Garbageable::objectTable().push_front(res);
    return res;
}

void Garbageable::operator delete[](void* ptr)
{
    // We may have cases when a pointer will be deleted during
    // a compilation, thus the pointer has to be removed from the list.
    if (!Garbageable::gHeapCleanup) {
        Garbageable::objectTable().remove(static_cast<Garbageable*>(ptr));
    }
    free(ptr);
}
