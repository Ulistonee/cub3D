#include "cub3D.h"

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	if (x < all->data.res1 && y < all->data.res2)
	{
		dst = all->display.addr + (y * all->display.line_length + x *
				(all->display.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int 			key_hook(int keynumber, t_all *all)
{
		double			old_x;

		if (keynumber == ESC)
			exit(0);
		if (keynumber == W || keynumber == UP)
			if (all->map.map[(int)(all->player.pos.y - STEP)][(int)(all->player.pos.x)] == '0')
				all->player.pos.y -= STEP;
		if (keynumber == S || keynumber == DOWN)
			if (all->map.map[(int)(all->player.pos.y + STEP)][(int)(all->player.pos.x)] == '0')
				all->player.pos.y += STEP;
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
			if (all->map.map[(int)(all->player.pos.y)][(int)(all->player.pos.x - STEP)] == '0')
				all->player.pos.x -= STEP;
		if (keynumber == D)
			if (all->map.map[(int)(all->player.pos.y)][(int)(all->player.pos.x + STEP)] == '0')
				all->player.pos.x += STEP;
		if (keynumber == RIGHT)
			{
				old_x = all->player.dir.x;
				all->player.dir.x = old_x * cos(ANGLE) - all->player.dir.y * sin(ANGLE);
				all->player.dir.y = old_x * sin(ANGLE) + all->player.dir.y * cos(ANGLE);
				old_x = all->player.plane.x;
				all->player.plane.x = old_x * cos(ANGLE) - all->player.plane.y * sin(ANGLE);
				all->player.plane.y = old_x * sin(ANGLE) + all->player.plane.y * cos(ANGLE);
			}
		mlx_destroy_image(all->display.mlx, all->display.img);
		all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
		all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
											  &all->display.line_length, &all->display.endian);
//		draw_map(all);
		draw_player(all);
		mlx_put_image_to_window(all->display.mlx, all->display.mlx_win, all->display.img, 0, 0);
		return (0);
}

int				main(int argc, char *argv[])
{
	t_all			all;

	parser(&all, argv[1]);
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	set_player(&all);
	visualize(&all);
	raycast(&all);
	mlx_hook(all.display.mlx_win, 2, (1L<<0), key_hook, &all);
	mlx_loop(all.display.mlx);
	return 0;
}
