
# static faust library
if (INCLUDE_STATIC)
	add_library(staticlib STATIC ${SRC} ${HH})
	target_compile_definitions (staticlib PRIVATE ${FAUST_DEFINITIONS})
	target_include_directories (staticlib PRIVATE ${FAUST_INC} ${LLVM_INCLUDE_DIRS})
	target_link_libraries (staticlib PRIVATE ${FAUST_LIBS})
	set_target_properties(staticlib PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${LIBDIR}
		LIBRARY_OUTPUT_DIRECTORY ${LIBDIR}
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${LIBDIR}
		LIBRARY_OUTPUT_DIRECTORY_RELEASE ${LIBDIR})
	if (MSVC)
		set_target_properties(staticlib PROPERTIES OUTPUT_NAME libfaust)
	elseif (IOS)
		set_target_properties(staticlib PROPERTIES OUTPUT_NAME faust.ios)
	else()
		set_target_properties(staticlib PROPERTIES OUTPUT_NAME faust)
	endif()
	set_target_properties(staticlib PROPERTIES COMPILE_FLAGS -DFAUST_LIB
		POSITION_INDEPENDENT_CODE ON)
	set (INSTALL_TARGETS ${INSTALL_TARGETS} staticlib)
	scan_backends (staticlib STATIC)
	if (INCLUDE_LLVM)
		if (WIN32)
			set (MAKELIBCMD Make.llvm.static.bat)
		else()
			set (MAKELIBCMD make -f Make.llvm.static || true)
		endif()
		add_custom_command(TARGET staticlib POST_BUILD
                   COMMAND ${MAKELIBCMD}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   COMMENT "Embed LLVM static libraries with libfaust" )
    endif()

endif()
