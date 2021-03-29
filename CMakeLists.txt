cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)

PROJECT(Midterm)
find_package(folly REQUIRED)
find_package(gflags REQUIRED)

# Prevent compilation in-source
if(${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
	Message(FATAL_ERROR "Source and build  directories are the same.
	Create an empty build directory,
	change into it and re-invoke cmake")
endif()

add_subdirectory(src)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/folly)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -Werror")
 

