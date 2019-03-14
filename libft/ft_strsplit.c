/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:32:30 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_count_words(const char *s, char c)
{
	int		i;
	size_t	count_words;

	count_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			++count_words;
			while (s[i] && s[i] != c)
				++i;
		}
	}
	return (count_words);
}

static void			*ft_clean_exit(char **s)
{
	if (s)
	{
		while (*s)
		{
			ft_strdel((void*)*s);
			++s;
		}
		ft_memdel((void*)*s);
	}
	return (NULL);
}

static unsigned int	ft_skip_separators(const char *s, char c, unsigned int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static unsigned int	ft_store_word(char **dst,
								const char *s,
								char c,
								unsigned int i)
{
	unsigned int	start;
	size_t			len;

	start = i;
	while (s[i] && s[i] != c)
		++i;
	len = i - start;
	*dst = ft_strsub(s, start, len);
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**split;
	size_t			count_words;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	count_words = ft_count_words(s, c);
	split = (char **)ft_memalloc(sizeof(char*) * (count_words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		i = ft_skip_separators(s, c, i);
		if (s[i])
		{
			i = ft_store_word(&split[j], s, c, i);
			if (split[j] == NULL)
				return (ft_clean_exit(split));
			++j;
		}
	}
	return (split);
}
