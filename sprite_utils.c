/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:33:21 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:33:24 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		vsl_sprite(double *z_buff, t_all *all, t_sprite sprite)
{
	double				j;
	double				i;
	t_pos				s_dot;
	int					clr;

	sprite_dimensions(all, &sprite);
	i = sprite.start.x;
	i = i < 0 ? 0 : i;
	while (i < sprite.end.x && i < all->data.res1)
	{
		if (sprite.end.y > z_buff[(int)i])
		{
			s_dot.x = (i - sprite.start.x) / sprite.width * all->s.s.w;
			j = sprite.start.y < 0 ? 0 : sprite.start.y;
			while (j < sprite.end.y && j < all->data.res2 && j >= 0)
			{
				s_dot.y = (j - sprite.start.y) / sprite.width * all->s.s.h;
				clr = gclr((t_img *)&all->s.s.img, (int)s_dot.x, (int)s_dot.y);
				if (clr != 0xFFFFFF && clr != 0x000000)
					my_mlx_pixel_put(all, (int)i, (int)j, clr);
				j++;
			}
		}
		i++;
	}
}

void		bubble_sort(t_all *all)
{
	int					i;
	int					j;
	t_sprite			temp;

	i = 0;
	while (i < all->spr_count)
	{
		j = all->spr_count - 1;
		while (j > i)
		{
			if (all->sarr[j - 1].dist < all->sarr[j].dist)
			{
				temp = all->sarr[j - 1];
				all->sarr[j - 1] = all->sarr[j];
				all->sarr[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void		count_dist(t_all *all)
{
	double				dist_to_spr;
	int					i;
	double				x;
	double				y;

	i = 0;
	while (i < all->spr_count)
	{
		x = all->plr.pos.x - all->sarr[i].crd.x;
		y = all->plr.pos.y - all->sarr[i].crd.y;
		dist_to_spr = len_of_vec(x, y);
		all->sarr[i].dist = dist_to_spr;
		i++;
	}
}

void		draw_sprites(double *z_buf, t_all *all)
{
	int					i;

	i = 0;
	count_dist(all);
	bubble_sort(all);
	while (i < all->spr_count)
	{
		if (all->sarr[i].tag_vis == 1)
		{
			all->proj_coor = project_spr(all, all->sarr[i].crd);
			all->proj_coor.x = (double)all->data.res1 / 2 * (1 + all->proj_coor.x / all->proj_coor.y);
			vsl_sprite(z_buf, all, all->sarr[i]);
		}
		i++;
	}
}

/*
 * we initialize a sprite, then we add it to the sarray. We include info about its coordinates.
 */
void		add_spr_to_arr(t_all *all, t_sprite **arr_m)
{
	t_sprite			*arr;
	int 				i;
	int 				x;
	int 				y;
	t_sprite			spr;

	if (!(arr = (t_sprite *)malloc(all->spr_count*sizeof(t_sprite))))
		handle_error("Memory allocation error\n, Exit game\n", all); // we have to free this pointer
	x = 0;
	y = 0;
	i = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (all->map.map[y][x] == '2')
			{
				spr.crd.x = x + 0.5;
				spr.crd.y = y + 0.5;
				arr[i] = spr;
				i++;
			}
			x++;
		}
		y++;
	}
	*arr_m = arr;
}
