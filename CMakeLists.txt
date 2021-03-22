 cmake_minimum_required(VERSION 3.17)
project(Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(./libft)

add_executable(Cub3D
        cub3D.h
        main.c
        parser/parser.c
        parser/parse_other.c
        parser/parse_map.c
        parser/is_map.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        handle_error.c
        scaler.c
        draw_player.c
        init_game.c
        raycast.c
        draw_map.c
        display_utils.c
        draw_walls.c
        len_of_vec.c
        dist_dots.c
        perp_vector.c
        create_rgb.c
        sprite_utils.c
        validator/enter_validator.c
        key_hook.c)

if (APPLE)
  target_link_libraries(Cub3D
  #    Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
      libft
      "-framework OpenGL"
      "-framework AppKit"
      ${CMAKE_SOURCE_DIR}/libmlx_mac/libmlx.a
      )
endif(APPLE)
if (UNIX AND NOT APPLE)
  target_link_libraries(Cub3D
      #    Cub3D ${CMAKE_SOURCE_DIR}/libft/libft.a
      libft
      ${CMAKE_SOURCE_DIR}/libmlx/libmlx.a
      "-lX11"
      "-lm"
      "-lXext"
  )
endif(UNIX AND NOT APPLE)