/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:07:50 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcjoin(char const *dst, char const *src, char c)
{
	char	*s;
	size_t	size_src;
	size_t	size;

	if (!dst)
		return (NULL);
	size_src = ft_strclen(src, c);
	size = ft_strlen(dst) + size_src;
	if (!(s = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strcat(s, (char*)dst);
	ft_strncat(s, (char*)src, size_src);
	return (s);
}
