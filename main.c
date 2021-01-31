#include "cub3D.h"
#include "get_next_line/get_next_line.h"

int main(){
	int 			fd;
	char			*line;
	t_struct		data;

	fd = open("../map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		parser(&data, line);
		printf("%s\n", line);
		//parser(data, &map);
	}
	return 0;
}