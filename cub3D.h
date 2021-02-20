# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h> // for strerror
# include <errno.h> // for errno
# include <stdlib.h> // for exit
# include <math.h>
# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "libmlx/mlx.h"
#define VALID_SYMBOLS "102 NEWS"
#define SCALE 90
#define STEP 0.1
#define ANGLE 0.1
# ifdef linux
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
# else
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define UP 126
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
# endif

typedef struct		s_pos
{
	double 			x;
	double 			y;
}					t_pos;

typedef struct 		s_player
{
	t_pos			pos;
	t_pos			dir;
}					t_player;


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
	t_player 		player;
}					t_all;


int					parse_other(t_all *all, char *line);
int 				parse_map(t_all *all, char *line);
int 				is_map(char *line);
int 				handle_error(int code, t_all *all);
int					scaler(t_all *all, int x_input, int y_input, int color);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
void 				draw_player(t_all *all);
int 				set_player_x_y(t_all *all);