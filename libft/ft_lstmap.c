/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 04:47:10 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *link, size_t size)
{
	t_list *tmp;

	tmp = (t_list*)link;
	if (link)
	{
		ft_bzero(tmp->content, size);
		ft_memdel(tmp->content);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list **iter;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	iter = &new;
	while (lst)
	{
		*iter = (*f)(lst);
		if (*iter == NULL)
		{
			ft_lstdel(&new, &del);
			return (NULL);
		}
		iter = &(*iter)->next;
		lst = lst->next;
	}
	return (new);
}
