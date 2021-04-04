/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:04:46 by cobara            #+#    #+#             */
/*   Updated: 2021/01/27 16:04:47 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	set_position(t_vars *option)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	i = 0;
	while (option->set->map[i] != NULL)
	{
		j = 0;
		x = 0;
		while (option->set->map[i][j] != '\0')
		{
			if (is_plr(option->set->map[i][j]) == 1)
				init_plr_pos(option, x, y, option->set->map[i][j]);
			x += 10;
			j++;
		}
		y += 10;
		i++;
	}
	if (is_plr(option->plr.pos) != 1)
		ft_print_error(8);
}

void	init_plr_pos(t_vars *option, int x, int y, char ch)
{
	option->plr.x = x / 10 + 0.5;
	option->plr.y = y / 10 + 0.5;
	option->plr.pos = ch;
}

void	draw_pod_y(t_vars *option, int stripe)
{
	int				y;
	unsigned int	*color;
	int				d;

	y = option->sinfo.drawstarty;
	while (y < option->sinfo.drawendy)
	{
		d = y * 256 - option->set->w_height * 128
		+ option->sinfo.spriteheight * 128;
		option->sinfo.texy = ((d * option->textures[4].texheight)
		/ option->sinfo.spriteheight) / 256;
		color = (unsigned int*)(option->textures[4].addr
		+ (option->sinfo.texy * option->textures[4].line_length
		+ option->sinfo.texx * (option->textures[4].bits_per_pixel
		/ 8)));
		if (((*color) & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(option, stripe, y, (int)*color);
		y++;
	}
}
