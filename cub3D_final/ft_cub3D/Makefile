NAME		= cub3D

SRCS	= \
			srcs/parser/parse_other.c \
			srcs/parser/parser_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			srcs/main.c \
			srcs/handle_error.c \
			srcs/init_game.c \
			srcs/raycast.c \
			srcs/parser/parser.c \
			srcs/display_utils.c \
			srcs/draw_walls.c\
			srcs/len_of_vec.c \
			srcs/perp_vector.c \
			srcs/create_rgb.c \
			srcs/sprite_utils.c \
			srcs/sprite_utils_part_two.c \
			srcs/sprite_utils_part_three.c \
			srcs/validator/enter_validator.c \
			srcs/take_screenshot.c \
			srcs/key_hook.c \
			srcs/hooks.c

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HEADER		= srcs/ft_cub.h

RM			= rm -f

all:		init ${NAME}

init:
			make -C libft
# 			make -C libmlx
			make -C minilibx_opengl_20191021

$(NAME):	$(OBJS) $(HEADER)
#MAC:
			$(CC) $(FLAGS) $(OBJS) -Llibft -lft -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#Lnx:
			#$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Llibmlx -lmlx -lXext -lX11 -lbsd -lm -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

#LINUX:
	# $(CC) $(FLAGS) main.c -Llibft -lft

clean:
			${RM} ${OBJS}
			make -C libft clean
			make -C minilibx_opengl_20191021 clean
		
fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean

re:			fclean all

norm:
			norminettev2 $(SRCS)
			norminettev2 $(HEADER)
			norminettev2 libft/*.c
			norminettev2 libft/*.h

.PHONY:		all clean fclean re

# commands
# http://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC77