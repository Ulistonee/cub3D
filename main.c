#include "cub3D.h"

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	dst = all->display.addr + (y * all->display.line_length + x *
			(all->display.bits_per_pixel /
			8));
	*(unsigned int*)dst = color;
}

int				draw_map(t_all *all)
{
	all->display.mlx = mlx_init();
	all->display.mlx_win = mlx_new_window(all->display.mlx, all->data.res1, all->data.res2,
									   "My_cub3D");
	all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
	all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
			&all->display.line_length, &all->display.endian);
	int x = 0;
	int y = 0;
//	printf("[%s]\n", all->map.map[0]);
	while (y < all->map.lines)
	{
//		printf("Y:%s\n", all->map.map[y]);
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
//			printf("X:%d\t", x);
			if (all->map.map[y][x] == '1')
			{
//				my_mlx_pixel_put(all, x, y, 0xFFFFFF);
				scaler(all, x, y);
			}
			x++;
		}
//		printf("\n");6
		y++;
	}
	mlx_put_image_to_window(all->display.mlx, all->display.mlx_win,
						 all->display.img,0, 0);
	mlx_loop(all->display.mlx);
	return (0);
}

int				main(int argc, char *argv[])
{
	int 			fd;
	char			*line;
	t_all			all;
	int 			i;

	all.map.lines = 0; // lines` counter
	fd = open(argv[1], O_RDONLY);
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	while (get_next_line(fd, &line)) // start GNL to count map size
	{
		if (is_map(line))
		{
			all.map.lines++;
			ft_free_mem(&line);
		}
	}
	close(fd);
	all.map.map = (char**)malloc(sizeof(char*) * all.map.lines); // allocate memory for two-dimensional array
//	handle_error(errno, &all);
	fd = open(argv[1], O_RDONLY); // open flow again for parsing
//	handle_error(errno, &all);
	i = 0;
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			all.map.map[i++] = ft_strdup(line); // create x-lines in the
			// two-dimensional array
		}
		else
			parse_other(&all, line);
		ft_free_mem(&line);
	}
	printf("RES_1: %d\n", all.data.res1);
	printf("RES_2: %d\n", all.data.res2);
	printf("NO: %s\n", all.data.no);
	printf("SO: %s\n", all.data.so);
	printf("WE: %s\n", all.data.we);
	printf("EA: %s\n", all.data.ea);
	printf("FLR_1: %d\n", all.data.flr_1);
	printf("FLR_2: %d\n", all.data.flr_2);
	printf("FLR_3: %d\n", all.data.flr_3);
	printf("CEIL_1: %d\n", all.data.ceil_1);
	printf("CEIL_2: %d\n", all.data.ceil_2);
	printf("CEIL_3: %d\n", all.data.ceil_3);
	printf("LINES: %d\n", all.map.lines);
	i = 0;
	while (i < all.map.lines)
	{
		printf("MAP: %s\n", all.map.map[i++]);
	}
	draw_player(&all);
	draw_map(&all);
	return 0;
}
