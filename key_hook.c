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

#include "ft_cub.h"

void				get_rotated(int keynumber, t_all *all)
{
	double		old_x;

	if (keynumber == LEFT)
	{
		old_x = all->plr.dir.x;
		all->plr.dir.x = old_x * cos(-ANGLE) - all->plr.dir.y * sin(-ANGLE);
		all->plr.dir.y = old_x * sin(-ANGLE) + all->plr.dir.y * cos(-ANGLE);
		old_x = all->plr.plane.x;
		all->plr.plane.x = old_x * cos(-ANGLE) - all->plr.plane.y * sin(-ANGLE);
		all->plr.plane.y = old_x * sin(-ANGLE) + all->plr.plane.y * cos(-ANGLE);
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
}

void				get_coordinates(t_all *all, t_pos *new_pos)
{
	all->plr.pos.x = new_pos->x;
	all->plr.pos.y = new_pos->y;
}

void				get_new_pos(int keynumber, t_all *all, t_pos *new_pos)
{
	if (keynumber == W || keynumber == UP)
	{
		new_pos->x = all->plr.dir.x * STEP + all->plr.pos.x;
		new_pos->y = all->plr.dir.y * STEP + all->plr.pos.y;
	}
	if (keynumber == S || keynumber == DOWN)
	{
		new_pos->x = -all->plr.dir.x * STEP + all->plr.pos.x;
		new_pos->y = -all->plr.dir.y * STEP + all->plr.pos.y;
	}
	if (keynumber == A)
	{
		new_pos->x = all->plr.pos.x + all->plr.dir.y * STEP;
		new_pos->y = all->plr.pos.y - all->plr.dir.x * STEP;
	}
	if (keynumber == D)
	{
		new_pos->x = all->plr.pos.x - all->plr.dir.y * STEP;
		new_pos->y = all->plr.pos.y + all->plr.dir.x * STEP;
	}
}

void				make_movement(int keynumber, t_all *all, t_pos *new_pos)
{
	get_new_pos(keynumber, all, new_pos);
	if (all->map.map[(int)new_pos->y][(int)new_pos->x] == '0')
		get_coordinates(all, new_pos);
}

int					key_hook(int keynumber, t_all *all)
{
	t_pos			new_pos;

	if (keynumber == ESC)
		exit(EXIT_SUCCESS);
	else if (keynumber == W || keynumber == UP)
		make_movement(keynumber, all, &new_pos);
	else if (keynumber == S || keynumber == DOWN)
		make_movement(keynumber, all, &new_pos);
	else if (keynumber == LEFT)
		get_rotated(keynumber, all);
	else if (keynumber == A)
		make_movement(keynumber, all, &new_pos);
	else if (keynumber == D)
		make_movement(keynumber, all, &new_pos);
	else if (keynumber == RIGHT)
		get_rotated(keynumber, all);
	return (0);
}
