#include "cub3D.h"

int 			key_hook(int keynumber, t_all *all)
{
		double			old_x;
		t_pos			new_pos;

		if (keynumber == ESC)
			exit(0);
		if (keynumber == W || keynumber == UP)
		{
			new_pos.x = all->player.dir.x * STEP + all->player.pos.x;
			new_pos.y = all->player.dir.y * STEP + all->player.pos.y;
			if (all->map.map[(int)new_pos.y][(int)new_pos.x] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == S || keynumber == DOWN)
		{
			new_pos.x = -all->player.dir.x * STEP + all->player.pos.x;
			new_pos.y = -all->player.dir.y * STEP + all->player.pos.y;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == LEFT)
		{
			old_x = all->player.dir.x;
			all->player.dir.x = old_x * cos(-ANGLE) - all->player.dir.y * sin(-ANGLE);
			all->player.dir.y = old_x * sin(-ANGLE) + all->player.dir.y * cos(-ANGLE);
			old_x = all->player.plane.x;
			all->player.plane.x = old_x * cos(-ANGLE) - all->player.plane.y * sin(-ANGLE);
			all->player.plane.y = old_x * sin(-ANGLE) + all->player.plane.y * cos(-ANGLE);
		}
		if (keynumber == A)
		{
			new_pos.x = all->player.pos.x + all->player.dir.y * STEP;
			new_pos.y = all->player.pos.y - all->player.dir.x * STEP;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == D)
		{
			new_pos.x = all->player.pos.x - all->player.dir.y * STEP;
			new_pos.y = all->player.pos.y + all->player.dir.x * STEP;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == RIGHT)
			{
				old_x = all->player.dir.x;
				all->player.dir.x = old_x * cos(ANGLE) - all->player.dir.y * sin(ANGLE);
				all->player.dir.y = old_x * sin(ANGLE) + all->player.dir.y * cos(ANGLE);
				old_x = all->player.plane.x;
				all->player.plane.x = old_x * cos(ANGLE) - all->player.plane.y * sin(ANGLE);
				all->player.plane.y = old_x * sin(ANGLE) + all->player.plane.y * cos(ANGLE);
			}
//		mlx_destroy_image(all->display.mlx, all->display.img);
//		all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
//		all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
//											  &all->display.line_length, &all->display.endian);
		return (0);
}

int					main(int argc, char *argv[])
{
	t_all			all;

	validate_map(&all, argv[1]);
	parser(&all, argv[1]);
//	enter_validator(&all);
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
	return 0;
}
