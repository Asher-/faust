/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
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

#include "instructions/declarations/declare_buffer_iterators.hh"
#include "global.hh"

// A list of channels variables also kept in the global name <===> type table (use in Rust and Julia backends)
DeclareBufferIterators::DeclareBufferIterators(const std::string& name1,
                                            const std::string& name2,
                                            int channels,
                                            Typed* type,
                                            bool mut)
    : fBufferName1(name1), fBufferName2(name2), fChannels(channels), fType(type), fMutable(mut)
{
    for (int i = 0; i < channels; i++) {
        std::string chan_name = name1 + std::to_string(i);
        if (gGlobal->gVarTypeTable.find(chan_name) == gGlobal->gVarTypeTable.end()) {
            gGlobal->gVarTypeTable[chan_name] = type;
        } else {
            faustassert(false);
        }
    }
}
