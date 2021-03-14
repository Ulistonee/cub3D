#include "cub3D.h"

void 					bubble_sort(t_all *all)
{
	int					i;
	int					j;
	t_sprite 			temp;

	i = 0;
	while(i < all->spr_count)
	{
		j = all->spr_count - 1;
		while(j > i)
		{
			if(all->spr_arr[j - 1].dist > all->spr_arr[j].dist)
			{
				temp = all->spr_arr[j - 1];
				all->spr_arr[j - 1] = all->spr_arr[j];
				all->spr_arr[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void					count_dist(t_all *all)
{
	double				dist_to_spr;
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (i < all->spr_count)
	{
		while(j < all->spr_count)
		{
			dist_to_spr = len_of_vec(all->player.pos.x - all->spr_arr->coord.x, all->player.pos.y - all->spr_arr->coord.y);
			all->spr_arr[i].dist = dist_to_spr;
		}
		j++;
	}
	i++;
}

void					draw_sprite(double *z_buf, t_all *all)
{
	count_dist(all);
	bubble_sort(all);
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