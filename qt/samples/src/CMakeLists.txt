set(SOURCES main.cpp 
    mainwindow.cpp
	logindialog.cpp
	user_info_window.cpp
	user_info_window_ext.cpp)
	
set(HEADERS mainwindow.h 
    logindialog.h
	user_info_window.h
	user_info_window_ext.h)
	
set(UI mainwindow.ui
   logindialog.ui
   userinfowindow.ui
   userinfowindowext.ui)

set(RESOURCES resource.qrc)

# This will create you executable
add_executable(HelloQt WIN32 ${SOURCES} ${HEADERS} ${UI} ${RESOURCES})
# This will link necessary Qt5 libraries to your project
target_link_libraries(HelloQt Qt5::Widgets)