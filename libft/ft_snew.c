/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:43:23 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:56:46 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		ft_sinit(t_string *str, size_t size)
{
	if (str != NULL)
	{
		str->s = (char*)ft_memalloc(sizeof(char) * (size + SREALLOC));
		str->size = size + SREALLOC;
		str->len = 0;
	}
}

t_string	*ft_snew(void)
{
	t_string	*snew;

	snew = (t_string*)ft_memalloc(sizeof(t_string));
	if (snew == NULL)
		return (NULL);
	ft_sinit(snew, SREALLOC);
	return (snew);
}

char		*ft_srealloc(t_string *str, size_t new_size)
{
	char	*new_s;

	if (str == NULL)
		return (NULL);
	new_s = (char*)ft_memalloc(new_size + SREALLOC);
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, str->s, (new_size > str->size ? str->size : new_size));
	ft_strdel(&(str->s));
	str->s = new_s;
	str->size = new_size + SREALLOC;
	return (str->s);
}

void		ft_sdel_static(t_string *str)
{
	ft_strdel(&(str->s));
	str->len = 0;
	str->size = 0;
}
