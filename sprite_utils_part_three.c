/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_part_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:43:06 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 14:43:09 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void			sprite_dimensions(t_all *all, t_sprite *spr)
{
	spr->width = fabs(all->data.res2 / all->p_coor.y);
	spr->start.x = all->p_coor.x - spr->width / 2;
	spr->end.x = all->p_coor.x + spr->width / 2;
	spr->start.y = all->data.res2 / 2 - all->data.res2 / all->p_coor.y / 2 - 1;
	spr->end.y = all->data.res2 / 2 + all->data.res2 / all->p_coor.y / 2;
}
