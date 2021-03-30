#include "cub3D.h"


int			scaler(t_all *all, int x_input, int y_input, int color)
{
	int 		x;
	int 		y;
	int			scl;

//	printf("check\n");
	x = 0;
	y = 0;
	all->s.s.scl = all->s.s.h/all->w.wall_h;
	while (y < scl)
	{
		x = 0;
		while (x < scl)
		{
			my_mlx_pixel_put(all, x + (x_input * all->s.s.scl), y + (y_input * all->s.s.scl), color);
			x++;
		}
		y++;
	}
	return (0);
}