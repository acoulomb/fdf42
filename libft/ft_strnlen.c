/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:12:11 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:55:15 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t size;

	size = 0;
	while (size < n && s[size])
		++size;
	return (size);
}
