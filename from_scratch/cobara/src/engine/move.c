/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:57:29 by cobara            #+#    #+#             */
/*   Updated: 2021/01/30 16:57:31 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	move(t_vars *option)
{
	float lastx;
	float lasty;

	lastx = option->plr.x;
	lasty = option->plr.y;
	init_move(option);
	if (check_position(option->plr.x, lasty,
	option->set->map) == 0)
		option->plr.x = lastx;
	if (check_position(lastx, option->plr.y, option->set->map) == 0)
		option->plr.y = lasty;
	if (option->key.right == '1' && option->key.left == '1')
		return ;
	if (option->key.right == '1' || option->key.left == '1')
		change_dis(option);
}

void	init_move(t_vars *option)
{
	float angle;

	angle = 0;
	if (option->key.w == '1')
	{
		angle = option->plr.dir;
		f(option, angle);
	}
	if (option->key.s == '1')
	{
		angle = option->plr.dir + (180 * M_PI / 180);
		f(option, angle);
	}
	if (option->key.a == '1')
	{
		angle = option->plr.dir + (270 * M_PI / 180);
		f(option, angle);
	}
	if (option->key.d == '1')
	{
		angle = option->plr.dir + (90 * M_PI / 180);
		f(option, angle);
	}
}

int		check_move(t_vars *option)
{
	if (option->key.w == '1' && check_position(option->plr.x,
	option->plr.y - 1, option->set->map) == 1)
		return (1);
	if (option->key.s == '1' && check_position(option->plr.x,
	option->plr.y + 10, option->set->map) == 1)
		return (1);
	if (option->key.a == '1' && check_position(option->plr.x - 1,
	option->plr.y, option->set->map) == 1)
		return (1);
	if (option->key.d == '1' && check_position(option->plr.x + 10,
	option->plr.y, option->set->map) == 1)
		return (1);
	return (0);
}

int		is_plr(char ch)
{
	if (ch == 'N' || ch == 'E' || ch == 'W' || ch == 'S')
		return (1);
	return (0);
}
