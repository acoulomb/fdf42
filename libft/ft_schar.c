/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_schar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:47:11 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_sclear(t_string *dst)
{
	dst->s[0] = '\0';
	dst->len = 0;
}

char			*ft_sset(t_string *dst, char c, size_t start, size_t len)
{
	if (dst == NULL)
		return (NULL);
	if (start >= dst->len)
		return (dst->s);
	if (start + len >= dst->len)
		len = start + len - dst->len;
	ft_memset((void*)dst->s + start, c, len);
	return (dst->s);
}

char			*ft_sappendc(t_string *dst, char c, size_t len)
{
	if (dst == NULL)
		return (NULL);
	if (c == '\0')
		return (dst->s);
	if (dst->len + len >= dst->size)
		if (ft_srealloc(dst, dst->len + len + 1) == NULL)
			return (NULL);
	while (len > 0)
	{
		dst->s[dst->len] = c;
		--len;
		++dst->len;
	}
	dst->s[dst->len] = '\0';
	return (dst->s);
}
