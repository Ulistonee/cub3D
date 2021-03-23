#include "cub3D.h"

int					init_textures(t_all *all)
{
	if (!(all->tex.n_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.no, &all->tex.n_tex.w, &all->tex.n_tex.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.e_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.ea, &all->tex.e_tex.w, &all->tex.e_tex.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.w_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.we, &all->tex.w_tex.w, &all->tex.w_tex.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.s_tex.img = mlx_xpm_file_to_image(all->display.mlx, all->data.so, &all->tex.s_tex.w, &all->tex.s_tex.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->s.s.img = mlx_xpm_file_to_image(all->display.mlx, all->data.s, &all->s.s.w, &all->s.s.h)))
		handle_error("Invalid texture file\n", all);
	all->tex.n_tex.addr = mlx_get_data_addr(all->tex.n_tex.img,
											&all->tex.n_tex.bits_per_pixel, &all->tex.n_tex.line_length, &all->tex.n_tex.endian);
	all->tex.e_tex.addr = mlx_get_data_addr(all->tex.e_tex.img,
											&all->tex.e_tex.bits_per_pixel, &all->tex.e_tex.line_length, &all->tex.e_tex.endian);
	all->tex.w_tex.addr = mlx_get_data_addr(all->tex.w_tex.img,
											&all->tex.w_tex.bits_per_pixel, &all->tex.w_tex.line_length, &all->tex.w_tex.endian);
	all->tex.s_tex.addr = mlx_get_data_addr(all->tex.s_tex.img,
											&all->tex.s_tex.bits_per_pixel, &all->tex.s_tex.line_length, &all->tex.s_tex.endian);
	all->s.s.addr = mlx_get_data_addr(all->s.s.img,
									  &all->s.s.bits_per_pixel, &all->s.s.line_length, &all->s.s.endian);
	return (0);
}

int			set_player_plane(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->player.plane.x = FOV_L; // height of the camera plane 0.577
		all->player.plane.y = 0;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->player.plane.x = 0;
		all->player.plane.y = FOV_L;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->player.plane.x = 0;
		all->player.plane.y = -FOV_L;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->player.plane.x = -FOV_L;
		all->player.plane.y = 0;
	}
	return (1);
}

int 		set_player_dir(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->player.dir.x = 0;
		all->player.dir.y = -1;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->player.dir.x = 1;
		all->player.dir.y = 0;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->player.dir.x = -1;
		all->player.dir.y = 0;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->player.dir.x = 0;
		all->player.dir.y = 1;
	}
	return (1);
};
int 		init_game(t_all *all)
{
	int x = 0;
	int y = 0;

	all->spr_count = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (ft_strchr("NEWS", all->map.map[y][x]))
			{
				all->player.pos.x = x + 0.5;
				all->player.pos.y = y + 0.5;
				set_player_dir(all, x, y);
				set_player_plane(all, x, y);
				all->map.map[y][x] = '0';
			}
			if (all->map.map[y][x] == '2')
			{
				all->spr_count++;
			}
			x++;
		}
		y++;
	}
//	display(all);
	init_textures(all);
	add_spr_to_arr(all, &all->spr_arr);
	return (0);
}