/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubgame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:19:07 by cobara            #+#    #+#             */
/*   Updated: 2021/01/18 17:19:11 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUBGAME_H
# define __CUBGAME_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "utils/get_next_line.h"
# include <libft.h>
# include "stdio.h"

# define SPRITES 4

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				texwidth;
	int				texheight;
}					t_data;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
	double			sprite_distance;
}					t_sprite;

typedef struct		s_sinfo
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
}					t_sinfo;

typedef struct		s_plr
{
	float			x;
	float			y;
	float			dir;
	float			start;
	float			end;
	char			pos;
	float			dirx;
	float			diry;
	float			planex;
	float			planey;
	float			raydirx;
	float			raydiry;
	float			camerax;
	int				mapx;
	int				mapy;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	int				stepx;
	int				stepy;
	int				drawstart;
	int				drawend;
	int				lineheight;
	int				texwidth;
	int				texheight;
}					t_plr;

typedef struct		s_key{
	char			w;
	char			s;
	char			a;
	char			d;
	char			left;
	char			right;
}					t_key;

typedef struct		s_set
{
	int				w_width;
	int				w_height;
	char			*path_noth;
	char			*path_south;
	char			*path_west;
	char			*path_east;
	char			*path_sprite;
	int				floor_color[3];
	int				ceilling_color[3];
	char			**map;
}					t_set;

typedef struct		s_vars{
	void			*mlx;
	void			*win;
	char			**map;
	t_data			img_plr;
	t_data			img_map;
	t_plr			plr;
	t_set			*set;
	t_key			key;
	char			flag;
	t_data			textures[5];
	int				sprite_order[SPRITES];
	double			z_buffer[10000];
	t_sprite		**sprites;
	int				sprites_count;
	t_sinfo			sinfo;
	char			bmp;
	unsigned char	***image;
}					t_vars;

typedef struct		s_all
{
	t_data			*win;
	t_plr			*plr;
	char			**map;
}					t_all;

void				ft_print_error(int code);
char				**make_map(t_list **head, int size);
char				**parse_file(char *filename);
t_vars				*ft_game(t_set *settings);
void				parse_resolution(char **map, t_set *settings);
t_set				*parse_map(char **map);
void				parse_textures(char **map, t_set *settings);
void				parse_no(char **map, t_set *settings);
void				parse_so(char **map, t_set *settings);
void				parse_we(char **map, t_set *settings);
void				parse_ea(char **map, t_set *settings);
void				parse_sprite(char **map, t_set *settings);
void				check_repeat(char **map, char ch, char c);
void				parse_color_f(char **map, t_set *settings);
void				parse_color_с(char **map, t_set *settings);
int					parse_main_map(char **map, t_set *settings);
void				ft_init(t_set *settings);
void				fill_main_map(char **map, t_set *settings, int size);
void				check_map(char **map, int size);
void				check_bottom_top(char **map, int side);
void				check_border(char **map);
void				check_probels(char **map, int i, int j);
void				check_around(char **map);
void				has_sh(char **map);
void				check_repeat_pl(char **map);
void				my_mlx_pixel_put(t_vars *option, int x, int y, int color);
void				ft_print_square(int x, int y, t_data img, char ch);
int					key_hook(int keycode, t_vars *vars);
void				ft_init_win(t_set *settings, t_vars *option);
int					check_position(int x, int y, char **map);
void				ft_drawmap(t_vars *option);
int					render(t_vars *option);
void				ft_drawplr(t_vars *option);
void				render_map(t_vars *option);
void				draw_rays(t_vars *option);
void				init_direction(t_vars *option);
void				make_all(t_vars *option);
void				make_plr(t_vars *option);
void				set_position(t_vars *option);
void				move(t_vars *option);
int					check_move(t_vars *option);
int					key_release(int keycode, t_vars *option);
void				f(t_vars *option, float angle);
void				init_move(t_vars *option);
void				check_direct(t_vars *option);
void				func_dda(t_vars *option, int *side);
void				init_rays_var(t_vars *option, int x, int w);
void				change_dis(t_vars *option);
void				init_plan(t_vars *option);
void				verline(int x, int drawstart, int drawend, t_vars *option);
void				draw_line(t_vars *option, int x, int side);
void				init_textures(t_vars *option);
void				output_piece(t_vars *option, int texx, int x, int side);
void				init_draw_param(t_vars *option, double perpwalldist);
void				init_textures_sprite(t_vars *option);
int					init_side(t_vars *option, int side);
void				draw_model(t_vars *option, int x, int side);
int					is_plr(char ch);
void				ft_clear_mas(char **tmp);
void				init_color(t_set *settings, char **tmp);
void				init_rotate(t_vars *option, float *rotate);
void				check_all_param(t_set *settings);
void				ft_check_digits(char **tmp);
void				check_zap(char *str);
void				check_posit(char **map, char c, char sh);
void				check_another_symb(char **map);
void				draw_sprites(t_vars *option);
int					count_sprite(t_vars *option);
void				init_sprite(t_vars *option);
void				init_sprite_info(t_vars *option, int i, int j, int *count);
void				init_plr_pos(t_vars *option, int x, int y, char ch);
void				sprite_render(t_vars *option);
void				draw_sprite_piece(t_vars *option);
void				draw_pod_y(t_vars *option, int stripe);
void				init_xmp_in_tex(t_vars *option, int i, char *path);
int					check_text(char **map, int i, int j);
int					check_color_resolution(char **map, int i, int j);
int					get_posit(char **map);
void				init_resolution(char **map, int i, int j, t_set *settings);
void				init_floor(char **map, int i, int j, t_set *settings);
void				init_ceil(char **map, int i, int j, t_set *settings);
void				createbtmp(t_vars *all);
void				ft_hook(t_vars *option);
void				generate_bitmapimage(t_vars *all, int height, int width,
					char *filename);
unsigned char		*create_header(int height, int width, int fd);
unsigned char		*create_infoheader(int height, int width, int fd);
int					prog_exit(int keycode, t_vars *vars);

#endif
