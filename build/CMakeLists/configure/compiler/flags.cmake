
set (FAUST_DEFINITIONS ${FAUST_DEFINITIONS} -DLIBDIR="${LIBSDIR}")
set(CMAKE_CXX_FLAGS_DEBUG   "-g  -fvisibility=hidden -fstandalone-debug -fno-eliminate-unused-debug-types -fdebug-macro -fno-limit-debug-info -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-overloaded-virtual -Wshadow")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fvisibility=hidden -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-overloaded-virtual")