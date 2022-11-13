
# dynamic faust library
if (INCLUDE_DYNAMIC)
	add_library(dynamiclib SHARED ${SRC} ${HH})
	target_compile_definitions (dynamiclib PRIVATE ${FAUST_DEFINITIONS})
	target_include_directories (dynamiclib PRIVATE ${FAUST_INC} ${LLVM_INCLUDE_DIRS})
	target_link_libraries (dynamiclib PRIVATE ${FAUST_LIBS})
	if (WIN32 OR MSYS)
		enable_language(RC)
		set_target_properties(dynamiclib PROPERTIES
			ARCHIVE_OUTPUT_DIRECTORY ${LIBDIR}
			RUNTIME_OUTPUT_DIRECTORY ${LIBDIR})
		set_target_properties(dynamiclib PROPERTIES OUTPUT_NAME faust)
		target_sources (faust PRIVATE ${ROOT}/windows/faust.rc)
		target_sources (dynamiclib PRIVATE ${ROOT}/windows/faustdll.rc)
	else()
		if (IOS)
			set_target_properties(dynamiclib PROPERTIES OUTPUT_NAME faust.ios)
		else()
			set_target_properties(dynamiclib PROPERTIES OUTPUT_NAME faust)
		endif()
		set_target_properties(dynamiclib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBDIR})
		set_target_properties(dynamiclib PROPERTIES
			LIBRARY_OUTPUT_DIRECTORY ${LIBDIR}
			VERSION ${VERSION}
			SOVERSION ${SOVERS})
	endif()
	set_target_properties(dynamiclib PROPERTIES COMPILE_FLAGS -DFAUST_LIB)
	scan_backends (dynamiclib DYNAMIC)
#	set (INSTALL_TARGETS ${INSTALL_TARGETS} dynamiclib)
endif()
