#include "cub3D.h"

int				draw_map(t_all *all);

int 			count_lines(char *file_name)
{
	int 			fd;
	char			*line;
	int 			counter;

	counter = 0; // lines` counter
	fd = open(file_name, O_RDONLY);
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	while (get_next_line(fd, &line)) // start GNL to count map size
	{
		if (is_map(line))
		{
			counter++;
			ft_free_mem(&line);
		}
	}
	close(fd);
	return (counter);
}

int 				parse_file(char *file_name, t_all *all)
{
	int 			fd;
	char			*line;
	int 			i;

	all->map.map = (char**)malloc(sizeof(char*) * all->map.lines); // allocate memory for two-dimensional array
//	handle_error(errno, &all);
	fd = open(file_name, O_RDONLY); // open flow again for parsing
//	handle_error(errno, &all);
	i = 0;
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			all->map.map[i++] = ft_strdup(line); // create x-lines in the
			// two-dimensional array
		}
		else
			parse_other(all, line);
		ft_free_mem(&line);
	}
	return (1);
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
		double 			old_x;

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
		draw_map(all);
		draw_player(all);
		mlx_put_image_to_window(all->display.mlx, all->display.mlx_win, all->display.img, 0, 0);
		return (0);
}

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
						 all->display.img,0, 0); // ?
	return (0);
}

int				main(int argc, char *argv[])
{
	t_all			all;

	all.map.lines = count_lines(argv[1]); // lines` counter
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	if (!(parse_file(argv[1], &all)))
		return (-1);
	set_player_x_y(&all);
//	printf("PLAYER_X: %d\n", all.player.x);
//	printf("PLAYER_Y: %d\n", all.player.y);
//	printf("RES_1: %d\n", all.data.res1);
//	printf("RES_2: %d\n", all.data.res2);
//	printf("NO: %s\n", all.data.no);
//	printf("SO: %s\n", all.data.so);
//	printf("WE: %s\n", all.data.we);
//	printf("EA: %s\n", all.data.ea);
//	printf("FLR_1: %d\n", all.data.flr_1);
//	printf("FLR_2: %d\n", all.data.flr_2);
//	printf("FLR_3: %d\n", all.data.flr_3);
//	printf("CEIL_1: %d\n", all.data.ceil_1);
//	printf("CEIL_2: %d\n", all.data.ceil_2);
//	printf("CEIL_3: %d\n", all.data.ceil_3);
//	printf("LINES: %d\n", all.map.lines);
//	i = 0;
//	while (i < all.map.lines)
//	{
//		printf("MAP: %s\n", all.map.map[i++]);
//	}
	display(&all);
	draw_map(&all);
	raycast(&all);
	mlx_hook(all.display.mlx_win, 2, (1L<<0), key_hook, &all);
	mlx_loop(all.display.mlx);
	return 0;
}
