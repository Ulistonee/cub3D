#include "cub3D.h"

int 				display(t_all *all)
{
	all->display.mlx = mlx_init();
	all->display.mlx_win = mlx_new_window(all->display.mlx, all->data.res1, all->data.res2,
										  "My_cub3D");
	all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
	all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
										  &all->display.line_length, &all->display.endian);
	return (1);
}

int			visualize(t_all *all)
{
	display(all);
	draw_map(all);

	return (0);
}