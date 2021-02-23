#include "cub3D.h"
/*
 * Returns the length of the ray from player position to the crossing dot.
 * Also returns the crossing dot`s coordinates.
 *
 */
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
	int 		n_x;
	int 		n_y;

	//	printf("dir: x: %f\ty: %f\n", all->player.dir.x, all->player.dir.y);
//	printf("plane: x: %f\ty: %f\n", all->player.plane.x, all->player.plane.y);
//	printf("ray: x: %f\ty: %f\n", ray->dir.x, ray->dir.y);
	n_x = 1;
	n_y = 1;
	ray->dot.x = all->player.pos.x;
	ray->dot.y = all->player.pos.y;
	while (all->map.map[(int)(ray->dot.y)][(int)(ray->dot.x)] != '1')
	{
		my_mlx_pixel_put(all, (int)(ray->dot.x * SCALE), (int)(ray->dot.y * SCALE), 0xFF0000);
		dot1.x = (ray->dir.x < 0) ? (int)all->player.pos.x + 1 - n_x : (int)all->player.pos.x + n_x;
		dot2.y = (ray->dir.y < 0) ? (int)all->player.pos.y + 1 - n_y : (int)all->player.pos.y + n_y; // check the y cross
		if (ray->dir.x == 0)
			len.y = fabs(all->player.pos.y - dot2.y);
		else
			len.x =  calc_trian(all, ray, n_x, &dot1); // length before the cross of the x
		if (ray->dir.y == 0)
			len.x = fabs(all->player.pos.x - dot1.x);
		else
			len.y = calc_trian_y(all, ray, n_y, &dot2); // length before the cross of the y
		if (len.x < len.y)
		{
			ray->len = len.x; // if the ray first crosses x, ray`s length is len.x
			ray->dot.x = dot1.x;
			ray->dot.y = dot1.y; // dot1.y is calculated in calc_triangle
			n_x++;
		}
		else
		{
			ray->len = len.y; // if the ray first crosses y, ray`s length is len.y
			ray->dot.x = dot2.x; // dot2.x is calculated in calc_triangle_y
			ray->dot.y = dot2.y;
			n_y++;
		}
	}
	return (0);
}

void				raycast(t_all *all)
{
	t_ray		ray;
	double		camera_plane;
	int			x;

	x = 0;
//	printf("dir: x: %f\ty: %f\n", all->player.dir.x, all->player.dir.y);
//	printf("plane: x: %f\ty: %f\n", all->player.plane.x, all->player.plane.y);
	while (x < all->data.res1)
	{
		camera_plane = 2 * x / (double)all->data.res1 - 1; // calculated camera_plane which is perpendicular
		ray.dir.x = all->player.dir.x + all->player.plane.x * camera_plane; // current ray direction inside the camera_plane
		ray.dir.y = all->player.dir.y + all->player.plane.y * camera_plane; // current ray direction inside the camera_plane
		calc_grid(all, &ray);
		x++;
	}
}