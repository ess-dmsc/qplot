cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)
project(qplot_test CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

set(EXTRA_MODULES_DIR ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${EXTRA_MODULES_DIR})

#===========================================================
# Internal compiler options
#===========================================================
# C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD LESS 11)
  set(CMAKE_CXX_STANDARD 11)
endif()
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(${EXTRA_MODULES_DIR}/DirsOf.cmake)

# Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Widgets REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES *.cpp *.h *.ui *.qrc)
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS *.h ${PROJECT_BINARY_DIR}/*.h)
dirs_of(${PROJECT_NAME}_INCLUDE_DIRS "${${PROJECT_NAME}_HEADERS}")

add_executable(
  ${PROJECT_NAME}
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${${PROJECT_NAME}_INCLUDE_DIRS}
  PRIVATE ${nmx_common_INCLUDE_DIRS}
  PRIVATE ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}
  ${nmx_common_LIBRARIES}
  ${OPENGL_LIBRARIES}
)

qt5_use_modules(${PROJECT_NAME} Widgets PrintSupport)

if(UNIX)
  install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()
