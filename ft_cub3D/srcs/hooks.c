/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:05:12 by rchalmer          #+#    #+#             */
/*   Updated: 2021/03/31 22:05:16 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void			hooks(t_all *all)
{
	mlx_hook(all->dsp.mlx_win, 17, (1L << 0), exit_program, all);
	mlx_hook(all->dsp.mlx_win, 2, (1L << 0), key_hook, all);
	mlx_loop_hook(all->dsp.mlx, display, all);
	mlx_loop(all->dsp.mlx);
}
