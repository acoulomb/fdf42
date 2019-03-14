/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:01:15 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*a;
	size_t		len;
	long int	tmp;

	len = 1;
	if (n < 0)
		++len;
	tmp = (long int)n;
	while ((tmp /= 10) != 0)
		++len;
	a = ft_strnew(len);
	if (a == NULL)
		return (NULL);
	if (n < 0)
		a[0] = '-';
	else
		a[0] = '0';
	tmp = n < 0 ? -(long int)n : (long int)n;
	while (tmp != 0)
	{
		a[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (a);
}
