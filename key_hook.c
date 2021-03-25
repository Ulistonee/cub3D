/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:25:35 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:25:38 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int				key_hook(int keynumber, t_all *all)
{
	double			old_x;
	t_pos			new_pos;

	if (keynumber == ESC)
		exit(EXIT_SUCCESS);
	if (keynumber == W || keynumber == UP)
	{
		new_pos.x = all->plr.dir.x * STEP + all->plr.pos.x;
		new_pos.y = all->plr.dir.y * STEP + all->plr.pos.y;
		if (all->map.map[(int)new_pos.y][(int)new_pos.x] == '0')
		{
			all->plr.pos.x = new_pos.x;
			all->plr.pos.y = new_pos.y;
		}
	}
	if (keynumber == S || keynumber == DOWN)
	{
		new_pos.x = -all->plr.dir.x * STEP + all->plr.pos.x;
		new_pos.y = -all->plr.dir.y * STEP + all->plr.pos.y;
		if (all->map.map[(int)(new_pos.y)][(int)(new_pos.x)] == '0')
		{
			all->plr.pos.x = new_pos.x;
			all->plr.pos.y = new_pos.y;
		}
	}
	if (keynumber == LEFT)
	{
		old_x = all->plr.dir.x;
		all->plr.dir.x = old_x * cos(-ANGLE) - all->plr.dir.y * sin(-ANGLE);
		all->plr.dir.y = old_x * sin(-ANGLE) + all->plr.dir.y * cos(-ANGLE);
		old_x = all->plr.plane.x;
		all->plr.plane.x = old_x * cos(-ANGLE) - all->plr.plane.y * sin(-ANGLE);
		all->plr.plane.y = old_x * sin(-ANGLE) + all->plr.plane.y * cos(-ANGLE);
	}
	if (keynumber == A)
	{
		new_pos.x = all->plr.pos.x + all->plr.dir.y * STEP;
		new_pos.y = all->plr.pos.y - all->plr.dir.x * STEP;
		if (all->map.map[(int)(new_pos.y)][(int)(new_pos.x)] == '0')
		{
			all->plr.pos.x = new_pos.x;
			all->plr.pos.y = new_pos.y;
		}
	}
	if (keynumber == D)
	{
		new_pos.x = all->plr.pos.x - all->plr.dir.y * STEP;
		new_pos.y = all->plr.pos.y + all->plr.dir.x * STEP;
		if (all->map.map[(int)(new_pos.y)][(int)(new_pos.x)] == '0')
		{
			all->plr.pos.x = new_pos.x;
			all->plr.pos.y = new_pos.y;
		}
	}
	if (keynumber == RIGHT)
	{
		old_x = all->plr.dir.x;
		all->plr.dir.x = old_x * cos(ANGLE) - all->plr.dir.y * sin(ANGLE);
		all->plr.dir.y = old_x * sin(ANGLE) + all->plr.dir.y * cos(ANGLE);
		old_x = all->plr.plane.x;
		all->plr.plane.x = old_x * cos(ANGLE) - all->plr.plane.y * sin(ANGLE);
		all->plr.plane.y = old_x * sin(ANGLE) + all->plr.plane.y * cos(ANGLE);
	}
	return (0);
}
