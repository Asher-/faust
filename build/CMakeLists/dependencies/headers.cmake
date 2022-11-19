
######################################
#  Headers + Includes
#######################################

# header files in source tree
file (GLOB_RECURSE SRC_HH
	${SRCDIR}/*.hh
	${SRCDIR}/*.hpp
	${SRCDIR}/*.h
)

# header files external to source tree
set ( EXT_HH
	${ROOT}/benchmark/timing.hh
	${ROOT}/architecture/faust/export.h
)

