cmake_minimum_required(VERSION 3.16)

project(global)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

aux_source_directory(. GLOBAL_SRC_FILES)

add_library(global SHARED ${GLOBAL_SRC_FILES})
