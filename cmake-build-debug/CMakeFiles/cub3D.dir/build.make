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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aizhan/cub3D/cub3D/my_cub3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cub3D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cub3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cub3D.dir/flags.make

CMakeFiles/cub3D.dir/main.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cub3D.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/main.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/main.c

CMakeFiles/cub3D.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/main.c > CMakeFiles/cub3D.dir/main.c.i

CMakeFiles/cub3D.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/main.c -o CMakeFiles/cub3D.dir/main.c.s

CMakeFiles/cub3D.dir/parser/parser.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/parser.c.o: ../parser/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cub3D.dir/parser/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/parser.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/parser/parser.c

CMakeFiles/cub3D.dir/parser/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/parser/parser.c > CMakeFiles/cub3D.dir/parser/parser.c.i

CMakeFiles/cub3D.dir/parser/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/parser/parser.c -o CMakeFiles/cub3D.dir/parser/parser.c.s

CMakeFiles/cub3D.dir/parser/parse_other.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/parse_other.c.o: ../parser/parse_other.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cub3D.dir/parser/parse_other.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/parse_other.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_other.c

CMakeFiles/cub3D.dir/parser/parse_other.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/parse_other.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_other.c > CMakeFiles/cub3D.dir/parser/parse_other.c.i

CMakeFiles/cub3D.dir/parser/parse_other.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/parse_other.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_other.c -o CMakeFiles/cub3D.dir/parser/parse_other.c.s

CMakeFiles/cub3D.dir/parser/parse_map.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/parse_map.c.o: ../parser/parse_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cub3D.dir/parser/parse_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/parse_map.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_map.c

CMakeFiles/cub3D.dir/parser/parse_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/parse_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_map.c > CMakeFiles/cub3D.dir/parser/parse_map.c.i

CMakeFiles/cub3D.dir/parser/parse_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/parse_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/parser/parse_map.c -o CMakeFiles/cub3D.dir/parser/parse_map.c.s

CMakeFiles/cub3D.dir/parser/is_map.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/parser/is_map.c.o: ../parser/is_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cub3D.dir/parser/is_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/parser/is_map.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/parser/is_map.c

CMakeFiles/cub3D.dir/parser/is_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/parser/is_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/parser/is_map.c > CMakeFiles/cub3D.dir/parser/is_map.c.i

CMakeFiles/cub3D.dir/parser/is_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/parser/is_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/parser/is_map.c -o CMakeFiles/cub3D.dir/parser/is_map.c.s

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o: ../get_next_line/get_next_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line.c

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line.c > CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.i

CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line.c -o CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.s

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o: ../get_next_line/get_next_line_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line_utils.c

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line_utils.c > CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.i

CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/get_next_line/get_next_line_utils.c -o CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.s

CMakeFiles/cub3D.dir/handle_error.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/handle_error.c.o: ../handle_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cub3D.dir/handle_error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/handle_error.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/handle_error.c

CMakeFiles/cub3D.dir/handle_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/handle_error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/handle_error.c > CMakeFiles/cub3D.dir/handle_error.c.i

CMakeFiles/cub3D.dir/handle_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/handle_error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/handle_error.c -o CMakeFiles/cub3D.dir/handle_error.c.s

CMakeFiles/cub3D.dir/scaler.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/scaler.c.o: ../scaler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/cub3D.dir/scaler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/scaler.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/scaler.c

CMakeFiles/cub3D.dir/scaler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/scaler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/scaler.c > CMakeFiles/cub3D.dir/scaler.c.i

CMakeFiles/cub3D.dir/scaler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/scaler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/scaler.c -o CMakeFiles/cub3D.dir/scaler.c.s

CMakeFiles/cub3D.dir/draw_player.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/draw_player.c.o: ../draw_player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/cub3D.dir/draw_player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/draw_player.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/draw_player.c

CMakeFiles/cub3D.dir/draw_player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/draw_player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/draw_player.c > CMakeFiles/cub3D.dir/draw_player.c.i

CMakeFiles/cub3D.dir/draw_player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/draw_player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/draw_player.c -o CMakeFiles/cub3D.dir/draw_player.c.s

CMakeFiles/cub3D.dir/set_player.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/set_player.c.o: ../set_player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/cub3D.dir/set_player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/set_player.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/set_player.c

CMakeFiles/cub3D.dir/set_player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/set_player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/set_player.c > CMakeFiles/cub3D.dir/set_player.c.i

CMakeFiles/cub3D.dir/set_player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/set_player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/set_player.c -o CMakeFiles/cub3D.dir/set_player.c.s

CMakeFiles/cub3D.dir/raycast.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/raycast.c.o: ../raycast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/cub3D.dir/raycast.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/raycast.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/raycast.c

CMakeFiles/cub3D.dir/raycast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/raycast.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/raycast.c > CMakeFiles/cub3D.dir/raycast.c.i

CMakeFiles/cub3D.dir/raycast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/raycast.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/raycast.c -o CMakeFiles/cub3D.dir/raycast.c.s

CMakeFiles/cub3D.dir/draw_map.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/draw_map.c.o: ../draw_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/cub3D.dir/draw_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/draw_map.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/draw_map.c

CMakeFiles/cub3D.dir/draw_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/draw_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/draw_map.c > CMakeFiles/cub3D.dir/draw_map.c.i

CMakeFiles/cub3D.dir/draw_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/draw_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/draw_map.c -o CMakeFiles/cub3D.dir/draw_map.c.s

CMakeFiles/cub3D.dir/visualize.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/visualize.c.o: ../visualize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/cub3D.dir/visualize.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/visualize.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/visualize.c

CMakeFiles/cub3D.dir/visualize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/visualize.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/visualize.c > CMakeFiles/cub3D.dir/visualize.c.i

CMakeFiles/cub3D.dir/visualize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/visualize.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/visualize.c -o CMakeFiles/cub3D.dir/visualize.c.s

CMakeFiles/cub3D.dir/draw_walls.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/draw_walls.c.o: ../draw_walls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/cub3D.dir/draw_walls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/draw_walls.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/draw_walls.c

CMakeFiles/cub3D.dir/draw_walls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/draw_walls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/draw_walls.c > CMakeFiles/cub3D.dir/draw_walls.c.i

CMakeFiles/cub3D.dir/draw_walls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/draw_walls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/draw_walls.c -o CMakeFiles/cub3D.dir/draw_walls.c.s

CMakeFiles/cub3D.dir/len_of_vec.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/len_of_vec.c.o: ../len_of_vec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/cub3D.dir/len_of_vec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/len_of_vec.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/len_of_vec.c

CMakeFiles/cub3D.dir/len_of_vec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/len_of_vec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/len_of_vec.c > CMakeFiles/cub3D.dir/len_of_vec.c.i

CMakeFiles/cub3D.dir/len_of_vec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/len_of_vec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/len_of_vec.c -o CMakeFiles/cub3D.dir/len_of_vec.c.s

CMakeFiles/cub3D.dir/dist_dots.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/dist_dots.c.o: ../dist_dots.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/cub3D.dir/dist_dots.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/dist_dots.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/dist_dots.c

CMakeFiles/cub3D.dir/dist_dots.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/dist_dots.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/dist_dots.c > CMakeFiles/cub3D.dir/dist_dots.c.i

CMakeFiles/cub3D.dir/dist_dots.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/dist_dots.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/dist_dots.c -o CMakeFiles/cub3D.dir/dist_dots.c.s

CMakeFiles/cub3D.dir/perp_vector.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/perp_vector.c.o: ../perp_vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/cub3D.dir/perp_vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/perp_vector.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/perp_vector.c

CMakeFiles/cub3D.dir/perp_vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/perp_vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/perp_vector.c > CMakeFiles/cub3D.dir/perp_vector.c.i

CMakeFiles/cub3D.dir/perp_vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/perp_vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/perp_vector.c -o CMakeFiles/cub3D.dir/perp_vector.c.s

CMakeFiles/cub3D.dir/create_rgb.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/create_rgb.c.o: ../create_rgb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/cub3D.dir/create_rgb.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cub3D.dir/create_rgb.c.o   -c /home/aizhan/cub3D/cub3D/my_cub3D/create_rgb.c

CMakeFiles/cub3D.dir/create_rgb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/create_rgb.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aizhan/cub3D/cub3D/my_cub3D/create_rgb.c > CMakeFiles/cub3D.dir/create_rgb.c.i

CMakeFiles/cub3D.dir/create_rgb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/create_rgb.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aizhan/cub3D/cub3D/my_cub3D/create_rgb.c -o CMakeFiles/cub3D.dir/create_rgb.c.s

# Object files for target cub3D
cub3D_OBJECTS = \
"CMakeFiles/cub3D.dir/main.c.o" \
"CMakeFiles/cub3D.dir/parser/parser.c.o" \
"CMakeFiles/cub3D.dir/parser/parse_other.c.o" \
"CMakeFiles/cub3D.dir/parser/parse_map.c.o" \
"CMakeFiles/cub3D.dir/parser/is_map.c.o" \
"CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o" \
"CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o" \
"CMakeFiles/cub3D.dir/handle_error.c.o" \
"CMakeFiles/cub3D.dir/scaler.c.o" \
"CMakeFiles/cub3D.dir/draw_player.c.o" \
"CMakeFiles/cub3D.dir/set_player.c.o" \
"CMakeFiles/cub3D.dir/raycast.c.o" \
"CMakeFiles/cub3D.dir/draw_map.c.o" \
"CMakeFiles/cub3D.dir/visualize.c.o" \
"CMakeFiles/cub3D.dir/draw_walls.c.o" \
"CMakeFiles/cub3D.dir/len_of_vec.c.o" \
"CMakeFiles/cub3D.dir/dist_dots.c.o" \
"CMakeFiles/cub3D.dir/perp_vector.c.o" \
"CMakeFiles/cub3D.dir/create_rgb.c.o"

# External object files for target cub3D
cub3D_EXTERNAL_OBJECTS =

cub3D: CMakeFiles/cub3D.dir/main.c.o
cub3D: CMakeFiles/cub3D.dir/parser/parser.c.o
cub3D: CMakeFiles/cub3D.dir/parser/parse_other.c.o
cub3D: CMakeFiles/cub3D.dir/parser/parse_map.c.o
cub3D: CMakeFiles/cub3D.dir/parser/is_map.c.o
cub3D: CMakeFiles/cub3D.dir/get_next_line/get_next_line.c.o
cub3D: CMakeFiles/cub3D.dir/get_next_line/get_next_line_utils.c.o
cub3D: CMakeFiles/cub3D.dir/handle_error.c.o
cub3D: CMakeFiles/cub3D.dir/scaler.c.o
cub3D: CMakeFiles/cub3D.dir/draw_player.c.o
cub3D: CMakeFiles/cub3D.dir/set_player.c.o
cub3D: CMakeFiles/cub3D.dir/raycast.c.o
cub3D: CMakeFiles/cub3D.dir/draw_map.c.o
cub3D: CMakeFiles/cub3D.dir/visualize.c.o
cub3D: CMakeFiles/cub3D.dir/draw_walls.c.o
cub3D: CMakeFiles/cub3D.dir/len_of_vec.c.o
cub3D: CMakeFiles/cub3D.dir/dist_dots.c.o
cub3D: CMakeFiles/cub3D.dir/perp_vector.c.o
cub3D: CMakeFiles/cub3D.dir/create_rgb.c.o
cub3D: CMakeFiles/cub3D.dir/build.make
cub3D: libLibFT.a
cub3D: ../libmlx/libmlx.a
cub3D: CMakeFiles/cub3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking C executable cub3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cub3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cub3D.dir/build: cub3D

.PHONY : CMakeFiles/cub3D.dir/build

CMakeFiles/cub3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cub3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cub3D.dir/clean

CMakeFiles/cub3D.dir/depend:
	cd /home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aizhan/cub3D/cub3D/my_cub3D /home/aizhan/cub3D/cub3D/my_cub3D /home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug /home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug /home/aizhan/cub3D/cub3D/my_cub3D/cmake-build-debug/CMakeFiles/cub3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cub3D.dir/depend

