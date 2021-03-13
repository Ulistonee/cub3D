#include "cub3D.h"

double						add_spr_to_arr(t_all *all)
{
	t_pos				map;
	int 				i;

	i = 0;
	all->spr.coord.x = map.x - all->player.pos.x;
	all->spr.coord.y = map.y - all->player.pos.y;
	all->spr.dist = len_of_vec(all->spr.coord.x, all->spr.coord.y);
	printf("SPR_DIST: %f\n", all->spr.dist);
	printf("SPR_COUNT: %d\n", all->spr_count);
	return (0);
}