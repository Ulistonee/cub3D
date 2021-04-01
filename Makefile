NAME		= cub3D

SRCS	= \
			parser/parse_other.c \
			parser/is_map.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			main.c \
			handle_error.c \
			init_game.c \
			raycast.c \
			parser/parser.c \
			display_utils.c \
			draw_walls.c\
			len_of_vec.c \
			perp_vector.c \
			create_rgb.c \
			sprite_utils.c \
			validator/enter_validator.c \
			take_screenshot.c \
			key_hook.c \
			hooks.c

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HEADER		= cub3D.h

RM			= rm -f

all:		init ${NAME}

init:
			@ echo "......init......"
			make -C libft
# 			make -C libmlx
			make -C minilibx_opengl_20191021

$(NAME):	$(OBJS) $(HEADER)
#MAC:
			$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

#Lnx:
			#$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Llibmlx -lmlx -lXext -lX11 -lbsd -lm -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

#LINUX:
	# $(CC) $(FLAGS) main.c -Llibft -lft

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			make -C libft clean
		
fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77