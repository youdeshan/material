set(SOURCES main.cpp 
    mainwindow.cpp
	logindialog.cpp)
	
set(HEADERS mainwindow.h 
    logindialog.h)
	
set(UI mainwindow.ui
   logindialog.ui)

set(RESOURCES resource.qrc)

# This will create you executable
add_executable(HelloQt WIN32 ${SOURCES} ${HEADERS} ${UI} ${RESOURCES})
# This will link necessary Qt5 libraries to your project
target_link_libraries(HelloQt Qt5::Widgets)