/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:03:42 by mdude             #+#    #+#             */
/*   Updated: 2021/01/22 12:03:44 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_fd(void)
{
	write(1, "Error\nInvalid path\n", 19);
	exit(0);
}

void		check_null(void)
{
	write(1, "Error\nInvalid map\n", 18);
	exit(0);
}

void		check_col(t_map *map, char *line)
{
	if (map->id_f.blue < 0 || map->id_c.blue < 0)
	{
		write(1, "Error\nInvalid color\n", 20);
		exit(0);
	}
	if (line[0] == '\0')
		check_null();
}

void		fill_map(char *line, char **temp, t_map *map)
{
	int		i;

	i = count_space(line);
	if (line[i] == 'R' && map->id_r.width == -1)
		map->id_r = init_screen(&line[i + 1]);
	else if (line[i] == 'N' && line[i + 1] == 'O' && map->id_no == NULL)
		map->id_no = ft_path(&line[i + 3]);
	else if (line[i] == 'S' && line[i + 1] == 'O' && map->id_so == NULL)
		map->id_so = ft_path(&line[i + 3]);
	else if (line[i] == 'W' && map->id_we == NULL)
		map->id_we = ft_path(&line[i + 3]);
	else if (line[i] == 'E' && map->id_ea == NULL)
		map->id_ea = ft_path(&line[i + 3]);
	else if (line[i] == 'S' && line[i + 1] != 'O' && map->id_s == NULL)
		map->id_s = ft_path(&line[i + 2]);
	else if (line[i] == 'F' && map->id_f.blue == -1)
		map->id_f = init_color(&line[i + 1]);
	else if (line[i] == 'C' && map->id_c.blue == -1)
		map->id_c = init_color(&line[i + 1]);
	else if (line[i] == ' ' || line[i] == '1')
		*temp = save_line(line, *temp);
	else if (line[i] != '\0')
		check_null();
	if (ft_strlen(*temp) > 1 && line[i] == '\0')
		check_null();
}

t_map		parser(char **argv)
{
	char	*line;
	t_map	map;
	char	*temp;
	char	*tmp;
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		check_fd();
	line = NULL;
	init_map(&map);
	temp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(line, &temp, &map);
		free(line);
	}
	tmp = temp;
	check_col(&map, line);
	temp = ft_strjoin(temp, line);
	free(line);
	free(tmp);
	map.map = ft_split(temp, '\n');
	free(temp);
	close(fd);
	return (map);
}
