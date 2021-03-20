#include "../cub3D.h"

int					valid_res(char *line)
{
	while (*line == ' ')
		line++;
	while (ft_isdigit(line))
		line++;

}

int					validate_map(t_all *all)
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
			if (!ft_strchr(VALID_SYMBOLS, all->map.map[y][x])
				return (-1);
			x++;
		}
		y++;
	}
}




//int					enter_validator(t_all *all, char *file_name)
//{
//	int				fd;
//	char			*line;
//
//	fd = open(file_name, O_RDONLY);
//	while(get_next_line(fd, &line))
//	{
//		validator(line);
//	}
//}