
set (FAUST_DEFINITIONS ${FAUST_DEFINITIONS} -DLIBDIR="${LIBSDIR}")

set (DEBUG_FLAGS "-fvisibility=hidden -fstandalone-debug -fno-eliminate-unused-debug-types -fdebug-macro -fno-limit-debug-info")
set (WARNING_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-overloaded-virtual -Wno-shadow -Wno-ignored-qualifiers")

set(CMAKE_CXX_FLAGS_DEBUG   "-g ${DEBUG_FLAGS} ${WARNING_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fvisibility=hidden ${WARNING_FLAGS}")
