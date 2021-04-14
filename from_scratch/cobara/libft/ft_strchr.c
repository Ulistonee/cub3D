/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:00:05 by cobara            #+#    #+#             */
/*   Updated: 2020/11/08 14:50:24 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	if (ch == '\0')
	{
		i = ft_strlen(str);
		return ((char *)(str + i));
	}
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
