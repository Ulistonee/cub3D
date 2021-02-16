#include "cub3D.h"

void 			draw_player(t_all *all)
{
	double			angle;
	int 			i;
	double			x;
	double 			y;
	double 			step;
	t_player		vector;

	vector.x = 1;
	vector.y = 1;
	i = 0;
	x = all->player.x;
	y = all->player.y;
	step = 0.1;
	my_mlx_pixel_put(all, all->player.x * SCALE, all->player.y * SCALE, 0xFF0000);
	while (i < 5)
	{
		y += step * vector.x;
		x += step * vector.y;
		my_mlx_pixel_put(all, x * SCALE, y * SCALE, 0x00FF7F);
		i++;
	}
}
