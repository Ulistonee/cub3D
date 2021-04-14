/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:15:05 by cobara            #+#    #+#             */
/*   Updated: 2021/02/08 11:15:10 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	draw_model(t_vars *option, int x, int side)
{
	double		perpwalldist;
	double		wallx;
	int			texx;

	if (side == 0)
		perpwalldist = (option->plr.mapx - option->plr.x
		+ (1 - option->plr.stepx) / 2) / option->plr.raydirx;
	else
		perpwalldist = (option->plr.mapy - option->plr.y
		+ (1 - option->plr.stepy) / 2) / option->plr.raydiry;
	init_draw_param(option, perpwalldist);
	if (side == 0)
		wallx = option->plr.y + perpwalldist * option->plr.raydiry;
	else
		wallx = option->plr.x + perpwalldist * option->plr.raydirx;
	wallx -= floor((wallx));
	texx = (int)(wallx
	* (double)option->textures[init_side(option, side)].texwidth);
	if (side == 0 && option->plr.raydirx > 0)
		texx = option->textures[init_side(option, side)].texwidth - texx - 1;
	if (side == 1 && option->plr.raydiry < 0)
		texx = option->textures[init_side(option, side)].texwidth - texx - 1;
	option->z_buffer[x] = perpwalldist;
	output_piece(option, texx, x, init_side(option, side));
}

void	output_piece(t_vars *option, int texx, int x, int side)
{
	double			step;
	double			texpos;
	int				y;
	int				texy;
	unsigned int	*color;

	y = option->plr.drawstart;
	step = 1.0 * option->textures[side].texheight / option->plr.lineheight;
	texpos = (option->plr.drawstart - option->set->w_height
	/ 2 + option->plr.lineheight / 2) * step;
	while (y < option->plr.drawend)
	{
		texy = (int)texpos;
		texpos += step;
		color = (unsigned int*)(option->textures[side].addr
		+ (texy * option->textures[side].line_length
				+ texx * (option->textures[side].bits_per_pixel / 8)));
		my_mlx_pixel_put(option, x, y, (int)*color);
		y++;
	}
	verline(x, option->plr.drawstart, option->plr.drawend, option);
}

int		ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	verline(int x, int drawstart, int drawend, t_vars *option)
{
	int i;
	int color_f;
	int color_c;

	color_f = ft_trgb(0, option->set->floor_color[0],
	option->set->floor_color[1], option->set->floor_color[2]);
	color_c = ft_trgb(0, option->set->ceilling_color[0],
	option->set->ceilling_color[1], option->set->ceilling_color[2]);
	i = 0;
	while (i < drawstart)
	{
		my_mlx_pixel_put(option, x, i, color_c);
		i++;
	}
	while (drawend < option->set->w_height)
	{
		my_mlx_pixel_put(option, x, drawend, color_f);
		drawend++;
	}
}

void	func_dda(t_vars *option, int *side)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (option->plr.sidedistx < option->plr.sidedisty)
		{
			option->plr.sidedistx += option->plr.deltadistx;
			option->plr.mapx += option->plr.stepx;
			(*side) = 0;
		}
		else
		{
			option->plr.sidedisty += option->plr.deltadisty;
			option->plr.mapy += option->plr.stepy;
			(*side) = 1;
		}
		if (check_position(option->plr.mapx, option->plr.mapy,
		option->set->map) == 0)
			hit = 1;
	}
}
