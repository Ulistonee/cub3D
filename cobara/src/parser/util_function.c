/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:26:36 by cobara            #+#    #+#             */
/*   Updated: 2021/02/28 12:26:37 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	init_floor(char **map, int i, int j, t_set *settings)
{
	char **tmp;

	if (map[i] == NULL)
		ft_print_error(2);
	while (ft_isdigit(map[i][j]) != 1 && map[i][j] != '\0'
	&& map[i][j] != '-')
		j++;
	check_zap(map[i]);
	tmp = ft_split(map[i] + j, ',');
	ft_check_digits(tmp);
	if (tmp[2] == NULL || tmp[3] != NULL)
		ft_print_error(2);
	settings->floor_color[0] = ft_atoi(tmp[0]);
	if (settings->floor_color[0] < 0 || settings->floor_color[0] > 255)
		ft_print_error(5);
	settings->floor_color[1] = ft_atoi(tmp[1]);
	if (settings->floor_color[1] < 0 || settings->floor_color[1] > 255)
		ft_print_error(5);
	settings->floor_color[2] = ft_atoi(tmp[2]);
	if (settings->floor_color[2] < 0 || settings->floor_color[2] > 255)
		ft_print_error(5);
	ft_clear_mas(tmp);
}

void	init_ceil(char **map, int i, int j, t_set *settings)
{
	char **tmp;

	if (map[i] == NULL)
		ft_print_error(2);
	j++;
	while (map[i][j] == ' ' || map[i][j] == '\t')
		j++;
	check_zap(map[i]);
	tmp = ft_split(map[i] + j, ',');
	ft_check_digits(tmp);
	if (tmp[2] == NULL || tmp[3] != NULL)
		ft_print_error(2);
	init_color(settings, tmp);
	ft_clear_mas(tmp);
}
