/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:12:31 by cobara            #+#    #+#             */
/*   Updated: 2020/11/09 16:49:06 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;
	int				isreached;

	i = 0;
	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	isreached = -1;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
		{
			isreached = i;
			break ;
		}
		i++;
	}
	if (isreached != -1)
		return ((void *)(to + i + 1));
	return (NULL);
}
