/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_dots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:46:32 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 20:46:41 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double			dist_dots(double x, double y, double a, double b)
{
	double			dist;

	dist = sqrt(pow((x - a), 2) + pow((a - b), 2));
	return (dist);
}
