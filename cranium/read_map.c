/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:10:44 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 15:10:47 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cranium.h"

void read_specification(t_map** tm)
{
	char	*sp;
	char	**sizes;
	int		i;
	
	get_next_line(3, &sp);
	if (ft_strstr(sp, "p1"))
		(*tm)->l = 'X';
	if (ft_strstr(sp, "p2"))
		(*tm)->l = 'O';
	free(sp);
	get_next_line(3, &sp);
	sizes = ft_strsplit(sp, ' ');
	free(sp);
	(*tm)->y = ft_atoi(sizes[1]);
	(*tm)->x = ft_atoi(delete_last_char(&(sizes[2])));
	i = -1;
	while (++i < 3)
		free(sizes[i]);
	free(sizes);
}

void	create_map(t_map** tm)
{
	int y;
	char *temp;

	y = (*tm)->y;
	(*tm)->map = (char**)ft_memalloc(sizeof(char*) * y);
	y = 0;
	get_next_line(3, &(temp));
	free(temp);
	while (y < (*tm)->y)
	{
		get_next_line(3, &temp);
		(*tm)->map[y++] = ft_strdup(ft_strchr(temp, ' '));
		free(temp);
	}
}

void free_map(t_map** tm)
{
	int j;

	j = -1;
	while (++j < (*tm)->y)
		free((*tm)->map[j]);
	free((*tm)->map);
	free((*tm));
}

void print_map(t_map** tm)
{
	int j = -1;

	printf("X = %i\n", (*tm)->x);
	printf("Y = %i\n", (*tm)->y);
	printf("Player = %c\n", (*tm)->l);
	while (++j < (*tm)->y)
	{
		printf("%s\n", (*tm)->map[j]);
	}
}