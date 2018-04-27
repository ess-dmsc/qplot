set(this_target ${PROJECT_NAME})

# Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

find_package(OpenGL REQUIRED)

set(${this_target}_RESOURCES qplot.qrc)
qt5_add_resources(RCC_SOURCES ${${this_target}_RESOURCES})

file(GLOB_RECURSE ${this_target}_SOURCES *.cpp)
file(GLOB_RECURSE ${this_target}_HEADERS *.h ${PROJECT_BINARY_DIR}/*.h)
dirs_of(${this_target}_INCLUDE_DIRS "${${this_target}_HEADERS}")

add_library(
    ${this_target} STATIC
    ${${this_target}_SOURCES}
    ${${this_target}_HEADERS}
    ${RCC_SOURCES}
)

target_include_directories(
    ${this_target}
    PUBLIC ${${this_target}_INCLUDE_DIRS}
    PRIVATE ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(
    ${this_target}
    PRIVATE ${OPENGL_LIBRARIES}
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::PrintSupport
)

#export(TARGETS ${this_target} FILE ${this_target}-exports.cmake EXPORT_LINK_INTERFACE_LIBRARIES)

