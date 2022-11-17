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

#ifndef _ADDRESS_
#define _ADDRESS_

#include "compiler/types/printable.hh"

struct InstVisitor;
struct CloneVisitor;

struct Address : public Printable {
    enum AccessType {
        kStruct       = 0x1,
        kStaticStruct = 0x2,  // Static shared variable between all DSPs
        kFunArgs      = 0x4,
        kStack        = 0x8,
        kGlobal       = 0x10,
        kLink         = 0x20,
        kLoop         = 0x40,
        kVolatile     = 0x80,
        kReference    = 0x100,  // Access by reference (for Rust backend)
        kMutable      = 0x200,  // Mutable access (for Rust backend)
        kConst        = 0x400   // Const access
    };

    Address() {}

    virtual void                setAccess(Address::AccessType type) = 0;
    virtual Address::AccessType getAccess() const                   = 0;
    bool isStack() { return getAccess() == kStack; }
    bool isStruct() { return getAccess() == kStruct; }

    virtual void   setName(const std::string& name) = 0;
    virtual std::string getName() const             = 0;

    static void dump(AccessType access) { *fOut << dumpString(access); }

#define hasAccess(arg) res += (res != "") ? (std::string("|") + std::string(arg)) : std::string(arg);

    static std::string dumpString(AccessType access)
    {
        std::string res;
        if (access & kStruct) hasAccess("kStruct");
        if (access & kStaticStruct) hasAccess("kStaticStruct");
        if (access & kFunArgs) hasAccess("kFunArgs");
        if (access & kStack) hasAccess("kStack");
        if (access & kGlobal) hasAccess("kGlobal");
        if (access & kLink) hasAccess("kLink");
        if (access & kLoop) hasAccess("kLoop");
        if (access & kVolatile) hasAccess("kVolatile");
        if (access & kReference) hasAccess("kReference");
        if (access & kMutable) hasAccess("kMutable");
        if (access & kConst) hasAccess("kConst");
        return res;
    }

    virtual Address* clone(CloneVisitor* cloner) = 0;

    virtual void accept(InstVisitor* visitor) = 0;
};

#endif
