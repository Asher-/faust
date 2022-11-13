
####################################
####################################
# Install
####################################
####################################

message (STATUS "Install location is ${CMAKE_INSTALL_PREFIX}")
message (STATUS "Install libraries in ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}")
message (STATUS "Include targets: ${INSTALL_TARGETS} ${SUBTARGETS}")

# the faust compiler and libraries
####################################
# bin/faust, lib/libfaustlib
####################################

if (PACK)
	set (CMAKE_INSTALL_PREFIX .)
endif()

install ( TARGETS ${INSTALL_TARGETS}
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/faust
)

if (INCLUDE_DYNAMIC)
install ( TARGETS dynamiclib
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
)
endif()

####################################
# lib/libfaustwithllvm
####################################

# install the faust with llvm library

if (INCLUDE_STATIC AND INCLUDE_LLVM)
if (WIN32)
	set (LFWITHLLVM  ${LIBDIR}/libfaustwithllvm.lib)
else()
	set (LFWITHLLVM  ${LIBDIR}/libfaustwithllvm.a)
endif()
install (
    FILES  ${LFWITHLLVM} DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    OPTIONAL
)
endif()

####################################
# Headers
####################################

install (
    DIRECTORY ${ARCHDIRS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/faust
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
    	GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    PATTERN ".DS_Store" EXCLUDE
    PATTERN "*.o" EXCLUDE
)
install (
    FILES     ${ARCHINC}/misc.h ${ARCHINC}/sound-file.h ${ARCHINC}/export.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/faust
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)
install (
    FILES     ${SRCDIR}/compiler/libfaust.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/faust/dsp
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

####################################
# HTTPd lib Dependency
####################################

# the file below is part of the httpd lib but installed even if the lib is not part of the config
# this is due to the fact that faust -i will try to read it (depending on the architecture file)
install (
    FILES     ${ARCHDIR}/httpdlib/src/include/HTTPDControler.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/faust/gui
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

####################################
# faust2xxx tools
####################################

file (GLOB FAUST2XXX ${ROOT}/tools/faust2appls/faust2* ${ROOT}/tools/faust2appls/faustremote ${ROOT}/tools/faust2appls/encoderunitypackage ${ROOT}/tools/faust2appls/usage.sh ${ROOT}/tools/faust2appls/filename2ident ${ROOT}/tools/faust2sc-1.0.0/faust2sc )
install (
    FILES     ${FAUST2XXX} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_EXECUTE WORLD_READ
)
install (
    FILES  ${ROOT}/tools/faust-config ${ROOT}/tools/faust2appls/faustoptflags ${ROOT}/tools/faust2appls/faustpath DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_EXECUTE WORLD_READ
)

####################################
# sound2xxx tools
####################################

file (GLOB SOUND2XXX ${ROOT}/tools/sound2faust/sound2faust ${ROOT}/tools/sound2faust/sound2file ${ROOT}/tools/sound2faust/sound2reader)
install (
    FILES     ${SOUND2XXX} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_EXECUTE WORLD_READ
    OPTIONAL
)

####################################
# Shared Resources
####################################

install (
    FILES     ${ROOT}/documentation/man/man1/faust.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/share/man/man1
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

install (
    FILES  ${ARCHDIR}/httpdlib/src/hexa/jsscripts DESTINATION ${CMAKE_INSTALL_PREFIX}/share/faust/js
    RENAME jsscripts.js
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

install (
    FILES  ${ARCHDIR}/httpdlib/src/hexa/stylesheet DESTINATION ${CMAKE_INSTALL_PREFIX}/share/faust/js
    RENAME stylesheet.js
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

####################################
# Examples
####################################

install (
    DIRECTORY     ${ROOT}/examples DESTINATION ${CMAKE_INSTALL_PREFIX}//share/faust
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
    	GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    PATTERN ".DS_Store" EXCLUDE
)

# install faust libraries
file (GLOB FAUSTDSPLIBS ${ROOT}/libraries/*.lib ${ROOT}/libraries/old/*.lib)
file (GLOB FAUSTDPSEMB ${ROOT}/libraries/embedded/*.lib)
# install various files from the architecture root folder
file (GLOB FAUSTARCHS ${ARCHDIR}/*.cpp ${ARCHDIR}/*.c ${ARCHDIR}/*.cs ${ARCHDIR}/*.rs ${ARCHDIR}/*.jl
					${ARCHDIR}/*.java
					${ARCHDIR}/*.h
					${ARCHDIR}/*.d
					${SRCDIR}/documentator/mathdoc/mathdoctexts-*.txt
					${ARCHDIR}/latexheader.tex)
install (
    FILES     ${FAUSTDSPLIBS} ${FAUSTARCHS} ${ROOT}/tools/faust2appls/Info.plist DESTINATION ${CMAKE_INSTALL_PREFIX}/share/faust
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)
install (
    FILES     ${FAUSTDPSEMB} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/faust/embedded
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

####################################
# Folders
####################################

set (ARCHSRC android api AU audiokit daisy esp32 iOS juce julia soul max-msp nodejs osclib sam smartKeyboard teensy unity vcvrack webaudio)
foreach (dir ${ARCHSRC})
	set(ARCHFOLDERS ${ARCHFOLDERS} ${ARCHDIR}/${dir})
endforeach()
set(ARCHFOLDERS ${ARCHFOLDERS} ${ARCHDIR}/httpdlib/html/js)

install (
    DIRECTORY ${ARCHFOLDERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/faust
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
    	GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    PATTERN ".DS_Store" EXCLUDE
    PATTERN "*.o" EXCLUDE
)

####################################
# iOS Lib
####################################

if (NOT WIN32)
	install (
		FILES     ${ARCHDIR}/ios-libsndfile.a DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBSDIR}
		PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
	)
endif()

####################################
# Platform-Specific Installation
####################################

if (MSVC)
  include (InstallRequiredSystemLibraries)
endif()

