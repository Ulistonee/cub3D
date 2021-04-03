/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:35:19 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 15:35:21 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
//# include "minilibx_opengl_20191021/mlx.h"
# include "libmlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define VALID_SYMBOLS "102 NEWS"
# define FOV_L 0.577
# define STEP 0.1
# define ANGLE 0.09
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define RIGHT 124
# define DOWN 125

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_sprite
{
	t_pos			crd;
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
	int				bpp;
	int				len;
	int				end;
	void			*mlx;
	void			*mlx_win;
	int				h;
	int				w;
	int				tag;
	int				scl;
}					t_img;

typedef struct		s_tex
{
	t_img			ntx;
	t_img			etx;
	t_img			wtx;
	t_img			stx;
	t_img			s;
}					t_tex;

typedef struct		s_walls
{
	double			wall_h;
	double			top;
	double			bottom;
	t_img			side;
}					t_walls;

typedef struct		s_pos_i
{
	int				x;
	int				y;
}					t_pos_i;

typedef struct		s_player
{
	t_pos			pos;
	t_pos			dir;
	t_pos			plane;
}					t_player;

typedef struct		s_struct
{
	int				res1;
	int				res2;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				flr_1;
	int				flr_2;
	int				flr_3;
	int				ceil_1;
	int				ceil_2;
	int				ceil_3;
	int				flr;
	int				ceil;
	char			*s;
	char			p;
}					t_struct;

typedef struct		s_map
{
	char			**map;
	int				lines;
}					t_map;

typedef struct		s_dsp
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
}					t_dsp;

typedef struct		s_all
{
	t_map			map;
	t_struct		data;
	t_dsp			dsp;
	t_player		plr;
	t_walls			w;
	t_tex			tx;
	t_tex			s;
	int				spr_count;
	t_sprite		*sarr;
	int				save_flag;
	t_pos			len;
	t_pos			dot1;
	t_pos			dot2;
	t_pos_i			n;
	t_pos			p_coor;
	int				plr_count;
}					t_all;

typedef struct		s_ray
{
	t_pos			dir;
	double			len;
	double			k;
	t_pos			dot;
}					t_ray;

void				parse_other(t_all *all, char *line);
int					is_map(char *line);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
int					init_game(t_all *all);
void				raycast(t_all *all);
void				parser(t_all *all, char *file_name);
int					draw_walls(t_all *all, t_ray *ray, int x);
double				len_of_vec(double x, double y);
void				perp_vector(t_ray *ray);
int					create_rgb(int r, int g, int b);
int					init_textures(t_all *all);
void				add_spr_to_arr(t_all *all, t_sprite **arr_m);
void				draw_sprites(double *z_buf, t_all *all);
void				hide_spr(t_all *all);
int					gclr(t_img *image, int x, int y);
void				init_spr(t_all *all, t_pos_i map);
int					display(t_all *all);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
int					enter_validator(t_all *all);
void				handle_error(char *message, t_all *all);
void				take_screenshot(t_all *all);
int					key_hook(int keynumber, t_all *all);
void				auto_clear(t_all *all);
void				hooks(t_all *all);
int					exit_program(t_all *all);
t_pos				project_spr(t_all *all, t_pos dot);
void				sprite_dimensions(t_all *all, t_sprite *sprite);
void				parse_color_util(t_all *all, char **line, int *dst);
void				init_val(t_all *all);
void				check_val_integrity(t_all *all);

#endif
