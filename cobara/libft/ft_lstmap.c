/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:39:16 by cobara            #+#    #+#             */
/*   Updated: 2020/11/06 13:33:49 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *result;
	t_list *head;

	if (!lst)
		return (lst);
	result = ft_lstnew((*f)(lst->content));
	if (result == NULL)
		return (NULL);
	head = result;
	if (lst->next == NULL)
		return (head);
	lst = lst->next;
	while (lst)
	{
		result = ft_lstnew((*f)(lst->content));
		if (result == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, result);
		lst = lst->next;
	}
	return (head);
}
