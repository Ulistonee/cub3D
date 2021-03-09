#include "cub3D.h"

int					init_textures(t_all *all)
{
	all->tex.n_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.no, &all->tex.n_tex.w, &all->tex.n_tex.h);
	all->tex.e_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.ea, &all->tex.e_tex.w, &all->tex.e_tex.h);
	all->tex.w_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.we, &all->tex.w_tex.w, &all->tex.w_tex.h);
	all->tex.s_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.so, &all->tex.s_tex.w, &all->tex.s_tex.h);
	printf("CHECK_INIT");
	return (0);
}

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
//	draw_map(all);
	init_textures(all);

	return (0);
}