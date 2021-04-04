/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:25:33 by mdude             #+#    #+#             */
/*   Updated: 2021/02/27 14:25:37 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_l(t_vars *vars)
{
	vars->pl.angle = vars->pl.angle - (M_PI / 36);
	if (vars->pl.angle <= 0)
		vars->pl.angle = vars->pl.angle + 2 * M_PI;
	else if (vars->pl.angle >= 2 * M_PI)
		vars->pl.angle = vars->pl.angle - 2 * M_PI;
}

void	turn_r(t_vars *vars)
{
	vars->pl.angle = vars->pl.angle + (M_PI / 36);
	if (vars->pl.angle <= 0)
		vars->pl.angle = vars->pl.angle + 2 * M_PI;
	else if (vars->pl.angle > 2 * M_PI)
		vars->pl.angle = vars->pl.angle - 2 * M_PI;
}
