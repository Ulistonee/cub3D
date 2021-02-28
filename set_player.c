#include "cub3D.h"

int			set_player_plane(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->player.plane.x = FOV_L; // height of the camera plane 0.577
		all->player.plane.y = 0;
		all->walls.side = 0xFF00FF;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->player.plane.x = 0;
		all->player.plane.y = FOV_L;
		all->walls.side = 0xFF00FF;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->player.plane.x = 0;
		all->player.plane.y = -FOV_L;
		all->walls.side = 0xFF00FF;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->player.plane.x = -FOV_L;
		all->player.plane.y = 0;
		all->walls.side = 0xFF00FF;
	}
	return (1);
}

int 		set_player_dir(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->player.dir.x = 0;
		all->player.dir.y = -1;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->player.dir.x = 1;
		all->player.dir.y = 0;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->player.dir.x = -1;
		all->player.dir.y = 0;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->player.dir.x = 0;
		all->player.dir.y = 1;
	}
	return (1);
};
int 		set_player(t_all *all)
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
				all->player.pos.x = x + 0.5;
				all->player.pos.y = y + 0.5;
				set_player_dir(all, x, y);
				set_player_plane(all, x, y);
				all->map.map[y][x] = '0'; // to get rid of the invisible wall
			}
			x++;
		}
		y++;
	}
	return (0);
}