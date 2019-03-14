/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:04:02 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t expected_size;
	size_t i;

	expected_size = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (ft_strlen(src) + size);
	ft_strncpy(&dst[i], src, size - i - 1);
	dst[size - 1] = '\0';
	return (expected_size);
}
