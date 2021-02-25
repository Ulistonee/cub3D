#include "cub3D.h"

int				draw_map(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (all->map.map[y][x] == '1')
				scaler(all, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->display.mlx, all->display.mlx_win,
							all->display.img,0, 0); //
	return (0);
}
