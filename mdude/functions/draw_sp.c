/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:37:47 by mdude             #+#    #+#             */
/*   Updated: 2021/02/28 13:09:08 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ch_col(t_vars *vars, t_sprite *sprite,
		t_spp sp, double *zbuffer)
{
	int			color;

	color = get_col(&vars->tex[4].img, (int)(sp.x /
				sprite[sp.i].size * vars->tex[4].w),
			(int)((sp.j + sprite[sp.i].temp / 2) *
				vars->tex[4].h / (sprite[sp.i].h + sprite[sp.i].temp)));
	if (color != 0 && sprite[sp.i].x_start < vars->map.id_r.width
			&& sprite[sp.i].x_start >= 0 &&
		zbuffer[(int)sprite[sp.i].x_start] /
		vars->k >= sprite[sp.i].range * cos(sprite[sp.i].a))
		my_mlx_pixel_put(&vars->img, sprite[sp.i].x_start, sp.y, color);
}

void			draw_sp(t_vars *vars, double *zbuffer)
{
	t_sprite	*sprite;
	t_spp		sp;
	int			count;

	sprite = init_sp(vars);
	sort_s(vars, sprite);
	count = count_sp(vars);
	sp.i = -1;
	while (++sp.i < count)
		if ((sprite[sp.i].a >= -M_PI / 3 && sprite[sp.i].a <= M_PI / 3))
		{
			sp.x = -1;
			while (++sp.x < (int)sprite[sp.i].size)
			{
				sp.j = -1;
				sp.y = sprite[sp.i].y_start;
				while (++sp.j < (int)sprite[sp.i].h)
				{
					ch_col(vars, sprite, sp, zbuffer);
					sp.y++;
				}
				sprite[sp.i].x_start++;
			}
		}
	free(sprite);
}
