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
    qcustomplot/qcustomplot.h
    )

file(RELATIVE_PATH
    PREFIX
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_LIST_DIR})


foreach(HEADER IN LISTS HEADERS)
  target_sources(${TARGET_NAME}
      PRIVATE
      $<INSTALL_INTERFACE:${PREFIX}/${HEADER}>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/${HEADER}>)
endforeach(HEADER IN HEADERS)
