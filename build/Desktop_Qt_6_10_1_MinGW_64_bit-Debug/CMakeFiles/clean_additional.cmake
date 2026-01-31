# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SongPlayer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SongPlayer_autogen.dir\\ParseCache.txt"
  "SongPlayer_autogen"
  )
endif()
