# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.4

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug

# Include any dependencies generated for this target.
include CMakeFiles/CurveAssignment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CurveAssignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CurveAssignment.dir/flags.make

CMakeFiles/CurveAssignment.dir/main.cpp.obj: CMakeFiles/CurveAssignment.dir/flags.make
CMakeFiles/CurveAssignment.dir/main.cpp.obj: C:/Users/Ned/Documents/_Programming/C++/_Graphics/CurveAssignment/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CurveAssignment.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CurveAssignment.dir\main.cpp.obj -c C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment\main.cpp

CMakeFiles/CurveAssignment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CurveAssignment.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment\main.cpp > CMakeFiles\CurveAssignment.dir\main.cpp.i

CMakeFiles/CurveAssignment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CurveAssignment.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment\main.cpp -o CMakeFiles\CurveAssignment.dir\main.cpp.s

CMakeFiles/CurveAssignment.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/CurveAssignment.dir/main.cpp.obj.requires

CMakeFiles/CurveAssignment.dir/main.cpp.obj.provides: CMakeFiles/CurveAssignment.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CurveAssignment.dir\build.make CMakeFiles/CurveAssignment.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CurveAssignment.dir/main.cpp.obj.provides

CMakeFiles/CurveAssignment.dir/main.cpp.obj.provides.build: CMakeFiles/CurveAssignment.dir/main.cpp.obj


# Object files for target CurveAssignment
CurveAssignment_OBJECTS = \
"CMakeFiles/CurveAssignment.dir/main.cpp.obj"

# External object files for target CurveAssignment
CurveAssignment_EXTERNAL_OBJECTS =

CurveAssignment.exe: CMakeFiles/CurveAssignment.dir/main.cpp.obj
CurveAssignment.exe: CMakeFiles/CurveAssignment.dir/build.make
CurveAssignment.exe: C:/MinGW/lib/glut32.lib
CurveAssignment.exe: CMakeFiles/CurveAssignment.dir/linklibs.rsp
CurveAssignment.exe: CMakeFiles/CurveAssignment.dir/objects1.rsp
CurveAssignment.exe: CMakeFiles/CurveAssignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CurveAssignment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CurveAssignment.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CurveAssignment.dir/build: CurveAssignment.exe

.PHONY : CMakeFiles/CurveAssignment.dir/build

CMakeFiles/CurveAssignment.dir/requires: CMakeFiles/CurveAssignment.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/CurveAssignment.dir/requires

CMakeFiles/CurveAssignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CurveAssignment.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CurveAssignment.dir/clean

CMakeFiles/CurveAssignment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment C:\Users\Ned\Documents\_Programming\C++\_Graphics\CurveAssignment C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug C:\Users\Ned\.CLion12\system\cmake\generated\109e547b\109e547b\Debug\CMakeFiles\CurveAssignment.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CurveAssignment.dir/depend

