/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:19:39 by cobara            #+#    #+#             */
/*   Updated: 2021/01/18 17:19:41 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubgame.h"

int		prog_exit(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

void	check_argv(char *filename)
{
	if (ft_strlen(filename) < 5)
		ft_print_error(1);
	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".cub", 4) != 0)
		ft_print_error(1);
}

int		main(int argc, char **argv)
{
	t_vars *all;

	if (argc == 2)
	{
		all = ft_game(parse_map(parse_file(argv[1])));
		check_argv(argv[1]);
		all->bmp = '0';
		make_all(all);
		ft_hook(all);
	}
	else if (argc == 3)
	{
		all = ft_game(parse_map(parse_file(argv[1])));
		check_argv(argv[1]);
		if (ft_strlen(argv[2]) > 6 || ft_strlen(argv[2]) < 6)
			ft_print_error(9);
		if (ft_strncmp(argv[2], "--save", 6) != 0)
			ft_print_error(9);
		all->bmp = '1';
		createbtmp(all);
	}
	else
		ft_print_error(0);
}
