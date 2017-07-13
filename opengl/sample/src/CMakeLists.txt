set (srcs
    app/main.cpp
    glad/glad.c
	shader/shader_program.cpp
	shader/shader_program.h
	shader/shader_info.h
	shader/shader_util.h
	shader/shader_util.cpp
	stb/stb_image_impl.cpp
	glsl/triangles.vert
	glsl/triangles.frag
	)
source_group_by_dir(srcs)
	
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
    dl
    glfw
    #    GLEW
)
file(COPY "${CMAKE_SOURCE_DIR}/third_party/unix/lib/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
elseif(WIN32)
set (LINK_LIBS
     ${wxWidgets_LIBRARIES}
	 glfw3dll

#	 debug glew32d
#     optimized glew32
)
configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/debug" "${CMAKE_CURRENT_BINARY_DIR}/debug")
configure_files("${CMAKE_SOURCE_DIR}/third_party/win32/bin/release" "${CMAKE_CURRENT_BINARY_DIR}/release")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
endif()
	
# add the executable
ADD_EXECUTABLE (glApp ${srcs} )
TARGET_LINK_LIBRARIES (glApp  ${LINK_LIBS})
