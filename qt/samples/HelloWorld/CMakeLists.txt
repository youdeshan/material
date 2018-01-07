cmake_minimum_required(VERSION 2.8.11)
project(HelloQT)

set(CMAKE_CXX_STANDARD 11) # This is equal to QMAKE_CXX_FLAGS += -std=c++0x

# Find includes in corresponding build directories
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to run uic automatically when needed.
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# This will find the Qt5 files. You will need a QT5_DIR env variable
find_package(Qt5Widgets REQUIRED) # Equivalent of QT += widgets

set(SOURCES main.cpp 
    mainwindow.cpp
	logindialog.cpp)
	
set(HEADERS mainwindow.h 
    logindialog.h)
	
set(UI mainwindow.ui)

set(RESOURCES res.qrc)

# This will create you executable
add_executable(HelloQt WIN32 ${SOURCES} ${HEADERS} ${UI} ${RESOURCES})
# This will link necessary Qt5 libraries to your project
target_link_libraries(HelloQt Qt5::Widgets)