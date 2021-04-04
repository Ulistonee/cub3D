/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:48:23 by cobara            #+#    #+#             */
/*   Updated: 2020/11/09 16:49:21 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;

	array = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (*(array + i) == (unsigned char)c)
			return ((void *)(array + i));
		i++;
	}
	return (NULL);
}
