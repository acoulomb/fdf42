/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:16:25 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:50:48 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"
#include "fdf.h"

t_pixel		*ft_rotation(t_pixel *pixel, double x, double y)
{
	pixel->x += x * cos(90 * M_PI / 180)
				- y * sin(90 * M_PI / 180);
	pixel->y += x * sin(90 * M_PI / 180) * cos(90 * M_PI / 180)
				+ y * cos(90 * M_PI / 180) * cos(90 * M_PI / 180);
	return (pixel);
}

static void	ft_translation(t_pixel **pixel, int i, int j, const t_info *e)
{
	pixel[i][j].x = e->map.point[i][j].x;
	pixel[i][j].y = e->map.point[i][j].y;
	ft_rotation(&pixel[i][j], pixel[i][j].x, pixel[i][j].y);
	pixel[i][j].x += (e->cam.scale * pixel[i][j].x) + e->cam.offs_x;
	pixel[i][j].y += (e->cam.scale * pixel[i][j].y) - e->cam.offs_y
						+ (j * e->cam.scale / 2);
	pixel[i][j].y -= e->map.point[i][j].z * e->cam.offs_z;
}

void		ft_move(t_info *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->map.height)
	{
		while (j < e->map.width)
		{
			ft_translation(e->to_print, i, j, e);
			j++;
		}
		j = 0;
		i++;
	}
}

t_pixel		**ft_init_move(t_info *e)
{
	int		i;
	int		j;
	t_pixel **pixel;

	i = 0;
	j = 0;
	if (!(pixel = (t_pixel**)
					ft_memalloc(sizeof(t_pixel) * (e->map.height + 1))))
		exit(0);
	while (i < e->map.height)
	{
		if (!(pixel[i] = (t_pixel*)ft_memalloc(sizeof(t_pixel)
												* (e->map.width + 1))))
			exit(0);
		while (j < e->map.width)
		{
			ft_translation(pixel, i, j, e);
			j++;
		}
		j = 0;
		i++;
	}
	return (pixel);
}
