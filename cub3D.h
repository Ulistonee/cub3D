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
//# include "libmlx/mlx.h"
#define VALID_SYMBOLS "102 NEWS"
#define SCALE 45
# define FOV_L 0.577
#define STEP 0.093
#define ANGLE 0.09
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

typedef struct		s_sprite
{
	t_pos			coord;
	double			dist;
	t_pos			start;
	t_pos			end;
	double			width;
	int				tag_vis;
}					t_sprite;

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
	int				h;
	int				w;
	int				tag;
}					t_image;

typedef struct		s_tex
{
	t_image			n_tex;
	t_image			e_tex;
	t_image			w_tex;
	t_image			s_tex;
	t_image			s;
}					t_tex;

typedef struct		s_walls
{
	double			wall_height;
	double			top;
	double			bottom;
	t_image			side;
}					t_walls;


typedef struct		s_pos_i
{
	int 			x;
	int 			y;
}					t_pos_i;

typedef struct		s_fow
{
	t_pos			plane;
	t_pos			old_plane;
	t_pos			ray_dir;
	t_pos			dir;
	t_pos			old_dir;
	double			camera_x;
	t_pos_i 		map;
	t_pos			pos;
	t_pos			side_dist;
	t_pos			delta_dist;
	double			perp_wall_dist;
	t_pos			step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
}					t_fow;
//
//typedef struct		s_posi
//{
//	int 			x;
//	int 			y;
//}					t_posi;

typedef struct 		s_player
{
	t_pos			pos;
	t_pos			dir;
	t_pos			plane;
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
	int				flr;
	int				ceil;
	char			*s;
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
	t_fow			fow;
	t_walls			walls;
	t_tex			tex;
	t_tex			s;
	t_image			image;
	int				spr_count;
	t_sprite		*spr_arr;
}					t_all;

typedef struct		s_ray
{
	t_pos			dir;
	double			len;
	double			k;
	t_pos			dot;

}					t_ray;

int					parse_other(t_all *all, char *line);
int 				parse_map(t_all *all, char *line);
int 				is_map(char *line);
int 				handle_error(int code, t_all *all);
int					scaler(t_all *all, int x_input, int y_input, int color);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
void 				draw_player(t_all *all);
int 				init_game(t_all *all);
void 				raycast(t_all *all);
int					parser(t_all *all, char *file_name);
int					visualize(t_all *all);
int					draw_map(t_all *all);
int					draw_walls(t_all *all, t_ray *ray, int x);
double				len_of_vec(double x, double y);
double				dist_dots(double x, double y, double a, double b);
double				perp_vector(t_all *all, double camera_plane, t_ray *ray);
int					create_rgb(int r, int g, int b);
int					init_textures(t_all *all);
//t_sprite			*add_spr_to_arr(t_all *all);
void 				add_spr_to_arr(t_all *all, t_sprite **arr_m);
void				draw_sprites(double *z_buf, t_all *all);
void				hide_spr(t_all *all);
int					get_color(t_image *image, int x, int y);
void				init_spr(t_all *all, t_pos_i map);
//int					init_textures(t_all *all);
int 				display(t_all *all);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
