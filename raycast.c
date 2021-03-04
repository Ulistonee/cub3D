#include "cub3D.h"

double 				calc_trian(t_all *all, t_ray *ray, int n_x, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.x = fabs(dot->x - all->player.pos.x); // difference between the starting x and the intersection point
	cath.y = fabs(ray->dir.y * cath.x / ray->dir.x); // similarity of triangles
	dot->y = (ray->dir.y > 0) ? all->player.pos.y + cath.y : all->player.pos.y - cath.y; // the sum of the starting y and the cath.y
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2)); // length of the ray
	return (len);
}

double 				calc_trian_y(t_all *all, t_ray *ray, int n_x, t_pos *dot)
{
	t_pos			cath;
	double			len;

	cath.y = fabs(dot->y - all->player.pos.y); // difference between the starting x and the intersection point
	cath.x = fabs(ray->dir.x * cath.y / ray->dir.y); // similarity of triangles
	dot->x = (ray->dir.x > 0) ? all->player.pos.x + cath.x : all->player.pos.x - cath.x; // the sum of the starting y and the cath.y
	len = sqrt(pow(cath.x, 2) + pow(cath.y, 2)); // length of the ray
	return (len);
}

int					calc_grid(t_all *all, t_ray *ray)
{
	t_pos		len;
	t_pos		dot1; // first grid cross occurrence
	t_pos		dot2; // first grid cross occurrence
	t_posi		map;
	t_posi 		n;

	n.x =  (ray->dir.x < 0)? -1 : 1;
	n.y =  (ray->dir.y < 0)? -1 : 1;
	map.x = (int)all->player.pos.x; // starting point for the crossing dot search because we have to enter the cycle
	map.y = (int)all->player.pos.y; // starting point for the crossing dot search because we have to enter the cycle
	while (all->map.map[map.y][map.x] != '1')
	{
		dot1.x = (ray->dir.x < 0) ? map.x : map.x + 1; // first we calculate one of the whole integers. Either x or y
		dot2.y = (ray->dir.y < 0) ? map.y : map.y + 1; // first we calculate one of the whole integers. Either x or y
		if (ray->dir.x == 0) // if the ray is parallel to one the grid`s axis`s then we just calculate the difference between player`s y and grid`s y
			len.y = fabs(all->player.pos.y - dot2.y);
		else
			len.x =  calc_trian(all, ray, n.x, &dot1); // length before the cross of the x
		if (ray->dir.y == 0)
			len.x = fabs(all->player.pos.x - dot1.x);
		else
			len.y = calc_trian_y(all, ray, n.y, &dot2); // length before the cross of the y
		if (len.x < len.y)
		{
			ray->len = len.x; // if the ray first crosses x, ray`s length is len.x
			ray->dot = dot1;
			map.x += n.x;
		}
		else
		{
			ray->len = len.y; // if the ray first crosses y, ray`s length is len.y
			ray->dot = dot2; // dot2.x is calculated in calc_triangle_y
			map.y += n.y;
		}
//		my_mlx_pixel_put(all, (int)(ray->dot.x * SCALE), (int)(ray->dot.y * SCALE), 0xFF0000);
	}
	return (0);
}

void				raycast(t_all *all)
{
	t_ray		ray;
	double		camera_plane;
	int			x;
<<<<<<< HEAD
	int			k;
	double		ray_len;
	double		cath_len;
	double		a;
	double		b;
=======
	double		k;
>>>>>>> b1f5b6062ed686b2444fe412d12dae215d7f74bd

	x = 0;
	while (x < all->data.res1)
	{
		camera_plane = 2 * x / (double)all->data.res1 - 1; // calculated camera_plane which is perpendicular
<<<<<<< HEAD
		a = all->player.dir.x + all->player.plane.x * camera_plane; // current ray direction inside the camera_plane
		b = all->player.dir.y + all->player.plane.y * camera_plane;
		ray_len = len_of_vec(a, b);
		cath_len = len_of_vec((all->player.plane.x * camera_plane), (all->player.plane.y * camera_plane));
		k = sqrt(pow(ray_len, 2) - pow(cath_len, 2));
		ray.dir.x = all->player.dir.x + all->player.plane.x * camera_plane * k; // current ray direction inside the camera_plane
		ray.dir.y = all->player.dir.y + all->player.plane.y * camera_plane * k;
//		printf("ray_len: %f\n", ray_len);
//		printf("cath_len: %f\n", cath_len);
=======
		ray.dir.x = all->player.dir.x + all->player.plane.x * camera_plane; // current ray direction inside the camera_plane
		ray.dir.y = all->player.dir.y + all->player.plane.y * camera_plane;
>>>>>>> b1f5b6062ed686b2444fe412d12dae215d7f74bd
		calc_grid(all, &ray);
		ray.k = perp_vector(all, camera_plane, &ray);
//		ray.k = ray.len;
		printf("len: %.4f\tk: %.4f\n", ray.len, ray.k);
		draw_walls(all, &ray, x);
		x++;
	}
}