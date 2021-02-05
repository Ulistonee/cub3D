#include "cub3D.h"
#include "get_next_line/get_next_line.h"

int main(){
	int 			fd;
	char			*line;
	t_all			all;

	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
			parse_map(&all, line);
		else
			parse_other(&all, line);
		ft_free_mem(&line);
//	 we have to free line after the parser because the line`s pointer gets
//	 broken

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