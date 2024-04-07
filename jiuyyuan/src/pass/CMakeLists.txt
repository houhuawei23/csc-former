cmake_minimum_required(VERSION 3.16)

project(pass)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

add_subdirectory("analysis")
add_subdirectory("optimize")

aux_source_directory(. PASS_SRC_FILES)

add_library(pass SHARED ${PASS_SRC_FILES})
