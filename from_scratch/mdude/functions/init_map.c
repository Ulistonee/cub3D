/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:19:27 by mdude             #+#    #+#             */
/*   Updated: 2021/01/23 12:19:28 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->id_r.width = -1;
	map->id_r.height = -1;
	map->id_no = NULL;
	map->id_so = NULL;
	map->id_we = NULL;
	map->id_ea = NULL;
	map->id_s = NULL;
	map->id_f.red = -1;
	map->id_f.green = -1;
	map->id_f.blue = -1;
	map->id_c.green = -1;
	map->id_c.red = -1;
	map->id_c.blue = -1;
	map->map = NULL;
}
