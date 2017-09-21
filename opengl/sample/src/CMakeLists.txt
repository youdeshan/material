set (srcs
	app/app.cpp
	app/app.h
	app/main_frame.cpp
	app/main_frame.h
	app/gl_canvas.cpp
	app/gl_canvas.h
	
	glad/glad.c
	shader/shader_program.cpp
	shader/shader_program.h
	shader/shader_info.h
	shader/shader_util.h
	shader/shader_util.cpp
	camera/camera.h
	camera/camera.cpp
	stb/stb_image_impl.cpp
	glsl/triangles.vert
	glsl/triangles.frag

	drawing/render/renderer.h
	drawing/render/renderer.cpp
	drawing/render/gl_renderer.h
	drawing/render/gl_renderer.cpp

	drawing/context/context.h
	drawing/context/gl_context.h
	drawing/context/gl_context.cpp

	drawing/scene/node.h
	drawing/scene/graph.h
	drawing/scene/graph.cpp
	drawing/scene/drawable.h
	drawing/scene/drawable.cpp
	)
source_group_by_dir(srcs)

set (LINK_LIBS
	${wxWidgets_LIBRARIES}
)

if(UNIX)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
elseif(WIN32)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/glsl" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/debug")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/release")
endif()	
	
# add the executable
ADD_EXECUTABLE (HelloGL WIN32 ${srcs} )
TARGET_LINK_LIBRARIES (HelloGL  ${LINK_LIBS})
