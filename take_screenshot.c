#include "cub3D.h"

static void			init_bmp_header(t_all *all, int fd)
{
	int				val;

	write(fd, "BM", 2);
	val = 14 + 40 + all->data.res1 * all->data.res2 *
					all->dsp.bits_per_pixel / 8;
	write(fd, &val, 4);
	val = 0;
	write(fd, &val, 4);
	val = 14 + 40;
	write(fd, &val, 4);
	val = 40;
	write(fd, &val, 4);
	write(fd, &all->data.res1, 4);
	write(fd, &all->data.res2, 4);
	val = 1;
	write(fd, &val, 2);
	write(fd, &all->dsp.bits_per_pixel, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void				take_screenshot(t_all *all)
{
	char			*file_name;
	int				fd;
	int				i;

	file_name = "screenshot.bmp";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		handle_error("Can`t open screenshot.bmp\n", all);
	init_bmp_header(all, fd);
	i = all->data.res2;
	while (i-- > 0)
	{
		write(fd, (all->dsp.addr + i * all->dsp.line_length),
			  (all->data.res1 * all->dsp.bits_per_pixel / 8));
	}
	close(fd);
	exit(0);
}