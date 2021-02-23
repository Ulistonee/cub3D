#include "cub3D.h"

int 		set_player_dir(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->player.dir.x = 0;
		all->player.dir.y = -1;
		all->player.plane.x = FOV_L;
		all->player.plane.y = 0;

	}
	if (all->map.map[y][x] == 'E')
	{
		all->player.dir.x = 1;
		all->player.dir.y = 0;
		all->player.plane.x = 0;
		all->player.plane.y = FOV_L;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->player.dir.x = -1;
		all->player.dir.y = 0;
		all->player.plane.x = 0;
		all->player.plane.y = -FOV_L;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->player.dir.x = 0;
		all->player.dir.y = 1;
		all->player.plane.x = -FOV_L;
		all->player.plane.y = 0;
	}
	return (1);
};
int 		set_player_x_y(t_all *all)
{
	int x = 0;
	int y = 0;

	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (ft_strchr("NEWS", all->map.map[y][x]))
			{
				all->player.pos.x = x;
				all->player.pos.y = y;
				set_player_dir(all, x, y);
				all->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (0);
}
