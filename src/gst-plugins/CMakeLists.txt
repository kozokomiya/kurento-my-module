include_directories(
  ${GSTREAMER_INCLUDE_DIRS}
  ${GSTREAMER_VIDEO_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${OPENCV_INCLUDE_DIRS}
  ${KmsGstCommons_INCLUDE_DIRS}      # 行追加
)

set(MY_MODULE_SOURCES
  mymodule.c
  gstcustommixer.h                   # gstcustommixer.hを指定
  gstcustommixer.c                   # gstcustommixer.cを指定
)

add_library(mymodule MODULE ${MY_MODULE_SOURCES})
if(SANITIZERS_ENABLED)
  add_sanitizers(mymodule)
endif()

target_link_libraries(mymodule
  ${GSTREAMER_LIBRARIES}
  ${GSTREAMER_VIDEO_LIBRARIES}
  ${OPENCV_LIBRARIES}
  ${KmsGstCommons_LIBRARIES}         # 行追加
)

install(
  TARGETS mymodule
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_GST_PLUGINS_DIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
