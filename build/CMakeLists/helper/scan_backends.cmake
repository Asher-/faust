
####################################
function (scan_backends TARGET FLAG)
	string (FIND "${C_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (C c ${TARGET})
	endif()
	string (FIND "${CPP_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (CPP cpp ${TARGET})
	endif()
	string (FIND "${CSHARP_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (CSHARP csharp ${TARGET})
	endif()
	string (FIND "${DLANG_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (DLANG dlang ${TARGET})
	endif()
	string (FIND "${FIR_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (FIR "" ${TARGET})
	endif()
	string (FIND "${INTERP_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (INTERP interpreter ${TARGET})
	endif()
	string (FIND "${JAVA_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (JAVA java ${TARGET})
	endif()
	string (FIND "${JAX_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (JAX jax ${TARGET})
	endif()
	string (FIND "${JULIA_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (JULIA julia ${TARGET})
	endif()
	string (FIND "${OLDCPP_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (OCPP "" ${TARGET})
	endif()
	string (FIND "${RUST_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (RUST rust ${TARGET})
	endif()
	string (FIND "${SOUL_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (SOUL soul ${TARGET})
	endif()
	string (FIND "${WASM_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (WASM wasm ${TARGET})
	endif()
	string (FIND "${LLVM_BACKEND}" ${FLAG} POS)
	if (${POS} GREATER -1)
		backend (LLVM llvm ${TARGET})
		target_compile_definitions (${TARGET} PRIVATE -D${LLVM_VERSION})
		target_include_directories (${TARGET} PRIVATE ${SRCDIR}/target/language/c ${SRCDIR}/target/language/cpp  ${LLVM_INCLUDE_DIRS} )
	endif()
endfunction()