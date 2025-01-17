# Install script for directory: /home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/antlr/antlr4-runtime

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/runtime/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime/antlr4-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime/antlr4-targets.cmake"
         "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/CMakeFiles/Export/lib/cmake/antlr4-runtime/antlr4-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime/antlr4-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime/antlr4-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime" TYPE FILE FILES "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/CMakeFiles/Export/lib/cmake/antlr4-runtime/antlr4-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime" TYPE FILE FILES "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/CMakeFiles/Export/lib/cmake/antlr4-runtime/antlr4-targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-runtime" TYPE FILE FILES
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/antlr4-runtime-config.cmake"
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/antlr4-runtime-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/antlr4-generator" TYPE FILE FILES
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/antlr4-generator-config.cmake"
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/build/antlr/antlr4-runtime/antlr4-generator-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libantlr4" TYPE FILE FILES
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/antlr/antlr4-runtime/README.md"
    "/home/hhw/compilers/csc-former/csc-23/arm/arm23-4-nudt-lilun-run/antlr/antlr4-runtime/VERSION"
    )
endif()

