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

#include "ft_cub.h"

int					exit_program(t_all *all)
{
	auto_clear(all);
	exit(EXIT_SUCCESS);
	return (0);
}

void				check_screen_size(t_all *all)
{
	int				width;
	int				height;

	mlx_get_screen_size(all->dsp.mlx, &width, &height);
	if (all->data.res1 > width)
		all->data.res1 = width;
	if (all->data.res2 > height)
		all->data.res2 = height;
}

void				auto_clear(t_all *all)
{
	int				i;

	i = 0;
	if (all->map.map)
	{
		while (i < all->map.lines)
		{
			ft_free_mem(&all->map.map[i]);
			i++;
		}
		ft_free_mem(all->map.map);
	}
}

static int			check_extension(char *file, char *exp)
{
	int			f_len;
	int			e_len;
	int			i;
	int			fd;

	f_len = (int)ft_strlen(file);
	e_len = (int)ft_strlen(exp);
	i = -1;
	if ((fd = open(file, O_DIRECTORY)) > 0)
		return (0);
	close(fd);
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
	all.map.map = NULL;
	all.sarr = NULL;
	if ((argc == 2 && check_extension(argv[1], ".cub"))
		|| (argc == 3 && (!ft_strncmp("--save", argv[2], 7))))
	{
		if (argc == 3)
			all.save_flag = 1;
		parser(&all, argv[1]);
		if (!(all.dsp.mlx = mlx_init()))
			handle_error("Mlx initialization error\n", &all);
		if (all.save_flag != 1)
			check_screen_size(&all);
		if (!(all.dsp.mlx_win = mlx_new_window(all.dsp.mlx,
							all.data.res1, all.data.res2, "cub3D")))
			handle_error("Mlx new window error\n", &all);
		init_game(&all);
		display(&all);
		hooks(&all);
	}
	else
		handle_error("Exit game\n", &all);
}
