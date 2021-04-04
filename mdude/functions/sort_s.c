/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:20:29 by mdude             #+#    #+#             */
/*   Updated: 2021/02/15 14:20:30 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sort_s(t_vars *vars, t_sprite *sprite)
{
	int			i;
	int			k;
	t_sprite	temp;

	k = 1;
	while (k < count_sp(vars))
	{
		i = 0;
		while (i < count_sp(vars) - k)
		{
			if (sprite[i].range < sprite[i + 1].range)
			{
				temp = sprite[i];
				sprite[i] = sprite[i + 1];
				sprite[i + 1] = temp;
			}
			i++;
		}
		k++;
	}
}
