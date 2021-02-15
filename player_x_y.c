#include "cub3D.h"

int 		player_x_y(t_all *all)
{
	int x = 0;
	int y = 0;
//	printf("[%s]\n", all->map.map[0]);
	while (y < all->map.lines)
	{
//		printf("Y:%s\n", all->map.map[y]);
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
//			printf("X:%d\t", x);
			if (ft_strchr("NEWS", all->map.map[y][x])) {
				all->player.x = x;
				all->player.y = y;
//				printf("Player_x: %d\n", all->player.x);
//				printf("Player_y: %d\n", all->player.y);
//				int n = 0;
//				while (n++ < 10) {
//					my_mlx_pixel_put(all, (x * SCALE) + n, y * SCALE + n, 0xFFFFFF);
//				}
			}
			x++;
		}
//		printf("\n");6
		y++;
	}
	return (0);
}
