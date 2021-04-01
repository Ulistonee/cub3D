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

void		init_spr(t_all *all, t_pos_i map)
{
	int				i;

	i = 0;
	while (i < all->spr_count)
	{
		if ((int)all->sarr[i].crd.x == map.x  && (int)all->sarr[i].crd.y == map.y)
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

int			get_color(t_image *image, int x, int y)
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

t_pos		project_spr(t_pos m, t_pos n, t_pos d0, t_pos dot)
{
	t_pos				proj;
	t_pos				sub_dot;
	double				det;

	sub_dot = v_sub(dot, d0);
	det = m.x * n.y - m.y * n.x;
	proj.x = 1 / det * (n.y * sub_dot.x - n.x * sub_dot.y);
	proj.y = 1 / det * (-m.y * sub_dot.x + m.x * sub_dot.y);
	return (proj);
}

void		vsl_sprite(double *z_buff, t_all *all, t_sprite sprite, t_pos proj_coor)
{
	double				j;
	double				i;
	t_pos				s_dot;
	int					color;

	sprite.width = fabs(all->data.res2 / proj_coor.y);
	sprite.start.x = proj_coor.x - sprite.width / 2;
	sprite.end.x = proj_coor.x + sprite.width / 2;
	sprite.start.y = all->data.res2 / 2 - all->data.res2 / proj_coor.y / 2 - 1;
	sprite.end.y = all->data.res2 / 2 + all->data.res2 / proj_coor.y / 2;
	i = sprite.start.x;
	all->s.s.w = 64;
	all->s.s.h = 64;
//	scl = all->s.s.h/all->walls.wall_height;
	if (i < 0)
		i = 0;
	while (i < sprite.end.x && i < all->data.res1)
	{
		if (sprite.end.y > z_buff[(int)i])
		{
			s_dot.x = (i - sprite.start.x) / sprite.width * all->s.s.w;
			j = sprite.start.y < 0 ? 0 : sprite.start.y;
			while (j < sprite.end.y && j < all->data.res2 && j >= 0)
			{
				s_dot.y = (j - sprite.start.y) / sprite.width * all->s.s.h;
				color = get_color((t_image *) &all->s.s.img, (int)s_dot.x, (int)s_dot.y);
				if (color != 0xFFFFFF && color != 0x000000)
					my_mlx_pixel_put(all, (int)i, (int)j, color);
//					scaler(all, (int)i, (int)j, color);
				j++;
			}
		}
		i++;
	}
}

void 		bubble_sort(t_all *all)
{
	int					i;
	int					j;
	t_sprite 			temp;

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
	int					j;

	i = 0;
	j = 0;
	while (i < all->spr_count)
	{
		dist_to_spr = len_of_vec(all->plr.pos.x - all->sarr[i].crd.x, all->plr.pos.y - all->sarr[i].crd.y);
		all->sarr[i].dist = dist_to_spr;
		i++;
	}
}

void		draw_sprites(double *z_buf, t_all *all)
{
	t_pos 				proj_coor;
	int					i;
	double				h;

	i = 0;
	count_dist(all);
	bubble_sort(all);
	while (i < all->spr_count)
	{
		if (all->sarr[i].tag_vis == 1) // all->sarr[i].dist < z_buf[i] &&
		{
			proj_coor = project_spr(all->plr.plane, all->plr.dir, all->plr.pos, all->sarr[i].crd);
			h = fabs(all->data.res2 / proj_coor.y);
			proj_coor.x = (double)all->data.res1 / 2 * (1 + proj_coor.x / proj_coor.y); // - h / 2;
			vsl_sprite(z_buf, all, all->sarr[i], proj_coor);
		}
		i++;
	}
}

/*
 * we initialize a sprite, then we add it to the sarray. We include info about its crdinates.
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
