cmake_minimum_required(VERSION 3.16)

project(asm)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")

aux_source_directory(. ASM_SRC_FILES)

add_library(asm SHARED ${ASM_SRC_FILES})

target_link_libraries(asm PUBLIC)
