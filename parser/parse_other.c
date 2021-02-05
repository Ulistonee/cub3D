#include "../cub3D.h"
#include <stdlib.h>
#include <stdio.h>

int			parse_other(t_all *all, char *line)
{
	char 		*srch;

	if (*line == 'R')
	{
		data->res1 = ft_atoi(2 + line);
//		printf("DEBUG_PARSER_R_1: %d\n", data->res1);
		srch = ft_strchr(2+line, ' ');
//		printf("DEBUG_S_SPACE: %s\n", srch);
		data->res2 = ft_atoi(srch);
//		printf("DEBUG_PARSER_R_2: %d\n", data->res2);
	}
	else if (*line == 'N' && *(1 + line) == 'O')
	{
		data->no = ft_strdup(3 + line);
//		data->no = 3 + line;
//		printf("DEBUG_NO: %s\n", data->no);
	}
	else if (*line == 'S' && *(1 + line) == 'O')
	{
		data->so = ft_strdup(3 + line);
//		printf("DEBUG_SO: %s\n", data->so);
	}
	else if (*line == 'W' && *(1 + line) == 'E')
	{
		data->we = ft_strdup(3 + line);
//		printf("DEBUG_WE: %s\n", data->we);
	}
	else if (*line == 'E' && *(1 + line) == 'A')
	{
		data->ea = ft_strdup(3 + line);
//		printf("DEBUG_EA: %s\n", data->ea);
	}
	else if (*line == 'F')
	{
		data->flr_1 = ft_atoi(2 + line);
		srch = ft_strchr(line, ',');
//		printf("DEBUG_FLR_2: %s\n", srch);
		data->flr_2 = ft_atoi(1 + srch);
		srch = ft_strchr(1 + srch, ',');
		data->flr_3 = ft_atoi(1 + srch);
	}
	else if (*line == 'C')
	{
		data->ceil_1 = ft_atoi(2 + line);
//		printf("DEBUG_CEIL_1: %d\n", data->ceil_1);
		srch = ft_strchr(line, ',');
		data->ceil_2 = ft_atoi(1 + srch);
//		printf("DEBUG_CEIL_2: %d\n", data->ceil_2);
		srch = ft_strchr(1 + srch, ',');
		data->ceil_3 = ft_atoi(1 + srch);
	}
	return (0);
}