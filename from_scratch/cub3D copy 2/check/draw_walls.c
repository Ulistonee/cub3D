#include "cub3D.h"

int						draw_walls(t_all *all, t_ray *ray, int x)
{
	int						y;
	t_pos					text_dot;
	int						color;

	y = 0;
	all->walls.wall_height = all->data.res2 / ray->k;
	all->walls.top = all->data.res2 / 2 - all->walls.wall_height / 2;
	all->walls.bottom = all->data.res2 / 2 + all->walls.wall_height / 2;
	if (all->walls.side.tag == 'N' || all->walls.side.tag == 'S')
		text_dot.x = (ray->dot.x - (int)ray->dot.x) * all->walls.side.w;
	else
		text_dot.x = (1 - ray->dot.y + (int)ray->dot.y) * all->walls.side.w;
	while (y < all->data.res2)
	{
		if (y > all->walls.top && y < all->walls.bottom)
		{
			text_dot.y = (y - all->walls.top) * all->walls.side.h / all->walls.wall_height;
			color = get_color(&all->walls.side, (int)text_dot.x, (int)text_dot.y);
			my_mlx_pixel_put(all, x, y, color);
		}
		if (y < all->walls.top)
			my_mlx_pixel_put(all, x, y, all->data.flr);
		if (y > all->walls.bottom)
			my_mlx_pixel_put(all, x, y, all->data.ceil);
		y++;
	}
	return (0);
}