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

#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include "documentator/doc.hh"
#include "documentator/doc_metadatas.hh"
#include "global.hh"

/*****************************************************************************
                        Public functions
 *****************************************************************************/
/**
 * Initialize global::config().gDocMetadatasKeySet, a set containing all the keywords.
 */
void initDocMetadatas()
{
    global::config().gDocMetadatasKeySet.insert("name");
    global::config().gDocMetadatasKeySet.insert("author");
    global::config().gDocMetadatasKeySet.insert("copyright");
    global::config().gDocMetadatasKeySet.insert("license");
    global::config().gDocMetadatasKeySet.insert("version");
}
