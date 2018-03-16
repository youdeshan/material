set(SOURCES main.cpp 
    view/mainwindow.cpp
	view/mainwindow.h
	view/logindialog.cpp
	view/logindialog.h
	view/user_info_window.cpp
	view/user_info_window.h
	view/user_info_window_ext.cpp
	view/user_info_window_ext.h
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
	)
source_group_by_dir(SOURCES)
	
set(UI ui/mainwindow.ui
   ui/logindialog.ui
   ui/userinfowindow.ui
   ui/userinfowindowext.ui)
source_group_by_dir(UI)

set(RESOURCES resource.qrc)

# This will create you executable
add_executable(HelloQt WIN32 ${SOURCES} ${UI} ${RESOURCES})
# This will link necessary Qt5 libraries to your project
target_link_libraries(HelloQt Qt5::Widgets)