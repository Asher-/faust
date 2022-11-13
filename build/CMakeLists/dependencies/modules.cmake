
####################################
# Modules (emcc, osclib, interpreter, etc.)
####################################

if (${CMAKE_GENERATOR} STREQUAL Xcode OR ${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC OR IOS)
	set (INCLUDE_EMCC off)
	set (INCLUDE_WASM_GLUE off)
endif()

if (INCLUDE_EMCC)
	add_subdirectory (emcc)
endif()

if (INCLUDE_WASM_GLUE)
	add_subdirectory (wasmglue)
endif()

if (INCLUDE_OSC OR OSCDYNAMIC)
	add_subdirectory (osc)
	set (SUBTARGETS ${SUBTARGETS} osc)
endif()

if (INCLUDE_HTTP OR HTTPDYNAMIC)
	add_subdirectory (http)
	set (SUBTARGETS ${SUBTARGETS} http)
endif()

if (INCLUDE_ITP OR ITPDYNAMIC)
	add_subdirectory (interp)
	set (SUBTARGETS ${SUBTARGETS} faustmachine)
endif()

