#include "cub3D.h"

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	if (x < all->data.res1 && y < all->data.res2 && x >= 0 && y >= 0)
	{
		dst = all->display.addr + (y * all->display.line_length + x *
																  (all->display.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int 				display(t_all *all)
{
	all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
	all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
										  &all->display.line_length, &all->display.endian);
	//to call all the calculations and drawing
	raycast(all);
	if (all->save_flag == 1)
		take_screenshot(all);
	mlx_put_image_to_window(all->display.mlx, all->display.mlx_win, all->display.img, 0, 0);
	mlx_destroy_image(all->display.mlx, all->display.img);
	return (1);
}
