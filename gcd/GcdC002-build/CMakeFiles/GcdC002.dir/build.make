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
CMAKE_SOURCE_DIR = /Users/osamu/Developer/lecture2015/gcd/GcdC002

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/osamu/Developer/lecture2015/gcd/GcdC002-build

# Include any dependencies generated for this target.
include CMakeFiles/GcdC002.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GcdC002.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GcdC002.dir/flags.make

CMakeFiles/GcdC002.dir/gcd.c.o: CMakeFiles/GcdC002.dir/flags.make
CMakeFiles/GcdC002.dir/gcd.c.o: /Users/osamu/Developer/lecture2015/gcd/GcdC002/gcd.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/gcd/GcdC002-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GcdC002.dir/gcd.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GcdC002.dir/gcd.c.o   -c /Users/osamu/Developer/lecture2015/gcd/GcdC002/gcd.c

CMakeFiles/GcdC002.dir/gcd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GcdC002.dir/gcd.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/osamu/Developer/lecture2015/gcd/GcdC002/gcd.c > CMakeFiles/GcdC002.dir/gcd.c.i

CMakeFiles/GcdC002.dir/gcd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GcdC002.dir/gcd.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/osamu/Developer/lecture2015/gcd/GcdC002/gcd.c -o CMakeFiles/GcdC002.dir/gcd.c.s

CMakeFiles/GcdC002.dir/gcd.c.o.requires:
.PHONY : CMakeFiles/GcdC002.dir/gcd.c.o.requires

CMakeFiles/GcdC002.dir/gcd.c.o.provides: CMakeFiles/GcdC002.dir/gcd.c.o.requires
	$(MAKE) -f CMakeFiles/GcdC002.dir/build.make CMakeFiles/GcdC002.dir/gcd.c.o.provides.build
.PHONY : CMakeFiles/GcdC002.dir/gcd.c.o.provides

CMakeFiles/GcdC002.dir/gcd.c.o.provides.build: CMakeFiles/GcdC002.dir/gcd.c.o

CMakeFiles/GcdC002.dir/main.cpp.o: CMakeFiles/GcdC002.dir/flags.make
CMakeFiles/GcdC002.dir/main.cpp.o: /Users/osamu/Developer/lecture2015/gcd/GcdC002/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/osamu/Developer/lecture2015/gcd/GcdC002-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GcdC002.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GcdC002.dir/main.cpp.o -c /Users/osamu/Developer/lecture2015/gcd/GcdC002/main.cpp

CMakeFiles/GcdC002.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GcdC002.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/osamu/Developer/lecture2015/gcd/GcdC002/main.cpp > CMakeFiles/GcdC002.dir/main.cpp.i

CMakeFiles/GcdC002.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GcdC002.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/osamu/Developer/lecture2015/gcd/GcdC002/main.cpp -o CMakeFiles/GcdC002.dir/main.cpp.s

CMakeFiles/GcdC002.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/GcdC002.dir/main.cpp.o.requires

CMakeFiles/GcdC002.dir/main.cpp.o.provides: CMakeFiles/GcdC002.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GcdC002.dir/build.make CMakeFiles/GcdC002.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GcdC002.dir/main.cpp.o.provides

CMakeFiles/GcdC002.dir/main.cpp.o.provides.build: CMakeFiles/GcdC002.dir/main.cpp.o

# Object files for target GcdC002
GcdC002_OBJECTS = \
"CMakeFiles/GcdC002.dir/gcd.c.o" \
"CMakeFiles/GcdC002.dir/main.cpp.o"

# External object files for target GcdC002
GcdC002_EXTERNAL_OBJECTS =

GcdC002: CMakeFiles/GcdC002.dir/gcd.c.o
GcdC002: CMakeFiles/GcdC002.dir/main.cpp.o
GcdC002: CMakeFiles/GcdC002.dir/build.make
GcdC002: CMakeFiles/GcdC002.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable GcdC002"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GcdC002.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GcdC002.dir/build: GcdC002
.PHONY : CMakeFiles/GcdC002.dir/build

CMakeFiles/GcdC002.dir/requires: CMakeFiles/GcdC002.dir/gcd.c.o.requires
CMakeFiles/GcdC002.dir/requires: CMakeFiles/GcdC002.dir/main.cpp.o.requires
.PHONY : CMakeFiles/GcdC002.dir/requires

CMakeFiles/GcdC002.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GcdC002.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GcdC002.dir/clean

CMakeFiles/GcdC002.dir/depend:
	cd /Users/osamu/Developer/lecture2015/gcd/GcdC002-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/osamu/Developer/lecture2015/gcd/GcdC002 /Users/osamu/Developer/lecture2015/gcd/GcdC002 /Users/osamu/Developer/lecture2015/gcd/GcdC002-build /Users/osamu/Developer/lecture2015/gcd/GcdC002-build /Users/osamu/Developer/lecture2015/gcd/GcdC002-build/CMakeFiles/GcdC002.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GcdC002.dir/depend

