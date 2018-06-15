cmake_minimum_required(VERSION 3.0.0)

project(qplot
    LANGUAGES CXX
    VERSION 0.0.1
    )

#=============================================================================
# Augment CMake with our custom scripts
#=============================================================================
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#=============================================================================
# General configuration
#=============================================================================
include(EnsureBuildType)
include(InstallConfig)
include(OutputDirConfig)
include(PackageConfig)
include(BuildInfo)

#=============================================================================
# compiler and library configuration
#=============================================================================
include(CompilerConfig)
include(QtLibraryConfig)

#=============================================================================
# source
#=============================================================================
add_subdirectory(src)

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

#=============================================================================
# tests
#=============================================================================
add_subdirectory(test)
