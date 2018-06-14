set(SOURCES
    document_save.png
    view_fullscreen.png
    view_statistics.png
    qplot.qrc
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
