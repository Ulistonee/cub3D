cmake_minimum_required(VERSION 3.17)
project(Cub3D C)
set(CMAKE_C_STANDARD 99)

file(GLOB LIBFILES libft/*.c)
add_library(LibFT STATIC ${LIBFILES})

#add_subdirectory(./libft)
add_executable (cub3D
        cub3D.h
        main.c
        parser/parser.c
        parser/parse_other.c
		parser/is_map.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        handle_error.c
		other/scaler.c
		other/draw_player.c
        init_game.c
        raycast.c
		other/draw_map.c
        display_utils.c
        draw_walls.c
        len_of_vec.c
		other/dist_dots.c
        perp_vector.c
        create_rgb.c
        sprite_utils.c
        validator/enter_validator.c
        take_screenshot.c
        key_hook.c
		hooks.c)
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
            )
endif(UNIX AND NOT APPLE)