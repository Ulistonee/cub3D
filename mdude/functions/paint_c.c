/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:25:53 by mdude             #+#    #+#             */
/*   Updated: 2021/02/09 16:25:54 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		paint_c(t_vars *vars)
{
	int		color_c;
	double	i;
	double	j;

	color_c = vars->map.id_c.red * 65536 + 256 *
			vars->map.id_c.green + vars->map.id_c.blue;
	i = 0;
	while (i < vars->map.id_r.width)
	{
		j = 0;
		while (j < vars->map.id_r.height / 2)
		{
			my_mlx_pixel_put(&vars->img, i, j, color_c);
			j++;
		}
		i++;
	}
}
