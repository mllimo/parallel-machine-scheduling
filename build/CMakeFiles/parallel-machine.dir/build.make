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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/limo/Documentos/c++/daa-parallel-machine-scheduling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/limo/Documentos/c++/daa-parallel-machine-scheduling/build

# Include any dependencies generated for this target.
include CMakeFiles/parallel-machine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parallel-machine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parallel-machine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallel-machine.dir/flags.make

CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o: ../src/greedy_pms.cc
CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o -MF CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o.d -o CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/greedy_pms.cc

CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/greedy_pms.cc > CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.i

CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/greedy_pms.cc -o CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.s

CMakeFiles/parallel-machine.dir/src/main.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/main.cc.o: ../src/main.cc
CMakeFiles/parallel-machine.dir/src/main.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/parallel-machine.dir/src/main.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/main.cc.o -MF CMakeFiles/parallel-machine.dir/src/main.cc.o.d -o CMakeFiles/parallel-machine.dir/src/main.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/main.cc

CMakeFiles/parallel-machine.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/main.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/main.cc > CMakeFiles/parallel-machine.dir/src/main.cc.i

CMakeFiles/parallel-machine.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/main.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/main.cc -o CMakeFiles/parallel-machine.dir/src/main.cc.s

CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o: ../src/problem_pms.cc
CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o -MF CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o.d -o CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/problem_pms.cc

CMakeFiles/parallel-machine.dir/src/problem_pms.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/problem_pms.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/problem_pms.cc > CMakeFiles/parallel-machine.dir/src/problem_pms.cc.i

CMakeFiles/parallel-machine.dir/src/problem_pms.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/problem_pms.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/problem_pms.cc -o CMakeFiles/parallel-machine.dir/src/problem_pms.cc.s

CMakeFiles/parallel-machine.dir/src/program.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/program.cc.o: ../src/program.cc
CMakeFiles/parallel-machine.dir/src/program.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/parallel-machine.dir/src/program.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/program.cc.o -MF CMakeFiles/parallel-machine.dir/src/program.cc.o.d -o CMakeFiles/parallel-machine.dir/src/program.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program.cc

CMakeFiles/parallel-machine.dir/src/program.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/program.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program.cc > CMakeFiles/parallel-machine.dir/src/program.cc.i

CMakeFiles/parallel-machine.dir/src/program.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/program.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program.cc -o CMakeFiles/parallel-machine.dir/src/program.cc.s

CMakeFiles/parallel-machine.dir/src/program_pms.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/program_pms.cc.o: ../src/program_pms.cc
CMakeFiles/parallel-machine.dir/src/program_pms.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/parallel-machine.dir/src/program_pms.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/program_pms.cc.o -MF CMakeFiles/parallel-machine.dir/src/program_pms.cc.o.d -o CMakeFiles/parallel-machine.dir/src/program_pms.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program_pms.cc

CMakeFiles/parallel-machine.dir/src/program_pms.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/program_pms.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program_pms.cc > CMakeFiles/parallel-machine.dir/src/program_pms.cc.i

CMakeFiles/parallel-machine.dir/src/program_pms.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/program_pms.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/program_pms.cc -o CMakeFiles/parallel-machine.dir/src/program_pms.cc.s

CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o: CMakeFiles/parallel-machine.dir/flags.make
CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o: ../src/strategy_pms.cc
CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o: CMakeFiles/parallel-machine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o -MF CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o.d -o CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o -c /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/strategy_pms.cc

CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/strategy_pms.cc > CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.i

CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/limo/Documentos/c++/daa-parallel-machine-scheduling/src/strategy_pms.cc -o CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.s

# Object files for target parallel-machine
parallel__machine_OBJECTS = \
"CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o" \
"CMakeFiles/parallel-machine.dir/src/main.cc.o" \
"CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o" \
"CMakeFiles/parallel-machine.dir/src/program.cc.o" \
"CMakeFiles/parallel-machine.dir/src/program_pms.cc.o" \
"CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o"

# External object files for target parallel-machine
parallel__machine_EXTERNAL_OBJECTS =

parallel-machine: CMakeFiles/parallel-machine.dir/src/greedy_pms.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/src/main.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/src/problem_pms.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/src/program.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/src/program_pms.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/src/strategy_pms.cc.o
parallel-machine: CMakeFiles/parallel-machine.dir/build.make
parallel-machine: CMakeFiles/parallel-machine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable parallel-machine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallel-machine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallel-machine.dir/build: parallel-machine
.PHONY : CMakeFiles/parallel-machine.dir/build

CMakeFiles/parallel-machine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallel-machine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallel-machine.dir/clean

CMakeFiles/parallel-machine.dir/depend:
	cd /home/limo/Documentos/c++/daa-parallel-machine-scheduling/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/limo/Documentos/c++/daa-parallel-machine-scheduling /home/limo/Documentos/c++/daa-parallel-machine-scheduling /home/limo/Documentos/c++/daa-parallel-machine-scheduling/build /home/limo/Documentos/c++/daa-parallel-machine-scheduling/build /home/limo/Documentos/c++/daa-parallel-machine-scheduling/build/CMakeFiles/parallel-machine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallel-machine.dir/depend
