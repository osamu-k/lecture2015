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
CMAKE_SOURCE_DIR = /Users/osamu/Developer/lecture2015/gcd/GcdCpp004

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build

# Include any dependencies generated for this target.
include CMakeFiles/GcdCpp004.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GcdCpp004.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GcdCpp004.dir/flags.make

CMakeFiles/GcdCpp004.dir/gcd.cpp.o: CMakeFiles/GcdCpp004.dir/flags.make
CMakeFiles/GcdCpp004.dir/gcd.cpp.o: /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/gcd.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GcdCpp004.dir/gcd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GcdCpp004.dir/gcd.cpp.o -c /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/gcd.cpp

CMakeFiles/GcdCpp004.dir/gcd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GcdCpp004.dir/gcd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/gcd.cpp > CMakeFiles/GcdCpp004.dir/gcd.cpp.i

CMakeFiles/GcdCpp004.dir/gcd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GcdCpp004.dir/gcd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/gcd.cpp -o CMakeFiles/GcdCpp004.dir/gcd.cpp.s

CMakeFiles/GcdCpp004.dir/gcd.cpp.o.requires:
.PHONY : CMakeFiles/GcdCpp004.dir/gcd.cpp.o.requires

CMakeFiles/GcdCpp004.dir/gcd.cpp.o.provides: CMakeFiles/GcdCpp004.dir/gcd.cpp.o.requires
	$(MAKE) -f CMakeFiles/GcdCpp004.dir/build.make CMakeFiles/GcdCpp004.dir/gcd.cpp.o.provides.build
.PHONY : CMakeFiles/GcdCpp004.dir/gcd.cpp.o.provides

CMakeFiles/GcdCpp004.dir/gcd.cpp.o.provides.build: CMakeFiles/GcdCpp004.dir/gcd.cpp.o

CMakeFiles/GcdCpp004.dir/main.cpp.o: CMakeFiles/GcdCpp004.dir/flags.make
CMakeFiles/GcdCpp004.dir/main.cpp.o: /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GcdCpp004.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GcdCpp004.dir/main.cpp.o -c /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/main.cpp

CMakeFiles/GcdCpp004.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GcdCpp004.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/main.cpp > CMakeFiles/GcdCpp004.dir/main.cpp.i

CMakeFiles/GcdCpp004.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GcdCpp004.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/gcd/GcdCpp004/main.cpp -o CMakeFiles/GcdCpp004.dir/main.cpp.s

CMakeFiles/GcdCpp004.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/GcdCpp004.dir/main.cpp.o.requires

CMakeFiles/GcdCpp004.dir/main.cpp.o.provides: CMakeFiles/GcdCpp004.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GcdCpp004.dir/build.make CMakeFiles/GcdCpp004.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GcdCpp004.dir/main.cpp.o.provides

CMakeFiles/GcdCpp004.dir/main.cpp.o.provides.build: CMakeFiles/GcdCpp004.dir/main.cpp.o

# Object files for target GcdCpp004
GcdCpp004_OBJECTS = \
"CMakeFiles/GcdCpp004.dir/gcd.cpp.o" \
"CMakeFiles/GcdCpp004.dir/main.cpp.o"

# External object files for target GcdCpp004
GcdCpp004_EXTERNAL_OBJECTS =

GcdCpp004: CMakeFiles/GcdCpp004.dir/gcd.cpp.o
GcdCpp004: CMakeFiles/GcdCpp004.dir/main.cpp.o
GcdCpp004: CMakeFiles/GcdCpp004.dir/build.make
GcdCpp004: CMakeFiles/GcdCpp004.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable GcdCpp004"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GcdCpp004.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GcdCpp004.dir/build: GcdCpp004
.PHONY : CMakeFiles/GcdCpp004.dir/build

CMakeFiles/GcdCpp004.dir/requires: CMakeFiles/GcdCpp004.dir/gcd.cpp.o.requires
CMakeFiles/GcdCpp004.dir/requires: CMakeFiles/GcdCpp004.dir/main.cpp.o.requires
.PHONY : CMakeFiles/GcdCpp004.dir/requires

CMakeFiles/GcdCpp004.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GcdCpp004.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GcdCpp004.dir/clean

CMakeFiles/GcdCpp004.dir/depend:
	cd /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/osamu/Developer/lecture2015/gcd/GcdCpp004 /Users/osamu/Developer/lecture2015/gcd/GcdCpp004 /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build /Users/osamu/Developer/lecture2015/gcd/GcdCpp004-build/CMakeFiles/GcdCpp004.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GcdCpp004.dir/depend
