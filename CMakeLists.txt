cmake_minimum_required(VERSION 3.0.0)

project(QPlot
    LANGUAGES CXX
    VERSION 0.0.1
    )

#=============================================================================
# Augment CMake with our custom scripts
#=============================================================================
set(EXTRA_MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${EXTRA_MODULES_DIR})

#=============================================================================
# General configuration
#=============================================================================

include(${EXTRA_MODULES_DIR}/EnsureBuildType.cmake)
include(${EXTRA_MODULES_DIR}/InstallConfig.cmake)
include(${EXTRA_MODULES_DIR}/OutputDirConfig.cmake)
include(${EXTRA_MODULES_DIR}/PackageConfig.cmake)
include(${EXTRA_MODULES_DIR}/BuildInfo.cmake)

#=============================================================================
# compiler and library configuration
#=============================================================================
include(${EXTRA_MODULES_DIR}/CompilerConfig.cmake)
include(${EXTRA_MODULES_DIR}/QtLibraryConfig.cmake)

add_subdirectory(src)
add_subdirectory(test)

#
# create and install the version file
#
write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/${PACKAGE_VERSION_FILE_NAME}
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(FILES ${PROJECT_BINARY_DIR}/${PACKAGE_VERSION_FILE_NAME}
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
    COMPONENT development)

#
# create and install the package file
#
configure_file("${PACKAGE_CONFIG_FILE_NAME}.in" ${PACKAGE_CONFIG_FILE_NAME} @ONLY)
install(FILES ${PROJECT_BINARY_DIR}/${PACKAGE_CONFIG_FILE_NAME}
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
    COMPONENT development)

