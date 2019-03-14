/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:28:20 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 17:07:45 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check(double x, double y, t_info *e)
{
	if (x >= e->win_w || x <= 0 || y <= 0 || y >= e->win_h)
		return (0);
	else
		return (1);
}

void		putpix_1(t_info *e, t_mid_point *mp)
{
	mp->pix.x = mp->lower->x;
	mp->pix.y = mp->lower->y;
	if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
		e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	while (mp->pix.x < mp->upper->x)
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides.y;
			++mp->pix.x;
			++mp->pix.y;
		}
		else
		{
			mp->decision += mp->delta_sides.x;
			++mp->pix.x;
		}
		if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
			e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	}
}

void		putpix_2(t_info *e, t_mid_point *mp)
{
	mp->pix.x = mp->lower->x;
	mp->pix.y = mp->lower->y;
	if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
		e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	while (mp->pix.y < mp->upper->y)
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides.y;
			++mp->pix.x;
			++mp->pix.y;
		}
		else
		{
			mp->decision += mp->delta_sides.x;
			++mp->pix.y;
		}
		if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
			e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	}
}

void		putpix_3(t_info *e, t_mid_point *mp)
{
	mp->pix.x = mp->lower->x;
	mp->pix.y = mp->lower->y;
	if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
		e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	while (mp->pix.x > mp->upper->x)
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides.y;
			--mp->pix.x;
			++mp->pix.y;
		}
		else
		{
			mp->decision += mp->delta_sides.x;
			--mp->pix.x;
		}
		if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
			e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	}
}

void		putpix_4(t_info *e, t_mid_point *mp)
{
	mp->pix.x = mp->lower->x;
	mp->pix.y = mp->lower->y;
	if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
		e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	while (mp->pix.y < mp->upper->y)
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides.y;
			--mp->pix.x;
			++mp->pix.y;
		}
		else
		{
			mp->decision += mp->delta_sides.x;
			++mp->pix.y;
		}
		if (ft_check(mp->pix.x, mp->pix.y, e) == 1)
			e->ren[(int)(mp->pix.x + mp->pix.y * e->win_w)] = e->col;
	}
}
