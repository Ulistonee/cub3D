#include "cub3D.h"
#include "minilibx-linux/mlx.h"

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             main(void)
{
	void    *mlx;
	void    *mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "My_cub3D");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	int x = 0;
	int y = 0;
	while (y < 50)
	{
		printf("Y:%d\n", y);
		my_mlx_pixel_put(&img, x, y, 0xFF0000);
		x = 0;
		while (x < 50)
		{
			printf("X:%d\t", x);
			my_mlx_pixel_put(&img, x, y, 0xFF0000);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);
	return (0);
}

