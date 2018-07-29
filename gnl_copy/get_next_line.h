/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:17:07 by akotilie          #+#    #+#             */
/*   Updated: 2017/12/17 13:17:12 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_line
{
	char			*line;
	int				fd;
	struct s_line	*next;
}					t_line;

int					mygetchar(int fd);
char				*myrealloc(char *line, size_t newsize);
int					myreadline(t_line *elem);
t_line				*myfindline(const int fd, t_line *head);
int					get_next_line(const int fd, char **line);
#endif
