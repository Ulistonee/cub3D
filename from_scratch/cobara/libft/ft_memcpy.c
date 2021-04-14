/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:01:51 by cobara            #+#    #+#             */
/*   Updated: 2020/11/09 16:48:57 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *desination, const void *source, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	i = 0;
	to = (unsigned char *)desination;
	from = (unsigned char *)source;
	if (to == NULL && from == NULL)
		return (NULL);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (desination);
}
