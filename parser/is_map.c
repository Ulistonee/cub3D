#include "../cub3D.h"

int 		is_map(char *line)
{
	if (*line == '\0')
		return (0);
	while(*line)
	{
		if (!(ft_strchr(VALID_SYMBOLS, *line)))
			return (0);
		line++;
	}
	return (1);
}