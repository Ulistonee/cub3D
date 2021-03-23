/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:50:53 by rchalmer          #+#    #+#             */
/*   Updated: 2021/01/09 16:56:03 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = (unsigned char *)b;
	while (len--)
		*(a++) = (unsigned char)c;
	return (b);
}

char		*ft_strdup(const char *s1)
{
	char		*new;
	int			size;
	int			i;

	size = ft_strlen(s1);
	if (!(new = malloc(size + 1)))
		return (NULL);
	ft_memset(new, 0, (size + 1));
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
** modified strchr :)
** injected '\0' for GNL project
*/

char		*ft_strchr_mod(char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			*s = '\0';
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		len3;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	len3 = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(s3 = malloc(sizeof(char) * (len3 + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
