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

#include "tlib/compatibility.hh"
#include "exepath.hh"

namespace Faust {

  struct Controller
  {
    /**
     * transform a filename "faust/example/noise.dsp" into
     * the corresponding fx name "noise"
     */
    static string fxName(const string& filename)
    {
        // determine position right after the last '/' or 0
        size_t p1 = 0;
        for (size_t i = 0; i < filename.size(); i++) {
            if (filename[i] == '/') {
                p1 = i + 1;
            }
        }

        // determine position of the last '.'
        size_t p2 = filename.size();
        for (size_t i = p1; i < filename.size(); i++) {
            if (filename[i] == '.') {
                p2 = i;
            }
        }

        return filename.substr(p1, p2 - p1);
    }

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

    static void initFaustDirectories( const char* const& path_called_to_execute  )
    {
    #if !defined(FAUST_SELF_CONTAINED_LIB)
        char s[1024];
        getFaustPathname(s, 1024);

        gGlobal->gFaustExeDir              = exepath::get(path_called_to_execute);
        gGlobal->gFaustRootDir             = exepath::dirup(gGlobal->gFaustExeDir);
        gGlobal->gFaustDirectory           = fileDirname(s);
        gGlobal->gFaustSuperDirectory      = fileDirname(gGlobal->gFaustDirectory);
        gGlobal->gFaustSuperSuperDirectory = fileDirname(gGlobal->gFaustSuperDirectory);

        //-------------------------------------------------------------------------------------
        // init gImportDirList : a list of path where to search .lib files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_LIB_PATH")) {
            gGlobal->gImportDirList.push_back(envpath);
        }
    #ifdef INSTALL_PREFIX
        gGlobal->gImportDirList.push_back(INSTALL_PREFIX "/share/faust");
    #endif

        gGlobal->gImportDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/share/faust");
        gGlobal->gImportDirList.push_back("/usr/local/share/faust");
        gGlobal->gImportDirList.push_back("/usr/share/faust");

        //-------------------------------------------------------------------------------------
        // init gArchitectureDirList : a list of path where to search architectures files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_ARCH_PATH")) {
            gGlobal->gArchitectureDirList.push_back(envpath);
        }
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustDirectory + "/architecture");
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustSuperDirectory + "/architecture");
        gGlobal->gArchitectureDirList.push_back(gGlobal->gFaustSuperSuperDirectory + "/architecture");
    #ifdef INSTALL_PREFIX
        gGlobal->gArchitectureDirList.push_back(INSTALL_PREFIX "/share/faust");
        gGlobal->gArchitectureDirList.push_back(INSTALL_PREFIX "/include");
    #endif
        gGlobal->gArchitectureDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/share/faust");
        gGlobal->gArchitectureDirList.push_back(exepath::dirup(gGlobal->gFaustExeDir) + "/include");
        gGlobal->gArchitectureDirList.push_back("/usr/local/share/faust");
        gGlobal->gArchitectureDirList.push_back("/usr/share/faust");
        gGlobal->gArchitectureDirList.push_back("/usr/local/include");
        gGlobal->gArchitectureDirList.push_back("/usr/include");

        // for debugging purposes
        //    cerr << "gArchitectureDirList:\n";
        //    for (const auto& d : gGlobal->gArchitectureDirList) {
        //        cerr << "\t" << d << "\n";
        //    }
        //    cerr << endl;
    #endif
    }

    #ifdef WIN32
    #define kPSEP '\\'
    #else
    #define kPSEP '/'
    #endif

    #ifndef LIBDIR
    #define LIBDIR "lib"
    #endif

    static void printLibDir()
    {
        cout << gGlobal->gFaustRootDir << kPSEP << LIBDIR << endl;
    }

    static void printIncludeDir()
    {
        cout << gGlobal->gFaustRootDir << kPSEP << "include" << endl;
    }

    static void printArchDir()
    {
        cout << gGlobal->gFaustRootDir << kPSEP << "share" << kPSEP << "faust" << endl;
    }

    static void printDspDir()
    {
        cout << gGlobal->gFaustRootDir << kPSEP << "share" << kPSEP << "faust" << endl;
    }

    static void printPaths()
    {
        cout << "FAUST dsp library paths:" << endl;
        for (const auto& path : gGlobal->gImportDirList) cout << path << endl;
        cout << "\nFAUST architectures paths:" << endl;
        for (const auto& path : gGlobal->gArchitectureDirList) cout << path << endl;
        cout << endl;
    }


  };

}

#endif
