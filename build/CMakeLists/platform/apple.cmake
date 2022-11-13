
if(IOS)
  include(CMakeLists/platform/apple/ios.cmake)
else()
  include(CMakeLists/platform/apple/macos.cmake)
endif()
