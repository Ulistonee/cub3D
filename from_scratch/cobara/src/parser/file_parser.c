/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:07:45 by cobara            #+#    #+#             */
/*   Updated: 2021/01/19 13:07:46 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubgame.h"

char		**parse_file(char *filename)
{
	int		fd;
	char	*line;
	t_list	*head;

	head = NULL;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_print_error(1);
	}
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	return (make_map(&head, ft_lstsize(head)));
}

char		**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	tmp = *head;
	while (tmp)
	{
		map[i++] = ft_strdup_gnl(tmp->content);
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	return (map);
}

t_set		*parse_map(char **map)
{
	t_set	*setting;
	int		size;

	size = 0;
	setting = malloc(sizeof(t_set));
	ft_init(setting);
	parse_resolution(map, setting);
	parse_textures(map, setting);
	parse_color_f(map, setting);
	check_repeat(map, 'F', ' ');
	parse_color_с(map, setting);
	check_repeat(map, 'C', ' ');
	check_all_param(setting);
	check_posit(map, 'W', 'E');
	check_posit(map, 'S', 'O');
	check_posit(map, 'N', 'O');
	check_posit(map, 'E', 'A');
	check_another_symb(map);
	size = parse_main_map(map, setting);
	check_map(setting->map, size);
	return (setting);
}

void		parse_resolution(char **map, t_set *settings)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == 'R' && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
			break ;
		i++;
	}
	init_resolution(map, i, j, settings);
}

void		check_all_param(t_set *settings)
{
	if (settings->w_width > 2560 || settings->w_height > 1440)
	{
		settings->w_height = 1440;
		settings->w_width = 2560;
	}
	if (settings->path_noth == NULL || settings->path_south == NULL
	|| settings->path_west == NULL || settings->path_east == NULL
	|| settings->path_sprite == NULL)
		ft_print_error(3);
}
