#include "cub3D.h"

int					raycaster(t_all *all)
{
	for (int x = 0; x < w; x++)
	{

		all->fow.camera_x = 2 * x / (double)all.data.res2 - 1; //x-coordinate in camera space
		all->fow.ray_dir.x = all->fow.dir.x + all->fow.plane.x * all->fow.camera_x;
		all->fow.ray_dir.y = all->fow.dir.y + all->fow.plane.y * all->fow.camera_x;
	//which box of the map we're in
	all->fow.map.x_int = all->fow.pos.x_int; // should be int
	all->fow.map.y_int = all->fow.pos.y_int;

	//length of ray from current position to next x or y-side
	all->fow.side_dist.x;
	all->fow.side_dist.y;

	//length of ray from one x or y-all->fow.side to next x or y-side
	all->fow.delta_dist.x = fabs(1 / all->fow.ray_dir.x);
	all->fow.delta_dist.y = fabs(1 / all->fow.ray_dir.y);
	all->fow.perp_wall_dist;

	//what direction to step in x or y-direction (either +1 or -1)
	all->fow.step.x_int;
	all->fow.step.y_int;

	all->fow.hit = 0; //was there a wall hit?
	all->fow.side; //was a NS or a EW wall hit?

	// Alternative code for deltaDist in case division through zero is not supported
	all->fow.delta_dist.x = (all->fow.ray_dir.y == 0) ? 0 : ((all->fow.ray_dir.x == 0) ? 1 : fabs(1 / all->fow.ray_dir.x);
	all->fow.delta_dist.y = (all->fow.ray_dir.x == 0) ? 0 : ((all->fow.ray_dir.y == 0) ? 1 : fabs(1 / all->fow.ray_dir.y));

	//calculate step and initial sideDist
	if (all->fow.ray_dir.x < 0)
	{
		all->fow.step.x = -1;
		all->fow.side_dist.x = (all->fow.pos.x - all->fow.map.x) * all->fow.delta_dist.x;
	}
	else
	{
		all->fow.step.x = 1;
		all->fow.side_dist.x = (all->fow.map.x + 1.0 - all->fow.pos.x) * all->fow.delta_dist.x;
	}
	if (all->fow.ray_dir.y < 0)
	{
		all->fow.step.y = -1;
		all->fow.side_dist.y = (all->fow.pos.y - all->fow.map.y) * all->fow.delta_dist.y;
	}
	else
	{
		all->fow.step.y = 1;
		all->fow.side_dist.y = (all->fow.map.y + 1.0 - all->fow.pos.y) * all->fow.delta_dist.y;
	}
	//perform DDA
	while (all->fow.hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (all->fow.side_dist.x < all->fow.side_dist.y)
		{
			all->fow.side_dist.x += all->fow.delta_dist.x;
			all->fow.map.x += all->fow.step.x;
			all->fow.side = 0;
		}
		else
		{
			all->fow.side_dist.y += all->fow.delta_dist.y;
			all->fow.map.y += all->fow.step.y;
			all->fow.side = 1;
		}
		//Check if ray has hit a wall
		if (all->map.map[all->fow.map.x][all->fow.map.y] > 0) all->fow.hit = 1;
	}
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
	if (all->fow.side == 0) all->fow.perp_wall_dist = (all->fow.map.x - all->fow.pos.x + (1 - all->fow.step.x) / 2) / all->fow.ray_dir.x;
	else           all->fow.perp_wall_dist = (all->fow.map.y - all->fow.pos.y + (1 - all->fow.step.y) / 2) / all->fow.ray_dir.y;
	//Calculate height of line to draw on screen
	all->fow.line_height = (int)(h / all->fow.perp_wall_dist);

	//calculate lowest and highest pixel to fill in current stripe
	all->fow.draw_start = -(all->fow.line_height) / 2 + h / 2;
	if(all->fow.draw_start < 0)all->fow.draw_start = 0;
	all->fow.draw_end = all->fow.line_height / 2 + h / 2;
	if(all->fow.draw_end >= h)all->fow.draw_end = h - 1;
	//choose wall color
	ColorRGB color;
	switch(all->map.map[all->fow.map.x][all->fow.map.y])
	{
		case 1:  color = RGB_Red;  break; //red
		case 2:  color = RGB_Green;  break; //green
		case 3:  color = RGB_Blue;   break; //blue
		case 4:  color = RGB_White;  break; //white
		default: color = RGB_Yellow; break; //yellow
	}

	//give x and y sides different brightness
	if (all->fow.side == 1) {color = color / 2;}

	//draw the pixels of the stripe as a vertical line
	verLine(x, all->fow.draw_start, all->fow.draw_end, color);
	//timing for input and FPS counter
	oldTime = time;
	time = getTicks();
	double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	print(1.0 / frameTime); //FPS counter
	redraw();
	cls();

	//speed modifiers
	all->fow.move_speed = frameTime * 5.0; //the constant value is in squares/second
	all->fow.rot_speed = frameTime * 3.0; //the constant value is in radians/second
//	readKeys();
//	//move forward if no wall in front of you
//	if (keyDown(SDLK_UP))
//	{
//		if(all->map.map[int(all->fow.pos.x + all->fow.dir.x * all->fow.move_speed][int(all->fow.pos.y)] == false) all->fow.pos.x += all->fow.dir.x * all->fow.move_speed;
//		if(all->map.map[int(all->fow.pos.x)][int(all->fow.pos.y + all->fow.dir.y * all->fow.move_speed] == false) all->fow.pos.y += all->fow.dir.y * all->fow.move_speed;
//	}
//	//move backwards if no wall behind you
//	if (keyDown(SDLK_DOWN))
//	{
//		if(all->map.map[int(all->fow.pos.x - all->fow.dir.x * all->fow.move_speed][int(all->fow.pos.y)] == false) all->fow.pos.x -= all->fow.dir.x * all->fow.move_speed;
//		if(all->map.map[int(all->fow.pos.x)][int(all->fow.pos.y - all->fow.dir.y * all->fow.move_speed] == false) all->fow.pos.y -= all->fow.dir.y * all->fow.move_speed;
//	}
//	//rotate to the right
//	if (keyDown(SDLK_RIGHT))
//	{
//		//both camera direction and camera plane must be rotated
//		all->fow.old_dir.x = all->fow.dir.x;
//		all->fow.dir.x = all->fow.dir.x * cos(-all->fow.rot_speed) - all->fow.dir.y * sin(-all->fow.rot_speed);
//		all->fow.dir.y = all->fow.old_dir * sin(-all->fow.rot_speed) + all->fow.dir.y * cos(-all->fow.rot_speed);
//		all->fow.old_plane.x = all->fow.plane.x;
//		all->fow.plane.x = all->fow.plane.x * cos(-all->fow.rot_speed) - all->fow.plane.y * sin(-all->fow.rot_speed);
//		all->fow.plane.y = all->fow.old_plane.x * sin(-all->fow.rot_speed) + all->fow.plane.y * cos(-all->fow.rot_speed);
//	}
//	//rotate to the left
//	if (keyDown(SDLK_LEFT))
//	{
//		//both camera direction and camera plane must be rotated
//		all->fow.old_dir.x = all->fow.dir.x;
//		all->fow.dir.x = all->fow.dir.x * cos(all->fow.rot_speed) - all->fow.dir.y * sin(all->fow.rot_speed);
//		all->fow.dir.y = all->fow.old_dir * sin(all->fow.rot_speed) + all->fow.dir.y * cos(all->fow.rot_speed);
//		all->fow.old_plane.x = all->fow.plane.x;
//		all->fow.plane.x = all->fow.plane.x * cos(all->fow.rot_speed) - all->fow.plane.y * sin(all->fow.rot_speed);
//		all->fow.plane.y = all->fow.old_plane.x * sin(all->fow.rot_speed) + all->fow.plane.y * cos(all->fow.rot_speed);
	}
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
//			printf("%d", all.x.map[i][j]);
//		}
//		printf("\n");
//	}
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
	raycaster(&all);
//	mlx_hook(all.display.mlx_win, 2, 0L, ft_move, &all);
	mlx_put_image_to_window(all.display.mlx, all.display.mlx_win, all.display.img, 0, 0);
	mlx_loop(all.display.mlx);
	return (0);
}
