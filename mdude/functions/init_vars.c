/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:04:54 by mdude             #+#    #+#             */
/*   Updated: 2021/03/06 11:57:52 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		err_res(t_vars *vars, int argc, char **argv)
{
	if ((vars->map.id_r.width > 16384 || vars->map.id_r.height > 16384)
	&& fl(argc, argv))
	{
		write(1, "Error\nResolution > 16384\n", 26);
		exit(0);
	}
}

t_vars		init_vars(t_map *map, int argc, char **argv)
{
	t_vars	vars;
	int		w;
	int		h;

	vars.map = *map;
	vars.k = 10;
	vars.pl = start_pos(map);
	vars.pl.pos.x = vars.pl.pos.x * vars.k + vars.k / 2;
	vars.pl.pos.y = vars.pl.pos.y * vars.k + vars.k / 2;
	vars.mlx = mlx_init();
	err_res(&vars, argc, argv);
	mlx_get_screen_size(vars.mlx, &w, &h);
	if (vars.map.id_r.width > w && !fl(argc, argv))
		vars.map.id_r.width = w;
	if (vars.map.id_r.height > h && !fl(argc, argv))
		vars.map.id_r.height = h;
	vars.win = mlx_new_window(vars.mlx, vars.map.id_r.width,
			vars.map.id_r.height, "cub3D");
	vars.img.img = mlx_new_image(vars.mlx, vars.map.id_r.width,
			vars.map.id_r.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.tex = init_tex(&vars);
	return (vars);
}
