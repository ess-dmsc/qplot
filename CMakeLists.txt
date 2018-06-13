cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(qplot
        LANGUAGES CXX
        VERSION 0.0.1
        )

set(EXTRA_MODULES_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${EXTRA_MODULES_DIR})

include(${EXTRA_MODULES_DIR}/OutputDirConfig.cmake)
include(${EXTRA_MODULES_DIR}/CompilerConfig.cmake)
include(${EXTRA_MODULES_DIR}/DirsOf.cmake)

add_subdirectory(source)
add_subdirectory(test)

