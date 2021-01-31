cmake_minimum_required(VERSION 3.17)
project(cub3D C)

set(CMAKE_C_STANDARD 99)
include_directories(./libft)
add_subdirectory(./libft)

add_executable(cub3D
		main.c
		parser/parser.c
		get_next_line/get_next_line.c
		get_next_line/get_next_line_utils.c)
target_link_libraries(cub3D
#		/Users/blavonne/CLionProjects/fractol/minilibx/libmlx.a
#		"-framework OpenGL"
#		"-framework AppKit"
		libft)
