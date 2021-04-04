/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:26:09 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:33:06 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if ((*lst) != NULL && del != NULL)
	{
		while ((*lst) != NULL)
		{
			temp = (*lst);
			(*lst) = (*lst)->next;
			ft_lstdelone(temp, del);
		}
	}
}
