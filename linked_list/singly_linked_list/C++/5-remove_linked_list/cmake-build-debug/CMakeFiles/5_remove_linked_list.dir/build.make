# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/asli/Downloads/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/asli/Downloads/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5_remove_linked_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_remove_linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_remove_linked_list.dir/flags.make

CMakeFiles/5_remove_linked_list.dir/main.cpp.o: CMakeFiles/5_remove_linked_list.dir/flags.make
CMakeFiles/5_remove_linked_list.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5_remove_linked_list.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/5_remove_linked_list.dir/main.cpp.o -c /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/main.cpp

CMakeFiles/5_remove_linked_list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5_remove_linked_list.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/main.cpp > CMakeFiles/5_remove_linked_list.dir/main.cpp.i

CMakeFiles/5_remove_linked_list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5_remove_linked_list.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/main.cpp -o CMakeFiles/5_remove_linked_list.dir/main.cpp.s

# Object files for target 5_remove_linked_list
5_remove_linked_list_OBJECTS = \
"CMakeFiles/5_remove_linked_list.dir/main.cpp.o"

# External object files for target 5_remove_linked_list
5_remove_linked_list_EXTERNAL_OBJECTS =

5_remove_linked_list: CMakeFiles/5_remove_linked_list.dir/main.cpp.o
5_remove_linked_list: CMakeFiles/5_remove_linked_list.dir/build.make
5_remove_linked_list: CMakeFiles/5_remove_linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5_remove_linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5_remove_linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_remove_linked_list.dir/build: 5_remove_linked_list

.PHONY : CMakeFiles/5_remove_linked_list.dir/build

CMakeFiles/5_remove_linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5_remove_linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5_remove_linked_list.dir/clean

CMakeFiles/5_remove_linked_list.dir/depend:
	cd /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug /home/asli/Documents/boost_calismalar/veri_yapilari/linked_list/singly_linked_list/C++/5-remove_linked_list/cmake-build-debug/CMakeFiles/5_remove_linked_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5_remove_linked_list.dir/depend

