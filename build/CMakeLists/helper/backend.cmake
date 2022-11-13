
####################################
function(backend NAME DIR TARGET)
	message(STATUS "In target ${TARGET}: include ${NAME} backend")
	target_compile_definitions (${TARGET} PRIVATE -D${NAME}_BUILD)
	if (NOT "${DIR}" STREQUAL "")
		file (GLOB BACKEND_SRC	${SRCDIR}/target/language/${DIR}/*.cpp ${SRCDIR}/target/language/${DIR}/*.hh)
		target_sources (${TARGET} PRIVATE ${BACKEND_SRC})
		target_include_directories (${TARGET} PRIVATE ${SRCDIR}/target/language/${DIR})
	endif()
endfunction()

