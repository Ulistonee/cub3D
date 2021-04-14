/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:59:26 by cobara            #+#    #+#             */
/*   Updated: 2020/11/16 13:31:15 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);

char	*ft_strdup_gnl(const char *str);

char	*ft_strjoin_gnl(char *s1, char const *s2);

size_t	ft_strlen_gnl(const char *str);

int		create_str_buf(char **buf, char **line, char **file_text);

void	create_str(char **line, char **file_text, int i);

int		read_from_ost(char **line, char **file_text);

int		read_from_buf(int fd, char **line, char **file_text);

#endif
