/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:43:03 by mdude             #+#    #+#             */
/*   Updated: 2021/02/11 13:43:04 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_col(t_data *img, int x, int y)
{
	unsigned int *color;

	color = (unsigned int*)(img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8)));
	return (*color);
}
