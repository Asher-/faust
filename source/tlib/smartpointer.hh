/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FAUST__SMART_POINTER__HH__
#define __FAUST__SMART_POINTER__HH__

#include "exception.hh"

/*!
\brief the smart pointer implementation

    A smart pointer is in charge of maintaining the objects reference count
    by the way of pointers operators overloading. It supports class
    inheritance and conversion whenever possible.
\n	Instances of the smartptr class are supposed to use \e smartable types (or at least
    objects that implements the \e addReference and \e removeReference
    methods in a consistent way).
*/
template <class T>
class smartptr {
   private:
    //! the actual pointer to the class
    T* fSmartPtr;

   public:
    //! an empty constructor - points to null
    smartptr() : fSmartPtr(0) {}
    //! build a smart pointer from a class pointer
    smartptr(T* rawptr) : fSmartPtr(rawptr)
    {
        if (fSmartPtr) fSmartPtr->addReference();
    }
    //! build a smart pointer from an convertible class reference
    template <class T2>
    smartptr(const smartptr<T2>& ptr) : fSmartPtr((T*)ptr)
    {
        if (fSmartPtr) fSmartPtr->addReference();
    }
    //! build a smart pointer from another smart pointer reference
    smartptr(const smartptr& ptr) : fSmartPtr((T*)ptr)
    {
        if (fSmartPtr) fSmartPtr->addReference();
    }

    //! the smart pointer destructor: simply removes one reference count
    ~smartptr()
    {
        if (fSmartPtr) fSmartPtr->removeReference();
    }

    //! cast operator to retrieve the actual class pointer
    operator T*() const { return fSmartPtr; }

    //! '*' operator to access the actual class pointer
    T& operator*() const
    {
        // checks for null dereference
        faustassert(fSmartPtr != 0);
        return *fSmartPtr;
    }

    //! operator -> overloading to access the actual class pointer
    T* operator->() const
    {
        // checks for null dereference
        faustassert(fSmartPtr != 0);
        return fSmartPtr;
    }

    //! operator = that moves the actual class pointer
    template <class T2>
    smartptr& operator=(T2 p1_)
    {
        *this = (T*)p1_;
        return *this;
    }

    //! operator = that moves the actual class pointer
    smartptr& operator=(T* p_)
    {
        // check first that pointers differ
        if (fSmartPtr != p_) {
            // increments the ref count of the new pointer if not null
            if (p_ != 0) p_->addReference();
            // decrements the ref count of the old pointer if not null
            if (fSmartPtr != 0) fSmartPtr->removeReference();
            // and finally stores the new actual pointer
            fSmartPtr = p_;
        }
        return *this;
    }
    //! operator < to support smartptr map with Visual C++
    bool operator<(const smartptr<T>& p_) const { return fSmartPtr < ((T*)p_); }
    //! operator = to support inherited class reference
    smartptr& operator=(const smartptr<T>& p_) { return operator=((T*)p_); }
    //! dynamic cast support
    template <class T2>
    smartptr& cast(T2* p_)
    {
        return operator=(dynamic_cast<T*>(p_));
    }
    //! dynamic cast support
    template <class T2>
    smartptr& cast(const smartptr<T2>& p_)
    {
        return operator=(dynamic_cast<T*>(p_));
    }
};

#endif
