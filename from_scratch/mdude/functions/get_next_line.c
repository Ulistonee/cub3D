/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:01:28 by mdude             #+#    #+#             */
/*   Updated: 2020/11/23 14:42:02 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_tail(char **str, char ***line, char **ch)
{
	if (*str)
	{
		if ((*ch = ft_strchr(*str, '\n')))
		{
			**line = under(*str);
			*str = ft_strdup(*ch + 1);
		}
		else
		{
			**line = ft_strdup(*str);
			free(*str);
			*str = NULL;
		}
	}
	else
		**line = ft_strdup("");
}

int		get_next_line(int fd, char **line)
{
	char		str[BUFFER_SIZE + 1];
	int			bytes;
	static char	*tail;
	char		*ch;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	ch = NULL;
	is_tail(&tail, &line, &ch);
	while (!ch && ((bytes = read(fd, str, BUFFER_SIZE)) > 0))
	{
		str[bytes] = '\0';
		tmp = *line;
		if ((ch = ft_strchr(str, '\n')))
		{
			tail = ft_strdup(ch + 1);
			*line = ft_strjoin(*line, under(str));
		}
		else
			*line = ft_strjoin(*line, str);
		free(tmp);
	}
	return ((bytes == 0 && !tail) ? 0 : 1);
}
