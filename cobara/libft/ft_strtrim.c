/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:22:21 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:38:51 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		iscontains(char c, char *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (iscontains(s1[start], (char *)set) == 1)
		start++;
	while (end > start && iscontains(s1[end - 1], (char*)set) == 1)
		end--;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
