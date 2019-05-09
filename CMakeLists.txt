cmake_minimum_required(VERSION 3.9)
# Require Modern C++
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engine)

### Setup Directories ###
# Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Output all DLLs from all libs into main build folder
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

### Add External Dependencies ###
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

### Engine Library ###
file(GLOB_RECURSE SOURCE_FILES engine/Code/*.cpp engine/Code/*.h)
add_library(lib_engine STATIC ${SOURCE_FILES})
target_include_directories(lib_engine INTERFACE "${CMAKE_SOURCE_DIR}/lib_engine" )
target_link_libraries(lib_engine sfml-graphics)

### Code ###
file(GLOB_RECURSE SOURCES Code/*.cpp Code/*.h)
file(GLOB_RECURSE SOURCES Code/*.cpp Code/*.h)
add_executable(Games_Engine ${SOURCES})
target_include_directories(Games_Engine PRIVATE ${SFML_INCS})
target_link_libraries(Games_Engine sfml-graphics lib_engine)

#set working directory to build directory
set_target_properties(${exe} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)