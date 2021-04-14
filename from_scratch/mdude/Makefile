ls# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdude <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 19:59:21 by mdude             #+#    #+#              #
#    Updated: 2021/02/28 21:35:45 by mdude            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME2 = libft/libft.a

HEADERS = functions/cub3d.h

HEADERSLIB = libft/libft.h

SRC = functions/count_sprites.c \
	  functions/draw_col.c \
	  functions/checks.c \
	  functions/draw_sp.c \
	  functions/ft_close.c \
	  functions/ft_path.c \
	  functions/get_color.c \
	  functions/get_next_line.c \
	  functions/get_next_line_utils.c \
	  functions/get_pos.c \
	  functions/init_color.c \
	  functions/init_map.c \
	  functions/init_screen.c \
	  functions/init_sp.c \
	  functions/init_tex.c \
	  functions/init_vars.c \
	  functions/intlen.c \
	  functions/is_news.c \
	  functions/is_space.c \
	  functions/is_str.c \
	  functions/is_wall.c \
	  functions/main.c \
	  functions/maxlen.c \
	  functions/move.c \
	  functions/my_mlx_pixel_put.c \
	  functions/paint_c.c \
	  functions/paint_f.c \
	  functions/paint_ray.c \
	  functions/parser.c \
	  functions/refresh.c \
	  functions/save_line.c \
	  functions/screen.c \
	  functions/sizestr.c \
	  functions/sort_s.c \
	  functions/start_pos.c \
	  functions/turn_l.c \
	  functions/valid_map.c

OBJ = $(SRC:%.c=%.o)

OBJLIB = $(SRCLIB:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c $(HEADERS) $(HEADERSLIB)
	gcc $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) $(HEADERSLIB)
	$(MAKE) -C mlx
	cp mlx/libmlx.dylib .
	$(MAKE) -C libft
	gcc $(FLAGS) -O3 $(SRC) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	rm -f libmlx.dylib
	rm -f screen.bmp

re: fclean all
