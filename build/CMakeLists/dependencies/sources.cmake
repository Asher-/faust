
#######################################
#  Source Files
#######################################

# faust source files
file (GLOB_RECURSE SRC ${SRCDIR}/*.cpp ${SRCDIR}/*.cc )
set ( SRC ${SRC}
	${ROOT}/benchmark/timing.cpp
	${ROOT}/architecture/faust/export.cpp
)

# test source files
file (GLOB SRC_TEST
	${ROOT}/tests/parser-tests/*.cpp
)

