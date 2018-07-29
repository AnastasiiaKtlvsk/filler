/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:56:50 by akotilie          #+#    #+#             */
/*   Updated: 2018/01/20 14:12:27 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		mygetchar(int fd)
{
	int				c;
	int				r;

	c = 0;
	r = read(fd, &c, BUFF_SIZE);
	if (r <= -1)
		return (-100);
	if (r != 1)
		return (EOF);
	else
		return (c);
}

char	*myrealloc(char *line, size_t newsize)
{
	char			*newline;

	newline = ft_memalloc(sizeof(char) * newsize + 1);
	ft_memcpy(newline, line, newsize - 128);
	free(line);
	return (newline);
}

int		myreadline(t_line *elem)
{
	int				count;
	int				max_size;
	char			ch;

	max_size = 128;
	count = (elem->line) ? ft_strlen(elem->line) - 1 : -1;
	if (elem->fd < 0 || (ch = mygetchar(elem->fd)) == -100)
		return (-1);
	if (ch == EOF)
		return (0);
	while ((ch != '\n') && (ch != EOF))
	{
		if (++count == max_size)
		{
			max_size += 128;
			elem->line = myrealloc(elem->line, max_size);
		}
		elem->line[count] = ch;
		ch = mygetchar(elem->fd);
	}
	elem->line[count + 1] = '\0';
	if (ch == EOF && mygetchar(elem->fd) > 0)
		return (0);
	return (1);
}

t_line	*myfindline(const int fd, t_line *head)
{
	t_line			*cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->fd == fd)
		{
			ft_bzero(cur->line, ft_strlen(cur->line));
			return (cur);
		}
		cur = cur->next;
	}
	cur = (t_line*)ft_memalloc(sizeof(t_line));
	cur->fd = fd;
	cur->line = (char*)ft_memalloc(sizeof(char) * 128);
	cur->next = NULL;
	return (cur);
}

int		get_next_line(const int fd, char **line)
{
	int				res;
	static t_line	*head;
	t_line			*elem;

	res = -1;
	if (line != NULL)
	{
		if (head == NULL)
		{
			head = (t_line*)ft_memalloc(sizeof(t_line));
			head->fd = fd;
			head->line = (char*)ft_memalloc(sizeof(char) * 128);
			head->next = NULL;
		}
		elem = myfindline(fd, head);
		res = myreadline(elem);
		*line = elem->line;
	}
	return (res);
}
