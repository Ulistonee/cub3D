#include "../cub3D.h"

int 		parse_map(t_all *all, char *line)
{
	int 		size;

	size = 0;
	if (!(is_map(line))
		return (-1);
	while (*line == '\n')
		size++;
	if (ft_strchr(VAL1ID_SYMBOLS, *line))
		map->map = &line;


}