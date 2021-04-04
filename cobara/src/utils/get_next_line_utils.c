/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:56 by cobara            #+#    #+#             */
/*   Updated: 2021/01/14 12:03:47 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *str)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen_gnl(str);
	i = 0;
	result = (char *)malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*result;
	int		lens1;
	int		lens2;
	int		i;
	int		cur;

	cur = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	result = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[cur] != '\0')
		result[i++] = s2[cur++];
	result[i] = '\0';
	free(s1);
	return (result);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
