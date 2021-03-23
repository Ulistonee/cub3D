#include "../cub3D.h"

void				check_val_integrity(t_all *all)
{
	if (all->data.res1 <= 0 || all->data.res2 <= 0 || !all->data.no ||!all->data.ea ||
			!all->data.we ||
			!all->data.so ||
			all->data.flr_1 < 0 || all->data.flr_1 > 255 ||
			all->data.flr_2 < 0 || all->data.flr_2 > 255 ||
			all->data.flr_3 < 0 || all->data.flr_3 > 255 ||
			all->data.ceil_1 < 0 || all->data.ceil_1 > 255 ||
			all->data.ceil_2 < 0 || all->data.ceil_2 > 255 ||
			all->data.ceil_3 < 0 || all->data.ceil_3 > 255 ||
			!all->data.s)
		handle_error("Not full data\n", all);
}

void				init_val(t_all *all)
{
	all->data.res1 = 0;
	all->data.res2 = 0;
	all->data.no = NULL;
	all->data.ea = NULL;
	all->data.we = NULL;
	all->data.so = NULL;
	all->data.flr_1 = -1;
	all->data.flr_2 = -1;
	all->data.flr_3 = -1;
	all->data.flr = 0;
	all->data.ceil = 0;
	all->data.ceil_1 = -1;
	all->data.ceil_2 = -1;
	all->data.ceil_3 = -1;
	all->data.s = NULL;
	all->data.p = 0;
}

int 				parse_file(char *file_name, t_all *all)
{
	int 			fd;
	char			*line;
	int 			i;
	int				res;

	i = 0;
	all->map.map = (char**)malloc(sizeof(char*) * all->map.lines); // allocate memory for two-dimensional array
	if ((fd = open(file_name, O_RDONLY)) < 0)
		handle_error("Can't open the file, invalid file\n", all);
	res = get_next_line(fd, &line);
	while (!is_map(line))
	{
		parse_other(all, line);
		ft_free_mem(&line);
		res = get_next_line(fd, &line);
	}
	while (is_map(line))
	{
		all->map.map[i++] = ft_strdup(line);
		ft_free_mem(&line);
		res = get_next_line(fd, &line);
		if (!res && is_map(line))
		{
			all->map.map[i++] = ft_strdup(line);
			break ;
		}
	}
	ft_free_mem(&line);
}

// we use the sequence pattern: !is_map -> is_map -> '\0'.
// otherwise we call handle_error (if the sequence is violated).
// also it counts the size of the map array.
// also validates the map
void				validate_file(t_all *all, char *file_name)
{
	int 			fd;
	char			*line;
	int 			counter;
	int 			res;

	counter = 0; // lines` counter
	if ((fd = open(file_name, O_RDONLY)) < 0)
		handle_error("Can't open the file, invalid file\n", all);
	res = get_next_line(fd, &line);
	while (!is_map(line) && res > 0)
	{
		ft_free_mem(&line);
		res = get_next_line(fd, &line);
	}
	while (is_map(line))
	{
		ft_free_mem(&line);
		counter++;
		res = get_next_line(fd, &line);
		if (!res && is_map(line))
		{
			ft_free_mem(&line);
			counter++;
			break ;
		}
	}
	// res > 0
	while (line && !is_map(line) && *line == '\0')
	{
		ft_free_mem(&line);
		res = get_next_line(fd, &line);
		if (!res && line && !is_map(line) && *line == '\0')
		{
			ft_free_mem(&line);
			break ;
		}
	}
	if (res != 0 || (line && *line != '\0') || counter == 0)
	{
		ft_free_mem(&line);
		handle_error("Invalid map\n", all);
	}
	all->map.lines = counter;
	close(fd);
}

void					parser(t_all *all, char *file_name)
{
	validate_file(all, file_name);
	init_val(all);
	parse_file(file_name, all);
	enter_validator(all);
	check_val_integrity(all);
}