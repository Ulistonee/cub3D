#include "../cub3D.h"

int		parser(t_struct *data, char *line)
{
	if (*line == 'R')
	{
		data->resolution = ft_atoi(++line);
		printf("%d\n", data->resolution);
	}
	return (0);
}