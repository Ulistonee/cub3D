/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:49:27 by mdude             #+#    #+#             */
/*   Updated: 2021/02/27 13:50:01 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ch_resol(void)
{
	write(1, "Error\nInvalid resolution\n", 25);
	exit(0);
}

double			width(char *line)
{
	int			i;
	double		res;

	i = 0;
	res = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		ch_resol();
	if (line[i] == '0')
		ch_resol();
	while (ft_isdigit(line[i]) && res < 160000)
	{
		res = res * 10 + line[i] - '0';
		i++;
	}
	if (res < 1)
		ch_resol();
	return (res);
}

double			height(char *line)
{
	int			i;
	double		res;

	i = 0;
	res = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		ch_resol();
	if (line[i] == '0')
		ch_resol();
	while (ft_isdigit(line[i]) && res < 160000)
	{
		res = res * 10 + line[i] - '0';
		i++;
	}
	if (res < 1)
		ch_resol();
	return (res);
}

t_screen		init_screen(char *line)
{
	int			i;
	t_screen	sc;

	i = 0;
	if (line[0] != ' ')
		ch_resol();
	while (is_space(line[i]))
		i++;
	sc.width = width(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	sc.height = height(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i])
	{
		if (!is_space(line[i]))
			ch_resol();
		i++;
	}
	return (sc);
}
