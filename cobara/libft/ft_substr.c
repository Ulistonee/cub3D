/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:54:17 by cobara            #+#    #+#             */
/*   Updated: 2020/11/10 18:08:57 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;
	int		size;

	i = 0;
	size = len;
	result = (char *)malloc((size) * sizeof(char) + 1);
	if (result == NULL || s == NULL)
		return (NULL);
	while (i < size && s[start] != '\0' && start < ft_strlen(s))
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
