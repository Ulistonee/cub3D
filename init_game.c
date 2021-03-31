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

void				get_address(t_all *all)
{
	all->tx.ntx.addr = mlx_get_data_addr(all->tx.ntx.img,
				&all->tx.ntx.bpp, &all->tx.ntx.len, &all->tx.ntx.end);
	all->tx.etx.addr = mlx_get_data_addr(all->tx.etx.img,
				&all->tx.etx.bpp, &all->tx.etx.len, &all->tx.etx.end);
	all->tx.wtx.addr = mlx_get_data_addr(all->tx.wtx.img,
				&all->tx.wtx.bpp, &all->tx.wtx.len, &all->tx.wtx.end);
	all->tx.stx.addr = mlx_get_data_addr(all->tx.stx.img,
				&all->tx.stx.bpp, &all->tx.stx.len, &all->tx.stx.end);
	all->s.s.addr = mlx_get_data_addr(all->s.s.img,
				&all->s.s.bpp, &all->s.s.len, &all->s.s.end);
}

int					init_textures(t_all *all)
{
	if (!(all->tx.ntx.img = mlx_xpm_file_to_image(all->dsp.mlx,
							all->data.no, &all->tx.ntx.w, &all->tx.ntx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tx.etx.img = mlx_xpm_file_to_image(all->dsp.mlx,
							all->data.ea, &all->tx.etx.w, &all->tx.etx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tx.wtx.img = mlx_xpm_file_to_image(all->dsp.mlx,
							all->data.we, &all->tx.wtx.w, &all->tx.wtx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->tx.stx.img = mlx_xpm_file_to_image(all->dsp.mlx,
							all->data.so, &all->tx.stx.w, &all->tx.stx.h)))
		handle_error("Invalid texture file\n", all);
	if (!(all->s.s.img = mlx_xpm_file_to_image(all->dsp.mlx,
							all->data.s, &all->s.s.w, &all->s.s.h)))
		handle_error("Invalid texture file\n", all);
	return (0);
}

int					set_player_plane(t_all *all, int x, int y)
{
	if (all->map.map[y][x] == 'N')
	{
		all->plr.plane.x = FOV_L;
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

int					set_player_dir(t_all *all, int x, int y)
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
}

<<<<<<< HEAD
int 		init_game(t_all *all)
=======
int					init_game(t_all *all)
>>>>>>> 1a87733e17059438d04574b5c4fb86b97000ea74
{
	int x;
	int y;

	y = 0;
<<<<<<< HEAD
	all->spr_count = 0;
=======
>>>>>>> 1a87733e17059438d04574b5c4fb86b97000ea74
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
			x++;
		}
		y++;
	}
	init_textures(all);
	get_address(all);
	add_spr_to_arr(all, &all->sarr);
	return (0);
}
