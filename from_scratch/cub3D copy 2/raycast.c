/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:33:13 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/30 15:33:16 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** In this function we use similarity of triangles.
** We also calculate the length of the ray.
*/

void				final_spot(t_all *all, t_ray *ray, t_pos_i *map)
{
	if (all->len.x < all->len.y)
	{
		ray->len = all->len.x;
		ray->dot = all->dot1;
		map->x += all->n.x;
		all->w.side = (ray->dir.x < 0) ? all->tx.wtx : all->tx.etx;
		all->w.side.tag = (ray->dir.x < 0) ? 'W' : 'E';
	}
	else
	{
		ray->len = all->len.y;
		ray->dot = all->dot2;
		map->y += all->n.y;
		all->w.side = (ray->dir.y < 0) ? all->tx.ntx : all->tx.stx;
		all->w.side.tag = (ray->dir.y < 0) ? 'N' : 'S';
	}
}

double				calc_trian(t_all *all, t_ray *ray, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.x = fabs(dot->x - all->plr.pos.x);
	cath.y = fabs(ray->dir.y * cath.x / ray->dir.x);
	if (ray->dir.y > 0)
		dot->y = all->plr.pos.y + cath.y;
	else
		dot->y = all->plr.pos.y - cath.y;
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2));
	return (len);
}

/*
** In this function we use similarity of triangles.
** We also calculate the length of the ray.
*/

double				calc_trian_y(t_all *all, t_ray *ray, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.y = fabs(dot->y - all->plr.pos.y);
	cath.x = fabs(ray->dir.x * cath.y / ray->dir.y);
	if (ray->dir.x > 0)
		dot->x = all->plr.pos.x + cath.x;
	else
		dot->x = all->plr.pos.x - cath.x;
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2));
	return (len);
}

/*
** In this function we firstly calculate one
** of the whole integers, either x or y.
** If the ray is parallel to one the grid`s axis`s then we
** just calculate the difference between plr`s y and grid`s y
*/

int					calc_grid(t_all *all, t_ray *ray)
{
	t_pos_i		map;

	all->n.x =  (ray->dir.x < 0)? -1 : 1;
	all->n.y =  (ray->dir.y < 0)? -1 : 1;
	map.x = (int)all->plr.pos.x;
	map.y = (int)all->plr.pos.y;
	while (all->map.map[map.y][map.x] != '1')
	{
		all->dot1.x = (ray->dir.x < 0) ? map.x : map.x + 1;
		all->dot2.y = (ray->dir.y < 0) ? map.y : map.y + 1;
		if (ray->dir.x == 0)
			all->len.y = fabs(all->plr.pos.y - all->dot2.y);
		else
			all->len.x =  calc_trian(all, ray, &all->dot1);
		if (ray->dir.y == 0)
			all->len.x = fabs(all->plr.pos.x - all->dot1.x);
		else
			all->len.y = calc_trian_y(all, ray, &all->dot2);
		final_spot(all, ray, &map);
//		if (all->len.x < all->len.y)
//		{
//			ray->len = all->len.x;
//			ray->dot = all->dot1;
//			map.x += all->n.x;
//			all->w.side = (ray->dir.x < 0) ? all->tx.wtx : all->tx.etx;
//			all->w.side.tag = (ray->dir.x < 0) ? 'W' : 'E';
//		}
//		else
//		{
//			ray->len = all->len.y;
//			ray->dot = all->dot2;
//			map.y += all->n.y;
//			all->w.side = (ray->dir.y < 0) ? all->tx.ntx : all->tx.stx;
//			all->w.side.tag = (ray->dir.y < 0) ? 'N' : 'S';
//		}
		if (all->map.map[map.y][map.x] == '2')
			init_spr(all, map);
	}
	return (0);
}

/*
** Camera_plane is always perpendicular
** Ray.dir.x/y - current ray direction inside the camera_plane
*/

void				raycast(t_all *all)
{
	t_ray		ray;
	double		camera_plane;
	int			x;
	double		z_buf[all->data.res1];

	x = 0;
	hide_spr(all);
	while (x < all->data.res1)
	{
		camera_plane = 2 * x / (double)all->data.res1 - 1;
		ray.dir.x = all->plr.dir.x + all->plr.plane.x * camera_plane;
		ray.dir.y = all->plr.dir.y + all->plr.plane.y * camera_plane;
		calc_grid(all, &ray);
		perp_vector(&ray);
		draw_walls(all, &ray, x);
		z_buf[x] = all->w.bottom;
		x++;
	}
	draw_sprites(z_buf, all);
}
