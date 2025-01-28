if(APPLE AND EXISTS /usr/local/opt/qt)
  # Homebrew installs Qt5 (up to at least 5.9.1) in /usr/local/opt/qt. Ensure it can be found by CMake since
  # it is not part of the default /usr/local prefix.
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt")
  
elseif(LINUX)
  list(APPEND CMAKE_PREFIX_PATH "$ENV{QT6_DIR}/lib/cmake")
endif()

message(STATUS "Qt6 cmake directory located in: ${CMAKE_PREFIX_PATH}" )


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport Core5Compat)