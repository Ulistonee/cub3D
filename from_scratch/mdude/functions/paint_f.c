/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:22:42 by mdude             #+#    #+#             */
/*   Updated: 2021/02/09 16:22:43 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		paint_f(t_vars *vars)
{
	int		color_f;
	double	i;
	double	j;

	color_f = vars->map.id_f.red * 65536 + 256 *
			vars->map.id_f.green + vars->map.id_f.blue;
	i = 0;
	while (i < vars->map.id_r.width)
	{
		j = vars->map.id_r.height / 2;
		while (j < vars->map.id_r.height)
		{
			my_mlx_pixel_put(&vars->img, i, j, color_f);
			j++;
		}
		i++;
	}
}
