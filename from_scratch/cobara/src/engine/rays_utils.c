/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:42 by cobara            #+#    #+#             */
/*   Updated: 2021/02/15 13:59:44 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	draw_rays(t_vars *option)
{
	int w;
	int x;
	int side;

	w = option->set->w_width;
	x = 0;
	side = 0;
	while (x < w)
	{
		init_rays_var(option, x, w);
		check_direct(option);
		func_dda(option, &side);
		draw_model(option, x, side);
		x++;
	}
	draw_sprites(option);
}

void	init_rays_var(t_vars *option, int x, int w)
{
	option->plr.camerax = 2 * x / (double)w - 1;
	option->plr.raydirx = option->plr.dirx + option->plr.planex
	* option->plr.camerax;
	option->plr.raydiry = option->plr.diry + option->plr.planey
	* option->plr.camerax;
	option->plr.mapx = option->plr.x;
	option->plr.mapy = option->plr.y;
	option->plr.deltadistx = sqrt(1 + (option->plr.raydiry
	* option->plr.raydiry) / (option->plr.raydirx * option->plr.raydirx));
	option->plr.deltadisty = sqrt(1 + (option->plr.raydirx
	* option->plr.raydirx) / (option->plr.raydiry * option->plr.raydiry));
}

void	check_direct(t_vars *option)
{
	if (option->plr.raydirx < 0)
	{
		option->plr.stepx = -1;
		option->plr.sidedistx = (option->plr.x - option->plr.mapx)
		* option->plr.deltadistx;
	}
	else
	{
		option->plr.stepx = 1;
		option->plr.sidedistx = (option->plr.mapx + 1.0 - option->plr.x)
		* option->plr.deltadistx;
	}
	if (option->plr.raydiry < 0)
	{
		option->plr.stepy = -1;
		option->plr.sidedisty = (option->plr.y - option->plr.mapy)
		* option->plr.deltadisty;
	}
	else
	{
		option->plr.stepy = 1;
		option->plr.sidedisty = (option->plr.mapy + 1.0 - option->plr.y)
		* option->plr.deltadisty;
	}
}

void	init_draw_param(t_vars *option, double perpwalldist)
{
	option->plr.lineheight = (int)(option->set->w_height / perpwalldist);
	option->plr.drawstart = -option->plr.lineheight / 2
	+ option->set->w_height / 2;
	if (option->plr.drawstart < 0)
		option->plr.drawstart = 0;
	option->plr.drawend = option->plr.lineheight / 2
	+ option->set->w_height / 2;
	if (option->plr.drawend >= option->set->w_height)
		option->plr.drawend = option->set->w_height - 1;
}

int		init_side(t_vars *option, int side)
{
	if (side == 0 && option->plr.mapx > option->plr.x)
		return (2);
	if (side == 0 && option->plr.mapx < option->plr.x)
		return (3);
	if (side == 1 && option->plr.mapy > option->plr.y)
		return (1);
	else
		return (0);
}
