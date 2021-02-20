#include "cub3D.h"

void 			draw_ray(t_all *all)
{
	int 			i;
	double 			step;
	t_pos			dot_ray;

	i = 0;
	dot_ray.x = all->player.pos.x;
	dot_ray.y = all->player.pos.y;
	step = 0.1;
	while (all->map.map[(int)dot_ray.y][(int)dot_ray.x] != '1')
	{
		dot_ray.y += step * all->player.dir.y;
		dot_ray.x += step * all->player.dir.x;
		my_mlx_pixel_put(all, dot_ray.x * SCALE, dot_ray.y * SCALE, 0x00FF7F);
		i++;
	}
}

void 			draw_player(t_all *all)
{
	my_mlx_pixel_put(all, all->player.pos.x * SCALE, all->player.pos.y * SCALE, 0xFF0000);
	draw_ray(all);
}
