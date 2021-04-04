/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:20:02 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:35:40 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

void			ft_putnbr_fd(int n, int fd)
{
	char	result[13];
	int		numberlen;
	int		to;

	to = 0;
	numberlen = numberzen(n);
	result[numberlen] = '\0';
	numberlen--;
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
	ft_putstr_fd(result, fd);
}
