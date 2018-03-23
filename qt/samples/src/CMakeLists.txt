set(SOURCES main.cpp 
    view/mainwindow.cpp
	view/mainwindow.h
	view/mainwindow.ui
	view/logindialog.cpp
	view/logindialog.h
	view/logindialog.ui
	view/user_info_window.cpp
	view/user_info_window.h
	view/userinfowindow.ui
	view/user_info_window_ext.cpp
	view/user_info_window_ext.h
	view/userinfowindowext.ui
	view/gl_widget.cpp
	view/gl_widget.h
	
	camera/camera.h
	camera/camera.cpp
	
	drawing/render/renderer.h
	drawing/render/gl_renderer.h
	drawing/render/gl_renderer.cpp
	
	drawing/scene/node.h
	drawing/scene/graph.h
	drawing/scene/graph.cpp
	drawing/scene/drawable.h
	drawing/scene/drawable.cpp
	
	utils/gl_general.h
	utils/gl_general.cpp
	
	glsl/colors.vs
	glsl/colors.fs
	glsl/lamp.vs
	glsl/lamp.fs
	)
source_group_by_dir(SOURCES)

set(RESOURCES resource.qrc)

if(UNIX)
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
elseif(WIN32)
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
endif()	

# This will create you executable
add_executable(HelloQt WIN32 ${SOURCES} ${RESOURCES})
# This will link necessary Qt5 libraries to your project
target_link_libraries(HelloQt Qt5::Widgets)