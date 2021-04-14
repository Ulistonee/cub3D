/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:19:47 by cobara            #+#    #+#             */
/*   Updated: 2021/01/22 13:19:48 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void		parse_sprite(char **map, t_set *settings)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == 'S' && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
			break ;
		i++;
	}
	if (map[i][j] != 'S' && settings->path_sprite != NULL)
		ft_print_error(3);
	tmp = ft_split(map[i] + j, ' ');
	settings->path_sprite = ft_strdup_gnl(tmp[1]);
	ft_clear_mas(tmp);
}

void		check_repeat(char **map, char ch, char c)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == ch && map[i][j + 1] == c)
			count++;
		i++;
	}
	if (count >= 2)
		ft_print_error(3);
}

void		ft_init(t_set *settings)
{
	ft_bzero(settings->ceilling_color, 3);
	ft_bzero(settings->floor_color, 3);
	settings->path_sprite = NULL;
	settings->path_south = NULL;
	settings->path_east = NULL;
	settings->path_west = NULL;
	settings->path_noth = NULL;
}

void		has_sh(char **map)
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
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == '2'
				|| map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				;
			else
				ft_print_error(6);
			j++;
		}
		i++;
	}
}

void		check_repeat_pl(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 'b';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'S' || map[i][j] == 'E')
			{
				if (c == 'b')
					c = map[i][j];
				else
					ft_print_error(7);
			}
			j++;
		}
		i++;
	}
}
