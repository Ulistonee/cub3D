#include "cub3D.h"

int					validate_map(int world_map)
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
	return (0);
}

int					main()
{
	int worldMap[8][5] =
			{
					{1,1,1,1,1,1,1,1},
					{1,2,0,0,0,2,0,1},
					{1,0,0,'N',0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1},

			};

	validate_map(worldMap);
	return (0);
}