/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:46:33 by cobara            #+#    #+#             */
/*   Updated: 2020/11/09 16:48:44 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;

	result = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		result[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
