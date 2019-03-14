/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:35:47 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include "libft/libft.h"

static void	ft_print(t_info *e)
{
	int i;
	int j;

	i = 0;
	j = e->map.width - 1;
	while (i < e->map.height)
	{
		if (j == e->map.width - 1 && i < e->map.height - 1)
			ft_draw_line(e, &(e->to_print[i][j]), &(e->to_print[i + 1][j]));
		j = 0;
		while (j < e->map.width - 1)
		{
			if (i == e->map.height - 1)
				ft_draw_line(e, &(e->to_print[i][j]), &(e->to_print[i][j + 1]));
			else
			{
				ft_draw_line(e, &(e->to_print[i][j]), &(e->to_print[i][j + 1]));
				ft_draw_line(e, &(e->to_print[i][j]), &(e->to_print[i + 1][j]));
			}
			j++;
		}
		i++;
	}
}

void		ft_image(t_info *e)
{
	e->img = mlx_new_image(e->mlx, e->win_w, e->win_h);
	e->ren = (int*)mlx_get_data_addr(e->img, &(e->bpp),
				&(e->size_line), &(e->endian));
	ft_print(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
