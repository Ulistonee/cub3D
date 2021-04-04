/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:41:06 by cobara            #+#    #+#             */
/*   Updated: 2021/01/22 17:41:07 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"
#include <stdio.h>

int		parse_main_map(char **map, t_set *settings)
{
	int i;
	int j;
	int size;

	size = 0;
	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while ((map[i][j] == ' ' || map[i][j] == '\t')
		&& map[i][j] != '\0')
			j++;
		if (map[i][j] == '1')
			size++;
		i++;
	}
	fill_main_map(map, settings, size);
	return (size);
}

void	fill_main_map(char **map, t_set *settings, int size)
{
	int i;
	int j;
	int ismeet;

	i = 0;
	j = 0;
	ismeet = 0;
	settings->map = malloc(size * sizeof(char *) + 1);
	size = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == '\0' && ismeet == 1)
			ft_print_error(6);
		if (map[i][j] == '1' || map[i][j] == '0')
		{
			settings->map[size++] = ft_strdup_gnl(map[i]);
			ismeet = 1;
		}
		i++;
	}
	ft_clear_mas(map);
	settings->map[size] = NULL;
}

void	check_another_symb(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == '\0')
		{
			i++;
			continue;
		}
		if (check_color_resolution(map, i, j) == 0 && check_text(map, i, j) == 0
		&& map[i][j] != '1' && map[i][j] != '\0')
			ft_print_error(6);
		i++;
	}
}

int		check_text(char **map, int i, int j)
{
	if ((ft_strncmp(&map[i][j], "NO", 2) != 0)
	&& (ft_strncmp(&map[i][j], "SO", 2) != 0)
	&& (ft_strncmp(&map[i][j], "WE", 2) != 0)
	&& (ft_strncmp(&map[i][j], "EA", 2) != 0)
	&& (ft_strncmp(&map[i][j], "S ", 2) != 0))
		return (0);
	return (1);
}

int		check_color_resolution(char **map, int i, int j)
{
	if ((ft_strncmp(&map[i][j], "F ", 2) != 0)
	&& (ft_strncmp(&map[i][j], "C ", 2) != 0)
	&& (ft_strncmp(&map[i][j], "R ", 2) != 0))
		return (0);
	return (1);
}
