/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:15:34 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:15:37 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int					init_textures(t_all *all)
{
	if (!(all->tex.ntx.img = mlx_xpm_file_to_image(all->dsp.mlx, all->data.no, &all->tex.ntx.w, &all->tex.ntx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.etx.img = mlx_xpm_file_to_image(all->dsp.mlx, all->data.ea, &all->tex.etx.w, &all->tex.etx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.wtx.img = mlx_xpm_file_to_image(all->dsp.mlx, all->data.we, &all->tex.wtx.w, &all->tex.wtx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tex.stx.img = mlx_xpm_file_to_image(all->dsp.mlx, all->data.so, &all->tex.stx.w, &all->tex.stx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->s.s.img = mlx_xpm_file_to_image(all->dsp.mlx, all->data.s, &all->s.s.w, &all->s.s.h)))
		handle_error("Invalid texture file\n", all);
	all->tex.ntx.addr = mlx_get_data_addr(all->tex.ntx.img,
											&all->tex.ntx.bpp, &all->tex.ntx.len, &all->tex.ntx.end);
	all->tex.etx.addr = mlx_get_data_addr(all->tex.etx.img,
											&all->tex.etx.bpp, &all->tex.etx.len, &all->tex.etx.end);
	all->tex.wtx.addr = mlx_get_data_addr(all->tex.wtx.img,
											&all->tex.wtx.bpp, &all->tex.wtx.len, &all->tex.wtx.end);
	all->tex.stx.addr = mlx_get_data_addr(all->tex.stx.img,
											&all->tex.stx.bpp, &all->tex.stx.len, &all->tex.stx.end);
	all->s.s.addr = mlx_get_data_addr(all->s.s.img,
									  &all->s.s.bpp, &all->s.s.len, &all->s.s.end);
	return (0);
}

int			set_player_plane(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->plr.plane.x = FOV_L; // height of the camera plane 0.577
		all->plr.plane.y = 0;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->plr.plane.x = 0;
		all->plr.plane.y = FOV_L;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->plr.plane.x = 0;
		all->plr.plane.y = -FOV_L;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->plr.plane.x = -FOV_L;
		all->plr.plane.y = 0;
	}
	all->plr.plane.x += 0.001;
	all->plr.plane.y += 0.001;
	return (1);
}

int 		set_player_dir(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->plr.dir.x = 0;
		all->plr.dir.y = -1;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->plr.dir.x = 1;
		all->plr.dir.y = 0;
	}
	if (all->map.map[y][x] == 'W')
	{
		all->plr.dir.x = -1;
		all->plr.dir.y = 0;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->plr.dir.x = 0;
		all->plr.dir.y = 1;
	}
	all->plr.dir.x += 0.001;
	all->plr.dir.y += 0.001;
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
				all->plr.pos.x = x + 0.5;
				all->plr.pos.y = y + 0.5;
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
	add_spr_to_arr(all, &all->sarr);
	return (0);
}
