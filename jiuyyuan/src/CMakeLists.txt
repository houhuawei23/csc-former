cmake_minimum_required(VERSION 3.16)

project(compiler)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

aux_source_directory(. SRC_FILES)

add_subdirectory("asm")
add_subdirectory("visitor")
add_subdirectory("ir")
add_subdirectory("global")
add_subdirectory("util")
add_subdirectory("antlr4")
# add_subdirectory("error")
add_subdirectory("pass")

add_executable(compiler ${SRC_FILES})

target_link_libraries(
  compiler
  PUBLIC
  pass
  optimize
  analysis
  asm
  visitor
  ir
  global
  util
  # antlr4
  # error
  SysYParser
  # ${3RD_PARTY_LIBS}
)
