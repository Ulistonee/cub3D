/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:55:38 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 19:58:15 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void				exit_program(t_all *all)
{
	exit(EXIT_SUCCESS);
}

void				check_screen_size(t_all *all)
{
	int				width;
	int				height;

	mlx_get_screen_size(&width, &height);
	if (all->data.res1 > width)
		all->data.res1 = width;
	if (all->data.res2 > height)
		all->data.res2 = height;
}

void				auto_clear(t_all *all)
{
	char		**p;

	if (all->map.map)
	{
		p = all->map.map;
		while (*p)
		{
			ft_free_mem(p);
			p++;
		}
		free(all->map.map);
	}
	if (all->sarr)
		ft_free_mem((char **)&all->sarr);
}

static int			check_extension(char *file, char *exp)
{
	int			f_len;
	int			e_len;
	int			i;

	f_len = (int)ft_strlen(file);
	e_len = (int)ft_strlen(exp);
	i = -1;
	if (f_len <= e_len)
		return (0);
	while (++i < e_len)
		if (exp[e_len - 1 - i] != file[f_len - 1 - i])
			return (0);
	return (1);
}

int					main(int argc, char *argv[])
{
	t_all			all;

	all.save_flag = 0;
	if ((argc == 2 && check_extension(argv[1], ".cub"))
		|| (argc == 3 && (!ft_strncmp("--save", argv[2], 6))))
	{
		if (argc == 3)
			all.save_flag = 1;
		parser(&all, argv[1]);
		all.dsp.mlx = mlx_init();
		if (all.save_flag != 1)
			check_screen_size(&all);
		all.dsp.mlx_win = mlx_new_window(all.dsp.mlx,
								all.data.res1, all.data.res2,"My_cub3D");
		init_game(&all);
		display(&all);
		mlx_hook(all.dsp.mlx_win, 17, (1L << 0), exit_program, &all);
		mlx_hook(all.dsp.mlx_win, 2, (1L << 0), key_hook, &all);
		mlx_loop_hook(all.dsp.mlx, display, &all);
		mlx_loop(all.dsp.mlx);
	}
	else
		handle_error("Exit game\n", &all);
	return (0);
}
