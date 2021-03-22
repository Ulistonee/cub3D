#include "cub3D.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char    *dst;

	dst = display->addr + (y * display->line_length + x * (display->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	img_init(t_all *all)
{
	all->display.img = mlx_new_image(all->display.mlx, all->data.res1, all->data.res2);
	all->display.addr = mlx_get_data_addr(all->display.img, &all->display.bits_per_pixel,
									&all->display.line_length, &all->display.endian);
}

int 	ft_move(int keycode, t_all *all)
{
	if (keycode == 53)
			exit(0);
	if (keycode == 13)
	{
		if (!all->map.map[(int)(all->player.pos.x + all->player.dir.x * all->fow.move_speed)][(int)
			(all->player.pos.y)])
			all->player.pos.x += all->player.dir.x * all->fow.move_speed;
		if (!all->map.map[(int)(all->player.pos.x)][(int)(all->player.pos.y + all->player.dir.y
			* all->fow.move_speed)])
			all->player.pos.y += all->player.dir.y * all->fow.move_speed;
	}
	if (keycode == 1)
	{
		if (!all->map.map[(int)(all->player.pos.x - all->player.dir.x * all->fow.move_speed)][(int)
		(all->player.pos.y)])
			all->player.pos.x -= all->player.dir.x * all->fow.move_speed;
		if (!all->map.map[(int)(all->player.pos.x)][(int)(all->player.pos.y - all->player.dir.y *
			all->fow.move_speed)])
			all->player.pos.y -= all->player.dir.y * all->fow.move_speed;
	}
	if (keycode == 0)
	{
		if (!all->map.map[(int)(all->player.pos.x - all->fow.plane.x * all->fow.move_speed)][(int)
				(all->player.pos.y)])
			all->player.pos.x -= all->fow.plane.x * all->fow.move_speed;
		if (!all->map.map[(int)(all->player.pos.x)][(int)(all->player.pos.y - all->fow.plane.y *
			all->fow.move_speed)])
			all->player.pos.y -= all->fow.plane.y * all->fow.move_speed;
	}
	if (keycode == 2)
	{
		if (!all->map.map[(int)(all->player.pos.x - all->fow.plane.x * all->fow.move_speed)][(int)
				(all->player.pos.y)])
			all->player.pos.x += all->fow.plane.x * all->fow.move_speed;
		if (!all->map.map[(int)(all->player.pos.x)][(int)(all->player.pos.y - all->fow.plane.y *
																all->fow.move_speed)])
			all->player.pos.y += all->fow.plane.y * all->fow.move_speed;
	}
	if (keycode == 123)
	{
		all->fow.old_dir.x = all->player.dir.x;
		all->player.dir.x = all->player.dir.x * cos(all->fow.rot_speed) - all->player.dir.y * sin(all->fow.rot_speed);
		all->player.dir.y = all->fow.old_dir.x * sin(all->fow.rot_speed) + all->player.dir.y * cos
				(all->fow.rot_speed);
		all->fow.old_plane.x = all->fow.plane.x;
		all->fow.plane.x = all->fow.plane.x * cos(all->fow.rot_speed) - all->fow.plane.y *
				sin(all->fow.rot_speed);
		all->fow.plane.y = all->fow.old_plane.x * sin(all->fow.rot_speed) + all->fow.plane.y *
				cos(all->fow.rot_speed);
	}
	if (keycode == 124)
	{
		all->fow.old_dir.x = all->player.dir.x;
		all->player.dir.x = all->player.dir.x * cos(-all->fow.rot_speed) - all->player.dir.y * sin
				(-all->fow.rot_speed);
		all->player.dir.y = all->fow.old_dir.x * sin(-all->fow.rot_speed) + all->player.dir.y * cos
				(-all->fow.rot_speed);
		all->fow.old_plane.x = all->fow.plane.x;
		all->fow.plane.x = all->fow.plane.x * cos(-all->fow.rot_speed) - all->fow.plane.y *
														 sin(-all->fow.rot_speed);
		all->fow.plane.y = all->fow.old_plane.x * sin(-all->fow.rot_speed) + all->fow.plane.y * cos(-all->fow.rot_speed);
	}
	raycasting(all);
	return (0);
}

void	raycasting(t_all *all)
{
	int 	x = 0;
	while (x < all->data.res1)
	{
		all->fow.camera_x = 2 * x / (double)all->data.res1 - 1;
		all->fow.ray_dir.x = all->player.dir.x + all->fow.plane.x * all->fow.camera_x;
		all->fow.ray_dir.y = all->player.dir.y + all->fow.plane.y * all->fow.camera_x;
		all->fow.map.x = all->player.pos.x;
		all->fow.map.y = all->player.pos.y;
		all->fow.hit = 0;
		all->fow.delta_dist.x = (!all->fow.ray_dir.y) ? 0 : ((!all->fow.ray_dir.x) ? 1 :
												 fabs(1 / all->fow.ray_dir.x));
		all->fow.delta_dist.y = (!all->fow.ray_dir.x) ? 0 : ((!all->fow.ray_dir.y) ? 1 :
												 fabs(1 / all->fow.ray_dir.y));
		if (all->fow.ray_dir.x < 0)
		{
			all->fow.step.x = -1;
			all->fow.side_dist.x = (all->player.pos.x - all->fow.map.x) * all->fow.delta_dist.x;
		} else
		{
			all->fow.step.x = 1;
			all->fow.side_dist.x = (all->fow.map.x + 1.0 - all->player.pos.x) * all->fow.delta_dist.x;
		}
		if (all->fow.ray_dir.y < 0)
		{
			all->fow.step.y = -1;
			all->fow.side_dist.y = (all->player.pos.y - all->fow.map.y) * all->fow.delta_dist.y;
		} else
		{
			all->fow.step.y = 1;
			all->fow.side_dist.y = (all->fow.map.y + 1.0 - all->player.pos.y) * all->fow.delta_dist.y;
		}
		while (!all->fow.hit)
		{
			if (all->fow.side_dist.x < all->fow.side_dist.y)
			{
				all->fow.side_dist.x += all->fow.delta_dist.x;
				all->fow.map.x += all->fow.step.x;
				all->fow.side = 0;
			} else
			{
				all->fow.side_dist.y += all->fow.delta_dist.y;
				all->fow.map.y += all->fow.step.y;
				all->fow.side = 1;
			}
			if (all->map.map[all->fow.map.x][all->fow.map.y] > 0)
				all->fow.hit = 1;
		}
		if (!all->fow.side)
			all->fow.perp_wall_dist = (all->fow.map.x - all->player.pos.x + (1.0 - all->fow.step.x) / 2) / all->fow.ray_dir.x;
		else
			all->fow.perp_wall_dist = (all->fow.map.y - all->player.pos.y + (1.0 - all->fow.step.y) / 2) / all->fow.ray_dir.y;

		all->fow.line_height = (int)(all->data.res2 / all->fow.perp_wall_dist);
		all->fow.draw_start = -all->fow.line_height / 2 + all->data.res2 / 2;
		if (all->fow.draw_start < 0)
			all->fow.draw_start = 0;
		all->fow.draw_end = all->fow.line_height / 2 + all->data.res2 / 2;
		if (all->fow.draw_end >= all->data.res2)
			all->fow.draw_end = all->data.res2 - 1;
		for (int i = 0; i < all->fow.draw_start; i++)
			my_mlx_pixel_put(&all->display, x, i, 0x540300);
		for (int i = all->fow.draw_start; i <= all->fow.draw_end; i++)
		{
			int color;
			if (all->fow.side == 1)
				color = (all->fow.ray_dir.y > 0) ? 0xff54ff : 0x1f3dff;
			else
				color = (all->fow.ray_dir.x > 0) ? 0xff9300 : 0xf3ff53;
			my_mlx_pixel_put(&all->display, x, i, color);
		}
		for (int i = all->fow.draw_end + 1; i < all->data.res2; i++)
			my_mlx_pixel_put(&all->display, x, i, 0x1c006c);
		x++;
	}
	mlx_put_image_to_window(all->display.mlx, all->display.mlx_win, all->display.img, 0, 0);
}

int main()
{
	t_all all;
	all.data.res1 = 1920;
	all.data.res2 = 1080;
	int worldMap[24][24]=
			{
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
					{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
			};
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 24; j++)
			all.map.map[i][j] = worldMap[i][j];
//	for (int i = 0; i < 24; i++)
//	{
//		for (int j = 0; j < 24; j++)
//		{
//			printf("%d", all.map.map[i][j]);
//		}
//		printf("\n");
//	}
	all.fow.rot_speed = 0.08;
	all.fow.move_speed = 0.3;
	all.player.pos.x = 22;
	all.player.pos.y = 12;
	all.player.dir.x = -1;
	all.player.dir.y = 0;
	all.fow.plane.x = 0;
	all.fow.plane.y = 0.66;
	all.display.mlx = mlx_init();
	all.display.mlx_win = mlx_new_window(all.display.mlx, all.data.res1, all.data.res2, "cub3D");
	all.display.img = mlx_new_image(all.display.mlx, all.data.res1, all.data.res2);
	all.display.addr = mlx_get_data_addr(all.display.img, &all.display.bits_per_pixel,
										 &all.display.line_length, &all.display.endian);
	raycasting(&all);
	mlx_hook(all.display.mlx_win, 2, 0L, ft_move, &all);
	mlx_put_image_to_window(all.display.mlx, all.display.mlx_win, all.display.img, 0, 0);
	mlx_loop(all.display.mlx);
	return (0);
}
