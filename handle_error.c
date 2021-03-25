/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:11:59 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/24 22:12:05 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void				handle_error(char *message, t_all *all)
{
	ft_putstr_fd("Error\n", 0);
	ft_putstr_fd(message, 0);
//	auto_clear(all);
	exit(EXIT_FAILURE);
}
