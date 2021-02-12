#include "cub3D.h"


int			scaler(t_all *all, int x_input, int y_input)
{
	int 		x;
	int 		y;

//	printf("check\n");
	x = 0;
	y = 0;
	while (y < SCALE)
	{
		x = 0;
		while (x < SCALE)
		{
			my_mlx_pixel_put(all, x + (x_input * SCALE), y + (y_input * SCALE), 0xFFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}