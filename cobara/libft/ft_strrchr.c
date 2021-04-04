/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:01:34 by cobara            #+#    #+#             */
/*   Updated: 2020/11/08 14:50:14 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;
	int lastcontain;

	i = 0;
	lastcontain = -1;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			lastcontain = i;
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	if (lastcontain == -1)
		return (NULL);
	return ((char*)(str + lastcontain));
}
