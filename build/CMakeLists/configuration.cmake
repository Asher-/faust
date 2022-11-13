
#######################################
#  Version
#######################################

include(CMakeLists/version.cmake)

#######################################
#  Variables
#######################################

include(CMakeLists/configure/variables.cmake)

#######################################
#  Directories
#######################################

include(CMakeLists/configure/locations/directories.cmake)

#######################################
#  Configuration
#######################################

include(CMakeLists/configure/standard.cmake)
include(CMakeLists/configure/debug.cmake)
include(CMakeLists/configure/options.cmake)

include(CMakeLists/configure/ensure_valid.cmake)

#######################################
#  Dependencies
#######################################

include(CMakeLists/dependencies/headers.cmake)
include(CMakeLists/dependencies/sources.cmake)
include(CMakeLists/dependencies/libs.cmake)

#######################################
#  Locations
#######################################

include(CMakeLists/configure/locations/include.cmake)
include(CMakeLists/configure/locations/lib.cmake)

#######################################
#  Helpers
#######################################

include(CMakeLists/helper/backend.cmake)
include(CMakeLists/helper/include_llvm.cmake)
include(CMakeLists/helper/llvm_cmake.cmake)
include(CMakeLists/helper/llvm_config.cmake)
include(CMakeLists/helper/scan_backends.cmake)

#######################################
#  Platform-Dependent Settings
#######################################

if(APPLE)
	include(CMakeLists/platform/apple.cmake)
elseif (WIN32 OR MSYS)
  if (MSVC_STATIC)
    include(CMakeLists/platform/windows/msvc/static_runtime.cmake)
  else()
    include(CMakeLists/platform/windows/win32.cmake)
  endif()
endif()

#######################################
#  Compiler-Dependent Settings
#######################################

if (MSVC)
  include(CMakeLists/configure/compiler/msvc.cmake)
else()
  include(CMakeLists/configure/compiler/flags.cmake)
endif()

# Theoretically, MSVC could be used to compile while including the LLVM backend.
include(CMakeLists/backend/llvm.cmake)
