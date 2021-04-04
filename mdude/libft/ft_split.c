/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:18:06 by mdude             #+#    #+#             */
/*   Updated: 2020/11/02 12:18:08 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	freemas(char **res, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static int	fillsplit(char **res, char const *s, char c)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c || i == (int)ft_strlen(s))
		{
			k = 0;
			if (!(res[j] = (char *)malloc(sizeof(char) * (i - count + 1))))
				return (freemas(res, j));
			while (i > count)
				res[j][k++] = s[count++];
			res[j++][k] = '\0';
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_countwords(s, c);
	res = (char **)malloc(sizeof(char*) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (!(fillsplit(res, &s[i], c)))
		return (NULL);
	res[len] = NULL;
	return (res);
}
