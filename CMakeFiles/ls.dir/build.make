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
include CMakeFiles/ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ls.dir/flags.make

CMakeFiles/ls.dir/ls.cpp.o: CMakeFiles/ls.dir/flags.make
CMakeFiles/ls.dir/ls.cpp.o: ../ls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleksandr/newShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ls.dir/ls.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ls.dir/ls.cpp.o -c /home/oleksandr/newShell/ls.cpp

CMakeFiles/ls.dir/ls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ls.dir/ls.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleksandr/newShell/ls.cpp > CMakeFiles/ls.dir/ls.cpp.i

CMakeFiles/ls.dir/ls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ls.dir/ls.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleksandr/newShell/ls.cpp -o CMakeFiles/ls.dir/ls.cpp.s

CMakeFiles/ls.dir/ls.cpp.o.requires:

.PHONY : CMakeFiles/ls.dir/ls.cpp.o.requires

CMakeFiles/ls.dir/ls.cpp.o.provides: CMakeFiles/ls.dir/ls.cpp.o.requires
	$(MAKE) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/ls.cpp.o.provides.build
.PHONY : CMakeFiles/ls.dir/ls.cpp.o.provides

CMakeFiles/ls.dir/ls.cpp.o.provides.build: CMakeFiles/ls.dir/ls.cpp.o


# Object files for target ls
ls_OBJECTS = \
"CMakeFiles/ls.dir/ls.cpp.o"

# External object files for target ls
ls_EXTERNAL_OBJECTS =

ls: CMakeFiles/ls.dir/ls.cpp.o
ls: CMakeFiles/ls.dir/build.make
ls: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
ls: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
ls: /usr/lib/x86_64-linux-gnu/libboost_system.so
ls: CMakeFiles/ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleksandr/newShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ls.dir/build: ls

.PHONY : CMakeFiles/ls.dir/build

CMakeFiles/ls.dir/requires: CMakeFiles/ls.dir/ls.cpp.o.requires

.PHONY : CMakeFiles/ls.dir/requires

CMakeFiles/ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ls.dir/clean

CMakeFiles/ls.dir/depend:
	cd /home/oleksandr/newShell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleksandr/newShell /home/oleksandr/newShell /home/oleksandr/newShell/cmake-build-debug /home/oleksandr/newShell/cmake-build-debug /home/oleksandr/newShell/cmake-build-debug/CMakeFiles/ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ls.dir/depend

