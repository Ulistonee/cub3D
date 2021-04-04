/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:36:56 by mdude             #+#    #+#             */
/*   Updated: 2021/03/06 12:36:57 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*save_line(char *line, char *temp)
{
	char	*newtemp;
	char	*tmp;

	if (line[0] == '\0')
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(0);
	}
	newtemp = ft_strjoin(line, "\n");
	tmp = temp;
	temp = ft_strjoin(temp, newtemp);
	free(newtemp);
	free(tmp);
	return (temp);
}
