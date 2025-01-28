# Use the env variable QT6_DIR to add Qt's cmake directory to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH "$ENV{QT6_DIR}/lib/cmake")

message(STATUS "Qt6 cmake directory located in: ${CMAKE_PREFIX_PATH}" )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport Core5Compat)