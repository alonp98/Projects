# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Payment_Calculator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Payment_Calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Payment_Calculator.dir/flags.make

CMakeFiles/Payment_Calculator.dir/main.cpp.o: CMakeFiles/Payment_Calculator.dir/flags.make
CMakeFiles/Payment_Calculator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Payment_Calculator.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Payment_Calculator.dir/main.cpp.o -c /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/main.cpp

CMakeFiles/Payment_Calculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Payment_Calculator.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/main.cpp > CMakeFiles/Payment_Calculator.dir/main.cpp.i

CMakeFiles/Payment_Calculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Payment_Calculator.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/main.cpp -o CMakeFiles/Payment_Calculator.dir/main.cpp.s

# Object files for target Payment_Calculator
Payment_Calculator_OBJECTS = \
"CMakeFiles/Payment_Calculator.dir/main.cpp.o"

# External object files for target Payment_Calculator
Payment_Calculator_EXTERNAL_OBJECTS =

Payment_Calculator: CMakeFiles/Payment_Calculator.dir/main.cpp.o
Payment_Calculator: CMakeFiles/Payment_Calculator.dir/build.make
Payment_Calculator: CMakeFiles/Payment_Calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Payment_Calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Payment_Calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Payment_Calculator.dir/build: Payment_Calculator
.PHONY : CMakeFiles/Payment_Calculator.dir/build

CMakeFiles/Payment_Calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Payment_Calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Payment_Calculator.dir/clean

CMakeFiles/Payment_Calculator.dir/depend:
	cd /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug /Users/alon/Desktop/Programming/CPP/Projects/Payment_Calculator/cmake-build-debug/CMakeFiles/Payment_Calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Payment_Calculator.dir/depend

