#include "cub3D.h"

int 			handle_error(int code, t_all *all)
{
	if (code != 0)
	{
		ft_putstr_fd(strerror(code), 1);
//		clear_all(all);
		exit(EXIT_FAILURE);
	}
	return (1);
}