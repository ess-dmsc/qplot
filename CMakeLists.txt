cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(QPLOT_PROJECT_NAME QPlot)
project(${QPLOT_PROJECT_NAME} CXX)


set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
    ${CMAKE_CURRENT_LIST_DIR})


include(CheckCXXCompilerFlag)

include(cmake/install.cmake)
include(cmake/qt-configuration.cmake)
include(cmake/versioning.cmake)


set(${QPLOT_PROJECT_NAME}_VERSION_MAJOR 1)
set(${QPLOT_PROJECT_NAME}_VERSION_MINOR 0)
set(${QPLOT_PROJECT_NAME}_VERSION_PATCH 0)
set(${QPLOT_PROJECT_NAME}_VERSION "${${QPLOT_PROJECT_NAME}_VERSION_MAJOR}.${${QPLOT_PROJECT_NAME}_VERSION_MINOR}.${${QPLOT_PROJECT_NAME}_VERSION_PATCH}")

if(APPLE AND EXISTS /usr/local/opt/qt)
  # Homebrew installs Qt5 (up to at least 5.9.1) in
  # /usr/local/opt/qt, ensure it can be found by CMake since
  # it is not in the default /usr/local prefix.
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt")
endif()
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

set(TARGET_NAME ${QPLOT_PROJECT_NAME})
set(TARGET_OUTPUT_SUFFIX "${${QPLOT_PROJECT_NAME}_VERSION_MAJOR}")
set(INCLUDE_PREFIX "QPlot")
set(QPLOT_LIBRARY "${TARGET_NAME}")


add_library(${TARGET_NAME} STATIC "")
set_target_properties(${TARGET_NAME}
    PROPERTIES
    EXPORT_NAME "${TARGET_NAME}${TARGET_OUTPUT_SUFFIX}")


set_target_properties(${TARGET_NAME}
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    VERSION ${${QPLOT_PROJECT_NAME}_VERSION}
    SOVERSION ${${QPLOT_PROJECT_NAME}_VERSION_MAJOR}
    "INTERFACE_${QPLOT_PROJECT_NAME}_MAJOR_VERSION" ${${QPLOT_PROJECT_NAME}_VERSION_MAJOR}
    COMPATIBLE_INTERFACE_STRING "${QPLOT_PROJECT_NAME}_MAJOR_VERSION"
    COMPILE_DEFINITIONS QTQPLOTS_LIBRARY
    OUTPUT_NAME "${TARGET_NAME}${TARGET_OUTPUT_SUFFIX}")

check_cxx_compiler_flag("-Wall" Wall_FLAG_SUPPORTED)

if(Wall_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
endif(Wall_FLAG_SUPPORTED)

check_cxx_compiler_flag("-pedantic" pedantic_FLAG_SUPPORTED)

if(pedantic_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic")
endif(pedantic_FLAG_SUPPORTED)

check_cxx_compiler_flag("-Wextra" Wextra_FLAG_SUPPORTED)

if(Wextra_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
endif(Wextra_FLAG_SUPPORTED)


set(EXPORT_HEADER "${INCLUDE_PREFIX}/QPlot_global.hpp")


generate_versioning_information(
    TARGET_NAME ${TARGET_NAME}
    EXPORT_HEADER ${EXPORT_HEADER}
    EXPORT_MACRO QCP_EXPORT
    VERSIONED_ENTITY ${QPLOT_PROJECT_NAME}
    INCLUDE_PREFIX ${INCLUDE_PREFIX})


target_include_directories(${TARGET_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
    )


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/${INCLUDE_PREFIX})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/resources/${INCLUDE_PREFIX})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/${INCLUDE_PREFIX})

target_link_libraries(
    ${TARGET_NAME}
    Qt5::Widgets
    Qt5::PrintSupport
)

install_project(
    PROJECT_NAME ${QPLOT_PROJECT_NAME}
    TARGET_NAME ${TARGET_NAME}
    TARGET_OUTPUT_SUFFIX ${TARGET_OUTPUT_SUFFIX}
    EXPORT_HEADER ${EXPORT_HEADER}
    INCLUDE_PREFIX ${INCLUDE_PREFIX}
    HEADER_MATCHING_REGEX "^.*\.h$|^.*\.hpp$|^.*$"
    VERSION_HEADER ${CMAKE_CURRENT_BINARY_DIR}/${QPLOT_PROJECT_NAME}_version.h
    NAMESPACE "")


add_subdirectory(test)

