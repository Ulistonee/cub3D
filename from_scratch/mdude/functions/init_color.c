/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:52:19 by mdude             #+#    #+#             */
/*   Updated: 2021/02/27 13:52:20 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ex_color(void)
{
	write(1, "Error\nInvalid color\n", 20);
	exit(0);
}

int			color(char *line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
	{
		write(1, "Error\nInvalid color\n", 20);
		exit(0);
	}
	while (ft_isdigit(line[i]) && res < 10000)
	{
		res = res * 10 + line[i] - '0';
		i++;
	}
	if (res > 255)
	{
		write(1, "Error\nInvalid color\n", 20);
		exit(0);
	}
	return (res);
}

int			space_in(char *line, int i)
{
	while (is_space(line[i]))
		i++;
	if (line[i] != ',')
	{
		write(1, "Error\nInvalid color\n", 20);
		exit(0);
	}
	else
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

t_rgb		init_color(char *line)
{
	int		i;
	t_rgb	rgb;

	i = 0;
	if (line[0] != ' ')
		ex_color();
	while (is_space(line[i]))
		i++;
	rgb.red = color(&line[i]);
	i = i + intlen(rgb.red);
	i = space_in(line, i);
	rgb.green = color(&line[i]);
	i = i + intlen(rgb.green);
	i = space_in(line, i);
	rgb.blue = color(&line[i]);
	i = i + intlen(rgb.blue);
	while (line[i])
	{
		if (!is_space(line[i]))
			ex_color();
		i++;
	}
	return (rgb);
}
