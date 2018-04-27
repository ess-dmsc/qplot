set(this_target qplot)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

# Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

find_package(OpenGL REQUIRED)

set(SOURCES
    ${dir}/qcustomplot/qcustomplot.cpp
    ${dir}/Gradients.cpp
    ${dir}/GradientSelector.cpp
    ${dir}/QPlot1D.cpp
    ${dir}/QPlot2D.cpp
    ${dir}/QPlotAppearance.cpp
    ${dir}/QPlotButton.cpp
    ${dir}/QPlot.cpp
    ${dir}/QPlotDraggable.cpp
    )

set(HEADERS
    ${dir}/qcustomplot/qcustomplot.h
    ${dir}/GradientSelector.h
    ${dir}/Gradients.h
    ${dir}/QHist.h
    ${dir}/QPlot1D.h
    ${dir}/QPlot2D.h
    ${dir}/QPlotAppearance.h
    ${dir}/QPlotButton.h
    ${dir}/QPlotDraggable.h
    ${dir}/QPlot.h
    )

set(${this_target}_RESOURCES qplot.qrc)
qt5_add_resources(RCC_SOURCES ${${this_target}_RESOURCES})

add_library(
    ${this_target} STATIC
    ${SOURCES}
    ${HEADERS}
    ${RCC_SOURCES}
)

target_include_directories(
    ${this_target}
    PUBLIC ${dir}
    PUBLIC ${dir}/qcustomplot
    PRIVATE ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(
    ${this_target}
    PRIVATE ${OPENGL_LIBRARIES}
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::PrintSupport
)

#export(TARGETS ${this_target} FILE ${this_target}-exports.cmake EXPORT_LINK_INTERFACE_LIBRARIES)

