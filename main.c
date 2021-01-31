#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub3D.h"

int main() {
	int 			fd;
	char			buf[5];
	int				status;
	t_struct		data;
	fd = open("map.cub", O_RDONLY);
	while (read(fd, buf, 5))
	{
		status = parser(data, &map);
	}
	return 0;
}