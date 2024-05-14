# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AirLife_autogen"
  "CMakeFiles\\AirLife_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AirLife_autogen.dir\\ParseCache.txt"
  "src\\Core\\CMakeFiles\\CoreCode_autogen.dir\\AutogenUsed.txt"
  "src\\Core\\CMakeFiles\\CoreCode_autogen.dir\\ParseCache.txt"
  "src\\Core\\CoreCode_autogen"
  "src\\UI\\CMakeFiles\\GUI_autogen.dir\\AutogenUsed.txt"
  "src\\UI\\CMakeFiles\\GUI_autogen.dir\\ParseCache.txt"
  "src\\UI\\GUI_autogen"
  )
endif()
