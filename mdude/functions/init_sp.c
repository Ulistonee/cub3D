/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:58:26 by mdude             #+#    #+#             */
/*   Updated: 2021/02/15 13:58:27 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite		fill_sp(t_ipos pos, t_vars *vars)
{
	t_sprite s;

	s.pos.x = pos.x * vars->k + vars->k / 2;
	s.pos.y = pos.y * vars->k + vars->k / 2;
	s.range = sqrt((s.pos.x - vars->pl.pos.x) * (s.pos.x - vars->pl.pos.x)
			+ (s.pos.y - vars->pl.pos.y) * (s.pos.y - vars->pl.pos.y));
	s.a = atan2((vars->pl.pos.y - s.pos.y), (vars->pl.pos.x - s.pos.x)) + M_PI;
	while (s.a - vars->pl.angle > M_PI)
		s.a = s.a - M_PI * 2;
	while (s.a - vars->pl.angle < -M_PI)
		s.a = s.a + M_PI * 2;
	s.a = s.a - vars->pl.angle;
	s.size = (WALLL / s.range) * (vars->map.id_r.width / 2)
			/ tan(M_PI / 6) / vars->k;
	s.h = s.size;
	s.temp = 0;
	if (s.size > vars->map.id_r.height)
	{
		s.temp = s.size - vars->map.id_r.height;
		s.h = vars->map.id_r.height;
	}
	s.x_start = (vars->map.id_r.width / (M_PI / 3 * (180.0 / M_PI))
			* ((180.0 / M_PI * (s.a)) + 30.0) - s.size / 2);
	s.y_start = (double)(vars->map.id_r.height / 2.0) - (double)(s.h / 2.0);
	return (s);
}

t_sprite		*init_sp(t_vars *vars)
{
	t_sprite	*sprite;
	int			k;
	t_ipos		pos;

	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite) * count_sp(vars))))
		return (NULL);
	pos.y = 0;
	k = 0;
	while (pos.y < sizestr(vars->map.map))
	{
		pos.x = 0;
		while (vars->map.map[pos.y][pos.x])
		{
			if (vars->map.map[pos.y][pos.x] == '2')
			{
				sprite[k] = fill_sp(pos, vars);
				k++;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (sprite);
}
