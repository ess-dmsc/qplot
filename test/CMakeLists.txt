set(this_target qplot_test)

## Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

add_executable(
    ${this_target} EXCLUDE_FROM_ALL
    main.cpp
    TestApp.cpp
    TestApp.h
    TestApp.ui
    TestPlot2D.cpp
    TestPlot2D.h
    TestPlot2D.ui
)

target_include_directories(
    ${this_target}
    PRIVATE .
    PRIVATE ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(
    ${this_target}
    QPlot
    Qt5::Widgets
    Qt5::PrintSupport
)

