/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:56:55 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove(t_list **lst, void *data,
						int (*f_cmp)(const void *d1, const void *d2),
						void (*del)(void *, size_t))
{
	t_list *to_delete;

	while (*lst && (*f_cmp)((*lst)->content, data) != 0)
		lst = &((*lst)->next);
	if (*lst)
	{
		to_delete = *lst;
		*lst = to_delete->next;
		ft_lstdelone(&to_delete, del);
	}
	return (*lst);
}
