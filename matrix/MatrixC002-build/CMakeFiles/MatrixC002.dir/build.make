# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/osamu/Developer/lecture2015/matrix/MatrixC002

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build

# Include any dependencies generated for this target.
include CMakeFiles/MatrixC002.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MatrixC002.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MatrixC002.dir/flags.make

CMakeFiles/MatrixC002.dir/main.cpp.o: CMakeFiles/MatrixC002.dir/flags.make
CMakeFiles/MatrixC002.dir/main.cpp.o: /Users/osamu/Developer/lecture2015/matrix/MatrixC002/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MatrixC002.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MatrixC002.dir/main.cpp.o -c /Users/osamu/Developer/lecture2015/matrix/MatrixC002/main.cpp

CMakeFiles/MatrixC002.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatrixC002.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/matrix/MatrixC002/main.cpp > CMakeFiles/MatrixC002.dir/main.cpp.i

CMakeFiles/MatrixC002.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatrixC002.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/matrix/MatrixC002/main.cpp -o CMakeFiles/MatrixC002.dir/main.cpp.s

CMakeFiles/MatrixC002.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/MatrixC002.dir/main.cpp.o.requires

CMakeFiles/MatrixC002.dir/main.cpp.o.provides: CMakeFiles/MatrixC002.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MatrixC002.dir/build.make CMakeFiles/MatrixC002.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MatrixC002.dir/main.cpp.o.provides

CMakeFiles/MatrixC002.dir/main.cpp.o.provides.build: CMakeFiles/MatrixC002.dir/main.cpp.o

CMakeFiles/MatrixC002.dir/matrix.c.o: CMakeFiles/MatrixC002.dir/flags.make
CMakeFiles/MatrixC002.dir/matrix.c.o: /Users/osamu/Developer/lecture2015/matrix/MatrixC002/matrix.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/MatrixC002.dir/matrix.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/MatrixC002.dir/matrix.c.o   -c /Users/osamu/Developer/lecture2015/matrix/MatrixC002/matrix.c

CMakeFiles/MatrixC002.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MatrixC002.dir/matrix.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/osamu/Developer/lecture2015/matrix/MatrixC002/matrix.c > CMakeFiles/MatrixC002.dir/matrix.c.i

CMakeFiles/MatrixC002.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MatrixC002.dir/matrix.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/osamu/Developer/lecture2015/matrix/MatrixC002/matrix.c -o CMakeFiles/MatrixC002.dir/matrix.c.s

CMakeFiles/MatrixC002.dir/matrix.c.o.requires:
.PHONY : CMakeFiles/MatrixC002.dir/matrix.c.o.requires

CMakeFiles/MatrixC002.dir/matrix.c.o.provides: CMakeFiles/MatrixC002.dir/matrix.c.o.requires
	$(MAKE) -f CMakeFiles/MatrixC002.dir/build.make CMakeFiles/MatrixC002.dir/matrix.c.o.provides.build
.PHONY : CMakeFiles/MatrixC002.dir/matrix.c.o.provides

CMakeFiles/MatrixC002.dir/matrix.c.o.provides.build: CMakeFiles/MatrixC002.dir/matrix.c.o

# Object files for target MatrixC002
MatrixC002_OBJECTS = \
"CMakeFiles/MatrixC002.dir/main.cpp.o" \
"CMakeFiles/MatrixC002.dir/matrix.c.o"

# External object files for target MatrixC002
MatrixC002_EXTERNAL_OBJECTS =

MatrixC002: CMakeFiles/MatrixC002.dir/main.cpp.o
MatrixC002: CMakeFiles/MatrixC002.dir/matrix.c.o
MatrixC002: CMakeFiles/MatrixC002.dir/build.make
MatrixC002: CMakeFiles/MatrixC002.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MatrixC002"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MatrixC002.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MatrixC002.dir/build: MatrixC002
.PHONY : CMakeFiles/MatrixC002.dir/build

CMakeFiles/MatrixC002.dir/requires: CMakeFiles/MatrixC002.dir/main.cpp.o.requires
CMakeFiles/MatrixC002.dir/requires: CMakeFiles/MatrixC002.dir/matrix.c.o.requires
.PHONY : CMakeFiles/MatrixC002.dir/requires

CMakeFiles/MatrixC002.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MatrixC002.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MatrixC002.dir/clean

CMakeFiles/MatrixC002.dir/depend:
	cd /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/osamu/Developer/lecture2015/matrix/MatrixC002 /Users/osamu/Developer/lecture2015/matrix/MatrixC002 /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build /Users/osamu/Developer/lecture2015/matrix/MatrixC002-build/CMakeFiles/MatrixC002.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MatrixC002.dir/depend

