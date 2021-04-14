/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:45:18 by mdude             #+#    #+#             */
/*   Updated: 2021/02/27 13:45:20 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			fl(int argc, char **argv)
{
	int		flag;

	flag = 0;
	if (argc == 3 && ft_strnstr(argv[2], "--save", 6))
		flag = 1;
	return (flag);
}

void		paint_all(t_vars *vars)
{
	paint_c(vars);
	paint_f(vars);
	paint_ray(vars);
}

int			main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;

	if (argc == 2 || argc == 3)
	{
		ch_f(argv);
		ch_args(argc, argv);
		map = f_map(argv);
		vars = init_vars(&map, argc, argv);
		paint_all(&vars);
		if (argc == 3 && is_str(argv[2]))
			screen(&vars);
		else
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
			mlx_hook(vars.win, 17, 1L << 17, ft_close, &vars);
			mlx_hook(vars.win, 2, 0, move, &vars);
			mlx_loop(vars.mlx);
		}
	}
	else
		ch_arg();
	return (0);
}
