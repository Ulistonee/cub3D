/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:52:58 by mdude             #+#    #+#             */
/*   Updated: 2021/01/27 12:52:59 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double			pl_an(char c)
{
	double		an;

	if (c == 'N')
		an = 3 * M_PI_2;
	if (c == 'E')
		an = 0;
	if (c == 'S')
		an = M_PI_2;
	if (c == 'W')
		an = M_PI;
	return (an);
}

t_player		start_pos(t_map *map)
{
	t_player	pl;
	t_ipos		xy;
	char		c;
	int			flag;

	xy.y = -1;
	flag = 0;
	while (++xy.y < sizestr(map->map) && !flag)
	{
		xy.x = 0;
		while (xy.x < (int)ft_strlen(map->map[xy.y]) && !flag)
		{
			if (is_news(map->map[xy.y][xy.x]))
			{
				flag = 1;
				c = map->map[xy.y][xy.x];
			}
			xy.x++;
		}
	}
	pl.pos.x = (xy.x - 1);
	pl.pos.y = (xy.y - 1);
	pl.dir = c;
	pl.angle = pl_an(c);
	return (pl);
}
