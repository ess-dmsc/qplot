
# Use the env variable QT6_DIR to add Qt's cmake directory to CMAKE_PREFIX_PATH
if(NOT DEFINED ENV{QT6_DIR})
  message(STATUS "The environment variable QT6_DIR has not been set. It should point to the root location of your Qt6 installation")
endif()
list(APPEND CMAKE_PREFIX_PATH "$ENV{QT6_DIR}/lib/cmake")

message(STATUS "Qt6 cmake directory located in: ${CMAKE_PREFIX_PATH}" )
message(STATUS "==============================================================")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport Core5Compat)