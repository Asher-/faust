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
#include "compiler/util/exepath.hh"

#include "compiler/parser/implementation.hh"

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
        if (global::config().gInputFiles.empty()) {
            gMasterDocument()  = "Unknown";
            global::config().gMasterDirectory = ".";
            global::config().gMasterName      = "faustfx";
            global::config().gDocName         = "faustdoc";
        } else {
            gMasterDocument()  = *global::config().gInputFiles.begin();
            global::config().gMasterDirectory = fileDirname(gMasterDocument());
            global::config().gMasterName      = fxName(gMasterDocument());
            global::config().gDocName         = fxName(gMasterDocument());
        }

        // Add gMasterDirectory in gImportDirList and gArchitectureDirList
        global::config().gImportDirList.push_back(global::config().gMasterDirectory);
        global::config().gArchitectureDirList.push_back(global::config().gMasterDirectory);
    }

    static void initFaustDirectories( const char* const& path_called_to_execute  )
    {
    #if !defined(FAUST_SELF_CONTAINED_LIB)
        char s[1024];
        getFaustPathname(s, 1024);

        global::config().gFaustExeDir              = exepath::get(path_called_to_execute);
        global::config().gFaustRootDir             = exepath::dirup(global::config().gFaustExeDir);
        global::config().gFaustDirectory           = fileDirname(s);
        global::config().gFaustSuperDirectory      = fileDirname(global::config().gFaustDirectory);
        global::config().gFaustSuperSuperDirectory = fileDirname(global::config().gFaustSuperDirectory);

        //-------------------------------------------------------------------------------------
        // init gImportDirList : a list of path where to search .lib files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_LIB_PATH")) {
            global::config().gImportDirList.push_back(envpath);
        }
    #ifdef INSTALL_PREFIX
        global::config().gImportDirList.push_back(INSTALL_PREFIX "/share/faust");
    #endif

        global::config().gImportDirList.push_back(exepath::dirup(global::config().gFaustExeDir) + "/share/faust");
        global::config().gImportDirList.push_back("/usr/local/share/faust");
        global::config().gImportDirList.push_back("/usr/share/faust");

        //-------------------------------------------------------------------------------------
        // init gArchitectureDirList : a list of path where to search architectures files
        //-------------------------------------------------------------------------------------
        if (char* envpath = getenv("FAUST_ARCH_PATH")) {
            global::config().gArchitectureDirList.push_back(envpath);
        }
        global::config().gArchitectureDirList.push_back(global::config().gFaustDirectory + "/architecture");
        global::config().gArchitectureDirList.push_back(global::config().gFaustSuperDirectory + "/architecture");
        global::config().gArchitectureDirList.push_back(global::config().gFaustSuperSuperDirectory + "/architecture");
    #ifdef INSTALL_PREFIX
        global::config().gArchitectureDirList.push_back(INSTALL_PREFIX "/share/faust");
        global::config().gArchitectureDirList.push_back(INSTALL_PREFIX "/include");
    #endif
        global::config().gArchitectureDirList.push_back(exepath::dirup(global::config().gFaustExeDir) + "/share/faust");
        global::config().gArchitectureDirList.push_back(exepath::dirup(global::config().gFaustExeDir) + "/include");
        global::config().gArchitectureDirList.push_back("/usr/local/share/faust");
        global::config().gArchitectureDirList.push_back("/usr/share/faust");
        global::config().gArchitectureDirList.push_back("/usr/local/include");
        global::config().gArchitectureDirList.push_back("/usr/include");

        // for debugging purposes
        //    cerr << "gArchitectureDirList:\n";
        //    for (const auto& d : global::config().gArchitectureDirList) {
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
        cout << global::config().gFaustRootDir << kPSEP << LIBDIR << endl;
    }

    static void printIncludeDir()
    {
        cout << global::config().gFaustRootDir << kPSEP << "include" << endl;
    }

    static void printArchDir()
    {
        cout << global::config().gFaustRootDir << kPSEP << "share" << kPSEP << "faust" << endl;
    }

    static void printDspDir()
    {
        cout << global::config().gFaustRootDir << kPSEP << "share" << kPSEP << "faust" << endl;
    }

    static void printPaths()
    {
        cout << "FAUST dsp library paths:" << endl;
        for (const auto& path : global::config().gImportDirList) cout << path << endl;
        cout << "\nFAUST architectures paths:" << endl;
        for (const auto& path : global::config().gArchitectureDirList) cout << path << endl;
        cout << endl;
    }


  };

}

#endif
