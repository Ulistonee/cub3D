#include "cub3D.h"

double 				calc_trian(t_all *all, t_ray *ray, int n_x, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.x = fabs(dot->x - all->plr.pos.x); // difference between the starting x and the intersection point
	cath.y = fabs(ray->dir.y * cath.x / ray->dir.x); // similarity of triangles
	dot->y = (ray->dir.y > 0) ? all->plr.pos.y + cath.y : all->plr.pos.y - cath.y; // the sum of the starting y and the cath.y
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2)); // length of the ray
	return (len);
}

double 				calc_trian_y(t_all *all, t_ray *ray, int n_x, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.y = fabs(dot->y - all->plr.pos.y); // difference between the starting x and the intersection point
	cath.x = fabs(ray->dir.x * cath.y / ray->dir.y); // similarity of triangles
	dot->x = (ray->dir.x > 0) ? all->plr.pos.x + cath.x : all->plr.pos.x - cath.x; // the sum of the starting y and the cath.y
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2)); // length of the ray
	return (len);
}

int					calc_grid(t_all *all, t_ray *ray)
{
	t_pos		len;
	t_pos		dot1; // first grid cross occurrence
	t_pos		dot2; // first grid cross occurrence
	t_pos_i		map;
	t_pos_i 	n;

	n.x =  (ray->dir.x < 0)? -1 : 1;
	n.y =  (ray->dir.y < 0)? -1 : 1;
	map.x = (int)all->plr.pos.x; // starting point for the crossing dot search because we have to enter the cycle
	map.y = (int)all->plr.pos.y; // starting point for the crossing dot search because we have to enter the cycle
	while (all->map.map[map.y][map.x] != '1')
	{
		dot1.x = (ray->dir.x < 0) ? map.x : map.x + 1; // first we calculate one of the whole integers. Either x or y
		dot2.y = (ray->dir.y < 0) ? map.y : map.y + 1; // first we calculate one of the whole integers. Either x or y
		if (ray->dir.x == 0) // if the ray is parallel to one the grid`s axis`s then we just calculate the difference between plr`s y and grid`s y
			len.y = fabs(all->plr.pos.y - dot2.y);
		else
			len.x =  calc_trian(all, ray, n.x, &dot1); // length before the cross of the x
		if (ray->dir.y == 0)
			len.x = fabs(all->plr.pos.x - dot1.x);
		else
			len.y = calc_trian_y(all, ray, n.y, &dot2); // length before the cross of the y
		if (len.x < len.y)
		{
			ray->len = len.x; // if the ray first crosses x, ray`s length is len.x
			ray->dot = dot1;
			map.x += n.x;
			all->walls.side = (ray->dir.x < 0) ? all->tex.wtx : all->tex.etx;
			all->walls.side.tag = (ray->dir.x < 0) ? 'W' : 'E';
		}
		else
		{
			ray->len = len.y; // if the ray first crosses y, ray`s length is len.y
			ray->dot = dot2; // dot2.x is calculated in calc_triangle_y
			map.y += n.y;
			all->walls.side = (ray->dir.y < 0) ? all->tex.ntx : all->tex.stx;
			all->walls.side.tag = (ray->dir.y < 0) ? 'N' : 'S';
		}
		if (all->map.map[map.y][map.x] == '2')
		{
			init_spr(all, map);
		}
	}
	return (0);
}

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
		camera_plane = 2 * x / (double)all->data.res1 - 1; // calculated camera_plane which is perpendicular
		ray.dir.x = all->plr.dir.x + all->plr.plane.x * camera_plane; // current ray direction inside the camera_plane
		ray.dir.y = all->plr.dir.y + all->plr.plane.y * camera_plane;
		calc_grid(all, &ray);
		perp_vector(all, camera_plane, &ray);
		draw_walls(all, &ray, x);
		z_buf[x] = all->walls.bottom;
		x++;
	}
	draw_sprites(z_buf, all);
}