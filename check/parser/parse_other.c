#include "../cub3D.h"

int			parse_other(t_all *all, char *line)
{
	char 		*srch;

	if (*line == 'R')
	{
		all->data.res1 = ft_atoi(2 + line);
		srch = ft_strchr(2+line, ' ');
		all->data.res2 = ft_atoi(srch);
	}
	else if (*line == 'N' && *(1 + line) == 'O')
	{
		all->data.no = ft_strdup(3 + line);
	}
	else if (*line == 'S' && *(1 + line) == 'O')
	{
		all->data.so = ft_strdup(3 + line);
	}
	else if (*line == 'W' && *(1 + line) == 'E')
	{
		all->data.we = ft_strdup(3 + line);
	}
	else if (*line == 'E' && *(1 + line) == 'A')
	{
		all->data.ea = ft_strdup(3 + line);
	}
	else if (*line == 'F')
	{
		all->data.flr_1 = ft_atoi(2 + line);
		srch = ft_strchr(line, ',');
		all->data.flr_2 = ft_atoi(1 + srch);
		srch = ft_strchr(1 + srch, ',');
		all->data.flr_3 = ft_atoi(1 + srch);
		all->data.flr = create_rgb(all->data.flr_1, all->data.flr_2, all->data.flr_3);
	}
	else if (*line == 'C')
	{
		all->data.ceil_1 = ft_atoi(2 + line);
		srch = ft_strchr(line, ',');
		all->data.ceil_2 = ft_atoi(1 + srch);
		srch = ft_strchr(1 + srch, ',');
		all->data.ceil_3 = ft_atoi(1 + srch);
		all->data.ceil = create_rgb(all->data.ceil_1, all->data.ceil_2, all->data.ceil_3);
	}
	else if (*line == 'S')
	{
		all->data.s = ft_strdup(2 + line);
	}
	return (0);
}