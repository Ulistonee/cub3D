/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:17:03 by cobara            #+#    #+#             */
/*   Updated: 2021/01/25 10:17:04 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	check_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (map[0] == NULL)
		ft_print_error(2);
	has_sh(map);
	check_bottom_top(map, 0);
	check_bottom_top(map, size - 1);
	check_border(map);
	check_around(map);
	check_repeat_pl(map);
}

void	check_bottom_top(char **map, int side)
{
	int j;

	j = 0;
	while (map[side][j] != '\0')
	{
		while ((map[side][j] == ' ' || map[side][j] == '\t'))
			j++;
		if (map[side][j] != '1')
			ft_print_error(6);
		j++;
	}
}

void	check_border(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			while (map[i][j] == ' ' || map[i][j] == '\t')
				j++;
			if (map[i][j] != '1' && map[i][ft_strlen_gnl(map[i]) - 1] != '1')
				ft_print_error(6);
			j++;
		}
		i++;
	}
}

void	check_around(char **map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == '2' ||
			map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
			|| map[i][j] == 'E')
				check_probels(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_probels(char **map, int i, int j)
{
	if (map[i][j + 1] == ' ' || map[i - 1][j] == ' '
	|| map[i][j - 1] == ' ' || map[i + 1][j] == ' ')
		ft_print_error(2);
	if (map[i][j + 1] == '\t' || map[i - 1][j] == '\t'
	|| map[i][j - 1] == '\t' || map[i + 1][j] == '\t')
		ft_print_error(2);
	if (map[i][j + 1] == '\0' || map[i - 1][j] == '\0'
		|| map[i][j - 1] == '\0' || map[i + 1][j] == '\0')
		ft_print_error(2);
	if (map[i + 1][j + 1] == ' ' || map[i - 1][j - 1] == ' '
		|| map[i + 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ')
		ft_print_error(2);
	if (map[i + 1][j + 1] == '\t' || map[i - 1][j - 1] == '\t'
		|| map[i + 1][j - 1] == '\t' || map[i - 1][j + 1] == '\t')
		ft_print_error(2);
	if (map[i + 1][j + 1] == '\0' || map[i - 1][j - 1] == '\0'
		|| map[i + 1][j - 1] == '\0' || map[i - 1][j + 1] == '\0')
		ft_print_error(2);
}
