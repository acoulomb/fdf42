/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:55:55 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/26 16:38:47 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_get_next_line.h"

/*
** This function compares 2 fd and return 0 if they are identical,
** else returns 1. It is sent in the ft_lstfind function.
*/

static int		fd_cmp(const void *fd1, const void *fd2)
{
	if (((t_multifd*)fd1)->fd == ((t_multifd*)fd2)->fd)
		return (0);
	return (1);
}

/*
** The insertc function copies one character in the string *line, making sure
** the end of the string is not reached yet. If so, it reallocates memory of the
** buffer size until the first '\n' or the end (use of ft_strclen).
*/

static char		*insertc(char **line, size_t *iline, size_t *size,
							t_multifd *data)
{
	char *tmp;

	if (*iline == *size - 1)
	{
		*size += ft_strclen(&(data->buf[data->ibuf]), '\n');
		tmp = ft_strnew(*size);
		if (tmp == NULL)
			return (NULL);
		ft_strcpy(tmp, *line);
		ft_strdel(line);
		*line = tmp;
		tmp = NULL;
	}
	(*line)[*iline] = data->buf[data->ibuf];
	++*iline;
	return (*line);
}

/*
** The readc function reloads the buffer if it has completely been copied
** and return the number of bytes read.
*/

static ssize_t	readc(t_multifd *data)
{
	ssize_t bytes;

	bytes = 0;
	++data->ibuf;
	if (data->buf[data->ibuf] == '\0')
	{
		bytes = read(data->fd, data->buf, BUFF_SIZE);
		if (bytes > -1)
		{
			data->buf[bytes] = '\0';
			data->ibuf = 0;
		}
	}
	return (bytes);
}

/*
** The gnl_init function initialises or retrieves a link of the multifd list.
** 1. It checks the error conditions.
** 2. Than allocates the char** line received.
** 3. Than checks if the fd received has already been used and stored in the
** list multifd. If not, it creates a new link and initialises the parameters :
** fd, buf and buf index ibuf.
** It return the fd-corresponding link or a new link.
*/

static t_list	*gnl_init(char **line, int fd, size_t *line_size,
							t_list **multifd)
{
	t_list			*fd_lst;
	t_multifd		data;

	*line_size = 1;
	if (fd < 0 || !(line) || read(fd, *line, 0) == -1 || BUFF_SIZE < 0
		|| ((*line = ft_strnew(*line_size)) == NULL))
		return (NULL);
	data.fd = fd;
	if ((fd_lst = ft_lstfind(*multifd, (void*)&data, &fd_cmp)) == NULL)
	{
		data.ibuf = 0;
		ft_bzero(data.buf, BUFF_SIZE + 1);
		if (read(data.fd, data.buf, BUFF_SIZE) == -1)
		{
			ft_strdel(line);
			return (NULL);
		}
		if ((fd_lst = ft_lstnew(&data, sizeof(data))) == NULL)
		{
			ft_strdel(line);
			return (NULL);
		}
		ft_lstadd(multifd, fd_lst);
	}
	return (fd_lst);
}

/*
** The get_next_line function reads and returns line by line a given file.
** It returns 1 if a line was found, 0 if the end of file has been reached, -1
** if an error occured.
** Thanks to a static list, it stores the fd, buffer read and the index of the
** next line. It enables the function to read different files simultaneously.
** The algorythm checks and copies characters by characters until a line or the
** end of file is reached.
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*multifd;
	t_list			*fd_cur;
	t_multifd		*data;
	size_t			line_size;
	size_t			iline;

	if ((fd_cur = gnl_init(line, fd, &line_size, &multifd)) == NULL)
		return (-1);
	data = (t_multifd*)fd_cur->content;
	iline = 0;
	while (data->buf[data->ibuf] != '\0')
	{
		if (data->buf[data->ibuf] == '\n')
			return ((readc(data) == -1) ? -1 : 1);
		if (insertc(line, &iline, &line_size, data) == NULL ||
			readc(data) == -1)
			return (-1);
	}
	if ((*line)[0] != '\0')
		return (1);
	data->fd = -1;
	return (0);
}
