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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rchalmer/c/cub3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rchalmer/c/cub3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cub3D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cub3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cub3D.dir/flags.make

CMakeFiles/cub3D.dir/main.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cub3D.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/main.c.o   -c /Users/rchalmer/c/cub3D/main.c

CMakeFiles/cub3D.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/main.c > CMakeFiles/cub3D.dir/main.c.i

CMakeFiles/cub3D.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/main.c -o CMakeFiles/cub3D.dir/main.c.s

CMakeFiles/cub3D.dir/handle_error.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/handle_error.c.o: ../handle_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cub3D.dir/handle_error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/handle_error.c.o   -c /Users/rchalmer/c/cub3D/handle_error.c

CMakeFiles/cub3D.dir/handle_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/handle_error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/handle_error.c > CMakeFiles/cub3D.dir/handle_error.c.i

CMakeFiles/cub3D.dir/handle_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/handle_error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/handle_error.c -o CMakeFiles/cub3D.dir/handle_error.c.s

CMakeFiles/cub3D.dir/parser/parse_other.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/parse_other.c.o: ../parser/parse_other.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cub3D.dir/parser/parse_other.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/parse_other.c.o   -c /Users/rchalmer/c/cub3D/parser/parse_other.c

CMakeFiles/cub3D.dir/parser/parse_other.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/parse_other.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/parser/parse_other.c > CMakeFiles/cub3D.dir/parser/parse_other.c.i

CMakeFiles/cub3D.dir/parser/parse_other.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/parse_other.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/parser/parse_other.c -o CMakeFiles/cub3D.dir/parser/parse_other.c.s

CMakeFiles/cub3D.dir/parser/parse_map.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/parse_map.c.o: ../parser/parse_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cub3D.dir/parser/parse_map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/parse_map.c.o   -c /Users/rchalmer/c/cub3D/parser/parse_map.c

CMakeFiles/cub3D.dir/parser/parse_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/parse_map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/parser/parse_map.c > CMakeFiles/cub3D.dir/parser/parse_map.c.i

CMakeFiles/cub3D.dir/parser/parse_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/parse_map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/parser/parse_map.c -o CMakeFiles/cub3D.dir/parser/parse_map.c.s

CMakeFiles/cub3D.dir/parser/is_map.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/is_map.c.o: ../parser/is_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cub3D.dir/parser/is_map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/is_map.c.o   -c /Users/rchalmer/c/cub3D/parser/is_map.c

CMakeFiles/cub3D.dir/parser/is_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/is_map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/parser/is_map.c > CMakeFiles/cub3D.dir/parser/is_map.c.i

CMakeFiles/cub3D.dir/parser/is_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/is_map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/parser/is_map.c -o CMakeFiles/cub3D.dir/parser/is_map.c.s

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o: ../get_next_line/get_next_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o   -c /Users/rchalmer/c/cub3D/get_next_line/get_next_line.c

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/get_next_line/get_next_line.c > CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/get_next_line/get_next_line.c -o CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o: ../get_next_line/get_next_line_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o   -c /Users/rchalmer/c/cub3D/get_next_line/get_next_line_utils.c

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/get_next_line/get_next_line_utils.c > CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/get_next_line/get_next_line_utils.c -o CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s

CMakeFiles/cub3D.dir/scaler.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/scaler.c.o: ../scaler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cub3D.dir/scaler.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/scaler.c.o   -c /Users/rchalmer/c/cub3D/scaler.c

CMakeFiles/cub3D.dir/scaler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/scaler.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rchalmer/c/cub3D/scaler.c > CMakeFiles/cub3D.dir/scaler.c.i

CMakeFiles/cub3D.dir/scaler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/scaler.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rchalmer/c/cub3D/scaler.c -o CMakeFiles/cub3D.dir/scaler.c.s

# Object files for target cub3D
cub3D_OBJECTS = \
"CMakeFiles/cub3D.dir/main.c.o" \
"CMakeFiles/cub3D.dir/handle_error.c.o" \
"CMakeFiles/cub3D.dir/parser/parse_other.c.o" \
"CMakeFiles/cub3D.dir/parser/parse_map.c.o" \
"CMakeFiles/cub3D.dir/parser/is_map.c.o" \
"CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o" \
"CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o" \
"CMakeFiles/cub3D.dir/scaler.c.o"

# External object files for target cub3D
cub3D_EXTERNAL_OBJECTS =

cub3D: CMakeFiles/cub3D.dir/main.c.o
cub3D: CMakeFiles/cub3D.dir/handle_error.c.o
cub3D: CMakeFiles/cub3D.dir/parser/parse_other.c.o
cub3D: CMakeFiles/cub3D.dir/parser/parse_map.c.o
cub3D: CMakeFiles/cub3D.dir/parser/is_map.c.o
cub3D: CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o
cub3D: CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o
cub3D: CMakeFiles/cub3D.dir/scaler.c.o
cub3D: CMakeFiles/cub3D.dir/build.make
cub3D: libft/liblibft.a
cub3D: CMakeFiles/cub3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable cub3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cub3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cub3D.dir/build: cub3D

.PHONY : CMakeFiles/cub3D.dir/build

CMakeFiles/cub3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cub3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cub3D.dir/clean

CMakeFiles/cub3D.dir/depend:
	cd /Users/rchalmer/c/cub3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rchalmer/c/cub3D /Users/rchalmer/c/cub3D /Users/rchalmer/c/cub3D/cmake-build-debug /Users/rchalmer/c/cub3D/cmake-build-debug /Users/rchalmer/c/cub3D/cmake-build-debug/CMakeFiles/cub3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cub3D.dir/depend

