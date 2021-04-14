/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:04:42 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:32:31 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numberzen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= -10;
		len += 2;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		numberlen;
	int		to;

	to = 0;
	numberlen = numberzen(n);
	result = (char *)malloc((numberlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numberlen--] = '\0';
	if (n < 0)
	{
		to = 1;
		result[numberlen] = ((n % 10) * -1) + '0';
		n /= -10;
		numberlen--;
		result[0] = '-';
	}
	while (numberlen >= to)
	{
		result[numberlen] = ((n % 10) + '0');
		n /= 10;
		numberlen--;
	}
	return (result);
}
