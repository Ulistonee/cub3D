#include "cub3D.h"

int					main(int argc, char *argv[])
{
	t_all			all;

	parser(&all, argv[1]);
	if (!enter_validator(&all))
		return (-1);
	all.display.mlx = mlx_init();
	all.display.mlx_win = mlx_new_window(all.display.mlx, all.data.res1, all.data.res2,
										  "My_cub3D");
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	init_game(&all);
	display(&all);
	mlx_hook(all.display.mlx_win, 2, (1L<<0), key_hook, &all);
	mlx_loop_hook(all.display.mlx, display, &all);
//	mlx_hook(all.display.mlx_win, 2, (1L<<0), key_hook, &all);
	mlx_loop(all.display.mlx);
	return (0);
}
