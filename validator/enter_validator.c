/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:28:18 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 19:28:22 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

void				plr_count(t_all *all)
{
	all->plr_count++;
	if (all->plr_count != 1)
		handle_error("Invalid number of players\n", all);
}

void				restore_map(t_all *all)
{
	int				x;
	int				y;

	y = -1;
	all->spr_count = 0;
	all->plr_count = 0;
	while (++y < all->map.lines)
	{
		x = -1;
		while (all->map.map[y][++x] != '\0')
		{
			if (all->map.map[y][x] == 'P')
			{
				all->map.map[y][x] = all->data.p;
				plr_count(all);
			}
			if (all->map.map[y][x] == '3')
				all->map.map[y][x] = '0';
			if (all->map.map[y][x] == 't')
			{
				all->map.map[y][x] = '2';
				all->spr_count++;
			}
		}
	}
}

int					valid_closed(t_all *all, int x, int y)
{
	if (x < 0 || y < 0 || y >= all->map.lines ||
			all->map.map[y][x] == '\0' || all->map.map[y][x] == ' ')
		handle_error("Invalid map\n", all);
	if (all->map.map[y][x] == '1' || all->map.map[y][x] == '3'
			|| all->map.map[y][x] == 'P' || all->map.map[y][x] == 't')
		return (1);
	if (all->map.map[y][x] == '0')
		all->map.map[y][x] = '3';
	if (ft_strchr("NEWS", all->map.map[y][x]))
	{
		all->data.p = all->map.map[y][x];
		all->map.map[y][x] = 'P';
	}
	if (all->map.map[y][x] == '2')
		all->map.map[y][x] = 't';
	return (valid_closed(all, x, y - 1) &&
			valid_closed(all, x, y + 1) &&
			valid_closed(all, x - 1, y) &&
			valid_closed(all, x + 1, y));
}

int					enter_validator(t_all *all)
{
	int				x;
	int				y;

	y = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (ft_strchr("NEWS02", all->map.map[y][x]))
			{
				valid_closed(all, x, y);
			}
			x++;
		}
		y++;
	}
	restore_map(all);
	return (0);
}
