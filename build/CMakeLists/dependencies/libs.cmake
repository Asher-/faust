#######################################
#  Libs
#######################################

# FIX - here temporarily
file (GLOB BREW_AND_PORTS_LIBS
  /usr/local/Cellar/flex/*/lib
  /opt/homebrew/Cellar/flex/*/lib
  /opt/pkg/lib
)

if(NOT ANDROID OR WIN32 OR MSYS OR APPLE)
	set (FAUST_LIBS ${FAUST_LIBS} -lpthread) 
endif()
