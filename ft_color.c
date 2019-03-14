/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 04:05:00 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:51:59 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_argv_color(const char *color)
{
	int rgb;

	rgb = ft_atoi_base(color, 16);
	if (rgb > 0 && rgb <= 16777215)
		return (rgb);
	else
		return (16777215);
}

int	ft_find_color(const char *color)
{
	int i;
	int rgb;

	i = 2;
	if (color[0] != '0' && color[1] != 'x')
		return (0);
	rgb = ft_atoi_base(color + i, 16);
	if (rgb >= 0 && rgb <= 16777215)
		return (rgb);
	else
		return (16777215);
}
