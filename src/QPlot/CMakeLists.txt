set(dir ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    ${dir}/Gradients.h
    ${dir}/GradientSelector.h
    ${dir}/QHist.h
    ${dir}/QPlot.h
    ${dir}/QPlot1D.h
    ${dir}/QPlot2D.h
    ${dir}/QPlotAppearance.h
    ${dir}/QPlotButton.h
    ${dir}/QPlotDraggable.h
    ${dir}/qcustomplot/qcustomplot.h
    )

set(SOURCES
    ${dir}/Gradients.cpp
    ${dir}/GradientSelector.cpp
    ${dir}/QPlot.cpp
    ${dir}/QPlot1D.cpp
    ${dir}/QPlot2D.cpp
    ${dir}/QPlotAppearance.cpp
    ${dir}/QPlotButton.cpp
    ${dir}/QPlotDraggable.cpp
    ${dir}/qcustomplot/qcustomplot.cpp
    )

set(${this_target}_RESOURCES ${dir}/resources/qplot.qrc)
qt5_add_resources(RCC_SOURCES ${${this_target}_RESOURCES})

install(FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QPlot)

add_library(QPlot STATIC
    ${HEADERS}
    ${SOURCES}
    ${RCC_SOURCES}
    )

target_compile_definitions(QPlot PRIVATE DLL_BUILD)
set(QPLOT_LINKS Qt5::Widgets Qt5::PrintSupport)

target_include_directories(QPlot
    PRIVATE ${PROJECT_SOURCE_DIR}/src
    INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )

set_target_properties(QPlot
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SO_VERSION 0
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME QPlot
    )

target_link_libraries(QPlot
    PUBLIC ${QPLOT_LINKS})

install(TARGETS QPlot
    EXPORT QPlot_targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT runtime
    )

install(EXPORT QPlot_targets
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
    COMPONENT development)



