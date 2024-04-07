cmake_minimum_required(VERSION 3.16)

project(optimize)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

aux_source_directory(. PASS_SRC_FILES)

add_library(optimize SHARED ${PASS_SRC_FILES})
