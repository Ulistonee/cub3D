#include "../cub3D.h"

int 				parse_file(char *file_name, t_all *all)
{
	int 			fd;
	char			*line;
	int 			i;

	all->map.map = (char**)malloc(sizeof(char*) * all->map.lines); // allocate memory for two-dimensional array
//	handle_error(errno, &all);
	fd = open(file_name, O_RDONLY); // open flow again for parsing
//	handle_error(errno, &all);
	i = 0;
	while (get_next_line(fd , &line))
	{
		if (is_map(line))
		{
			all->map.map[i++] = ft_strdup(line); // create x-lines in the
			// two-dimensional array
		}
		else
			parse_other(all, line);
		ft_free_mem(&line);
	}
	return (1);
}

int 				count_lines(t_all *all, char *file_name)
{
	int 			fd;
	char			*line;
	int				counter;
	int				flag;
	int				res;

	counter = 0; // lines` counter
	fd = open(file_name, O_RDONLY);
//	handle_error(errno, &all); // identify errors on the initial stage such as no file etc.
	flag = 0;
	while ((res = get_next_line(fd, &line)) >= 0) // start GNL to count map size
	{
		if (is_map(line))
		{
			if (flag)
				handle_error("Invalid map\n", all);
			counter++;
			ft_free_mem(&line);
		}
		else if (counter > 0)
			flag = 1;
		if (res == 0)
			break;
	}
	all->map.lines = counter;
	close(fd);
	return (0);
}

int					parser(t_all *all, char *file_name)
{
	count_lines(all, file_name);
	if (!(parse_file(file_name, all)))
		return (-1);
	return (0);
}