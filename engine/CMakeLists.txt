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

### Main Project ###
file(GLOB_RECURSE SOURCES Code/*.cpp Code/*.h)
add_executable(Games_Engine ${SOURCES})
target_include_directories(Games_Engine PRIVATE ${SFML_INCS})

#set working directory to build directory
set_target_properties(${exe} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)