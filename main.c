#include "cub3D.h"

int				main(int argc, char *argv[])
{
	int 			fd;
	char			*line;
	t_all			all;
	int				counter;
	int 			i;

	counter = 0;
	fd = open(argv[1], O_RDONLY);
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
	all.map.map = (char**)malloc(sizeof(char*) * counter); // allocate memory for two-dimensional array
//	handle_error(errno, &all);
	fd = open(argv[1], O_RDONLY); // open flow again for parsing
//	handle_error(errno, &all);
	i = 0;
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			all.map.map[i++] = ft_strdup(line);
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
	i = 0;
	while (i < counter)
	{
		printf("MAP: %s\n", all.map.map[i++]);
	}
	return 0;
}