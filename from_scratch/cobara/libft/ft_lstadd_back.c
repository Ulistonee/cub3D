/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:49:33 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:32:45 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *cur;

	cur = *lst;
	if (new == NULL)
		return ;
	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = new;
	}
}
