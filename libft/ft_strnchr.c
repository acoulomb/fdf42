/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:29:19 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	while (*s && n > 0)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		++s;
		--n;
	}
	if (c == '\0' || n == 0)
		return ((char *)s);
	return (NULL);
}
