set (app_srcs
	app/main.cpp
	)
source_group(app FILES ${app_srcs})
set (srcs ${srcs} ${app_srcs})
	
set (LINK_LIBS
	${wxWidgets_LIBRARIES}

    X11
    Xxf86vm
    Xrandr
    GL
    m
    freeglut
    GLEW
	)
	
# add the executable
ADD_EXECUTABLE (glApp ${srcs} )
ARGET_LINK_LIBRARIES (glApp  ${LINK_LIBS})
