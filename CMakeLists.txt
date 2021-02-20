cmake_minimum_required(VERSION 3.17)
project(Cub3D C)
set(CMAKE_C_STANDARD 99)

file(GLOB LIBFILES libft/*.c)
add_library(LibFT STATIC ${LIBFILES})

#add_subdirectory(./libft)
add_executable (cub3D
        cub3D.h
        main.c
        parser/parse_other.c
        parser/parse_map.c
        parser/is_map.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        handle_error.c
        scaler.c
        draw_player.c
        set_player_x_y.c)
target_link_libraries(cub3D LibFT)
if (APPLE)
    target_link_libraries(cub3D
            #     Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
            LibFT
            ${CMAKE_SOURCE_DIR}/minilibx_opengl_20191021/libmlx.a
            "-framework OpenGL"
            "-framework AppKit"
            )
endif(APPLE)
if (UNIX AND NOT APPLE)
    target_link_libraries(cub3D
            #     Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
            ${CMAKE_SOURCE_DIR}/libmlx/libmlx.a
            "-lX11"
            "-lm"
            "-lXext"
            "-lz"
            )
endif(UNIX AND NOT APPLE)