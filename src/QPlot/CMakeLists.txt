set(HEADERS
    Gradients.h
    GradientSelector.h
    QHist.h
    QPlot.h
    QPlot1D.h
    QPlot2D.h
    QPlotAppearance.h
    QPlotButton.h
    QPlotDraggable.h
    )

set(SOURCES
    Gradients.cpp
    GradientSelector.cpp
    QPlot.cpp
    QPlot1D.cpp
    QPlot2D.cpp
    QPlotAppearance.cpp
    QPlotButton.cpp
    QPlotDraggable.cpp
    )

install(FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QPlot)

#add_definitions(-DQCUSTOMPLOT_USE_OPENGL=1)
add_subdirectory(qcustomplot)

set(${this_target}_RESOURCES resources/qplot.qrc)
qt5_add_resources(RCC_SOURCES ${${this_target}_RESOURCES})

add_library(QPlot STATIC
    ${HEADERS}
    ${SOURCES}
    ${RCC_SOURCES}
    )

target_include_directories(QPlot
    PRIVATE ${PROJECT_SOURCE_DIR}/src
    INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )

set_target_properties(QPlot
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SO_VERSION 0
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME qplot
    )

target_link_libraries(QPlot
    PUBLIC Qt5::Widgets Qt5::PrintSupport)

install(TARGETS QPlot
    EXPORT qplot_targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT runtime
    )

install(EXPORT qplot_targets
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
    COMPONENT development)



