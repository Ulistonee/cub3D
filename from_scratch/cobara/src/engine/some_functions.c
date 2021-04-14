/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:52:17 by cobara            #+#    #+#             */
/*   Updated: 2021/02/08 15:52:18 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	init_plan(t_vars *option)
{
	if (option->plr.pos == 'N')
	{
		option->plr.dirx = 0;
		option->plr.diry = -1;
		option->plr.dir = (270 * M_PI) / 180;
	}
	else if (option->plr.pos == 'E')
	{
		option->plr.dirx = 1;
		option->plr.diry = 0;
		option->plr.dir = (360 * M_PI) / 180;
	}
	else if (option->plr.pos == 'W')
	{
		option->plr.dirx = -1;
		option->plr.diry = 0;
		option->plr.dir = (180 * M_PI) / 180;
	}
	else
	{
		option->plr.dirx = 0;
		option->plr.diry = 1;
		option->plr.dir = (90 * M_PI) / 180;
	}
}

void	change_dis(t_vars *option)
{
	float	rotate;
	double	olddirx;
	double	oldplanex;

	if (option->key.right == '1')
	{
		rotate = 0.05;
		option->plr.dir += 0.05;
	}
	else
	{
		rotate = -0.05;
		option->plr.dir -= 0.05;
	}
	olddirx = option->plr.dirx;
	option->plr.dirx = option->plr.dirx * cos(rotate)
					- option->plr.diry * sin(rotate);
	option->plr.diry = olddirx * sin(rotate) + option->plr.diry * cos(rotate);
	oldplanex = option->plr.planex;
	option->plr.planex = option->plr.planex * cos(rotate)
						- option->plr.planey * sin(rotate);
	option->plr.planey = oldplanex * sin(rotate) + option->plr.planey
												* cos(rotate);
}
