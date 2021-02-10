# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h> // for strerror
# include <errno.h> // for errno
# include <stdlib.h> // for exit
# include "libmlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
#define VALID_SYMBOLS "102 NEW"

typedef struct		s_struct
{
	int 			res1;
	int 			res2;
	char 			*no;
	char 			*so;
	char 			*we;
	char 			*ea;
	int 			flr_1;
	int 			flr_2;
	int 			flr_3;
	int 			ceil_1;
	int 			ceil_2;
	int 			ceil_3;
}					t_struct;

typedef struct		s_map
{
	char 			**map;
	int 			lines;
}					t_map;

typedef struct		s_display
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
}					t_display;

typedef struct		s_all
{
	t_map			map;
	t_struct		data;
	t_display		display;
}					t_all;


int					parse_other(t_all *all, char *line);
int 				parse_map(t_all *all, char *line);
int 				is_map(char *line);
int 				handle_error(int code, t_all *all);