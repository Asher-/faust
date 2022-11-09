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

#include <string.h>

#include "faust/compiler/generator/common.hh"

#include "faust/compiler/generator/types.hh"

#ifdef FAUST_LIB
// 'libfaust' compiler uses an empty 'alarm' function
unsigned faust_alarm(unsigned seconds)
{
    return 0;
}
#else
// Standalone compiler uses the real 'alarm' function
unsigned faust_alarm(unsigned seconds)
{
    return alarm(seconds);
}
#endif

namespace Faust {
  namespace Compiler {

    namespace Helper {
      template <typename Compilers> struct FindCompiler;
      template <typename...CompilerType>
      struct FindCompiler<::Faust::CompilerTypes<CompilerType...>>
      {
        static constexpr Common* type( const std::string& output_lang )
        {
          bool found_compiler = false;
          Common*  compiler = nullptr;
          ( ( ( ( output_lang == CompilerType::LanguageString ) && ! found_compiler)
              ? ( found_compiler = true,compiler = new CompilerType() )
              : nullptr ), ... );
          return compiler;
        }
      };
    }
    using FindCompiler = Helper::FindCompiler<::Faust::Compilers>;

    Common* Common::compiler( const std::string& output_lang )
    {
        Common* compiler = FindCompiler::type( output_lang );
        if ( ! compiler ) {
            stringstream error;
            error << "ERROR : cannot find backend for "
                  << "\"" << output_lang << "\"" << endl;
            throw faustexception(error.str());
        }
        return compiler;
    }

  }
}
