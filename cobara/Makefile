SRCS = src/main.c \
src/parser/file_parser.c \
src/parser/parser_map.c \
src/parser/validation.c \
src/parser/parser_utils.c \
src/parser/parser_color.c \
src/parser/print_errors.c \
src/parser/parser_textures.c \
src/utils/get_next_line.c \
src/utils/get_next_line_utils.c \
src/engine/game.c \
src/engine/game_utils.c \
src/engine/draw.c \
src/engine/rendering.c \
src/engine/move.c \
src/engine/rays.c \
src/engine/some_functions.c \
src/engine/rays_utils.c \
src/engine/sprites_draw.c \
src/parser/util_function.c \
src/engine/init_tex.c \
src/engine/bitmap.c

OBJS  = ${SRCS:.c=.o}

RM = rm -rf
CC = gcc -Ilibft

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
	make -C libft
	make bonus -C libft
	$(CC) libft/libft.a ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean:		clean
	${RM} $(NAME)
	$(RM) libft/*.a
	
re:			fclean all

.PHONY: all clean fclean re