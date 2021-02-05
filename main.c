#include "cub3D.h"
#include "get_next_line/get_next_line.h"

int				main()
{
	int 			fd;
	char			*line;
	t_all			all;
	int 			counter;

	counter = 0;
	fd = open("../map.cub", O_RDONLY);
	handle_error(errno, &all);
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			counter++;
		}
		ft_free_mem(&line);
	}
	close(fd);
	fd = open("../map.cub", O_RDONLY);
	handle_error(errno, &all);
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			parse_map(&all, line);
			counter++;
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
	return 0;
}