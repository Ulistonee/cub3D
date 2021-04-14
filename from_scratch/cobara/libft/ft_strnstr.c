/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:21:41 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:56:41 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	char	*stra;
	char	*strb;
	size_t	i;
	size_t	lenstr;

	stra = (char *)hay;
	strb = (char *)need;
	i = 0;
	lenstr = ft_strlen(need);
	if (lenstr > ft_strlen(hay))
		return (NULL);
	while (i < len)
	{
		if (i + lenstr > len)
			return (NULL);
		if (ft_strncmp(stra + i, strb, lenstr) == 0)
			return (stra + i);
		i++;
	}
	if (ft_strlen(need) == 0)
		return ((char *)(hay));
	return (NULL);
}
