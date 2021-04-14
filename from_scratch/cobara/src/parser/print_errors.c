/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:23:10 by cobara            #+#    #+#             */
/*   Updated: 2021/01/20 12:23:12 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	ft_print_error(int code)
{
	ft_putstr_fd("Error\n", 1);
	if (code == 0)
		ft_putstr_fd("Wrong number of parameters\n", 1);
	if (code == 1)
		ft_putstr_fd("Invalid file\n", 1);
	if (code == 2)
		ft_putstr_fd("Uncorrected information in file\n", 1);
	if (code == 3)
		ft_putstr_fd("Textures are not valid\n", 1);
	if (code == 4)
		ft_putstr_fd("Not enough memmory\n", 1);
	if (code == 5)
		ft_putstr_fd("Problem with color\n", 1);
	if (code == 6)
		ft_putstr_fd("Invalid map\n", 1);
	if (code == 7)
		ft_putstr_fd("Too much players\n", 1);
	if (code == 8)
		ft_putstr_fd("Player is not found\n", 1);
	if (code == 9)
		ft_putstr_fd("Argument is not valid\n", 1);
	exit(0);
}

void	check_zap(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_print_error(5);
}

void	check_posit(char **map, char c, char sh)
{
	int i;
	int j;
	int oldi;

	oldi = get_posit(map);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == c && map[i][j + 1] == sh)
			break ;
		i++;
	}
	if (oldi < i)
		ft_print_error(2);
}

int		get_posit(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == '1' || map[i][j] == '0')
			break ;
		i++;
	}
	return (i);
}

void	init_resolution(char **map, int i, int j, t_set *settings)
{
	char **tmp;

	if (map[i] == NULL)
		ft_print_error(2);
	j++;
	while (map[i][j] == ' ')
		j++;
	tmp = ft_split(map[i] + j, ' ');
	if (tmp[1] == NULL || tmp[0] == NULL)
		ft_print_error(2);
	ft_check_digits(tmp);
	settings->w_width = ft_atoi(tmp[0]);
	settings->w_height = ft_atoi(tmp[1]);
	if (settings->w_width <= 0 || settings->w_height <= 0
	|| tmp[2] != NULL)
		ft_print_error(2);
	ft_clear_mas(tmp);
}
