#include "../cub3D.h"

int 		is_map(char *line)
{
	while(*line)
	{
		if (!(ft_strchr(VALID_SYMBOLS, *line)))
			return (-1);
		line++;
	}
	return (1);
}