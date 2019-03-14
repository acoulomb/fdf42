/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:45:24 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"
#include <unistd.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_info	e;

	if (!(argc >= 2 && argc <= 3))
	{
		ft_putstr("usage : ./fdf [filename]\n");
		return (1);
	}
	if (!ft_init_map(&(e.map), argv[1]))
		return (1);
	ft_init_info(&e);
	if (argc == 3)
		e.col = ft_argv_color(argv[2]);
	e.to_print = ft_init_move(&e);
	mlx_key_hook(e.win, key_hook, &e);
	ft_image(&e);
	mlx_loop(e.mlx);
	mlx_destroy_window(e.mlx, e.win);
	return (0);
}
