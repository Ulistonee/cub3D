/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:06:01 by cobara            #+#    #+#             */
/*   Updated: 2020/11/09 16:49:32 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)arr1;
	buf2 = (unsigned char *)arr2;
	i = 0;
	while (i < n)
	{
		if (buf1[i] > buf2[i])
			return (buf1[i] - buf2[i]);
		if (buf1[i] < buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}
