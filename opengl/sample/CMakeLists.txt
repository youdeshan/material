cmake_minimum_required(VERSION 2.8)
PROJECT(HelloGL)

include("${PROJECT_SOURCE_DIR}/macro.cmake")

# Find Boost
find_package(Boost)
if(Boost_FOUND)
    message(STATUS "boost all required components are found.")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else(Boost_FOUND)
    message("some of the required boost components are NOT found.")
    find_package(Boost)
    if(Boost_FOUND)
        message(STATUS "boost header only is found.")
        include_directories(${Boost_INCLUDE_DIRS})
    endif()
endif(Boost_FOUND)

# Find wxWidgets
find_package(wxWidgets COMPONENTS core base adv xml net qa xrc html gl)
include(${wxWidgets_USE_FILE})

# set include search paths
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/third_party/include)

if(UNIX)
    # UNIX will not define _DEBUG as default
    if(CMAKE_BUILD_TYPE STREQUAL Debug)
        add_definitions(-D_DEBUG)
    endif()
endif()

# Close CRT secure warnings.
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)

# Build in Unicode.
add_definitions(-DUNICODE -D_UNICODE)

add_subdirectory(src)
