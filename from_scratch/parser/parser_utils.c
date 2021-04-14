/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:02:47 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 17:02:50 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

void					check_val_integrity(t_all *all)
{
	if (all->data.res1 <= 0 || all->data.res2 <= 0 || !all->data.no ||
		!all->data.ea ||
		!all->data.we ||
		!all->data.so ||
		all->data.flr_1 < 0 || all->data.flr_1 > 255 ||
		all->data.flr_2 < 0 || all->data.flr_2 > 255 ||
		all->data.flr_3 < 0 || all->data.flr_3 > 255 ||
		all->data.ceil_1 < 0 || all->data.ceil_1 > 255 ||
		all->data.ceil_2 < 0 || all->data.ceil_2 > 255 ||
		all->data.ceil_3 < 0 || all->data.ceil_3 > 255 ||
		!all->data.s)
		handle_error("Not full data\n", all);
}

void					init_val(t_all *all)
{
	all->data.res1 = 0;
	all->data.res2 = 0;
	all->data.no = NULL;
	all->data.ea = NULL;
	all->data.we = NULL;
	all->data.so = NULL;
	all->data.flr_1 = -1;
	all->data.flr_2 = -1;
	all->data.flr_3 = -1;
	all->data.flr = 0;
	all->data.ceil = 0;
	all->data.ceil_1 = -1;
	all->data.ceil_2 = -1;
	all->data.ceil_3 = -1;
	all->data.s = NULL;
	all->data.p = 0;
}

void					parse_color_util(t_all *all, char **line, int *dst)
{
	while (**line == ' ')
		(*line)++;
	if (ft_isdigit(**line))
	{
		if (*dst != -1)
			handle_error("Too much data\n", all);
		*dst = ft_atoi(*line);
	}
	while (ft_isdigit(**line))
		(*line)++;
}

int						is_map(char *line)
{
	if (*line == '\0')
		return (0);
	while (*line)
	{
		if (!(ft_strchr(VALID_SYMBOLS, *line)))
			return (0);
		line++;
	}
	return (1);
}
