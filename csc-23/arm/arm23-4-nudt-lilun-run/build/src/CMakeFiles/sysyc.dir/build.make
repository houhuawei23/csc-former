# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build

# Include any dependencies generated for this target.
include src/CMakeFiles/sysyc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/sysyc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sysyc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/sysyc.dir/flags.make

src/CMakeFiles/sysyc.dir/sysy.cpp.o: src/CMakeFiles/sysyc.dir/flags.make
src/CMakeFiles/sysyc.dir/sysy.cpp.o: ../src/sysy.cpp
src/CMakeFiles/sysyc.dir/sysy.cpp.o: src/CMakeFiles/sysyc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/sysyc.dir/sysy.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/sysyc.dir/sysy.cpp.o -MF CMakeFiles/sysyc.dir/sysy.cpp.o.d -o CMakeFiles/sysyc.dir/sysy.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/sysy.cpp

src/CMakeFiles/sysyc.dir/sysy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sysyc.dir/sysy.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/sysy.cpp > CMakeFiles/sysyc.dir/sysy.cpp.i

src/CMakeFiles/sysyc.dir/sysy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sysyc.dir/sysy.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/sysy.cpp -o CMakeFiles/sysyc.dir/sysy.cpp.s

src/CMakeFiles/sysyc.dir/IR.cpp.o: src/CMakeFiles/sysyc.dir/flags.make
src/CMakeFiles/sysyc.dir/IR.cpp.o: ../src/IR.cpp
src/CMakeFiles/sysyc.dir/IR.cpp.o: src/CMakeFiles/sysyc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/sysyc.dir/IR.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/sysyc.dir/IR.cpp.o -MF CMakeFiles/sysyc.dir/IR.cpp.o.d -o CMakeFiles/sysyc.dir/IR.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/IR.cpp

src/CMakeFiles/sysyc.dir/IR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sysyc.dir/IR.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/IR.cpp > CMakeFiles/sysyc.dir/IR.cpp.i

src/CMakeFiles/sysyc.dir/IR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sysyc.dir/IR.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/IR.cpp -o CMakeFiles/sysyc.dir/IR.cpp.s

src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o: src/CMakeFiles/sysyc.dir/flags.make
src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o: ../src/SysYIRGenerator.cpp
src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o: src/CMakeFiles/sysyc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o -MF CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o.d -o CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/SysYIRGenerator.cpp

src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/SysYIRGenerator.cpp > CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.i

src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/SysYIRGenerator.cpp -o CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.s

src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o: src/CMakeFiles/sysyc.dir/flags.make
src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o: ../src/Diagnostic.cpp
src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o: src/CMakeFiles/sysyc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o -MF CMakeFiles/sysyc.dir/Diagnostic.cpp.o.d -o CMakeFiles/sysyc.dir/Diagnostic.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/Diagnostic.cpp

src/CMakeFiles/sysyc.dir/Diagnostic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sysyc.dir/Diagnostic.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/Diagnostic.cpp > CMakeFiles/sysyc.dir/Diagnostic.cpp.i

src/CMakeFiles/sysyc.dir/Diagnostic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sysyc.dir/Diagnostic.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/Diagnostic.cpp -o CMakeFiles/sysyc.dir/Diagnostic.cpp.s

src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o: src/CMakeFiles/sysyc.dir/flags.make
src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o: ../src/backend/codegen.cpp
src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o: src/CMakeFiles/sysyc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o -MF CMakeFiles/sysyc.dir/backend/codegen.cpp.o.d -o CMakeFiles/sysyc.dir/backend/codegen.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/backend/codegen.cpp

src/CMakeFiles/sysyc.dir/backend/codegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sysyc.dir/backend/codegen.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/backend/codegen.cpp > CMakeFiles/sysyc.dir/backend/codegen.cpp.i

src/CMakeFiles/sysyc.dir/backend/codegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sysyc.dir/backend/codegen.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src/backend/codegen.cpp -o CMakeFiles/sysyc.dir/backend/codegen.cpp.s

# Object files for target sysyc
sysyc_OBJECTS = \
"CMakeFiles/sysyc.dir/sysy.cpp.o" \
"CMakeFiles/sysyc.dir/IR.cpp.o" \
"CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o" \
"CMakeFiles/sysyc.dir/Diagnostic.cpp.o" \
"CMakeFiles/sysyc.dir/backend/codegen.cpp.o"

# External object files for target sysyc
sysyc_EXTERNAL_OBJECTS =

../sysyc: src/CMakeFiles/sysyc.dir/sysy.cpp.o
../sysyc: src/CMakeFiles/sysyc.dir/IR.cpp.o
../sysyc: src/CMakeFiles/sysyc.dir/SysYIRGenerator.cpp.o
../sysyc: src/CMakeFiles/sysyc.dir/Diagnostic.cpp.o
../sysyc: src/CMakeFiles/sysyc.dir/backend/codegen.cpp.o
../sysyc: src/CMakeFiles/sysyc.dir/build.make
../sysyc: lib/libSysYParser.so
../sysyc: lib/libantlr4-runtime.so.4.12.0
../sysyc: src/CMakeFiles/sysyc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../sysyc"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sysyc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/sysyc.dir/build: ../sysyc
.PHONY : src/CMakeFiles/sysyc.dir/build

src/CMakeFiles/sysyc.dir/clean:
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && $(CMAKE_COMMAND) -P CMakeFiles/sysyc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/sysyc.dir/clean

src/CMakeFiles/sysyc.dir/depend:
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/CMakeFiles/sysyc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sysyc.dir/depend
