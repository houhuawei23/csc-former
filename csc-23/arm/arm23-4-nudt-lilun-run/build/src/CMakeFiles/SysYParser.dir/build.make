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
include src/CMakeFiles/SysYParser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/SysYParser.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SysYParser.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SysYParser.dir/flags.make

src/SysYLexer.interp: ../src/SysY.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building SysYGen with ANTLR 4.12.0"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src && /usr/bin/java -jar /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/antlr/antlr-4.12.0-complete.jar SysY.g4 -o /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src -no-listener -Dlanguage=Cpp -visitor

src/SysYLexer.tokens: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYLexer.tokens

src/SysYLexer.h: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYLexer.h

src/SysYLexer.cpp: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYLexer.cpp

src/SysYParser.h: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYParser.h

src/SysYParser.cpp: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYParser.cpp

src/SysYBaseVisitor.h: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYBaseVisitor.h

src/SysYBaseVisitor.cpp: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYBaseVisitor.cpp

src/SysYVisitor.h: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYVisitor.h

src/SysYVisitor.cpp: src/SysYLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/SysYVisitor.cpp

src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o: src/CMakeFiles/SysYParser.dir/flags.make
src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o: src/SysYLexer.cpp
src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o: src/CMakeFiles/SysYParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o -MF CMakeFiles/SysYParser.dir/SysYLexer.cpp.o.d -o CMakeFiles/SysYParser.dir/SysYLexer.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYLexer.cpp

src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SysYParser.dir/SysYLexer.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYLexer.cpp > CMakeFiles/SysYParser.dir/SysYLexer.cpp.i

src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SysYParser.dir/SysYLexer.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYLexer.cpp -o CMakeFiles/SysYParser.dir/SysYLexer.cpp.s

src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o: src/CMakeFiles/SysYParser.dir/flags.make
src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o: src/SysYParser.cpp
src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o: src/CMakeFiles/SysYParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o -MF CMakeFiles/SysYParser.dir/SysYParser.cpp.o.d -o CMakeFiles/SysYParser.dir/SysYParser.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYParser.cpp

src/CMakeFiles/SysYParser.dir/SysYParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SysYParser.dir/SysYParser.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYParser.cpp > CMakeFiles/SysYParser.dir/SysYParser.cpp.i

src/CMakeFiles/SysYParser.dir/SysYParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SysYParser.dir/SysYParser.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYParser.cpp -o CMakeFiles/SysYParser.dir/SysYParser.cpp.s

src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o: src/CMakeFiles/SysYParser.dir/flags.make
src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o: src/SysYBaseVisitor.cpp
src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o: src/CMakeFiles/SysYParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o -MF CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o.d -o CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYBaseVisitor.cpp

src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYBaseVisitor.cpp > CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.i

src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYBaseVisitor.cpp -o CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.s

src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o: src/CMakeFiles/SysYParser.dir/flags.make
src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o: src/SysYVisitor.cpp
src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o: src/CMakeFiles/SysYParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o -MF CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o.d -o CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o -c /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYVisitor.cpp

src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SysYParser.dir/SysYVisitor.cpp.i"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYVisitor.cpp > CMakeFiles/SysYParser.dir/SysYVisitor.cpp.i

src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SysYParser.dir/SysYVisitor.cpp.s"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/SysYVisitor.cpp -o CMakeFiles/SysYParser.dir/SysYVisitor.cpp.s

# Object files for target SysYParser
SysYParser_OBJECTS = \
"CMakeFiles/SysYParser.dir/SysYLexer.cpp.o" \
"CMakeFiles/SysYParser.dir/SysYParser.cpp.o" \
"CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o" \
"CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o"

# External object files for target SysYParser
SysYParser_EXTERNAL_OBJECTS =

lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/SysYLexer.cpp.o
lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/SysYParser.cpp.o
lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/SysYBaseVisitor.cpp.o
lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/SysYVisitor.cpp.o
lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/build.make
lib/libSysYParser.so: lib/libantlr4-runtime.so.4.12.0
lib/libSysYParser.so: src/CMakeFiles/SysYParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../lib/libSysYParser.so"
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SysYParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SysYParser.dir/build: lib/libSysYParser.so
.PHONY : src/CMakeFiles/SysYParser.dir/build

src/CMakeFiles/SysYParser.dir/clean:
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SysYParser.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SysYParser.dir/clean

src/CMakeFiles/SysYParser.dir/depend: src/SysYBaseVisitor.cpp
src/CMakeFiles/SysYParser.dir/depend: src/SysYBaseVisitor.h
src/CMakeFiles/SysYParser.dir/depend: src/SysYLexer.cpp
src/CMakeFiles/SysYParser.dir/depend: src/SysYLexer.h
src/CMakeFiles/SysYParser.dir/depend: src/SysYLexer.interp
src/CMakeFiles/SysYParser.dir/depend: src/SysYLexer.tokens
src/CMakeFiles/SysYParser.dir/depend: src/SysYParser.cpp
src/CMakeFiles/SysYParser.dir/depend: src/SysYParser.h
src/CMakeFiles/SysYParser.dir/depend: src/SysYVisitor.cpp
src/CMakeFiles/SysYParser.dir/depend: src/SysYVisitor.h
	cd /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/src /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/src/CMakeFiles/SysYParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/SysYParser.dir/depend
