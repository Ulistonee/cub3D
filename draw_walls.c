#include "cub3D.h"

int				draw_walls(t_all *all, t_ray *ray, int x)
{
	int				y;

	y = 0;
	all->walls.wall_height = all->data.res2 / ray->len;
	all->walls.top = all->data.res2 / 2 - all->walls.wall_height / 2;
	all->walls.bottom = all->data.res2 / 2 + all->walls.wall_height / 2;
	while (y < all->data.res2)
	{
		if (y > all->walls.top && y < all->walls.bottom)
			my_mlx_pixel_put(all, x, y, all->walls.side);
//			printf("wall_color: %d\n", all->walls.side);
		y++;
	}
	return (0);
}