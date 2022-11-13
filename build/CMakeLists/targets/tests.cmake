
if (INCLUDE_TESTS)
	add_executable(test ${SRC} ${SRC_TEST} ${HH})
	target_compile_definitions (test PRIVATE ${FAUST_DEFINITIONS})
	target_include_directories (test PRIVATE ${FAUST_TEST_INC} ${FAUST_INC} ${LLVM_INCLUDE_DIRS} ${FAUST_TEST_INC})
	target_link_libraries (test PRIVATE ${FAUST_LIBS} -lgtest -lgtest_main)
	target_link_directories (test PRIVATE ${MACSDK}/usr/lib ${BREW_AND_PORTS_LIBS} /usr/local/lib)
	scan_backends (test COMPILER)
	set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})
	set_target_properties(test PROPERTIES COMPILE_FLAGS -DFAUST_EXE )

endif()
