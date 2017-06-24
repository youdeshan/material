set (app_srcs
	app/main.cpp
	)
source_group(app FILES ${app_srcs})
set (srcs ${srcs} ${app_srcs})
	
if(UNIX)
link_directories(${CMAKE_CURRENT_BINARY_DIR})
set (LINK_LIBS
	${wxWidgets_LIBRARIES}

    #X11
    #Xxf86vm
    #Xrandr
    #GL
    #m
    #freeglut
    glfw
    GLEW
)
file(COPY "${CMAKE_SOURCE_DIR}/third_party/unix/lib/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
elseif(WIN32)
set (LINK_LIBS
     ${wxWidgets_LIBRARIES}
	 glfw3dll

	 debug glew32d
     optimized glew32
)
configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/debug" "${CMAKE_CURRENT_BINARY_DIR}/debug")
configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/release" "${CMAKE_CURRENT_BINARY_DIR}/release")
endif()
	
# add the executable
ADD_EXECUTABLE (glApp ${srcs} )
TARGET_LINK_LIBRARIES (glApp  ${LINK_LIBS})
