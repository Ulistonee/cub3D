#include "cub3D.h"

double						calc_sprite(t_all *all)
{
	t_pos				map;
	int 				i = 0;

	all->spr.coord.x = map.x - all->player.pos.x;
	all->spr.coord.y = map.y - all->player.pos.y;
	all->dist = len_of_vec(all->spr.coord.x, all->spr.coord.y);

//	printf("SPR_DIST: %f\n", all->spr.dist);
	return (0);
}