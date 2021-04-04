/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:16:08 by cobara            #+#    #+#             */
/*   Updated: 2021/03/07 10:38:47 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"
#include <fcntl.h>

void			init_image(t_vars *all)
{
	int i;
	int j;

	j = 0;
	i = 0;
	all->image = malloc(sizeof(unsigned char **) * (all->set->w_height + 1));
	if (all->image == NULL)
		ft_print_error(4);
	while (i < all->set->w_height)
	{
		all->image[i] = malloc(sizeof(unsigned char *)
		* (all->set->w_width + 1));
		if (all->image[i] == NULL)
			ft_print_error(4);
		j = 0;
		while (j < all->set->w_width)
		{
			all->image[i][j] = malloc(sizeof(unsigned char) * 3);
			if (all->image[i][j] == NULL)
				ft_print_error(4);
			j++;
		}
		i++;
	}
}

void			createbtmp(t_vars *all)
{
	int		height;
	int		width;
	char	*filename;

	height = all->set->w_height;
	width = all->set->w_width;
	filename = "screen.bmp";
	init_image(all);
	make_all(all);
	generate_bitmapimage(all, height, width, filename);
}

void			generate_bitmapimage(t_vars *all, int height, int width,
		char *filename)
{
	int fd;
	int i;
	int j;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0700);
	create_header(height, width, fd);
	create_infoheader(height, width, fd);
	i = height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < width)
		{
			write(fd, all->image[i][j], 3);
			j++;
		}
		i--;
	}
	close(fd);
}

unsigned char	*create_header(int height, int width, int fd)
{
	int				file_size;
	unsigned char	*file_header;

	file_size = 14 + 40 + 3 * height * width;
	file_header = malloc(sizeof(unsigned char) * 14);
	ft_bzero(file_header, 14);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	write(fd, file_header, 14);
	free(file_header);
	return (file_header);
}

unsigned char	*create_infoheader(int height, int width, int fd)
{
	unsigned char	*info_header;

	info_header = NULL;
	info_header = malloc(sizeof(unsigned char) * 40);
	ft_bzero(info_header, 40);
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(3 * 8);
	write(fd, info_header, 40);
	free(info_header);
	return (info_header);
}
