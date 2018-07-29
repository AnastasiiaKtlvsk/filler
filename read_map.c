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

void read_specification(t_map** tm, int i) // i = -1
{
	char	*sp;
	char	**sizes;
	
	get_next_line(3, &sp);
	if (ft_strstr(sp, "p1"))
	{
		(*tm)->l = 'o';
		(*tm)->el = 'x';
	}
	if (ft_strstr(sp, "p2"))
	{
		(*tm)->l = 'x';
		(*tm)->el = 'o';  
	}
	free(sp);		
	get_next_line(3, &sp);
	sizes = ft_strsplit(sp, ' ');
	free(sp);
	(*tm)->y = ft_atoi( sizes[1]);
	(*tm)->x = ft_atoi(delete_last_char(&(sizes[2])));
	while (++i < 3)
	free(sizes[i]);
	free(sizes);
}

void		create_map(t_map** tm)
{
	int y;
	char *temp;
	int	i;

	y = (*tm)->y;
	(*tm)->map = (char**)ft_memalloc(sizeof(char*) * y);
	y = 0;
	get_next_line(3, &(temp));
	free(temp);
	while (y < (*tm)->y)
	{
		get_next_line(3, &temp);
		i = -1;
		while (temp[++i])
			temp[i] = ft_tolower(temp[i]);
//		printf("%s\n", ft_strdup(ft_strchr(temp, ' ') + 1));
		(*tm)->map[y++] = ft_strdup(ft_strchr(temp, ' ') + 1);
	//	printf("map %p\n",  &((*tm)->map[y - 1]));
		free(temp);
	}
	find_enemy_points(tm);
}

void	find_enemy_points(t_map** tm)
{
	int		i;
	int		ce;
	int		j;

	ce = 0;
	(*tm)->p = (t_p*)ft_memalloc(sizeof(t_p));
	(*tm)->p->x = ft_memalloc(sizeof(int) * (*tm)->x * (*tm)->y);
	(*tm)->p->y = ft_memalloc(sizeof(int) * (*tm)->x * (*tm)->y);
	j = -1;
	while (++j < (*tm)->y)
	{
		i = -1;
		while ((*tm)->map[j][++i])
		{			
			if ((*tm)->map[j][i] == (*tm)->el)
			{
				(*tm)->p->y[ce] = j;
				(*tm)->p->x[ce++] = i;
				(*tm)->ce++;
			}
		}
	}
}

void free_map(t_map** tm)
{
	int j;

	j = -1;
//	printf("map 0 %p\n",  &((*tm)->map[0]));
	while (++j < (*tm)->y)
		free((*tm)->map[j]);
	free((*tm)->map);
	free((*tm)->p->x);
	free((*tm)->p->y);
	free((*tm)->p);
	free((*tm)->sh->p->x);
	free((*tm)->sh->p->y);
	/*free((*tm)->sh->p);*/
	j = -1;
	while (++j < (*tm)->sh->y)
		free((*tm)->sh->sm[j]);
	free((*tm)->sh->sm);
	free((*tm)->sh);
	/*free((*tm)->ps->ap->x);
	free((*tm)->ps->ap->y);
	free((*tm)->ps->ap);
	free((*tm)->ps);*/
//	printf("__________________________free\n");
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
	j = -1;
	printf("CE  %i\n",(*tm)->ce);
	while (++j < (*tm)->ce)
	{
		printf("%i ", (*tm)->p->y[j]);
		printf("%i\n", (*tm)->p->x[j]);
	}
}