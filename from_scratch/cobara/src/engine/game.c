/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:35:48 by cobara            #+#    #+#             */
/*   Updated: 2021/01/22 11:35:53 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

t_vars		*ft_game(t_set *settings)
{
	t_vars *option;

	option = malloc(sizeof(t_vars));
	option->mlx = mlx_init();
	option->win = mlx_new_window(option->mlx, settings->w_width,
	settings->w_height, "CUB3D");
	if (option->win == NULL)
		ft_print_error(4);
	option->set = settings;
	set_position(option);
	init_direction(option);
	init_textures(option);
	init_sprite(option);
	return (option);
}

void		ft_hook(t_vars *option)
{
	mlx_loop_hook(option->mlx, render, option);
	mlx_loop(option->mlx);
}

void		init_sprite(t_vars *option)
{
	int count;
	int i;
	int j;

	count = count_sprite(option);
	option->sprites = malloc(sizeof(t_sprite*) * count + 1);
	option->sprites_count = count;
	i = 0;
	while (i < count)
		option->sprites[i++] = malloc(sizeof(t_sprite));
	i = 0;
	count = 0;
	while (option->set->map[i] != NULL)
	{
		j = 0;
		while (option->set->map[i][j] != '\0')
		{
			if (option->set->map[i][j] == '2')
				init_sprite_info(option, i, j, &count);
			j++;
		}
		i++;
	}
}

void		init_sprite_info(t_vars *option, int i, int j, int *count)
{
	option->sprites[(*count)]->x = j + 0.5;
	option->sprites[(*count)]->y = i + 0.5;
	option->sprites[(*count)]->texture = 4;
	option->sprites[(*count)]->sprite_distance = 0;
	(*count)++;
}

int			count_sprite(t_vars *option)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (option->set->map[i] != NULL)
	{
		j = 0;
		while (option->set->map[i][j] != '\0')
		{
			if (option->set->map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
