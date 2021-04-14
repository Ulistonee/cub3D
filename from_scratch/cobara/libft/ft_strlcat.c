/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:59:05 by cobara            #+#    #+#             */
/*   Updated: 2020/11/10 16:53:49 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	if (ft_strlen(dst) >= size)
		len = ft_strlen(src) + size;
	else
	{
		len = ft_strlen(dst) + ft_strlen(src);
		j = 0;
		i = 0;
		while (dst[i] != '\0')
			i++;
		if (size != 0)
		{
			while (i < size - 1 && src[j] != '\0')
				dst[i++] = src[j++];
			dst[i] = '\0';
		}
	}
	return (len);
}
