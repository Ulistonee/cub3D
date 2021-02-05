#include "../cub3D.h"

int 		parse_map(t_all *all, char *line)
{
	if (ft_strchr(VALID_SYMBOLS, *line))
		all->map.map = &line;
		return (1);
}