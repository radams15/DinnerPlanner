# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/rhys/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rhys/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DinnerPlanner_Gui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DinnerPlanner_Gui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DinnerPlanner_Gui.dir/flags.make

CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o: CMakeFiles/DinnerPlanner_Gui.dir/flags.make
CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o -c /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/main.cpp

CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/main.cpp > CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.i

CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/main.cpp -o CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.s

CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o: CMakeFiles/DinnerPlanner_Gui.dir/flags.make
CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o: ../sqlite/sqlite3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o   -c /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/sqlite/sqlite3.c

CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/sqlite/sqlite3.c > CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.i

CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/sqlite/sqlite3.c -o CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.s

CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o: CMakeFiles/DinnerPlanner_Gui.dir/flags.make
CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o: ../DB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o -c /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/DB.cpp

CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/DB.cpp > CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.i

CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/DB.cpp -o CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.s

CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o: CMakeFiles/DinnerPlanner_Gui.dir/flags.make
CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o: ../Recipe_View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o -c /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/Recipe_View.cpp

CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/Recipe_View.cpp > CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.i

CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/Recipe_View.cpp -o CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.s

# Object files for target DinnerPlanner_Gui
DinnerPlanner_Gui_OBJECTS = \
"CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o" \
"CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o" \
"CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o" \
"CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o"

# External object files for target DinnerPlanner_Gui
DinnerPlanner_Gui_EXTERNAL_OBJECTS =

DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/main.cpp.o
DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/sqlite/sqlite3.c.o
DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/DB.cpp.o
DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/Recipe_View.cpp.o
DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/build.make
DinnerPlanner_Gui: CMakeFiles/DinnerPlanner_Gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DinnerPlanner_Gui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DinnerPlanner_Gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DinnerPlanner_Gui.dir/build: DinnerPlanner_Gui

.PHONY : CMakeFiles/DinnerPlanner_Gui.dir/build

CMakeFiles/DinnerPlanner_Gui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DinnerPlanner_Gui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DinnerPlanner_Gui.dir/clean

CMakeFiles/DinnerPlanner_Gui.dir/depend:
	cd /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug /home/rhys/scripts/Projects/DinnerPlanner/DinnerPlanner_Gui/cmake-build-debug/CMakeFiles/DinnerPlanner_Gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DinnerPlanner_Gui.dir/depend
