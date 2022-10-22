/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2016 GRAME, Centre National de Creation Musicale
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

#ifndef __FAUST_CONTROLLER_HH__
#define __FAUST_CONTROLLER_HH__

namespace Faust {

  struct Controller
  {
    static void initDocumentNames()
    {
        if (gGlobal->gInputFiles.empty()) {
            gGlobal->gMasterDocument  = "Unknown";
            gGlobal->gMasterDirectory = ".";
            gGlobal->gMasterName      = "faustfx";
            gGlobal->gDocName         = "faustdoc";
        } else {
            gGlobal->gMasterDocument  = *gGlobal->gInputFiles.begin();
            gGlobal->gMasterDirectory = fileDirname(gGlobal->gMasterDocument);
            gGlobal->gMasterName      = fxName(gGlobal->gMasterDocument);
            gGlobal->gDocName         = fxName(gGlobal->gMasterDocument);
        }

        // Add gMasterDirectory in gImportDirList and gArchitectureDirList
        gGlobal->gImportDirList.push_back(gGlobal->gMasterDirectory);
        gGlobal->gArchitectureDirList.push_back(gGlobal->gMasterDirectory);
    }

  };

}

#endif
