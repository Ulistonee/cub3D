/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:08:04 by rchalmer          #+#    #+#             */
/*   Updated: 2021/01/08 21:50:13 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_mem(char **mem)
{
	if (*mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*str1;
	size_t		sz;

	sz = count * size;
	if (!(str1 = malloc(sz)))
		return (NULL);
	ft_memset(str1, 0, sz);
	return (str1);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*check_storage(char *what_left, char **line)
{
	char		*new_l;
	char		*tmp;

	new_l = NULL;
	if (what_left)
	{
		if ((new_l = ft_strchr_mod(what_left, '\n')))
		{
			tmp = *line;
			*line = ft_strdup(what_left);
			free_mem(&tmp);
			ft_strcpy(what_left, ++new_l);
		}
		else
		{
			tmp = *line;
			*line = ft_strdup(what_left);
			free_mem(&tmp);
			free_mem(&what_left);
			what_left = NULL;
		}
	}
	return (new_l);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	char			*new_l;
	static char		*what_left;
	char			*tmp;
	int				rd;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	new_l = check_storage(what_left, line);
	while (!new_l && ((rd = read(fd, buf, BUFFER_SIZE)) > 0) && *line != NULL)
	{
		buf[rd] = '\0';
		if ((new_l = ft_strchr_mod(buf, '\n')))
			what_left = ft_strdup(++new_l);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free_mem(&tmp);
	}
	if (rd == -1 || *line == NULL)
		return (-1);
	if (new_l)
		return (1);
	what_left = NULL;
	return (0);
}
