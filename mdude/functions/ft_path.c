/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:00:57 by mdude             #+#    #+#             */
/*   Updated: 2021/03/07 12:00:58 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			count_space(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (is_space(str[i]))
	{
		count++;
		i++;
	}
	return (count);
}

void		ch_path(char *str)
{
	int		len;

	len = ft_strlen(str) - 1;
	if (len < 5)
	{
		write(1, "Error\nInvalid path\n", 19);
		exit(0);
	}
	if (str[len] != 'm' && str[len - 1] != 'p' &&
	str[len - 2] != 'x' && str[len - 3] != '.')
	{
		write(1, "Error\nInvalid path\n", 19);
		exit(0);
	}
}

char		*ft_path(const char *s1)
{
	char	*newstr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (is_space(s1[count]))
		count++;
	newstr = (char*)malloc(ft_strlen(s1) + 1 - count);
	if (!newstr)
		return (NULL);
	else
	{
		while (s1[count] != '\0')
		{
			newstr[i] = s1[count];
			i++;
			count++;
		}
		newstr[i] = '\0';
		ch_path(newstr);
		return (newstr);
	}
}
