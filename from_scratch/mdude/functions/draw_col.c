/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:04:00 by mdude             #+#    #+#             */
/*   Updated: 2021/02/28 16:04:01 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_col(t_wall *wall, t_vars *vars, t_tex *tex, int flag_x)
{
	int		i;
	int		color;

	i = 0;
	while (i < (int)(wall->h))
	{
		color = get_col(&tex[flag_x - 1].img,
						(int)wall->p, (int)((i + wall->temp / 2) *
											tex[flag_x - 1].h /
											(wall->h + wall->temp)));
		my_mlx_pixel_put(&vars->img, wall->pos.x, wall->pos.y, color);
		i++;
		wall->pos.y++;
	}
}
