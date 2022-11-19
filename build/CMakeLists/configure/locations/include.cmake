#######################################
#  Includes
#######################################

# headers are currently referenced without path,
# so any directory with a header is an include dir
foreach(hh ${SRC_HH})
	get_filename_component(hh_include_dir ${hh} DIRECTORY)
	set ( HEADER_INCLUDE_DIRS ${HEADER_INCLUDE_DIRS} ${hh_include_dir} )
	get_filename_component(hh_include_parent_dir ${hh_include_dir} DIRECTORY)
	if ( NOT ${hh_include_dir} STREQUAL ${SRCDIR} )
		while( NOT ${hh_include_parent_dir} STREQUAL ${SRCDIR} )
			set ( HEADER_INCLUDE_DIRS ${HEADER_INCLUDE_DIRS} ${hh_include_parent_dir} )
			get_filename_component(hh_include_parent_dir ${hh_include_parent_dir} DIRECTORY)
		endwhile()
	endif()
 unset( hh_include_dir )
 unset( hh_include_parent_dir )
endforeach()

# FIX - here temporarily
file (GLOB BREW_AND_PORTS_INCLUDES
  /usr/local/Cellar/flex/*/include
  /opt/homebrew/Cellar/flex/*/include
  /opt/pkg/include
)

set ( HEADER_INCLUDE_DIRS ${HEADER_INCLUDE_DIRS}
  ${ROOT}/benchmark
  ${ROOT}/architecture
)

set (FAUST_INC ${HEADER_INCLUDE_DIRS} ${SRC_HH} ${EXT_HH}
	${ROOT}/architecture/faust
	${ROOT}/benchmark
  ${BREW_AND_PORTS_INCLUDES}
	/usr/local/include
)

# test include directories
set (FAUST_TEST_INC ${FAUST_INC}
	${ROOT}/tests
	${ROOT}/tests/parser-tests
)

