#include "cub3D.h"

void			auto_clear(t_all *all)
{
	char		**p;

	if (all->map.map)
	{
		p = all->map.map;
		while (*p)
		{
			ft_free_mem(p);
			p++;
		}
		free(all->map.map);
	}
	if (all->spr_arr)
		ft_free_mem((char **) &all->spr_arr);
}

static int		check_extension(char *file, char *exp)
{
	int			f_len;
	int			e_len;
	int			i;

	f_len = (int)ft_strlen(file);
	e_len = (int)ft_strlen(exp);
	i = -1;
	if (f_len <= e_len)
		return (0);
	while (++i < e_len)
		if (exp[e_len - 1 - i] != file[f_len - 1 - i])
			return (0);
	return (1);
}

int 			key_hook(int keynumber, t_all *all)
{
		double			old_x;
		t_pos			new_pos;

		if (keynumber == ESC)
			exit(0);
		if (keynumber == W || keynumber == UP)
		{
			new_pos.x = all->player.dir.x * STEP + all->player.pos.x;
			new_pos.y = all->player.dir.y * STEP + all->player.pos.y;
			if (all->map.map[(int)new_pos.y][(int)new_pos.x] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == S || keynumber == DOWN)
		{
			new_pos.x = -all->player.dir.x * STEP + all->player.pos.x;
			new_pos.y = -all->player.dir.y * STEP + all->player.pos.y;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == LEFT)
		{
			old_x = all->player.dir.x;
			all->player.dir.x = old_x * cos(-ANGLE) - all->player.dir.y * sin(-ANGLE);
			all->player.dir.y = old_x * sin(-ANGLE) + all->player.dir.y * cos(-ANGLE);
			old_x = all->player.plane.x;
			all->player.plane.x = old_x * cos(-ANGLE) - all->player.plane.y * sin(-ANGLE);
			all->player.plane.y = old_x * sin(-ANGLE) + all->player.plane.y * cos(-ANGLE);
		}
		if (keynumber == A)
		{
			new_pos.x = all->player.pos.x + all->player.dir.y * STEP;
			new_pos.y = all->player.pos.y - all->player.dir.x * STEP;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == D)
		{
			new_pos.x = all->player.pos.x - all->player.dir.y * STEP;
			new_pos.y = all->player.pos.y + all->player.dir.x * STEP;
			if (all->map.map[(int) (new_pos.y)][(int) (new_pos.x)] == '0')
			{
				all->player.pos.x = new_pos.x;
				all->player.pos.y = new_pos.y;
			}
		}
		if (keynumber == RIGHT)
			{
				old_x = all->player.dir.x;
				all->player.dir.x = old_x * cos(ANGLE) - all->player.dir.y * sin(ANGLE);
				all->player.dir.y = old_x * sin(ANGLE) + all->player.dir.y * cos(ANGLE);
				old_x = all->player.plane.x;
				all->player.plane.x = old_x * cos(ANGLE) - all->player.plane.y * sin(ANGLE);
				all->player.plane.y = old_x * sin(ANGLE) + all->player.plane.y * cos(ANGLE);
			}
		return (0);
}

int					main(int argc, char *argv[])
{
	t_all			all;

	all.save_flag = 0;
	if ((argc == 2 && check_extension(argv[1], ".cub"))
		|| (argc == 3 && (!ft_strncmp("--save", argv[2], 6))))
	{
		if (argc == 3)
			all.save_flag = 1;
		parser(&all, argv[1]);
		all.display.mlx = mlx_init();
		all.display.mlx_win = mlx_new_window(all.display.mlx, all.data.res1, all.data.res2,
											  "My_cub3D");
		init_game(&all);
		display(&all);
		mlx_hook(all.display.mlx_win, 2, (1L<<0), key_hook, &all);
		mlx_loop_hook(all.display.mlx, display, &all);
		mlx_loop(all.display.mlx);
	}
	else
		handle_error("Exit game\n", &all);
	return 0;
}
