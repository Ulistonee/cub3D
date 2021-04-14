/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:43:51 by mdude             #+#    #+#             */
/*   Updated: 2021/02/23 13:43:52 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			sizeoffile(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

static int			*header(t_vars *vars, int fd)
{
	unsigned char	bitmap[14];
	int				size;

	ft_bzero(bitmap, 14);
	bitmap[0] = (unsigned char)'B';
	bitmap[1] = (unsigned char)'M';
	size = (vars->map.id_r.width * vars->map.id_r.height * 4) + 54;
	sizeoffile(bitmap + 2, size);
	bitmap[10] = (unsigned char)54;
	write(fd, bitmap, 14);
	return (0);
}

static int			*data(t_vars *vars, int fd)
{
	unsigned char	bitmap[40];
	int				width;
	int				height;

	ft_bzero(bitmap, 40);
	bitmap[0] = (unsigned char)40;
	height = vars->map.id_r.height;
	width = vars->map.id_r.width;
	sizeoffile(bitmap + 4, width);
	sizeoffile(bitmap + 8, height);
	bitmap[12] = (unsigned char)1;
	bitmap[14] = (unsigned char)32;
	write(fd, bitmap, 40);
	return (0);
}

static int			*bmp_draw(t_vars *vars, int fd)
{
	int				i;
	int				j;

	i = vars->map.id_r.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < vars->map.id_r.width)
		{
			write(fd, vars->img.addr + (i * vars->img.line_length
			+ j * (vars->img.bits_per_pixel / 8)), 4);
			j++;
		}
		i--;
	}
	return (0);
}

int					screen(t_vars *vars)
{
	int				fd;

	fd = open("screen.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	header(vars, fd);
	data(vars, fd);
	bmp_draw(vars, fd);
	close(fd);
	exit(0);
}
