/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:54:05 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	const char	*t[2];
	int			i;
	int			j;

	if (!(s1 && s2))
		return (NULL);
	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	t[0] = s1;
	t[1] = s2;
	i = -1;
	j = 0;
	while (++i < 2)
	{
		while (*t[i])
		{
			join[j] = *t[i];
			++t[i];
			++j;
		}
	}
	join[j] = '\0';
	return (join);
}
