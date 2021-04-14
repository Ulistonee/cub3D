/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:58:09 by cobara            #+#    #+#             */
/*   Updated: 2021/01/14 12:04:24 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		read_from_buf(int fd, char **line, char **file_text)
{
	char	*buf;
	int		read_bytes;
	int		result;

	buf = (char *)malloc((size_t)BUFFER_SIZE * sizeof(char) + 1);
	if (buf == NULL)
		return (-1);
	while ((read_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		result = create_str_buf(&buf, line, file_text);
		if (result != 0)
			return (result);
		free(*file_text);
		*line = ft_strjoin_gnl(*line, buf);
		if (line == NULL)
			return (-1);
	}
	free(buf);
	if (read_bytes == -1)
		return (-1);
	return (0);
}

int		create_str_buf(char **buf, char **line, char **file_text)
{
	int i;

	i = 0;
	while ((*buf)[i] != '\0')
	{
		if ((*buf)[i] == '\n')
		{
			(*buf)[i] = '\0';
			*line = ft_strjoin_gnl(*line, *buf);
			free(*file_text);
			*file_text = ft_strdup_gnl(((*buf) + i + 1));
			if (file_text == NULL)
			{
				free(line);
				free(*buf);
				free(file_text);
				return (-1);
			}
			free(*buf);
			return (1);
		}
		i++;
	}
	return (0);
}

void	create_str(char **line, char **file_text, int i)
{
	char *sub_file;

	sub_file = NULL;
	(*file_text)[i] = '\0';
	free(*line);
	*line = ft_strdup_gnl(*file_text);
	free(sub_file);
	sub_file = ft_strdup_gnl(*file_text + i + 1);
	free(*file_text);
	*file_text = ft_strdup_gnl(sub_file);
	free(sub_file);
}

int		read_from_ost(char **line, char **file_text)
{
	int i;

	i = 0;
	if (*file_text != NULL)
	{
		while ((*file_text)[i] != '\0')
		{
			if ((*file_text)[i] == '\n')
			{
				create_str(line, file_text, i);
				if (*line == NULL)
					return (-1);
				return (1);
			}
			i++;
		}
		free(*line);
		*line = ft_strdup_gnl(*file_text);
		free(*file_text);
		*file_text = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*file_text;
	int				result;

	if (BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup_gnl("");
	result = read_from_ost(line, &file_text);
	if (result == 1)
		return (1);
	if (result == -1)
		return (-1);
	result = read_from_buf(fd, line, &file_text);
	return (result);
}
