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
CMAKE_SOURCE_DIR = /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build

# Include any dependencies generated for this target.
include CMakeFiles/MatrixCpp001.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MatrixCpp001.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MatrixCpp001.dir/flags.make

CMakeFiles/MatrixCpp001.dir/main.cpp.o: CMakeFiles/MatrixCpp001.dir/flags.make
CMakeFiles/MatrixCpp001.dir/main.cpp.o: /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MatrixCpp001.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MatrixCpp001.dir/main.cpp.o -c /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/main.cpp

CMakeFiles/MatrixCpp001.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatrixCpp001.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/main.cpp > CMakeFiles/MatrixCpp001.dir/main.cpp.i

CMakeFiles/MatrixCpp001.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatrixCpp001.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/main.cpp -o CMakeFiles/MatrixCpp001.dir/main.cpp.s

CMakeFiles/MatrixCpp001.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/MatrixCpp001.dir/main.cpp.o.requires

CMakeFiles/MatrixCpp001.dir/main.cpp.o.provides: CMakeFiles/MatrixCpp001.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MatrixCpp001.dir/build.make CMakeFiles/MatrixCpp001.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MatrixCpp001.dir/main.cpp.o.provides

CMakeFiles/MatrixCpp001.dir/main.cpp.o.provides.build: CMakeFiles/MatrixCpp001.dir/main.cpp.o

CMakeFiles/MatrixCpp001.dir/matrix.cpp.o: CMakeFiles/MatrixCpp001.dir/flags.make
CMakeFiles/MatrixCpp001.dir/matrix.cpp.o: /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/matrix.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MatrixCpp001.dir/matrix.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MatrixCpp001.dir/matrix.cpp.o -c /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/matrix.cpp

CMakeFiles/MatrixCpp001.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatrixCpp001.dir/matrix.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/matrix.cpp > CMakeFiles/MatrixCpp001.dir/matrix.cpp.i

CMakeFiles/MatrixCpp001.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatrixCpp001.dir/matrix.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001/matrix.cpp -o CMakeFiles/MatrixCpp001.dir/matrix.cpp.s

CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.requires:
.PHONY : CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.requires

CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.provides: CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/MatrixCpp001.dir/build.make CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.provides.build
.PHONY : CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.provides

CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.provides.build: CMakeFiles/MatrixCpp001.dir/matrix.cpp.o

# Object files for target MatrixCpp001
MatrixCpp001_OBJECTS = \
"CMakeFiles/MatrixCpp001.dir/main.cpp.o" \
"CMakeFiles/MatrixCpp001.dir/matrix.cpp.o"

# External object files for target MatrixCpp001
MatrixCpp001_EXTERNAL_OBJECTS =

MatrixCpp001: CMakeFiles/MatrixCpp001.dir/main.cpp.o
MatrixCpp001: CMakeFiles/MatrixCpp001.dir/matrix.cpp.o
MatrixCpp001: CMakeFiles/MatrixCpp001.dir/build.make
MatrixCpp001: CMakeFiles/MatrixCpp001.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MatrixCpp001"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MatrixCpp001.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MatrixCpp001.dir/build: MatrixCpp001
.PHONY : CMakeFiles/MatrixCpp001.dir/build

CMakeFiles/MatrixCpp001.dir/requires: CMakeFiles/MatrixCpp001.dir/main.cpp.o.requires
CMakeFiles/MatrixCpp001.dir/requires: CMakeFiles/MatrixCpp001.dir/matrix.cpp.o.requires
.PHONY : CMakeFiles/MatrixCpp001.dir/requires

CMakeFiles/MatrixCpp001.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MatrixCpp001.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MatrixCpp001.dir/clean

CMakeFiles/MatrixCpp001.dir/depend:
	cd /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001 /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001 /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build /Users/osamu/Developer/lecture2015/matrix/MatrixCpp001-build/CMakeFiles/MatrixCpp001.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MatrixCpp001.dir/depend
