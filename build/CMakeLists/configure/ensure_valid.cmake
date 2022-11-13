#######################################
#  Ensure No Build Option Conflicts
#######################################

if (UNIVERSAL AND NOT APPLE)
	message(WARNING "UNIVERSAL option is only available on MacOS or iOS. Setting UNIVERSAL to off.")
  set(UNIVERSAL off)
endif()

