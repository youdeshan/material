set (app_srcs
	app/main.cpp
	)
source_group(app FILES ${app_srcs})
set (srcs ${srcs} ${app_srcs})
	
set (LINK_LIBS
	${wxWidgets_LIBRARIES}
	)
	
# add the executable
ADD_EXECUTABLE (glApp ${srcs} )
TARGET_LINK_LIBRARIES (glApp  ${LINK_LIBS})
