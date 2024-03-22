cmake_minimum_required(VERSION 3.16)

project(util)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")

aux_source_directory(. UTIL_SRC_FILES)

add_library(util SHARED ${UTIL_SRC_FILES})
