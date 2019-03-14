/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:46:15 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 17:11:11 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_up_low_pix(t_mid_point *mp, const t_pixel *a, const t_pixel *b)
{
	if (a->y > b->y)
	{
		mp->upper = (t_pixel *)a;
		mp->lower = (t_pixel *)b;
	}
	else
	{
		mp->upper = (t_pixel *)b;
		mp->lower = (t_pixel *)a;
	}
}

static void	init_octant(t_mid_point *mp)
{
	mp->octant = 0;
	mp->delta_a_b.y = mp->upper->y - mp->lower->y;
	if (mp->upper->x < mp->lower->x)
	{
		mp->delta_a_b.x = mp->lower->x - mp->upper->x;
		mp->octant = 2;
	}
	else
		mp->delta_a_b.x = mp->upper->x - mp->lower->x;
	if (mp->delta_a_b.x < mp->delta_a_b.y)
	{
		mp->decision = 2 * mp->delta_a_b.x - mp->delta_a_b.y;
		mp->delta_sides.x = 2 * mp->delta_a_b.x;
		mp->delta_sides.y = 2 * (mp->delta_a_b.x - mp->delta_a_b.y);
		mp->octant |= 1;
	}
	else
	{
		mp->decision = 2 * mp->delta_a_b.y - mp->delta_a_b.x;
		mp->delta_sides.x = 2 * mp->delta_a_b.y;
		mp->delta_sides.y = 2 * (mp->delta_a_b.y - mp->delta_a_b.x);
	}
}

void		ft_draw_line(t_info *e, const t_pixel *pxa, const t_pixel *pxb)
{
	static	t_mid_point	mp;
	static	t_putpix	f_putpix[] = {putpix_1,
									putpix_2,
									putpix_3,
									putpix_4};

	init_up_low_pix(&mp, pxa, pxb);
	init_octant(&mp);
	(*f_putpix[mp.octant])(e, &mp);
}
