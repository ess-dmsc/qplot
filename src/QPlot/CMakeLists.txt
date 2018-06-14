set(SOURCES
    Gradients.cpp
    GradientSelector.cpp
    QPlot.cpp
    QPlot1D.cpp
    QPlot2D.cpp
    QPlotAppearance.cpp
    QPlotButton.cpp
    QPlotDraggable.cpp
    qcustomplot/qcustomplot.cpp
    )

file(RELATIVE_PATH
    PREFIX
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_LIST_DIR})


foreach(SOURCE IN LISTS SOURCES)
  target_sources(${TARGET_NAME}
      PRIVATE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/${SOURCE}>)
endforeach(SOURCE IN SOURCES)
