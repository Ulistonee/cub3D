#include "cub3D.h"

int 			key_hook(int keynumber, t_all *all)
{
	double			old_x;
	t_pos			new_pos;

	if (keynumber == ESC)
		exit(0);
	if (keynumber == W || keynumber == UP)
	{
		new_pos.x = all->player.dir.x * STEP + all->player.pos.x;
		new_pos.y = all->player.dir.y * STEP + all->player.pos.y;
		if (all->map.map[(int)new_pos.y][(int)new_pos.x] == '0')
		{
			all->player.pos.x = new_pos.x;
			all->player.pos.y = new_pos.y;
		}
	}
	if (keynumber == S || keynumber == DOWN)
	{
		new_pos.x = -all->player.dir.x * STEP + all->player.pos.x;
		new_pos.y = -all->player.dir.y * STEP + all->player.pos.y;
		if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
		{
			all->player.pos.x = new_pos.x;
			all->player.pos.y = new_pos.y;
		}
	}
	if (keynumber == LEFT)
	{
		old_x = all->player.dir.x;
		all->player.dir.x = old_x * cos(-ANGLE) - all->player.dir.y * sin(-ANGLE);
		all->player.dir.y = old_x * sin(-ANGLE) + all->player.dir.y * cos(-ANGLE);
		old_x = all->player.plane.x;
		all->player.plane.x = old_x * cos(-ANGLE) - all->player.plane.y * sin(-ANGLE);
		all->player.plane.y = old_x * sin(-ANGLE) + all->player.plane.y * cos(-ANGLE);
	}
	if (keynumber == A)
	{
		new_pos.x = all->player.pos.x + all->player.dir.y * STEP;
		new_pos.y = all->player.pos.y - all->player.dir.x * STEP;
		if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
		{
			all->player.pos.x = new_pos.x;
			all->player.pos.y = new_pos.y;
		}
	}
	if (keynumber == D)
	{
		new_pos.x = all->player.pos.x - all->player.dir.y * STEP;
		new_pos.y = all->player.pos.y + all->player.dir.x * STEP;
		if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
		{
			all->player.pos.x = new_pos.x;
			all->player.pos.y = new_pos.y;
		}
	}
	if (keynumber == RIGHT)
	{
		old_x = all->player.dir.x;
		all->player.dir.x = old_x * cos(ANGLE) - all->player.dir.y * sin(ANGLE);
		all->player.dir.y = old_x * sin(ANGLE) + all->player.dir.y * cos(ANGLE);
		old_x = all->player.plane.x;
		all->player.plane.x = old_x * cos(ANGLE) - all->player.plane.y * sin(ANGLE);
		all->player.plane.y = old_x * sin(ANGLE) + all->player.plane.y * cos(ANGLE);
	}
	return (0);
}