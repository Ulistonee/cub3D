/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:00:11 by cobara            #+#    #+#             */
/*   Updated: 2021/01/22 17:00:13 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	parse_color_f(char **map, t_set *settings)
{
	int		i;
	int		j;

	j = 0;
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
		if (map[i][j] == 'F' && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
			break ;
		i++;
	}
	init_floor(map, i, j, settings);
}

void	parse_color_с(char **map, t_set *settings)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == 'C' && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
			break ;
		i++;
	}
	init_ceil(map, i, j, settings);
}

void	ft_clear_mas(char **tmp)
{
	int z;

	z = 0;
	while (tmp[z] != NULL)
	{
		free(tmp[z]);
		z++;
	}
	free(tmp);
}

void	init_color(t_set *settings, char **tmp)
{
	settings->ceilling_color[0] = ft_atoi(tmp[0]);
	if (settings->ceilling_color[0] < 0
	|| settings->ceilling_color[0] > 255)
		ft_print_error(5);
	settings->ceilling_color[1] = ft_atoi(tmp[1]);
	if (settings->ceilling_color[1] < 0
	|| settings->ceilling_color[1] > 255)
		ft_print_error(5);
	settings->ceilling_color[2] = ft_atoi(tmp[2]);
	if (settings->ceilling_color[2] < 0
	|| settings->ceilling_color[2] > 255)
		ft_print_error(5);
}

void	ft_check_digits(char **tmp)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tmp[i] != NULL)
	{
		j = 0;
		while (tmp[i][j] != '\0')
		{
			if (ft_isdigit(tmp[i][j]) != 1)
			{
				ft_print_error(2);
			}
			j++;
		}
		i++;
	}
}
