/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:36:41 by cobara            #+#    #+#             */
/*   Updated: 2021/01/22 13:37:31 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void		parse_textures(char **map, t_set *settings)
{
	parse_no(map, settings);
	check_repeat(map, 'N', 'O');
	parse_so(map, settings);
	check_repeat(map, 'S', 'O');
	parse_ea(map, settings);
	check_repeat(map, 'E', 'A');
	parse_we(map, settings);
	check_repeat(map, 'W', 'E');
	parse_sprite(map, settings);
	check_repeat(map, 'S', ' ');
}

void		parse_no(char **map, t_set *settings)
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
		if (map[i][j] == 'N' && map[i][j + 1] == 'O'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
			break ;
		i++;
	}
	if (map[i] == NULL)
		ft_print_error(3);
	tmp = ft_split(map[i] + j, ' ');
	if (tmp[2] != NULL)
		ft_print_error(3);
	settings->path_noth = ft_strdup_gnl(tmp[1]);
	ft_clear_mas(tmp);
}

void		parse_so(char **map, t_set *settings)
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
		if (map[i][j] == 'S' && map[i][j + 1] == 'O'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
			break ;
		i++;
	}
	if (map[i] == NULL)
		ft_print_error(3);
	tmp = ft_split(map[i] + j, ' ');
	if (tmp[2] != NULL)
		ft_print_error(3);
	settings->path_south = ft_strdup_gnl(tmp[1]);
	ft_clear_mas(tmp);
}

void		parse_we(char **map, t_set *settings)
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
		if (map[i][j] == 'W' && map[i][j + 1] == 'E'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
			break ;
		i++;
	}
	if (map[i] == NULL)
		ft_print_error(2);
	tmp = ft_split(map[i] + j, ' ');
	if (tmp[2] != NULL)
		ft_print_error(2);
	settings->path_west = ft_strdup_gnl(tmp[1]);
	ft_clear_mas(tmp);
}

void		parse_ea(char **map, t_set *settings)
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
		if (map[i][j] == 'E' && map[i][j + 1] == 'A'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
			break ;
		i++;
	}
	if (map[i] == NULL)
		ft_print_error(2);
	tmp = ft_split(map[i] + j, ' ');
	if (tmp[2] != NULL)
		ft_print_error(2);
	settings->path_east = ft_strdup_gnl(tmp[1]);
	ft_clear_mas(tmp);
}
