/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:44:18 by mdude             #+#    #+#             */
/*   Updated: 2021/02/15 13:44:22 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_sp(t_vars *vars)
{
	int	count;
	int	i;
	int	j;
	int size;

	count = 0;
	i = 0;
	size = sizestr(vars->map.map);
	while (i < size)
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
