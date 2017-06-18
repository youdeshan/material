set (app_srcs
	app/main.cpp
	)
source_group(app FILES ${app_srcs})
set (srcs ${srcs} ${app_srcs})
	
if(UNIX)
set (LINK_LIBS
	${wxWidgets_LIBRARIES}

    #X11
    #Xxf86vm
    #Xrandr
    #GL
    #m
    #freeglut
    rt
    m
    dl
    glfw3
    GLEW
)
elseif(WIN32)
set (LINK_LIBS
     ${wxWidgets_LIBRARIES}
	 glfw3

	 debug glew32d
     optimized glew32
)
endif()
	
# add the executable
ADD_EXECUTABLE (glApp ${srcs} )
TARGET_LINK_LIBRARIES (glApp  ${LINK_LIBS})

configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/debug" "${CMAKE_CURRENT_BINARY_DIR}/debug")
configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/release" "${CMAKE_CURRENT_BINARY_DIR}/release")
