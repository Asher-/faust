#######################################
#  Faust Build System
#######################################

cmake_minimum_required(VERSION 3.5)
project(faust)

####################################
# Configuration
####################################

# All configuration that is not project(faust)-specific
# is kept in a separate configuration.cmake file so that
# it can be easily re-used by dependent projects.

include(CMakeLists/configuration.cmake)

####################################
# Targets
####################################

include(CMakeLists/targets/faust.cmake)
include(CMakeLists/targets/tests.cmake)

include(CMakeLists/targets/library/static.cmake)
include(CMakeLists/targets/library/dynamic.cmake)
include(CMakeLists/targets/library/self_contained.cmake)

####################################
# Modules (emcc, osclib, interpreter, etc.)
####################################

include(CMakeLists/dependencies/modules.cmake)

####################################
# Install
####################################

include(CMakeLists/install.cmake)
include(CMakeLists/pack.cmake)
