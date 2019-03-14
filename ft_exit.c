/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:16:01 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 17:05:38 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"
#include <unistd.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

/*
** fonction free split a faire
*/

void		ft_free_split(char ***split)
{
	int i;

	if (split && *split)
	{
		i = 0;
		while ((*split)[i])
		{
			ft_memdel(((void**)&((*split)[i])));
			++i;
		}
		ft_memdel((void**)split);
	}
}

static void	ft_free_t_pixel(t_pixel ***pixel, int height)
{
	int i;

	if (pixel && *pixel)
	{
		i = 0;
		while (i < height)
		{
			if ((*pixel)[i])
				ft_memdel((void*)&((*pixel)[i]));
			i++;
		}
		ft_memdel((void*)pixel);
	}
}

static void	ft_free_t_coord(t_coord ***coord, int height)
{
	int i;

	if (coord && *coord)
	{
		i = 0;
		while (i < height)
		{
			if ((*coord)[i])
				ft_memdel((void*)&((*coord)[i]));
			i++;
		}
		ft_memdel((void*)coord);
	}
}

void		ft_free_info(t_info *e)
{
	ft_free_t_pixel(&(e->to_print), e->map.height);
	ft_free_t_coord(&(e->map.point), e->map.height);
	e->map.width = 0;
	e->map.height = 0;
	e->map.mid_x = 0;
	e->map.mid_y = 0;
	e->col = 0;
	e->bpp = 0;
	e->size_line = 0;
	e->endian = 0;
	e->win_h = 0;
	e->win_w = 0;
}

void		ft_exit(t_info *e)
{
	ft_free_info(e);
	exit(0);
}
