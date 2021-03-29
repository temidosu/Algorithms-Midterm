cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 20) #std::ranges

PROJECT(Midterm)

# Prevent compilation in-source
if(${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
	Message(FATAL_ERROR "Source and build  directories are the same.
	Create an empty build directory,
	change into it and re-invoke cmake")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -Werror")


add_subdirectory(src)