/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:19:36 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:31:21 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	result = (void *)malloc(number * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * number);
	return (result);
}
