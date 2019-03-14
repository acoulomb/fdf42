/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:11:34 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:57:13 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <string.h>
# include "libft.h"

# define SREALLOC 1024

typedef struct	s_string
{
	char		*s;
	size_t		len;
	size_t		size;
}				t_string;

void			ft_sinit(t_string *str, size_t size);
t_string		*ft_snew(void);
char			*ft_srealloc(t_string *str, size_t new_size);
char			*ft_sappend(t_string *dst, const char *src);
char			*ft_sappendn(t_string *dst, const char *src, size_t n);
char			*ft_serase(t_string *dst, const char *src);
char			*ft_sinsert(t_string *dst, const char *src, size_t index);
void			ft_sclear(t_string *dst);
char			*ft_sset(t_string *dst, char c, size_t start, size_t len);
int				ft_sputstr(const t_string *str);
char			*ft_sappendc(t_string *dst, char c, size_t len);
char			*ft_sinsertn(t_string *dst, const char *src, size_t index,
							size_t n);
void			ft_sdel_static(t_string *str);

#endif
