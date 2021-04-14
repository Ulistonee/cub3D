/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:04:19 by mdude             #+#    #+#             */
/*   Updated: 2021/02/24 18:04:20 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_all(char c)
{
	return (c == '0' || c == '1' || c == '2' || is_news(c));
}

int	checkmap(t_map *map, int i, int j)
{
	if ((i < 1) || (i > sizestr(map->map) - 2) || (j < 1) ||
	(j > (int)ft_strlen(map->map[i]) - 2))
		return (0);
	else if (!is_all(map->map[i - 1][j - 1]) || !is_all(map->map[i - 1][j]) ||
	!is_all(map->map[i - 1][j + 1]) || !is_all(map->map[i][j - 1]) ||
	!is_all(map->map[i][j + 1]) || !is_all(map->map[i + 1][j - 1]) ||
	!is_all(map->map[i + 1][j]) || !is_all(map->map[i + 1][j + 1]))
		return (0);
	return (1);
}

int	check_news(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < sizestr(map->map))
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_news(map->map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	else
		return (1);
}

int	other(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < sizestr(map->map))
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_all(map->map[i][j]) && map->map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_map *map)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < sizestr(map->map))
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == '2'
			|| is_news(map->map[i][j]))
			{
				temp = checkmap(map, i, j);
				if (temp == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (!check_news(map) || !other(map))
		return (0);
	return (1);
}
