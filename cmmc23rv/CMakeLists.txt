cmake_minimum_required(VERSION 3.10)
project(YOUR_PROJECT_NAME)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Source files
file(GLOB_RECURSE SOURCES
    "cmmc/*.cpp"
    "cmmc/Transforms/*.cpp"
    "cmmc/Frontend/Support/*.cpp"
    "cmmc/Target/*.cpp"
)

# Executable target
add_executable(compiler ${SOURCES})

# Link against m library
target_link_libraries(compiler m)