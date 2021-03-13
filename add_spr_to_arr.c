#include "cub3D.h"

void					draw_sprite(double *z_buf, t_all *all)
{

}



/*
 * we initialize a sprite, then we add it to the spr_array. We include info about its coordinates.
 */
void 					add_spr_to_arr(t_all *all, t_sprite **arr_m)
{
	t_sprite			arr[all->spr_count];
	int 				i;
	int 				x;
	int 				y;
	t_sprite			spr;

	x = 0;
	y = 0;
	i = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (all->map.map[y][x] == '2')
			{
				spr.coord.x = x + 0.5;
				spr.coord.y = y + 0.5;
				arr[i] = spr;
				i++;
			}
			x++;
		}
		y++;
	}
	*arr_m = arr;
}