/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:33:42 by mdude             #+#    #+#             */
/*   Updated: 2021/02/28 16:14:46 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ex_path(void)
{
	write(1, "Invalid path\n", 13);
	exit(0);
}

t_tex		*init_tex(t_vars *vars)
{
	t_tex	*tex;
	int		i;

	if (!(tex = (t_tex*)malloc(sizeof(t_tex) * 6)))
		return (NULL);
	if (!(tex[0].img.img = mlx_xpm_file_to_image(vars->mlx, vars->map.id_so,
					&tex[0].w, &tex[0].h)) ||
			!(tex[1].img.img = mlx_xpm_file_to_image(vars->mlx, vars->map.id_no,
					&tex[1].w, &tex[1].h)) ||
			!(tex[2].img.img = mlx_xpm_file_to_image(vars->mlx, vars->map.id_ea,
					&tex[2].w, &tex[2].h)) ||
			!(tex[3].img.img = mlx_xpm_file_to_image(vars->mlx, vars->map.id_we,
					&tex[3].w, &tex[3].h)) ||
			!(tex[4].img.img = mlx_xpm_file_to_image(vars->mlx, vars->map.id_s,
					&tex[4].w, &tex[4].h)))
		ex_path();
	i = -1;
	while (++i < 5)
		tex[i].img.addr = mlx_get_data_addr(tex[i].img.img,
				&tex[i].img.bits_per_pixel, &tex[i].img.line_length,
				&tex[i].img.endian);
	return (tex);
}
