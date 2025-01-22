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
  ${dir}/KnightRiderWidget.h
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
  ${dir}/KnightRiderWidget.cpp
  )

install(FILES ${HEADERS}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QPlot)

add_doxygen_source_deps(${HEADERS})

#add_definitions(-DQCUSTOMPLOT_USE_OPENGL=1)
add_subdirectory(qcustomplot)

set(${this_target}_RESOURCES resources/qplot.qrc)
qt_add_resources(RCC_SOURCES ${${this_target}_RESOURCES})

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

target_link_libraries(
  QPlot
  PUBLIC Qt6::Widgets
  PUBLIC Qt6::PrintSupport
  PUBLiC Qt6::Core5Compat
  )

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



