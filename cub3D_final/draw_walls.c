/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:48:50 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 20:48:54 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void					calculate_walls(t_all *all, t_ray *ray)
{
	all->w.wall_h = all->data.res2 / ray->k;
	all->w.top = (double)all->data.res2 / 2 - all->w.wall_h / 2;
	all->w.bottom = (double)all->data.res2 / 2 + all->w.wall_h / 2;
}

int						draw_walls(t_all *all, t_ray *ray, int x)
{
	int						y;
	t_pos					txt_d;
	int						color;

	y = 0;
	calculate_walls(all, ray);
	if (all->w.side.tag == 'N' || all->w.side.tag == 'S')
		txt_d.x = (ray->dot.x - (int)ray->dot.x) * all->w.side.w;
	else
		txt_d.x = (1 - ray->dot.y + (int)ray->dot.y) * all->w.side.w;
	while (y < all->data.res2)
	{
		if (y > all->w.top && y < all->w.bottom)
		{
			txt_d.y = (y - all->w.top) * all->w.side.h / all->w.wall_h;
			color = gclr(&all->w.side, (int)txt_d.x, (int)txt_d.y);
			my_mlx_pixel_put(all, x, y, color);
		}
		if (y < all->w.top)
			my_mlx_pixel_put(all, x, y, all->data.ceil);
		if (y > all->w.bottom)
			my_mlx_pixel_put(all, x, y, all->data.flr);
		y++;
	}
	return (0);
}
