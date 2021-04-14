/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:31:28 by mdude             #+#    #+#             */
/*   Updated: 2021/02/28 16:00:24 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			flag_res(t_pos xy, double k, int flag_y, double an)
{
	int		flag_x;

	if (((int)xy.y % (int)k) == 0 && flag_y == 1)
		flag_x = 1;
	if (((int)(xy.y - sin(an)) % (int)k) == 0 && flag_y == 1)
		flag_x = 2;
	if (((int)xy.x % (int)k) == 0 && flag_y == 2)
		flag_x = 3;
	if (((int)(xy.x - cos(an)) % (int)k) == 0 && flag_y == 2)
		flag_x = 4;
	return (flag_x);
}

double		len_ray(t_pos *xy, int *flag_y, double an, t_vars *vars)
{
	int		count;

	count = 0;
	*flag_y = 0;
	while (!is_wall(vars->map.map, xy->y, xy->x, vars->k))
	{
		xy->y = xy->y + sin(an) / vars->k;
		if (is_wall(vars->map.map, xy->y, xy->x, vars->k))
		{
			*flag_y = 1;
			break ;
		}
		xy->x = xy->x + cos(an) / vars->k;
		if (is_wall(vars->map.map, xy->y, xy->x, vars->k))
		{
			*flag_y = 2;
			break ;
		}
		count = count + 1;
	}
	return (count);
}

double		len_p(int flag_x, t_pos xy, t_tex *tex, t_vars *vars)
{
	double	p;

	if (flag_x == 1 || flag_x == 2)
		p = fabs((int)xy.x / (int)vars->k -
				(double)(xy.x / vars->k)) * tex[flag_x - 1].w;
	if (flag_x == 3 || flag_x == 4)
		p = fabs((int)xy.y / (int)vars->k -
				(double)(xy.y / vars->k)) * tex[flag_x - 1].w;
	return (p);
}

void		init_hp(t_wall *wall, t_vars *vars, t_tex *tex, t_pos xy)
{
	wall->h = (double)(WALLL / wall->len *
			(double)((vars->map.id_r.width / 2.0) / (tan(M_PI / 6.0))));
	wall->temp = 0;
	if (wall->h > vars->map.id_r.height)
	{
		wall->temp = wall->h - vars->map.id_r.height;
		wall->h = vars->map.id_r.height;
	}
	wall->p = len_p(wall->flag_x, xy, tex, vars);
}

void		paint_ray(t_vars *vars)
{
	t_pos	xy;
	t_pos	pos;
	t_tex	*tex;
	double	zbuffer[(int)vars->map.id_r.width];
	t_wall	wall;

	tex = init_tex(vars);
	pos = get_pos(&vars->pl);
	wall.pos.x = -1;
	wall.an = vars->pl.angle - M_PI / 6.0;
	while (++wall.pos.x < vars->map.id_r.width)
	{
		xy = pos;
		wall.len = len_ray(&xy, &wall.flag_y, wall.an, vars);
		wall.flag_x = flag_res(xy, vars->k, wall.flag_y, wall.an);
		wall.len = wall.len * cos((vars->pl.angle - wall.an));
		init_hp(&wall, vars, tex, xy);
		wall.pos.y = (double)(vars->map.id_r.height / 2.0) -
				(double)(wall.h / 2.0);
		draw_col(&wall, vars, tex, wall.flag_x);
		zbuffer[(int)wall.pos.x] = wall.len;
		wall.an = wall.an + (double)(M_PI / (3 * vars->map.id_r.width));
	}
	draw_sp(vars, zbuffer);
	free(tex);
}
