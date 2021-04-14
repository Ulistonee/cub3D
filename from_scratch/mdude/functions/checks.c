/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:32:17 by mdude             #+#    #+#             */
/*   Updated: 2021/03/06 14:32:21 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		f_map(char **argv)
{
	t_map	map;

	map = parser(argv);
	if (map.id_r.height < 1 || map.id_r.width < 1)
	{
		write(1, "Error\nInvalid resolution\n", 25);
		exit(0);
	}
	if (!valid_map(&map))
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(0);
	}
	return (map);
}

void		ch_arg(void)
{
	write(1, "Error\nInvalid argument\n", 23);
	exit(0);
}

int			check_format(char *str)
{
	int		len;

	if (ft_strlen(str) < 5)
		return (0);
	len = ft_strlen(str) - 1;
	if (str[len] != 'b')
		return (0);
	if (str[len - 1] != 'u')
		return (0);
	if (str[len - 2] != 'c')
		return (0);
	if (str[len - 3] != '.')
		return (0);
	return (1);
}

void		ch_f(char **argv)
{
	if (!check_format(argv[1]))
	{
		write(1, "Error\nInvalid format\n", 21);
		exit(0);
	}
}

void		ch_args(int argc, char **argv)
{
	if (argc == 3 && !is_str(argv[2]))
	{
		write(1, "Error\nInvalid argument\n", 23);
		exit(0);
	}
}
