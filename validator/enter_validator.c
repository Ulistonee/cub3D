#include "../cub3D.h"

void				restore_map(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == '3')
		all->map.map[y][x] = '0';
	if (all->map.map[y][x] == 'N')
		all->map.map[y][x] = 'n';


}

int					valid_closed(t_all *all, int x, int y)
{
	if ( x < 0 || y < 0 || y >= all->map.lines || all->map.map[y][x] == '\0' || all->map.map[y][x] == ' ')
		handle_error("Invalid map\n", all);
	if (all->map.map[y][x] == '1' || all->map.map[y][x] == '3' || all->map.map[y][x] == 'P' || all->map.map[y][x] == 't')
		return (1);
	if (all->map.map[y][x] == '0')
		all->map.map[y][x] = '3';
	all->data.p = ft_strchr("NEWS", all->map.map[y][x]);
	if (*all->data.p == 'N')
		all->map.map[y][x] = 'n';
	if (*all->data.p == 'E')
		all->map.map[y][x] = 'E';
	if (*all->data.p == 'W')
		all->map.map[y][x] = 'W';
	if (*all->data.p == 'S')
		all->map.map[y][x] = 'S';
	if (all->map.map[y][x] == '2')
		all->map.map[y][x] = 't';
	return(	valid_closed(all, x, y - 1) &&
			valid_closed(all, x, y + 1) &&
			valid_closed(all, x - 1, y) &&
			valid_closed(all, x + 1, y)
			);
}

int					valid_res(char *line)
{
	while (*line == ' ')
		line++;
	while (ft_isdigit(line))
		line++;

}

void					valid_map(t_all *all)
{
	int 			x;
	int 			y;

	x = 0;
	y = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (!ft_strchr(VALID_SYMBOLS, all->map.map[y][x]))
				printf("Invalid map\n");
			x++;
		}
		y++;
	}
}

int					enter_validator(t_all *all)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
//	if (!valid_map(all))
//		return (-1);
	while(y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (ft_strchr("NEWS02", all->map.map[y][x]))
			{
				valid_closed(all, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}