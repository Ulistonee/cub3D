/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:29:22 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:29:36 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void			perp_vector(t_all *all, double camera_plane, t_ray *ray)
{
	double			ray_len;
	double			k1;

	ray_len = len_of_vec(ray->dir.x, ray->dir.y);
	k1 = 1 * ray->len / ray_len;
	ray->k = (ray->len / ray_len > 0.01) ? k1 : ray->k;
}
