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

#ifndef _STRUCT_MANAGER_H
#define _STRUCT_MANAGER_H

#include <string>
#include <utility>
#include <vector>

#include "compiler/instruction/instructions.hh"

// Describe a field memory location in the DSP structure
struct MemoryDesc {
    enum memType { kLocal, kExternal };
    int fIndex;             // Index
    int fOffset;            // Offset in bytes in a mixed int/real zone
    int fIntOffset;         // Offset in bytes in a separated int zone
    int fRealOffset;        // Offset in bytes in a separated real zone
    int fRAccessCount;      // Read access counter
    int fWAccessCount;      // Write access counter
    int fSize;              // Size in frames
    int fSizeBytes;         // Size in bytes
    Typed::VarType fType;   // FIR type
    memType fMemType;       // Memory type

    MemoryDesc() : fIndex(-1), fOffset(-1),
        fIntOffset(-1), fRealOffset(-1),
        fRAccessCount(0), fWAccessCount(0),
        fSize(-1), fSizeBytes(-1),
        fType(Typed::kNoType), fMemType(kLocal) {}

    MemoryDesc(int index, int offset, int size, int size_bytes, Typed::VarType type)
    : fIndex(index), fOffset(offset),
        fIntOffset(-1), fRealOffset(-1),
        fRAccessCount(0), fWAccessCount(0),
        fSize(size), fSizeBytes(size_bytes),
        fType(type), fMemType(kLocal) {}

    MemoryDesc(int index, int offset,
               int int_offset, int real_offset,
               int size, int size_bytes,
               Typed::VarType type,
               memType mem_type = kLocal)
        : fIndex(index), fOffset(offset),
        fIntOffset(int_offset), fRealOffset(real_offset),
        fRAccessCount(0), fWAccessCount(0),
        fSize(size), fSizeBytes(size_bytes),
        fType(type), fMemType(mem_type) {}

    Typed* getTyped()
    {
        if (fSize > 1) {
            return InstBuilder::genArrayTyped(InstBuilder::genBasicTyped(fType), fSize);
        } else {
            return InstBuilder::genBasicTyped(fType);
        }
    }
};



#endif
