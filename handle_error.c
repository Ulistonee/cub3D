#include "cub3D.h"

void 			handle_error(char *message, t_all *all)
{
	ft_putstr_fd("Error\n", 0);
	ft_putstr_fd(message, 1);
//		clear_all(all);
	exit(EXIT_FAILURE);
}