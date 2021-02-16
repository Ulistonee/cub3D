#include "cub3D.h"

int 		player_x_y(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (ft_strchr("NEWS", all->map.map[y][x])) {
				all->player.x = x;
				all->player.y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}
