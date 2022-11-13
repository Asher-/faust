#######################################
#  LLVM
#######################################

include_llvm()

if (INCLUDE_LLVM )
	if(USE_LLVM_CONFIG)
		llvm_config()
	else()
		llvm_cmake()
	endif()

	string (REGEX REPLACE "([0-9]+)\\.[0-9]+.*" "\\1" LLVM_MAJOR_VERSION ${LLVM_PACKAGE_VERSION})
	string (REGEX REPLACE "[0-9]+\\.([0-9]+).*" "\\1" LLVM_MINOR_VERSION ${LLVM_PACKAGE_VERSION})
  
  if(LLVM_MAJOR_VERSION GREATER 9)
    set(LLVM_VERSION "LLVM_${LLVM_MAJOR_VERSION}0")
  else()
    set(LLVM_VERSION "LLVM_${LLVM_MAJOR_VERSION}${LLVM_MINOR_VERSION}")
  endif()

	# the declarations below are redundant but necessary to cope with different cmake behaviors on different platforms
	set (TMP ${SRCDIR}/dsp_factory/llvm)
  
  if (NOT MSVC)
    set_property(SOURCE ${TMP}/llvm_dsp_aux.cpp ${TMP}/llvm_dynamic_dsp_aux.cpp APPEND_STRING PROPERTY COMPILE_FLAGS "-fno-rtti ${LLVM_DEFINITIONS}")
    set_property(SOURCE ${TMP}/llvm_dsp_aux.cpp ${TMP}/llvm_dynamic_dsp_aux.cpp APPEND_STRING PROPERTY CMAKE_CXX_FLAGS "-fno-rtti ${LLVM_DEFINITIONS}")
  endif()
	
  set (FAUST_LIBS ${FAUST_LIBS} ${LLVM_LD_FLAGS} ${LLVM_LIBS})

	set (FAUST_DEFINITIONS ${FAUST_DEFINITIONS} -DLLVM_VERSION="${LLVM_PACKAGE_VERSION}")

endif()
