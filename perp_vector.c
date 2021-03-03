#include "cub3D.h"

double			perp_vector(t_all *all, double camera_plane, t_ray *ray)
{
	double			ray_len;
	double			camera_len;
	double			k;
	double			k1;

	ray_len = len_of_vec(ray->dir.x, ray->dir.y);
	camera_len = len_of_vec((all->player.plane.x * camera_plane), (all->player.plane.y * camera_plane));
	k = sqrt(pow(ray->len, 2) - pow(camera_len, 2));
	k1 = k * ray->len / ray_len;
	return (k1);
}