/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_of_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:28:52 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:28:56 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

double			len_of_vec(double x, double y)
{
	double		len;

	len = sqrt(pow(x, 2) + pow(y, 2));
	return (len);
}
