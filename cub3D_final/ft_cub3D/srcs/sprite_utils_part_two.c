/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_part_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:30:07 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 15:30:09 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void		init_spr(t_all *all, t_pos_i map)
{
	int				i;

	i = 0;
	while (i < all->spr_count)
	{
		if ((int)all->sarr[i].crd.x == map.x &&
		(int)all->sarr[i].crd.y == map.y)
			all->sarr[i].tag_vis = 1;
		i++;
	}
}

void		hide_spr(t_all *all)
{
	int				i;

	i = 0;
	while (i < all->spr_count)
	{
		all->sarr[i].tag_vis = 0;
		i++;
	}
}

int			gclr(t_img *image, int x, int y)
{
	char		*dst;
	int			res;

	if (x < image->w && y < image->h && x >= 0 && y >= 0)
	{
		dst = image->addr + (y * image->len + x * (image->bpp / 8));
		res = (*(int*)dst);
		return (res);
	}
	return (0);
}

t_pos		v_sub(t_pos v1, t_pos v2)
{
	t_pos				res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

t_pos		project_spr(t_all *all, t_pos dot)
{
	t_pos				proj;
	t_pos				sub_dot;
	double				det;

	sub_dot = v_sub(dot, all->plr.pos);
	det = all->plr.plane.x * all->plr.dir.y - all->plr.plane.y * all->plr.dir.x;
	proj.x = 1 / det * (all->plr.dir.y * sub_dot.x -
			all->plr.dir.x * sub_dot.y);
	proj.y = 1 / det * (-all->plr.plane.y * sub_dot.x +
			all->plr.plane.x * sub_dot.y);
	return (proj);
}
