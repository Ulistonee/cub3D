/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:38:17 by cobara            #+#    #+#             */
/*   Updated: 2020/11/08 14:33:16 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numofcontains(char const *s, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		|| (s[i] != c && s[i + 1] == '\0'))
		{
			result++;
		}
		i++;
	}
	return (result);
}

static void		ft_write(char *dst, char const *start, char c)
{
	int i;

	i = 0;
	while (start[i] != c && start[i] != '\0')
	{
		dst[i] = start[i];
		i++;
	}
	dst[i] = '\0';
}

static char		**clear(char **result, int g)
{
	while (g >= 0)
	{
		free(result[g]);
		g--;
	}
	free(result);
	return (NULL);
}

static char		**create_result(char const *s, size_t j, char **result, char c)
{
	size_t g;
	size_t i;

	i = j + 1;
	g = 0;
	while (s[i] != '\0' && ft_strlen(s) >= i)
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
		{
			result[g] = (char*)malloc(i - j + 1);
			if (result[g] == NULL)
				return (clear(result, g));
			ft_write(result[g++], s + j, c);
			j = i + 1;
		}
		i++;
	}
	if (ft_strlen(s) >= i)
	{
		result[g] = (char *)malloc(i - j + 1);
		ft_write(result[g++], s + j, c);
	}
	result[g] = NULL;
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	int		g;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	g = 0;
	result = (char **)malloc((numofcontains(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[i++] == c)
		j++;
	if (i >= ft_strlen(s))
	{
		result[0] = NULL;
		return (result);
	}
	result = create_result(s, j, result, c);
	if (result == NULL)
		return (NULL);
	return (result);
}
