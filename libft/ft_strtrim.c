/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:06:57 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	size_t start;
	size_t len;
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_strtrim_isspace(s[i]))
		++i;
	start = i;
	while (s[i])
		++i;
	i--;
	while (i > start && ft_strtrim_isspace(s[i]))
		--i;
	len = i - start;
	return (ft_strsub(s, start, len + 1));
}
