####################################
# cmake LLVM scan
macro (llvm_cmake)
	find_package(LLVM REQUIRED CONFIG)
	if (COMMAND llvm_map_components_to_libnames)
		message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
		message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
		# Find the libraries that correspond to the LLVM components that we wish to use
		llvm_map_components_to_libnames(LLVM_LIBS all)
#		list(REMOVE_ITEM LLVM_LIBS LTO)
	else()
		llvm_config()
	endif()
endmacro()
