/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:40:48 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"
#include "fdf.h"

void		ft_init_cam(t_info *e)
{
	e->cam.scale = ((WIN_W / e->map.width) + (WIN_H / e->map.height)) * 0.20;
	e->cam.offs_x = (WIN_W - e->map.mid_x * e->cam.scale) / 2;
	e->cam.offs_y = -(WIN_H - e->map.mid_y * e->cam.scale) / 4;
	e->cam.offs_z = e->map.width / e->map.height;
}

void		ft_init_info(t_info *e)
{
	e->win_w = WIN_W;
	e->win_h = WIN_H;
	e->mlx = mlx_init();
	if ((e->win = mlx_new_window(e->mlx, e->win_w, e->win_h, "fdf")) == NULL)
		exit(0);
	e->col = 16777215;
	ft_init_cam(e);
}
