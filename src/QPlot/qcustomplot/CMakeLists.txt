set(dir ${CMAKE_CURRENT_SOURCE_DIR})

set(my_sources
    ${dir}/qcustomplot.cpp
  )

set(my_headers
    ${dir}/qcustomplot.h
  )

install(FILES ${my_headers}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QPlot/qcustomplot)

set(HEADERS ${HEADERS} ${my_headers} PARENT_SCOPE)
set(SOURCES ${SOURCES} ${my_sources} PARENT_SCOPE)
