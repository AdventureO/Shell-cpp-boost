# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /home/oleksandr/CLIon/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/oleksandr/CLIon/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oleksandr/newShell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleksandr/newShell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cp.dir/flags.make

CMakeFiles/cp.dir/cp.cpp.o: CMakeFiles/cp.dir/flags.make
CMakeFiles/cp.dir/cp.cpp.o: ../cp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleksandr/newShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cp.dir/cp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cp.dir/cp.cpp.o -c /home/oleksandr/newShell/cp.cpp

CMakeFiles/cp.dir/cp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cp.dir/cp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleksandr/newShell/cp.cpp > CMakeFiles/cp.dir/cp.cpp.i

CMakeFiles/cp.dir/cp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cp.dir/cp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleksandr/newShell/cp.cpp -o CMakeFiles/cp.dir/cp.cpp.s

CMakeFiles/cp.dir/cp.cpp.o.requires:

.PHONY : CMakeFiles/cp.dir/cp.cpp.o.requires

CMakeFiles/cp.dir/cp.cpp.o.provides: CMakeFiles/cp.dir/cp.cpp.o.requires
	$(MAKE) -f CMakeFiles/cp.dir/build.make CMakeFiles/cp.dir/cp.cpp.o.provides.build
.PHONY : CMakeFiles/cp.dir/cp.cpp.o.provides

CMakeFiles/cp.dir/cp.cpp.o.provides.build: CMakeFiles/cp.dir/cp.cpp.o


# Object files for target cp
cp_OBJECTS = \
"CMakeFiles/cp.dir/cp.cpp.o"

# External object files for target cp
cp_EXTERNAL_OBJECTS =

cp: CMakeFiles/cp.dir/cp.cpp.o
cp: CMakeFiles/cp.dir/build.make
cp: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
cp: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
cp: /usr/lib/x86_64-linux-gnu/libboost_system.so
cp: CMakeFiles/cp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleksandr/newShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cp.dir/build: cp

.PHONY : CMakeFiles/cp.dir/build

CMakeFiles/cp.dir/requires: CMakeFiles/cp.dir/cp.cpp.o.requires

.PHONY : CMakeFiles/cp.dir/requires

CMakeFiles/cp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cp.dir/clean

CMakeFiles/cp.dir/depend:
	cd /home/oleksandr/newShell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleksandr/newShell /home/oleksandr/newShell /home/oleksandr/newShell/cmake-build-debug /home/oleksandr/newShell/cmake-build-debug /home/oleksandr/newShell/cmake-build-debug/CMakeFiles/cp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cp.dir/depend

