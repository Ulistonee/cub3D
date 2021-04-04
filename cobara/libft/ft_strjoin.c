/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:10:01 by cobara            #+#    #+#             */
/*   Updated: 2020/11/07 10:03:01 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		lens1;
	int		lens2;
	int		i;
	int		cur;

	cur = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[cur] != '\0')
		result[i++] = s2[cur++];
	result[i] = '\0';
	return (result);
}
