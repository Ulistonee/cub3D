/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:49:18 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 15:49:20 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
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

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		start;
	int		finish;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] != '\0' && ft_isset(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	finish = (int)ft_strlen(s1) - 1;
	while (finish >= 0 && ft_isset(s1[finish], set))
		finish--;
	if (finish == -1)
		return (ft_strdup(""));
	newstr = (char *)malloc(finish - start + 2);
	if (!newstr)
		return (NULL);
	i = 0;
	while (finish >= start)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}
