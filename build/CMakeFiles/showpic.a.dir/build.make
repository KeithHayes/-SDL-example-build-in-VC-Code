# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kdog/Code/gcc/showpic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kdog/Code/gcc/showpic/build

# Include any dependencies generated for this target.
include CMakeFiles/showpic.a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/showpic.a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/showpic.a.dir/flags.make

CMakeFiles/showpic.a.dir/src/main.cpp.o: CMakeFiles/showpic.a.dir/flags.make
CMakeFiles/showpic.a.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kdog/Code/gcc/showpic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/showpic.a.dir/src/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/showpic.a.dir/src/main.cpp.o -c /home/kdog/Code/gcc/showpic/src/main.cpp

CMakeFiles/showpic.a.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/showpic.a.dir/src/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kdog/Code/gcc/showpic/src/main.cpp > CMakeFiles/showpic.a.dir/src/main.cpp.i

CMakeFiles/showpic.a.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/showpic.a.dir/src/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kdog/Code/gcc/showpic/src/main.cpp -o CMakeFiles/showpic.a.dir/src/main.cpp.s

CMakeFiles/showpic.a.dir/src/picwindow.cpp.o: CMakeFiles/showpic.a.dir/flags.make
CMakeFiles/showpic.a.dir/src/picwindow.cpp.o: ../src/picwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kdog/Code/gcc/showpic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/showpic.a.dir/src/picwindow.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/showpic.a.dir/src/picwindow.cpp.o -c /home/kdog/Code/gcc/showpic/src/picwindow.cpp

CMakeFiles/showpic.a.dir/src/picwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/showpic.a.dir/src/picwindow.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kdog/Code/gcc/showpic/src/picwindow.cpp > CMakeFiles/showpic.a.dir/src/picwindow.cpp.i

CMakeFiles/showpic.a.dir/src/picwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/showpic.a.dir/src/picwindow.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kdog/Code/gcc/showpic/src/picwindow.cpp -o CMakeFiles/showpic.a.dir/src/picwindow.cpp.s

# Object files for target showpic.a
showpic_a_OBJECTS = \
"CMakeFiles/showpic.a.dir/src/main.cpp.o" \
"CMakeFiles/showpic.a.dir/src/picwindow.cpp.o"

# External object files for target showpic.a
showpic_a_EXTERNAL_OBJECTS =

showpic.a: CMakeFiles/showpic.a.dir/src/main.cpp.o
showpic.a: CMakeFiles/showpic.a.dir/src/picwindow.cpp.o
showpic.a: CMakeFiles/showpic.a.dir/build.make
showpic.a: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
showpic.a: /usr/lib/x86_64-linux-gnu/libSDL2.so
showpic.a: CMakeFiles/showpic.a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kdog/Code/gcc/showpic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable showpic.a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/showpic.a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/showpic.a.dir/build: showpic.a

.PHONY : CMakeFiles/showpic.a.dir/build

CMakeFiles/showpic.a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/showpic.a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/showpic.a.dir/clean

CMakeFiles/showpic.a.dir/depend:
	cd /home/kdog/Code/gcc/showpic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kdog/Code/gcc/showpic /home/kdog/Code/gcc/showpic /home/kdog/Code/gcc/showpic/build /home/kdog/Code/gcc/showpic/build /home/kdog/Code/gcc/showpic/build/CMakeFiles/showpic.a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/showpic.a.dir/depend
