/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:06:03 by cobara            #+#    #+#             */
/*   Updated: 2021/02/27 17:10:53 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

void	sort_sprites(t_vars *option)
{
	int			i;
	int			j;
	t_sprite	*tmp;

	i = 0;
	while (i < option->sprites_count)
	{
		j = 0;
		while (j < option->sprites_count - i - 1)
		{
			if (option->sprites[j]->sprite_distance
			< option->sprites[j + 1]->sprite_distance)
			{
				tmp = option->sprites[j];
				option->sprites[j] = option->sprites[j + 1];
				option->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_render(t_vars *option)
{
	int i;

	i = 0;
	while (i < option->sprites_count)
	{
		option->sprite_order[i] = i;
		option->sprites[i]->sprite_distance =
		((option->plr.x - option->sprites[i]->x)
		* (option->plr.x - option->sprites[i]->x)
		+ (option->plr.y - option->sprites[i]->y)
		* (option->plr.y - option->sprites[i]->y));
		i++;
	}
	sort_sprites(option);
}

void	init_variable(t_vars *option, int i)
{
	option->sinfo.spritex = option->sprites[option->sprite_order[i]]->x
	- option->plr.x;
	option->sinfo.spritey = option->sprites[option->sprite_order[i]]->y
	- option->plr.y;
	option->sinfo.invdet = 1.0 / (option->plr.planex
	* option->plr.diry - option->plr.dirx * option->plr.planey);
	option->sinfo.transformx = option->sinfo.invdet
	* (option->plr.diry * option->sinfo.spritex - option->plr.dirx
	* option->sinfo.spritey);
	option->sinfo.transformy = option->sinfo.invdet
	* (-option->plr.planey * option->sinfo.spritex + option->plr.planex
	* option->sinfo.spritey);
	option->sinfo.spritescreenx = (int)((option->set->w_width / 2)
	* (1 + option->sinfo.transformx / option->sinfo.transformy));
	option->sinfo.spriteheight = abs((int)(option->set->w_height
	/ (option->sinfo.transformy)));
	option->sinfo.drawstarty = -option->sinfo.spriteheight
	/ 2 + option->set->w_height / 2;
}

void	draw_sprites(t_vars *option)
{
	int i;

	i = 0;
	sprite_render(option);
	while (i < option->sprites_count)
	{
		init_variable(option, i++);
		if (option->sinfo.drawstarty < 0)
			option->sinfo.drawstarty = 0;
		option->sinfo.drawendy = option->sinfo.spriteheight
		/ 2 + option->set->w_height / 2;
		if (option->sinfo.drawendy >= option->set->w_height)
			option->sinfo.drawendy = option->set->w_height - 1;
		option->sinfo.spritewidth = abs((int)(option->set->w_height
		/ (option->sinfo.transformy)));
		option->sinfo.drawstartx = -option->sinfo.spritewidth / 2
		+ option->sinfo.spritescreenx;
		if (option->sinfo.drawstartx < 0)
			option->sinfo.drawstartx = 0;
		option->sinfo.drawendx = option->sinfo.spritewidth
		/ 2 + option->sinfo.spritescreenx;
		if (option->sinfo.drawendx >= option->set->w_width)
			option->sinfo.drawendx = option->set->w_width - 1;
		draw_sprite_piece(option);
	}
}

void	draw_sprite_piece(t_vars *option)
{
	int stripe;

	stripe = option->sinfo.drawstartx;
	while (stripe < option->sinfo.drawendx)
	{
		option->sinfo.texx = (int)(256
		* (stripe - (-option->sinfo.spritewidth / 2
		+ option->sinfo.spritescreenx)) * option->textures[4].texwidth
		/ option->sinfo.spritewidth) / 256;
		if (option->sinfo.transformy > 0 && stripe > 0
			&& stripe < option->set->w_width
			&& option->sinfo.transformy < option->z_buffer[stripe])
			draw_pod_y(option, stripe);
		stripe++;
	}
}
