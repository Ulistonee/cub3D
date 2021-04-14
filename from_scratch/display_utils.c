/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:44:31 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 20:44:35 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void				my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	if (x < all->data.res1 && y < all->data.res2 && x >= 0 && y >= 0)
	{
		dst = all->dsp.addr + (y * all->dsp.line_length + x *
				(all->dsp.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int					display(t_all *all)
{
	all->dsp.img = mlx_new_image(all->dsp.mlx, all->data.res1, all->data.res2);
	all->dsp.addr = mlx_get_data_addr(all->dsp.img,
								&all->dsp.bits_per_pixel,
								&all->dsp.line_length, &all->dsp.endian);
	raycast(all);
	if (all->save_flag == 1)
		take_screenshot(all);
	mlx_put_image_to_window(all->dsp.mlx, all->dsp.mlx_win, all->dsp.img, 0, 0);
	mlx_destroy_image(all->dsp.mlx, all->dsp.img);
	return (1);
}
