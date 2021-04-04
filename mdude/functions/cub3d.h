/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:05:22 by mdude             #+#    #+#             */
/*   Updated: 2021/01/22 12:09:20 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WALLL 64
# define BUFFER_SIZE 64
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_screen
{
	double		width;
	double		height;
}				t_screen;
typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;
typedef struct	s_map
{
	t_screen	id_r;
	char		*id_no;
	char		*id_so;
	char		*id_we;
	char		*id_ea;
	char		*id_s;
	t_rgb		id_f;
	t_rgb		id_c;
	char		**map;
}				t_map;

typedef	struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;
typedef struct	s_player
{
	t_pos		pos;
	char		dir;
	double		angle;
}				t_player;
typedef struct	s_tex
{
	int			h;
	int			w;
	t_data		img;
}				t_tex;
typedef struct	s_sprite
{
	t_pos		pos;
	double		range;
	double		a;
	double		size;
	double		x_start;
	double		y_start;
	double		h;
	double		temp;
}				t_sprite;
typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	pl;
	double		k;
	t_data		img;
	t_tex		*tex;
}				t_vars;
typedef struct	s_spp
{
	int			x;
	double		y;
	int			j;
	int			i;
}				t_spp;
typedef struct	s_ipos
{
	int			x;
	int			y;
}				t_ipos;
typedef struct	s_wall
{
	double		h;
	double		len;
	t_pos		pos;
	double		temp;
	double		an;
	double		p;
	int			flag_x;
	int			flag_y;
}				t_wall;
int				intlen(long n);
void			init_map(t_map *map);
int				maxlen(char **str);
int				sizestr(char **str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			fill_sq(t_data *img, int color, int i);
int				is_news(char c);
void			paint(t_map *map, t_vars *vars);
void			fill_luch(t_data *img, int color, t_player *pl);
t_player		start_pos(t_map *map);
void			fill_sq_pl(t_data *img, int color, int i, t_player *pl);
t_pos			get_pos(t_player *pl);
void			draw_sp(t_vars *vars, double *zbuffer);
void			paint_ray(t_vars *vars);
t_vars			init_vars(t_map *map, int argc, char **argv);
int				is_wall(char **map, double y, double x, double k);
void			paint_c(t_vars *vars);
void			paint_f(t_vars *vars);
double			len_y(t_vars *vars, double an, double x, double y);
double			len_x(t_vars *vars, double an, double x, double y);
double			min_count(double a, double b);
unsigned int	get_col(t_data *img, int x, int y);
t_tex			*init_tex(t_vars *vars);
int				count_sp(t_vars *vars);
t_sprite		*init_sp(t_vars *vars);
void			sort_s(t_vars *vars, t_sprite *sprite);
char			*ft_itoa_base(unsigned long n, int rank, int up);
int				screen(t_vars *vars);
int				valid_map(t_map *map);
int				is_space(char c);
int				move(int keycode, t_vars *vars);
int				main(int argc, char **argv);
t_map			parser(char **argv);
t_screen		init_screen(char *line);
t_rgb			init_color(char *line);
void			refresh(t_vars *vars);
void			turn_l(t_vars *vars);
void			turn_r(t_vars *vars);
void			draw_col(t_wall *wall, t_vars *vars, t_tex *tex, int flag_x);
int				fl(int argc, char **argv);
int				get_next_line(int fd, char **line);
char			*under(char *str);
int				is_all(char c);
char			*save_line(char *line, char *temp);
int				is_str(char *str);
t_map			f_map(char **argv);
void			ch_arg(void);
int				check_format(char *str);
void			ch_f(char **argv);
void			ch_args(int argc, char **argv);
int				ft_close(t_vars *vars);
int				count_space(char *str);
char			*ft_path(const char *s1);

#endif
