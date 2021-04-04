/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:58:49 by cobara            #+#    #+#             */
/*   Updated: 2021/01/27 13:58:52 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	my_mlx_pixel_put(t_vars *option, int x, int y, int color)
{
	char	*dst;
	t_data	*data;

	data = &option->img_map;
	if (option->bmp == '0')
	{
		dst = data->addr + (y * data->line_length + x
		* (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
	else
	{
		option->image[y][x][0] = (unsigned char)
		((int)color % 256);
		option->image[y][x][1] = (unsigned char)
		((int)color / 256);
		option->image[y][x][2] = (unsigned char)
		((int)color / 256 / 256);
	}
}

int		check_position(int x, int y, char **map)
{
	if (map[(y)][(x)] == '1')
		return (0);
	return (1);
}

void	init_direction(t_vars *option)
{
	if (option->plr.pos == 'E')
	{
		option->plr.planex = 0;
		option->plr.planey = 0.66;
	}
	if (option->plr.pos == 'W')
	{
		option->plr.planex = 0;
		option->plr.planey = -0.66;
	}
	if (option->plr.pos == 'N')
	{
		option->plr.planex = 0.66;
		option->plr.planey = 0;
	}
	if (option->plr.pos == 'S')
	{
		option->plr.planex = -0.66;
		option->plr.planey = 0;
	}
	init_plan(option);
}

void	make_all(t_vars *option)
{
	option->img_map.img = mlx_new_image(option->mlx, option->set->w_width,
									option->set->w_height);
	option->img_map.addr = mlx_get_data_addr(option->img_map.img,
										&option->img_map.bits_per_pixel,
										&option->img_map.line_length,
										&option->img_map.endian);
	draw_rays(option);
	mlx_put_image_to_window(option->mlx, option->win,
						option->img_map.img, 0, 0);
}

void	make_plr(t_vars *option)
{
	option->img_plr.img = mlx_new_image(option->mlx, 1, 1);
	option->img_plr.addr = mlx_get_data_addr(option->img_plr.img,
										&option->img_plr.bits_per_pixel,
										&option->img_plr.line_length,
										&option->img_map.endian);
	mlx_put_image_to_window(option->mlx, option->win, option->img_plr.img,
						option->plr.x, option->plr.y);
}
