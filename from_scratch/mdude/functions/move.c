/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:18:56 by mdude             #+#    #+#             */
/*   Updated: 2021/02/27 13:18:57 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		up(t_vars *vars)
{
	double	x;
	double	y;
	double	an;

	x = vars->pl.pos.x;
	y = vars->pl.pos.y;
	an = vars->pl.angle;
	if (vars->map.map[(int)(y + 2 * sin(an)) / (int)vars->k]
	[(int)(x + 2 * cos(an)) / (int)vars->k] != '1')
	{
		if (vars->map.map[(int)((vars->pl.pos.y + sin(an)) /
		(int)vars->k)][(int)(vars->pl.pos.x / (int)vars->k)] != '1')
			vars->pl.pos.y = y + sin(an);
		if (vars->map.map[(int)(vars->pl.pos.y / (int)vars->k)]
		[(int)((vars->pl.pos.x + cos(an)) /
		(int)vars->k)] != '1')
			vars->pl.pos.x = x + cos(an);
	}
}

void		left(t_vars *vars)
{
	double	x;
	double	y;
	double	an;

	x = vars->pl.pos.x;
	y = vars->pl.pos.y;
	an = vars->pl.angle;
	if (vars->map.map[(int)(y - 2 * cos(an)) / (int)vars->k]
	[(int)(x + 2 * sin(an)) / (int)vars->k] != '1')
	{
		if (vars->map.map[(int)((vars->pl.pos.y - cos(an)) /
		(int)vars->k)][(int)(vars->pl.pos.x / (int)vars->k)] != '1')
			vars->pl.pos.y = y - cos(an);
		if (vars->map.map[(int)(vars->pl.pos.y / (int)vars->k)]
		[(int)((vars->pl.pos.x + sin(an)) /
		(int)vars->k)] != '1')
			vars->pl.pos.x = x + sin(an);
	}
}

void		down(t_vars *vars)
{
	double	x;
	double	y;
	double	an;

	x = vars->pl.pos.x;
	y = vars->pl.pos.y;
	an = vars->pl.angle;
	if (vars->map.map[(int)(y - 2 * sin(an)) / (int)vars->k]
	[(int)(x - 2 * cos(an)) / (int)vars->k] != '1')
	{
		if (vars->map.map[(int)((vars->pl.pos.y - sin(an)) /
		(int)vars->k)][(int)(vars->pl.pos.x / (int)vars->k)] != '1')
			vars->pl.pos.y = y - sin(an);
		if (vars->map.map[(int)(vars->pl.pos.y / (int)vars->k)]
		[(int)((vars->pl.pos.x - cos(an)) /
		(int)vars->k)] != '1')
			vars->pl.pos.x = x - cos(an);
	}
}

void		right(t_vars *vars)
{
	double	x;
	double	y;
	double	an;

	x = vars->pl.pos.x;
	y = vars->pl.pos.y;
	an = vars->pl.angle;
	if (vars->map.map[(int)(y + 2 * cos(an)) / (int)vars->k]
	[(int)(x - 2 * sin(an)) / (int)vars->k] != '1')
	{
		if (vars->map.map[(int)((vars->pl.pos.y + cos(an)) /
		(int)vars->k)][(int)(vars->pl.pos.x / (int)vars->k)] != '1')
			vars->pl.pos.y = y + cos(an);
		if (vars->map.map[(int)(vars->pl.pos.y / (int)vars->k)]
		[(int)((vars->pl.pos.x - sin(an)) /
		(int)vars->k)] != '1')
			vars->pl.pos.x = x - sin(an);
	}
}

int			move(int keycode, t_vars *vars)
{
	refresh(vars);
	if (keycode == 13)
		up(vars);
	else if (keycode == 0)
		left(vars);
	else if (keycode == 1)
		down(vars);
	else if (keycode == 2)
		right(vars);
	else if (keycode == 123)
		turn_l(vars);
	else if (keycode == 124)
		turn_r(vars);
	paint_c(vars);
	paint_f(vars);
	paint_ray(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
