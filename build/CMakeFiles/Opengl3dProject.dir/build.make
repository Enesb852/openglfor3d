# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/enes/openglfor3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/enes/openglfor3d/build

# Include any dependencies generated for this target.
include CMakeFiles/Opengl3dProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Opengl3dProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Opengl3dProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Opengl3dProject.dir/flags.make

CMakeFiles/Opengl3dProject.dir/src/main.cpp.o: CMakeFiles/Opengl3dProject.dir/flags.make
CMakeFiles/Opengl3dProject.dir/src/main.cpp.o: /home/enes/openglfor3d/src/main.cpp
CMakeFiles/Opengl3dProject.dir/src/main.cpp.o: CMakeFiles/Opengl3dProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/enes/openglfor3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Opengl3dProject.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Opengl3dProject.dir/src/main.cpp.o -MF CMakeFiles/Opengl3dProject.dir/src/main.cpp.o.d -o CMakeFiles/Opengl3dProject.dir/src/main.cpp.o -c /home/enes/openglfor3d/src/main.cpp

CMakeFiles/Opengl3dProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Opengl3dProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/enes/openglfor3d/src/main.cpp > CMakeFiles/Opengl3dProject.dir/src/main.cpp.i

CMakeFiles/Opengl3dProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Opengl3dProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/enes/openglfor3d/src/main.cpp -o CMakeFiles/Opengl3dProject.dir/src/main.cpp.s

# Object files for target Opengl3dProject
Opengl3dProject_OBJECTS = \
"CMakeFiles/Opengl3dProject.dir/src/main.cpp.o"

# External object files for target Opengl3dProject
Opengl3dProject_EXTERNAL_OBJECTS =

Opengl3dProject: CMakeFiles/Opengl3dProject.dir/src/main.cpp.o
Opengl3dProject: CMakeFiles/Opengl3dProject.dir/build.make
Opengl3dProject: /usr/lib/libglfw.so.3.4
Opengl3dProject: libglad.a
Opengl3dProject: /usr/lib/libGLX.so
Opengl3dProject: /usr/lib/libOpenGL.so
Opengl3dProject: CMakeFiles/Opengl3dProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/enes/openglfor3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Opengl3dProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Opengl3dProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Opengl3dProject.dir/build: Opengl3dProject
.PHONY : CMakeFiles/Opengl3dProject.dir/build

CMakeFiles/Opengl3dProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Opengl3dProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Opengl3dProject.dir/clean

CMakeFiles/Opengl3dProject.dir/depend:
	cd /home/enes/openglfor3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/enes/openglfor3d /home/enes/openglfor3d /home/enes/openglfor3d/build /home/enes/openglfor3d/build /home/enes/openglfor3d/build/CMakeFiles/Opengl3dProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Opengl3dProject.dir/depend

