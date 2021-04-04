/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:26:12 by cobara            #+#    #+#             */
/*   Updated: 2020/11/08 14:14:07 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					isminus;

	isminus = 1;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		isminus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
		result = result * 10 + (str[i++] - '0');
	if (result > 9223372036854775807 && isminus == 1)
		return (-1);
	else if (result > 9223372036854775807 && isminus == -1)
		return (0);
	return (result * isminus);
}
