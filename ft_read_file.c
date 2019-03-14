/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:00:53 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:16 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fdf.h"

static int	ft_read_map(char **map_str, int *nb_lines, int fd)
{
	char		*line;
	int			ret;
	char		*str;

	line = NULL;
	*nb_lines = 0;
	if (!(*map_str = ft_strnew(0)))
		return (0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		str = ft_strjoin(*map_str, line);
		if (!str)
			return (0);
		ft_strdel(map_str);
		*map_str = ft_strjoin(str, "\n");
		if (!(*map_str))
			return (0);
		ft_strdel(&str);
		ft_strdel(&line);
		(*nb_lines)++;
	}
	if (ret != 0)
		return (0);
	ft_strdel(&line);
	return (1);
}

static int	ft_fill_col(t_map *map, const char **split_col, int nb_line)
{
	int nb_col;
	int i;

	nb_col = 0;
	while (split_col[nb_col])
	{
		map->point[nb_line][nb_col].x = nb_col;
		map->point[nb_line][nb_col].y = nb_line;
		if (!(ft_isdigit((int)split_col[nb_col][0]) ||
		(split_col[nb_col][0] == '-' && ft_isdigit((int)split_col[nb_col][1]))))
			return (0);
		map->point[nb_line][nb_col].z = ft_atoi(split_col[nb_col]);
		while (split_col[nb_col][i] && split_col[nb_col][i] != ',')
			i++;
		if (split_col[nb_col][i] == ',')
			map->point[nb_line][nb_col].color =
				ft_find_color(&split_col[nb_col][i++]);
		i = 0;
		nb_col++;
	}
	return (1);
}

static int	ft_fill_map(t_map *map, char *split_line, int nb_line)
{
	int		i;
	char	**split_col;
	int		check_col;

	i = 0;
	check_col = 0;
	if (!(split_col = ft_strsplit(split_line, ' ')))
		return (0);
	while (split_col[check_col])
		check_col++;
	if (map->width == 0)
		map->width = check_col;
	if (check_col != map->width)
		return (0);
	if (!((map->point)[nb_line] =
		(t_coord*)ft_memalloc(sizeof(t_coord) * map->width)))
		return (0);
	if (!(ft_fill_col(map, (const char **)split_col, nb_line)))
	{
		ft_putstr("unvalid file\n");
		return (0);
	}
	ft_free_split(&split_col);
	return (1);
}

static int	ft_store_coords(t_map *map, const char *map_str)
{
	static int	nb_line = 0;
	char		**split_line;

	map->width = 0;
	if (!(map->point = (t_coord**)
						ft_memalloc(sizeof(t_coord*) * (map->height + 1))))
		return (0);
	if (!(split_line = ft_strsplit(map_str, '\n')))
		return (0);
	while (split_line[nb_line])
	{
		if (!ft_fill_map(map, split_line[nb_line], nb_line))
			return (0);
		nb_line++;
	}
	ft_free_split(&split_line);
	return (1);
}

int			ft_init_map(t_map *map, const char *file)
{
	int			fd;
	char		*map_str;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("unvalid file\n");
		return (0);
	}
	if (!ft_read_map(&map_str, &(map->height), fd))
	{
		ft_putstr("unvalid file\n");
		return (0);
	}
	if (!ft_store_coords(map, map_str))
		return (0);
	map->mid_x = (map->point[map->height - 1][map->width - 1].x
					- map->point[0][0].x) / 2;
	map->mid_y = (map->point[0][0].y
					- map->point[map->height - 1][map->width - 1].y) / 2;
	ft_strdel(&map_str);
	return (1);
}
