/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:52:31 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 17:10:05 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>

typedef struct		s_camera
{
	double			offs_x;
	double			offs_y;
	double			offs_z;
	int				scale;
}					t_camera;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_coord;

typedef struct		s_pixel
{
	double			x;
	double			y;
	int				color;
}					t_pixel;

typedef struct		s_map
{
	int				width;
	int				height;
	int				mid_x;
	int				mid_y;
	t_coord			**point;
}					t_map;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				*ren;
	void			*img;
	int				win_w;
	int				win_h;
	t_camera		cam;
	t_map			map;
	t_pixel			**to_print;
	int				col;
	int				bpp;
	int				size_line;
	int				endian;
}					t_info;

typedef t_pixel		t_delta;
typedef struct		s_mid_point
{
	t_delta			delta_a_b;
	int				decision;
	t_delta			delta_sides;
	t_pixel			pix;
	t_pixel			*lower;
	t_pixel			*upper;
	short int		octant;
}					t_mid_point;

typedef void		(*t_putpix)(t_info *e, t_mid_point *mp);

int					ft_find_color(const char *color);
int					ft_argv_color(const char *color);
int					ft_init_map(t_map *map, const char *file);
void				ft_init_cam(t_info *e);
void				ft_init_info(t_info *e);
void				ft_move(t_info *e);
t_pixel				**ft_init_move(t_info *e);
void				ft_draw(t_info *e);
void				ft_draw_line(t_info *e, const t_pixel *a, const t_pixel *b);
void				ft_exit(t_info *e);
void				ft_image(t_info *e);
int					key_hook(int keycode, t_info *e);
void				putpix_1(t_info *e, t_mid_point *md);
void				putpix_2(t_info *e, t_mid_point *md);
void				putpix_3(t_info *e, t_mid_point *md);
void				putpix_4(t_info *e, t_mid_point *md);
void				ft_free_split(char ***split);

# define KEY_TRANS_R 124
# define KEY_TRANS_L 123
# define KEY_TRANS_U 126
# define KEY_TRANS_D 125

# define KEY_Z_P 47
# define KEY_Z_M 43

# define KEY_ESC 53
# define KEY_ZOOM_P 69
# define KEY_ZOOM_M 78
# define KEY_CENTRE 49

# define WIN_H 1200
# define WIN_W 1500

# define BLUE_FDF 255
# define GREEN_FDF 3407616
# define YELLOW_FDF 16776960
# define RED_FDF 16711680
# define PINK_FDF 16711935
# define PURPLE_FDF 6684927
# define ORANGE_FDF 16737792

#endif
