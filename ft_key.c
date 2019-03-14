/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:37:50 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

static void	ft_reload(t_info *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_move(e);
	ft_image(e);
}

static void	key_hook_zoom(int keycode, t_info *e)
{
	if (keycode == KEY_ZOOM_P)
		e->cam.scale += 2;
	else if (keycode == KEY_ZOOM_M)
	{
		if (e->cam.scale > 1)
			e->cam.scale -= 2;
	}
}

static void	key_hook_z(int keycode, t_info *e)
{
	if (keycode == KEY_Z_P)
		e->cam.offs_z++;
	else if (keycode == KEY_Z_M)
		e->cam.offs_z--;
	else
		key_hook_zoom(keycode, e);
}

static void	key_hook_translation(int keycode, t_info *e)
{
	if (keycode == KEY_TRANS_R)
		e->cam.offs_x += 10;
	else if (keycode == KEY_TRANS_L)
		e->cam.offs_x -= 10;
	else if (keycode == KEY_TRANS_U)
		e->cam.offs_y += 10;
	else if (keycode == KEY_TRANS_D)
		e->cam.offs_y -= 10;
	else if (keycode == KEY_CENTRE)
		ft_init_cam(e);
	else
		key_hook_z(keycode, e);
}

int			key_hook(int keycode, t_info *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		ft_exit(e);
	}
	key_hook_translation(keycode, e);
	ft_reload(e);
	return (1);
}
