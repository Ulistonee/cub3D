/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:03:17 by rchalmer          #+#    #+#             */
/*   Updated: 2021/04/02 17:03:20 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub.h"

static void		valid_algr_two(char **line, int res, int fd, t_all *all)
{
	int			i;

	i = 0;
	while (!is_map(*line))
	{
		parse_other(all, *line);
		ft_free_mem(line);
		res = get_next_line(fd, line);
	}
	while (is_map(*line))
	{
		all->map.map[i++] = ft_strdup(*line);
		ft_free_mem(line);
		res = get_next_line(fd, line);
		if (!res && is_map(*line))
		{
			all->map.map[i++] = ft_strdup(*line);
			break ;
		}
	}
	ft_free_mem(line);
}

static void		parse_file(char *file_name, t_all *all)
{
	int				fd;
	char			*line;
	int				i;
	int				res;

	i = 0;
	if (!(all->map.map = (char**)malloc(sizeof(char*) * all->map.lines)))
		handle_error("Memory allocation error\n, Exit game\n", all);
	while (i < all->map.lines)
		all->map.map[i++] = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		handle_error("Can't open the file, invalid file\n", all);
	res = get_next_line(fd, &line);
	valid_algr_two(&line, res, fd, all);
}

static int		valid_algr(char **line, int res, int fd, t_all *all)
{
	while (!is_map(*line) && res > 0 && ft_free_mem(line))
		res = get_next_line(fd, line);
	while (is_map(*line) && ft_free_mem(line))
	{
		all->map.lines++;
		res = get_next_line(fd, line);
		if (!res && is_map(*line) && ft_free_mem(line))
		{
			all->map.lines++;
			break ;
		}
	}
	while (*line && !is_map(*line) && **line == '\0' && ft_free_mem(line))
	{
		res = get_next_line(fd, line);
		if (!res && *line && !is_map(*line)
		&& **line == '\0' && ft_free_mem(line))
			break ;
	}
	return (res);
}

/*
** we use the sequence pattern: !is_map -> is_map -> '\0'.
** otherwise we call handle_error (if the sequence is violated).
** also it counts the size of the map array.
** also validates the map
*/

static void		validate_file(t_all *all, char *file_name)
{
	int				fd;
	char			*line;
	int				res;

	all->map.lines = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		handle_error("Can't open the file, invalid file\n", all);
	res = get_next_line(fd, &line);
	res = valid_algr(&line, res, fd, all);
	if ((res != 0 || (line && *line != '\0') ||
	all->map.lines == 0) && ft_free_mem(&line))
		handle_error("Invalid map\n", all);
	close(fd);
}

void			parser(t_all *all, char *file_name)
{
	validate_file(all, file_name);
	init_val(all);
	parse_file(file_name, all);
	enter_validator(all);
	check_val_integrity(all);
}
