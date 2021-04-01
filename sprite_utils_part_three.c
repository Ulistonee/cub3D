#include "cub3D.h"

void			sprite_dimensions(t_all *all, t_sprite *sprite)
{
	sprite->width = fabs(all->data.res2 / all->proj_coor.y);
	sprite->start.x = all->proj_coor.x - sprite->width / 2;
	sprite->end.x = all->proj_coor.x + sprite->width / 2;
	sprite->start.y = all->data.res2 / 2 - all->data.res2 / all->proj_coor.y / 2 - 1;
	sprite->end.y = all->data.res2 / 2 + all->data.res2 / all->proj_coor.y / 2;
}
