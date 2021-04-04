/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:52:41 by cobara            #+#    #+#             */
/*   Updated: 2021/01/30 16:52:43 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	f(t_vars *option, float angle)
{
	option->plr.x += cos(angle) * 0.05;
	option->plr.y += sin(angle) * 0.05;
}

int		render(t_vars *option)
{
	mlx_hook(option->win, 2, (1L << 0), key_hook, option);
	mlx_hook(option->win, 3, (1L << 1), key_release, option);
	mlx_hook(option->win, 17, 1, prog_exit, option);
	if (option->key.d == '1' || option->key.w == '1' || option->key.s == '1'
	|| option->key.a == '1' || option->key.right == '1'
	|| option->key.left == '1')
	{
		move(option);
		render_map(option);
		option->flag = '0';
	}
	else if (option->flag == '0')
	{
		move(option);
		render_map(option);
		option->flag = '1';
	}
	return (1);
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->key.w = '1';
	if (keycode == 1)
		vars->key.s = '1';
	if (keycode == 0)
		vars->key.a = '1';
	if (keycode == 2)
		vars->key.d = '1';
	if (keycode == 123)
		vars->key.left = '1';
	if (keycode == 124)
		vars->key.right = '1';
	if (keycode == 53)
		exit(0);
	return (1);
}

void	render_map(t_vars *option)
{
	mlx_clear_window(option->mlx, option->win);
	make_all(option);
}

int		key_release(int keycode, t_vars *option)
{
	if (keycode == 13)
		option->key.w = '0';
	if (keycode == 1)
		option->key.s = '0';
	if (keycode == 0)
		option->key.a = '0';
	if (keycode == 2)
		option->key.d = '0';
	if (keycode == 123)
		option->key.left = '0';
	if (keycode == 124)
		option->key.right = '0';
	return (1);
}
