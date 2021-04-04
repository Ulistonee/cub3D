/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:26:56 by cobara            #+#    #+#             */
/*   Updated: 2021/02/27 14:26:58 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	init_textures(t_vars *option)
{
	init_xmp_in_tex(option, 0, option->set->path_noth);
	init_xmp_in_tex(option, 1, option->set->path_south);
	init_xmp_in_tex(option, 2, option->set->path_east);
	init_xmp_in_tex(option, 3, option->set->path_west);
	init_xmp_in_tex(option, 4, option->set->path_sprite);
}

void	init_xmp_in_tex(t_vars *option, int i, char *path)
{
	int size_x;
	int size_y;

	option->textures[i].img = mlx_xpm_file_to_image(option->mlx, path, &size_x,
	&size_y);
	option->textures[i].texwidth = size_x;
	option->textures[i].texheight = size_y;
	if (option->textures[i].img == NULL)
		ft_print_error(3);
	option->textures[i].addr = mlx_get_data_addr(option->textures[i].img,
											&option->textures[i].bits_per_pixel,
											&option->textures[i].line_length,
											&option->textures[i].endian);
}
