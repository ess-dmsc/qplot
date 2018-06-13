set(this_target qplot_test)

## Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

file(GLOB ${this_target}_UI *.ui)
file(GLOB ${this_target}_SOURCES *.cpp)
file(GLOB ${this_target}_HEADERS *.h ${PROJECT_BINARY_DIR}/*.h)
dirs_of(${this_target}_INCLUDE_DIRS "${${this_target}_HEADERS}")

add_executable(
    ${this_target} EXCLUDE_FROM_ALL
    ${${this_target}_UI}
    ${${this_target}_SOURCES}
    ${${this_target}_HEADERS}
)

target_include_directories(
    ${this_target}
    PUBLIC ${${this_target}_INCLUDE_DIRS}
)

target_link_libraries(
    ${this_target}
    qplot
    Qt5::Widgets
    Qt5::PrintSupport
)

